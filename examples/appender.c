/*
 * Tests for cgs_appendi.
 *
 * Build it the same way as the rest of your code (it uses f"..." strings),
 * link it against the library and run it. Every failing check prints a
 * short report to stderr, and the exit status is 1 if anything failed.
 *
 * Formats are always f"..." literals. A plain "..." literal is written out
 * as-is, which test_plain_literals checks.
 *
 * Each string type has its own conversion:
 *
 *     %s   char*              %Hs  CGS_StrView
 *     %Ds  CGS_DStr           %zs  CGS_StrBuf
 *     %DS  CGS_DStr*          %zS  CGS_StrBuf*
 *     %ts  CGS_MutStrRef
 *
 * CGS_ZStrView isn't in that table, so it's only tested through %{expr}?,
 * which takes the type from the expression.
 *
 * Define CGS_TEST_PENDING to also run the tests for features that are still
 * TODO: width, precision, the '-', '0' and '#' flags, '+' on floats, %e and %c.
 *
 * Also run the suite with -fsanitize=address,undefined, and under valgrind.
 * test_bool_args and test_self_append target memory errors (an out-of-bounds
 * read, a use-after-free) that can print the right text by accident, so a plain
 * build may pass them. The empty-DStr checks in test_dstr can pass a NULL buffer
 * to memcpy with a length of 0, which only UBSan reports. valgrind also catches
 * reads of uninitialized variables.
 */

#include "cgs.h" /* adjust to your header */

#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Adjust if your DStr cleanup function has a different name. */
#define TEST_DSTR_DEINIT(s) cgs_dstr_deinit(&(s))

/* ------------------------------------------------------------------------- */
/* Test harness                                                              */
/* ------------------------------------------------------------------------- */

static int g_checks;
static int g_failures;

static void fail(const char *file, int line, const char *call)
{
    g_failures++;
    fprintf(stderr, "FAIL %s:%d: %s\n", file, line, call);
}

static void check_output(const char *file, int line, const char *call, CGS_Error err, const char *got, const char *want)
{
    g_checks++;
    if (err.ec != CGS_OK)
    {
        fail(file, line, call);
        fprintf(stderr, "    returned error %d, expected \"%s\"\n", (int)err.ec, want);
    }
    else if (strcmp(got, want) != 0)
    {
        fail(file, line, call);
        fprintf(stderr, "    got      \"%s\"\n    expected \"%s\"\n", got, want);
    }
}

static void check_error(const char *file, int line, const char *call, CGS_Error err, int want_ec, const char *want_name)
{
    g_checks++;
    if ((int)err.ec != want_ec)
    {
        fail(file, line, call);
        fprintf(stderr, "    returned %d, expected %s (%d)\n", (int)err.ec, want_name, want_ec);
    }
}

static void check_ok(const char *file, int line, const char *call, CGS_Error err)
{
    g_checks++;
    if (err.ec != CGS_OK)
    {
        fail(file, line, call);
        fprintf(stderr, "    returned error %d\n", (int)err.ec);
    }
}

static void check_trunc(
    const char *file, int line, const char *call, const char *buf, size_t cap, const unsigned char *guard, size_t guard_len,
    const char *want
)
{
    g_checks++;
    for (size_t k = 0; k < guard_len; k++)
    {
        if (guard[k] != 0x5A)
        {
            fail(file, line, call);
            fprintf(stderr, "    wrote past the end of a char[%zu]\n", cap);
            return;
        }
    }
    if (memchr(buf, '\0', cap) == NULL)
    {
        fail(file, line, call);
        fprintf(stderr, "    char[%zu] is not NUL-terminated\n", cap);
        return;
    }
    if (strcmp(buf, want) != 0)
    {
        fail(file, line, call);
        fprintf(stderr, "    got      \"%s\"\n    expected \"%s\"\n", buf, want);
    }
}

/* Checks that a stored length matches `want`. */
static void check_len(const char *file, int line, const char *call, unsigned int len, const char *want)
{
    g_checks++;
    if (len != strlen(want))
    {
        fail(file, line, call);
        fprintf(stderr, "    len is %u, expected %zu\n", len, strlen(want));
    }
}

/* Checks a StrBuf's text, and that its len matches the text. Reads the buffer directly. */
static void check_strbuf(const char *file, int line, const CGS_StrBuf *sb, const char *want)
{
    g_checks++;
    if (memchr(sb->chars, '\0', sb->cap) == NULL)
    {
        fail(file, line, "contents of the StrBuf");
        fprintf(stderr, "    not NUL-terminated within its cap (%u)\n", sb->cap);
    }
    else if (strcmp(sb->chars, want) != 0)
    {
        fail(file, line, "contents of the StrBuf");
        fprintf(stderr, "    got      \"%s\"\n    expected \"%s\"\n", sb->chars, want);
    }
    else if (sb->len != strlen(want))
    {
        fail(file, line, "contents of the StrBuf");
        fprintf(stderr, "    text is right, but len is %u, expected %zu\n", sb->len, strlen(want));
    }
}

/* Reads the DStr back through %DS (CGS_DStr*) and compares. */
static void check_dstr(const char *file, int line, CGS_DStr *s, const char *want)
{
    static char got[8192];
    got[0] = '\0';

    CGS_Error err = cgs_appendi(got, f"%DS", s);
    check_output(file, line, "contents of the DStr", err, got, want);
}

