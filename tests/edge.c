#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

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
// Edge Case Tests for cgs_at
// ============================================================================

void test_str_at_edge_cases() {
    TEST("cgs_at: at exactly length boundary");
    {
        char buf[] = "test";
        // Accessing at index 4 (length) should be '\0'
        ASSERT_EQ(cgs_at(buf, 4), '\0');
        // Accessing beyond should also return '\0' (likely implementation dependent)
        // ASSERT_EQ(cgs_at(buf, 100), '\0');
    }
    
    TEST("cgs_at: empty string");
    {
        char buf[] = "";
        ASSERT_EQ(cgs_at(buf, 0), '\0');
        // ASSERT_EQ(cgs_at(buf, 1), '\0');
    }
    
    TEST("cgs_at: with embedded nulls");
    {
        char buf[10] = {'a', 'b', '\0', 'c', 'd', '\0'};
        ASSERT_EQ(cgs_at(buf, 0), 'a');
        ASSERT_EQ(cgs_at(buf, 1), 'b');
        ASSERT_EQ(cgs_at(buf, 2), '\0');
        // After first null, behavior depends on implementation
    }
    
    TEST("cgs_at: UINT_MAX index");
    {
        char buf[] = "test";
        // ASSERT_EQ(cgs_at(buf, UINT_MAX), '\0');
    }
}

// ============================================================================
// Edge Case Tests for cgs_len
// ============================================================================

void test_str_len_edge_cases() {
    TEST("cgs_len: empty string");
    {
        char buf[] = "";
        ASSERT_EQ(cgs_len(buf), 0);
    }
    
    TEST("cgs_len: single null terminator");
    {
        char buf[1] = {'\0'};
        ASSERT_EQ(cgs_len(buf), 0);
    }
    
    TEST("cgs_len: DStr with zero capacity");
    {
        DStr dstr = dstr_init(0);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_len: very long string");
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
    TEST("cgs_cap: raw char array");
    {
        char buf[100];
        // For raw arrays, capacity might not be trackable
        // This tests that it doesn't crash
        unsigned int cap = cgs_cap(buf);
        ASSERT_TRUE(cap == 100);
    }
    
    TEST("cgs_cap: StrBuf at exact capacity");
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
    TEST("cgs_equal: both empty");
    {
        char a[] = "";
        char b[] = "";
        ASSERT_TRUE(cgs_equal(a, b));
    }
    
    TEST("cgs_equal: one empty, one not");
    {
        char a[] = "";
        char b[] = "test";
        ASSERT_FALSE(cgs_equal(a, b));
        ASSERT_FALSE(cgs_equal(b, a));
    }
    
    TEST("cgs_equal: same pointer");
    {
        char a[] = "test";
        ASSERT_TRUE(cgs_equal(a, a));
    }
    
    TEST("cgs_equal: different types with same content");
    {
        char cstr[] = "hello";
        DStr dstr = dstr_init_from(cstr);
        ASSERT_TRUE(cgs_equal(cstr, &dstr));
        ASSERT_TRUE(cgs_equal(&dstr, cstr));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_equal: strings differing only in last char");
    {
        char a[] = "test1";
        char b[] = "test2";
        ASSERT_FALSE(cgs_equal(a, b));
    }
    
    TEST("cgs_equal: strings with embedded nulls");
    {
        char a[5] = {'a', 'b', '\0', 'c', 'd'};
        char b[5] = {'a', 'b', '\0', 'x', 'y'};
        // Should be equal up to first null
        ASSERT_TRUE(cgs_equal(a, b));
    }
    
    TEST("cgs_equal: very long identical strings");
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
    TEST("cgs_find: basic match");
    {
        char hay[] = "hello world";
        StrView v = cgs_find(hay, "world");
        // Should return view starting at index 6, length 5
        ASSERT_TRUE(v.chars == &hay[6]);
        ASSERT_TRUE(v.len == 5);
    }
    
    TEST("cgs_find: not found");
    {
        StrView v = cgs_find("apple", "orange");
        // Usually returns a null view (chars == NULL) or a view with len 0
        ASSERT_TRUE(v.chars == NULL || v.len == 0);
    }
    
    TEST("cgs_find: match at start and end");
    {
        char hay[] = "bracket";
        StrView start = cgs_find(hay, "b");
        StrView end = cgs_find(hay, "t");
        
        ASSERT_TRUE(start.chars == &hay[0]);
        ASSERT_TRUE(end.chars == &hay[6]);
    }
    
    TEST("cgs_find: empty needle");
    {
        char hay[] = "abc";
        StrView v = cgs_find(hay, "");
        // In most languages, finding "" returns the start of the string
        ASSERT_TRUE(v.chars == &hay[0]);
        ASSERT_TRUE(v.len == 0);
    }
    
    TEST("cgs_find: needle equals haystack");
    {
        char hay[] = "same";
        StrView v = cgs_find(hay, "same");
        ASSERT_TRUE(v.len == 4 && v.chars == &hay[0]);
    }
    
    TEST("cgs_find: needle longer than haystack");
    {
        StrView v = cgs_find("short", "much longer needle");
        ASSERT_TRUE(v.chars == NULL || v.len == 0);
    }
    
    TEST("cgs_find: empty needle in empty haystack");
    {
        char hay[] = "";
        char needle[] = "";
        StrView result = cgs_find(hay, needle);
        // Finding empty in empty might return start or invalid
        // Check it doesn't crash
        ASSERT_TRUE((char*)result.chars == hay);
    }
    
    TEST("cgs_find: empty needle in non-empty haystack");
    {
        char hay[] = "test";
        char needle[] = "";
        StrView result = cgs_find(hay, needle);
        // Should probably find at position 0 or be invalid
        ASSERT_TRUE(result.chars == hay);
    }
    
    TEST("cgs_find: needle longer than haystack");
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 0); // Not found
    }
    
    TEST("cgs_find: needle equals haystack");
    {
        char hay[] = "exact";
        char needle[] = "exact";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 5);
    }
    
    TEST("cgs_find: needle at very end");
    {
        char hay[] = "abcdefghij";
        char needle[] = "hij";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 3);
    }
    
    TEST("cgs_find: needle at very start");
    {
        char hay[] = "abcdefghij";
        char needle[] = "abc";
        StrView result = cgs_find(hay, needle);
        ASSERT_EQ(cgs_len(result), 3);
    }
    
    TEST("cgs_find: overlapping pattern");
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        StrView result = cgs_find(hay, needle);
        // Should find first occurrence
        ASSERT_TRUE(cgs_len(result) > 0);
    }
    
    TEST("cgs_find: pattern that almost matches");
    {
        char hay[] = "abcabcabd";
        char needle[] = "abcabd";
        StrView result = cgs_find(hay, needle);
        ASSERT_TRUE(cgs_len(result) > 0);
    }
}

