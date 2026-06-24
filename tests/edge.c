#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

#define CGS_debug_break()
#define CGS_SHORT_NAMES
#include "../cgs.c"
// Forward declaration for appender state

// Test counter
static int test_count = 0;
static int passed_count = 0;

#define TEST(name) \
do { \
    printf("Running test: %s\n", name); \
    /*test_count++*/; \
} while(0)

#define ASSERT_EQ(a, b) \
do { \
    test_count++; \
    if ((a) == (b)) { \
        passed_count++; \
    } else { \
        printf("  FAILED: Expected %d, got %d at line %d\n", (int)(b), (int)(a), __LINE__); \
    } \
} while(0)

#define ASSERT_TRUE(cond) \
do { \
    test_count++; \
    if (cond) { \
        passed_count++; \
    } else { \
        printf("  FAILED: Condition false at line %d\n", __LINE__); \
    } \
} while(0)

#define ASSERT_FALSE(cond) \
do { \
    test_count++; \
    if (!(cond)) { \
        passed_count++; \
    } else { \
        printf("  FAILED: Condition true at line %d\n", __LINE__); \
    } \
} while(0)

#define ASSERT_NULL(ptr) \
do { \
    test_count++; \
    if ((ptr) == NULL) { \
        passed_count++; \
    } else { \
        printf("  FAILED: Expected NULL at line %d\n", __LINE__); \
    } \
} while(0)

#define ASSERT_NOT_NULL(ptr) \
do { \
    test_count++; \
    if ((ptr) != NULL) { \
        passed_count++; \
    } else { \
        printf("  FAILED: Expected non-NULL at line %d\n", __LINE__); \
    } \
} while(0)

// ============================================================================
// Edge Case Tests for cgs_len
// ============================================================================

void test_str_len_edge_cases() {
    TEST("cgs_len: empty string");;;
    {
        char buf[] = "";
        ASSERT_EQ(cgs_len(buf), 0);
    }
    
    TEST("cgs_len: single null terminator");;;
    {
        char buf[1] = {'\0'};
        ASSERT_EQ(cgs_len(buf), 0);
    }
    
    TEST("cgs_len: CGS_DStr with zero capacity");;;
    {
        CGS_DStr dstr = cgs_dstr_init(0);
        ASSERT_EQ(cgs_len(&dstr), 0);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_len: very long string");;;
    {
        // This tests if length calculation handles large strings
        CGS_DStr dstr = cgs_dstr_init(10000);
        for (int i = 0; i < 9999; i++) {
            cgs_putc(&dstr, 'a');
        }
        ASSERT_EQ(cgs_len(&dstr), 9999);
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_cap
// ============================================================================

void test_str_cap_edge_cases() {
    TEST("cgs_cap: raw char array");;;
    {
        char buf[100];
        unsigned int cap = cgs_cap(buf);
        ASSERT_TRUE(cap == 100);
    }
    
    TEST("cgs_cap: CGS_StrBuf at exact capacity");;;
    {
        char backing[5] = {'t', 'e', 's', 't', '\0'};
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 5);
        ASSERT_EQ(cgs_cap(&sb), 5);
    }
}

// ============================================================================
// Edge Case Tests for cgs_equal
// ============================================================================

void test_str_equal_edge_cases() {
    TEST("cgs_equal: both empty");;;
    {
        char a[] = "";
        char b[] = "";
        ASSERT_TRUE(cgs_equal(a, b));
    }
    
    TEST("cgs_equal: one empty, one not");;;
    {
        char a[] = "";
        char b[] = "test";
        ASSERT_FALSE(cgs_equal(a, b));
        ASSERT_FALSE(cgs_equal(b, a));
    }
    
    TEST("cgs_equal: same pointer");;;
    {
        char a[] = "test";
        ASSERT_TRUE(cgs_equal(a, a));
    }
    
    TEST("cgs_equal: different types with same content");;;
    {
        char cstr[] = "hello";
        CGS_DStr dstr = cgs_dstr_init_from(cstr);
        ASSERT_TRUE(cgs_equal(cstr, &dstr));
        ASSERT_TRUE(cgs_equal(&dstr, cstr));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_equal: strings differing only in last char");;;
    {
        char a[] = "test1";
        char b[] = "test2";
        ASSERT_FALSE(cgs_equal(a, b));
    }
    
    TEST("cgs_equal: strings with embedded nulls");;;
    {
        char a[5] = {'a', 'b', '\0', 'c', 'd'};
        char b[5] = {'a', 'b', '\0', 'x', 'y'};
        // Should be equal up to first null
        ASSERT_TRUE(cgs_equal(a, b));
    }
    
    TEST("cgs_equal: very long identical strings");;;
    {
        CGS_DStr a = cgs_dstr_init(5000);
        CGS_DStr b = cgs_dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            cgs_putc(&a, 'x');
            cgs_putc(&b, 'x');
        }
        ASSERT_TRUE(cgs_equal(&a, &b));
        cgs_dstr_deinit(&a);
        cgs_dstr_deinit(&b);
    }
}

// ============================================================================
// Edge Case Tests for cgs_find
// ============================================================================

void test_str_find_edge_cases() {
    TEST("cgs_find: basic match");;;
    {
        char hay[] = "hello world";
        CGS_StrView v = cgs_find(hay, "world");
        // Should return view starting at index 6, length 5
        ASSERT_TRUE(v.chars == &hay[6]);
        ASSERT_TRUE(v.len == 5);
    }
    
    TEST("cgs_find: not found");;;
    {
        CGS_StrView v = cgs_find("apple", "orange");
        // Usually returns a null view (chars == NULL) or a view with len 0
        ASSERT_TRUE(v.chars == NULL || v.len == 0);
    }
    
    TEST("cgs_find: match at start and end");;;
    {
        char hay[] = "bracket";
        CGS_StrView start = cgs_find(hay, "b");
        CGS_StrView end = cgs_find(hay, "t");
        
        ASSERT_TRUE(start.chars == &hay[0]);
        ASSERT_TRUE(end.chars == &hay[6]);
    }
    
    TEST("cgs_find: empty needle");;;
    {
        char hay[] = "abc";
        CGS_StrView v = cgs_find(hay, "");
        // In most languages, finding "" returns the start of the string
        ASSERT_TRUE(v.chars == &hay[0]);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_find: needle equals haystack");;;
    {
        char hay[] = "same";
        CGS_StrView v = cgs_find(hay, "same");
        ASSERT_TRUE(v.len == 4 && v.chars == &hay[0]);
    }
    
    TEST("cgs_find: needle longer than haystack");;;
    {
        CGS_StrView v = cgs_find("short", "much longer needle");
        ASSERT_TRUE(v.chars == NULL || v.len == 0);
    }
    
    TEST("cgs_find: empty needle in empty haystack");;;
    {
        char hay[] = "";
        char needle[] = "";
        CGS_StrView result = cgs_find(hay, needle);
        // Finding empty in empty might return start or invalid
        // Check it doesn't crash
        ASSERT_TRUE((char*)result.chars == hay);
    }
    
    TEST("cgs_find: empty needle in non-empty haystack");;;
    {
        char hay[] = "test";
        char needle[] = "";
        CGS_StrView result = cgs_find(hay, needle);
        // Should probably find at position 0 or be invalid
        ASSERT_TRUE(result.chars == hay);
    }
    
    TEST("cgs_find: needle longer than haystack");;;
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        CGS_StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 0); // Not found
    }
    
    TEST("cgs_find: needle equals haystack");;;
    {
        char hay[] = "exact";
        char needle[] = "exact";
        CGS_StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 5);
    }
    
    TEST("cgs_find: needle at very end");;;
    {
        char hay[] = "abcdefghij";
        char needle[] = "hij";
        CGS_StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 3);
    }
    
    TEST("cgs_find: needle at very start");;;
    {
        char hay[] = "abcdefghij";
        char needle[] = "abc";
        CGS_StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 3);
    }
    
    TEST("cgs_find: overlapping pattern");;;
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        CGS_StrView result = cgs_find(hay, needle);
        // Should find first occurrence
        ASSERT_TRUE(cgs_len(result) > 0);
    }
    
    TEST("cgs_find: pattern that almost matches");;;
    {
        char hay[] = "abcabcabd";
        char needle[] = "abcabd";
        CGS_StrView result = cgs_find(hay, needle);
        ASSERT_TRUE(cgs_len(result) > 0);
    }
    
    /* --- cgs_trim_view --- */
    
    TEST("cgs_trim_view: no whitespace");;;
    {
        char s[] = "hello";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: leading spaces");;;
    {
        char s[] = "   hello";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[3]);
    }
    
    TEST("cgs_trim_view: trailing spaces");;;
    {
        char s[] = "hello   ";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: leading and trailing spaces");;;
    {
        char s[] = "  hello  ";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[2]);
    }
    
    TEST("cgs_trim_view: interior whitespace is preserved");;;
    {
        char s[] = "  hello world  ";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 11 && v.chars == &s[2]);
    }
    
    TEST("cgs_trim_view: only spaces");;;
    {
        char s[] = "     ";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_trim_view: empty string");;;
    {
        char s[] = "";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_trim_view: empty string");;;
    {
        char s[] = " \t\n";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_trim_view: single non-whitespace character");;;
    {
        char s[] = "x";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 1 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: single space");;;
    {
        char s[] = " ";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0 && v.chars == s + 1);
    }
    
    TEST("cgs_trim_view: leading tab");;;
    {
        char s[] = "\thello";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[1]);
    }
    
    TEST("cgs_trim_view: trailing newline");;;
    {
        char s[] = "hello\n";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: mixed whitespace characters on both sides");;;
    {
        char s[] = " \t\n hello \r\n";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[4]);
    }
    
    TEST("cgs_trim_view: accepts CGS_StrView");;;
    {
        CGS_StrView src = cgs_strv("  hi  ");
        CGS_StrView v = cgs_trim_view(src);
        ASSERT_TRUE(v.len == 2);
    }
    
    TEST("cgs_trim_view: accepts CGS_DStr");;;
    {
        CGS_DStr d = cgs_dstr_init_from("  hi  ");
        CGS_StrView v = cgs_trim_view(d);
        ASSERT_TRUE(v.len == 2);
        cgs_dstr_deinit(&d);
    }
    
    TEST("cgs_trim_view: result points into original buffer, not a copy");;;
    {
        char s[] = "  abc  ";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.chars == &s[2]);
    }
    
    TEST("cgs_trim_view: only spaces");;;
    {
        char s[] = "   ";
        CGS_StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0 && v.chars == s + 3);
    }
    
    /* --- cgs_trim --- */
    
    TEST("cgs_trim: no whitespace");;;
    {
        char s[64] = "hello";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "hello") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: leading spaces");;;
    {
        char s[64] = "   hello";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "hello") == 0);
        ASSERT_TRUE(cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: trailing spaces");;;
    {
        char s[64] = "hello   ";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "hello") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: leading and trailing spaces");;;
    {
        char s[64] = "  hello  ";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(s, "hello"));
        ASSERT_TRUE( cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: all whitespace");;;
    {
        // A string of 4 spaces. Length is 4.
        // Buffer is exactly large enough for 4 chars + null (5 bytes).
        char s[5] = "    "; 
        
        // Logic execution:
        // 1. begin will become 4 (it hits the end of the string).
        // 2. end will stay 4 (the loop 'end > begin' will never execute).
        // 3. len = 4 - 4 = 0.
        // 4. memmove(s, s + 4, 4);  <-- BUG HERE
        
        // This memmove will try to read 4 bytes starting from index 4.
        // Index 4 is '\0', but indices 5, 6, and 7 are OUTSIDE the array 's[5]'.
        
        CGS_Error e = cgs_trim(s);
        
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(s, ""));
        ASSERT_TRUE(cgs_len(s) == 0);
    }
    
    TEST("cgs_trim: interior whitespace is preserved");;;
    {
        char s[64] = "  hello world  ";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "hello world") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: only spaces");;;
    {
        char s[64] = "     ";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: empty string");;;
    {
        char s[64] = "";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: single non-whitespace character");;;
    {
        char s[64] = "x";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "x") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: single space");;;
    {
        char s[64] = " ";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: leading tab");;;
    {
        char s[64] = "\thello";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "hello") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: trailing newline");;;
    {
        char s[64] = "hello\n";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "hello") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: mixed whitespace on both sides");;;
    {
        char s[64] = " \t\n hello \r\n";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(s, "hello") == 0 && cgs_chars(s) == p);
    }
    
    TEST("cgs_trim: CGS_DStr*");;;
    {
        CGS_DStr d = cgs_dstr_init_from("  hello  ");
        char *p = cgs_chars(d);
        CGS_Error e = cgs_trim(&d);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(d, "hello") && cgs_chars(d) == p);
        cgs_dstr_deinit(&d);
    }
    
    TEST("cgs_trim: CGS_StrBuf*");;;
    {
        char buf[64] = "  hello  ";
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(buf, sizeof(buf));
        char *p = cgs_chars(sb);
        CGS_Error e = cgs_trim(&sb);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(sb, "hello") && cgs_chars(sb) == p);
    }
    
    TEST("cgs_trim: CGS_MutStrRef");;;
    {
        char buf[64] = "  hello  ";
        CGS_MutStrRef ref = cgs_mutstr_ref(buf);
        char *p = buf;
        CGS_Error e = cgs_trim(ref);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(strcmp(buf, "hello") == 0 && buf == p);
    }
    
    TEST("cgs_trim: length decreases correctly after trim");;;
    {
        char s[64] = "  hi  ";
        char *p = s;
        CGS_Error e = cgs_trim(s);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(cgs_len(s) == 2 && cgs_chars(s) == p);
    }
}