/* Formats into an empty char[512] and compares with `want`. */
#define EXPECT(want, ...)                                                                          \
    do                                                                                             \
    {                                                                                              \
        char got_[512] = "";                                                                       \
        CGS_Error err_ = cgs_appendi(got_, __VA_ARGS__);                                           \
        check_output(__FILE__, __LINE__, "cgs_appendi(buf, " #__VA_ARGS__ ")", err_, got_, (want)); \
    } while (0)

/*
 * Runs the same arguments through the C library's snprintf with `c_fmt` and
 * through cgs_appendi with `cgs_fmt`; the outputs must match. The two formats
 * should be the same text, one plain and one f"...".
 */
#define EXPECT_PRINTF(c_fmt, cgs_fmt, ...)                       \
    do                                                           \
    {                                                            \
        char want_[512];                                         \
        snprintf(want_, sizeof want_, c_fmt, __VA_ARGS__);       \
        EXPECT(want_, cgs_fmt, __VA_ARGS__);                     \
    } while (0)

/* Expects cgs_appendi to fail with the given error code. */
#define EXPECT_ERR(code, ...)                                                                      \
    do                                                                                             \
    {                                                                                              \
        char got_[512] = "";                                                                       \
        CGS_Error err_ = cgs_appendi(got_, __VA_ARGS__);                                           \
        check_error(__FILE__, __LINE__, "cgs_appendi(buf, " #__VA_ARGS__ ")", err_, (code), #code); \
    } while (0)

/* Expects the call to succeed. */
#define CHECK_OK(expr) check_ok(__FILE__, __LINE__, #expr, (expr))

/*
 * Formats into a char[size] that starts out as `prefill`, followed by 16 guard
 * bytes. Checks that nothing was written past the array, that it's still
 * NUL-terminated, and that it holds `want`.
 */
#define EXPECT_TRUNC(size, prefill, want, ...)                                                            \
    do                                                                                                    \
    {                                                                                                     \
        struct                                                                                            \
        {                                                                                                 \
            char buf[size];                                                                               \
            unsigned char guard[16];                                                                      \
        } t_;                                                                                             \
        memset(&t_, 0x5A, sizeof t_);                                                                     \
        strcpy(t_.buf, (prefill));                                                                        \
        cgs_appendi(t_.buf, __VA_ARGS__);                                                                 \
        check_trunc(                                                                                      \
            __FILE__, __LINE__, "char[" #size "] = \"" prefill "\"; cgs_appendi(buf, " #__VA_ARGS__ ")", \
            t_.buf, sizeof t_.buf, t_.guard, sizeof t_.guard, (want)                                      \
        );                                                                                                \
    } while (0)

/*
 * Same as EXPECT_TRUNC, but appends through a CGS_StrBuf over the char[size],
 * and also checks that the StrBuf's len matches the text.
 */
#define EXPECT_STRBUF(size, prefill, want, ...)                                                           \
    do                                                                                                    \
    {                                                                                                     \
        struct                                                                                            \
        {                                                                                                 \
            char buf[size];                                                                               \
            unsigned char guard[16];                                                                      \
        } t_;                                                                                             \
        memset(&t_, 0x5A, sizeof t_);                                                                     \
        strcpy(t_.buf, (prefill));                                                                        \
        CGS_StrBuf sb_ = {.chars = t_.buf, .cap = sizeof t_.buf, .len = (unsigned int)strlen(prefill)};   \
        cgs_appendi(&sb_, __VA_ARGS__);                                                                   \
        check_trunc(                                                                                      \
            __FILE__, __LINE__,                                                                           \
            "StrBuf over char[" #size "] = \"" prefill "\"; cgs_appendi(&sb, " #__VA_ARGS__ ")",          \
            t_.buf, sizeof t_.buf, t_.guard, sizeof t_.guard, (want)                                      \
        );                                                                                                \
        check_len(__FILE__, __LINE__, "StrBuf len after cgs_appendi(&sb, " #__VA_ARGS__ ")", sb_.len, (want)); \
    } while (0)

/* Same as EXPECT_TRUNC, but appends through cgs_mutstr_ref(buf). */
#define EXPECT_REF_TRUNC(size, prefill, want, ...)                                                        \
    do                                                                                                    \
    {                                                                                                     \
        struct                                                                                            \
        {                                                                                                 \
            char buf[size];                                                                               \
            unsigned char guard[16];                                                                      \
        } t_;                                                                                             \
        memset(&t_, 0x5A, sizeof t_);                                                                     \
        strcpy(t_.buf, (prefill));                                                                        \
        CGS_MutStrRef ref_ = cgs_mutstr_ref(t_.buf);                                                      \
        cgs_appendi(ref_, __VA_ARGS__);                                                                   \
        check_trunc(                                                                                      \
            __FILE__, __LINE__,                                                                           \
            "cgs_mutstr_ref(char[" #size "] = \"" prefill "\"); cgs_appendi(ref, " #__VA_ARGS__ ")",      \
            t_.buf, sizeof t_.buf, t_.guard, sizeof t_.guard, (want)                                      \
        );                                                                                                \
    } while (0)

/* ------------------------------------------------------------------------- */
/* Literals                                                                  */
/* ------------------------------------------------------------------------- */

static void test_literals(void)
{
    EXPECT("", f"");
    EXPECT("hello", f"hello");
    EXPECT("100%", f"100%%");
    EXPECT("50%", f"%d%%", 50);
    EXPECT("<>", f"<%s>", "");

    /* text after the last specifier must be written too */
    EXPECT("3 apples", f"%d apples", 3);
    EXPECT("a1bxc", f"a%db%sc", 1, "x");
}

/* A plain string literal is taken as text, with no specifiers or interps. */
static void test_plain_literals(void)
{
    EXPECT("", "");
    EXPECT("hello", "hello");
    EXPECT("%d apples", "%d apples");
    EXPECT("100%%", "100%%");
    EXPECT("%{12}x", "%{12}x");
    EXPECT_TRUNC(8, "", "abcdefg", "abcdefghij");
}

/* ------------------------------------------------------------------------- */
/* Integers                                                                  */
/* ------------------------------------------------------------------------- */

static void test_basic_integers(void)
{
    EXPECT("42", f"%d", 42);
    EXPECT("-42", f"%d", -42);
    EXPECT("-7", f"%i", -7);
    EXPECT("0", f"%d", 0);
    EXPECT("42", f"%u", 42u);
    EXPECT("ff", f"%x", 255);
    EXPECT("FF", f"%X", 255);
    EXPECT("377", f"%o", 255);
    EXPECT("101", f"%b", 5);
    EXPECT("0", f"%x", 0);
    EXPECT("0", f"%b", 0);

    EXPECT_PRINTF("%d", f"%d", INT_MIN);
    EXPECT_PRINTF("%d", f"%d", INT_MAX);
    EXPECT_PRINTF("%u", f"%u", UINT_MAX);
    EXPECT_PRINTF("%x", f"%x", UINT_MAX);

    /* narrower argument types */
    EXPECT("65", f"%d", (char)65);
    EXPECT("-1", f"%d", (signed char)-1);
    EXPECT("200", f"%d", (unsigned char)200);
    EXPECT("-5", f"%d", (short)-5);
    EXPECT("65535", f"%u", (unsigned short)65535);
}

/* The conversion character decides signedness, not the argument's type. */
static void test_conversion_decides_signedness(void)
{
    /* the original bug: this used to print a 20-digit number */
    EXPECT("170", f"%+hhu", -1110);

    EXPECT("170", f"%hhu", -1110);
    EXPECT("-86", f"%hhd", -1110);
    EXPECT("aa", f"%hhx", -1110);
    EXPECT("255", f"%hhu", -1);
    EXPECT("-56", f"%hhd", 200);
    EXPECT("-56", f"%hhd", 200u);
    EXPECT("-5536", f"%hd", 60000u);
    EXPECT("65535", f"%hu", -1);
    EXPECT("ffff", f"%hx", -1);
}

/* With no length modifier, integers are converted to int / unsigned int. */
static void test_default_int_truncation(void)
{
    EXPECT("4294967295", f"%u", -1);
    EXPECT("-1294967296", f"%d", 3000000000u);
    EXPECT("ffffffff", f"%x", -1);
    EXPECT("ffffffff", f"%x", -1LL);
    EXPECT("5", f"%d", 0x100000005LL);
    EXPECT("-1", f"%d", 0xFFFFFFFFFFFFFFFFULL);
    EXPECT("4294967295", f"%u", ULLONG_MAX);
}

static void test_length_modifiers(void)
{
    EXPECT("-32768", f"%hd", SHRT_MIN);
    EXPECT("7f", f"%hhx", 0x17f);
    EXPECT("2345", f"%hx", 0x12345);

    /* LONG_MAX catches a long being read through an int */
    EXPECT_PRINTF("%ld", f"%ld", LONG_MIN);
    EXPECT_PRINTF("%ld", f"%ld", LONG_MAX);
    EXPECT_PRINTF("%lu", f"%lu", ULONG_MAX);
    EXPECT_PRINTF("%lx", f"%lx", ULONG_MAX);

    EXPECT_PRINTF("%lld", f"%lld", LLONG_MIN);
    EXPECT_PRINTF("%lld", f"%lld", LLONG_MAX);
    EXPECT_PRINTF("%llu", f"%llu", ULLONG_MAX);
    EXPECT_PRINTF("%llx", f"%llx", ULLONG_MAX);

    /* narrower arguments are converted to the modifier's type */
    EXPECT("-1", f"%lld", -1);
    EXPECT("18446744073709551615", f"%llu", -1);
    EXPECT("18446744073709551615", f"%llu", -1LL);
}

/* z, t and j; %zd and %tu used to read through an 8-bit type */
static void test_size_types(void)
{
    EXPECT("1000", f"%zu", (size_t)1000);
    EXPECT("1000", f"%zd", 1000);
    EXPECT("-1000", f"%zd", -1000);
    EXPECT_PRINTF("%zu", f"%zu", SIZE_MAX);

    EXPECT("1000", f"%tu", (ptrdiff_t)1000);
    EXPECT("-1000", f"%td", (ptrdiff_t)-1000);
    EXPECT_PRINTF("%td", f"%td", PTRDIFF_MIN);
    EXPECT_PRINTF("%td", f"%td", PTRDIFF_MAX);

    EXPECT("-1", f"%jd", -1);
    EXPECT_PRINTF("%jd", f"%jd", INTMAX_MIN);
    EXPECT_PRINTF("%ju", f"%ju", UINTMAX_MAX);
}

/* C23 wN and wfN */
static void test_exact_width(void)
{
    char want[64];

    EXPECT("-56", f"%w8d", 200);
    EXPECT("255", f"%w8u", -1);
    EXPECT("7f", f"%w8x", 0x17f);
    EXPECT("-5536", f"%w16d", 60000);
    EXPECT("65535", f"%w16u", -1);
    EXPECT("-1", f"%w32d", 0xFFFFFFFFu);
    EXPECT("ffffffff", f"%w32x", -1LL);
    EXPECT("-9223372036854775808", f"%w64d", INT64_MIN);
    EXPECT("18446744073709551615", f"%w64u", -1);

    /* the fast types' widths vary by platform, so compare with <inttypes.h> */
    snprintf(want, sizeof want, "%" PRIuFAST8, (uint_fast8_t)300);
    EXPECT(want, f"%wf8u", 300);
    snprintf(want, sizeof want, "%" PRIuFAST16, (uint_fast16_t)-1);
    EXPECT(want, f"%wf16u", -1);
    snprintf(want, sizeof want, "%" PRIdFAST16, (int_fast16_t)40000);
    EXPECT(want, f"%wf16d", 40000);
    snprintf(want, sizeof want, "%" PRIuFAST32, (uint_fast32_t)-1);
    EXPECT(want, f"%wf32u", -1);
    EXPECT("18446744073709551615", f"%wf64u", -1);

    /* only 8, 16, 32 and 64 are valid */
    EXPECT_ERR(CGS_BAD_FORMAT, f"%w12d", 1);
    EXPECT_ERR(CGS_BAD_FORMAT, f"%w128d", 1);
    EXPECT_ERR(CGS_BAD_FORMAT, f"%wf4d", 1);
    EXPECT_ERR(CGS_BAD_FORMAT, f"%w0d", 1);
}

static void test_plus_flag(void)
{
    EXPECT("+5", f"%+d", 5);
    EXPECT("-5", f"%+d", -5);
    EXPECT("+0", f"%+d", 0);
    EXPECT("+7", f"%+i", 7);
    EXPECT("+127", f"%+hhd", 127);
    EXPECT("-128", f"%+hhd", 128);

    /* '+' has no effect on unsigned conversions */
    EXPECT("5", f"%+u", 5);
    EXPECT("ff", f"%+x", 255);
}

/*
 * bool is 1 byte, but printf accepts it for %d because it is promoted to int.
 * Integer arguments are read as 8 bytes, so a bool must be converted at the
 * call site like the other integer types, or these read past it.
 */
static void test_bool_args(void)
{
    bool yes = true;
    bool no  = false;

    EXPECT("1", f"%d", yes);
    EXPECT("0", f"%d", no);
    EXPECT("1 0", f"%u %u", yes, no);
    EXPECT("1", f"%x", yes);
    EXPECT("0 1 0", f"%d %d %d", no, yes, no);
    EXPECT("1", f"%{yes}d");
}

/* ------------------------------------------------------------------------- */
/* The %? extension (interpolation only: %{expr}?)                           */
/* ------------------------------------------------------------------------- */

static void test_question_mark(void)
{
    const char *hi = "hi";

    EXPECT("42", f"%{42}?");
    EXPECT("-42", f"%{-42}?");
    EXPECT("42", f"%{42u}?");
    EXPECT("-1", f"%{-1LL}?");
    EXPECT("18446744073709551615", f"%{ULLONG_MAX}?");
    EXPECT("65", f"%{(unsigned char)65}?");
    EXPECT("hi", f"%{hi}?");
}

/* ------------------------------------------------------------------------- */
/* Interpolation                                                             */
/* ------------------------------------------------------------------------- */

static void test_interpolation(void)
{
    int n            = 7;
    int a            = 2;
    int b            = 3;
    const char *name = "bob";

    EXPECT("10 hello world", f"%{10}? %s", "hello world");
    EXPECT("c", f"%{12}x");
    EXPECT("-5", f"%{-5}d");
    EXPECT("FF", f"%{255}X");
    /* {} infers the length modifier from the expression's type: int here, long long below */
    EXPECT("4294967295", f"%{-1}u");
    EXPECT("ffffffffffffffff", f"%{-1LL}x");

    EXPECT("n=7", f"n=%{n}d");
    EXPECT("hi bob!", f"hi %{name}s!");
    EXPECT("bob", f"%{name}?");
    EXPECT("2+3=5", f"%{a}d+%{b}d=%{a + b}d");

    /* interps must not consume the normal arguments */
    EXPECT("1-7-3", f"%d-%{n}d-%d", 1, 3);
}

/* ------------------------------------------------------------------------- */
/* Strings                                                                   */
/* ------------------------------------------------------------------------- */

/* %s: char* and char[] */
static void test_strings(void)
{
    char arr[]    = "array";
    const char *p = "ptr";

    EXPECT("hello", f"%s", "hello");
    EXPECT("", f"%s", "");
    EXPECT("array", f"%s", arr);
    EXPECT("[ptr]", f"[%s]", p);
}

/* %Hs: a CGS_StrView isn't NUL-terminated, so it must stop at the view's length. */
static void test_strview(void)
{
    char text[]       = "hello, world";
    CGS_StrView all   = cgs_strv(text);
    CGS_StrView hello = cgs_strv(text, 0, 5);
    CGS_StrView world = cgs_strv(text, 7);
    CGS_StrView ll    = cgs_strv(text, 2, 4);
    CGS_StrView wor   = cgs_strv(world, 0, 3); /* a view of a view */
    CGS_StrView empty = cgs_strv(text, 3, 3);

    EXPECT("hello, world", f"%Hs", all);
    EXPECT("hello", f"%Hs", hello);
    EXPECT("world", f"%Hs", world);
    EXPECT("ll", f"%Hs", ll);
    EXPECT("wor", f"%Hs", wor);
    EXPECT("<>", f"<%Hs>", empty);
    EXPECT("hello|world", f"%Hs|%Hs", hello, world);
    EXPECT("hello", f"%{hello}?");
    EXPECT("wor", f"%{wor}?");

    EXPECT_TRUNC(4, "", "hel", f"%Hs", hello);
    EXPECT_TRUNC(8, "ab", "abhello", f"%Hs", hello);
}

/* CGS_ZStrView has no conversion in the table, so only %? is tested. */
static void test_zstrview(void)
{
    char text[]        = "hello";
    CGS_ZStrView all   = cgs_zstrv(text);
    CGS_ZStrView tail  = cgs_zstrv(text, 2);
    CGS_ZStrView empty = cgs_zstrv(text, 5);

    EXPECT("hello", f"%{all}?");
    EXPECT("llo", f"%{tail}?");
    EXPECT("<>", f"<%{empty}?>");
}

/* %zs and %zS: CGS_StrBuf by value and by pointer */
static void test_strbuf_args(void)
{
    char arr[32]     = "buf";
    char cstr[]      = "from cstr";
    char none[8]     = "";
    CGS_StrBuf sb    = {.chars = arr, .cap = sizeof arr, .len = 3};
    CGS_StrBuf from  = cgs_strbuf_init_from_cstr(cstr);
    CGS_StrBuf empty = {.chars = none, .cap = sizeof none, .len = 0};

    EXPECT("buf", f"%zs", sb);
    EXPECT("buf", f"%zS", &sb);
    EXPECT("[buf]", f"[%zs]", sb);
    EXPECT("from cstr", f"%zs", from);
    EXPECT("from cstr", f"%zS", &from);
    EXPECT("<>", f"<%zs>", empty);
    EXPECT("<>", f"<%zS>", &empty);
    EXPECT("buf", f"%{sb}?");
    EXPECT("buf", f"%{&sb}?");

    /* 'z' still means size_t before an integer conversion */
    EXPECT("buf 3", f"%zs %zu", sb, (size_t)3);
}

/* %ts: CGS_MutStrRef */
static void test_mutstr_ref_args(void)
{
    char arr[32]     = "ref";
    char backing[16] = "ptr+cap";
    char *p          = backing;
    CGS_MutStrRef r  = cgs_mutstr_ref(arr);
    CGS_MutStrRef rp = cgs_mutstr_ref(p, sizeof backing);

    EXPECT("ref", f"%ts", r);
    EXPECT("[ref]", f"[%ts]", r);
    EXPECT("ptr+cap", f"%ts", rp);
    EXPECT("ref|ptr+cap", f"%ts|%ts", r, rp);
    EXPECT("ref", f"%{r}?");

    /* 't' still means ptrdiff_t before an integer conversion */
    EXPECT("ref -3", f"%ts %td", r, (ptrdiff_t)-3);
}

/* Each string conversion takes exactly one argument, of its own type. */
static void test_string_types_mixed(void)
{
    char arr[]      = "arr";
    char sbarr[16]  = "sb";
    char refarr[16] = "ref";
    CGS_StrBuf sb   = {.chars = sbarr, .cap = sizeof sbarr, .len = 2};
    CGS_StrView v   = cgs_strv(arr, 0, 2);
    CGS_MutStrRef r = cgs_mutstr_ref(refarr);
    CGS_DStr ds     = cgs_dstr_init();

    CHECK_OK(cgs_appendi(&ds, "ds"));

    EXPECT("arr|ds|ds|ar|sb|sb|ref|7", f"%s|%Ds|%DS|%Hs|%zs|%zS|%ts|%d", arr, ds, &ds, v, sb, &sb, r, 7);
    EXPECT("7|ref|sb|ar|ds|ds|arr|8", f"%d|%ts|%zS|%Hs|%DS|%Ds|%s|%d", 7, r, &sb, v, &ds, ds, arr, 8);
    EXPECT("ds 1 ar 2 sb 3", f"%Ds %d %Hs %d %zs %d", ds, 1, v, 2, sb, 3);

    TEST_DSTR_DEINIT(ds);
}

/* ------------------------------------------------------------------------- */
/* Floats                                                                    */
/* ------------------------------------------------------------------------- */

static void test_floats(void)
{
    EXPECT("1.500000", f"%f", 1.5);
    EXPECT("-0.250000", f"%f", -0.25);
    EXPECT("1.500000", f"%f", 1.5f);
    EXPECT("0.000000", f"%f", 0.0);

    EXPECT("1.5", f"%g", 1.5);
    EXPECT("100000", f"%g", 100000.0);
    EXPECT("1e+06", f"%g", 1e6);
    EXPECT("0.0001", f"%g", 0.0001);

    EXPECT_PRINTF("%a", f"%a", 1.0);
    EXPECT_PRINTF("%a", f"%a", -0.5);

    /* C99: 'l' has no effect on f, e, g and a. Remove this if you reject %lf on purpose. */
    EXPECT("1.500000", f"%lf", 1.5);
}

/* ------------------------------------------------------------------------- */
/* '*' width and precision                                                   */
/* ------------------------------------------------------------------------- */

/*
 * Width 0 and precision 1 don't change integer output, so these only check
 * that '*' consumes the right arguments. Padding is in test_pending.
 */
static void test_star_args(void)
{
    EXPECT("42|7", f"%*d|%d", 0, 42, 7);
    EXPECT("42|7", f"%.*d|%d", 1, 42, 7);
    EXPECT("42|7", f"%*.*d|%d", 0, 1, 42, 7);
}

/* ------------------------------------------------------------------------- */
/* Several specifiers                                                        */
/* ------------------------------------------------------------------------- */

static void test_multiple_specifiers(void)
{
    /* each specifier must take the next argument */
    EXPECT("123", f"%d%d%d", 1, 2, 3);
    EXPECT("-1 mid 4294967295", f"%d %s %u", -1, "mid", -1);
    EXPECT("ff-FF-377-11111111", f"%x-%X-%o-%b", 255, 255, 255, 255);
    EXPECT("a=1, b=two, c=3.500000", f"a=%d, b=%s, c=%f", 1, "two", 3.5);
}

/* ------------------------------------------------------------------------- */
/* Errors                                                                    */
/* (passing an argument of the wrong type is undefined behavior, not tested) */
/* ------------------------------------------------------------------------- */

static void test_arg_count_errors(void)
{
    char arr[8]   = "x";
    CGS_StrBuf sb = {.chars = arr, .cap = sizeof arr, .len = 1};

    EXPECT_ERR(CGS_BAD_FORMAT, f"%d");
    EXPECT_ERR(CGS_BAD_FORMAT, f"%d %d", 1);
    EXPECT_ERR(CGS_BAD_FORMAT, f"%*d", 5);
    EXPECT_ERR(CGS_BAD_FORMAT, f"%*.*d", 5, 1);

    EXPECT_ERR(CGS_BAD_FORMAT, f"%Hs");
    EXPECT_ERR(CGS_BAD_FORMAT, f"%DS");
    EXPECT_ERR(CGS_BAD_FORMAT, f"%zs %zS", sb);
}

/* A writer that fails when asked to write the '+' sign of %+d. */
typedef struct RejectPlusWriter
{
    CGS_Writer base;
} RejectPlusWriter;

static CGS_Error reject_plus_write(CGS_Writer *dst, CGS_StrView str)
{
    (void)dst;
    if (str.len == 1 && str.chars[0] == '+')
        return (CGS_Error) {CGS_IO_ERROR};
    return (CGS_Error) {CGS_OK};
}

/* A failed write must be returned, not overwritten by the write after it. */
static void test_writer_errors(void)
{
    RejectPlusWriter w = {.base = {.write = reject_plus_write}};

    check_error(
        __FILE__, __LINE__, "cgs_appendi(writer that rejects '+', f\"%+d\", 5)",
        cgs_appendi(&w.base, f"%+d", 5), CGS_IO_ERROR, "CGS_IO_ERROR"
    );
}

/* ------------------------------------------------------------------------- */
/* char[] destinations                                                       */
/* ------------------------------------------------------------------------- */

static void test_char_array(void)
{
    /* appends to what's already there */
    EXPECT_TRUNC(32, "ab", "ab1", f"%d", 1);
    EXPECT_TRUNC(32, "x=", "x=-5, y=hi", f"%d, y=%s", -5, "hi");

    /* never writes past sizeof, and keeps the NUL */
    EXPECT_TRUNC(8, "", "0123456", f"%s", "0123456789");
    EXPECT_TRUNC(8, "", "abcdefg", f"abcdefghij");
    EXPECT_TRUNC(8, "", "1234567", f"%d", 123456789);
    EXPECT_TRUNC(8, "", "1234-56", f"%d-%d", 1234, 5678);
    EXPECT_TRUNC(8, "abcde", "abcde12", f"%d", 12345);
    EXPECT_TRUNC(8, "abcdefg", "abcdefg", f"%d", 1);
    EXPECT_TRUNC(8, "", "fffffff", f"%llx", ULLONG_MAX);

    /* exact fit */
    EXPECT_TRUNC(4, "", "123", f"%d", 123);
    EXPECT_TRUNC(1, "", "", f"%d", 5);
}

/* ------------------------------------------------------------------------- */
/* CGS_StrBuf destinations                                                   */
/* ------------------------------------------------------------------------- */

/* Appends, never writes past cap, keeps the NUL, and keeps len in sync. */
static void test_strbuf_dest(void)
{
    EXPECT_STRBUF(32, "ab", "ab1", f"%d", 1);
    EXPECT_STRBUF(32, "", "x=-5, y=hi", f"x=%d, y=%s", -5, "hi");

    EXPECT_STRBUF(8, "", "0123456", f"%s", "0123456789");
    EXPECT_STRBUF(8, "", "1234-56", f"%d-%d", 1234, 5678);
    EXPECT_STRBUF(8, "abcde", "abcde12", f"%d", 12345);
    EXPECT_STRBUF(8, "abcdefg", "abcdefg", f"%d", 1);

    EXPECT_STRBUF(4, "", "123", f"%d", 123);
    EXPECT_STRBUF(1, "", "", f"%d", 5);

    /* when it fits, it succeeds */
    {
        char arr[16]  = "";
        CGS_StrBuf sb = {.chars = arr, .cap = sizeof arr, .len = 0};

        CHECK_OK(cgs_appendi(&sb, f"%d-%s", 1, "a"));
        check_strbuf(__FILE__, __LINE__, &sb, "1-a");
    }
}

/* ------------------------------------------------------------------------- */
/* CGS_MutStrRef destinations                                                */
/* ------------------------------------------------------------------------- */

static void test_mutstr_ref_dest(void)
{
    /* over a char[]: same rules as writing to the char[] directly */
    EXPECT_REF_TRUNC(32, "ab", "ab1", f"%d", 1);
    EXPECT_REF_TRUNC(8, "", "0123456", f"%s", "0123456789");
    EXPECT_REF_TRUNC(8, "abcde", "abcde12", f"%d", 12345);
    EXPECT_REF_TRUNC(4, "", "123", f"%d", 123);

    /* over a StrBuf: the StrBuf's len must follow */
    {
        char arr[32]    = "ab";
        CGS_StrBuf sb   = {.chars = arr, .cap = sizeof arr, .len = 2};
        CGS_MutStrRef r = cgs_mutstr_ref(&sb);

        CHECK_OK(cgs_appendi(r, f"%d-%s", 1, "x"));
        check_strbuf(__FILE__, __LINE__, &sb, "ab1-x");
    }

    /* over a DStr with enough room that it doesn't have to grow */
    {
        CGS_DStr s = cgs_dstr_init(64);
        CHECK_OK(cgs_appendi(&s, "ab"));

        CGS_MutStrRef r = cgs_mutstr_ref(&s);
        CHECK_OK(cgs_appendi(r, f"%d-%s", 1, "x"));
        check_dstr(__FILE__, __LINE__, &s, "ab1-x");
        TEST_DSTR_DEINIT(s);
    }
}

/* ------------------------------------------------------------------------- */
/* CGS_DStr destinations                                                     */
/* ------------------------------------------------------------------------- */

static void test_dstr(void)
{
    CGS_DStr s = cgs_dstr_init();

    CHECK_OK(cgs_appendi(&s, f"%d", 1));
    CHECK_OK(cgs_appendi(&s, f" %s", "two"));
    CHECK_OK(cgs_appendi(&s, f"%{3}?"));
    CHECK_OK(cgs_appendi(&s, f"%{12}x"));
    check_dstr(__FILE__, __LINE__, &s, "1 two3c");
    TEST_DSTR_DEINIT(s);

    /* growth past any initial capacity */
    {
        static char want[8192];
        size_t len = 0;

        s = cgs_dstr_init();
        for (int k = 0; k < 1000; k++)
        {
            CHECK_OK(cgs_appendi(&s, f"%d,", k));
            len += snprintf(want + len, sizeof want - len, "%d,", k);
        }
        check_dstr(__FILE__, __LINE__, &s, want);
        TEST_DSTR_DEINIT(s);
    }

    /* a DStr as a string argument: %Ds by value, %DS by pointer */
    s = cgs_dstr_init();
    CHECK_OK(cgs_appendi(&s, "inner"));
    EXPECT("[inner]", f"[%Ds]", s);
    EXPECT("[inner]", f"[%DS]", &s);
    EXPECT("[inner]", f"[%{s}?]");
    EXPECT("[inner]", f"[%{&s}?]");
    {
        CGS_StrView v = cgs_strv(&s, 1, 3);
        EXPECT("nn", f"%Hs", v);
    }
    TEST_DSTR_DEINIT(s);

    /* an empty DStr that never allocated */
    s = cgs_dstr_init();
    EXPECT("<>", f"<%Ds>", s);
    EXPECT("<>", f"<%DS>", &s);
    EXPECT("<>", f"<%{&s}?>");
    check_dstr(__FILE__, __LINE__, &s, "");
    TEST_DSTR_DEINIT(s);
}

/*
 * A string passed as an argument while also being the destination. An argument
 * is read when its specifier is reached, so it includes whatever the same call
 * has already written. The DStr strings are long enough that the append has to
 * reallocate, which frees the storage a %DS view of the same DStr points into
 * if that view is taken before the destination grows.
 */
static void test_self_append(void)
{
    static char init[1001];
    static char want[4096];

    for (int k = 0; k < 1000; k++)
        init[k] = (char)('a' + k % 26);
    init[1000] = '\0';

    CGS_DStr s = cgs_dstr_init();
    CHECK_OK(cgs_appendi(&s, f"%s", init));
    CHECK_OK(cgs_appendi(&s, f"x%DS", &s));
    snprintf(want, sizeof want, "%sx%sx", init, init); /* %DS sees the 'x' */
    check_dstr(__FILE__, __LINE__, &s, want);
    TEST_DSTR_DEINIT(s);

    s = cgs_dstr_init();
    CHECK_OK(cgs_appendi(&s, f"%s", init));
    CHECK_OK(cgs_appendi(&s, f"%DS%DS", &s, &s));
    snprintf(want, sizeof want, "%s%s%s%s", init, init, init, init); /* the 2nd %DS sees the 1st */
    check_dstr(__FILE__, __LINE__, &s, want);
    TEST_DSTR_DEINIT(s);

    s = cgs_dstr_init();
    CHECK_OK(cgs_appendi(&s, f"%s", init));
    CHECK_OK(cgs_appendi(&s, f"[%{&s}?]"));
    snprintf(want, sizeof want, "%s[%s[]", init, init); /* the interp sees the '[' */
    check_dstr(__FILE__, __LINE__, &s, want);
    TEST_DSTR_DEINIT(s);

    /* a StrBuf doesn't reallocate, but the same rule applies */
    {
        char arr[32]  = "ab";
        CGS_StrBuf sb = {.chars = arr, .cap = sizeof arr, .len = 2};

        CHECK_OK(cgs_appendi(&sb, f"%zS%zS", &sb, &sb));
        check_strbuf(__FILE__, __LINE__, &sb, "abababab");
    }
}

/* ------------------------------------------------------------------------- */
/* Not implemented yet                                                       */
/* ------------------------------------------------------------------------- */

#ifdef CGS_TEST_PENDING
static void test_pending(void)
{
    /* width, '-' and '0' */
    EXPECT("   42", f"%5d", 42);
    EXPECT("42", f"%1d", 42);
    EXPECT("42   |", f"%-5d|", 42);
    EXPECT("00042", f"%05d", 42);
    EXPECT("-0042", f"%05d", -42);
    EXPECT("+0042", f"%+05d", 42);
    EXPECT("42   |", f"%-05d|", 42); /* '-' overrides '0' */
    EXPECT("   ab|", f"%5s|", "ab");
    EXPECT("ab   |", f"%-5s|", "ab");
    EXPECT("   42", f"%*d", 5, 42);
    EXPECT("42   |", f"%*d|", -5, 42); /* a negative '*' width means '-' */
    EXPECT("ab   |", f"%*s|", -5, "ab");
    EXPECT("42   |", f"%-*d|", -5, 42); /* '-' given twice is still '-' */

    /* precision */
    EXPECT("007", f"%.3d", 7);
    EXPECT("-007", f"%.3d", -7);
    EXPECT("     007", f"%8.3d", 7);
    EXPECT("     007", f"%08.3d", 7); /* '0' is ignored when there's a precision */
    EXPECT("", f"%.0d", 0);
    EXPECT("42", f"%.*d", -1, 42); /* a negative '*' precision is as if omitted */
    EXPECT("42", f"%.*d", -5, 42); /* any negative value, not just -1 */
    EXPECT("0", f"%.*d", -5, 0);   /* as if omitted, not precision 0 (which prints "") */
    EXPECT("hello", f"%.*s", -3, "hello");
    EXPECT("he", f"%.2s", "hello");
    EXPECT("hel", f"%.*s", 3, "hello");
    EXPECT("3.14", f"%.2f", 3.14159);
    EXPECT("   3.142", f"%8.3f", 3.14159);
    EXPECT("3", f"%.0f", 2.6);

    /* width and precision on a StrView; a precision past its length must still stop at the view's end */
    {
        char text[]       = "hello, world";
        CGS_StrView hello = cgs_strv(text, 0, 5);

        EXPECT("hel", f"%.3Hs", hello);
        EXPECT("hello", f"%.20Hs", hello);
        EXPECT("  hello|", f"%7Hs|", hello);
        EXPECT("hello  |", f"%-7Hs|", hello);
    }

    /* '#' */
    EXPECT("0xff", f"%#x", 255);
    EXPECT("0XFF", f"%#X", 255);
    EXPECT("010", f"%#o", 8);
    EXPECT("0", f"%#x", 0);
    EXPECT("0b101", f"%#b", 5);

    /* '+' on floats */
    EXPECT("+2.0", f"%+.1f", 2.0);
    EXPECT("+1.500000", f"%+f", 1.5);

    /* conversions without a case yet */
    EXPECT("1.500000e+00", f"%e", 1.5);
    EXPECT("A", f"%c", 'A');
}
#endif

/* ------------------------------------------------------------------------- */

int main(void)
{
    test_literals();
    test_plain_literals();
    test_basic_integers();
    test_conversion_decides_signedness();
    test_default_int_truncation();
    test_length_modifiers();
    test_size_types();
    test_exact_width();
    test_plus_flag();
    test_bool_args();
    test_question_mark();
    test_interpolation();
    test_strings();
    test_strview();
    test_zstrview();
    test_strbuf_args();
    test_mutstr_ref_args();
    test_string_types_mixed();
    test_floats();
    test_star_args();
    test_multiple_specifiers();
    test_arg_count_errors();
    test_writer_errors();
    test_char_array();
    test_strbuf_dest();
    test_mutstr_ref_dest();
    test_dstr();
    test_self_append();
#ifdef CGS_TEST_PENDING
    test_pending();
#endif

    printf("%d/%d checks passed\n", g_checks - g_failures, g_checks);
    return g_failures != 0;
}