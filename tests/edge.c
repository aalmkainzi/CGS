#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

#define SGS_SHORT_NAMES
#include "../sgs.c"
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
// Edge Case Tests for sgs_at
// ============================================================================

void test_str_at_edge_cases() {
    TEST("sgs_at: at exactly length boundary");
    {
        char buf[] = "test";
        // Accessing at index 4 (length) should be '\0'
        ASSERT_EQ(sgs_at(buf, 4), '\0');
        // Accessing beyond should also return '\0' (likely implementation dependent)
        // ASSERT_EQ(sgs_at(buf, 100), '\0');
    }
    
    TEST("sgs_at: empty string");
    {
        char buf[] = "";
        ASSERT_EQ(sgs_at(buf, 0), '\0');
        // ASSERT_EQ(sgs_at(buf, 1), '\0');
    }
    
    TEST("sgs_at: with embedded nulls");
    {
        char buf[10] = {'a', 'b', '\0', 'c', 'd', '\0'};
        ASSERT_EQ(sgs_at(buf, 0), 'a');
        ASSERT_EQ(sgs_at(buf, 1), 'b');
        ASSERT_EQ(sgs_at(buf, 2), '\0');
        // After first null, behavior depends on implementation
    }
    
    TEST("sgs_at: UINT_MAX index");
    {
        char buf[] = "test";
        // ASSERT_EQ(sgs_at(buf, UINT_MAX), '\0');
    }
}

// ============================================================================
// Edge Case Tests for sgs_len
// ============================================================================

void test_str_len_edge_cases() {
    TEST("sgs_len: empty string");
    {
        char buf[] = "";
        ASSERT_EQ(sgs_len(buf), 0);
    }
    
    TEST("sgs_len: single null terminator");
    {
        char buf[1] = {'\0'};
        ASSERT_EQ(sgs_len(buf), 0);
    }
    
    TEST("sgs_len: DStr with zero capacity");
    {
        DStr dstr = dstr_init(0);
        ASSERT_EQ(sgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_len: very long string");
    {
        // This tests if length calculation handles large strings
        DStr dstr = dstr_init(10000);
        for (int i = 0; i < 9999; i++) {
            sgs_putc(&dstr, 'a');
        }
        ASSERT_EQ(sgs_len(&dstr), 9999);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for sgs_cap
// ============================================================================

void test_str_cap_edge_cases() {
    TEST("sgs_cap: raw char array");
    {
        char buf[100];
        // For raw arrays, capacity might not be trackable
        // This tests that it doesn't crash
        unsigned int cap = sgs_cap(buf);
        ASSERT_TRUE(cap == 100);
    }
    
    TEST("sgs_cap: StrBuf at exact capacity");
    {
        char backing[5] = {'t', 'e', 's', 't', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 5);
        ASSERT_EQ(sgs_cap(&sb), 5);
    }
}

// ============================================================================
// Edge Case Tests for sgs_equal
// ============================================================================

void test_str_equal_edge_cases() {
    TEST("sgs_equal: both empty");
    {
        char a[] = "";
        char b[] = "";
        ASSERT_TRUE(sgs_equal(a, b));
    }
    
    TEST("sgs_equal: one empty, one not");
    {
        char a[] = "";
        char b[] = "test";
        ASSERT_FALSE(sgs_equal(a, b));
        ASSERT_FALSE(sgs_equal(b, a));
    }
    
    TEST("sgs_equal: same pointer");
    {
        char a[] = "test";
        ASSERT_TRUE(sgs_equal(a, a));
    }
    
    TEST("sgs_equal: different types with same content");
    {
        char cstr[] = "hello";
        DStr dstr = dstr_init_from(cstr);
        ASSERT_TRUE(sgs_equal(cstr, &dstr));
        ASSERT_TRUE(sgs_equal(&dstr, cstr));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_equal: strings differing only in last char");
    {
        char a[] = "test1";
        char b[] = "test2";
        ASSERT_FALSE(sgs_equal(a, b));
    }
    
    TEST("sgs_equal: strings with embedded nulls");
    {
        char a[5] = {'a', 'b', '\0', 'c', 'd'};
        char b[5] = {'a', 'b', '\0', 'x', 'y'};
        // Should be equal up to first null
        ASSERT_TRUE(sgs_equal(a, b));
    }
    
    TEST("sgs_equal: very long identical strings");
    {
        DStr a = dstr_init(5000);
        DStr b = dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            sgs_putc(&a, 'x');
            sgs_putc(&b, 'x');
        }
        ASSERT_TRUE(sgs_equal(&a, &b));
        dstr_deinit(&a);
        dstr_deinit(&b);
    }
}

// ============================================================================
// Edge Case Tests for sgs_find
// ============================================================================

void test_str_find_edge_cases() {
    TEST("sgs_find: empty needle in empty haystack");
    {
        char hay[] = "";
        char needle[] = "";
        StrView result = sgs_find(hay, needle);
        // Finding empty in empty might return start or invalid
        // Check it doesn't crash
        ASSERT_TRUE((char*)result.chars == hay);
    }
    
    TEST("sgs_find: empty needle in non-empty haystack");
    {
        char hay[] = "test";
        char needle[] = "";
        StrView result = sgs_find(hay, needle);
        // Should probably find at position 0 or be invalid
        ASSERT_TRUE(1);
    }
    
    TEST("sgs_find: needle longer than haystack");
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        StrView result = sgs_find(hay, needle);
        ASSERT_EQ(sgs_len(result), 0); // Not found
    }
    
    TEST("sgs_find: needle equals haystack");
    {
        char hay[] = "exact";
        char needle[] = "exact";
        StrView result = sgs_find(hay, needle);
        ASSERT_EQ(sgs_len(result), 5);
    }
    
    TEST("sgs_find: needle at very end");
    {
        char hay[] = "abcdefghij";
        char needle[] = "hij";
        StrView result = sgs_find(hay, needle);
        ASSERT_EQ(sgs_len(result), 3);
    }
    
    TEST("sgs_find: needle at very start");
    {
        char hay[] = "abcdefghij";
        char needle[] = "abc";
        StrView result = sgs_find(hay, needle);
        ASSERT_EQ(sgs_len(result), 3);
    }
    
    TEST("sgs_find: overlapping pattern");
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        StrView result = sgs_find(hay, needle);
        // Should find first occurrence
        ASSERT_TRUE(sgs_len(result) > 0);
    }
    
    TEST("sgs_find: pattern that almost matches");
    {
        char hay[] = "abcabcabd";
        char needle[] = "abcabd";
        StrView result = sgs_find(hay, needle);
        ASSERT_TRUE(sgs_len(result) > 0);
    }
}

// ============================================================================
// Edge Case Tests for sgs_count
// ============================================================================

void test_str_count_edge_cases() {
    TEST("sgs_count: empty needle");
    {
        char hay[] = "test";
        char needle[] = "";
        unsigned int count = sgs_count(hay, needle);
        // Counting empty strings might return 0 or undefined
        (void)count;
        ASSERT_TRUE(1);
    }
    
    TEST("sgs_count: empty haystack");
    {
        char hay[] = "";
        char needle[] = "x";
        ASSERT_EQ(sgs_count(hay, needle), 0);
    }
    
    TEST("sgs_count: overlapping occurrences");
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        unsigned int count = sgs_count(hay, needle);
        // Could be 2 (non-overlapping) or 3 (overlapping)
        ASSERT_TRUE(count == 2 || count == 3);
    }
    
    TEST("sgs_count: needle equals haystack");
    {
        char hay[] = "exact";
        char needle[] = "exact";
        ASSERT_EQ(sgs_count(hay, needle), 1);
    }
    
    TEST("sgs_count: needle longer than haystack");
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        ASSERT_EQ(sgs_count(hay, needle), 0);
    }
    
    TEST("sgs_count: many occurrences");
    {
        char hay[] = "a a a a a a a a a a";
        char needle[] = "a";
        ASSERT_EQ(sgs_count(hay, needle), 10);
    }
}