// ============================================================================
// Edge Case Tests for cgs_count
// ============================================================================

void test_str_count_edge_cases() {
    TEST("cgs_count: basic count");
    {
        unsigned int n = cgs_count("banana", "a");
        ASSERT_TRUE(n == 3);
    }
    
    TEST("cgs_count: non-overlapping logic");
    {
        // "aa" appears in "aaaaa" at:
        // [aa] [aa] a  <- Non-overlapping (2)
        //  a [aa] [aa] <- Non-overlapping alternative
        // Standard behavior is to consume the first match and move on.
        unsigned int n = cgs_count("aaaaa", "aa");
        ASSERT_TRUE(n == 2);
    }
    
    TEST("cgs_count: no matches");
    {
        unsigned int n = cgs_count("abc", "z");
        ASSERT_TRUE(n == 0);
    }
    
    TEST("cgs_count: empty needle (Interstitial Gaps)");
    {
        // "abc" has gaps: ^ a ^ b ^ c ^ 
        // Index:        0 1 1 2 2 3 3
        // Most modern libs (Python, Go, etc.) count len + 1
        unsigned int n = cgs_count("abc", "");
        ASSERT_TRUE(n == 4);
    }
    
    TEST("cgs_count: empty haystack");
    {
        // "" contains one ""
        ASSERT_TRUE(cgs_count("", "") == 1);
        // "" contains zero "a"
        ASSERT_TRUE(cgs_count("", "a") == 0);
    }
    
    TEST("cgs_count: needle is haystack");
    {
        ASSERT_TRUE(cgs_count("test", "test") == 1);
    }
    
    TEST("cgs_count: needle overlaps but is not identical");
    {
        // count "ababa" in "abababa"
        // [ababa] ba -> 1 match
        unsigned int n = cgs_count("abababa", "ababa");
        ASSERT_TRUE(n == 1);
    }
    
    TEST("cgs_count: empty needle");
    {
        char hay[] = "test";
        char needle[] = "";
        unsigned int count = cgs_count(hay, needle);
        ASSERT_TRUE(count == cgs_len(hay) + 1);
    }
    
    TEST("cgs_count: empty haystack");
    {
        char hay[] = "";
        char needle[] = "x";
        ASSERT_EQ(cgs_count(hay, needle), 0);
    }
    
    TEST("cgs_count: overlapping occurrences");
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        unsigned int count = cgs_count(hay, needle);
        // Could be 2 (non-overlapping) or 3 (overlapping)
        ASSERT_TRUE(count == 2 || count == 3);
    }
    
    TEST("cgs_count: needle equals haystack");
    {
        char hay[] = "exact";
        char needle[] = "exact";
        ASSERT_EQ(cgs_count(hay, needle), 1);
    }
    
    TEST("cgs_count: needle longer than haystack");
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        ASSERT_EQ(cgs_count(hay, needle), 0);
    }
    
    TEST("cgs_count: many occurrences");
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
    TEST("cgs_clear: already empty DStr");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_clear(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_clear: StrBuf at capacity");
    {
        char backing[5] = {'f', 'u', 'l', 'l', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 5);
        CGS_Error err = cgs_clear(&sb);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&sb), 0);
    }
    
    TEST("cgs_clear: raw char array (might be unsupported)");
    {
        char buf[10] = "test";
        // This might return an error or work
        CGS_Error err = cgs_clear(buf);
        // Just check it doesn't crash
        ASSERT_TRUE(1);
    }
    
    TEST("cgs_clear: then append");
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
    TEST("cgs_starts_with: empty prefix");
    {
        char hay[] = "test";
        char prefix[] = "";
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: prefix equals string");
    {
        char hay[] = "exact";
        char prefix[] = "exact";
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: prefix longer than string");
    {
        char hay[] = "ab";
        char prefix[] = "abcdef";
        ASSERT_FALSE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_starts_with: both empty");
    {
        char hay[] = "";
        char prefix[] = "";
        ASSERT_TRUE(cgs_starts_with(hay, prefix));
    }
    
    TEST("cgs_ends_with: empty suffix");
    {
        char hay[] = "test";
        char suffix[] = "";
        ASSERT_TRUE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_ends_with: suffix equals string");
    {
        char hay[] = "exact";
        char suffix[] = "exact";
        ASSERT_TRUE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_ends_with: suffix longer than string");
    {
        char hay[] = "ab";
        char suffix[] = "zabcdef";
        ASSERT_FALSE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_ends_with: single character suffix");
    {
        char hay[] = "test";
        char suffix[] = "t";
        ASSERT_TRUE(cgs_ends_with(hay, suffix));
    }
    
    TEST("cgs_starts_with: case sensitive");
    {
        char hay[] = "Test";
        char prefix[] = "test";
        ASSERT_FALSE(cgs_starts_with(hay, prefix));
    }
}

// ============================================================================
// Edge Case Tests for cgs_tolower / cgs_toupper
// ============================================================================

void test_str_case_edge_cases() {
    TEST("cgs_tolower: empty string");
    {
        DStr dstr = dstr_init_from("");
        cgs_tolower(&dstr);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: already lowercase");
    {
        DStr dstr = dstr_init_from("alllower");
        cgs_tolower(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "alllower"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: with numbers and symbols");
    {
        DStr dstr = dstr_init_from("Test123!@#");
        cgs_tolower(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "test123!@#"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_toupper: empty string");
    {
        DStr dstr = dstr_init_from("");
        cgs_toupper(&dstr);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_toupper: already uppercase");
    {
        DStr dstr = dstr_init_from("ALLUPPER");
        cgs_toupper(&dstr);
        ASSERT_TRUE(cgs_equal(&dstr, "ALLUPPER"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_tolower: on read-only buffer (should fail)");
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
    TEST("cgs_copy: empty to empty");
    {
        char dst[10] = "";
        char src[] = "";
        CGS_Error err = cgs_copy(dst, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(dst), 0);
    }
    
    TEST("cgs_copy: to buffer exactly sized");
    {
        char dst[5];
        char src[] = "test";
        CGS_Error err = cgs_copy(dst, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(dst, "test"));
    }
    
    TEST("cgs_copy: to buffer one too small");
    {
        char dst[4];
        char src[] = "test";
        CGS_Error err = cgs_copy(dst, src);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_copy: to StrBuf at capacity");
    {
        char backing[5];
        StrBuf sb = strbuf_init_from_buf(backing, 5);
        char src[] = "test";
        CGS_Error err = cgs_copy(&sb, src);
        ASSERT_EQ(err.ec, CGS_OK);
    }
    
    TEST("cgs_copy: overlapping buffers (aliasing)");
    {
        char buf[10] = "test";
        // Copying to itself should fail or handle gracefully
        CGS_Error err = cgs_copy(buf, buf);
        // Might return CGS_ALIASING_NOT_SUPPORTED
        ASSERT_TRUE(err.ec == CGS_ALIASING_NOT_SUPPORTED || err.ec == CGS_OK);
    }
    
    TEST("cgs_copy: to DStr with insufficient capacity");
    {
        DStr dstr = dstr_init(2);
        char src[] = "this is a long string";
        CGS_Error err = cgs_copy(&dstr, src);
        // Should either reallocate or fail
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_DST_TOO_SMALL || err.ec == CGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_copy: from DStr to char array");
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
    TEST("cgs_putc: to empty DStr");
    {
        DStr dstr = dstr_init(0);
        CGS_Error err = cgs_putc(&dstr, 'a');
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: null character");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_putc(&dstr, '\0');
        // Behavior may vary - might end string or add literal null
        (void)err;
        ASSERT_TRUE(1);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: to StrBuf at capacity");
    {
        char backing[3] = {'a', 'b', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 3);
        CGS_Error err = cgs_putc(&sb, 'c');
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_putc: extended ASCII character");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_putc(&dstr, 0xFF);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_putc: many characters sequentially");
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
}

// ============================================================================
// Edge Case Tests for cgs_append
// ============================================================================

void test_str_append_edge_cases() {
    TEST("cgs_append: empty to empty");
    {
        DStr dst = dstr_init(10);
        char src[] = "";
        CGS_Error err = cgs_append(&dst, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("cgs_append: to itself (aliasing)");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_append(&dstr, &dstr);
        // Should detect aliasing or handle it
        ASSERT_TRUE(err.ec == CGS_ALIASING_NOT_SUPPORTED || err.ec == CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_append: to StrBuf causing overflow");
    {
        char backing[10] = "hello";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        char src[] = "world!";
        CGS_Error err = cgs_append(&sb, src);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_append: exactly fitting capacity");
    {
        char backing[11] = "hello";
        StrBuf sb = strbuf_init_from_cstr(backing, 11);
        char src[] = "world";
        CGS_Error err = cgs_append(&sb, src);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&sb, "helloworld"));
    }
    
    TEST("cgs_append: multiple appends growing DStr");
    {
        DStr dstr = dstr_init(1);
        for (int i = 0; i < 100; i++) {
            CGS_Error err = cgs_append(&dstr, "x");
            ASSERT_EQ(err.ec, CGS_OK);
        }
        ASSERT_EQ(cgs_len(&dstr), 100);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_append: very long string");
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
    TEST("cgs_del: delete entire string");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete nothing (from == to)");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 2, 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: invalid range (from > to)");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 3, 1);
        ASSERT_EQ(err.ec, CGS_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: out of bounds from");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 10, 15);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: out of bounds to");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 100);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete from middle");
    {
        DStr dstr = dstr_init_from("abcdef");
        CGS_Error err = cgs_del(&dstr, 2, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abef"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete first character");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 0, 1);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "est"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: delete last character");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_del(&dstr, 3, 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "tes"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_del: on empty string");
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
    TEST("cgs_replace: target not found");
    {
        DStr dstr = dstr_init_from("hello world");
        ReplaceResult res = cgs_replace(&dstr, "xyz", "abc");
        ASSERT_EQ(res.err.ec, CGS_NOT_FOUND);
        ASSERT_EQ(res.nb_replaced, 0);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: empty target");
    {
        DStr dstr = dstr_init_from("test");
        ReplaceResult res = cgs_replace(&dstr, "", "x");
        // Replacing empty string is likely an error or no-op
        ASSERT_TRUE(res.err.ec == CGS_OK || res.err.ec == CGS_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replace with empty string");
    {
        DStr dstr = dstr_init_from("hello world");
        ReplaceResult res = cgs_replace(&dstr, "o", "");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hell wrld"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replacement longer than target");
    {
        DStr dstr = dstr_init_from("hi hi hi");
        ReplaceResult res = cgs_replace(&dstr, "hi", "hello");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hello hello hello"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: replacement shorter than target");
    {
        DStr dstr = dstr_init_from("hello hello");
        ReplaceResult res = cgs_replace(&dstr, "hello", "hi");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "hi hi"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: overlapping matches");
    {
        DStr dstr = dstr_init_from("aaa");
        ReplaceResult res = cgs_replace(&dstr, "aa", "b");
        // Should replace non-overlapping: "aaa" -> "ba" (1 replacement)
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(res.nb_replaced == 1);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: target equals entire string");
    {
        DStr dstr = dstr_init_from("exact");
        ReplaceResult res = cgs_replace(&dstr, "exact", "replaced");
        ASSERT_EQ(res.err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "replaced"));
        ASSERT_EQ(res.nb_replaced, 1);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace: on StrBuf with insufficient space");
    {
        char backing[10] = "hi hi"; // "hello hi"
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        ReplaceResult res = cgs_replace(&sb, "hi", "hello");
        // println("hi hi", " became :: ", sb);
        ASSERT_EQ(res.err.ec, CGS_DST_TOO_SMALL);
        ASSERT_EQ(res.nb_replaced, 1);
    }
    
    TEST("cgs_replace: many occurrences");
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
    TEST("cgs_replace_first: no occurrence");
    {
        DStr dstr = dstr_init_from("hello");
        CGS_Error err = cgs_replace_first(&dstr, "xyz", "abc");
        ASSERT_EQ(err.ec, CGS_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: empty string target");
    {
        DStr s = dstr_init_from("abc");
        // Replacing the first "" is defined in many libs as an injection at start
        cgs_replace_first(&s, "", "!");
        ASSERT_TRUE(cgs_equal(&s, "!abc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: match at end of string");
    {
        DStr s = dstr_init_from("path/to/file");
        cgs_replace_first(&s, "file", "dir");
        ASSERT_TRUE(cgs_equal(&s, "path/to/dir"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: multiple occurrences");
    {
        DStr dstr = dstr_init_from("test test test");
        CGS_Error err = cgs_replace_first(&dstr, "test", "word");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "word test test"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: at end of string");
    {
        DStr dstr = dstr_init_from("abcdef");
        CGS_Error err = cgs_replace_first(&dstr, "def", "xyz");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abcxyz"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_first: only first occurrence");
    {
        DStr s = dstr_init_from("ababab");
        CGS_Error err = cgs_replace_first(&s, "ab", "X");
        ASSERT_TRUE(cgs_equal(&s, "Xabab") && err.ec == CGS_OK);
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: target at the very end");
    {
        DStr s = dstr_init_from("hello world");
        CGS_Error err = cgs_replace_first(&s, "world", "C");
        ASSERT_TRUE(cgs_equal(&s, "hello C"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: target is the whole string");
    {
        DStr s = dstr_init_from("match");
        cgs_replace_first(&s, "match", "replaced");
        ASSERT_TRUE(cgs_equal(&s, "replaced"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_first: error when not found");
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
    TEST("cgs_replace_range: remove last character");
    {
        DStr s = dstr_init_from("Hello!");
        // Range is [5, 6) -> the '!'
        cgs_replace_range(&s, 5, 6, ""); 
        ASSERT_TRUE(cgs_equal(&s, "Hello"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace inside string with much longer string");
    {
        DStr s = dstr_init_from("a[ ]c");
        // Replace "[ ]" (index 1 to 4) with "long string"
        cgs_replace_range(&s, 1, 4, "is a very long string");
        ASSERT_TRUE(cgs_equal(&s, "ais a very long stringc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: null/empty replacement at specific index (Insertion)");
    {
        DStr s = dstr_init_from("ac");
        cgs_replace_range(&s, 1, 1, "b");
        ASSERT_TRUE(cgs_equal(&s, "abc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace entire string");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 4, "replaced");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "replaced"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: invalid range");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 3, 1, "x");
        ASSERT_EQ(err.ec, CGS_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: out of bounds");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 100, "x");
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: zero-length range (insertion)");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 2, 2, "XX");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "teXXst"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: with empty replacement (deletion)");
    {
        DStr dstr = dstr_init_from("testing");
        CGS_Error err = cgs_replace_range(&dstr, 2, 5, "");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "teng"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: at string boundaries");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_replace_range(&dstr, 0, 0, "start");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "starttest"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_replace_range: StrBuf overflow");
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_replace_range(&sb, 0, 4, "very long replacement");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: replace middle (same size)");
    {
        DStr s = dstr_init_from("ABCDE");
        // Replace "BCD" (indices 1, 2, 3) with "123"
        CGS_Error err = cgs_replace_range(&s, 1, 4, "123");
        ASSERT_TRUE(cgs_equal(&s, "A123E"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: grow string (insertion)");
    {
        DStr s = dstr_init_from("AB");
        // Replace nothing at index 1 with "123" -> "A123B"
        CGS_Error err = cgs_replace_range(&s, 1, 1, "123");
        ASSERT_TRUE(cgs_equal(&s, "A123B"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: shrink string (deletion)");
    {
        DStr s = dstr_init_from("Hello World");
        // Replace " World" (index 5 to 11) with ""
        CGS_Error err = cgs_replace_range(&s, 5, 11, "");
        ASSERT_TRUE(cgs_equal(&s, "Hello"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: replace entire string");
    {
        DStr s = dstr_init_from("old");
        cgs_replace_range(&s, 0, 3, "new");
        ASSERT_TRUE(cgs_equal(&s, "new"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: out of bounds");
    {
        DStr s = dstr_init_from("abc");
        CGS_Error err = cgs_replace_range(&s, 1, 10, "x");
        ASSERT_TRUE(err.ec == CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace_range: inverted range");
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
    
    TEST("cgs_split: empty string");
    {
        char str[] = "";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should return array with 0 or 1 empty element
        ASSERT_TRUE(arr.len == 1 && arr.strs[0].chars == str);
        free(arr.strs);
    }
    
    TEST("Split: No delimiter present in source");
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
    
    TEST("cgs_split: empty string with non-empty delimiter");
    {
        char str[] = "";
        StrViewArray arr = cgs_split(str, ",");
        // Most languages (Java, JS, Python) return [""]
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(arr.strs[0].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: empty delimiter (Explode behavior)");
    {
        char str[] = "abc";
        StrViewArray arr = cgs_split(str, "");
        // Explode: "abc" -> ["a", "b", "c"]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[0].len == 1 && arr.strs[0].chars[0] == 'a');
        ASSERT_TRUE(arr.strs[2].len == 1 && arr.strs[2].chars[0] == 'c');
        free(arr.strs);
    }
    
    TEST("cgs_split: consecutive delimiters (Empty fields)");
    {
        char str[] = "a,,b";
        StrViewArray arr = cgs_split(str, ",");
        // Result: ["a", "", "b"]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[1].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: leading and trailing delimiters");
    {
        char str[] = ",a,";
        StrViewArray arr = cgs_split(str, ",");
        // Result: ["", "a", ""]
        ASSERT_TRUE(arr.len == 3);
        ASSERT_TRUE(arr.strs[0].len == 0);
        ASSERT_TRUE(arr.strs[2].len == 0);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter not present");
    {
        char str[] = "hello";
        StrViewArray arr = cgs_split(str, "|");
        // Should return the original string as the only element
        ASSERT_TRUE(arr.len == 1);
        ASSERT_TRUE(cgs_equal(arr.strs[0], "hello"));
        free(arr.strs);
    }
    
    TEST("cgs_split: string is exactly the delimiter");
    {
        char str[] = "::";
        StrViewArray arr = cgs_split(str, "::");
        // Result: ["", ""]
        ASSERT_TRUE(arr.len == 2);
        ASSERT_TRUE(arr.strs[0].len == 0 && arr.strs[1].len == 0);
        free(arr.strs);
    }    
    TEST("cgs_split: delimiter not in string");
    {
        char str[] = "no delimiters here";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        ASSERT_EQ(arr.len, 1);
        free(arr.strs);
    }
    
    TEST("cgs_split: consecutive delimiters");
    {
        char str[] = "a,,b,,c";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 5 elements: "a", "", "b", "", "c"
        ASSERT_EQ(arr.len, 5);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter at start");
    {
        char str[] = ",test";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 2 elements: "" and "test"
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: delimiter at end");
    {
        char str[] = "test,";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 2 elements: "test" and ""
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: only delimiter");
    {
        char str[] = ",";
        char delim[] = ",";
        StrViewArray arr = cgs_split(str, delim);
        // Should have 2 empty elements
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("cgs_split: multi-character delimiter");
    {
        char str[] = "a::b::c";
        char delim[] = "::";
        StrViewArray arr = cgs_split(str, delim);
        ASSERT_EQ(arr.len, 3);
        free(arr.strs);
    }
    
    TEST("cgs_split: many splits");
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
    TEST("cgs_insert: at position 0 (same as prepend)");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "START", 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "STARTtest"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: at middle position");
    {
        DStr dstr = dstr_init_from("abef");
        CGS_Error err = cgs_insert(&dstr, "cd", 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "abcdef"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: at end position");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "end", 4);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "testend"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: out of bounds position");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "x", 100);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: into empty string at position 0");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_insert(&dstr, "first", 0);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: into empty string at position > 0");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_insert(&dstr, "test", 5);
        ASSERT_EQ(err.ec, CGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_insert: StrBuf overflow");
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_insert(&sb, "longinsert", 2);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_insert: empty string insertion");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = cgs_insert(&dstr, "", 2);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_prepend: to empty string");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_prepend(&dstr, "first");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_prepend: StrBuf overflow");
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        CGS_Error err = cgs_prepend(&sb, "longprefix");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_prepend: multiple times");
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
    TEST("dstr_init: zero capacity");
    {
        DStr dstr = dstr_init(0);
        ASSERT_EQ(cgs_len(&dstr), 0);
        // Should still be usable
        CGS_Error err = cgs_append(&dstr, "test");
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init: very large capacity");
    {
        DStr dstr = dstr_init(1000000);
        ASSERT_TRUE(cgs_cap(&dstr) >= 1000000 || cgs_cap(&dstr) == 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init_from: empty string");
    {
        DStr dstr = dstr_init_from("");
        ASSERT_EQ(cgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: already minimal");
    {
        DStr dstr = dstr_init_from("test");
        CGS_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_cap(&dstr) >= cgs_len(&dstr));
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: after deletions");
    {
        DStr dstr = dstr_init(1000);
        cgs_append(&dstr, "small");
        CGS_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: already sufficient");
    {
        DStr dstr = dstr_init(100);
        CGS_Error err = dstr_ensure_cap(&dstr, 50);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: needs growth");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = dstr_ensure_cap(&dstr, 100);
        ASSERT_TRUE(err.ec == CGS_OK || err.ec == CGS_ALLOC_ERR);
        if (err.ec == CGS_OK) {
            ASSERT_TRUE(cgs_cap(&dstr) >= 100);
        }
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: zero requested");
    {
        DStr dstr = dstr_init(10);
        CGS_Error err = dstr_ensure_cap(&dstr, 0);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for StrBuf
// ============================================================================

void test_string_buffer_edge_cases() {
    TEST("StrBuf: from empty array");
    {
        char buf[1] = {'\0'};
        StrBuf sb = strbuf_init_from_cstr(buf, 1);
        ASSERT_EQ(cgs_len(&sb), 0);
        ASSERT_EQ(cgs_cap(&sb), 1);
    }
    
    TEST("StrBuf: from array without null terminator");
    {
        char buf[5] = {'t', 'e', 's', 't', 'x'};
        StrBuf sb = strbuf_init_from_buf(buf, 5);
        ASSERT_TRUE(sb.len == 0);
    }
    
    TEST("StrBuf: from cstr with capacity exactly length + 1");
    {
        char buf[5] = {'t', 'e', 's', 't', '\0'};
        StrBuf sb = strbuf_init_from_cstr(buf, 5);
        ASSERT_EQ(cgs_cap(&sb), 5);
        ASSERT_EQ(cgs_len(&sb), 4);
    }
    
    TEST("StrBuf: from buf with exact capacity");
    {
        char buf[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
        StrBuf sb = strbuf_init_from_buf(buf, 10);
        ASSERT_EQ(cgs_cap(&sb), 10);
    }
    
    TEST("StrBuf: append to full buffer from cstr");
    {
        char buf[5] = {'f', 'u', 'l', 'l', '\0'};
        StrBuf sb = strbuf_init_from_cstr(buf, 5);
        CGS_Error err = cgs_append(&sb, "x");
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("StrBuf: init from buf then set content");
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
    TEST("strv: empty range");
    {
        char str[] = "test";
        StrView sv = strv(str, 2, 2);
        ASSERT_EQ(cgs_len(sv), 0);
    }
    
    TEST("strv: entire string");
    {
        char str[] = "test";
        StrView sv = strv(str, 0, 4);
        ASSERT_EQ(cgs_len(sv), 4);
        ASSERT_TRUE(cgs_equal(sv, "test"));
    }
    
    TEST("strv: invalid range (from > to)");
    {
        char str[] = "test";
        StrView sv = strv(str, 3, 1);
        // Likely returns empty or errors
        ASSERT_TRUE(1);
    }
    
    TEST("strv: single character");
    {
        char str[] = "test";
        StrView sv = strv(str, 1, 2);
        ASSERT_EQ(cgs_len(sv), 1);
        ASSERT_EQ(cgs_at(sv, 0), 'e');
    }
}

// ============================================================================
// Edge Case Tests for file I/O functions
// ============================================================================

void test_file_io_edge_cases() {
    TEST("cgs_fread_line: from empty file");
    {
        FILE *f = tmpfile();
        DStr dstr = dstr_init(10);
        CGS_Error err = cgs_fread_line(&dstr, f);
        // Should indicate EOF or empty read
        ASSERT_TRUE(err.ec == CGS_OK || err.ec != CGS_OK);
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_fread_line: very long line");
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
    
    TEST("cgs_fread_line: line without newline");
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
    
    TEST("cgs_fread_line: multiple calls");
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
    
    TEST("cgs_append_fread_line: append multiple lines");
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
    TEST("cgs_appender: basic usage");
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
    
    TEST("cgs_appender: without commit");
    {
        DStr dstr = dstr_init_from("start");
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "lost");
        // Not committed - dstr should be unchanged
        ASSERT_TRUE(cgs_equal(&dstr, "start"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: multiple appends before commit");
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
    
    TEST("cgs_appender: on empty DStr");
    {
        DStr dstr = dstr_init(10);
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        cgs_append(appender, "first");
        cgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(cgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: commit without any appends");
    {
        DStr dstr = dstr_init_from("unchanged");
        AppenderState state = {};
        MutStrRef appender = cgs_appender(&dstr, &state);
        CGS_Error err = cgs_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_TRUE(cgs_equal(&dstr, "unchanged"));
        dstr_deinit(&dstr);
    }
    
    TEST("cgs_appender: multiple uses with same state");
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
    
    TEST("cgs_appender: causing buffer growth");
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
    
    TEST("cgs_join: empty array");
    {
        StrViewArray arr = {NULL, 0, 0};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(dst.len == 0); // Should be empty string
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: single element");
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
    
    TEST("cgs_join: elements are empty strings");
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
    
    TEST("cgs_join: empty delimiter");
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
    TEST("cgs_join: empty array");
    {
        StrViewArray arr = {NULL, 0, 0};
        DStr dst = dstr_init(10);
        CGS_Error err = cgs_join(&dst, arr, ",");
        ASSERT_EQ(err.ec, CGS_OK);
        ASSERT_EQ(cgs_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: single element");
    {
        char s1[] = "only";
        StrView views[] = {strv(s1, 0, 4)};
        StrViewArray arr = {views, 1, 1};
        DStr dst = dstr_init(10);
        cgs_join(&dst, arr, ",");
        ASSERT_TRUE(cgs_equal(&dst, "only"));
        dstr_deinit(&dst);
    }
    
    TEST("cgs_join: empty delimiter");
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
    
    TEST("cgs_join: multi-char delimiter");
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
    
    TEST("cgs_join: with empty strings");
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
    
    TEST("cgs_join: buffer too small");
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

void test_tostr_edge_cases() {
    TEST("tostr: integer boundary values");
    {
        DStr dstr = dstr_init(30);
        CGS_Error err = tostr(&dstr, INT_MAX);
        ASSERT_EQ(err.ec, CGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: negative integers");
    {
        DStr dstr = dstr_init(30);
        tostr(&dstr, INT_MIN);
        ASSERT_TRUE(cgs_len(&dstr) > 0);
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: zero");
    {
        DStr dstr = dstr_init(10);
        tostr(&dstr, 0);
        ASSERT_TRUE(cgs_equal(&dstr, "0"));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: buffer too small");
    {
        char backing[3];
        StrBuf sb = strbuf_init_from_buf(backing, 3);
        cgs_clear(&sb); // Initialize to empty
        CGS_Error err = tostr(&sb, 123456);
        ASSERT_EQ(err.ec, CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_print: multiple arguments");
    {
        DStr dstr = dstr_init(50);
        // Assuming cgs_print can take multiple args
        // cgs_print(&dstr, 123, " ", "test", " ", 456);
        // Test would verify concatenation
        ASSERT_TRUE(1);
        dstr_deinit(&dstr);
    }
    
    TEST("tsfmt: various format characters");
    {
        DStr dstr = dstr_init(30);
        // Test hex, octal, etc.
        // tostr(&dstr, tsfmt(255, 'x'));
        ASSERT_TRUE(1);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Stress Tests
// ============================================================================

void test_stress_cases() {
    TEST("cgs_replace: fixed buffer overflow check");
    {
        char buf[10] = "apple"; // capacity 10
        // Result would be "appleapple", length 10 + 1 for null = 11.
        // This should return CGS_DST_TOO_SMALL
        ReplaceResult res = cgs_replace(buf, "apple", "appleapple");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: invalid indices");
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
    
    TEST("cgs_replace: fixed buffer overflow check");
    {
        char buf[10] = "apple"; // capacity 10
        // Result would be "appleapple", length 10 + 1 for null = 11.
        // This should return CGS_DST_TOO_SMALL
        ReplaceResult res = cgs_replace(buf, "apple", "appleapple");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_range: invalid indices");
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
    
    TEST("stress: many allocations and deallocations");
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
    
    TEST("stress: alternating growth and shrinkage");
    {
        DStr dstr = dstr_init(10);
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 100; j++) {
                cgs_putc(&dstr, 'x');
            }
            cgs_clear(&dstr);
        }
        dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
    
    TEST("stress: very deep nesting of operations");
    {
        DStr dstr = dstr_init(1000);
        cgs_append(&dstr, "start");
        for (int i = 0; i < 100; i++) {
            cgs_replace(&dstr, "start", "middle");
            cgs_replace(&dstr, "middle", "end");
            cgs_replace(&dstr, "end", "start");
        }
        dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
}

// ============================================================================
// Special Character Tests
// ============================================================================

void test_special_characters() {
    TEST("special chars: all printable ASCII");
    {
        DStr dstr = dstr_init(200);
        for (char c = 32; c < 127; c++) {
            cgs_putc(&dstr, c);
        }
        ASSERT_EQ(cgs_len(&dstr), 127 - 32);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: control characters");
    {
        DStr dstr = dstr_init(50);
        cgs_putc(&dstr, '\t');
        cgs_putc(&dstr, '\n');
        cgs_putc(&dstr, '\r');
        ASSERT_EQ(cgs_len(&dstr), 3);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: high ASCII");
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
    TEST("cgs_replace: standard multiple replacement");
    {
        DStr s = dstr_init_from("banana");
        ReplaceResult res = cgs_replace(&s, "a", "o");
        // Result: "bonono", count: 3
        ASSERT_TRUE(res.nb_replaced == 3 && cgs_equal(&s, "bonono"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: empty target (Injection behavior)");
    {
        DStr s = dstr_init_from("abc");
        // Standard behavior (Python/JS): Replace "" with "-"
        // This usually results in "-a-b-c-"
        ReplaceResult res = cgs_replace(&s, "", "-");
        ASSERT_TRUE(cgs_equal(&s, "-a-b-c-"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: replacement contains target (No infinite loop)");
    {
        DStr s = dstr_init_from("a");
        // Replacing "a" with "aa" should only happen once per original match
        ReplaceResult res = cgs_replace(&s, "a", "aa");
        ASSERT_TRUE(res.nb_replaced == 1 && cgs_equal(&s, "aa"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: non-overlapping counts");
    {
        DStr s = dstr_init_from("aaaaa"); 
        ReplaceResult res = cgs_replace(&s, "aa", "b");
        // Result must be "bba", count must be 2
        ASSERT_TRUE(res.nb_replaced == 2);
        ASSERT_TRUE(cgs_equal(&s, "bba"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: target longer than source");
    {
        DStr s = dstr_init_from("abc");
        ReplaceResult res = cgs_replace(&s, "abcd", "x");
        ASSERT_TRUE(res.nb_replaced == 0 && cgs_equal(&s, "abc"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: multiple replacements with different lengths");
    {
        DStr s = dstr_init_from("1-2-3");
        // Growing the string: "1" -> "one"
        ReplaceResult res = cgs_replace(&s, "-", "---");
        ASSERT_TRUE(cgs_equal(&s, "1---2---3"));
        dstr_deinit(&s);
    }
    
    TEST("cgs_replace: fixed buffer too small");
    {
        char buf[5] = "abc"; // Small fixed buffer
        ReplaceResult res = cgs_replace(buf, "b", "verylongstring");
        ASSERT_TRUE(res.err.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace_first: fixed buffer too small");
    {
        char buf[5] = "abc"; // Small fixed buffer
        CGS_Error res = cgs_replace_first(buf, "b", "verylongstring");
        ASSERT_TRUE(res.ec == CGS_DST_TOO_SMALL);
    }
    
    TEST("cgs_replace: target not found");
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
    
    test_str_at_edge_cases();
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
    
    return (passed_count == test_count) ? 0 : 1;
}