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
 * Define CGS_TEST_PENDING to also run the tests for features that are still
 * TODO: width, precision, the '-', '0' and '#' flags, '+' on floats, %e and %c.
 */

#include "cgs.h" /* adjust to your header */

#include <inttypes.h>
#include <limits.h>
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
/* Strings and floats                                                        */
/* ------------------------------------------------------------------------- */

static void test_strings(void)
{
    char arr[]    = "array";
    const char *p = "ptr";

    EXPECT("hello", f"%s", "hello");
    EXPECT("", f"%s", "");
    EXPECT("array", f"%s", arr);
    EXPECT("[ptr]", f"[%s]", p);
}

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
    EXPECT_ERR(CGS_BAD_FORMAT, f"%d");
    EXPECT_ERR(CGS_BAD_FORMAT, f"%d %d", 1);
    EXPECT_ERR(CGS_BAD_FORMAT, f"%*d", 5);
    EXPECT_ERR(CGS_BAD_FORMAT, f"%*.*d", 5, 1);
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
/* CGS_DStr destinations                                                     */
/* ------------------------------------------------------------------------- */

/* Reads the DStr back through %s (CGS_DStr*) and compares. */
static void check_dstr(const char *file, int line, CGS_DStr *s, const char *want)
{
    static char got[8192];
    got[0] = '\0';

    CGS_Error err = cgs_appendi(got, f"%s", s);
    check_output(file, line, "contents of the DStr", err, got, want);
}

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

    /* a DStr as a %s argument, by value and by pointer */
    s = cgs_dstr_init();
    CHECK_OK(cgs_appendi(&s, "inner"));
    EXPECT("[inner]", f"[%s]", s);
    EXPECT("[inner]", f"[%s]", &s);
    EXPECT("[inner]", f"[%{&s}?]");
    TEST_DSTR_DEINIT(s);
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

    /* precision */
    EXPECT("007", f"%.3d", 7);
    EXPECT("-007", f"%.3d", -7);
    EXPECT("     007", f"%8.3d", 7);
    EXPECT("     007", f"%08.3d", 7); /* '0' is ignored when there's a precision */
    EXPECT("", f"%.0d", 0);
    EXPECT("42", f"%.*d", -1, 42); /* a negative '*' precision is as if omitted */
    EXPECT("he", f"%.2s", "hello");
    EXPECT("hel", f"%.*s", 3, "hello");
    EXPECT("3.14", f"%.2f", 3.14159);
    EXPECT("   3.142", f"%8.3f", 3.14159);
    EXPECT("3", f"%.0f", 2.6);

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
    test_question_mark();
    test_interpolation();
    test_strings();
    test_floats();
    test_star_args();
    test_multiple_specifiers();
    test_arg_count_errors();
    test_char_array();
    test_dstr();
    #ifdef CGS_TEST_PENDING
    test_pending();
    #endif

    printf("%d/%d checks passed\n", g_checks - g_failures, g_checks);
    return g_failures != 0;
}