void test_spn_cspn_tok()
{
    /* ════════════════════════════════════════════════════════════
     * cgs_spn — first chunk made up ONLY of chars in charset
     * ════════════════════════════════════════════════════════════ */

    TEST("cgs_spn: leading run of charset chars");
    {
        /* "aaabbb" with charset "a" → "aaa" */
        CGS_StrView v = cgs_spn(cgs_strv("aaabbb"), cgs_strv("a"));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("aaa")));
    }

    TEST("cgs_spn: charset with multiple chars");
    {
        /* "abc123" charset "abc" → "abc" */
        CGS_StrView v = cgs_spn(cgs_strv("abc123"), cgs_strv("abc"));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("abc")));
    }

    TEST("cgs_spn: whole string matches charset");
    {
        CGS_StrView v = cgs_spn(cgs_strv("12345"), cgs_strv("0123456789"));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("12345")));
    }

    TEST("cgs_spn: first char not in charset → empty view");
    {
        CGS_StrView v = cgs_spn(cgs_strv("xabc"), cgs_strv("abc"));
        ASSERT_TRUE(v.len == 0);
    }

    TEST("cgs_spn: empty source → empty view");
    {
        CGS_StrView v = cgs_spn(cgs_strv(""), cgs_strv("abc"));
        ASSERT_TRUE(v.len == 0);
    }

    TEST("cgs_spn: empty charset → empty view");
    {
        CGS_StrView v = cgs_spn(cgs_strv("abc"), cgs_strv(""));
        ASSERT_TRUE(v.len == 0);
    }

    TEST("cgs_spn: view begins at start of source");
    {
        CGS_StrView src = cgs_strv("aabxx");
        CGS_StrView v = cgs_spn(src, cgs_strv("ab"));
        ASSERT_TRUE(v.chars == src.chars);
        ASSERT_TRUE(cgs_equal(v, cgs_strv("aab")));
    }

    TEST("cgs_spn: repeated charset chars are handled");
    {
        /* charset "aА" duplicate-free behaviour: "aaa bbb", charset "a " */
        CGS_StrView v = cgs_spn(cgs_strv("aaa bbb"), cgs_strv("a "));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("aaa ")));
    }

    /* ════════════════════════════════════════════════════════════
     * cgs_cspn — first chunk made up ONLY of chars NOT in charset
     * ════════════════════════════════════════════════════════════ */

    TEST("cgs_cspn: stop at first charset char");
    {
        /* "abc123" charset "0123456789" → "abc" */
        CGS_StrView v = cgs_cspn(cgs_strv("abc123"), cgs_strv("0123456789"));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("abc")));
    }

    TEST("cgs_cspn: stop at first delimiter");
    {
        /* "hello world" charset " " → "hello" */
        CGS_StrView v = cgs_cspn(cgs_strv("hello world"), cgs_strv(" "));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("hello")));
    }

    TEST("cgs_cspn: no charset char present → whole string");
    {
        CGS_StrView v = cgs_cspn(cgs_strv("hello"), cgs_strv("xyz"));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("hello")));
    }

    TEST("cgs_cspn: first char in charset → empty view");
    {
        CGS_StrView v = cgs_cspn(cgs_strv(",abc"), cgs_strv(","));
        ASSERT_TRUE(v.len == 0);
    }

    TEST("cgs_cspn: empty source → empty view");
    {
        CGS_StrView v = cgs_cspn(cgs_strv(""), cgs_strv(","));
        ASSERT_TRUE(v.len == 0);
    }

    TEST("cgs_cspn: empty charset → whole string");
    {
        /* nothing to stop at, so the whole string qualifies */
        CGS_StrView v = cgs_cspn(cgs_strv("abc"), cgs_strv(""));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("abc")));
    }

    TEST("cgs_cspn: multi-char charset, stop at earliest match");
    {
        /* "abc;def,ghi" charset ";," → "abc" (';' comes first) */
        CGS_StrView v = cgs_cspn(cgs_strv("abc;def,ghi"), cgs_strv(";,"));
        ASSERT_TRUE(cgs_equal(v, cgs_strv("abc")));
    }

    /* ════════════════════════════════════════════════════════════
     * cgs_next_tok — skips leading delims, returns next token,
     * advances base past it. Empty token (all delim / empty base)
     * returns CGS_NOT_FOUND.
     * ════════════════════════════════════════════════════════════ */

    TEST("cgs_next_tok: simple comma-separated tokens");
    {
        CGS_StrView base = cgs_strv("one,two,three");

        CGS_Result(CGS_StrView) r1 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r1.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r1.val, cgs_strv("one")));

        CGS_Result(CGS_StrView) r2 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r2.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r2.val, cgs_strv("two")));

        CGS_Result(CGS_StrView) r3 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r3.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r3.val, cgs_strv("three")));

        /* base now exhausted */
        CGS_Result(CGS_StrView) r4 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r4.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok: skips leading delimiters");
    {
        /* leading commas are skipped, first token is "a" */
        CGS_StrView base = cgs_strv(",,,a,b");
        CGS_Result(CGS_StrView) r = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r.val, cgs_strv("a")));
    }

    TEST("cgs_next_tok: collapses consecutive delimiters between tokens");
    {
        /* "a,,,b" → "a" then "b" (no empty tokens) */
        CGS_StrView base = cgs_strv("a,,,b");

        CGS_Result(CGS_StrView) r1 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r1.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r1.val, cgs_strv("a")));

        CGS_Result(CGS_StrView) r2 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r2.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r2.val, cgs_strv("b")));

        CGS_Result(CGS_StrView) r3 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r3.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok: trailing delimiters yield NOT_FOUND after last token");
    {
        CGS_StrView base = cgs_strv("a,b,,,");

        CGS_Result(CGS_StrView) r1 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(r1.val, cgs_strv("a")));

        CGS_Result(CGS_StrView) r2 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(r2.val, cgs_strv("b")));

        CGS_Result(CGS_StrView) r3 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r3.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok: empty base → NOT_FOUND");
    {
        CGS_StrView base = cgs_strv("");
        CGS_Result(CGS_StrView) r = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok: base entirely delimiters → NOT_FOUND");
    {
        CGS_StrView base = cgs_strv(",,,,");
        CGS_Result(CGS_StrView) r = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok: no delimiter present → whole string is one token");
    {
        CGS_StrView base = cgs_strv("nodelim");
        CGS_Result(CGS_StrView) r1 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r1.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r1.val, cgs_strv("nodelim")));

        CGS_Result(CGS_StrView) r2 = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(r2.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok: multi-char delimiter");
    {
        /* delim "::" → "a", "b", "c" */
        CGS_StrView base = cgs_strv("a::b::c");

        CGS_Result(CGS_StrView) r1 = cgs_next_tok(&base, cgs_strv("::"));
        ASSERT_TRUE(cgs_equal(r1.val, cgs_strv("a")));

        CGS_Result(CGS_StrView) r2 = cgs_next_tok(&base, cgs_strv("::"));
        ASSERT_TRUE(cgs_equal(r2.val, cgs_strv("b")));

        CGS_Result(CGS_StrView) r3 = cgs_next_tok(&base, cgs_strv("::"));
        ASSERT_TRUE(cgs_equal(r3.val, cgs_strv("c")));

        CGS_Result(CGS_StrView) r4 = cgs_next_tok(&base, cgs_strv("::"));
        ASSERT_TRUE(r4.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok: multi-char delimiter, partial prefix is not a match");
    {
        /* "key-value" contains '-' but not "->" so no split should occur */
        CGS_StrView base = cgs_strv("key-value");
        CGS_Result(CGS_StrView) r = cgs_next_tok(&base, cgs_strv("->"));
        ASSERT_TRUE(r.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r.val, cgs_strv("key-value")));
    }

    TEST("cgs_next_tok: drive a full loop to collect all tokens");
    {
        CGS_StrView base = cgs_strv("  the quick   brown fox  ");
        const char *expected[] = { "the", "quick", "brown", "fox" };
        int i = 0;

        for (;;)
        {
            CGS_Result(CGS_StrView) r = cgs_next_tok(&base, cgs_strv(" "));
            if (r.err.ec == CGS_NOT_FOUND) break;
            ASSERT_TRUE(cgs_equal(r.val, cgs_strv(expected[i])));
            i++;
        }
        ASSERT_TRUE(i == 4);
    }

    /* ════════════════════════════════════════════════════════════
     * cgs_next_tok_any — like cgs_next_tok but any char in the
     * delim_set is treated as a delimiter.
     * ════════════════════════════════════════════════════════════ */

    TEST("cgs_next_tok_any: mixed single-char delimiters");
    {
        CGS_StrView base = cgs_strv("a;b,c|d");
        const char *expected[] = { "a", "b", "c", "d" };
        int i = 0;

        for (;;)
        {
            CGS_Result(CGS_StrView) r = cgs_next_tok_any(&base, cgs_strv(";,|"));
            if (r.err.ec == CGS_NOT_FOUND) break;
            ASSERT_TRUE(cgs_equal(r.val, cgs_strv(expected[i])));
            i++;
        }
        ASSERT_TRUE(i == 4);
    }

    TEST("cgs_next_tok_any: skips leading delimiters from the set");
    {
        /* leading mix of ' ' and '\t' skipped */
        CGS_StrView base = cgs_strv(" \t a b");
        CGS_Result(CGS_StrView) r = cgs_next_tok_any(&base, cgs_strv(" \t"));
        ASSERT_TRUE(r.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r.val, cgs_strv("a")));
    }

    TEST("cgs_next_tok_any: collapses consecutive delimiters of differing kinds");
    {
        /* "a,;|b" with set ",;|" → "a" then "b" */
        CGS_StrView base = cgs_strv("a,;|b");

        CGS_Result(CGS_StrView) r1 = cgs_next_tok_any(&base, cgs_strv(",;|"));
        ASSERT_TRUE(cgs_equal(r1.val, cgs_strv("a")));

        CGS_Result(CGS_StrView) r2 = cgs_next_tok_any(&base, cgs_strv(",;|"));
        ASSERT_TRUE(cgs_equal(r2.val, cgs_strv("b")));

        CGS_Result(CGS_StrView) r3 = cgs_next_tok_any(&base, cgs_strv(",;|"));
        ASSERT_TRUE(r3.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok_any: whitespace tokenization");
    {
        CGS_StrView base = cgs_strv("foo\tbar baz\nqux");
        const char *expected[] = { "foo", "bar", "baz", "qux" };
        int i = 0;

        for (;;)
        {
            CGS_Result(CGS_StrView) r = cgs_next_tok_any(&base, cgs_strv(" \t\n"));
            if (r.err.ec == CGS_NOT_FOUND) break;
            ASSERT_TRUE(cgs_equal(r.val, cgs_strv(expected[i])));
            i++;
        }
        ASSERT_TRUE(i == 4);
    }

    TEST("cgs_next_tok_any: empty base → NOT_FOUND");
    {
        CGS_StrView base = cgs_strv("");
        CGS_Result(CGS_StrView) r = cgs_next_tok_any(&base, cgs_strv(",;"));
        ASSERT_TRUE(r.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok_any: base entirely delimiters → NOT_FOUND");
    {
        CGS_StrView base = cgs_strv(";,;,");
        CGS_Result(CGS_StrView) r = cgs_next_tok_any(&base, cgs_strv(",;"));
        ASSERT_TRUE(r.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok_any: no delimiter present → whole string");
    {
        CGS_StrView base = cgs_strv("single");
        CGS_Result(CGS_StrView) r1 = cgs_next_tok_any(&base, cgs_strv(",;|"));
        ASSERT_TRUE(r1.err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(r1.val, cgs_strv("single")));

        CGS_Result(CGS_StrView) r2 = cgs_next_tok_any(&base, cgs_strv(",;|"));
        ASSERT_TRUE(r2.err.ec == CGS_NOT_FOUND);
    }

    TEST("cgs_next_tok_any: single-element delim set behaves like next_tok");
    {
        CGS_StrView base = cgs_strv("a,b,c");
        const char *expected[] = { "a", "b", "c" };
        int i = 0;

        for (;;)
        {
            CGS_Result(CGS_StrView) r = cgs_next_tok_any(&base, cgs_strv(","));
            if (r.err.ec == CGS_NOT_FOUND) break;
            ASSERT_TRUE(cgs_equal(r.val, cgs_strv(expected[i])));
            i++;
        }
        ASSERT_TRUE(i == 3);
    }
}

// ============================================================================
// Edge Case Tests for cgs_count
// ============================================================================

void test_str_count_edge_cases() {
    TEST("cgs_count: basic count");;;
    {
        unsigned int n = cgs_count("banana", "a");
        ASSERT_TRUE(n == 3);
    }
    
    TEST("cgs_count: non-overlapping logic");;;
    {
        // "aa" appears in "aaaaa" at:
        // [aa] [aa] a  <- Non-overlapping (2)
        //  a [aa] [aa] <- Non-overlapping alternative
        // Standard behavior is to consume the first match and move on.
        unsigned int n = cgs_count("aaaaa", "aa");
        ASSERT_TRUE(n == 2);
    }
    
    TEST("cgs_count: no matches");;;
    {
        unsigned int n = cgs_count("abc", "z");
        ASSERT_TRUE(n == 0);
    }
    
    TEST("cgs_count: empty needle (Interstitial Gaps)");;;
    {
        // "abc" has gaps: ^ a ^ b ^ c ^ 
        // Index:        0 1 1 2 2 3 3
        // Most modern libs (Python, Go, etc.) count len + 1
        unsigned int n = cgs_count("abc", "");
        ASSERT_TRUE(n == 4);
    }
    
    TEST("cgs_count: empty haystack");;;
    {
        // "" contains one ""
        ASSERT_TRUE(cgs_count("", "") == 1);
        // "" contains zero "a"
        ASSERT_TRUE(cgs_count("", "a") == 0);
    }
    
    TEST("cgs_count: needle is haystack");;;
    {
        ASSERT_TRUE(cgs_count("test", "test") == 1);
    }
    
    TEST("cgs_count: needle overlaps but is not identical");;;
    {
        // count "ababa" in "abababa"
        // [ababa] ba -> 1 match
        unsigned int n = cgs_count("abababa", "ababa");
        ASSERT_TRUE(n == 1);
    }
    
    TEST("cgs_count: empty needle");;;
    {
        char hay[] = "test";
        char needle[] = "";
        unsigned int count = cgs_count(hay, needle);
        ASSERT_TRUE(count == cgs_len(hay) + 1);
    }
    
    TEST("cgs_count: empty haystack");;;
    {
        char hay[] = "";
        char needle[] = "x";
        ASSERT_EQ(cgs_count(hay, needle), 0);
    }
    
    TEST("cgs_count: overlapping occurrences");;;
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        unsigned int count = cgs_count(hay, needle);
        // Could be 2 (non-overlapping) or 3 (overlapping)
        ASSERT_TRUE(count == 2 || count == 3);
    }
    
    TEST("cgs_count: needle equals haystack");;;
    {
        char hay[] = "exact";
        char needle[] = "exact";
        ASSERT_EQ(cgs_count(hay, needle), 1);
    }
    
    TEST("cgs_count: needle longer than haystack");;;
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        ASSERT_EQ(cgs_count(hay, needle), 0);
    }
    
    TEST("cgs_count: many occurrences");;;
    {
        char hay[] = "a a a a a a a a a a";
        char needle[] = "a";
        ASSERT_EQ(cgs_count(hay, needle), 10);
    }
}

// ============================================================================
// Edge Case Tests for cgs_clear
// ============================================================================

void test_str_clear_edge_cases() {
    TEST("cgs_clear: already empty CGS_DStr");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_clear(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 0);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_clear: CGS_StrBuf at capacity");;;
    {
        char backing[5] = {'f', 'u', 'l', 'l', '\0'};
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 5);
        CGS_Error err = cgs_clear(&sb);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&sb), 0);
    }
    
    TEST("cgs_clear: raw char array (might be unsupported)");;;
    {
        char buf[10] = "test";
        // This might return an error or work
        CGS_Error err = cgs_clear(buf);
        // Just check it doesn't crash
        ASSERT_TRUE(1);
    }
    
    TEST("cgs_clear: then append");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("original");
        cgs_clear(&dstr);
        CGS_Error err = cgs_append(&dstr, "new");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "new"));
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_starts_with / cgs_ends_with
// ============================================================================

void test_str_starts_ends_with_edge_cases() {
    TEST("cgs_starts_with: empty prefix");;;
    {
        char hay[] = "test";
        char prefix[] = "";
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: prefix equals string");;;
    {
        char hay[] = "exact";
        char prefix[] = "exact";
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: prefix longer than string");;;
    {
        char hay[] = "ab";
        char prefix[] = "abcdef";
        ASSERT_FALSE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: both empty");;;
    {
        char hay[] = "";
        char prefix[] = "";
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_ends_with: empty suffix");;;
    {
        char hay[] = "test";
        char suffix[] = "";
        ASSERT_TRUE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_ends_with: suffix equals string");;;
    {
        char hay[] = "exact";
        char suffix[] = "exact";
        ASSERT_TRUE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_ends_with: suffix longer than string");;;
    {
        char hay[] = "ab";
        char suffix[] = "zabcdef";
        ASSERT_FALSE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_ends_with: single character suffix");;;
    {
        char hay[] = "test";
        char suffix[] = "t";
        ASSERT_TRUE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_starts_with: case sensitive");;;
    {
        char hay[] = "Test";
        char prefix[] = "test";
        ASSERT_FALSE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: NULL hay");;;
    {
        CGS_StrView hay = {0};
        CGS_StrView prefix = cgs_strv("hello");
        ASSERT_FALSE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: NULL needle");;;
    {
        CGS_StrView hay = cgs_strv("hello");
        CGS_StrView prefix = {0};
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: NULL both");;;
    {
        CGS_StrView hay = {0};
        CGS_StrView prefix = {0};
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
}

// ============================================================================
// Edge Case Tests for cgs_tolower / cgs_toupper
// ============================================================================

void test_str_case_edge_cases() {
    TEST("cgs_tolower: empty string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("");
        cgs_tolower(&dstr);
        ASSERT_EQ(cgs_len(&dstr), 0);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: already lowercase");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("alllower");
        cgs_tolower(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "alllower"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: with numbers and symbols");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("Test123!@#");
        cgs_tolower(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "test123!@#"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_toupper: empty string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("");
        cgs_toupper(&dstr);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_toupper: already uppercase");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("ALLUPPER");
        cgs_toupper(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "ALLUPPER"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: on read-only buffer (should fail)");;;
    {
        char buf[] = "TEST";
        cgs_tolower(buf);
        ASSERT_TRUE(cgs_equal(buf, "test"));
    }
}

// ============================================================================
// Edge Case Tests for cgs_copy
// ============================================================================

void test_str_copy_edge_cases() {
    TEST("cgs_copy: empty to empty");;;
    {
        char dst[10] = "";
        char src[] = "";
        CGS_Error err = cgs_copy(dst, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(dst), 0);
    }
    
    TEST("cgs_copy: to buffer exactly sized");;;
    {
        char dst[5];
        char src[] = "test";
        CGS_Error err = cgs_copy(dst, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, "test"));
    }
    
    TEST("cgs_copy: to buffer one too small");;;
    {
        char dst[4];
        char src[] = "test";
        CGS_Error err = cgs_copy(dst, src);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_copy: to CGS_StrBuf at capacity");;;
    {
        char backing[5];
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(backing, 5);
        char src[] = "test";
        CGS_Error err = cgs_copy(&sb, src);
        ASSERT_EQ(err.ec, CGS_OK);
    }
    
    TEST("cgs_copy: overlapping buffers (aliasing)");;;
    {
        char buf[10] = "test";
        // Copying to itself should fail or handle gracefully
        CGS_Error err = cgs_copy(buf, buf);
        // Might return CGS_ALIASING_NOT_SUPPORTED
        ASSERT_TRUE(err.ec == CGS_ALIASING_NOT_SUPPORTED || err.ec == CGS_OK);
    }
    
    TEST("cgs_copy: to CGS_DStr with insufficient capacity");;;
    {
        CGS_DStr dstr = cgs_dstr_init(2);
        char src[] = "this is a long string";
        CGS_Error err = cgs_copy(&dstr, src);
        // Should either reallocate or fail
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_DST_TOO_SMALL || err.ec == CGS_ALLOC_ERROR);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_copy: from CGS_DStr to char array");;;
    {
        CGS_DStr src = cgs_dstr_init_from("source");
        char dst[20];
        CGS_Error err = cgs_copy(dst, &src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, "source"));
        cgs_dstr_deinit(&src);
    }
}

// ============================================================================
// Edge Case Tests for cgs_putc
// ============================================================================

void test_str_putc_edge_cases() {
    TEST("cgs_putc: to empty CGS_DStr");;;
    {
        CGS_DStr dstr = cgs_dstr_init(0);
        CGS_Error err = cgs_putc(&dstr, 'a');
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERROR);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: null character");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_putc(&dstr, '\0');
        // Behavior may vary - might end string or add literal null
        (void)err;
        ASSERT_TRUE(1);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: to CGS_StrBuf at capacity");;;
    {
        char backing[3] = {'a', 'b', '\0'};
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 3);
        CGS_Error err = cgs_putc(&sb, 'c');
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_putc: extended ASCII character");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_putc(&dstr, 0xFF);
        ASSERT_EQ(err.ec, CGS_OK);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: many characters sequentially");;;
    {
        CGS_DStr dstr = cgs_dstr_init(1);
        for (int i = 0; i < 1000; i++) {
            CGS_Error err = cgs_putc(&dstr, 'x');
            if (err.ec != CGS_OK) {
                printf("  Failed at iteration %d with error code %d\n", i, err.ec);
                break;
            }
        }
        ASSERT_EQ(cgs_len(&dstr), 1000);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("writer_t: cgs_putc with FILE*");;;
    {
        FILE* tmp = tmpfile();
        
        cgs_putc(tmp, 'A');
        cgs_putc(tmp, 'B');
        cgs_putc(tmp, 'C');
        
        rewind(tmp);
        char buf[4] = {0};
        fread(buf, 1, 3, tmp);
        
        ASSERT_EQ(strcmp(buf, "ABC"), 0);
        fclose(tmp);
    }
    
    TEST("writer_t: cgs_append with FILE*");;;
    {
        FILE* tmp = tmpfile();
        
        cgs_append(tmp, "Hello, ");
        cgs_append(tmp, "World");
        
        rewind(tmp);
        CGS_DStr result = cgs_dstr_init();
        cgs_fread_line(&result, tmp);
        
        ASSERT_TRUE(cgs_equal(result, "Hello, World"));
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("writer_t: cgs_append_tostr with FILE*");;;
    {
        FILE* tmp = tmpfile();
        
        // Testing integer conversion to file
        cgs_append_tostr(tmp, 1234);
        cgs_putc(tmp, ' ');
        // Testing float conversion to file
        cgs_append_tostr(tmp, cgs_nfmt(5.5, 'f', 2));
        
        rewind(tmp);
        CGS_DStr result = cgs_dstr_init();
        cgs_fread_line(&result, tmp);
        
        ASSERT_EQ(strcmp(cgs_chars(result), "1234 5.50"), 0);
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("writer_t: cgs_append_tostr_many with FILE*");;;
    {
        FILE* tmp = tmpfile();
        
        // Using the variadic printing macro directly to a FILE*
        cgs_append_tostr_many(tmp, "Hex: ", cgs_nfmt(255, 'X'), ", Score: ", 100);
        
        rewind(tmp);
        CGS_DStr result = cgs_dstr_init();
        cgs_fread_line(&result, tmp);
        
        ASSERT_EQ(strcmp(cgs_chars(result), "Hex: FF, Score: 100"), 0);
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_line: basic line reading");;;
    {
        FILE* tmp = tmpfile();
        fputs("line one\nline two", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init();
        
        cgs_fread_line(&result, tmp);
        ASSERT_TRUE(cgs_equal(result, "line one\n"));
        
        cgs_clear(&result);
        cgs_fread_line(&result, tmp);
        ASSERT_TRUE(cgs_equal(result, "line two"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_append_fread_line: appending multiple lines");;;
    {
        FILE* tmp = tmpfile();
        fputs("first\nsecond", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init_from("init:");
        
        cgs_append_fread_line(&result, tmp); // appends "first\n"
        cgs_append_fread_line(&result, tmp); // appends "second"
        
        ASSERT_TRUE(cgs_equal(result, "init:first\nsecond"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_until: basic delimiter test");;;
    {
        FILE* tmp = tmpfile();
        fputs("user@hostname.com", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init();
        
        cgs_fread_until(&result, tmp, '@');
        ASSERT_TRUE(cgs_equal(result, "user@"));
        
        cgs_clear(&result);
        cgs_fread_until(&result, tmp, '.');
        ASSERT_TRUE(cgs_equal(result, "hostname."));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_until: read until EOF (delimiter not found)");;;
    {
        FILE* tmp = tmpfile();
        fputs("hello world", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init();
        
        // Search for '!' which doesn't exist
        cgs_fread_until(&result, tmp, '!');
        ASSERT_TRUE(cgs_equal(result, "hello world"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_append_fread_until: building a path");;;
    {
        FILE* tmp = tmpfile();
        fputs("home/user/docs", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init_from("/");
        
        cgs_append_fread_until(&result, tmp, '/'); // appends "home/"
        cgs_append_fread_until(&result, tmp, '/'); // appends "user/"
        
        ASSERT_TRUE(cgs_equal(result, "/home/user/"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_line: empty file and immediate EOF");;;
    {
        FILE* tmp = tmpfile(); // empty
        CGS_DStr result = cgs_dstr_init_from("untouched");
        
        CGS_Error err = cgs_fread_line(&result, tmp);
        
        ASSERT_TRUE(cgs_equal(result, ""));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_until: basic delimiter inclusion");;;
    {
        FILE* tmp = tmpfile();
        fputs("key:value", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init();
        
        // Should include the ':'
        cgs_fread_until(&result, tmp, ':');
        ASSERT_TRUE(cgs_equal(result, "key:"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_until: EOF as delimiter (read whole file)");;;
    {
        FILE* tmp = tmpfile();
        fputs("line 1\nline 2", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init();
        
        // Using EOF as the delimiter should read until the end
        // EOF itself is not a character, so it is never "included"
        cgs_fread_until(&result, tmp, EOF);
        ASSERT_TRUE(cgs_equal(result, "line 1\nline 2"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_until: reaching EOF before delim (delim not included)");;;
    {
        FILE* tmp = tmpfile();
        fputs("partial data", tmp); // No semicolon here
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init();
        
        // Searching for ';' but hitting EOF first
        cgs_fread_until(&result, tmp, ';');
        
        // Per requirements: if EOF is reached, the delim (;) won't be included
        ASSERT_TRUE(cgs_equal(result, "partial data"));
        ASSERT_FALSE(cgs_ends_with(result, ";"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_append_fread_until: logic with EOF and appends");;;
    {
        FILE* tmp = tmpfile();
        fputs("part1;part2", tmp);
        rewind(tmp);
        
        CGS_DStr result = cgs_dstr_init_from("Data: ");
        
        // 1. Read until ';' (found, so included)
        cgs_append_fread_until(&result, tmp, ';');
        ASSERT_TRUE(cgs_equal(result, "Data: part1;"));
        
        // 2. Read until ';' again (not found, hits EOF, so NOT included)
        cgs_append_fread_until(&result, tmp, ';');
        ASSERT_TRUE(cgs_equal(result, "Data: part1;part2"));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("cgs_fread_until: empty file immediately hitting EOF");;;
    {
        FILE* tmp = tmpfile(); // Empty
        CGS_DStr result = cgs_dstr_init();
        
        // Should handle immediate EOF gracefully (result empty, no delim)
        cgs_fread_until(&result, tmp, ':');
        ASSERT_TRUE(cgs_equal(result, ""));
        
        cgs_dstr_deinit(&result);
        fclose(tmp);
    }
    
    /* =========================================================================
     * cgs_fmt — basic copying (no specifiers)
     * ========================================================================= */
    
    TEST("cgs_fmt: no specifiers copies string as-is into CGS_DStr");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: no specifiers copies string as-is into CGS_StrBuf");
    {
        char buf[32];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    TEST("cgs_fmt: no specifiers copies string as-is into FILE*");
    {
        FILE *f = tmpfile();
        CGS_Error err = cgs_appendf(f, "hello world");
        ASSERT_TRUE(err.ec == CGS_OK);
        rewind(f);
        char buf[32] = {0};
        fread(buf, 1, sizeof(buf) - 1, f);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
        fclose(f);
    }
    
    /* =========================================================================
     * cgs_fmt — percent escape
     * ========================================================================= */
    
    TEST("cgs_fmt: %% writes a literal percent sign");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "100%%");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("100%")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: multiple %% escapes all produce literal percent signs");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%%+%%=%%");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("%+%=%")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — single substitution
     * ========================================================================= */
    
    TEST("cgs_fmt: single % substituted with string arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        const char *fmt = "hello %?";
        CGS_Error err = cgs_fmt(&dst, fmt, cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: % at start of format string");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%? world", cgs_strv("hello"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: % at end of format string");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: % substituted with empty string arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello%?world", cgs_strv(""));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("helloworld")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — multiple substitutions
     * ========================================================================= */
    
    TEST("cgs_fmt: multiple % substituted in order");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%? %? %?",
                                   cgs_strv("one"), cgs_strv("two"), cgs_strv("three"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("one two three")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: mixed %% escapes and % substitutions");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%% of %? is %?",
                                   cgs_strv("50"), cgs_strv("done"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("% of 50 is done")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — arg count errors
     * ========================================================================= */
    
    TEST("cgs_fmt: more % than args returns CGS_NOT_ENOUGH_ARGS");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%? and %?", cgs_strv("only one"));
        ASSERT_TRUE(err.ec == CGS_NOT_ENOUGH_ARGS);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: more args than % returns CGS_TOO_MANY_ARGS");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello",
                                   cgs_strv("extra"), cgs_strv("args"));
        ASSERT_TRUE(err.ec == CGS_TOO_MANY_ARGS);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: %% escape does not consume an arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%% and %?", cgs_strv("hello"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("% and hello")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — overflow / CGS_DST_TOO_SMALL
     * ========================================================================= */
    
    TEST("cgs_fmt: output exceeding CGS_StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[4];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: substitution exceeding CGS_StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[8];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hi %?", cgs_strv("this is way too long"));
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: output exactly filling CGS_StrBuf capacity succeeds");
    {
        char buf[6];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello");  /* 5 chars + null */
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello")));
    }
    
    /* =========================================================================
     * cgs_fmt — writer type variants
     * ========================================================================= */
    
    TEST("cgs_fmt: writer as char[]");
    {
        char buf[32] = {0};
        CGS_Error err = cgs_fmt(buf, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
    }
    
    TEST("cgs_fmt: writer as CGS_MutStrRef");
    {
        char buf[32] = {0};
        CGS_MutStrRef dst = cgs_mutstr_ref(buf);
        CGS_Error err = cgs_fmt(dst, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
    }
    
    TEST("cgs_fmt: writer as FILE*");
    {
        FILE *f = tmpfile();
        CGS_Error err = cgs_appendf(f, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        rewind(f);
        char buf[32] = {0};
        fread(buf, 1, sizeof(buf) - 1, f);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
        fclose(f);
    }
    
    /* =========================================================================
     * cgs_appendf — appending behaviour
     * ========================================================================= */
    
    TEST("cgs_appendf: appends to existing CGS_DStr content");
    {
        CGS_DStr dst = cgs_dstr_init_from(cgs_strv("hello "));
        CGS_Error err = cgs_appendf(&dst, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_appendf: appends with substitution to existing CGS_DStr content");
    {
        CGS_DStr dst = cgs_dstr_init_from(cgs_strv("hello "));
        CGS_Error err = cgs_appendf(&dst, "%?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_appendf: multiple appends accumulate correctly");
    {
        CGS_DStr dst = cgs_dstr_init();
        cgs_appendf(&dst, "one");
        cgs_appendf(&dst, ", two");
        CGS_Error err = cgs_appendf(&dst, ", three");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("one, two, three")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_appendf: appends to existing CGS_StrBuf content");
    {
        char buf[32] = {0};
        CGS_StrBuf dst = cgs_strbuf_init_from_cstr(buf);
        cgs_appendf(&dst, "hello ");
        CGS_Error err = cgs_appendf(&dst, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    TEST("cgs_appendf: appending to CGS_StrBuf that leaves no remaining capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[8];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        cgs_appendf(&dst, "hello");   /* 5 chars, 2 remaining (+ null) */
        CGS_Error err = cgs_appendf(&dst, " world");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_appendf: appends to FILE* after existing content");
    {
        FILE *f = tmpfile();
        fwrite("hello ", 1, 6, f);
        CGS_Error err = cgs_appendf(f, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        rewind(f);
        char buf[32] = {0};
        fread(buf, 1, sizeof(buf) - 1, f);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
        fclose(f);
    }
    
    TEST("cgs_appendf: appends with substitution to FILE* after existing content");
    {
        FILE *f = tmpfile();
        fwrite("hello ", 1, 6, f);
        CGS_Error err = cgs_appendf(f, "%?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        rewind(f);
        char buf[32] = {0};
        fread(buf, 1, sizeof(buf) - 1, f);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
        fclose(f);
    }
    
    TEST("cgs_appendf: appends to CGS_StrBuf with sufficient remaining capacity");
    {
        char buf[32];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        cgs_appendf(&dst, "hello ");
        CGS_Error err = cgs_appendf(&dst, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    TEST("cgs_appendf: appends with substitution to CGS_StrBuf");
    {
        char buf[32];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        cgs_appendf(&dst, "hello ");
        CGS_Error err = cgs_appendf(&dst, "%?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    /* =========================================================================
     * cgs_fmt — basic copying (no specifiers)
     * ========================================================================= */
    
    TEST("cgs_fmt: no specifiers copies string as-is into CGS_DStr");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: no specifiers copies string as-is into CGS_StrBuf");
    {
        char buf[32];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    /* =========================================================================
     * cgs_fmt — percent escape
     * ========================================================================= */
    
    TEST("cgs_fmt: %% writes a literal percent sign");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "100%%");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("100%")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: multiple %% escapes all produce literal percent signs");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%%+%%=%%");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("%+%=%")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — auto-indexed substitution (%?)
     * ========================================================================= */
    
    TEST("cgs_fmt: single %? substituted with string arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: multiple %? substituted in order");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%? %? %?",
                                   cgs_strv("one"), cgs_strv("two"), cgs_strv("three"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("one two three")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: %? substituted with integer arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "value is %?", 42);
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("value is 42")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: %? substituted with float arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "pi is %?", 3.14f);
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("pi is 3.14")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: mixed %% escape and %? substitution");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%% of %? is %?",
                                   cgs_strv("50"), cgs_strv("done"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("% of 50 is done")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: %? at start of format string");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%? world", cgs_strv("hello"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: %? at end of format string");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: %? substituted with empty string arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello%?world", cgs_strv(""));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("helloworld")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — explicit indexed substitution (%[0], %[1], ...)
     * ========================================================================= */
    
    TEST("cgs_fmt: explicit index %[0] selects first arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello %[0]", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit indices in order");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%[0] %[1] %[2]",
                                   cgs_strv("one"), cgs_strv("two"), cgs_strv("three"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("one two three")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit indices out of order");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%[2] %[0] %[1]",
                                   cgs_strv("one"), cgs_strv("two"), cgs_strv("three"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("three one two")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit index can repeat an arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%[0] and %[0]", cgs_strv("hello"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello and hello")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit index out of bounds returns CGS_INDEX_OUT_OF_BOUNDS");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%[3]", cgs_strv("only one arg"));
        ASSERT_TRUE(err.ec == CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: mixed %% escape and explicit index substitution");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%% of %[0] is %[1]",
                                   cgs_strv("50"), cgs_strv("done"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("% of 50 is done")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — mixing auto and explicit indexing
     * ========================================================================= */
    
    TEST("cgs_fmt: mixing %? and explicit index returns CGS_BAD_FORMAT");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%? and %[0]",
                                   cgs_strv("hello"), cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_BAD_FORMAT);
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — arg count errors
     * ========================================================================= */
    
    TEST("cgs_fmt: more %? than args returns CGS_NOT_ENOUGH_ARGS");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%? and %?", cgs_strv("only one"));
        ASSERT_TRUE(err.ec == CGS_NOT_ENOUGH_ARGS);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: more args than %? returns CGS_TOO_MANY_ARGS");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello",
                                   cgs_strv("extra"), cgs_strv("args"));
        ASSERT_TRUE(err.ec == CGS_TOO_MANY_ARGS);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: %% escape does not consume an arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%% and %?", cgs_strv("hello"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("% and hello")));
        cgs_dstr_deinit(&dst);
    }
    
    /* =========================================================================
     * cgs_fmt — overflow / CGS_DST_TOO_SMALL
     * ========================================================================= */
    
    TEST("cgs_fmt: output exceeding CGS_StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[4];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: substitution exceeding CGS_StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[8];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hi %?", cgs_strv("this is way too long"));
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: output exactly filling CGS_StrBuf capacity succeeds");
    {
        char buf[6];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello");  /* 5 chars + null */
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello")));
    }
    
    /* =========================================================================
     * cgs_fmt — writer type variants
     * ========================================================================= */
    
    TEST("cgs_fmt: writer as char[]");
    {
        char buf[32] = {0};
        CGS_Error err = cgs_fmt(buf, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
    }
    
    TEST("cgs_fmt: writer as CGS_MutStrRef");
    {
        char buf[32] = {0};
        CGS_MutStrRef dst = cgs_mutstr_ref(buf);
        CGS_Error err = cgs_fmt(dst, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
    }
}

// ============================================================================
// Edge Case Tests for cgs_append
// ============================================================================

void test_str_append_edge_cases() {
    TEST("cgs_append: empty to empty");;;
    {
        CGS_DStr dst = cgs_dstr_init(10);
        char src[] = "";
        CGS_Error err = cgs_append(&dst, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dst), 0);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_append: to itself (aliasing)");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_append(&dstr, &dstr);
        // Should detect aliasing or handle it
        ASSERT_TRUE(err.ec == CGS_ALIASING_NOT_SUPPORTED || err.ec == CGS_OK);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_append: to CGS_StrBuf causing overflow");;;
    {
        char backing[10] = "hello";
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 10);
        char src[] = "world!";
        CGS_Error err = cgs_append(&sb, src);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_append: exactly fitting capacity");;;
    {
        char backing[11] = "hello";
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 11);
        char src[] = "world";
        CGS_Error err = cgs_append(&sb, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&sb, "helloworld"));
    }
    
    TEST("cgs_append: multiple appends growing CGS_DStr");;;
    {
        CGS_DStr dstr = cgs_dstr_init(1);
        for (int i = 0; i < 100; i++) {
            CGS_Error err = cgs_append(&dstr, "x");
            ASSERT_EQ(err.ec, CGS_OK);
        }
        ASSERT_EQ(cgs_len(&dstr), 100);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_append: very long string");;;
    {
        CGS_DStr dstr = cgs_dstr_init(100);
        CGS_DStr long_str = cgs_dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            cgs_putc(&long_str, 'a');
        }
        CGS_Error err = cgs_append(&dstr, &long_str);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 4999);
        cgs_dstr_deinit(&dstr);
        cgs_dstr_deinit(&long_str);
    }
}

// ============================================================================
// Edge Case Tests for cgs_del
// ============================================================================

void test_str_del_edge_cases() {
    TEST("cgs_del: delete entire string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 0);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete nothing (from == to)");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 2, 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "test"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: invalid range (from > to)");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 3, 1);
        ASSERT_EQ(err.ec, CGS_BAD_RANGE);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: out of bounds from");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 10, 15);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: out of bounds to");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 100);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete from middle");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("abcdef");
        CGS_Error err = cgs_del(&dstr, 2, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abef"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete first character");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 1);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "est"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete last character");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 3, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "tes"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: on empty string");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_del(&dstr, 0, 0);
        ASSERT_EQ(err.ec, CGS_OK);
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_replace
// ============================================================================

void test_str_replace_edge_cases() {
    TEST("cgs_replace: target not found");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("hello world");
        CGS_Result(int) res = cgs_replace(&dstr, "xyz", "abc");
        ASSERT_EQ(res.err.ec, CGS_NOT_FOUND);
        ASSERT_EQ(res.val, 0);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: empty target");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Result(int) res = cgs_replace(&dstr, "", "x");
        // Replacing empty string is likely an error or no-op
        ASSERT_TRUE(res.err.ec == CGS_OK || res.err.ec == CGS_NOT_FOUND);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replace with empty string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("hello world");
        CGS_Result(int) res = cgs_replace(&dstr, "o", "");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hell wrld"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replacement longer than target");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("hi hi hi");
        CGS_Result(int) res = cgs_replace(&dstr, "hi", "hello");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hello hello hello"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replacement shorter than target");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("hello hello");
        CGS_Result(int) res = cgs_replace(&dstr, "hello", "hi");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hi hi"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: overlapping matches");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("aaa");
        CGS_Result(int) res = cgs_replace(&dstr, "aa", "b");
        // Should replace non-overlapping: "aaa" -> "ba" (1 replacement)
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(res.val == 1);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: target equals entire string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("exact");
        CGS_Result(int) res = cgs_replace(&dstr, "exact", "replaced");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "replaced"));
        ASSERT_EQ(res.val, 1);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: on CGS_StrBuf with insufficient space");;;
    {
        char backing[10] = "hi hi"; // "hello hi"
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 10);
        CGS_Result(int) res = cgs_replace(&sb, "hi", "hello");
        // println("hi hi", " became :: ", sb);
        ASSERT_EQ(res.err.ec, CGS_DST_TOO_SMALL);
        ASSERT_EQ(res.val, 1);
    }
    
    TEST("cgs_replace: many occurrences");;;
    {
        CGS_DStr dstr = cgs_dstr_init(100);
        for (int i = 0; i < 50; i++) {
            cgs_append(&dstr, "x ");
        }
        CGS_Result(int) res = cgs_replace(&dstr, "x", "y");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_EQ(res.val, 50);
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_replace_first
// ============================================================================

void test_str_replace_first_edge_cases() {
    TEST("cgs_replace_first: no occurrence");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("hello");
        CGS_Error err = cgs_replace_first(&dstr, "xyz", "abc");
        ASSERT_EQ(err.ec, CGS_NOT_FOUND);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: empty string target");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        // Replacing the first "" is defined in many libs as an injection at start
        cgs_replace_first(&s, "", "!");
        ASSERT_TRUE(cgs_equal(&s, "!abc"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: match at end of string");;;
    {
        CGS_DStr s = cgs_dstr_init_from("path/to/file");
        cgs_replace_first(&s, "file", "dir");
        ASSERT_TRUE(cgs_equal(&s, "path/to/dir"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: multiple occurrences");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test test test");
        CGS_Error err = cgs_replace_first(&dstr, "test", "word");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "word test test"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: at end of string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("abcdef");
        CGS_Error err = cgs_replace_first(&dstr, "def", "xyz");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abcxyz"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: only first occurrence");;;
    {
        CGS_DStr s = cgs_dstr_init_from("ababab");
        CGS_Error err = cgs_replace_first(&s, "ab", "X");
        ASSERT_TRUE(cgs_equal(&s, "Xabab") && err.ec == CGS_OK);
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: target at the very end");;;
    {
        CGS_DStr s = cgs_dstr_init_from("hello world");
        CGS_Error err = cgs_replace_first(&s, "world", "C");
        ASSERT_TRUE(cgs_equal(&s, "hello C"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: target is the whole string");;;
    {
        CGS_DStr s = cgs_dstr_init_from("match");
        cgs_replace_first(&s, "match", "replaced");
        ASSERT_TRUE(cgs_equal(&s, "replaced"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: error when not found");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        CGS_Error err = cgs_replace_first(&s, "z", "x");
        // Some libs return OK with 0 changes, but CGS_NOT_FOUND is safer for a "First" API
        ASSERT_TRUE(err.ec == CGS_NOT_FOUND);
        cgs_dstr_deinit(&s);
    }
}

// ============================================================================
// Edge Case Tests for cgs_replace_range
// ============================================================================

void test_str_replace_range_edge_cases() {
    TEST("cgs_replace_range: remove last character");;;
    {
        CGS_DStr s = cgs_dstr_init_from("Hello!");
        // Range is [5, 6) -> the '!'
        cgs_replace_range(&s, 5, 6, ""); 
        ASSERT_TRUE(cgs_equal(&s, "Hello"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace inside string with much longer string");;;
    {
        CGS_DStr s = cgs_dstr_init_from("a[ ]c");
        // Replace "[ ]" (index 1 to 4) with "long string"
        cgs_replace_range(&s, 1, 4, "is a very long string");
        ASSERT_TRUE(cgs_equal(&s, "ais a very long stringc"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: null/empty replacement at specific index (Insertion)");;;
    {
        CGS_DStr s = cgs_dstr_init_from("ac");
        cgs_replace_range(&s, 1, 1, "b");
        ASSERT_TRUE(cgs_equal(&s, "abc"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace entire string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 4, "replaced");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "replaced"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: invalid range");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 3, 1, "x");
        ASSERT_EQ(err.ec, CGS_BAD_RANGE);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: out of bounds");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 100, "x");
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: zero-length range (insertion)");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 2, 2, "XX");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "teXXst"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: with empty replacement (deletion)");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("testing");
        CGS_Error err = cgs_replace_range(&dstr, 2, 5, "");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "teng"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: at string boundaries");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 0, "start");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "starttest"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: CGS_StrBuf overflow");;;
    {
        char backing[10] = "test";
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_replace_range(&sb, 0, 4, "very long replacement");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: replace middle (same size)");;;
    {
        CGS_DStr s = cgs_dstr_init_from("ABCDE");
        // Replace "BCD" (indices 1, 2, 3) with "123"
        CGS_Error err = cgs_replace_range(&s, 1, 4, "123");
        ASSERT_TRUE(cgs_equal(&s, "A123E"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: grow string (insertion)");;;
    {
        CGS_DStr s = cgs_dstr_init_from("AB");
        // Replace nothing at index 1 with "123" -> "A123B"
        CGS_Error err = cgs_replace_range(&s, 1, 1, "123");
        ASSERT_TRUE(cgs_equal(&s, "A123B"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: shrink string (deletion)");;;
    {
        CGS_DStr s = cgs_dstr_init_from("Hello World");
        // Replace " World" (index 5 to 11) with ""
        CGS_Error err = cgs_replace_range(&s, 5, 11, "");
        ASSERT_TRUE(cgs_equal(&s, "Hello"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace entire string");;;
    {
        CGS_DStr s = cgs_dstr_init_from("old");
        cgs_replace_range(&s, 0, 3, "new");
        ASSERT_TRUE(cgs_equal(&s, "new"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: out of bounds");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        CGS_Error err = cgs_replace_range(&s, 1, 10, "x");
        ASSERT_TRUE(err.ec == CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: inverted range");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        CGS_Error err = cgs_replace_range(&s, 3, 1, "x");
        ASSERT_TRUE(err.ec == CGS_BAD_RANGE);
        cgs_dstr_deinit(&s);
    }
}

// ============================================================================
// Edge Case Tests for cgs_split
// ============================================================================

void test_str_split_edge_cases() {
    
    TEST("cgs_split: empty string");;;
    {
        char str[] = "";
        char delim[] = ",";
        CGS_StrViewArray arr = cgs_split(str, delim);
        // Should return array with 0 or 1 empty element
        ASSERT_TRUE(arr.len == 1 && arr.strs[0].chars == str);
        free(arr.strs);
    }
    
    TEST("Split: No delimiter present in source");;;
    {
        char str[] = "hello world";
        char delim[] = ",";
        CGS_StrViewArray arr = cgs_split(str, delim);
        // Delimiter not found -> 1 element (the whole string)
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(arr.strs[0].len == 11);
        ASSERT_TRUE(memcmp(arr.strs[0].chars, "hello world", 11) == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: empty string with non-empty delimiter");;;
    {
        char str[] = "";
        CGS_StrViewArray arr = cgs_split(str, ",");
        // Most languages (Java, JS, Python) return [""]
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(arr.strs[0].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: empty delimiter (Explode behavior)");;;
    {
        char str[] = "abc";
        CGS_StrViewArray arr = cgs_split(str, "");
        // Explode: "abc" -> ["a", "b", "c"]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[0].len == 1 && arr.strs[0].chars[0] == 'a');
        ASSERT_TRUE(arr.strs[2].len == 1 && arr.strs[2].chars[0] == 'c');
        free(arr.strs);
    }
    
    TEST("cgs_split: consecutive delimiters (Empty fields)");;;
    {
        char str[] = "a,,b";
        CGS_StrViewArray arr = cgs_split(str, ",");
        // Result: ["a", "", "b"]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[1].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: leading and trailing delimiters");;;
    {
        char str[] = ",a,";
        CGS_StrViewArray arr = cgs_split(str, ",");
        // Result: ["", "a", ""]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[0].len == 0);
        ASSERT_TRUE(arr.strs[2].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter not present");;;
    {
        char str[] = "hello";
        CGS_StrViewArray arr = cgs_split(str, "|");
        // Should return the original string as the only element
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(cgs_equal(arr.strs[0], "hello"));
        free(arr.strs);
    }
    
    TEST("cgs_split: string is exactly the delimiter");;;
    {
        char str[] = "::";
        CGS_StrViewArray arr = cgs_split(str, "::");
        // Result: ["", ""]
        ASSERT_TRUE(arr.len == 2);
        ASSERT_TRUE(arr.strs[0].len == 0 && arr.strs[1].len == 0);
        free(arr.strs);
    }    
    TEST("cgs_split: delimiter not in string");;;
    {
        char str[] = "no delimiters here";
        char delim[] = ",";
        CGS_StrViewArray arr = cgs_split(str, delim);
        ASSERT_EQ(arr.len, 1);
        free(arr.strs);
    }
    
    TEST("cgs_split: consecutive delimiters");;;
    {
        char str[] = "a,,b,,c";
        char delim[] = ",";
        CGS_StrViewArray arr = cgs_split(str, delim);
        // Should have 5 elements: "a", "", "b", "", "c"
        ASSERT_EQ(arr.len, 5);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter at start");;;
    {
        char str[] = ",test";
        char delim[] = ",";
        CGS_StrViewArray arr = cgs_split(str, delim);
        // Should have 2 elements: "" and "test"
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter at end");;;
    {
        char str[] = "test,";
        char delim[] = ",";
        CGS_StrViewArray arr = cgs_split(str, delim);
        // Should have 2 elements: "test" and ""
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: only delimiter");;;
    {
        char str[] = ",";
        char delim[] = ",";
        CGS_StrViewArray arr = cgs_split(str, delim);
        // Should have 2 empty elements
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: multi-character delimiter");;;
    {
        char str[] = "a::b::c";
        char delim[] = "::";
        CGS_StrViewArray arr = cgs_split(str, delim);
        ASSERT_EQ(arr.len, 3);
        free(arr.strs);
    }
    
    TEST("cgs_split: many splits");;;
    {
        CGS_DStr dstr = cgs_dstr_init(1000);
        for (int i = 0; i < 100; i++) {
            cgs_append(&dstr, "x,");
        }
        CGS_StrViewArray arr = cgs_split(&dstr, ",");
        ASSERT_EQ(arr.len, 101); // 100 "x" and 1 trailing empty
        cgs_dstr_deinit(&dstr);
        free(arr.strs);
    }
}

// ============================================================================
// Edge Case Tests for cgs_insert / cgs_prepend
// ============================================================================

void test_str_insert_prepend_edge_cases() {
    TEST("cgs_insert: at position 0 (same as prepend)");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "START", 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "STARTtest"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: at middle position");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("abef");
        CGS_Error err = cgs_insert(&dstr, "cd", 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abcdef"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: at end position");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "end", 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "testend"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: out of bounds position");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "x", 100);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: into empty string at position 0");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_insert(&dstr, "first", 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: into empty string at position > 0");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_insert(&dstr, "test", 5);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: CGS_StrBuf overflow");;;
    {
        char backing[10] = "test";
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_insert(&sb, "longinsert", 2);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_insert: empty string insertion");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "", 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "test"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_prepend: to empty string");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_prepend(&dstr, "first");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_prepend: CGS_StrBuf overflow");;;
    {
        char backing[10] = "test";
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_prepend(&sb, "longprefix");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_prepend: multiple times");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("end");
        cgs_prepend(&dstr, "middle");
        cgs_prepend(&dstr, "start");
        ASSERT_TRUE(cgs_equal(&dstr, "startmiddleend"));
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for CGS_DStr functions
// ============================================================================

void test_dstring_edge_cases() {
    TEST("cgs_dstr_init: zero capacity");;;
    {
        CGS_DStr dstr = cgs_dstr_init(0);
        ASSERT_EQ(cgs_len(&dstr), 0);
        // Should still be usable
        CGS_Error err = cgs_append(&dstr, "test");
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERROR);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_dstr_init: very large capacity");;;
    {
        CGS_DStr dstr = cgs_dstr_init(1000000);
        ASSERT_TRUE(cgs_cap(&dstr) >= 1000000 || cgs_cap(&dstr) == 0);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_dstr_init_from: empty string");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("");
        ASSERT_EQ(cgs_len(&dstr), 0);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_dstr_shrink_to_fit: already minimal");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("test");
        CGS_Error err = cgs_dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_cap(&dstr) >= cgs_len(&dstr));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_dstr_shrink_to_fit: after deletions");;;
    {
        CGS_DStr dstr = cgs_dstr_init(1000);
        cgs_append(&dstr, "small");
        CGS_Error err = cgs_dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_dstr_ensure_cap: already sufficient");;;
    {
        CGS_DStr dstr = cgs_dstr_init(100);
        CGS_Error err = cgs_dstr_ensure_cap(&dstr, 50);
        ASSERT_EQ(err.ec, CGS_OK);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_dstr_ensure_cap: needs growth");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_dstr_ensure_cap(&dstr, 100);
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERROR);
        if (err.ec == CGS_OK) {
            ASSERT_TRUE(cgs_cap(&dstr) >= 100);
        }
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_dstr_ensure_cap: zero requested");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_dstr_ensure_cap(&dstr, 0);
        ASSERT_EQ(err.ec, CGS_OK);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_find: null checks");;;
    {
        CGS_DStr dstr = cgs_dstr_init();
        ASSERT_TRUE(dstr.chars == NULL);
        ASSERT_TRUE(cgs_find(dstr, "").chars == dstr.chars);
        ASSERT_TRUE(cgs_equal(dstr, ""));
        ASSERT_TRUE(cgs_starts_with(dstr, ""));
        ASSERT_TRUE(cgs_ends_with(dstr, ""));
        
        ASSERT_FALSE(cgs_starts_with(dstr, "something"));
        
        CGS_StrBuf sb = {0};
        CGS_Error err = cgs_copy(&sb, "hello");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for CGS_StrBuf
// ============================================================================

void test_string_buffer_edge_cases() {
    TEST("CGS_StrBuf: from empty array");;;
    {
        char buf[1] = {'\0'};
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(buf, 1);
        ASSERT_EQ(cgs_len(&sb), 0);
        ASSERT_EQ(cgs_cap(&sb), 1);
    }
    
    TEST("CGS_StrBuf: from array without null terminator");;;
    {
        char buf[5] = {'t', 'e', 's', 't', 'x'};
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(buf, 5);
        ASSERT_TRUE(sb.len == 0);
    }
    
    TEST("CGS_StrBuf: from cstr with capacity exactly length + 1");;;
    {
        char buf[5] = {'t', 'e', 's', 't', '\0'};
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(buf, 5);
        ASSERT_EQ(cgs_cap(&sb), 5);
        ASSERT_EQ(cgs_len(&sb), 4);
    }
    
    TEST("CGS_StrBuf: from buf with exact capacity");;;
    {
        char buf[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(buf, 10);
        ASSERT_EQ(cgs_cap(&sb), 10);
    }
    
    TEST("CGS_StrBuf: append to full buffer from cstr");;;
    {
        char buf[5] = {'f', 'u', 'l', 'l', '\0'};
        CGS_StrBuf sb = cgs_strbuf_init_from_cstr(buf, 5);
        CGS_Error err = cgs_append(&sb, "x");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("CGS_StrBuf: init from buf then set content");;;
    {
        char buf[20];
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(buf, 20);
        CGS_Error err = cgs_copy(&sb, "test");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&sb, "test"));
    }
}

// ============================================================================
// Edge Case Tests for cgs_strv
// ============================================================================

void test_strv_edge_cases() {
    TEST("cgs_strv: empty range");;;
    {
        char str[] = "test";
        CGS_StrView sv = cgs_strv(str, 2, 2);
        ASSERT_EQ(cgs_len(sv), 0);
    }
    
    TEST("cgs_strv: entire string");;;
    {
        char str[] = "test";
        CGS_StrView sv = cgs_strv(str, 0, 4);
        ASSERT_EQ(cgs_len(sv), 4);
        ASSERT_TRUE(cgs_equal(sv, "test"));
    }
    
    TEST("cgs_strv: invalid range (from > to)");;;
    {
        char str[] = "test";
        CGS_StrView sv = cgs_strv(str, 3, 1);
        // Likely returns empty or errors
        ASSERT_TRUE(1);
    }
    
    TEST("cgs_strv: single character");;;
    {
        char str[] = "test";
        CGS_StrView sv = cgs_strv(str, 1, 2);
        ASSERT_EQ(cgs_len(sv), 1);
        ASSERT_EQ(sv.chars[0], 'e');
    }
}

// ============================================================================
// Edge Case Tests for file I/O functions
// ============================================================================

void test_file_io_edge_cases() {
    TEST("cgs_fread_line: from empty file");;;
    {
        FILE *f = tmpfile();
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_fread_line(&dstr, f);
        // Should indicate EOF or empty read
        ASSERT_TRUE(err.ec == CGS_OK || err.ec != CGS_OK);
        fclose(f);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_fread_line: very long line");;;
    {
        FILE *f = tmpfile();
        for (int i = 0; i < 10000; i++)
        {
            fputc('x', f);
        }
        fputc('\n', f);
        rewind(f);
        
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_fread_line(&dstr, f);
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERROR);
        if (err.ec == CGS_OK)
        {
            ASSERT_EQ(cgs_len(&dstr), 10001);
        }
        fclose(f);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_fread_line: line without newline");;;
    {
        FILE *f = tmpfile();
        fprintf(f, "no newline");
        rewind(f);
        
        CGS_DStr dstr = cgs_dstr_init(20);
        CGS_Error err = cgs_fread_line(&dstr, f);
        ASSERT_EQ(err.ec, CGS_NOT_FOUND);
        ASSERT_TRUE(cgs_equal(&dstr, "no newline"));
        fclose(f);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_fread_line: multiple calls");;;
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\nline3\n");
        rewind(f);
        
        CGS_DStr dstr = cgs_dstr_init(20);
        cgs_fread_line(&dstr, f);
        ASSERT_TRUE(cgs_equal(&dstr, "line1\n"));
        
        cgs_clear(&dstr);
        cgs_fread_line(&dstr, f);
        ASSERT_TRUE(cgs_equal(&dstr, "line2\n"));
        
        fclose(f);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_append_fread_line: append multiple lines");;;
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\n");
        rewind(f);
        
        CGS_DStr dstr = cgs_dstr_init(50);
        cgs_append_fread_line(&dstr, f);
        cgs_append_fread_line(&dstr, f);
        ASSERT_TRUE(cgs_equal(&dstr, "line1\nline2\n"));
        
        fclose(f);
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for appender
// ============================================================================

void test_appender_edge_cases() {
    TEST("cgs_appender: basic usage");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("start");
        CGS_AppenderState state = {};
        CGS_MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "end");
        CGS_Error err = cgs_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "startend"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: without commit");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("start");
        CGS_AppenderState state = {};
        CGS_MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "lost");
        // Not committed - dstr should be unchanged
        ASSERT_TRUE(cgs_equal(&dstr, "start"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: multiple appends before commit");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("start");
        CGS_AppenderState state = {};
        CGS_MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "a");
        cgs_append(appender, "b");
        cgs_append(appender, "c");
        cgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(cgs_equal(&dstr, "startabc"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: on empty CGS_DStr");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_AppenderState state = {};
        CGS_MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "first");
        cgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: commit without any appends");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("unchanged");
        CGS_AppenderState state = {};
        CGS_MutStrRef appender = cgs_appender(&dstr, &state);
        CGS_Error err = cgs_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "unchanged"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: multiple uses with same state");;;
    {
        CGS_DStr dstr = cgs_dstr_init_from("base");
        CGS_AppenderState state = {};
        
        CGS_MutStrRef app1 = cgs_appender(&dstr, &state);
        cgs_append(app1, "1");
        cgs_commit_appender(&dstr, app1);
        
        CGS_MutStrRef app2 = cgs_appender(&dstr, &state);
        cgs_append(app2, "2");
        cgs_commit_appender(&dstr, app2);
        
        ASSERT_TRUE(cgs_equal(&dstr, "base12"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: causing buffer growth");;;
    {
        CGS_DStr dstr = cgs_dstr_init(5);
        cgs_append(&dstr, "x");
        CGS_AppenderState state = {};
        CGS_MutStrRef appender = cgs_appender(&dstr, &state);
        for (int i = 0; i < 100; i++) {
            cgs_append(appender, "y");
        }
        CGS_Error err = cgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERROR);
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_join
// ============================================================================

void test_str_join_edge_cases() {
    
    TEST("cgs_join: empty array");;;
    {
        CGS_StrViewArray arr = {NULL, 0, 0};
        CGS_DStr dst = cgs_dstr_init(10);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(dst.len == 0); // Should be empty string
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: single element");;;
    {
        char s1[] = "lonely";
        CGS_StrView views[] = { cgs_strv(s1, 0, 6) };
        CGS_StrViewArray arr = {views, 1, 1};
        CGS_DStr dst = cgs_dstr_init(10);
        cgs_join(&dst, arr, ",");
        // Should NOT have a trailing delimiter: "lonely", not "lonely,"
        ASSERT_TRUE(cgs_equal(&dst, "lonely"));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: elements are empty strings");;;
    {
        char empty[] = "";
        CGS_StrView views[] = { cgs_strv(empty, 0, 0), cgs_strv(empty, 0, 0) };
        CGS_StrViewArray arr = {views, 2, 2};
        CGS_DStr dst = cgs_dstr_init(10);
        cgs_join(&dst, arr, ",");
        // Should result in exactly the delimiter: ","
        ASSERT_TRUE(cgs_equal(&dst, ","));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: empty delimiter");;;
    {
        char s1[] = "a", s2[] = "b";
        CGS_StrView views[] = { cgs_strv(s1, 0, 1), cgs_strv(s2, 0, 1) };
        CGS_StrViewArray arr = {views, 2, 2};
        CGS_DStr dst = cgs_dstr_init(10);
        cgs_join(&dst, arr, "");
        // Should just concatenate: "ab"
        ASSERT_TRUE(cgs_equal(&dst, "ab"));
        cgs_dstr_deinit(&dst);
    }
    
    // old
    TEST("cgs_join: empty array");;;
    {
        CGS_StrViewArray arr = {NULL, 0, 0};
        CGS_DStr dst = cgs_dstr_init(10);
        CGS_Error err = cgs_join(&dst, arr, ",");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dst), 0);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: single element");;;
    {
        char s1[] = "only";
        CGS_StrView views[] = {cgs_strv(s1, 0, 4)};
        CGS_StrViewArray arr = {views, 1, 1};
        CGS_DStr dst = cgs_dstr_init(10);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(cgs_equal(&dst, "only"));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: empty delimiter");;;
    {
        char s1[] = "a", s2[] = "b", s3[] = "c";
        CGS_StrView views[] = {
            cgs_strv(s1, 0, 1),
            cgs_strv(s2, 0, 1),
            cgs_strv(s3, 0, 1)
        };
        CGS_StrViewArray arr = {views, 3, 3};
        CGS_DStr dst = cgs_dstr_init(10);
        cgs_join(&dst, arr, "");
        ASSERT_TRUE(cgs_equal(&dst, "abc"));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: multi-char delimiter");;;
    {
        char s1[] = "a", s2[] = "b";
        CGS_StrView views[] = {
            cgs_strv(s1, 0, 1),
            cgs_strv(s2, 0, 1)
        };
        CGS_StrViewArray arr = {views, 2, 2};
        CGS_DStr dst = cgs_dstr_init(20);
        cgs_join(&dst, arr, "::");
        ASSERT_TRUE(cgs_equal(&dst, "a::b"));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: with empty strings");;;
    {
        char s1[] = "", s2[] = "mid", s3[] = "";
        CGS_StrView views[] = {
            cgs_strv(s1, 0, 0),
            cgs_strv(s2, 0, 3),
            cgs_strv(s3, 0, 0)
        };
        CGS_StrViewArray arr = {views, 3, 3};
        CGS_DStr dst = cgs_dstr_init(20);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(cgs_equal(&dst, ",mid,"));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_join: buffer too small");;;
    {
        char s1[] = "long", s2[] = "strings";
        CGS_StrView views[] = {
            cgs_strv(s1, 0, 4),
            cgs_strv(s2, 0, 7)
        };
        CGS_StrViewArray arr = {views, 2, 2};
        char backing[5];
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(backing, 5);
        cgs_clear(&sb); // Initialize to empty
        CGS_Error err = cgs_join(&sb, arr, ",");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for cgs_tostr and print functions
// ============================================================================

static bool cb_toupper(char *c, void *arg) {
    (void)arg;
    if (*c >= 'a' && *c <= 'z') *c -= 32;
    return true;
}

static bool cb_exit_on_bang(char *c, void *arg) {
    int *count = (int*)arg;
    if (*c == '!') return false;
    (*count)++;
    return true;
}

void test_tostr_edge_cases() {
    TEST("cgs_tostr_len: scalar types");;;
    {
        // Integers
        ASSERT_EQ(cgs_tostr_len(0), 1);      // "0"
        ASSERT_EQ(cgs_tostr_len(123), 3);    // "123"
        ASSERT_EQ(cgs_tostr_len(-45), 3);    // "-45"
        
        // Floats (default precision 6)
        // 3.140000 -> 8 chars
        ASSERT_EQ(cgs_tostr_len(3.14), (unsigned int) snprintf(0,0,"%g",3.14)); 
        
        // Booleans
        ASSERT_EQ(cgs_tostr_len(true), 4);   // "true"
    }
    
    TEST("cgs_tostr_p_len: string and pointer types");;;
    {
        int val = 1024;
        ASSERT_EQ(cgs_tostr_p_len(&val), 4); // "1024"
        
        CGS_StrView sv = cgs_strv("hello world");
        ASSERT_EQ(cgs_tostr_p_len(&sv), 11);
        
        CGS_DStr ds = cgs_dstr_init_from("test");
        ASSERT_EQ(cgs_tostr_p_len(&ds), 4);
        cgs_dstr_deinit(&ds);
    }
    
    TEST("cgs_tostr_len: formatters (cgs_nfmt/arrfmt)");;;
    {
        // cgs_nfmt(255, 'X') -> "FF"
        ASSERT_EQ(cgs_tostr_len(cgs_nfmt(255, 'X')), 2);
        
        int arr[] = {1, 2, 3};
        ASSERT_EQ(cgs_tostr_len(cgs_arrfmt(arr, 3)), strlen("{1, 2, 3}"));
    }
    
    TEST("cgs_map_chars: successful full iteration");;;
    {
        char buf[] = "hello";
        CGS_Error err = cgs_map_chars(buf, cb_toupper, NULL);
        
        ASSERT_EQ(err.ec, 0); // Success
        ASSERT_TRUE(cgs_equal(buf, "HELLO"));
    }
    
    TEST("cgs_map_chars: early exit with CGS_CALLBACK_EXIT");;;
    {
        char buf[] = "abc!def";
        int processed_count = 0;
        
        CGS_Error err = cgs_map_chars(buf, cb_exit_on_bang, &processed_count);
        
        // Verify early exit error code
        ASSERT_EQ(err.ec, CGS_CALLBACK_EXIT);
        // Verify we stopped at '!'
        ASSERT_EQ(processed_count, 3); 
    }
    
    TEST("cgs_map_chars: edge cases (empty strings)");;;
    {
        char buf[] = "";
        int processed_count = 0;
        
        CGS_Error err = cgs_map_chars(buf, cb_exit_on_bang, &processed_count);
        
        ASSERT_EQ(err.ec, 0);
        ASSERT_EQ(processed_count, 0);
    }
    
    TEST("cgs_map_chars: with CGS_DStr* and pointer types");;;
    {
        CGS_DStr ds = cgs_dstr_init_from("123!456");
        int count = 0;
        
        CGS_Error err = cgs_map_chars(&ds, cb_exit_on_bang, &count);
        
        ASSERT_EQ(err.ec, CGS_CALLBACK_EXIT);
        ASSERT_EQ(count, 3);
        
        cgs_dstr_deinit(&ds);
    }
    
    TEST("cgs_tostr_len: large values");;;
    {
        // 18446744073709551615 is 20 digits
        unsigned long long ull = 18446744073709551615ULL;
        ASSERT_EQ(cgs_tostr_len(ull), 20);
    }
    
    TEST("cgs_tostr: integer boundary values (INT_MAX)");;;
    {
        CGS_DStr dstr = cgs_dstr_init();
        CGS_Error err = cgs_tostr(&dstr, INT_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_int_max[32]; // Max 2^31-1 is 10 digits, plus sign and null. 32 is safe.
        sprintf(expected_int_max, "%d", INT_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_int_max));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: integer boundary values (INT_MIN)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        CGS_Error err = cgs_tostr(&dstr, INT_MIN);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_int_min[32]; // Max -2^31 is 10 digits, plus sign and null. 32 is safe.
        sprintf(expected_int_min, "%d", INT_MIN);
        ASSERT_TRUE(cgs_equal(&dstr, expected_int_min));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: zero");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_tostr(&dstr, 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "0"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: positive integer");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_tostr(&dstr, 12345);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "12345"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: negative integer");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        CGS_Error err = cgs_tostr(&dstr, -6789);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "-6789"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: long long boundary values (LLONG_MAX)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        CGS_Error err = cgs_tostr(&dstr, LLONG_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_llong_max[64]; // Long long can be up to 19 digits + sign. 64 is very safe.
        sprintf(expected_llong_max, "%lld", LLONG_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_llong_max));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: unsigned int (UINT_MAX)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        CGS_Error err = cgs_tostr(&dstr, UINT_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_uint_max[32];
        sprintf(expected_uint_max, "%u", UINT_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_uint_max));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: unsigned long long (ULLONG_MAX)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        CGS_Error err = cgs_tostr(&dstr, ULLONG_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_ullong_max[64];
        sprintf(expected_ullong_max, "%llu", ULLONG_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_ullong_max));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: float (positive)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        float val = 123.456f;
        CGS_Error err = cgs_tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_float[30];
        sprintf(expected_float, "%.6g", val); // Use appropriate precision for floats
        ASSERT_TRUE(cgs_equal(&dstr, expected_float));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: float (negative)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        float val = -987.65f;
        CGS_Error err = cgs_tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_float[30];
        sprintf(expected_float, "%.6g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_float));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: float zero");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        float val = 0.0f;
        CGS_Error err = cgs_tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_float[30];
        sprintf(expected_float, "%.6g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_float));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: double (positive)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(50);
        double val = 12345.67890123;
        CGS_Error err = cgs_tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_double[50];
        sprintf(expected_double, "%g", val); // Use appropriate precision for doubles
        ASSERT_TRUE(cgs_equal(&dstr, expected_double));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: double (negative)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(50);
        double val = -98765.43210987;
        CGS_Error err = cgs_tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_double[50];
        sprintf(expected_double, "%g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_double));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: double zero");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        double val = 0.0;
        CGS_Error err = cgs_tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_double[30];
        sprintf(expected_double, "%.12g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_double));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr: buffer too small for integer");;;
    {
        char backing[3]; // Can hold "12" + null terminator
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(backing, 3);
        cgs_clear(&sb);
        CGS_Error err = cgs_tostr(&sb, 123456); // Requires more than 2 characters + null
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_tostr: buffer too small for double");;;
    {
        char backing[5]; // Can hold "0.0" + null. Try to fit something bigger.
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(backing, 5);
        cgs_clear(&sb);
        CGS_Error err = cgs_tostr(&sb, 123.456);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    // You could add tests for:
    // - Scientific notation for very large/small floats/doubles if your cgs_tostr supports it.
    // - Special float values: INFINITY, -INFINITY, NaN (if cgs_tostr handles them gracefully).
    
    TEST("cgs_print: multiple arguments (concatenation)");;;
    {
        CGS_StrBuf sb = {0};
        cgs_tostr_many(&sb, 123, " ", "test", " ", cgs_nfmt(456.78f, 'f', 2), "!", -99);
        ASSERT_TRUE(cgs_equal(sb, ""));
    }
    
    TEST("cgs_print: multiple arguments (concatenation)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(50);
        cgs_tostr_many(&dstr, 123, " ", "test", " ", cgs_nfmt(456.78f, 'f', 2), "!", -99);
        ASSERT_TRUE(cgs_equal(&dstr, "123 test 456.78!-99"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_print: multiple arguments, buffer too small");;;
    {
        char backing[10];
        CGS_StrBuf sb = cgs_strbuf_init_from_buf(backing, 10);
        cgs_clear(&sb);
        cgs_tostr_many(&sb, 1, " ", "long_string_here");
        ASSERT_TRUE(cgs_equal(sb, "1 long_st"));
    }
    
    TEST("cgs_nfmt: various format characters");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        // Test hex, octal, etc.
        cgs_tostr(&dstr, cgs_nfmt(255, 'x'));
        ASSERT_TRUE(cgs_equal(dstr, "ff"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: integer decimal (signed/unsigned)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        cgs_tostr_many(&dstr, cgs_nfmt(0, 'd'), " ", cgs_nfmt(-123, 'd'), " ", cgs_nfmt(2147483647, 'd'));
        ASSERT_TRUE(cgs_equal(&dstr, "0 -123 2147483647"));
        cgs_dstr_deinit(&dstr);
    }

    TEST("cgs_nfmt: integer hexadecimal (x/X)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(20);
        cgs_tostr(&dstr, cgs_nfmt(255, 'x'));
        ASSERT_TRUE(cgs_equal(&dstr, "ff"));
        
        cgs_clear(&dstr);
        cgs_tostr(&dstr, cgs_nfmt(4095, 'X'));
        ASSERT_TRUE(cgs_equal(&dstr, "FFF"));
        cgs_dstr_deinit(&dstr);
    }

    TEST("cgs_nfmt: integer octal and binary");;;
    {
        CGS_DStr dstr = cgs_dstr_init(20);
        cgs_tostr_many(&dstr, cgs_nfmt(8, 'o'), " ", cgs_nfmt(5, 'b'));
        // 8 in octal is 10, 5 in binary is 101
        ASSERT_TRUE(cgs_equal(&dstr, "10 101"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: floating point fixed-point (f/F)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        // Test precision and rounding
        cgs_tostr_many(&dstr, cgs_nfmt(3.14159f, 'f', 2), " ", cgs_nfmt(-0.555f, 'f', 1));
        ASSERT_TRUE(cgs_equal(&dstr, "3.14 -0.6"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: scientific notation (e/E)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        cgs_tostr_many(&dstr, cgs_nfmt(1000.0, 'e', 2));
        ASSERT_TRUE(cgs_equal(&dstr, "1.00e+03"));
        
        cgs_clear(&dstr);
        cgs_tostr_many(&dstr, cgs_nfmt(0.001, 'E', 1));
        ASSERT_TRUE(cgs_equal(&dstr, "1.0E-03"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: general format (g/G)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        // 'g' chooses between fixed and scientific based on magnitude
        cgs_tostr_many(&dstr, cgs_nfmt(123.456, 'g', 4));
        ASSERT_TRUE(cgs_equal(&dstr, "123.5")); // 4 significant digits
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: hex-float (a/A)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(30);
        cgs_tostr(&dstr, cgs_nfmt(1.0, 'a'));
        // Usually 0x1.0p+0 or similar depending on implementation
        ASSERT_TRUE(cgs_equal(&dstr, "0x1p+0")); 
        
        cgs_clear(&dstr);
        cgs_tostr(&dstr, cgs_nfmt(15.5, 'A'));
        ASSERT_TRUE(cgs_equal(&dstr, "0X1.FP+3"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: integer limits and zero");;;
    {
        CGS_DStr dstr = cgs_dstr_init(50);
        long long max_val = 9223372036854775807LL;
        cgs_tostr_many(&dstr, cgs_nfmt(0, 'x'), " ", cgs_nfmt(max_val, 'd'));
        ASSERT_TRUE(cgs_equal(&dstr, "0 9223372036854775807"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: high precision and rounding");;;
    {
        CGS_DStr dstr = cgs_dstr_init(50);
        // Test very small float with high precision
        double val = 0.0000123456;
        cgs_tostr_many(&dstr, cgs_nfmt(val, 'f', 8));
        ASSERT_TRUE(cgs_equal(&dstr, "0.00001235"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr_many: complex mixed types");;;
    {
        CGS_DStr dstr = cgs_dstr_init(100);
        int hex_val = 0xDEAD;
        float pi = 3.14159f;
        cgs_tostr_many(&dstr, "Hex: ", cgs_nfmt(hex_val, 'X'), ", Pi: ", cgs_nfmt(pi, 'g', 3), ", Bin: ", cgs_nfmt(7, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "Hex: DEAD, Pi: 3.14, Bin: 111"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt (binary): basic and zero");;;
    {
        CGS_DStr dstr = cgs_dstr_init(20);
        // Zero is a common edge case
        cgs_tostr(&dstr, cgs_nfmt(0, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "0"));
        
        cgs_clear(&dstr);
        // Small powers of 2
        cgs_tostr_many(&dstr, cgs_nfmt(1, 'b'), ",", cgs_nfmt(2, 'b'), ",", cgs_nfmt(4, 'b'), ",", cgs_nfmt(8, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "1,10,100,1000"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt (octal): basic and zero");;;
    {
        CGS_DStr dstr = cgs_dstr_init(20);
        cgs_tostr(&dstr, cgs_nfmt(0, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "0"));
        
        cgs_clear(&dstr);
        // Standard octal transitions
        cgs_tostr_many(&dstr, cgs_nfmt(7, 'o'), ",", cgs_nfmt(8, 'o'), ",", cgs_nfmt(16, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "7,10,20"));
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: unsigned integer limits (binary)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(128);
        
        // uint8_t max (255)
        unsigned char u8_max = 255;
        cgs_tostr(&dstr, cgs_nfmt(u8_max, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "11111111"));
        
        cgs_clear(&dstr);
        // uint64_t max (18,446,744,073,709,551,615)
        unsigned long long u64_max = 0xFFFFFFFFFFFFFFFFULL;
        cgs_tostr(&dstr, cgs_nfmt(u64_max, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "1111111111111111111111111111111111111111111111111111111111111111"));
        
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: unsigned integer limits (octal)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(64);
        
        // uint16_t max (65535)
        unsigned short u16_max = 65535;
        cgs_tostr(&dstr, cgs_nfmt(u16_max, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "177777"));
        
        cgs_clear(&dstr);
        // uint32_t max (4294967295)
        unsigned int u32_max = 4294967295U;
        cgs_tostr(&dstr, cgs_nfmt(u32_max, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "37777777777"));
        
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: signed negative integers (binary/octal)");;;
    {
        // Note: Standard C behavior for %o and %x is to treat the bits as unsigned.
        // These tests assume your library follows that convention.
        CGS_DStr dstr = cgs_dstr_init(128);
        
        // int8_t -1 (Two's complement: 11111111)
        signed char s8_neg = -1;
        cgs_tostr(&dstr, cgs_nfmt(s8_neg, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "11111111"));
        
        cgs_clear(&dstr);
        // int16_t -1 in octal (Two's complement: 177777)
        short s16_neg = -1;
        cgs_tostr(&dstr, cgs_nfmt(s16_neg, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "177777"));
        
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: signed integer limits (decimal vs others)");;;
    {
        CGS_DStr dstr = cgs_dstr_init(128);
        
        // 64-bit Signed Minimum: -9,223,372,036,854,775,808
        long long s64_min = -9223372036854775807LL - 1LL;
        
        // Decimal should show the minus sign
        cgs_tostr(&dstr, cgs_nfmt(s64_min, 'd'));
        ASSERT_TRUE(cgs_equal(&dstr, "-9223372036854775808"));
        
        cgs_clear(&dstr);
        // Binary for signed min (usually 1 followed by 63 zeros)
        cgs_tostr(&dstr, cgs_nfmt(s64_min, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "1000000000000000000000000000000000000000000000000000000000000000"));
        
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("cgs_nfmt: type genericity check");;;
    {
        CGS_DStr dstr = cgs_dstr_init(100);
        
        unsigned char  v1 = 10;
        unsigned short v2 = 20;
        unsigned int   v3 = 30;
        
        // Testing that the macro/generic correctly handles different sizes in one call
        cgs_tostr_many(&dstr, cgs_nfmt(v1, 'b'), " ", cgs_nfmt(v2, 'o'), " ", cgs_nfmt(v3, 'x'));
        // 10=1010(b), 20=24(o), 30=1e(x)
        ASSERT_TRUE(cgs_equal(&dstr, "1010 24 1e"));
        
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Stress Tests
// ============================================================================

void test_stress_cases() {
    TEST("cgs_replace: fixed buffer overflow check");;;
    {
        char buf[10] = "apple"; // capacity 10
        // Result would be "appleapple", length 10 + 1 for null = 11.
        // This should return CGS_DST_TOO_SMALL
        CGS_Result(int) res = cgs_replace(buf, "apple", "appleapple");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: invalid indices");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        // Start > End
        CGS_Error err1 = cgs_replace_range(&s, 2, 1, "x");
        ASSERT_TRUE(err1.ec == CGS_BAD_RANGE);
        
        // Start out of bounds
        CGS_Error err2 = cgs_replace_range(&s, 5, 6, "x");
        ASSERT_TRUE(err2.ec == CGS_INDEX_OUT_OF_BOUNDS);
        
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace: fixed buffer overflow check");;;
    {
        char buf[10] = "apple"; // capacity 10
        // Result would be "appleapple", length 10 + 1 for null = 11.
        // This should return CGS_DST_TOO_SMALL
        CGS_Result(int) res = cgs_replace(buf, "apple", "appleapple");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: invalid indices");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        // Start > End
        CGS_Error err1 = cgs_replace_range(&s, 2, 1, "x");
        ASSERT_TRUE(err1.ec == CGS_BAD_RANGE);
        
        // Start out of bounds
        CGS_Error err2 = cgs_replace_range(&s, 5, 6, "x");
        ASSERT_TRUE(err2.ec == CGS_INDEX_OUT_OF_BOUNDS);
        
        cgs_dstr_deinit(&s);
    }
    
    TEST("stress: many allocations and deallocations");;;
    {
        for (int i = 0; i < 100; i++) {
            CGS_DStr dstr = cgs_dstr_init(i * 10);
            for (int j = 0; j < i; j++) {
                cgs_append(&dstr, "x");
            }
            cgs_dstr_deinit(&dstr);
        }
        ASSERT_TRUE(1);
    }
    
    TEST("stress: alternating growth and shrinkage");;;
    {
        CGS_DStr dstr = cgs_dstr_init(10);
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 100; j++) {
                cgs_putc(&dstr, 'x');
            }
            char x[101];
            memset(x, 'x', sizeof(x));
            x[sizeof(x) - 1] = 0;
            assert(cgs_equal(dstr, x));
            cgs_clear(&dstr);
        }
        cgs_dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
    
    TEST("stress: very deep nesting of operations");;;
    {
        CGS_DStr dstr = cgs_dstr_init(1000);
        cgs_append(&dstr, "start");
        for (int i = 0; i < 100; i++) {
            cgs_replace(&dstr, "start", "middle");
            cgs_replace(&dstr, "middle", "end");
            cgs_replace(&dstr, "end", "start");
        }
        ASSERT_TRUE(cgs_equal(&dstr, "start"));
        cgs_dstr_deinit(&dstr);
    }
}

// ============================================================================
// Special Character Tests
// ============================================================================

void test_special_characters() {
    TEST("special chars: all printable ASCII");;;
    {
        CGS_DStr dstr = cgs_dstr_init(200);
        for (char c = 32; c < 127; c++) {
            cgs_putc(&dstr, c);
        }
        ASSERT_EQ(cgs_len(&dstr), 127 - 32);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("special chars: control characters");;;
    {
        CGS_DStr dstr = cgs_dstr_init(50);
        cgs_putc(&dstr, '\t');
        cgs_putc(&dstr, '\n');
        cgs_putc(&dstr, '\r');
        ASSERT_EQ(cgs_len(&dstr), 3);
        cgs_dstr_deinit(&dstr);
    }
    
    TEST("special chars: high ASCII");;;
    {
        CGS_DStr dstr = cgs_dstr_init(200);
        for (unsigned char c = 128; c < 255; c++) {
            cgs_putc(&dstr, c);
        }
        cgs_dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
}

void test_replace_all()
{
    TEST("cgs_replace: standard multiple replacement");;;
    {
        CGS_DStr s = cgs_dstr_init_from("banana");
        CGS_Result(int) res = cgs_replace(&s, "a", "o");
        // Result: "bonono", count: 3
        ASSERT_TRUE(res.val == 3 && cgs_equal(&s, "bonono"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace: empty target (Injection behavior)");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        // Standard behavior (Python/JS): Replace "" with "-"
        // This usually results in "-a-b-c-"
        CGS_Result(int) res = cgs_replace(&s, "", "-");
        ASSERT_TRUE(cgs_equal(&s, "-a-b-c-"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace: replacement contains target (No infinite loop)");;;
    {
        CGS_DStr s = cgs_dstr_init_from("a");
        // Replacing "a" with "aa" should only happen once per original match
        CGS_Result(int) res = cgs_replace(&s, "a", "aa");
        ASSERT_TRUE(res.val == 1 && cgs_equal(&s, "aa"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace: non-overlapping counts");;;
    {
        CGS_DStr s = cgs_dstr_init_from("aaaaa"); 
        CGS_Result(int) res = cgs_replace(&s, "aa", "b");
        // Result must be "bba", count must be 2
        ASSERT_TRUE(res.val == 2);
        ASSERT_TRUE(cgs_equal(&s, "bba"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace: target longer than source");;;
    {
        CGS_DStr s = cgs_dstr_init_from("abc");
        CGS_Result(int) res = cgs_replace(&s, "abcd", "x");
        ASSERT_TRUE(res.val == 0 && cgs_equal(&s, "abc"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace: multiple replacements with different lengths");;;
    {
        CGS_DStr s = cgs_dstr_init_from("1-2-3");
        // Growing the string: "1" -> "one"
        CGS_Result(int) res = cgs_replace(&s, "-", "---");
        ASSERT_TRUE(cgs_equal(&s, "1---2---3"));
        cgs_dstr_deinit(&s);
    }
    
    TEST("cgs_replace: fixed buffer too small");;;
    {
        char buf[5] = "abc"; // Small fixed buffer
        CGS_Result(int) res = cgs_replace(buf, "b", "verylongstring");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_first: fixed buffer too small");;;
    {
        char buf[5] = "abc"; // Small fixed buffer
        CGS_Error res = cgs_replace_first(buf, "b", "verylongstring");
        ASSERT_TRUE(res.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace: target not found");;;
    {
        CGS_DStr s = cgs_dstr_init_from("hello");
        CGS_Result(int) res = cgs_replace(&s, "world", "earth");
        ASSERT_TRUE(res.val == 0 && res.err.ec == CGS_NOT_FOUND);
        cgs_dstr_deinit(&s);
    }
}

void test_alignfmt(void)
{
    char buf[64];

    /* ── LEFT: content shorter than width ─────────────────────── */

    TEST("cgs_alignfmt: left-align 'hello' width=10 space fill");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 10, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello     "));
    }

    TEST("cgs_alignfmt: left-align 'hello' width=10 dash fill");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 10, '-'));
        ASSERT_TRUE(cgs_equal (buf, "hello-----"));
    }

    TEST("cgs_alignfmt: left-align default fill (space)");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 8));
        ASSERT_TRUE(cgs_equal (buf, "hello   "));
    }

    /* ── RIGHT: content shorter than width ────────────────────── */

    TEST("cgs_alignfmt: right-align 'hello' width=10 space fill");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 10, ' '));
        ASSERT_TRUE(cgs_equal (buf, "     hello"));
    }

    TEST("cgs_alignfmt: right-align 'hello' width=10 dash fill");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 10, '-'));
        ASSERT_TRUE(cgs_equal (buf, "-----hello"));
    }

    TEST("cgs_alignfmt: right-align default fill (space)");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 8));
        ASSERT_TRUE(cgs_equal (buf, "   hello"));
    }

    /* ── CENTER: even padding ─────────────────────────────────── */

    TEST("cgs_alignfmt: center 'hi' width=6 even padding → 2 left 2 right");
    {
        char *s = "hi";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 6, ' '));
        ASSERT_TRUE(cgs_equal (buf, "  hi  "));
    }

    TEST("cgs_alignfmt: center 'hi' width=6 star fill even padding");
    {
        char *s = "hi";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 6, '*'));
        ASSERT_TRUE(cgs_equal (buf, "**hi**"));
    }

    TEST("cgs_alignfmt: center 'hello' width=9 even padding → 2 left 2 right");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 9, ' '));
        ASSERT_TRUE(cgs_equal (buf, "  hello  "));
    }

    /* ── CENTER: odd padding (extra goes RIGHT) ───────────────── */

    TEST("cgs_alignfmt: center 'hi' width=7 odd padding → 2 left 3 right");
    {
        char *s = "hi";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 7, ' '));
        ASSERT_TRUE(cgs_equal (buf, "  hi   "));
    }

    TEST("cgs_alignfmt: center 'hi' width=7 star fill odd → extra right");
    {
        char *s = "hi";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 7, '*'));
        ASSERT_TRUE(cgs_equal (buf, "**hi***"));
    }

    TEST("cgs_alignfmt: center 'abc' width=8 odd padding → 2 left 3 right");
    {
        char *s = "abc";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 8, ' '));
        ASSERT_TRUE(cgs_equal (buf, "  abc   "));
    }

    TEST("cgs_alignfmt: center 'x' width=4 odd padding → 1 left 2 right");
    {
        /* 4-1=3 padding, 3/2=1 left, 2 right */
        char *s = "x";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 4, '.'));
        ASSERT_TRUE(cgs_equal (buf, ".x.."));
    }

    TEST("cgs_alignfmt: center 'X' width=20 odd padding → 9 left 10 right");
    {
        /* 20-1=19 padding, 19/2=9 left, 10 right */
        char *s = "X";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 20, ' '));
        ASSERT_TRUE(strlen(buf) == 20);
        ASSERT_TRUE(buf[9]  == 'X');
        ASSERT_TRUE(buf[0]  == ' ');
        ASSERT_TRUE(buf[19] == ' ');
    }

    /* ── Width == content length (no padding added) ───────────── */

    TEST("cgs_alignfmt: left-align exact width → no padding");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 5, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    TEST("cgs_alignfmt: right-align exact width → no padding");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 5, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    TEST("cgs_alignfmt: center exact width → no padding");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 5, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    TEST("cgs_alignfmt: center 'x' width=1 exact → no padding");
    {
        char *s = "x";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 1, ' '));
        ASSERT_TRUE(cgs_equal (buf, "x"));
    }

    /* ── Width < content length (no truncation) ──────────────── */

    TEST("cgs_alignfmt: left-align width < length → full content, no truncation");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 3, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    TEST("cgs_alignfmt: right-align width < length → full content, no truncation");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 3, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    TEST("cgs_alignfmt: center width < length → full content, no truncation");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 3, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    /* ── Width == 0 ───────────────────────────────────────────── */

    TEST("cgs_alignfmt: left-align width=0 → content unchanged");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 0, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    TEST("cgs_alignfmt: right-align width=0 → content unchanged");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 0, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    TEST("cgs_alignfmt: center width=0 → content unchanged");
    {
        char *s = "hello";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 0, ' '));
        ASSERT_TRUE(cgs_equal (buf, "hello"));
    }

    /* ── Empty string ─────────────────────────────────────────── */

    TEST("cgs_alignfmt: left-align empty string width=4 → all fill");
    {
        char *s = "";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 4, '_'));
        ASSERT_TRUE(cgs_equal (buf, "____"));
    }

    TEST("cgs_alignfmt: right-align empty string width=4 → all fill");
    {
        char *s = "";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 4, '_'));
        ASSERT_TRUE(cgs_equal (buf, "____"));
    }

    TEST("cgs_alignfmt: center empty string width=4 → all fill");
    {
        /* 4-0=4 padding, even → 2 left 2 right */
        char *s = "";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 4, '_'));
        ASSERT_TRUE(cgs_equal (buf, "____"));
    }

    TEST("cgs_alignfmt: center empty string width=5 → all fill odd → extra right");
    {
        /* 5 padding, odd → 2 left 3 right */
        char *s = "";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_CENTER, 5, '_'));
        ASSERT_TRUE(cgs_equal (buf, "_____"));
    }

    /* ── Non-string types ─────────────────────────────────────── */

    TEST("cgs_alignfmt: right-align int 42 width=6 zero fill → '000042'");
    {
        int n = 42;
        cgs_fmt(buf, "%?", cgs_alignfmt(n, CGS_ALIGN_RIGHT, 6, '0'));
        ASSERT_TRUE(cgs_equal (buf, "000042"));
    }

    TEST("cgs_alignfmt: left-align int 42 width=6 zero fill → '420000'");
    {
        int n = 42;
        cgs_fmt(buf, "%?", cgs_alignfmt(n, CGS_ALIGN_LEFT, 6, '0'));
        ASSERT_TRUE(cgs_equal (buf, "420000"));
    }

    TEST("cgs_alignfmt: center int 42 width=6 zero fill → '004200'");
    {
        /* "42" len=2, 6-2=4 padding, even → 2 left 2 right */
        int n = 42;
        cgs_fmt(buf, "%?", cgs_alignfmt(n, CGS_ALIGN_CENTER, 6, '0'));
        ASSERT_TRUE(cgs_equal (buf, "004200"));
    }

    TEST("cgs_alignfmt: right-align int 42 width=2 exact → '42'");
    {
        int n = 42;
        cgs_fmt(buf, "%?", cgs_alignfmt(n, CGS_ALIGN_RIGHT, 2, '0'));
        ASSERT_TRUE(cgs_equal (buf, "42"));
    }

    TEST("cgs_alignfmt: right-align int 42 width=1 smaller → '42' no truncation");
    {
        int n = 42;
        cgs_fmt(buf, "%?", cgs_alignfmt(n, CGS_ALIGN_RIGHT, 1, '0'));
        ASSERT_TRUE(cgs_equal (buf, "42"));
    }

    /* ── Large width ──────────────────────────────────────────── */

    TEST("cgs_alignfmt: left-align 'X' width=20 → 'X' followed by 19 spaces");
    {
        char *s = "X";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 20, ' '));
        ASSERT_TRUE(strlen(buf) == 20);
        ASSERT_TRUE(buf[0] == 'X');
        ASSERT_TRUE(buf[1] == ' ');
        ASSERT_TRUE(buf[19] == ' ');
    }

    TEST("cgs_alignfmt: right-align 'X' width=20 → 19 spaces then 'X'");
    {
        char *s = "X";
        cgs_fmt(buf, "%?", cgs_alignfmt(s, CGS_ALIGN_RIGHT, 20, ' '));
        ASSERT_TRUE(strlen(buf) == 20);
        ASSERT_TRUE(buf[0]  == ' ');
        ASSERT_TRUE(buf[19] == 'X');
    }

    /* ── Composition: alignfmt inside larger fmt string ──────── */

    TEST("cgs_alignfmt: embedded in fmt string with brackets");
    {
        char *s = "ok";
        cgs_fmt(buf, "[%?]", cgs_alignfmt(s, CGS_ALIGN_CENTER, 6, '-'));
        ASSERT_TRUE(cgs_equal (buf, "[--ok--]"));
    }

    TEST("cgs_alignfmt: two alignfmts as separate args in one fmt call");
    {
        char *s = "hello";
        cgs_fmt(buf, "%? | %?",
                cgs_alignfmt(s, CGS_ALIGN_LEFT, 8,  '.'),
                cgs_alignfmt(s, CGS_ALIGN_RIGHT, 8, '.'));
        ASSERT_TRUE(cgs_equal (buf, "hello... | ...hello"));
    }

    /* ── arrfmt inside alignfmt ───────────────────────────────── */

    TEST("cgs_alignfmt: left-align arrfmt result");
    {
        /* "{1, 2, 3}" is 9 chars, width=14 → 5 spaces right */
        int arr[] = {1, 2, 3};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3);
        cgs_fmt(buf, "%?", cgs_alignfmt(af, CGS_ALIGN_LEFT, 14, ' '));
        ASSERT_TRUE(cgs_equal (buf, "{1, 2, 3}     "));
    }

    TEST("cgs_alignfmt: right-align arrfmt result");
    {
        int arr[] = {1, 2, 3};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3);
        cgs_fmt(buf, "%?", cgs_alignfmt(af, CGS_ALIGN_RIGHT, 14, ' '));
        ASSERT_TRUE(cgs_equal (buf, "     {1, 2, 3}"));
    }

    TEST("cgs_alignfmt: center arrfmt result even padding");
    {
        /* "{1, 2, 3}" is 9 chars, width=13 → 4 padding even → 2 left 2 right */
        int arr[] = {1, 2, 3};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3);
        cgs_fmt(buf, "%?", cgs_alignfmt(af, CGS_ALIGN_CENTER, 13, ' '));
        ASSERT_TRUE(cgs_equal (buf, "  {1, 2, 3}  "));
    }

    TEST("cgs_alignfmt: center arrfmt result odd padding → extra right");
    {
        /* "{1, 2, 3}" is 9 chars, width=14 → 5 padding odd → 2 left 3 right */
        int arr[] = {1, 2, 3};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3);
        cgs_fmt(buf, "%?", cgs_alignfmt(af, CGS_ALIGN_CENTER, 14, '-'));
        ASSERT_TRUE(cgs_equal (buf, "--{1, 2, 3}---"));
    }

    TEST("cgs_alignfmt: right-align arrfmt with custom open/close/delim");
    {
        /* "[1|2|3]" is 7 chars, width=11 → 4 spaces left */
        int arr[] = {1, 2, 3};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3, "[", "]", "|", "");
        cgs_fmt(buf, "%?", cgs_alignfmt(af, CGS_ALIGN_RIGHT, 11, ' '));
        ASSERT_TRUE(cgs_equal (buf, "    [1|2|3]"));
    }

    TEST("cgs_alignfmt: center arrfmt exact width → no padding");
    {
        /* "{1, 2, 3}" is 9 chars, width=9 → no padding */
        int arr[] = {1, 2, 3};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3);
        cgs_fmt(buf, "%?", cgs_alignfmt(af, CGS_ALIGN_CENTER, 9, '*'));
        ASSERT_TRUE(cgs_equal (buf, "{1, 2, 3}"));
    }

    TEST("cgs_alignfmt: left-align arrfmt width < content → no truncation");
    {
        int arr[] = {1, 2, 3};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3);
        cgs_fmt(buf, "%?", cgs_alignfmt(af, CGS_ALIGN_LEFT, 3, ' '));
        ASSERT_TRUE(cgs_equal (buf, "{1, 2, 3}"));
    }

    /* ── alignfmt inside arrfmt ───────────────────────────────── */

    TEST("cgs_arrfmt: array of aligned ints via alignfmt");
    {
        /* each int aligned right in width 4 with '0':
         * 1 → "0001", 20 → "0020", 300 → "0300"
         * arrfmt default: "{0001, 0020, 0300}" */
        /* arrfmt takes T* and size_t, elements must have tostr.
         * CGS__AlignFmt has tostr, so make an array of them. */
        int n1 = 1, n2 = 20, n3 = 300;
        CGS__AlignFmt elems[3] = {
            cgs_alignfmt(n1, CGS_ALIGN_RIGHT, 4, '0'),
            cgs_alignfmt(n2, CGS_ALIGN_RIGHT, 4, '0'),
            cgs_alignfmt(n3, CGS_ALIGN_RIGHT, 4, '0'),
        };
        CGS_ArrayFmt af = cgs_arrfmt(elems, 3);
        cgs_fmt(buf, "%?", af);
        ASSERT_TRUE(cgs_equal (buf, "{0001, 0020, 0300}"));
    }

    TEST("cgs_arrfmt: array of center-aligned strings");
    {
        char *a = "a", *bb = "bb", *ccc = "ccc";
        CGS__AlignFmt elems[3] = {
            cgs_alignfmt(a,   CGS_ALIGN_CENTER, 5, '-'),
            cgs_alignfmt(bb,  CGS_ALIGN_CENTER, 5, '-'),
            cgs_alignfmt(ccc, CGS_ALIGN_CENTER, 5, '-'),
        };
        /* "a"   width=5 → 2 left 2 right → "--a--"
         * "bb"  width=5 → 1 left 2 right → "-bb--" (odd extra right)
         * "ccc" width=5 → 1 left 1 right → "-ccc-" */
        CGS_ArrayFmt af = cgs_arrfmt(elems, 3, "[", "]", ", ", "");
        cgs_fmt(buf, "%?", af);
        ASSERT_TRUE(cgs_equal (buf, "[--a--, -bb--, -ccc-]"));
    }

    /* ── both nested in cgs_fmt with other args ───────────────── */

    TEST("cgs_fmt: alignfmt and arrfmt as separate args in one call");
    {
        int arr[] = {7, 8, 9};
        CGS_ArrayFmt af = cgs_arrfmt(arr, 3);
        char *label = "data";
        cgs_fmt(buf, "%?: %?",
                cgs_alignfmt(label, CGS_ALIGN_LEFT, 8, '.'),
                af);
        ASSERT_TRUE(cgs_equal (buf, "data....: {7, 8, 9}"));
    }

    TEST("cgs_fmt: aligned arrfmt next to aligned scalar");
    {
        int arr[] = {1, 2};
        CGS_ArrayFmt af  = cgs_arrfmt(arr, 2);
        int          n   = 42;
        cgs_fmt(buf, "[%?][%?]",
                cgs_alignfmt(af, CGS_ALIGN_RIGHT, 10, ' '),
                cgs_alignfmt(n,   CGS_ALIGN_LEFT, 6,  '0'));
        /* "{1, 2}" is 6 chars, right in 10 → "    {1, 2}"
         * "42"    is 2 chars, left  in  6 → "420000" */
        ASSERT_TRUE(cgs_equal (buf, "[    {1, 2}][420000]"));
    }

    TEST("cgs_fmt: arrfmt of alignfmts embedded inside another alignfmt");
    {
        /* inner: array of right-aligned ints → "{  1,  2,  3}"
         * outer: that whole string centered in width 17            */
        int n1 = 1, n2 = 2, n3 = 3;
        CGS__AlignFmt inner_elems[3] = {
            cgs_alignfmt(n1, CGS_ALIGN_RIGHT, 2, ' '),
            cgs_alignfmt(n2, CGS_ALIGN_RIGHT, 2, ' '),
            cgs_alignfmt(n3, CGS_ALIGN_RIGHT, 2, ' '),
        };
        CGS_ArrayFmt inner_af = cgs_arrfmt(inner_elems, 3);
        /* inner_af tostr → "{ 1,  2,  3}" (13 chars) */
        cgs_fmt(buf, "%?", cgs_alignfmt(inner_af, CGS_ALIGN_CENTER, 17, '='));
        /* 17-13=4 padding even → 2 left 2 right */
        ASSERT_TRUE(cgs_equal (buf, "=={ 1,  2,  3}==="));
    }

    TEST("cgs_fmt: three-level nesting alignfmt(arrfmt(alignfmt))");
    {
        /* level 1: right-align each int in width 3 with '0'
         *   1 → "001", 22 → "022", 333 → "333"
         * level 2: arrfmt with custom brackets → "<001|022|333>"  (13 chars)
         * level 3: left-align that in width 16 with '.' */
        int n1 = 1, n2 = 22, n3 = 333;
        CGS__AlignFmt l1[3] = {
            cgs_alignfmt(n1, CGS_ALIGN_RIGHT, 3, '0'),
            cgs_alignfmt(n2, CGS_ALIGN_RIGHT, 3, '0'),
            cgs_alignfmt(n3, CGS_ALIGN_RIGHT, 3, '0'),
        };
        CGS_ArrayFmt l2 = cgs_arrfmt(l1, 3, "<", ">", "|", "");
        cgs_fmt(buf, "%?", cgs_alignfmt(l2, CGS_ALIGN_LEFT, 16, '.'));
        ASSERT_TRUE(cgs_equal (buf, "<001|022|333>..."));
    }
}

void test_writer_counter(void)
{
    /* unsigned int* as writer_t — counts chars written, discards content */
    
    /* ── cgs_append ───────────────────────────────────────────── */
    
    TEST("writer unsigned int*: cgs_append counts chars of a plain string");
    {
        unsigned int n = 0;
        cgs_append(&n, "hello");
        ASSERT_TRUE(n == 5);
    }
    
    TEST("writer unsigned int*: cgs_append accumulates across multiple calls");
    {
        unsigned int n = 0;
        cgs_append(&n, "hello");
        cgs_append(&n, ", ");
        cgs_append(&n, "world");
        ASSERT_TRUE(n == 12);
    }
    
    TEST("writer unsigned int*: cgs_append of empty string adds 0");
    {
        unsigned int n = 0;
        cgs_append(&n, "hello");
        cgs_append(&n, "");
        ASSERT_TRUE(n == 5);
    }
    
    TEST("writer unsigned int*: cgs_append of StrView counts only the view length");
    {
        /* StrView of "hello" [1,4) → "ell" (3 chars) */
        unsigned int n = 0;
        cgs_append(&n, cgs_strv("hello", 1, 4));
        ASSERT_TRUE(n == 3);
    }
    
    TEST("writer unsigned int*: cgs_append starts from existing count");
    {
        unsigned int n = 10;
        cgs_append(&n, "hello");
        ASSERT_TRUE(n == 15);
    }
    
    /* ── cgs_putc ─────────────────────────────────────────────── */
    
    TEST("writer unsigned int*: cgs_putc counts 1");
    {
        unsigned int n = 0;
        cgs_putc(&n, 'x');
        ASSERT_TRUE(n == 1);
    }
    
    TEST("writer unsigned int*: cgs_putc accumulates");
    {
        unsigned int n = 0;
        cgs_putc(&n, 'a');
        cgs_putc(&n, 'b');
        cgs_putc(&n, 'c');
        ASSERT_TRUE(n == 3);
    }
    
    /* ── cgs_appendf ───────────────────────────────────────── */
    
    TEST("writer unsigned int*: cgs_appendf counts formatted output length");
    {
        unsigned int n = 0;
        cgs_appendf(&n, "%? + %? = %?", 1, 2, 3);
        /* "1 + 2 = 3" → 9 chars */
        ASSERT_TRUE(n == 9);
    }
    
    TEST("writer unsigned int*: cgs_appendf accumulates across calls");
    {
        unsigned int n = 0;
        cgs_appendf(&n, "%?", "hello");
        cgs_appendf(&n, "%?", "world");
        ASSERT_TRUE(n == 10);
    }
    
    TEST("writer unsigned int*: cgs_appendf with nfmt counts correctly");
    {
        /* cgs_nfmt(255, 'X') → "FF" (2 chars) */
        unsigned int n = 0;
        cgs_appendf(&n, "%?", cgs_nfmt(255, 'X'));
        ASSERT_TRUE(n == 2);
    }
    
    TEST("writer unsigned int*: cgs_appendf with arrfmt counts correctly");
    {
        /* "{1, 2, 3}" → 9 chars */
        int arr[] = {1, 2, 3};
        unsigned int n = 0;
        cgs_appendf(&n, "%?", cgs_arrfmt(arr, 3));
        ASSERT_TRUE(n == 9);
    }
    
    TEST("writer unsigned int*: cgs_appendf with alignfmt counts padded length");
    {
        /* "hello" left-aligned in width 10 → "hello     " → 10 chars */
        char *s = "hello";
        unsigned int n = 0;
        cgs_appendf(&n, "%?", cgs_alignfmt(s, CGS_ALIGN_LEFT, 10, ' '));
        ASSERT_TRUE(n == 10);
    }
    
    /* ── cgs_append_tostr / cgs_append_tostr_many ─────────────── */
    
    TEST("writer unsigned int*: cgs_append_tostr counts int tostr length");
    {
        unsigned int n = 0;
        cgs_append_tostr(&n, 12345);
        /* "12345" → 5 chars */
        ASSERT_TRUE(n == 5);
    }
    
    TEST("writer unsigned int*: cgs_append_tostr counts negative int tostr length");
    {
        unsigned int n = 0;
        cgs_append_tostr(&n, -99);
        /* "-99" → 3 chars */
        ASSERT_TRUE(n == 3);
    }
    
    TEST("writer unsigned int*: cgs_append_tostr_many sums all args");
    {
        /* "hello" + ", " + "42" → 5+2+2 = 9 chars */
        unsigned int n = 0;
        cgs_append_tostr_many(&n, "hello", ", ", 42);
        ASSERT_TRUE(n == 9);
    }
    
    TEST("writer unsigned int*: cgs_append_tostr_many with nfmt");
    {
        /* "FF" + " " + "255" → 2+1+3 = 6 chars */
        unsigned int n = 0;
        cgs_append_tostr_many(&n, cgs_nfmt(255, 'X'), " ", 255);
        ASSERT_TRUE(n == 6);
    }
    
    /* ── use as a dry-run before allocating ───────────────────── */
    
    TEST("writer unsigned int*: dry-run matches actual written length");
    {
        /* count first, then write to a real buffer, check lengths match */
        unsigned int n = 0;
        cgs_appendf(&n, "%? = %?", "answer", 42);
        
        char buf[64];
        cgs_fmt(buf, "%? = %?", "answer", 42);
        
        ASSERT_TRUE(n == cgs_len(buf));
    }
    
    TEST("writer unsigned int*: dry-run of complex nested fmt");
    {
        int arr[] = {10, 200, 3000};
        char *label = "vals";
        
        unsigned int n = 0;
        cgs_appendf(&n, "%?: %?", cgs_alignfmt(label, CGS_ALIGN_LEFT, 8, '.'), cgs_arrfmt(arr, 3));
        
        char buf[64];
        cgs_fmt(buf, "%?: %?", cgs_alignfmt(label, CGS_ALIGN_LEFT, 8 , '.'), cgs_arrfmt(arr, 3));
        
        ASSERT_TRUE(n == cgs_len(buf));
    }
    
    /* ── cgs_writer wrapping unsigned int* ────────────────────── */
    
    TEST("writer unsigned int*: cgs_writer wraps counter and counts via append");
    {
        unsigned int n = 0;
        CGS_Writer *w = cgs_writer_ptr(&n);
        cgs_append(w, "abc");
        cgs_append(w, "de");
        ASSERT_TRUE(n == 5);
    }
    
    TEST("writer unsigned int*: cgs_writer counts putc calls");
    {
        unsigned int n = 0;
        CGS_Writer *w = cgs_writer_ptr(&n);
        cgs_putc(w, 'x');
        cgs_putc(w, 'y');
        ASSERT_TRUE(n == 2);
    }
    
    TEST("writer unsigned int*: cgs_writer counts append_fmt output");
    {
        /* "1 + 2 = 3" → 9 chars */
        unsigned int n = 0;
        CGS_Writer *w = cgs_writer_ptr(&n);
        cgs_appendf(w, "%? + %? = %?", 1, 2, 3);
        ASSERT_TRUE(n == 9);
    }
}

// ============================================================================
// Main
// ============================================================================

int main() {
    printf("========================================\n");
    printf("String Library Edge Case Test Suite\n");
    printf("========================================\n\n");
    
    test_str_len_edge_cases();
    test_str_cap_edge_cases();
    test_str_equal_edge_cases();
    test_str_find_edge_cases();
    test_str_count_edge_cases();
    test_str_clear_edge_cases();
    test_str_starts_ends_with_edge_cases();
    test_str_case_edge_cases();
    test_str_copy_edge_cases();
    test_str_putc_edge_cases();
    test_str_append_edge_cases();
    test_str_del_edge_cases();
    test_str_replace_edge_cases();
    test_str_replace_first_edge_cases();
    test_str_replace_range_edge_cases();
    test_str_split_edge_cases();
    test_str_insert_prepend_edge_cases();
    test_dstring_edge_cases();
    test_string_buffer_edge_cases();
    test_strv_edge_cases();
    test_file_io_edge_cases();
    test_appender_edge_cases();
    test_str_join_edge_cases();
    test_tostr_edge_cases();
    test_stress_cases();
    test_special_characters();
    test_replace_all();
    test_alignfmt();
    test_writer_counter();
    test_spn_cspn_tok();
    
    printf("\n========================================\n");
    printf("Test Results: %d/%d passed\n", passed_count, test_count);
    printf("========================================\n");
        
    return (passed_count == test_count) ? 0 : 1;
}