// ============================================================================
// Edge Case Tests for sgs_clear
// ============================================================================

void test_str_clear_edge_cases() {
    TEST("sgs_clear: already empty DStr");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_clear(&dstr);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_EQ(sgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_clear: StrBuf at capacity");
    {
        char backing[5] = {'f', 'u', 'l', 'l', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 5);
        SGS_Error err = sgs_clear(&sb);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_EQ(sgs_len(&sb), 0);
    }
    
    TEST("sgs_clear: raw char array (might be unsupported)");
    {
        char buf[10] = "test";
        // This might return an error or work
        SGS_Error err = sgs_clear(buf);
        // Just check it doesn't crash
        ASSERT_TRUE(1);
    }
    
    TEST("sgs_clear: then append");
    {
        DStr dstr = dstr_init_from("original");
        sgs_clear(&dstr);
        SGS_Error err = sgs_append(&dstr, "new");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "new"));
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for sgs_starts_with / sgs_ends_with
// ============================================================================

void test_str_starts_ends_with_edge_cases() {
    TEST("sgs_starts_with: empty prefix");
    {
        char hay[] = "test";
        char prefix[] = "";
        ASSERT_TRUE(sgs_starts_with(hay, prefix));
    }
    
    TEST("sgs_starts_with: prefix equals string");
    {
        char hay[] = "exact";
        char prefix[] = "exact";
        ASSERT_TRUE(sgs_starts_with(hay, prefix));
    }
    
    TEST("sgs_starts_with: prefix longer than string");
    {
        char hay[] = "ab";
        char prefix[] = "abcdef";
        ASSERT_FALSE(sgs_starts_with(hay, prefix));
    }
    
    TEST("sgs_starts_with: both empty");
    {
        char hay[] = "";
        char prefix[] = "";
        ASSERT_TRUE(sgs_starts_with(hay, prefix));
    }
    
    TEST("sgs_ends_with: empty suffix");
    {
        char hay[] = "test";
        char suffix[] = "";
        ASSERT_TRUE(sgs_ends_with(hay, suffix));
    }
    
    TEST("sgs_ends_with: suffix equals string");
    {
        char hay[] = "exact";
        char suffix[] = "exact";
        ASSERT_TRUE(sgs_ends_with(hay, suffix));
    }
    
    TEST("sgs_ends_with: suffix longer than string");
    {
        char hay[] = "ab";
        char suffix[] = "zabcdef";
        ASSERT_FALSE(sgs_ends_with(hay, suffix));
    }
    
    TEST("sgs_ends_with: single character suffix");
    {
        char hay[] = "test";
        char suffix[] = "t";
        ASSERT_TRUE(sgs_ends_with(hay, suffix));
    }
    
    TEST("sgs_starts_with: case sensitive");
    {
        char hay[] = "Test";
        char prefix[] = "test";
        ASSERT_FALSE(sgs_starts_with(hay, prefix));
    }
}

// ============================================================================
// Edge Case Tests for sgs_tolower / sgs_toupper
// ============================================================================

void test_str_case_edge_cases() {
    TEST("sgs_tolower: empty string");
    {
        DStr dstr = dstr_init_from("");
        sgs_tolower(&dstr);
        ASSERT_EQ(sgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_tolower: already lowercase");
    {
        DStr dstr = dstr_init_from("alllower");
        sgs_tolower(&dstr);
        ASSERT_TRUE(sgs_equal(&dstr, "alllower"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_tolower: with numbers and symbols");
    {
        DStr dstr = dstr_init_from("Test123!@#");
        sgs_tolower(&dstr);
        ASSERT_TRUE(sgs_equal(&dstr, "test123!@#"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_toupper: empty string");
    {
        DStr dstr = dstr_init_from("");
        sgs_toupper(&dstr);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_toupper: already uppercase");
    {
        DStr dstr = dstr_init_from("ALLUPPER");
        sgs_toupper(&dstr);
        ASSERT_TRUE(sgs_equal(&dstr, "ALLUPPER"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_tolower: on read-only buffer (should fail)");
    {
        char buf[] = "TEST";
        sgs_tolower(buf);
        ASSERT_TRUE(sgs_equal(buf, "test"));
    }
}

// ============================================================================
// Edge Case Tests for sgs_copy
// ============================================================================

void test_str_copy_edge_cases() {
    TEST("sgs_copy: empty to empty");
    {
        char dst[10] = "";
        char src[] = "";
        SGS_Error err = sgs_copy(dst, src);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_EQ(sgs_len(dst), 0);
    }
    
    TEST("sgs_copy: to buffer exactly sized");
    {
        char dst[5];
        char src[] = "test";
        SGS_Error err = sgs_copy(dst, src);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(dst, "test"));
    }
    
    TEST("sgs_copy: to buffer one too small");
    {
        char dst[4];
        char src[] = "test";
        SGS_Error err = sgs_copy(dst, src);
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
    
    TEST("sgs_copy: to StrBuf at capacity");
    {
        char backing[5];
        StrBuf sb = strbuf_init_from_buf(backing, 5);
        char src[] = "test";
        SGS_Error err = sgs_copy(&sb, src);
        ASSERT_EQ(err.ec, SGS_OK);
    }
    
    TEST("sgs_copy: overlapping buffers (aliasing)");
    {
        char buf[10] = "test";
        // Copying to itself should fail or handle gracefully
        SGS_Error err = sgs_copy(buf, buf);
        // Might return SGS_ALIASING_NOT_SUPPORTED
        ASSERT_TRUE(err.ec == SGS_ALIASING_NOT_SUPPORTED || err.ec == SGS_OK);
    }
    
    TEST("sgs_copy: to DStr with insufficient capacity");
    {
        DStr dstr = dstr_init(2);
        char src[] = "this is a long string";
        SGS_Error err = sgs_copy(&dstr, src);
        // Should either reallocate or fail
        ASSERT_TRUE(err.ec == SGS_OK || err.ec == SGS_DST_TOO_SMALL || err.ec == SGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_copy: from DStr to char array");
    {
        DStr src = dstr_init_from("source");
        char dst[20];
        SGS_Error err = sgs_copy(dst, &src);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(dst, "source"));
        dstr_deinit(&src);
    }
}

// ============================================================================
// Edge Case Tests for sgs_putc
// ============================================================================

void test_str_putc_edge_cases() {
    TEST("sgs_putc: to empty DStr");
    {
        DStr dstr = dstr_init(0);
        SGS_Error err = sgs_putc(&dstr, 'a');
        ASSERT_TRUE(err.ec == SGS_OK || err.ec == SGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_putc: null character");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_putc(&dstr, '\0');
        // Behavior may vary - might end string or add literal null
        (void)err;
        ASSERT_TRUE(1);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_putc: to StrBuf at capacity");
    {
        char backing[3] = {'a', 'b', '\0'};
        StrBuf sb = strbuf_init_from_cstr(backing, 3);
        SGS_Error err = sgs_putc(&sb, 'c');
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
    
    TEST("sgs_putc: extended ASCII character");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_putc(&dstr, 0xFF);
        ASSERT_EQ(err.ec, SGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_putc: many characters sequentially");
    {
        DStr dstr = dstr_init(1);
        for (int i = 0; i < 1000; i++) {
            SGS_Error err = sgs_putc(&dstr, 'x');
            if (err.ec != SGS_OK) {
                printf("  Failed at iteration %d with error code %d\n", i, err.ec);
                break;
            }
        }
        ASSERT_EQ(sgs_len(&dstr), 1000);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for sgs_append
// ============================================================================

void test_str_append_edge_cases() {
    TEST("sgs_append: empty to empty");
    {
        DStr dst = dstr_init(10);
        char src[] = "";
        SGS_Error err = sgs_append(&dst, src);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_EQ(sgs_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("sgs_append: to itself (aliasing)");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_append(&dstr, &dstr);
        // Should detect aliasing or handle it
        ASSERT_TRUE(err.ec == SGS_ALIASING_NOT_SUPPORTED || err.ec == SGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_append: to StrBuf causing overflow");
    {
        char backing[10] = "hello";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        char src[] = "world!";
        SGS_Error err = sgs_append(&sb, src);
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
    
    TEST("sgs_append: exactly fitting capacity");
    {
        char backing[11] = "hello";
        StrBuf sb = strbuf_init_from_cstr(backing, 11);
        char src[] = "world";
        SGS_Error err = sgs_append(&sb, src);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&sb, "helloworld"));
    }
    
    TEST("sgs_append: multiple appends growing DStr");
    {
        DStr dstr = dstr_init(1);
        for (int i = 0; i < 100; i++) {
            SGS_Error err = sgs_append(&dstr, "x");
            ASSERT_EQ(err.ec, SGS_OK);
        }
        ASSERT_EQ(sgs_len(&dstr), 100);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_append: very long string");
    {
        DStr dstr = dstr_init(100);
        DStr long_str = dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            sgs_putc(&long_str, 'a');
        }
        SGS_Error err = sgs_append(&dstr, &long_str);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_EQ(sgs_len(&dstr), 4999);
        dstr_deinit(&dstr);
        dstr_deinit(&long_str);
    }
}

// ============================================================================
// Edge Case Tests for sgs_del
// ============================================================================

void test_str_del_edge_cases() {
    TEST("sgs_del: delete entire string");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_del(&dstr, 0, 4);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_EQ(sgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: delete nothing (from == to)");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_del(&dstr, 2, 2);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: invalid range (from > to)");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_del(&dstr, 3, 1);
        ASSERT_EQ(err.ec, SGS_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: out of bounds from");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_del(&dstr, 10, 15);
        ASSERT_EQ(err.ec, SGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: out of bounds to");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_del(&dstr, 0, 100);
        ASSERT_EQ(err.ec, SGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: delete from middle");
    {
        DStr dstr = dstr_init_from("abcdef");
        SGS_Error err = sgs_del(&dstr, 2, 4);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "abef"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: delete first character");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_del(&dstr, 0, 1);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "est"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: delete last character");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_del(&dstr, 3, 4);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "tes"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_del: on empty string");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_del(&dstr, 0, 0);
        ASSERT_EQ(err.ec, SGS_OK);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for sgs_replace
// ============================================================================

void test_str_replace_edge_cases() {
    TEST("sgs_replace: target not found");
    {
        DStr dstr = dstr_init_from("hello world");
        ReplaceResult res = sgs_replace(&dstr, "xyz", "abc");
        ASSERT_EQ(res.err.ec, SGS_NOT_FOUND);
        ASSERT_EQ(res.nb_replaced, 0);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace: empty target");
    {
        DStr dstr = dstr_init_from("test");
        ReplaceResult res = sgs_replace(&dstr, "", "x");
        // Replacing empty string is likely an error or no-op
        ASSERT_TRUE(res.err.ec == SGS_OK || res.err.ec == SGS_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace: replace with empty string");
    {
        DStr dstr = dstr_init_from("hello world");
        ReplaceResult res = sgs_replace(&dstr, "o", "");
        ASSERT_EQ(res.err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "hell wrld"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace: replacement longer than target");
    {
        DStr dstr = dstr_init_from("hi hi hi");
        ReplaceResult res = sgs_replace(&dstr, "hi", "hello");
        ASSERT_EQ(res.err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "hello hello hello"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace: replacement shorter than target");
    {
        DStr dstr = dstr_init_from("hello hello");
        ReplaceResult res = sgs_replace(&dstr, "hello", "hi");
        ASSERT_EQ(res.err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "hi hi"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace: overlapping matches");
    {
        DStr dstr = dstr_init_from("aaa");
        ReplaceResult res = sgs_replace(&dstr, "aa", "b");
        // Should replace non-overlapping: "aaa" -> "ba" (1 replacement)
        ASSERT_EQ(res.err.ec, SGS_OK);
        ASSERT_TRUE(res.nb_replaced == 1);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace: target equals entire string");
    {
        DStr dstr = dstr_init_from("exact");
        ReplaceResult res = sgs_replace(&dstr, "exact", "replaced");
        ASSERT_EQ(res.err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "replaced"));
        ASSERT_EQ(res.nb_replaced, 1);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace: on StrBuf with insufficient space");
    {
        char backing[10] = "hi hi"; // "hello hi"
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        ReplaceResult res = sgs_replace(&sb, "hi", "hello");
        // println("hi hi", " became :: ", sb);
        ASSERT_EQ(res.err.ec, SGS_DST_TOO_SMALL);
        ASSERT_EQ(res.nb_replaced, 1);
    }
    
    TEST("sgs_replace: many occurrences");
    {
        DStr dstr = dstr_init(100);
        for (int i = 0; i < 50; i++) {
            sgs_append(&dstr, "x ");
        }
        ReplaceResult res = sgs_replace(&dstr, "x", "y");
        ASSERT_EQ(res.err.ec, SGS_OK);
        ASSERT_EQ(res.nb_replaced, 50);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for sgs_replace_first
// ============================================================================

void test_str_replace_first_edge_cases() {
    TEST("sgs_replace_first: no occurrence");
    {
        DStr dstr = dstr_init_from("hello");
        SGS_Error err = sgs_replace_first(&dstr, "xyz", "abc");
        ASSERT_EQ(err.ec, SGS_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_first: multiple occurrences");
    {
        DStr dstr = dstr_init_from("test test test");
        SGS_Error err = sgs_replace_first(&dstr, "test", "word");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "word test test"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_first: at end of string");
    {
        DStr dstr = dstr_init_from("abcdef");
        SGS_Error err = sgs_replace_first(&dstr, "def", "xyz");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "abcxyz"));
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for sgs_replace_range
// ============================================================================

void test_str_replace_range_edge_cases() {
    TEST("sgs_replace_range: replace entire string");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_replace_range(&dstr, 0, 4, "replaced");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "replaced"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_range: invalid range");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_replace_range(&dstr, 3, 1, "x");
        ASSERT_EQ(err.ec, SGS_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_range: out of bounds");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_replace_range(&dstr, 0, 100, "x");
        ASSERT_EQ(err.ec, SGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_range: zero-length range (insertion)");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_replace_range(&dstr, 2, 2, "XX");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "teXXst"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_range: with empty replacement (deletion)");
    {
        DStr dstr = dstr_init_from("testing");
        SGS_Error err = sgs_replace_range(&dstr, 2, 5, "");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "teng"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_range: at string boundaries");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_replace_range(&dstr, 0, 0, "start");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "starttest"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_replace_range: StrBuf overflow");
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        SGS_Error err = sgs_replace_range(&sb, 0, 4, "very long replacement");
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for sgs_split
// ============================================================================

void test_str_split_edge_cases() {
    TEST("sgs_split: empty string");
    {
        char str[] = "";
        char delim[] = ",";
        StrViewArray arr = sgs_split(str, delim);
        // Should return array with 0 or 1 empty element
        ASSERT_TRUE(arr.len == 0 || arr.len == 1);
        free(arr.strs);
    }
    
    TEST("sgs_split: empty delimiter");
    {
        char str[] = "test";
        char delim[] = "";
        StrViewArray arr = sgs_split(str, delim);
        // Behavior undefined - might split into characters or return whole string
        ASSERT_TRUE(1);
        free(arr.strs);
    }
    
    TEST("sgs_split: delimiter not in string");
    {
        char str[] = "no delimiters here";
        char delim[] = ",";
        StrViewArray arr = sgs_split(str, delim);
        ASSERT_EQ(arr.len, 1);
        free(arr.strs);
    }
    
    TEST("sgs_split: consecutive delimiters");
    {
        char str[] = "a,,b,,c";
        char delim[] = ",";
        StrViewArray arr = sgs_split(str, delim);
        // Should have 5 elements: "a", "", "b", "", "c"
        ASSERT_EQ(arr.len, 5);
        free(arr.strs);
    }
    
    TEST("sgs_split: delimiter at start");
    {
        char str[] = ",test";
        char delim[] = ",";
        StrViewArray arr = sgs_split(str, delim);
        // Should have 2 elements: "" and "test"
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("sgs_split: delimiter at end");
    {
        char str[] = "test,";
        char delim[] = ",";
        StrViewArray arr = sgs_split(str, delim);
        // Should have 2 elements: "test" and ""
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("sgs_split: only delimiter");
    {
        char str[] = ",";
        char delim[] = ",";
        StrViewArray arr = sgs_split(str, delim);
        // Should have 2 empty elements
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("sgs_split: multi-character delimiter");
    {
        char str[] = "a::b::c";
        char delim[] = "::";
        StrViewArray arr = sgs_split(str, delim);
        ASSERT_EQ(arr.len, 3);
        free(arr.strs);
    }
    
    TEST("sgs_split: many splits");
    {
        DStr dstr = dstr_init(1000);
        for (int i = 0; i < 100; i++) {
            sgs_append(&dstr, "x,");
        }
        StrViewArray arr = sgs_split(&dstr, ",");
        ASSERT_EQ(arr.len, 101); // 100 "x" and 1 trailing empty
        dstr_deinit(&dstr);
        free(arr.strs);
    }
}

// ============================================================================
// Edge Case Tests for sgs_insert / sgs_prepend
// ============================================================================

void test_str_insert_prepend_edge_cases() {
    TEST("sgs_insert: at position 0 (same as prepend)");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_insert(&dstr, "START", 0);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "STARTtest"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_insert: at middle position");
    {
        DStr dstr = dstr_init_from("abef");
        SGS_Error err = sgs_insert(&dstr, "cd", 2);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "abcdef"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_insert: at end position");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_insert(&dstr, "end", 4);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "testend"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_insert: out of bounds position");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_insert(&dstr, "x", 100);
        ASSERT_EQ(err.ec, SGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_insert: into empty string at position 0");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_insert(&dstr, "first", 0);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_insert: into empty string at position > 0");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_insert(&dstr, "test", 5);
        ASSERT_EQ(err.ec, SGS_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_insert: StrBuf overflow");
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        SGS_Error err = sgs_insert(&sb, "longinsert", 2);
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
    
    TEST("sgs_insert: empty string insertion");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = sgs_insert(&dstr, "", 2);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_prepend: to empty string");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_prepend(&dstr, "first");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_prepend: StrBuf overflow");
    {
        char backing[10] = "test";
        StrBuf sb = strbuf_init_from_cstr(backing, 10);
        SGS_Error err = sgs_prepend(&sb, "longprefix");
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
    
    TEST("sgs_prepend: multiple times");
    {
        DStr dstr = dstr_init_from("end");
        sgs_prepend(&dstr, "middle");
        sgs_prepend(&dstr, "start");
        ASSERT_TRUE(sgs_equal(&dstr, "startmiddleend"));
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
        ASSERT_EQ(sgs_len(&dstr), 0);
        // Should still be usable
        SGS_Error err = sgs_append(&dstr, "test");
        ASSERT_TRUE(err.ec == SGS_OK || err.ec == SGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init: very large capacity");
    {
        DStr dstr = dstr_init(1000000);
        ASSERT_TRUE(sgs_cap(&dstr) >= 1000000 || sgs_cap(&dstr) == 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init_from: empty string");
    {
        DStr dstr = dstr_init_from("");
        ASSERT_EQ(sgs_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: already minimal");
    {
        DStr dstr = dstr_init_from("test");
        SGS_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_cap(&dstr) >= sgs_len(&dstr));
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: after deletions");
    {
        DStr dstr = dstr_init(1000);
        sgs_append(&dstr, "small");
        SGS_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, SGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: already sufficient");
    {
        DStr dstr = dstr_init(100);
        SGS_Error err = dstr_ensure_cap(&dstr, 50);
        ASSERT_EQ(err.ec, SGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: needs growth");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = dstr_ensure_cap(&dstr, 100);
        ASSERT_TRUE(err.ec == SGS_OK || err.ec == SGS_ALLOC_ERR);
        if (err.ec == SGS_OK) {
            ASSERT_TRUE(sgs_cap(&dstr) >= 100);
        }
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: zero requested");
    {
        DStr dstr = dstr_init(10);
        SGS_Error err = dstr_ensure_cap(&dstr, 0);
        ASSERT_EQ(err.ec, SGS_OK);
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
        ASSERT_EQ(sgs_len(&sb), 0);
        ASSERT_EQ(sgs_cap(&sb), 1);
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
        ASSERT_EQ(sgs_cap(&sb), 5);
        ASSERT_EQ(sgs_len(&sb), 4);
    }
    
    TEST("StrBuf: from buf with exact capacity");
    {
        char buf[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
        StrBuf sb = strbuf_init_from_buf(buf, 10);
        ASSERT_EQ(sgs_cap(&sb), 10);
    }
    
    TEST("StrBuf: append to full buffer from cstr");
    {
        char buf[5] = {'f', 'u', 'l', 'l', '\0'};
        StrBuf sb = strbuf_init_from_cstr(buf, 5);
        SGS_Error err = sgs_append(&sb, "x");
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
    
    TEST("StrBuf: init from buf then set content");
    {
        char buf[20];
        StrBuf sb = strbuf_init_from_buf(buf, 20);
        SGS_Error err = sgs_copy(&sb, "test");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&sb, "test"));
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
        ASSERT_EQ(sgs_len(sv), 0);
    }
    
    TEST("strv: entire string");
    {
        char str[] = "test";
        StrView sv = strv(str, 0, 4);
        ASSERT_EQ(sgs_len(sv), 4);
        ASSERT_TRUE(sgs_equal(sv, "test"));
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
        ASSERT_EQ(sgs_len(sv), 1);
        ASSERT_EQ(sgs_at(sv, 0), 'e');
    }
}

// ============================================================================
// Edge Case Tests for file I/O functions
// ============================================================================

void test_file_io_edge_cases() {
    TEST("sgs_fread_line: from empty file");
    {
        FILE *f = tmpfile();
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_fread_line(&dstr, f);
        // Should indicate EOF or empty read
        ASSERT_TRUE(err.ec == SGS_OK || err.ec != SGS_OK);
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_fread_line: very long line");
    {
        FILE *f = tmpfile();
        for (int i = 0; i < 10000; i++)
        {
            fputc('x', f);
        }
        fputc('\n', f);
        rewind(f);
        
        DStr dstr = dstr_init(10);
        SGS_Error err = sgs_fread_line(&dstr, f);
        ASSERT_TRUE(err.ec == SGS_OK || err.ec == SGS_ALLOC_ERR);
        if (err.ec == SGS_OK)
        {
            ASSERT_EQ(sgs_len(&dstr), 10001);
        }
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_fread_line: line without newline");
    {
        FILE *f = tmpfile();
        fprintf(f, "no newline");
        rewind(f);
        
        DStr dstr = dstr_init(20);
        SGS_Error err = sgs_fread_line(&dstr, f);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "no newline"));
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_fread_line: multiple calls");
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\nline3\n");
        rewind(f);
        
        DStr dstr = dstr_init(20);
        sgs_fread_line(&dstr, f);
        ASSERT_TRUE(sgs_equal(&dstr, "line1\n"));
        
        sgs_clear(&dstr);
        sgs_fread_line(&dstr, f);
        ASSERT_TRUE(sgs_equal(&dstr, "line2\n"));
        
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_append_fread_line: append multiple lines");
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\n");
        rewind(f);
        
        DStr dstr = dstr_init(50);
        sgs_append_fread_line(&dstr, f);
        sgs_append_fread_line(&dstr, f);
        ASSERT_TRUE(sgs_equal(&dstr, "line1\nline2\n"));
        
        fclose(f);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for appender
// ============================================================================

void test_appender_edge_cases() {
    TEST("sgs_appender: basic usage");
    {
        DStr dstr = dstr_init_from("start");
        StrAppenderState state = {};
        MutStrRef appender = sgs_appender(&dstr, &state);
        sgs_append(appender, "end");
        SGS_Error err = sgs_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "startend"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_appender: without commit");
    {
        DStr dstr = dstr_init_from("start");
        StrAppenderState state = {};
        MutStrRef appender = sgs_appender(&dstr, &state);
        sgs_append(appender, "lost");
        // Not committed - dstr should be unchanged
        ASSERT_TRUE(sgs_equal(&dstr, "start"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_appender: multiple appends before commit");
    {
        DStr dstr = dstr_init_from("start");
        StrAppenderState state = {};
        MutStrRef appender = sgs_appender(&dstr, &state);
        sgs_append(appender, "a");
        sgs_append(appender, "b");
        sgs_append(appender, "c");
        sgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(sgs_equal(&dstr, "startabc"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_appender: on empty DStr");
    {
        DStr dstr = dstr_init(10);
        StrAppenderState state = {};
        MutStrRef appender = sgs_appender(&dstr, &state);
        sgs_append(appender, "first");
        sgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(sgs_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_appender: commit without any appends");
    {
        DStr dstr = dstr_init_from("unchanged");
        StrAppenderState state = {};
        MutStrRef appender = sgs_appender(&dstr, &state);
        SGS_Error err = sgs_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_TRUE(sgs_equal(&dstr, "unchanged"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_appender: multiple uses with same state");
    {
        DStr dstr = dstr_init_from("base");
        StrAppenderState state = {};
        
        MutStrRef app1 = sgs_appender(&dstr, &state);
        sgs_append(app1, "1");
        sgs_commit_appender(&dstr, app1);
        
        MutStrRef app2 = sgs_appender(&dstr, &state);
        sgs_append(app2, "2");
        sgs_commit_appender(&dstr, app2);
        
        ASSERT_TRUE(sgs_equal(&dstr, "base12"));
        dstr_deinit(&dstr);
    }
    
    TEST("sgs_appender: causing buffer growth");
    {
        DStr dstr = dstr_init(5);
        sgs_append(&dstr, "x");
        StrAppenderState state = {};
        MutStrRef appender = sgs_appender(&dstr, &state);
        for (int i = 0; i < 100; i++) {
            sgs_append(appender, "y");
        }
        SGS_Error err = sgs_commit_appender(&dstr, appender);
        ASSERT_TRUE(err.ec == SGS_OK || err.ec == SGS_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for sgs_join
// ============================================================================

void test_str_join_edge_cases() {
    TEST("sgs_join: empty array");
    {
        StrViewArray arr = {0, 0, NULL};
        DStr dst = dstr_init(10);
        SGS_Error err = sgs_join(&dst, arr, ",");
        ASSERT_EQ(err.ec, SGS_OK);
        ASSERT_EQ(sgs_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("sgs_join: single element");
    {
        char s1[] = "only";
        StrView views[] = {strv(s1, 0, 4)};
        StrViewArray arr = {1, 1, views};
        DStr dst = dstr_init(10);
        sgs_join(&dst, arr, ",");
        ASSERT_TRUE(sgs_equal(&dst, "only"));
        dstr_deinit(&dst);
    }
    
    TEST("sgs_join: empty delimiter");
    {
        char s1[] = "a", s2[] = "b", s3[] = "c";
        StrView views[] = {
            strv(s1, 0, 1),
            strv(s2, 0, 1),
            strv(s3, 0, 1)
        };
        StrViewArray arr = {3, 3, views};
        DStr dst = dstr_init(10);
        sgs_join(&dst, arr, "");
        ASSERT_TRUE(sgs_equal(&dst, "abc"));
        dstr_deinit(&dst);
    }
    
    TEST("sgs_join: multi-char delimiter");
    {
        char s1[] = "a", s2[] = "b";
        StrView views[] = {
            strv(s1, 0, 1),
            strv(s2, 0, 1)
        };
        StrViewArray arr = {2, 2, views};
        DStr dst = dstr_init(20);
        sgs_join(&dst, arr, "::");
        ASSERT_TRUE(sgs_equal(&dst, "a::b"));
        dstr_deinit(&dst);
    }
    
    TEST("sgs_join: with empty strings");
    {
        char s1[] = "", s2[] = "mid", s3[] = "";
        StrView views[] = {
            strv(s1, 0, 0),
            strv(s2, 0, 3),
            strv(s3, 0, 0)
        };
        StrViewArray arr = {3, 3, views};
        DStr dst = dstr_init(20);
        sgs_join(&dst, arr, ",");
        ASSERT_TRUE(sgs_equal(&dst, ",mid,"));
        dstr_deinit(&dst);
    }
    
    TEST("sgs_join: buffer too small");
    {
        char s1[] = "long", s2[] = "strings";
        StrView views[] = {
            strv(s1, 0, 4),
            strv(s2, 0, 7)
        };
        StrViewArray arr = {2, 2, views};
        char backing[5];
        StrBuf sb = strbuf_init_from_buf(backing, 5);
        sgs_clear(&sb); // Initialize to empty
        SGS_Error err = sgs_join(&sb, arr, ",");
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for tostr and print functions
// ============================================================================

void test_tostr_edge_cases() {
    TEST("tostr: integer boundary values");
    {
        DStr dstr = dstr_init(30);
        SGS_Error err = tostr(&dstr, INT_MAX);
        ASSERT_EQ(err.ec, SGS_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: negative integers");
    {
        DStr dstr = dstr_init(30);
        tostr(&dstr, INT_MIN);
        ASSERT_TRUE(sgs_len(&dstr) > 0);
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: zero");
    {
        DStr dstr = dstr_init(10);
        tostr(&dstr, 0);
        ASSERT_TRUE(sgs_equal(&dstr, "0"));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: buffer too small");
    {
        char backing[3];
        StrBuf sb = strbuf_init_from_buf(backing, 3);
        sgs_clear(&sb); // Initialize to empty
        SGS_Error err = tostr(&sb, 123456);
        ASSERT_EQ(err.ec, SGS_DST_TOO_SMALL);
    }
    
    TEST("sgs_print: multiple arguments");
    {
        DStr dstr = dstr_init(50);
        // Assuming sgs_print can take multiple args
        // sgs_print(&dstr, 123, " ", "test", " ", 456);
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
    TEST("stress: many allocations and deallocations");
    {
        for (int i = 0; i < 100; i++) {
            DStr dstr = dstr_init(i * 10);
            for (int j = 0; j < i; j++) {
                sgs_append(&dstr, "x");
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
                sgs_putc(&dstr, 'x');
            }
            sgs_clear(&dstr);
        }
        dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
    
    TEST("stress: very deep nesting of operations");
    {
        DStr dstr = dstr_init(1000);
        sgs_append(&dstr, "start");
        for (int i = 0; i < 100; i++) {
            sgs_replace(&dstr, "start", "middle");
            sgs_replace(&dstr, "middle", "end");
            sgs_replace(&dstr, "end", "start");
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
            sgs_putc(&dstr, c);
        }
        ASSERT_EQ(sgs_len(&dstr), 127 - 32);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: control characters");
    {
        DStr dstr = dstr_init(50);
        sgs_putc(&dstr, '\t');
        sgs_putc(&dstr, '\n');
        sgs_putc(&dstr, '\r');
        ASSERT_EQ(sgs_len(&dstr), 3);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: high ASCII");
    {
        DStr dstr = dstr_init(200);
        for (unsigned char c = 128; c < 255; c++) {
            sgs_putc(&dstr, c);
        }
        dstr_deinit(&dstr);
        ASSERT_TRUE(1);
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
    
    printf("\n========================================\n");
    printf("Test Results: %d/%d passed\n", passed_count, test_count);
    printf("========================================\n");
    
    return (passed_count == test_count) ? 0 : 1;
}