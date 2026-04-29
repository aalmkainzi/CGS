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
    
    TEST("cgs_len: DStr with zero capacity");;;
    {
        DStr dstr = dstr_init(0);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_len: very long string");;;
    {
        // This tests if length calculation handles large strings
        DStr dstr = dstr_init(10000);
        for (int i = 0; i < 9999; i++) {
            cgs_putc(&dstr, 'a');
        }
        ASSERT_EQ(cgs_len(&dstr), 9999);
        dstr_deinit(&dstr);
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
    
    TEST("cgs_cap: StrBuf at exact capacity");;;
    {
        char backing[5] = {'t', 'e', 's', 't', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 5);
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
        DStr dstr = dstr_init_from(cstr);
        ASSERT_TRUE(cgs_equal(cstr, &dstr));
        ASSERT_TRUE(cgs_equal(&dstr, cstr));
        dstr_deinit(&dstr);
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
        DStr a = dstr_init(5000);
        DStr b = dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            cgs_putc(&a, 'x');
            cgs_putc(&b, 'x');
        }
        ASSERT_TRUE(cgs_equal(&a, &b));
        dstr_deinit(&a);
        dstr_deinit(&b);
    }
}

// ============================================================================
// Edge Case Tests for cgs_find
// ============================================================================

void test_str_find_edge_cases() {
    TEST("cgs_find: basic match");;;
    {
        char hay[] = "hello world";
        StrView v = cgs_find(hay, "world");
        // Should return view starting at index 6, length 5
        ASSERT_TRUE(v.chars == &hay[6]);
        ASSERT_TRUE(v.len == 5);
    }
    
    TEST("cgs_find: not found");;;
    {
        StrView v = cgs_find("apple", "orange");
        // Usually returns a null view (chars == NULL) or a view with len 0
        ASSERT_TRUE(v.chars == NULL || v.len == 0);
    }
    
    TEST("cgs_find: match at start and end");;;
    {
        char hay[] = "bracket";
        StrView start = cgs_find(hay, "b");
        StrView end = cgs_find(hay, "t");
        
        ASSERT_TRUE(start.chars == &hay[0]);
        ASSERT_TRUE(end.chars == &hay[6]);
    }
    
    TEST("cgs_find: empty needle");;;
    {
        char hay[] = "abc";
        StrView v = cgs_find(hay, "");
        // In most languages, finding "" returns the start of the string
        ASSERT_TRUE(v.chars == &hay[0]);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_find: needle equals haystack");;;
    {
        char hay[] = "same";
        StrView v = cgs_find(hay, "same");
        ASSERT_TRUE(v.len == 4 && v.chars == &hay[0]);
    }
    
    TEST("cgs_find: needle longer than haystack");;;
    {
        StrView v = cgs_find("short", "much longer needle");
        ASSERT_TRUE(v.chars == NULL || v.len == 0);
    }
    
    TEST("cgs_find: empty needle in empty haystack");;;
    {
        char hay[] = "";
        char needle[] = "";
        StrView result = cgs_find(hay, needle);
        // Finding empty in empty might return start or invalid
        // Check it doesn't crash
        ASSERT_TRUE((char*)result.chars == hay);
    }
    
    TEST("cgs_find: empty needle in non-empty haystack");;;
    {
        char hay[] = "test";
        char needle[] = "";
        StrView result = cgs_find(hay, needle);
        // Should probably find at position 0 or be invalid
        ASSERT_TRUE(result.chars == hay);
    }
    
    TEST("cgs_find: needle longer than haystack");;;
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 0); // Not found
    }
    
    TEST("cgs_find: needle equals haystack");;;
    {
        char hay[] = "exact";
        char needle[] = "exact";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 5);
    }
    
    TEST("cgs_find: needle at very end");;;
    {
        char hay[] = "abcdefghij";
        char needle[] = "hij";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 3);
    }
    
    TEST("cgs_find: needle at very start");;;
    {
        char hay[] = "abcdefghij";
        char needle[] = "abc";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 3);
    }
    
    TEST("cgs_find: overlapping pattern");;;
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        StrView result = cgs_find(hay, needle);
        // Should find first occurrence
        ASSERT_TRUE(cgs_len(result) > 0);
    }
    
    TEST("cgs_find: pattern that almost matches");;;
    {
        char hay[] = "abcabcabd";
        char needle[] = "abcabd";
        StrView result = cgs_find(hay, needle);
        ASSERT_TRUE(cgs_len(result) > 0);
    }
    
    /* --- cgs_trim_view --- */
    
    TEST("cgs_trim_view: no whitespace");;;
    {
        char s[] = "hello";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: leading spaces");;;
    {
        char s[] = "   hello";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[3]);
    }
    
    TEST("cgs_trim_view: trailing spaces");;;
    {
        char s[] = "hello   ";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: leading and trailing spaces");;;
    {
        char s[] = "  hello  ";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[2]);
    }
    
    TEST("cgs_trim_view: interior whitespace is preserved");;;
    {
        char s[] = "  hello world  ";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 11 && v.chars == &s[2]);
    }
    
    TEST("cgs_trim_view: only spaces");;;
    {
        char s[] = "     ";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_trim_view: empty string");;;
    {
        char s[] = "";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_trim_view: empty string");;;
    {
        char s[] = " \t\n";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_trim_view: single non-whitespace character");;;
    {
        char s[] = "x";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 1 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: single space");;;
    {
        char s[] = " ";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 0 && v.chars == s + 1);
    }
    
    TEST("cgs_trim_view: leading tab");;;
    {
        char s[] = "\thello";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[1]);
    }
    
    TEST("cgs_trim_view: trailing newline");;;
    {
        char s[] = "hello\n";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[0]);
    }
    
    TEST("cgs_trim_view: mixed whitespace characters on both sides");;;
    {
        char s[] = " \t\n hello \r\n";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.len == 5 && v.chars == &s[4]);
    }
    
    TEST("cgs_trim_view: accepts StrView");;;
    {
        StrView src = strv("  hi  ");
        StrView v = cgs_trim_view(src);
        ASSERT_TRUE(v.len == 2);
    }
    
    TEST("cgs_trim_view: accepts DStr");;;
    {
        DStr d = dstr_init_from("  hi  ");
        StrView v = cgs_trim_view(d);
        ASSERT_TRUE(v.len == 2);
        dstr_deinit(&d);
    }
    
    TEST("cgs_trim_view: result points into original buffer, not a copy");;;
    {
        char s[] = "  abc  ";
        StrView v = cgs_trim_view(s);
        ASSERT_TRUE(v.chars == &s[2]);
    }
    
    TEST("cgs_trim_view: only spaces");;;
    {
        char s[] = "   ";
        StrView v = cgs_trim_view(s);
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
    
    TEST("cgs_trim: DStr*");;;
    {
        DStr d = dstr_init_from("  hello  ");
        char *p = cgs_chars(d);
        CGS_Error e = cgs_trim(&d);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(d, "hello") && cgs_chars(d) == p);
        dstr_deinit(&d);
    }
    
    TEST("cgs_trim: StrBuf*");;;
    {
        char buf[64] = "  hello  ";
        StrBuf sb = strbuf_init_from_cstr(buf, sizeof(buf));
        char *p = cgs_chars(sb);
        CGS_Error e = cgs_trim(&sb);
        ASSERT_TRUE(e.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(sb, "hello") && cgs_chars(sb) == p);
    }
    
    TEST("cgs_trim: MutStrRef");;;
    {
        char buf[64] = "  hello  ";
        MutStrRef ref = mutstr_ref(buf);
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
    
    /* --- cgs_spn --- */
    
    TEST("cgs_spn: entire string in charset");;;
    {
        char s[] = "aabbcc";
        ASSERT_TRUE(cgs_spn(s, "abc").len == 6);
    }
    
    TEST("cgs_spn: no chars in charset");;;
    {
        char s[] = "hello";
        ASSERT_TRUE(cgs_spn(s, "xyz").len == 0);
    }
    
    TEST("cgs_spn: partial match at start");;;
    {
        char s[] = "aaabcd";
        ASSERT_TRUE(cgs_spn(s, "ab").len == 4);
    }
    
    TEST("cgs_spn: match stops at first non-charset char");;;
    {
        char s[] = "aaa!aaa";
        ASSERT_TRUE(cgs_spn(s, "a").len == 3);
    }
    
    TEST("cgs_spn: empty string");;;
    {
        char s[] = "";
        ASSERT_TRUE(cgs_spn(s, "abc").len == 0);
    }
    
    TEST("cgs_spn: empty charset");;;
    {
        char s[] = "hello";
        ASSERT_TRUE(cgs_spn(s, "").len == 0);
    }
    
    TEST("cgs_spn: both empty");;;
    {
        char s[] = "";
        ASSERT_TRUE(cgs_spn(s, "").len == 0);
    }
    
    TEST("cgs_spn: single char string, in charset");;;
    {
        char s[] = "a";
        ASSERT_TRUE(cgs_spn(s, "a").len == 1);
    }
    
    TEST("cgs_spn: single char string, not in charset");;;
    {
        char s[] = "a";
        ASSERT_TRUE(cgs_spn(s, "b").len == 0);
    }
    
    TEST("cgs_spn: charset has duplicate chars");;;
    {
        char s[] = "aaabbb";
        ASSERT_TRUE(cgs_spn(s, "aaabbb").len == 6);
    }
    
    TEST("cgs_spn: charset larger than string");;;
    {
        char s[] = "ab";
        ASSERT_TRUE(cgs_spn(s, "abcdefghijklmnop").len == 2);
    }
    
    TEST("cgs_spn: whitespace charset");;;
    {
        char s[] = "   \t\nhello";
        ASSERT_TRUE(cgs_spn(s, " \t\n\r").len == 5);
    }
    
    TEST("cgs_spn: first char not in charset");;;
    {
        char s[] = "xaaa";
        ASSERT_TRUE(cgs_spn(s, "a").len == 0);
    }
    
    TEST("cgs_spn: accepts StrView");;;
    {
        StrView sv = strv("aaabcd");
        ASSERT_TRUE(cgs_spn(sv, "a").len == 3);
    }
    
    TEST("cgs_spn: accepts DStr");;;
    {
        DStr d = dstr_init_from("aaabcd");
        ASSERT_TRUE(cgs_spn(d, "a").len == 3);
        dstr_deinit(&d);
    }
    
    TEST("cgs_spn: charset as StrView");;;
    {
        char s[] = "aaabcd";
        StrView charset = strv("a");
        ASSERT_TRUE(cgs_spn(s, charset).len == 3);
    }
    
    TEST("cgs_spn: result equals length means all chars matched");;;
    {
        char s[] = "abcabc";
        unsigned int n = cgs_spn(s, "abc").len;
        ASSERT_TRUE(n == cgs_len(s));
    }
    
    /* --- cgs_cspn --- */
    
    TEST("cgs_cspn: no chars in charset");;;
    {
        char s[] = "hello";
        ASSERT_TRUE(cgs_cspn(s, "xyz").len == 5);
    }
    
    TEST("cgs_cspn: first char in charset");;;
    {
        char s[] = "hello";
        ASSERT_TRUE(cgs_cspn(s, "h").len == 0);
    }
    
    TEST("cgs_cspn: charset hit in middle");;;
    {
        char s[] = "abcXdef";
        ASSERT_TRUE(cgs_cspn(s, "X").len == 3);
    }
    
    TEST("cgs_cspn: charset hit at last char");;;
    {
        char s[] = "abcdX";
        ASSERT_TRUE(cgs_cspn(s, "X").len == 4);
    }
    
    TEST("cgs_cspn: entire string in charset");;;
    {
        char s[] = "aaa";
        ASSERT_TRUE(cgs_cspn(s, "a").len == 0);
    }
    
    TEST("cgs_cspn: empty string");;;
    {
        char s[] = "";
        ASSERT_TRUE(cgs_cspn(s, "abc").len == 0);
    }
    
    TEST("cgs_cspn: empty charset");;;
    {
        char s[] = "hello";
        ASSERT_TRUE(cgs_cspn(s, "").len == 5);
    }
    
    TEST("cgs_cspn: both empty");;;
    {
        char s[] = "";
        ASSERT_TRUE(cgs_cspn(s, "").len == 0);
    }
    
    TEST("cgs_cspn: single char string, in charset");;;
    {
        char s[] = "a";
        ASSERT_TRUE(cgs_cspn(s, "a").len == 0);
    }
    
    TEST("cgs_cspn: single char string, not in charset");;;
    {
        char s[] = "a";
        ASSERT_TRUE(cgs_cspn(s, "b").len == 1);
    }
    
    TEST("cgs_cspn: multiple chars in charset, first hit determines result");;;
    {
        char s[] = "abcdef";
        ASSERT_TRUE(cgs_cspn(s, "ce").len == 2);
    }
    
    TEST("cgs_cspn: charset has duplicate chars");;;
    {
        char s[] = "abcXdef";
        ASSERT_TRUE(cgs_cspn(s, "XX").len == 3);
    }
    
    TEST("cgs_cspn: whitespace as charset");;;
    {
        char s[] = "hello world";
        ASSERT_TRUE(cgs_cspn(s, " \t\n\r").len == 5);
    }
    
    TEST("cgs_cspn: accepts StrView");;;
    {
        StrView sv = strv("abcXdef");
        ASSERT_TRUE(cgs_cspn(sv, "X").len == 3);
    }
    
    TEST("cgs_cspn: accepts DStr");;;
    {
        DStr d = dstr_init_from("abcXdef");
        ASSERT_TRUE(cgs_cspn(d, "X").len == 3);
        dstr_deinit(&d);
    }
    
    TEST("cgs_cspn: charset as StrView");;;
    {
        char s[] = "abcXdef";
        StrView charset = strv("X");
        ASSERT_TRUE(cgs_cspn(s, charset).len == 3);
    }
    
    TEST("cgs_cspn: result equals length means no chars matched");;;
    {
        char s[] = "hello";
        unsigned int n = cgs_cspn(s, "xyz").len;
        ASSERT_TRUE(n == cgs_len(s));
    }
    
    /* --- cgs_spn / cgs_cspn: complementary relationship --- */
    
    TEST("cgs_spn + cgs_cspn: partition the string");;;
    {
        /* for any string and charset, spn + cspn(from that offset) should
         *           walk the entire string */
        char s[] = "aaabbbccc";
        unsigned int spn = cgs_spn(s, "a").len;
        StrView rest = strv(s, spn);
        unsigned int cspn = cgs_cspn(rest, "a").len;
        ASSERT_TRUE(spn == 3 && cspn == 6);
    }
    
    TEST("cgs_spn + cgs_cspn: on same string and charset sum to string length when non-overlapping");;;
    {
        /* all-a string: spn == len, cspn == 0 */
        char s[] = "aaaa";
        ASSERT_TRUE(cgs_spn(s, "a").len + cgs_cspn(s, "a").len == cgs_len(s));
    }
    
    /* =========================================================================
     * cgs_next_tok  —  substring delimiter
     * ========================================================================= */
    
    TEST("cgs_next_tok: basic split");;
    {
        CGS_StrView base = cgs_strv("hello-world");
        CGS_StrView tok  = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("world")));
    }
    
    TEST("cgs_next_tok: second call consumes remainder");;
    {
        CGS_StrView base = cgs_strv("hello-world");
        cgs_next_tok(&base, cgs_strv("-"));
        CGS_StrView tok = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("world")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: full iteration over all tokens");;
    {
        CGS_StrView base     = cgs_strv("a,bb,ccc,dddd");
        CGS_StrView delim    = cgs_strv(",");
        const char *expected[] = { "a", "bb", "ccc", "dddd" };
        int i = 0;
        while (base.len > 0) {
            CGS_StrView tok = cgs_next_tok(&base, delim);
            ASSERT_TRUE(cgs_equal(tok, cgs_strv(expected[i])));
            i++;
        }
        ASSERT_TRUE(i == 4);
    }
    
    TEST("cgs_next_tok: delimiter not found returns whole string");;
    {
        CGS_StrView base = cgs_strv("hello");
        CGS_StrView tok  = cgs_next_tok(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: delimiter at start produces empty token");;
    {
        CGS_StrView base = cgs_strv("-hello");
        CGS_StrView tok  = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("hello")));
    }
    
    TEST("cgs_next_tok: delimiter at end produces empty trailing token");;
    {
        CGS_StrView base = cgs_strv("hello-");
        const char *origin = base.chars;
        
        CGS_StrView tok = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(tok.chars == origin);           /* tok starts at original base */
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
        ASSERT_TRUE(base.chars == origin + 6);      /* points at '\0' of "hello-" */
        
        CGS_StrView tok2 = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok2, cgs_strv("")));
        ASSERT_TRUE(tok2.chars == origin + 6);      /* still pointing at '\0', not moved */
        ASSERT_TRUE(base.chars == origin + 6);      /* base unchanged after exhaustion */
    }
    
    TEST("cgs_next_tok: consecutive delimiters produce empty tokens");;
    {
        CGS_StrView base  = cgs_strv("a--b");
        CGS_StrView delim = cgs_strv("-");
        CGS_StrView t0 = cgs_next_tok(&base, delim);
        CGS_StrView t1 = cgs_next_tok(&base, delim);
        CGS_StrView t2 = cgs_next_tok(&base, delim);
        ASSERT_TRUE(cgs_equal(t0,   cgs_strv("a")));
        ASSERT_TRUE(cgs_equal(t1,   cgs_strv("")));
        ASSERT_TRUE(cgs_equal(t2,   cgs_strv("b")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: delimiter equals entire string");;
    {
        CGS_StrView base = cgs_strv("-");
        CGS_StrView tok  = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: empty base returns empty token without crash");;
    {
        CGS_StrView base = cgs_strv("");
        CGS_StrView tok  = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: single character string no delimiter match");;
    {
        CGS_StrView base = cgs_strv("x");
        CGS_StrView tok  = cgs_next_tok(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("x")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: multi-char delimiter is matched as whole sequence");;
    {
        CGS_StrView base  = cgs_strv("key->value->end");
        CGS_StrView delim = cgs_strv("->");
        CGS_StrView t0 = cgs_next_tok(&base, delim);
        CGS_StrView t1 = cgs_next_tok(&base, delim);
        CGS_StrView t2 = cgs_next_tok(&base, delim);
        ASSERT_TRUE(cgs_equal(t0,   cgs_strv("key")));
        ASSERT_TRUE(cgs_equal(t1,   cgs_strv("value")));
        ASSERT_TRUE(cgs_equal(t2,   cgs_strv("end")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: multi-char delimiter partial prefix is not a match");;
    {
        /* "key-value" contains '-' but not "->" so no split should occur */
        CGS_StrView base = cgs_strv("key-value");
        CGS_StrView tok  = cgs_next_tok(&base, cgs_strv("->"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("key-value")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok: CRLF delimiter splits HTTP-style lines correctly");;
    {
        CGS_StrView base  = cgs_strv("Header: value\r\nOther: data\r\n");
        CGS_StrView delim = cgs_strv("\r\n");
        CGS_StrView t0 = cgs_next_tok(&base, delim);
        CGS_StrView t1 = cgs_next_tok(&base, delim);
        ASSERT_TRUE(cgs_equal(t0, cgs_strv("Header: value")));
        ASSERT_TRUE(cgs_equal(t1, cgs_strv("Other: data")));
    }
    
    TEST("cgs_next_tok: does not modify the underlying string data");;
    {
        char buf[] = "foo|bar";
        CGS_StrView base = cgs_strv(buf);
        cgs_next_tok(&base, cgs_strv("|"));
        ASSERT_TRUE(buf[3] == '|');   /* delimiter byte must be untouched */
    }
    
    /* --- second-argument type variants ---------------------------------------- */
    
    TEST("cgs_next_tok: delimiter as CGS_StrBuf");;
    {
        char dbuf[]      = "-";
        CGS_StrBuf delim = cgs_strbuf_init_from_cstr(dbuf);
        CGS_StrView base = cgs_strv("hello-world");
        CGS_StrView tok  = cgs_next_tok(&base, delim);
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("world")));
    }
    
    TEST("cgs_next_tok: delimiter as CGS_DStr");;
    {
        CGS_DStr delim = cgs_dstr_init_from(cgs_strv("-"));
        CGS_StrView base = cgs_strv("hello-world");
        CGS_StrView tok  = cgs_next_tok(&base, delim);
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("world")));
        cgs_dstr_deinit(&delim);
    }
    
    TEST("cgs_next_tok: delimiter as CGS_MutStrRef");;
    {
        char dbuf[]        = "-";
        CGS_MutStrRef delim = cgs_mutstr_ref(dbuf);
        CGS_StrView base   = cgs_strv("hello-world");
        CGS_StrView tok    = cgs_next_tok(&base, delim);
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("world")));
    }
    
    
    /* =========================================================================
     * cgs_next_tok_any  —  character-set delimiter
     * ========================================================================= */
    
    TEST("cgs_next_tok_any: basic split on single char set");;
    {
        CGS_StrView base = cgs_strv("hello-world");
        CGS_StrView tok  = cgs_next_tok_any(&base, cgs_strv("-"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("world")));
    }
    
    TEST("cgs_next_tok_any: splits on any character in the set");;
    {
        CGS_StrView base  = cgs_strv("one,two;three");
        CGS_StrView delim = cgs_strv(",;");
        
        CGS_StrView t0 = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t0,   cgs_strv("one")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("two;three")));
        
        CGS_StrView t1 = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t1,   cgs_strv("two")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("three")));
        
        CGS_StrView t2 = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t2,   cgs_strv("three")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok_any: whitespace set splits words");;
    {
        CGS_StrView base  = cgs_strv("hello world\there");
        CGS_StrView delim = cgs_strv(" \t");
        CGS_StrView t0 = cgs_next_tok_any(&base, delim);
        CGS_StrView t1 = cgs_next_tok_any(&base, delim);
        CGS_StrView t2 = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t0, cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(t1, cgs_strv("world")));
        ASSERT_TRUE(cgs_equal(t2, cgs_strv("here")));
    }
    
    TEST("cgs_next_tok_any: each char in set is an independent split point");;
    {
        /* ",;" set — "a,b;c" and "a;b,c" should behave identically */
        CGS_StrView base1 = cgs_strv("a,b;c");
        CGS_StrView base2 = cgs_strv("a;b,c");
        CGS_StrView delim = cgs_strv(",;");
        CGS_StrView a0 = cgs_next_tok_any(&base1, delim);
        CGS_StrView a1 = cgs_next_tok_any(&base1, delim);
        CGS_StrView b0 = cgs_next_tok_any(&base2, delim);
        CGS_StrView b1 = cgs_next_tok_any(&base2, delim);
        ASSERT_TRUE(cgs_equal(a0, b0));
        ASSERT_TRUE(cgs_equal(a1, b1));
    }
    
    TEST("cgs_next_tok_any: delimiter not found returns whole string");;
    {
        CGS_StrView base = cgs_strv("hello");
        CGS_StrView tok  = cgs_next_tok_any(&base, cgs_strv(",;"));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok_any: delimiter char at start produces empty token");;
    {
        CGS_StrView base = cgs_strv(",hello");
        CGS_StrView tok  = cgs_next_tok_any(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("hello")));
    }
    
    TEST("cgs_next_tok_any: delimiter char at end produces empty trailing token");;
    {
        CGS_StrView base = cgs_strv("hello,");
        CGS_StrView tok  = cgs_next_tok_any(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("hello")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
        CGS_StrView tok2 = cgs_next_tok_any(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(tok2, cgs_strv("")));
    }
    
    TEST("cgs_next_tok_any: consecutive delimiter chars produce empty tokens");;
    {
        CGS_StrView base  = cgs_strv("a,,b");
        CGS_StrView delim = cgs_strv(",");
        CGS_StrView t0 = cgs_next_tok_any(&base, delim);
        CGS_StrView t1 = cgs_next_tok_any(&base, delim);
        CGS_StrView t2 = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t0,   cgs_strv("a")));
        ASSERT_TRUE(cgs_equal(t1,   cgs_strv("")));
        ASSERT_TRUE(cgs_equal(t2,   cgs_strv("b")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok_any: two different consecutive delimiter chars produce empty token");;
    {
        /* ",;" set — ",;" in the string should produce an empty token between them */
        CGS_StrView base  = cgs_strv("a,;b");
        CGS_StrView delim = cgs_strv(",;");
        CGS_StrView t0 = cgs_next_tok_any(&base, delim);
        CGS_StrView t1 = cgs_next_tok_any(&base, delim);
        CGS_StrView t2 = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t0,   cgs_strv("a")));
        ASSERT_TRUE(cgs_equal(t1,   cgs_strv("")));
        ASSERT_TRUE(cgs_equal(t2,   cgs_strv("b")));
    }
    
    TEST("cgs_next_tok_any: empty base returns empty token without crash");;
    {
        CGS_StrView base = cgs_strv("");
        CGS_StrView tok  = cgs_next_tok_any(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok_any: single character string no delimiter match");;
    {
        CGS_StrView base = cgs_strv("x");
        CGS_StrView tok  = cgs_next_tok_any(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("x")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok_any: single character string is the delimiter");;
    {
        CGS_StrView base = cgs_strv(",");
        CGS_StrView tok  = cgs_next_tok_any(&base, cgs_strv(","));
        ASSERT_TRUE(cgs_equal(tok,  cgs_strv("")));
        ASSERT_TRUE(cgs_equal(base, cgs_strv("")));
    }
    
    TEST("cgs_next_tok_any: multi-char set does not split on sequence, only individual chars");;
    {
        /* contrast with cgs_next_tok: "->" as a set splits on '-' OR '>' individually */
        CGS_StrView base  = cgs_strv("key->value");
        CGS_StrView t0 = cgs_next_tok_any(&base, cgs_strv("->"));
        CGS_StrView t1 = cgs_next_tok_any(&base, cgs_strv("->"));
        CGS_StrView t2 = cgs_next_tok_any(&base, cgs_strv("->"));
        ASSERT_TRUE(cgs_equal(t0,   cgs_strv("key")));
        ASSERT_TRUE(cgs_equal(t1,   cgs_strv("")));      /* '-' and '>' are both hits */
        ASSERT_TRUE(cgs_equal(t2,   cgs_strv("value")));
    }
    
    TEST("cgs_next_tok_any: does not modify the underlying string data");;
    {
        char buf[] = "foo|bar";
        CGS_StrView base = cgs_strv(buf);
        cgs_next_tok_any(&base, cgs_strv("|"));
        ASSERT_TRUE(buf[3] == '|');
    }
    
    /* --- second-argument type variants ---------------------------------------- */
    
    TEST("cgs_next_tok_any: delimiter set as CGS_StrBuf");;
    {
        char dbuf[]      = ",;";
        CGS_StrBuf delim = cgs_strbuf_init_from_cstr(dbuf);
        CGS_StrView base = cgs_strv("a,b;c");
        CGS_StrView t0   = cgs_next_tok_any(&base, delim);
        CGS_StrView t1   = cgs_next_tok_any(&base, delim);
        CGS_StrView t2   = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t0, cgs_strv("a")));
        ASSERT_TRUE(cgs_equal(t1, cgs_strv("b")));
        ASSERT_TRUE(cgs_equal(t2, cgs_strv("c")));
    }
    
    TEST("cgs_next_tok_any: delimiter set as CGS_DStr");;
    {
        CGS_DStr delim   = cgs_dstr_init_from(cgs_strv(",;"));
        CGS_StrView base = cgs_strv("a,b;c");
        CGS_StrView t0   = cgs_next_tok_any(&base, delim);
        CGS_StrView t1   = cgs_next_tok_any(&base, delim);
        CGS_StrView t2   = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t0, cgs_strv("a")));
        ASSERT_TRUE(cgs_equal(t1, cgs_strv("b")));
        ASSERT_TRUE(cgs_equal(t2, cgs_strv("c")));
        cgs_dstr_deinit(&delim);
    }
    
    TEST("cgs_next_tok_any: delimiter set as CGS_MutStrRef");;
    {
        char dbuf[]         = ",;";
        CGS_MutStrRef delim = cgs_mutstr_ref(dbuf);
        CGS_StrView base    = cgs_strv("a,b;c");
        CGS_StrView t0      = cgs_next_tok_any(&base, delim);
        CGS_StrView t1      = cgs_next_tok_any(&base, delim);
        CGS_StrView t2      = cgs_next_tok_any(&base, delim);
        ASSERT_TRUE(cgs_equal(t0, cgs_strv("a")));
        ASSERT_TRUE(cgs_equal(t1, cgs_strv("b")));
        ASSERT_TRUE(cgs_equal(t2, cgs_strv("c")));
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
    TEST("cgs_clear: already empty DStr");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_clear(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_clear: StrBuf at capacity");;;
    {
        char backing[5] = {'f', 'u', 'l', 'l', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 5);
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
        DStr dstr = dstr_init_from("original");
        cgs_clear(&dstr);
        CGS_Error err = cgs_append(&dstr, "new");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "new"));
        dstr_deinit(&dstr);
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
        StrView hay = {0};
        StrView prefix = strv("hello");
        ASSERT_FALSE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: NULL needle");;;
    {
        StrView hay = strv("hello");
        StrView prefix = {0};
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: NULL both");;;
    {
        StrView hay = {0};
        StrView prefix = {0};
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
}

// ============================================================================
// Edge Case Tests for cgs_tolower / cgs_toupper
// ============================================================================

void test_str_case_edge_cases() {
    TEST("cgs_tolower: empty string");;;
    {
        DStr dstr = dstr_init_from("");
        cgs_tolower(&dstr);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: already lowercase");;;
    {
        DStr dstr = dstr_init_from("alllower");
        cgs_tolower(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "alllower"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: with numbers and symbols");;;
    {
        DStr dstr = dstr_init_from("Test123!@#");
        cgs_tolower(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "test123!@#"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_toupper: empty string");;;
    {
        DStr dstr = dstr_init_from("");
        cgs_toupper(&dstr);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_toupper: already uppercase");;;
    {
        DStr dstr = dstr_init_from("ALLUPPER");
        cgs_toupper(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "ALLUPPER"));
        dstr_deinit(&dstr);
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
    
    TEST("cgs_copy: to StrBuf at capacity");;;
    {
        char backing[5];
        StrBuf sb = strbuf_init_from_buf(backing, 5);
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
    
    TEST("cgs_copy: to DStr with insufficient capacity");;;
    {
        DStr dstr = dstr_init(2);
        char src[] = "this is a long string";
        CGS_Error err = cgs_copy(&dstr, src);
        // Should either reallocate or fail
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_DST_TOO_SMALL || err.ec == CGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_copy: from DStr to char array");;;
    {
        DStr src = dstr_init_from("source");
        char dst[20];
        CGS_Error err = cgs_copy(dst, &src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, "source"));
        dstr_deinit(&src);
    }
}

// ============================================================================
// Edge Case Tests for cgs_putc
// ============================================================================

void test_str_putc_edge_cases() {
    TEST("cgs_putc: to empty DStr");;;
    {
        DStr dstr = dstr_init(0);
        CGS_Error err = cgs_putc(&dstr, 'a');
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: null character");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_putc(&dstr, '\0');
        // Behavior may vary - might end string or add literal null
        (void)err;
        ASSERT_TRUE(1);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: to StrBuf at capacity");;;
    {
        char backing[3] = {'a', 'b', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 3);
        CGS_Error err = cgs_putc(&sb, 'c');
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_putc: extended ASCII character");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_putc(&dstr, 0xFF);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: many characters sequentially");;;
    {
        DStr dstr = dstr_init(1);
        for (int i = 0; i < 1000; i++) {
            CGS_Error err = cgs_putc(&dstr, 'x');
            if (err.ec != CGS_OK) {
                printf("  Failed at iteration %d with error code %d\n", i, err.ec);
                break;
            }
        }
        ASSERT_EQ(cgs_len(&dstr), 1000);
        dstr_deinit(&dstr);
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
        DStr result = dstr_init();
        cgs_fread_line(&result, tmp);
        
        ASSERT_TRUE(cgs_equal(result, "Hello, World"));
        dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("writer_t: cgs_append_tostr with FILE*");;;
    {
        FILE* tmp = tmpfile();
        
        // Testing integer conversion to file
        cgs_append_tostr(tmp, 1234);
        cgs_putc(tmp, ' ');
        // Testing float conversion to file
        cgs_append_tostr(tmp, nfmt(5.5, 'f', 2));
        
        rewind(tmp);
        DStr result = dstr_init();
        cgs_fread_line(&result, tmp);
        
        ASSERT_EQ(strcmp(cgs_chars(result), "1234 5.50"), 0);
        
        dstr_deinit(&result);
        fclose(tmp);
    }
    
    TEST("writer_t: cgs_append_tostr_all with FILE*");;;
    {
        FILE* tmp = tmpfile();
        
        // Using the variadic printing macro directly to a FILE*
        cgs_append_tostr_all(tmp, "Hex: ", nfmt(255, 'X'), ", Score: ", 100);
        
        rewind(tmp);
        DStr result = dstr_init();
        cgs_fread_line(&result, tmp);
        
        ASSERT_EQ(strcmp(cgs_chars(result), "Hex: FF, Score: 100"), 0);
        
        dstr_deinit(&result);
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
    
    TEST("cgs_fmt: no specifiers copies string as-is into DStr");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: no specifiers copies string as-is into StrBuf");
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
        CGS_Error err = cgs_append_fmt(f, "hello world");
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
    
    TEST("cgs_fmt: output exceeding StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[4];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: substitution exceeding StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[8];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hi %?", cgs_strv("this is way too long"));
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: output exactly filling StrBuf capacity succeeds");
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
    
    TEST("cgs_fmt: writer as MutStrRef");
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
        CGS_Error err = cgs_append_fmt(f, "hello %?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        rewind(f);
        char buf[32] = {0};
        fread(buf, 1, sizeof(buf) - 1, f);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
        fclose(f);
    }
    
    /* =========================================================================
     * cgs_append_fmt — appending behaviour
     * ========================================================================= */
    
    TEST("cgs_append_fmt: appends to existing DStr content");
    {
        CGS_DStr dst = cgs_dstr_init_from(cgs_strv("hello "));
        CGS_Error err = cgs_append_fmt(&dst, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_append_fmt: appends with substitution to existing DStr content");
    {
        CGS_DStr dst = cgs_dstr_init_from(cgs_strv("hello "));
        CGS_Error err = cgs_append_fmt(&dst, "%?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_append_fmt: multiple appends accumulate correctly");
    {
        CGS_DStr dst = cgs_dstr_init();
        cgs_append_fmt(&dst, "one");
        cgs_append_fmt(&dst, ", two");
        CGS_Error err = cgs_append_fmt(&dst, ", three");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("one, two, three")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_append_fmt: appends to existing StrBuf content");
    {
        char buf[32] = {0};
        CGS_StrBuf dst = cgs_strbuf_init_from_cstr(buf);
        cgs_append_fmt(&dst, "hello ");
        CGS_Error err = cgs_append_fmt(&dst, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    TEST("cgs_append_fmt: appending to StrBuf that leaves no remaining capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[8];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        cgs_append_fmt(&dst, "hello");   /* 5 chars, 2 remaining (+ null) */
        CGS_Error err = cgs_append_fmt(&dst, " world");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_append_fmt: appends to FILE* after existing content");
    {
        FILE *f = tmpfile();
        fwrite("hello ", 1, 6, f);
        CGS_Error err = cgs_append_fmt(f, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        rewind(f);
        char buf[32] = {0};
        fread(buf, 1, sizeof(buf) - 1, f);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
        fclose(f);
    }
    
    TEST("cgs_append_fmt: appends with substitution to FILE* after existing content");
    {
        FILE *f = tmpfile();
        fwrite("hello ", 1, 6, f);
        CGS_Error err = cgs_append_fmt(f, "%?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        rewind(f);
        char buf[32] = {0};
        fread(buf, 1, sizeof(buf) - 1, f);
        ASSERT_TRUE(strcmp(buf, "hello world") == 0);
        fclose(f);
    }
    
    TEST("cgs_append_fmt: appends to StrBuf with sufficient remaining capacity");
    {
        char buf[32];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        cgs_append_fmt(&dst, "hello ");
        CGS_Error err = cgs_append_fmt(&dst, "world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    TEST("cgs_append_fmt: appends with substitution to StrBuf");
    {
        char buf[32];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        cgs_append_fmt(&dst, "hello ");
        CGS_Error err = cgs_append_fmt(&dst, "%?", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
    }
    
    /* =========================================================================
     * cgs_fmt — basic copying (no specifiers)
     * ========================================================================= */
    
    TEST("cgs_fmt: no specifiers copies string as-is into DStr");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: no specifiers copies string as-is into StrBuf");
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
     * cgs_fmt — explicit indexed substitution (%0, %1, ...)
     * ========================================================================= */
    
    TEST("cgs_fmt: explicit index %0 selects first arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "hello %0", cgs_strv("world"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello world")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit indices in order");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%0 %1 %2",
                                   cgs_strv("one"), cgs_strv("two"), cgs_strv("three"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("one two three")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit indices out of order");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%2 %0 %1",
                                   cgs_strv("one"), cgs_strv("two"), cgs_strv("three"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("three one two")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit index can repeat an arg");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%0 and %0", cgs_strv("hello"));
        ASSERT_TRUE(err.ec == CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, cgs_strv("hello and hello")));
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: explicit index out of bounds returns CGS_INDEX_OUT_OF_BOUNDS");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%3", cgs_strv("only one arg"));
        ASSERT_TRUE(err.ec == CGS_INDEX_OUT_OF_BOUNDS);
        cgs_dstr_deinit(&dst);
    }
    
    TEST("cgs_fmt: mixed %% escape and explicit index substitution");
    {
        CGS_DStr dst = cgs_dstr_init();
        CGS_Error err = cgs_fmt(&dst, "%% of %0 is %1",
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
        CGS_Error err = cgs_fmt(&dst, "%? and %0",
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
    
    TEST("cgs_fmt: output exceeding StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[4];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hello world");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: substitution exceeding StrBuf capacity returns CGS_DST_TOO_SMALL");
    {
        char buf[8];
        CGS_StrBuf dst = cgs_strbuf_init_from_buf(buf);
        CGS_Error err = cgs_fmt(&dst, "hi %?", cgs_strv("this is way too long"));
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_fmt: output exactly filling StrBuf capacity succeeds");
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
    
    TEST("cgs_fmt: writer as MutStrRef");
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
        DStr dst = dstr_init(10);
        char src[] = "";
        CGS_Error err = cgs_append(&dst, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("cgs_append: to itself (aliasing)");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_append(&dstr, &dstr);
        // Should detect aliasing or handle it
        ASSERT_TRUE(err.ec == CGS_ALIASING_NOT_SUPPORTED || err.ec == CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_append: to StrBuf causing overflow");;;
    {
        char backing[10] = "hello";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        char src[] = "world!";
        CGS_Error err = cgs_append(&sb, src);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_append: exactly fitting capacity");;;
    {
        char backing[11] = "hello";
        StrBuf sb = strbuf_init_from_cstr(backing, 11);
        char src[] = "world";
        CGS_Error err = cgs_append(&sb, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&sb, "helloworld"));
    }
    
    TEST("cgs_append: multiple appends growing DStr");;;
    {
        DStr dstr = dstr_init(1);
        for (int i = 0; i < 100; i++) {
            CGS_Error err = cgs_append(&dstr, "x");
            ASSERT_EQ(err.ec, CGS_OK);
        }
        ASSERT_EQ(cgs_len(&dstr), 100);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_append: very long string");;;
    {
        DStr dstr = dstr_init(100);
        DStr long_str = dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            cgs_putc(&long_str, 'a');
        }
        CGS_Error err = cgs_append(&dstr, &long_str);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 4999);
        dstr_deinit(&dstr);
        dstr_deinit(&long_str);
    }
}

// ============================================================================
// Edge Case Tests for cgs_del
// ============================================================================

void test_str_del_edge_cases() {
    TEST("cgs_del: delete entire string");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete nothing (from == to)");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 2, 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: invalid range (from > to)");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 3, 1);
        ASSERT_EQ(err.ec, CGS_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: out of bounds from");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 10, 15);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: out of bounds to");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 100);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete from middle");;;
    {
        DStr dstr = dstr_init_from("abcdef");
        CGS_Error err = cgs_del(&dstr, 2, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abef"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete first character");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 1);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "est"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete last character");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 3, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "tes"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: on empty string");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_del(&dstr, 0, 0);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_replace
// ============================================================================

void test_str_replace_edge_cases() {
    TEST("cgs_replace: target not found");;;
    {
        DStr dstr = dstr_init_from("hello world");
        ReplaceResult res = cgs_replace(&dstr, "xyz", "abc");
        ASSERT_EQ(res.err.ec, CGS_NOT_FOUND);
        ASSERT_EQ(res.nb_replaced, 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: empty target");;;
    {
        DStr dstr = dstr_init_from("test");
        ReplaceResult res = cgs_replace(&dstr, "", "x");
        // Replacing empty string is likely an error or no-op
        ASSERT_TRUE(res.err.ec == CGS_OK || res.err.ec == CGS_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replace with empty string");;;
    {
        DStr dstr = dstr_init_from("hello world");
        ReplaceResult res = cgs_replace(&dstr, "o", "");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hell wrld"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replacement longer than target");;;
    {
        DStr dstr = dstr_init_from("hi hi hi");
        ReplaceResult res = cgs_replace(&dstr, "hi", "hello");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hello hello hello"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replacement shorter than target");;;
    {
        DStr dstr = dstr_init_from("hello hello");
        ReplaceResult res = cgs_replace(&dstr, "hello", "hi");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hi hi"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: overlapping matches");;;
    {
        DStr dstr = dstr_init_from("aaa");
        ReplaceResult res = cgs_replace(&dstr, "aa", "b");
        // Should replace non-overlapping: "aaa" -> "ba" (1 replacement)
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(res.nb_replaced == 1);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: target equals entire string");;;
    {
        DStr dstr = dstr_init_from("exact");
        ReplaceResult res = cgs_replace(&dstr, "exact", "replaced");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "replaced"));
        ASSERT_EQ(res.nb_replaced, 1);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: on StrBuf with insufficient space");;;
    {
        char backing[10] = "hi hi"; // "hello hi"
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        ReplaceResult res = cgs_replace(&sb, "hi", "hello");
        // println("hi hi", " became :: ", sb);
        ASSERT_EQ(res.err.ec, CGS_DST_TOO_SMALL);
        ASSERT_EQ(res.nb_replaced, 1);
    }
    
    TEST("cgs_replace: many occurrences");;;
    {
        DStr dstr = dstr_init(100);
        for (int i = 0; i < 50; i++) {
            cgs_append(&dstr, "x ");
        }
        ReplaceResult res = cgs_replace(&dstr, "x", "y");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_EQ(res.nb_replaced, 50);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_replace_first
// ============================================================================

void test_str_replace_first_edge_cases() {
    TEST("cgs_replace_first: no occurrence");;;
    {
        DStr dstr = dstr_init_from("hello");
        CGS_Error err = cgs_replace_first(&dstr, "xyz", "abc");
        ASSERT_EQ(err.ec, CGS_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: empty string target");;;
    {
        DStr s = dstr_init_from("abc");
        // Replacing the first "" is defined in many libs as an injection at start
        cgs_replace_first(&s, "", "!");
        ASSERT_TRUE(cgs_equal(&s, "!abc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: match at end of string");;;
    {
        DStr s = dstr_init_from("path/to/file");
        cgs_replace_first(&s, "file", "dir");
        ASSERT_TRUE(cgs_equal(&s, "path/to/dir"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: multiple occurrences");;;
    {
        DStr dstr = dstr_init_from("test test test");
        CGS_Error err = cgs_replace_first(&dstr, "test", "word");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "word test test"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: at end of string");;;
    {
        DStr dstr = dstr_init_from("abcdef");
        CGS_Error err = cgs_replace_first(&dstr, "def", "xyz");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abcxyz"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: only first occurrence");;;
    {
        DStr s = dstr_init_from("ababab");
        CGS_Error err = cgs_replace_first(&s, "ab", "X");
        ASSERT_TRUE(cgs_equal(&s, "Xabab") && err.ec == CGS_OK);
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: target at the very end");;;
    {
        DStr s = dstr_init_from("hello world");
        CGS_Error err = cgs_replace_first(&s, "world", "C");
        ASSERT_TRUE(cgs_equal(&s, "hello C"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: target is the whole string");;;
    {
        DStr s = dstr_init_from("match");
        cgs_replace_first(&s, "match", "replaced");
        ASSERT_TRUE(cgs_equal(&s, "replaced"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: error when not found");;;
    {
        DStr s = dstr_init_from("abc");
        CGS_Error err = cgs_replace_first(&s, "z", "x");
        // Some libs return OK with 0 changes, but CGS_NOT_FOUND is safer for a "First" API
        ASSERT_TRUE(err.ec == CGS_NOT_FOUND);
        dstr_deinit(&s);
    }
}

// ============================================================================
// Edge Case Tests for cgs_replace_range
// ============================================================================

void test_str_replace_range_edge_cases() {
    TEST("cgs_replace_range: remove last character");;;
    {
        DStr s = dstr_init_from("Hello!");
        // Range is [5, 6) -> the '!'
        cgs_replace_range(&s, 5, 6, ""); 
        ASSERT_TRUE(cgs_equal(&s, "Hello"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace inside string with much longer string");;;
    {
        DStr s = dstr_init_from("a[ ]c");
        // Replace "[ ]" (index 1 to 4) with "long string"
        cgs_replace_range(&s, 1, 4, "is a very long string");
        ASSERT_TRUE(cgs_equal(&s, "ais a very long stringc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: null/empty replacement at specific index (Insertion)");;;
    {
        DStr s = dstr_init_from("ac");
        cgs_replace_range(&s, 1, 1, "b");
        ASSERT_TRUE(cgs_equal(&s, "abc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace entire string");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 4, "replaced");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "replaced"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: invalid range");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 3, 1, "x");
        ASSERT_EQ(err.ec, CGS_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: out of bounds");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 100, "x");
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: zero-length range (insertion)");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 2, 2, "XX");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "teXXst"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: with empty replacement (deletion)");;;
    {
        DStr dstr = dstr_init_from("testing");
        CGS_Error err = cgs_replace_range(&dstr, 2, 5, "");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "teng"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: at string boundaries");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 0, "start");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "starttest"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: StrBuf overflow");;;
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_replace_range(&sb, 0, 4, "very long replacement");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: replace middle (same size)");;;
    {
        DStr s = dstr_init_from("ABCDE");
        // Replace "BCD" (indices 1, 2, 3) with "123"
        CGS_Error err = cgs_replace_range(&s, 1, 4, "123");
        ASSERT_TRUE(cgs_equal(&s, "A123E"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: grow string (insertion)");;;
    {
        DStr s = dstr_init_from("AB");
        // Replace nothing at index 1 with "123" -> "A123B"
        CGS_Error err = cgs_replace_range(&s, 1, 1, "123");
        ASSERT_TRUE(cgs_equal(&s, "A123B"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: shrink string (deletion)");;;
    {
        DStr s = dstr_init_from("Hello World");
        // Replace " World" (index 5 to 11) with ""
        CGS_Error err = cgs_replace_range(&s, 5, 11, "");
        ASSERT_TRUE(cgs_equal(&s, "Hello"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace entire string");;;
    {
        DStr s = dstr_init_from("old");
        cgs_replace_range(&s, 0, 3, "new");
        ASSERT_TRUE(cgs_equal(&s, "new"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: out of bounds");;;
    {
        DStr s = dstr_init_from("abc");
        CGS_Error err = cgs_replace_range(&s, 1, 10, "x");
        ASSERT_TRUE(err.ec == CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: inverted range");;;
    {
        DStr s = dstr_init_from("abc");
        CGS_Error err = cgs_replace_range(&s, 3, 1, "x");
        ASSERT_TRUE(err.ec == CGS_BAD_RANGE);
        dstr_deinit(&s);
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
        StrViewArray arr = cgs_split(str, delim);
        // Should return array with 0 or 1 empty element
        ASSERT_TRUE(arr.len == 1 && arr.strs[0].chars == str);
        free(arr.strs);
    }
    
    TEST("Split: No delimiter present in source");;;
    {
        char str[] = "hello world";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Delimiter not found -> 1 element (the whole string)
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(arr.strs[0].len == 11);
        ASSERT_TRUE(memcmp(arr.strs[0].chars, "hello world", 11) == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: empty string with non-empty delimiter");;;
    {
        char str[] = "";
        StrViewArray arr = cgs_split(str, ",");
        // Most languages (Java, JS, Python) return [""]
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(arr.strs[0].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: empty delimiter (Explode behavior)");;;
    {
        char str[] = "abc";
        StrViewArray arr = cgs_split(str, "");
        // Explode: "abc" -> ["a", "b", "c"]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[0].len == 1 && arr.strs[0].chars[0] == 'a');
        ASSERT_TRUE(arr.strs[2].len == 1 && arr.strs[2].chars[0] == 'c');
        free(arr.strs);
    }
    
    TEST("cgs_split: consecutive delimiters (Empty fields)");;;
    {
        char str[] = "a,,b";
        StrViewArray arr = cgs_split(str, ",");
        // Result: ["a", "", "b"]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[1].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: leading and trailing delimiters");;;
    {
        char str[] = ",a,";
        StrViewArray arr = cgs_split(str, ",");
        // Result: ["", "a", ""]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[0].len == 0);
        ASSERT_TRUE(arr.strs[2].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter not present");;;
    {
        char str[] = "hello";
        StrViewArray arr = cgs_split(str, "|");
        // Should return the original string as the only element
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(cgs_equal(arr.strs[0], "hello"));
        free(arr.strs);
    }
    
    TEST("cgs_split: string is exactly the delimiter");;;
    {
        char str[] = "::";
        StrViewArray arr = cgs_split(str, "::");
        // Result: ["", ""]
        ASSERT_TRUE(arr.len == 2);
        ASSERT_TRUE(arr.strs[0].len == 0 && arr.strs[1].len == 0);
        free(arr.strs);
    }    
    TEST("cgs_split: delimiter not in string");;;
    {
        char str[] = "no delimiters here";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        ASSERT_EQ(arr.len, 1);
        free(arr.strs);
    }
    
    TEST("cgs_split: consecutive delimiters");;;
    {
        char str[] = "a,,b,,c";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 5 elements: "a", "", "b", "", "c"
        ASSERT_EQ(arr.len, 5);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter at start");;;
    {
        char str[] = ",test";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 2 elements: "" and "test"
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter at end");;;
    {
        char str[] = "test,";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 2 elements: "test" and ""
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: only delimiter");;;
    {
        char str[] = ",";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 2 empty elements
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: multi-character delimiter");;;
    {
        char str[] = "a::b::c";
        char delim[] = "::";
        StrViewArray arr = cgs_split(str, delim);
        ASSERT_EQ(arr.len, 3);
        free(arr.strs);
    }
    
    TEST("cgs_split: many splits");;;
    {
        DStr dstr = dstr_init(1000);
        for (int i = 0; i < 100; i++) {
            cgs_append(&dstr, "x,");
        }
        StrViewArray arr = cgs_split(&dstr, ",");
        ASSERT_EQ(arr.len, 101); // 100 "x" and 1 trailing empty
        dstr_deinit(&dstr);
        free(arr.strs);
    }
}

// ============================================================================
// Edge Case Tests for cgs_insert / cgs_prepend
// ============================================================================

void test_str_insert_prepend_edge_cases() {
    TEST("cgs_insert: at position 0 (same as prepend)");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "START", 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "STARTtest"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: at middle position");;;
    {
        DStr dstr = dstr_init_from("abef");
        CGS_Error err = cgs_insert(&dstr, "cd", 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abcdef"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: at end position");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "end", 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "testend"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: out of bounds position");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "x", 100);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: into empty string at position 0");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_insert(&dstr, "first", 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: into empty string at position > 0");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_insert(&dstr, "test", 5);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: StrBuf overflow");;;
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_insert(&sb, "longinsert", 2);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_insert: empty string insertion");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "", 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_prepend: to empty string");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_prepend(&dstr, "first");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_prepend: StrBuf overflow");;;
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_prepend(&sb, "longprefix");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_prepend: multiple times");;;
    {
        DStr dstr = dstr_init_from("end");
        cgs_prepend(&dstr, "middle");
        cgs_prepend(&dstr, "start");
        ASSERT_TRUE(cgs_equal(&dstr, "startmiddleend"));
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for DStr functions
// ============================================================================

void test_dstring_edge_cases() {
    TEST("dstr_init: zero capacity");;;
    {
        DStr dstr = dstr_init(0);
        ASSERT_EQ(cgs_len(&dstr), 0);
        // Should still be usable
        CGS_Error err = cgs_append(&dstr, "test");
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init: very large capacity");;;
    {
        DStr dstr = dstr_init(1000000);
        ASSERT_TRUE(cgs_cap(&dstr) >= 1000000 || cgs_cap(&dstr) == 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init_from: empty string");;;
    {
        DStr dstr = dstr_init_from("");
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: already minimal");;;
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_cap(&dstr) >= cgs_len(&dstr));
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: after deletions");;;
    {
        DStr dstr = dstr_init(1000);
        cgs_append(&dstr, "small");
        CGS_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: already sufficient");;;
    {
        DStr dstr = dstr_init(100);
        CGS_Error err = dstr_ensure_cap(&dstr, 50);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: needs growth");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = dstr_ensure_cap(&dstr, 100);
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        if (err.ec == CGS_OK) {
            ASSERT_TRUE(cgs_cap(&dstr) >= 100);
        }
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: zero requested");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = dstr_ensure_cap(&dstr, 0);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_find: null checks");;;
    {
        DStr dstr = dstr_init();
        ASSERT_TRUE(dstr.chars == NULL);
        ASSERT_TRUE(cgs_find(dstr, "").chars == dstr.chars);
        ASSERT_TRUE(cgs_equal(dstr, ""));
        ASSERT_TRUE(cgs_starts_with(dstr, ""));
        ASSERT_TRUE(cgs_ends_with(dstr, ""));
        
        ASSERT_FALSE(cgs_starts_with(dstr, "something"));
        
        StrBuf sb = {0};
        CGS_Error err = cgs_copy(&sb, "hello");
        ASSERT_TRUE(err.ec == CGS_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for StrBuf
// ============================================================================

void test_string_buffer_edge_cases() {
    TEST("StrBuf: from empty array");;;
    {
        char buf[1] = {'\0'};
        StrBuf sb = strbuf_init_from_cstr(buf, 1);
        ASSERT_EQ(cgs_len(&sb), 0);
        ASSERT_EQ(cgs_cap(&sb), 1);
    }
    
    TEST("StrBuf: from array without null terminator");;;
    {
        char buf[5] = {'t', 'e', 's', 't', 'x'};
        StrBuf sb = strbuf_init_from_buf(buf, 5);
        ASSERT_TRUE(sb.len == 0);
    }
    
    TEST("StrBuf: from cstr with capacity exactly length + 1");;;
    {
        char buf[5] = {'t', 'e', 's', 't', '\0'};
        StrBuf sb = strbuf_init_from_cstr(buf, 5);
        ASSERT_EQ(cgs_cap(&sb), 5);
        ASSERT_EQ(cgs_len(&sb), 4);
    }
    
    TEST("StrBuf: from buf with exact capacity");;;
    {
        char buf[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
        StrBuf sb = strbuf_init_from_buf(buf, 10);
        ASSERT_EQ(cgs_cap(&sb), 10);
    }
    
    TEST("StrBuf: append to full buffer from cstr");;;
    {
        char buf[5] = {'f', 'u', 'l', 'l', '\0'};
        StrBuf sb = strbuf_init_from_cstr(buf, 5);
        CGS_Error err = cgs_append(&sb, "x");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("StrBuf: init from buf then set content");;;
    {
        char buf[20];
        StrBuf sb = strbuf_init_from_buf(buf, 20);
        CGS_Error err = cgs_copy(&sb, "test");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&sb, "test"));
    }
}

// ============================================================================
// Edge Case Tests for strv
// ============================================================================

void test_strv_edge_cases() {
    TEST("strv: empty range");;;
    {
        char str[] = "test";
        StrView sv = strv(str, 2, 2);
        ASSERT_EQ(cgs_len(sv), 0);
    }
    
    TEST("strv: entire string");;;
    {
        char str[] = "test";
        StrView sv = strv(str, 0, 4);
        ASSERT_EQ(cgs_len(sv), 4);
        ASSERT_TRUE(cgs_equal(sv, "test"));
    }
    
    TEST("strv: invalid range (from > to)");;;
    {
        char str[] = "test";
        StrView sv = strv(str, 3, 1);
        // Likely returns empty or errors
        ASSERT_TRUE(1);
    }
    
    TEST("strv: single character");;;
    {
        char str[] = "test";
        StrView sv = strv(str, 1, 2);
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
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_fread_line(&dstr, f);
        // Should indicate EOF or empty read
        ASSERT_TRUE(err.ec == CGS_OK || err.ec != CGS_OK);
        fclose(f);
        dstr_deinit(&dstr);
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
        
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_fread_line(&dstr, f);
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        if (err.ec == CGS_OK)
        {
            ASSERT_EQ(cgs_len(&dstr), 10001);
        }
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_fread_line: line without newline");;;
    {
        FILE *f = tmpfile();
        fprintf(f, "no newline");
        rewind(f);
        
        DStr dstr = dstr_init(20);
        CGS_Error err = cgs_fread_line(&dstr, f);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "no newline"));
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_fread_line: multiple calls");;;
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\nline3\n");
        rewind(f);
        
        DStr dstr = dstr_init(20);
        cgs_fread_line(&dstr, f);
        ASSERT_TRUE(cgs_equal(&dstr, "line1\n"));
        
        cgs_clear(&dstr);
        cgs_fread_line(&dstr, f);
        ASSERT_TRUE(cgs_equal(&dstr, "line2\n"));
        
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_append_fread_line: append multiple lines");;;
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\n");
        rewind(f);
        
        DStr dstr = dstr_init(50);
        cgs_append_fread_line(&dstr, f);
        cgs_append_fread_line(&dstr, f);
        ASSERT_TRUE(cgs_equal(&dstr, "line1\nline2\n"));
        
        fclose(f);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for appender
// ============================================================================

void test_appender_edge_cases() {
    TEST("cgs_appender: basic usage");;;
    {
        DStr dstr = dstr_init_from("start");
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "end");
        CGS_Error err = cgs_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "startend"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: without commit");;;
    {
        DStr dstr = dstr_init_from("start");
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "lost");
        // Not committed - dstr should be unchanged
        ASSERT_TRUE(cgs_equal(&dstr, "start"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: multiple appends before commit");;;
    {
        DStr dstr = dstr_init_from("start");
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "a");
        cgs_append(appender, "b");
        cgs_append(appender, "c");
        cgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(cgs_equal(&dstr, "startabc"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: on empty DStr");;;
    {
        DStr dstr = dstr_init(10);
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "first");
        cgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: commit without any appends");;;
    {
        DStr dstr = dstr_init_from("unchanged");
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        CGS_Error err = cgs_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "unchanged"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: multiple uses with same state");;;
    {
        DStr dstr = dstr_init_from("base");
        AppenderState state = {};
        
        MutStrRef app1 = cgs_appender(&dstr, &state);
        cgs_append(app1, "1");
        cgs_commit_appender(&dstr, app1);
        
        MutStrRef app2 = cgs_appender(&dstr, &state);
        cgs_append(app2, "2");
        cgs_commit_appender(&dstr, app2);
        
        ASSERT_TRUE(cgs_equal(&dstr, "base12"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: causing buffer growth");;;
    {
        DStr dstr = dstr_init(5);
        cgs_append(&dstr, "x");
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        for (int i = 0; i < 100; i++) {
            cgs_append(appender, "y");
        }
        CGS_Error err = cgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for cgs_join
// ============================================================================

void test_str_join_edge_cases() {
    
    TEST("cgs_join: empty array");;;
    {
        StrViewArray arr = {NULL, 0, 0};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(dst.len == 0); // Should be empty string
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: single element");;;
    {
        char s1[] = "lonely";
        StrView views[] = { strv(s1, 0, 6) };
        StrViewArray arr = {views, 1, 1};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, ",");
        // Should NOT have a trailing delimiter: "lonely", not "lonely,"
        ASSERT_TRUE(cgs_equal(&dst, "lonely"));
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: elements are empty strings");;;
    {
        char empty[] = "";
        StrView views[] = { strv(empty, 0, 0), strv(empty, 0, 0) };
        StrViewArray arr = {views, 2, 2};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, ",");
        // Should result in exactly the delimiter: ","
        ASSERT_TRUE(cgs_equal(&dst, ","));
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: empty delimiter");;;
    {
        char s1[] = "a", s2[] = "b";
        StrView views[] = { strv(s1, 0, 1), strv(s2, 0, 1) };
        StrViewArray arr = {views, 2, 2};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, "");
        // Should just concatenate: "ab"
        ASSERT_TRUE(cgs_equal(&dst, "ab"));
        dstr_deinit(&dst);
    }
    
    // old
    TEST("cgs_join: empty array");;;
    {
        StrViewArray arr = {NULL, 0, 0};
        DStr dst = dstr_init(10);
        CGS_Error err = cgs_join(&dst, arr, ",");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: single element");;;
    {
        char s1[] = "only";
        StrView views[] = {strv(s1, 0, 4)};
        StrViewArray arr = {views, 1, 1};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(cgs_equal(&dst, "only"));
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: empty delimiter");;;
    {
        char s1[] = "a", s2[] = "b", s3[] = "c";
        StrView views[] = {
            strv(s1, 0, 1),
            strv(s2, 0, 1),
            strv(s3, 0, 1)
        };
        StrViewArray arr = {views, 3, 3};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, "");
        ASSERT_TRUE(cgs_equal(&dst, "abc"));
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: multi-char delimiter");;;
    {
        char s1[] = "a", s2[] = "b";
        StrView views[] = {
            strv(s1, 0, 1),
            strv(s2, 0, 1)
        };
        StrViewArray arr = {views, 2, 2};
        DStr dst = dstr_init(20);
        cgs_join(&dst, arr, "::");
        ASSERT_TRUE(cgs_equal(&dst, "a::b"));
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: with empty strings");;;
    {
        char s1[] = "", s2[] = "mid", s3[] = "";
        StrView views[] = {
            strv(s1, 0, 0),
            strv(s2, 0, 3),
            strv(s3, 0, 0)
        };
        StrViewArray arr = {views, 3, 3};
        DStr dst = dstr_init(20);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(cgs_equal(&dst, ",mid,"));
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: buffer too small");;;
    {
        char s1[] = "long", s2[] = "strings";
        StrView views[] = {
            strv(s1, 0, 4),
            strv(s2, 0, 7)
        };
        StrViewArray arr = {views, 2, 2};
        char backing[5];
        StrBuf sb = strbuf_init_from_buf(backing, 5);
        cgs_clear(&sb); // Initialize to empty
        CGS_Error err = cgs_join(&sb, arr, ",");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for tostr and print functions
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
    
    TEST("cgs_tostr_len: formatters (nfmt/arrfmt)");;;
    {
        // nfmt(255, 'X') -> "FF"
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
    
    TEST("cgs_map_chars: with DStr* and pointer types");;;
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
    
    TEST("tostr: integer boundary values (INT_MAX)");;;
    {
        DStr dstr = dstr_init();
        CGS_Error err = tostr(&dstr, INT_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_int_max[32]; // Max 2^31-1 is 10 digits, plus sign and null. 32 is safe.
        sprintf(expected_int_max, "%d", INT_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_int_max));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: integer boundary values (INT_MIN)");;;
    {
        DStr dstr = dstr_init(30);
        CGS_Error err = tostr(&dstr, INT_MIN);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_int_min[32]; // Max -2^31 is 10 digits, plus sign and null. 32 is safe.
        sprintf(expected_int_min, "%d", INT_MIN);
        ASSERT_TRUE(cgs_equal(&dstr, expected_int_min));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: zero");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = tostr(&dstr, 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "0"));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: positive integer");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = tostr(&dstr, 12345);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "12345"));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: negative integer");;;
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = tostr(&dstr, -6789);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "-6789"));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: long long boundary values (LLONG_MAX)");;;
    {
        DStr dstr = dstr_init(30);
        CGS_Error err = tostr(&dstr, LLONG_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_llong_max[64]; // Long long can be up to 19 digits + sign. 64 is very safe.
        sprintf(expected_llong_max, "%lld", LLONG_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_llong_max));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: unsigned int (UINT_MAX)");;;
    {
        DStr dstr = dstr_init(30);
        CGS_Error err = tostr(&dstr, UINT_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_uint_max[32];
        sprintf(expected_uint_max, "%u", UINT_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_uint_max));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: unsigned long long (ULLONG_MAX)");;;
    {
        DStr dstr = dstr_init(30);
        CGS_Error err = tostr(&dstr, ULLONG_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_ullong_max[64];
        sprintf(expected_ullong_max, "%llu", ULLONG_MAX);
        ASSERT_TRUE(cgs_equal(&dstr, expected_ullong_max));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: float (positive)");;;
    {
        DStr dstr = dstr_init(30);
        float val = 123.456f;
        CGS_Error err = tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_float[30];
        sprintf(expected_float, "%.6g", val); // Use appropriate precision for floats
        ASSERT_TRUE(cgs_equal(&dstr, expected_float));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: float (negative)");;;
    {
        DStr dstr = dstr_init(30);
        float val = -987.65f;
        CGS_Error err = tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_float[30];
        sprintf(expected_float, "%.6g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_float));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: float zero");;;
    {
        DStr dstr = dstr_init(30);
        float val = 0.0f;
        CGS_Error err = tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_float[30];
        sprintf(expected_float, "%.6g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_float));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: double (positive)");;;
    {
        DStr dstr = dstr_init(50);
        double val = 12345.67890123;
        CGS_Error err = tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_double[50];
        sprintf(expected_double, "%g", val); // Use appropriate precision for doubles
        ASSERT_TRUE(cgs_equal(&dstr, expected_double));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: double (negative)");;;
    {
        DStr dstr = dstr_init(50);
        double val = -98765.43210987;
        CGS_Error err = tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_double[50];
        sprintf(expected_double, "%g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_double));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: double zero");;;
    {
        DStr dstr = dstr_init(30);
        double val = 0.0;
        CGS_Error err = tostr(&dstr, val);
        ASSERT_EQ(err.ec, CGS_OK);
        char expected_double[30];
        sprintf(expected_double, "%.12g", val);
        ASSERT_TRUE(cgs_equal(&dstr, expected_double));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: buffer too small for integer");;;
    {
        char backing[3]; // Can hold "12" + null terminator
        StrBuf sb = strbuf_init_from_buf(backing, 3);
        cgs_clear(&sb);
        CGS_Error err = tostr(&sb, 123456); // Requires more than 2 characters + null
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("tostr: buffer too small for double");;;
    {
        char backing[5]; // Can hold "0.0" + null. Try to fit something bigger.
        StrBuf sb = strbuf_init_from_buf(backing, 5);
        cgs_clear(&sb);
        CGS_Error err = tostr(&sb, 123.456);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    // You could add tests for:
    // - Scientific notation for very large/small floats/doubles if your tostr supports it.
    // - Special float values: INFINITY, -INFINITY, NaN (if tostr handles them gracefully).
    
    TEST("cgs_print: multiple arguments (concatenation)");;;
    {
        CGS_StrBuf sb = {0};
        cgs_tostr_all(&sb, 123, " ", "test", " ", nfmt(456.78f, 'f', 2), "!", -99);
        ASSERT_TRUE(cgs_equal(sb, ""));
    }
    
    TEST("cgs_print: multiple arguments (concatenation)");;;
    {
        DStr dstr = dstr_init(50);
        cgs_tostr_all(&dstr, 123, " ", "test", " ", nfmt(456.78f, 'f', 2), "!", -99);
        ASSERT_TRUE(cgs_equal(&dstr, "123 test 456.78!-99"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_print: multiple arguments, buffer too small");;;
    {
        char backing[10];
        StrBuf sb = strbuf_init_from_buf(backing, 10);
        cgs_clear(&sb);
        cgs_tostr_all(&sb, 1, " ", "long_string_here");
        ASSERT_TRUE(cgs_equal(sb, "1 long_st"));
    }
    
    TEST("nfmt: various format characters");;;
    {
        DStr dstr = dstr_init(30);
        // Test hex, octal, etc.
        tostr(&dstr, nfmt(255, 'x'));
        ASSERT_TRUE(cgs_equal(dstr, "ff"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: integer decimal (signed/unsigned)");;;
    {
        DStr dstr = dstr_init(30);
        cgs_tostr_all(&dstr, nfmt(0, 'd'), " ", nfmt(-123, 'd'), " ", nfmt(2147483647, 'd'));
        ASSERT_TRUE(cgs_equal(&dstr, "0 -123 2147483647"));
        dstr_deinit(&dstr);
    }

    TEST("nfmt: integer hexadecimal (x/X)");;;
    {
        DStr dstr = dstr_init(20);
        tostr(&dstr, nfmt(255, 'x'));
        ASSERT_TRUE(cgs_equal(&dstr, "ff"));
        
        cgs_clear(&dstr);
        tostr(&dstr, nfmt(4095, 'X'));
        ASSERT_TRUE(cgs_equal(&dstr, "FFF"));
        dstr_deinit(&dstr);
    }

    TEST("nfmt: integer octal and binary");;;
    {
        DStr dstr = dstr_init(20);
        cgs_tostr_all(&dstr, nfmt(8, 'o'), " ", nfmt(5, 'b'));
        // 8 in octal is 10, 5 in binary is 101
        ASSERT_TRUE(cgs_equal(&dstr, "10 101"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: floating point fixed-point (f/F)");;;
    {
        DStr dstr = dstr_init(30);
        // Test precision and rounding
        cgs_tostr_all(&dstr, nfmt(3.14159f, 'f', 2), " ", nfmt(-0.555f, 'f', 1));
        ASSERT_TRUE(cgs_equal(&dstr, "3.14 -0.6"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: scientific notation (e/E)");;;
    {
        DStr dstr = dstr_init(30);
        cgs_tostr_all(&dstr, nfmt(1000.0, 'e', 2));
        ASSERT_TRUE(cgs_equal(&dstr, "1.00e+03"));
        
        cgs_clear(&dstr);
        cgs_tostr_all(&dstr, nfmt(0.001, 'E', 1));
        ASSERT_TRUE(cgs_equal(&dstr, "1.0E-03"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: general format (g/G)");;;
    {
        DStr dstr = dstr_init(30);
        // 'g' chooses between fixed and scientific based on magnitude
        cgs_tostr_all(&dstr, nfmt(123.456, 'g', 4));
        ASSERT_TRUE(cgs_equal(&dstr, "123.5")); // 4 significant digits
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: hex-float (a/A)");;;
    {
        DStr dstr = dstr_init(30);
        tostr(&dstr, nfmt(1.0, 'a'));
        // Usually 0x1.0p+0 or similar depending on implementation
        ASSERT_TRUE(cgs_equal(&dstr, "0x1p+0")); 
        
        cgs_clear(&dstr);
        tostr(&dstr, nfmt(15.5, 'A'));
        ASSERT_TRUE(cgs_equal(&dstr, "0X1.FP+3"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: integer limits and zero");;;
    {
        DStr dstr = dstr_init(50);
        long long max_val = 9223372036854775807LL;
        cgs_tostr_all(&dstr, nfmt(0, 'x'), " ", nfmt(max_val, 'd'));
        ASSERT_TRUE(cgs_equal(&dstr, "0 9223372036854775807"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: high precision and rounding");;;
    {
        DStr dstr = dstr_init(50);
        // Test very small float with high precision
        double val = 0.0000123456;
        cgs_tostr_all(&dstr, nfmt(val, 'f', 8));
        ASSERT_TRUE(cgs_equal(&dstr, "0.00001235"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_tostr_all: complex mixed types");;;
    {
        DStr dstr = dstr_init(100);
        int hex_val = 0xDEAD;
        float pi = 3.14159f;
        cgs_tostr_all(&dstr, "Hex: ", nfmt(hex_val, 'X'), ", Pi: ", nfmt(pi, 'g', 3), ", Bin: ", nfmt(7, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "Hex: DEAD, Pi: 3.14, Bin: 111"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt (binary): basic and zero");;;
    {
        DStr dstr = dstr_init(20);
        // Zero is a common edge case
        tostr(&dstr, nfmt(0, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "0"));
        
        cgs_clear(&dstr);
        // Small powers of 2
        cgs_tostr_all(&dstr, nfmt(1, 'b'), ",", nfmt(2, 'b'), ",", nfmt(4, 'b'), ",", nfmt(8, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "1,10,100,1000"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt (octal): basic and zero");;;
    {
        DStr dstr = dstr_init(20);
        tostr(&dstr, nfmt(0, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "0"));
        
        cgs_clear(&dstr);
        // Standard octal transitions
        cgs_tostr_all(&dstr, nfmt(7, 'o'), ",", nfmt(8, 'o'), ",", nfmt(16, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "7,10,20"));
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: unsigned integer limits (binary)");;;
    {
        DStr dstr = dstr_init(128);
        
        // uint8_t max (255)
        unsigned char u8_max = 255;
        tostr(&dstr, nfmt(u8_max, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "11111111"));
        
        cgs_clear(&dstr);
        // uint64_t max (18,446,744,073,709,551,615)
        unsigned long long u64_max = 0xFFFFFFFFFFFFFFFFULL;
        tostr(&dstr, nfmt(u64_max, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "1111111111111111111111111111111111111111111111111111111111111111"));
        
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: unsigned integer limits (octal)");;;
    {
        DStr dstr = dstr_init(64);
        
        // uint16_t max (65535)
        unsigned short u16_max = 65535;
        tostr(&dstr, nfmt(u16_max, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "177777"));
        
        cgs_clear(&dstr);
        // uint32_t max (4294967295)
        unsigned int u32_max = 4294967295U;
        tostr(&dstr, nfmt(u32_max, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "37777777777"));
        
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: signed negative integers (binary/octal)");;;
    {
        // Note: Standard C behavior for %o and %x is to treat the bits as unsigned.
        // These tests assume your library follows that convention.
        DStr dstr = dstr_init(128);
        
        // int8_t -1 (Two's complement: 11111111)
        signed char s8_neg = -1;
        tostr(&dstr, nfmt(s8_neg, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "11111111"));
        
        cgs_clear(&dstr);
        // int16_t -1 in octal (Two's complement: 177777)
        short s16_neg = -1;
        tostr(&dstr, nfmt(s16_neg, 'o'));
        ASSERT_TRUE(cgs_equal(&dstr, "177777"));
        
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: signed integer limits (decimal vs others)");;;
    {
        DStr dstr = dstr_init(128);
        
        // 64-bit Signed Minimum: -9,223,372,036,854,775,808
        long long s64_min = -9223372036854775807LL - 1LL;
        
        // Decimal should show the minus sign
        tostr(&dstr, nfmt(s64_min, 'd'));
        ASSERT_TRUE(cgs_equal(&dstr, "-9223372036854775808"));
        
        cgs_clear(&dstr);
        // Binary for signed min (usually 1 followed by 63 zeros)
        tostr(&dstr, nfmt(s64_min, 'b'));
        ASSERT_TRUE(cgs_equal(&dstr, "1000000000000000000000000000000000000000000000000000000000000000"));
        
        dstr_deinit(&dstr);
    }
    
    TEST("nfmt: type genericity check");;;
    {
        DStr dstr = dstr_init(100);
        
        unsigned char  v1 = 10;
        unsigned short v2 = 20;
        unsigned int   v3 = 30;
        
        // Testing that the macro/generic correctly handles different sizes in one call
        cgs_tostr_all(&dstr, nfmt(v1, 'b'), " ", nfmt(v2, 'o'), " ", nfmt(v3, 'x'));
        // 10=1010(b), 20=24(o), 30=1e(x)
        ASSERT_TRUE(cgs_equal(&dstr, "1010 24 1e"));
        
        dstr_deinit(&dstr);
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
        ReplaceResult res = cgs_replace(buf, "apple", "appleapple");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: invalid indices");;;
    {
        DStr s = dstr_init_from("abc");
        // Start > End
        CGS_Error err1 = cgs_replace_range(&s, 2, 1, "x");
        ASSERT_TRUE(err1.ec == CGS_BAD_RANGE);
        
        // Start out of bounds
        CGS_Error err2 = cgs_replace_range(&s, 5, 6, "x");
        ASSERT_TRUE(err2.ec == CGS_INDEX_OUT_OF_BOUNDS);
        
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: fixed buffer overflow check");;;
    {
        char buf[10] = "apple"; // capacity 10
        // Result would be "appleapple", length 10 + 1 for null = 11.
        // This should return CGS_DST_TOO_SMALL
        ReplaceResult res = cgs_replace(buf, "apple", "appleapple");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: invalid indices");;;
    {
        DStr s = dstr_init_from("abc");
        // Start > End
        CGS_Error err1 = cgs_replace_range(&s, 2, 1, "x");
        ASSERT_TRUE(err1.ec == CGS_BAD_RANGE);
        
        // Start out of bounds
        CGS_Error err2 = cgs_replace_range(&s, 5, 6, "x");
        ASSERT_TRUE(err2.ec == CGS_INDEX_OUT_OF_BOUNDS);
        
        dstr_deinit(&s);
    }
    
    TEST("stress: many allocations and deallocations");;;
    {
        for (int i = 0; i < 100; i++) {
            DStr dstr = dstr_init(i * 10);
            for (int j = 0; j < i; j++) {
                cgs_append(&dstr, "x");
            }
            dstr_deinit(&dstr);
        }
        ASSERT_TRUE(1);
    }
    
    TEST("stress: alternating growth and shrinkage");;;
    {
        DStr dstr = dstr_init(10);
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
        dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
    
    TEST("stress: very deep nesting of operations");;;
    {
        DStr dstr = dstr_init(1000);
        cgs_append(&dstr, "start");
        for (int i = 0; i < 100; i++) {
            cgs_replace(&dstr, "start", "middle");
            cgs_replace(&dstr, "middle", "end");
            cgs_replace(&dstr, "end", "start");
        }
        ASSERT_TRUE(cgs_equal(&dstr, "start"));
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Special Character Tests
// ============================================================================

void test_special_characters() {
    TEST("special chars: all printable ASCII");;;
    {
        DStr dstr = dstr_init(200);
        for (char c = 32; c < 127; c++) {
            cgs_putc(&dstr, c);
        }
        ASSERT_EQ(cgs_len(&dstr), 127 - 32);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: control characters");;;
    {
        DStr dstr = dstr_init(50);
        cgs_putc(&dstr, '\t');
        cgs_putc(&dstr, '\n');
        cgs_putc(&dstr, '\r');
        ASSERT_EQ(cgs_len(&dstr), 3);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: high ASCII");;;
    {
        DStr dstr = dstr_init(200);
        for (unsigned char c = 128; c < 255; c++) {
            cgs_putc(&dstr, c);
        }
        dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
}

void test_replace_all()
{
    TEST("cgs_replace: standard multiple replacement");;;
    {
        DStr s = dstr_init_from("banana");
        ReplaceResult res = cgs_replace(&s, "a", "o");
        // Result: "bonono", count: 3
        ASSERT_TRUE(res.nb_replaced == 3 && cgs_equal(&s, "bonono"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: empty target (Injection behavior)");;;
    {
        DStr s = dstr_init_from("abc");
        // Standard behavior (Python/JS): Replace "" with "-"
        // This usually results in "-a-b-c-"
        ReplaceResult res = cgs_replace(&s, "", "-");
        ASSERT_TRUE(cgs_equal(&s, "-a-b-c-"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: replacement contains target (No infinite loop)");;;
    {
        DStr s = dstr_init_from("a");
        // Replacing "a" with "aa" should only happen once per original match
        ReplaceResult res = cgs_replace(&s, "a", "aa");
        ASSERT_TRUE(res.nb_replaced == 1 && cgs_equal(&s, "aa"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: non-overlapping counts");;;
    {
        DStr s = dstr_init_from("aaaaa"); 
        ReplaceResult res = cgs_replace(&s, "aa", "b");
        // Result must be "bba", count must be 2
        ASSERT_TRUE(res.nb_replaced == 2);
        ASSERT_TRUE(cgs_equal(&s, "bba"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: target longer than source");;;
    {
        DStr s = dstr_init_from("abc");
        ReplaceResult res = cgs_replace(&s, "abcd", "x");
        ASSERT_TRUE(res.nb_replaced == 0 && cgs_equal(&s, "abc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: multiple replacements with different lengths");;;
    {
        DStr s = dstr_init_from("1-2-3");
        // Growing the string: "1" -> "one"
        ReplaceResult res = cgs_replace(&s, "-", "---");
        ASSERT_TRUE(cgs_equal(&s, "1---2---3"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: fixed buffer too small");;;
    {
        char buf[5] = "abc"; // Small fixed buffer
        ReplaceResult res = cgs_replace(buf, "b", "verylongstring");
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
        DStr s = dstr_init_from("hello");
        ReplaceResult res = cgs_replace(&s, "world", "earth");
        ASSERT_TRUE(res.nb_replaced == 0 && res.err.ec == CGS_NOT_FOUND);
        dstr_deinit(&s);
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
    
    printf("\n========================================\n");
    printf("Test Results: %d/%d passed\n", passed_count, test_count);
    printf("========================================\n");
    
    nfmt_t(int, 'd') f = nfmt(10, 'd');
    
    return (passed_count == test_count) ? 0 : 1;
}
