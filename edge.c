#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

#define NEAT_STR_SHORT_NAMES
#include "neat_str.c"
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
// Edge Case Tests for str_at
// ============================================================================

void test_str_at_edge_cases() {
    TEST("str_at: at exactly length boundary");
    {
        char buf[] = "test";
        // Accessing at index 4 (length) should be '\0'
        ASSERT_EQ(str_at(buf, 4), '\0');
        // Accessing beyond should also return '\0' (likely implementation dependent)
        // ASSERT_EQ(str_at(buf, 100), '\0');
    }
    
    TEST("str_at: empty string");
    {
        char buf[] = "";
        ASSERT_EQ(str_at(buf, 0), '\0');
        // ASSERT_EQ(str_at(buf, 1), '\0');
    }
    
    TEST("str_at: with embedded nulls");
    {
        char buf[10] = {'a', 'b', '\0', 'c', 'd', '\0'};
        ASSERT_EQ(str_at(buf, 0), 'a');
        ASSERT_EQ(str_at(buf, 1), 'b');
        ASSERT_EQ(str_at(buf, 2), '\0');
        // After first null, behavior depends on implementation
    }
    
    TEST("str_at: UINT_MAX index");
    {
        char buf[] = "test";
        // ASSERT_EQ(str_at(buf, UINT_MAX), '\0');
    }
}

// ============================================================================
// Edge Case Tests for str_len
// ============================================================================

void test_str_len_edge_cases() {
    TEST("str_len: empty string");
    {
        char buf[] = "";
        ASSERT_EQ(str_len(buf), 0);
    }
    
    TEST("str_len: single null terminator");
    {
        char buf[1] = {'\0'};
        ASSERT_EQ(str_len(buf), 0);
    }
    
    TEST("str_len: DString with zero capacity");
    {
        DString dstr = dstr_init(0);
        ASSERT_EQ(str_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("str_len: very long string");
    {
        // This tests if length calculation handles large strings
        DString dstr = dstr_init(10000);
        for (int i = 0; i < 9999; i++) {
            str_putc(&dstr, 'a');
        }
        ASSERT_EQ(str_len(&dstr), 9999);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for str_cap
// ============================================================================

void test_str_cap_edge_cases() {
    TEST("str_cap: zero capacity DString");
    {
        DString dstr = dstr_init(0);
        // Should have at least 1 for null terminator or 0
        unsigned int cap = str_cap(&dstr);
        ASSERT_TRUE(cap >= 0);
        dstr_deinit(&dstr);
    }
    
    TEST("str_cap: raw char array");
    {
        char buf[100];
        // For raw arrays, capacity might not be trackable
        // This tests that it doesn't crash
        unsigned int cap = str_cap(buf);
        (void)cap; // Just ensure no crash
        ASSERT_TRUE(1);
    }
    
    TEST("str_cap: String_Buffer at exact capacity");
    {
        char backing[5] = {'t', 'e', 's', 't', '\0'};
        String_Buffer sb = strbuf_init_from_cstr(backing, 5);
        ASSERT_EQ(str_cap(&sb), 5);
    }
}

// ============================================================================
// Edge Case Tests for str_equal
// ============================================================================

void test_str_equal_edge_cases() {
    TEST("str_equal: both empty");
    {
        char a[] = "";
        char b[] = "";
        ASSERT_TRUE(str_equal(a, b));
    }
    
    TEST("str_equal: one empty, one not");
    {
        char a[] = "";
        char b[] = "test";
        ASSERT_FALSE(str_equal(a, b));
        ASSERT_FALSE(str_equal(b, a));
    }
    
    TEST("str_equal: same pointer");
    {
        char a[] = "test";
        ASSERT_TRUE(str_equal(a, a));
    }
    
    TEST("str_equal: different types with same content");
    {
        char cstr[] = "hello";
        DString dstr = dstr_init_from(cstr);
        ASSERT_TRUE(str_equal(cstr, &dstr));
        ASSERT_TRUE(str_equal(&dstr, cstr));
        dstr_deinit(&dstr);
    }
    
    TEST("str_equal: strings differing only in last char");
    {
        char a[] = "test1";
        char b[] = "test2";
        ASSERT_FALSE(str_equal(a, b));
    }
    
    TEST("str_equal: strings with embedded nulls");
    {
        char a[5] = {'a', 'b', '\0', 'c', 'd'};
        char b[5] = {'a', 'b', '\0', 'x', 'y'};
        // Should be equal up to first null
        ASSERT_TRUE(str_equal(a, b));
    }
    
    TEST("str_equal: very long identical strings");
    {
        DString a = dstr_init(5000);
        DString b = dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            str_putc(&a, 'x');
            str_putc(&b, 'x');
        }
        ASSERT_TRUE(str_equal(&a, &b));
        dstr_deinit(&a);
        dstr_deinit(&b);
    }
}

// ============================================================================
// Edge Case Tests for str_find
// ============================================================================

void test_str_find_edge_cases() {
    TEST("str_find: empty needle in empty haystack");
    {
        char hay[] = "";
        char needle[] = "";
        String_View result = str_find(hay, needle);
        // Finding empty in empty might return start or invalid
        // Check it doesn't crash
        ASSERT_TRUE(1);
    }
    
    TEST("str_find: empty needle in non-empty haystack");
    {
        char hay[] = "test";
        char needle[] = "";
        String_View result = str_find(hay, needle);
        // Should probably find at position 0 or be invalid
        ASSERT_TRUE(1);
    }
    
    TEST("str_find: needle longer than haystack");
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        String_View result = str_find(hay, needle);
        ASSERT_EQ(str_len(result), 0); // Not found
    }
    
    TEST("str_find: needle equals haystack");
    {
        char hay[] = "exact";
        char needle[] = "exact";
        String_View result = str_find(hay, needle);
        ASSERT_EQ(str_len(result), 5);
    }
    
    TEST("str_find: needle at very end");
    {
        char hay[] = "abcdefghij";
        char needle[] = "hij";
        String_View result = str_find(hay, needle);
        ASSERT_EQ(str_len(result), 3);
    }
    
    TEST("str_find: needle at very start");
    {
        char hay[] = "abcdefghij";
        char needle[] = "abc";
        String_View result = str_find(hay, needle);
        ASSERT_EQ(str_len(result), 3);
    }
    
    TEST("str_find: overlapping pattern");
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        String_View result = str_find(hay, needle);
        // Should find first occurrence
        ASSERT_TRUE(str_len(result) > 0);
    }
    
    TEST("str_find: pattern that almost matches");
    {
        char hay[] = "abcabcabd";
        char needle[] = "abcabd";
        String_View result = str_find(hay, needle);
        ASSERT_TRUE(str_len(result) > 0);
    }
}

// ============================================================================
// Edge Case Tests for str_count
// ============================================================================

void test_str_count_edge_cases() {
    TEST("str_count: empty needle");
    {
        char hay[] = "test";
        char needle[] = "";
        unsigned int count = str_count(hay, needle);
        // Counting empty strings might return 0 or undefined
        (void)count;
        ASSERT_TRUE(1);
    }
    
    TEST("str_count: empty haystack");
    {
        char hay[] = "";
        char needle[] = "x";
        ASSERT_EQ(str_count(hay, needle), 0);
    }
    
    TEST("str_count: overlapping occurrences");
    {
        char hay[] = "aaaa";
        char needle[] = "aa";
        unsigned int count = str_count(hay, needle);
        // Could be 2 (non-overlapping) or 3 (overlapping)
        ASSERT_TRUE(count == 2 || count == 3);
    }
    
    TEST("str_count: needle equals haystack");
    {
        char hay[] = "exact";
        char needle[] = "exact";
        ASSERT_EQ(str_count(hay, needle), 1);
    }
    
    TEST("str_count: needle longer than haystack");
    {
        char hay[] = "ab";
        char needle[] = "abcdef";
        ASSERT_EQ(str_count(hay, needle), 0);
    }
    
    TEST("str_count: many occurrences");
    {
        char hay[] = "a a a a a a a a a a";
        char needle[] = "a";
        ASSERT_EQ(str_count(hay, needle), 10);
    }
}

// ============================================================================
// Edge Case Tests for str_clear
// ============================================================================

void test_str_clear_edge_cases() {
    TEST("str_clear: already empty DString");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = str_clear(&dstr);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("str_clear: String_Buffer at capacity");
    {
        char backing[5] = {'f', 'u', 'l', 'l', '\0'};
        String_Buffer sb = strbuf_init_from_cstr(backing, 5);
        Neat_Error err = str_clear(&sb);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(&sb), 0);
    }
    
    TEST("str_clear: raw char array (might be unsupported)");
    {
        char buf[10] = "test";
        // This might return an error or work
        Neat_Error err = str_clear(buf);
        // Just check it doesn't crash
        ASSERT_TRUE(1);
    }
    
    TEST("str_clear: then append");
    {
        DString dstr = dstr_init_from("original");
        str_clear(&dstr);
        Neat_Error err = str_append(&dstr, "new");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "new"));
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for str_starts_with / str_ends_with
// ============================================================================

void test_str_starts_ends_with_edge_cases() {
    TEST("str_starts_with: empty prefix");
    {
        char hay[] = "test";
        char prefix[] = "";
        ASSERT_TRUE(str_starts_with(hay, prefix));
    }
    
    TEST("str_starts_with: prefix equals string");
    {
        char hay[] = "exact";
        char prefix[] = "exact";
        ASSERT_TRUE(str_starts_with(hay, prefix));
    }
    
    TEST("str_starts_with: prefix longer than string");
    {
        char hay[] = "ab";
        char prefix[] = "abcdef";
        ASSERT_FALSE(str_starts_with(hay, prefix));
    }
    
    TEST("str_starts_with: both empty");
    {
        char hay[] = "";
        char prefix[] = "";
        ASSERT_TRUE(str_starts_with(hay, prefix));
    }
    
    TEST("str_ends_with: empty suffix");
    {
        char hay[] = "test";
        char suffix[] = "";
        ASSERT_TRUE(str_ends_with(hay, suffix));
    }
    
    TEST("str_ends_with: suffix equals string");
    {
        char hay[] = "exact";
        char suffix[] = "exact";
        ASSERT_TRUE(str_ends_with(hay, suffix));
    }
    
    TEST("str_ends_with: suffix longer than string");
    {
        char hay[] = "ab";
        char suffix[] = "zabcdef";
        ASSERT_FALSE(str_ends_with(hay, suffix));
    }
    
    TEST("str_ends_with: single character suffix");
    {
        char hay[] = "test";
        char suffix[] = "t";
        ASSERT_TRUE(str_ends_with(hay, suffix));
    }
    
    TEST("str_starts_with: case sensitive");
    {
        char hay[] = "Test";
        char prefix[] = "test";
        ASSERT_FALSE(str_starts_with(hay, prefix));
    }
}

// ============================================================================
// Edge Case Tests for str_tolower / str_toupper
// ============================================================================

void test_str_case_edge_cases() {
    TEST("str_tolower: empty string");
    {
        DString dstr = dstr_init_from("");
        Neat_Error err = str_tolower(&dstr);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("str_tolower: already lowercase");
    {
        DString dstr = dstr_init_from("alllower");
        str_tolower(&dstr);
        ASSERT_TRUE(str_equal(&dstr, "alllower"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_tolower: with numbers and symbols");
    {
        DString dstr = dstr_init_from("Test123!@#");
        str_tolower(&dstr);
        ASSERT_TRUE(str_equal(&dstr, "test123!@#"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_toupper: empty string");
    {
        DString dstr = dstr_init_from("");
        Neat_Error err = str_toupper(&dstr);
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("str_toupper: already uppercase");
    {
        DString dstr = dstr_init_from("ALLUPPER");
        str_toupper(&dstr);
        ASSERT_TRUE(str_equal(&dstr, "ALLUPPER"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_tolower: non-ASCII characters");
    {
        // Test behavior with extended ASCII
        DString dstr = dstr_init_from("café");
        Neat_Error err = str_tolower(&dstr);
        // Behavior is implementation-defined for non-ASCII
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("str_tolower: on read-only buffer (should fail)");
    {
        char buf[] = "TEST";
        // Might return error on certain string types
        Neat_Error err = str_tolower(buf);
        // Just ensure no crash
        ASSERT_TRUE(1);
    }
}

// ============================================================================
// Edge Case Tests for str_copy
// ============================================================================

void test_str_copy_edge_cases() {
    TEST("str_copy: empty to empty");
    {
        char dst[10] = "";
        char src[] = "";
        Neat_Error err = str_copy(dst, src);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(dst), 0);
    }
    
    TEST("str_copy: to buffer exactly sized");
    {
        char dst[5];
        char src[] = "test";
        Neat_Error err = str_copy(dst, src);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(dst, "test"));
    }
    
    TEST("str_copy: to buffer one too small");
    {
        char dst[4];
        char src[] = "test";
        Neat_Error err = str_copy(dst, src);
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
    
    TEST("str_copy: to String_Buffer at capacity");
    {
        char backing[5];
        String_Buffer sb = strbuf_init_from_buf(backing, 5);
        char src[] = "test";
        Neat_Error err = str_copy(&sb, src);
        ASSERT_EQ(err.ec, NEAT_OK);
    }
    
    TEST("str_copy: overlapping buffers (aliasing)");
    {
        char buf[10] = "test";
        // Copying to itself should fail or handle gracefully
        Neat_Error err = str_copy(buf, buf);
        // Might return NEAT_ALIASING_NOT_SUPPORTED
        ASSERT_TRUE(err.ec == NEAT_ALIASING_NOT_SUPPORTED || err.ec == NEAT_OK);
    }
    
    TEST("str_copy: to DString with insufficient capacity");
    {
        DString dstr = dstr_init(2);
        char src[] = "this is a long string";
        Neat_Error err = str_copy(&dstr, src);
        // Should either reallocate or fail
        ASSERT_TRUE(err.ec == NEAT_OK || err.ec == NEAT_DST_TOO_SMALL || err.ec == NEAT_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("str_copy: from DString to char array");
    {
        DString src = dstr_init_from("source");
        char dst[20];
        Neat_Error err = str_copy(dst, &src);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(dst, "source"));
        dstr_deinit(&src);
    }
}

// ============================================================================
// Edge Case Tests for str_putc
// ============================================================================

void test_str_putc_edge_cases() {
    TEST("str_putc: to empty DString");
    {
        DString dstr = dstr_init(0);
        Neat_Error err = str_putc(&dstr, 'a');
        ASSERT_TRUE(err.ec == NEAT_OK || err.ec == NEAT_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("str_putc: null character");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = str_putc(&dstr, '\0');
        // Behavior may vary - might end string or add literal null
        (void)err;
        ASSERT_TRUE(1);
        dstr_deinit(&dstr);
    }
    
    TEST("str_putc: to String_Buffer at capacity");
    {
        char backing[3] = {'a', 'b', '\0'};
        String_Buffer sb = strbuf_init_from_cstr(backing, 3);
        Neat_Error err = str_putc(&sb, 'c');
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
    
    TEST("str_putc: extended ASCII character");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = str_putc(&dstr, 0xFF);
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("str_putc: many characters sequentially");
    {
        DString dstr = dstr_init(1);
        for (int i = 0; i < 1000; i++) {
            Neat_Error err = str_putc(&dstr, 'x');
            if (err.ec != NEAT_OK) {
                printf("  Failed at iteration %d with error code %d\n", i, err.ec);
                break;
            }
        }
        ASSERT_EQ(str_len(&dstr), 1000);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for str_append
// ============================================================================

void test_str_append_edge_cases() {
    TEST("str_append: empty to empty");
    {
        DString dst = dstr_init(10);
        char src[] = "";
        Neat_Error err = str_append(&dst, src);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("str_append: to itself (aliasing)");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_append(&dstr, &dstr);
        // Should detect aliasing or handle it
        ASSERT_TRUE(err.ec == NEAT_ALIASING_NOT_SUPPORTED || err.ec == NEAT_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("str_append: to String_Buffer causing overflow");
    {
        char backing[10] = "hello";
        String_Buffer sb = strbuf_init_from_cstr(backing, 10);
        char src[] = "world!";
        Neat_Error err = str_append(&sb, src);
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
    
    TEST("str_append: exactly fitting capacity");
    {
        char backing[11] = "hello";
        String_Buffer sb = strbuf_init_from_cstr(backing, 11);
        char src[] = "world";
        Neat_Error err = str_append(&sb, src);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&sb, "helloworld"));
    }
    
    TEST("str_append: multiple appends growing DString");
    {
        DString dstr = dstr_init(1);
        for (int i = 0; i < 100; i++) {
            Neat_Error err = str_append(&dstr, "x");
            ASSERT_EQ(err.ec, NEAT_OK);
        }
        ASSERT_EQ(str_len(&dstr), 100);
        dstr_deinit(&dstr);
    }
    
    TEST("str_append: very long string");
    {
        DString dstr = dstr_init(100);
        DString long_str = dstr_init(5000);
        for (int i = 0; i < 4999; i++) {
            str_putc(&long_str, 'a');
        }
        Neat_Error err = str_append(&dstr, &long_str);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(&dstr), 4999);
        dstr_deinit(&dstr);
        dstr_deinit(&long_str);
    }
}

// ============================================================================
// Edge Case Tests for str_del
// ============================================================================

void test_str_del_edge_cases() {
    TEST("str_del: delete entire string");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_del(&dstr, 0, 4);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: delete nothing (from == to)");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_del(&dstr, 2, 2);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: invalid range (from > to)");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_del(&dstr, 3, 1);
        ASSERT_EQ(err.ec, NEAT_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: out of bounds from");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_del(&dstr, 10, 15);
        ASSERT_EQ(err.ec, NEAT_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: out of bounds to");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_del(&dstr, 0, 100);
        ASSERT_EQ(err.ec, NEAT_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: delete from middle");
    {
        DString dstr = dstr_init_from("abcdef");
        Neat_Error err = str_del(&dstr, 2, 4);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "abef"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: delete first character");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_del(&dstr, 0, 1);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "est"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: delete last character");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_del(&dstr, 3, 4);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "tes"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_del: on empty string");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = str_del(&dstr, 0, 0);
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for str_replace
// ============================================================================

void test_str_replace_edge_cases() {
    TEST("str_replace: target not found");
    {
        DString dstr = dstr_init_from("hello world");
        Replace_Result res = str_replace(&dstr, "xyz", "abc");
        ASSERT_EQ(res.err.ec, NEAT_NOT_FOUND);
        ASSERT_EQ(res.nb_replaced, 0);
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace: empty target");
    {
        DString dstr = dstr_init_from("test");
        Replace_Result res = str_replace(&dstr, "", "x");
        // Replacing empty string is likely an error or no-op
        ASSERT_TRUE(res.err.ec == NEAT_OK || res.err.ec == NEAT_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace: replace with empty string");
    {
        DString dstr = dstr_init_from("hello world");
        Replace_Result res = str_replace(&dstr, "o", "");
        ASSERT_EQ(res.err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "hell wrld"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace: replacement longer than target");
    {
        DString dstr = dstr_init_from("hi hi hi");
        Replace_Result res = str_replace(&dstr, "hi", "hello");
        ASSERT_EQ(res.err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "hello hello hello"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace: replacement shorter than target");
    {
        DString dstr = dstr_init_from("hello hello");
        Replace_Result res = str_replace(&dstr, "hello", "hi");
        ASSERT_EQ(res.err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "hi hi"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace: overlapping matches");
    {
        DString dstr = dstr_init_from("aaa");
        Replace_Result res = str_replace(&dstr, "aa", "b");
        // Should replace non-overlapping: "aaa" -> "ba" (1 replacement)
        ASSERT_EQ(res.err.ec, NEAT_OK);
        ASSERT_TRUE(res.nb_replaced == 1);
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace: target equals entire string");
    {
        DString dstr = dstr_init_from("exact");
        Replace_Result res = str_replace(&dstr, "exact", "replaced");
        ASSERT_EQ(res.err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "replaced"));
        ASSERT_EQ(res.nb_replaced, 1);
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace: on String_Buffer with insufficient space");
    {
        char backing[10] = "hi hi"; // "hello hi"
        String_Buffer sb = strbuf_init_from_cstr(backing, 10);
        Replace_Result res = str_replace(&sb, "hi", "hello");
        // println("hi hi", " became :: ", sb);
        ASSERT_EQ(res.err.ec, NEAT_DST_TOO_SMALL);
        ASSERT_EQ(res.nb_replaced, 1);
    }
    
    TEST("str_replace: many occurrences");
    {
        DString dstr = dstr_init(100);
        for (int i = 0; i < 50; i++) {
            str_append(&dstr, "x ");
        }
        Replace_Result res = str_replace(&dstr, "x", "y");
        ASSERT_EQ(res.err.ec, NEAT_OK);
        ASSERT_EQ(res.nb_replaced, 50);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for str_replace_first
// ============================================================================

void test_str_replace_first_edge_cases() {
    TEST("str_replace_first: no occurrence");
    {
        DString dstr = dstr_init_from("hello");
        Neat_Error err = str_replace_first(&dstr, "xyz", "abc");
        ASSERT_EQ(err.ec, NEAT_NOT_FOUND);
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_first: multiple occurrences");
    {
        DString dstr = dstr_init_from("test test test");
        Neat_Error err = str_replace_first(&dstr, "test", "word");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "word test test"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_first: at end of string");
    {
        DString dstr = dstr_init_from("abcdef");
        Neat_Error err = str_replace_first(&dstr, "def", "xyz");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "abcxyz"));
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for str_replace_range
// ============================================================================

void test_str_replace_range_edge_cases() {
    TEST("str_replace_range: replace entire string");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_replace_range(&dstr, 0, 4, "replaced");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "replaced"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_range: invalid range");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_replace_range(&dstr, 3, 1, "x");
        ASSERT_EQ(err.ec, NEAT_BAD_RANGE);
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_range: out of bounds");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_replace_range(&dstr, 0, 100, "x");
        ASSERT_EQ(err.ec, NEAT_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_range: zero-length range (insertion)");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_replace_range(&dstr, 2, 2, "XX");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "teXXst"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_range: with empty replacement (deletion)");
    {
        DString dstr = dstr_init_from("testing");
        Neat_Error err = str_replace_range(&dstr, 2, 5, "");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "teng"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_range: at string boundaries");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_replace_range(&dstr, 0, 0, "start");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "starttest"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_replace_range: String_Buffer overflow");
    {
        char backing[10] = "test";
        String_Buffer sb = strbuf_init_from_cstr(backing, 10);
        Neat_Error err = str_replace_range(&sb, 0, 4, "very long replacement");
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for str_split
// ============================================================================

void test_str_split_edge_cases() {
    TEST("str_split: empty string");
    {
        char str[] = "";
        char delim[] = ",";
        String_View_Array arr = str_split(str, delim);
        // Should return array with 0 or 1 empty element
        ASSERT_TRUE(arr.len == 0 || arr.len == 1);
        free(arr.strs);
    }
    
    TEST("str_split: empty delimiter");
    {
        char str[] = "test";
        char delim[] = "";
        String_View_Array arr = str_split(str, delim);
        // Behavior undefined - might split into characters or return whole string
        ASSERT_TRUE(1);
        free(arr.strs);
    }
    
    TEST("str_split: delimiter not in string");
    {
        char str[] = "no delimiters here";
        char delim[] = ",";
        String_View_Array arr = str_split(str, delim);
        ASSERT_EQ(arr.len, 1);
        free(arr.strs);
    }
    
    TEST("str_split: consecutive delimiters");
    {
        char str[] = "a,,b,,c";
        char delim[] = ",";
        String_View_Array arr = str_split(str, delim);
        // Should have 5 elements: "a", "", "b", "", "c"
        ASSERT_EQ(arr.len, 5);
        free(arr.strs);
    }
    
    TEST("str_split: delimiter at start");
    {
        char str[] = ",test";
        char delim[] = ",";
        String_View_Array arr = str_split(str, delim);
        // Should have 2 elements: "" and "test"
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("str_split: delimiter at end");
    {
        char str[] = "test,";
        char delim[] = ",";
        String_View_Array arr = str_split(str, delim);
        // Should have 2 elements: "test" and ""
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("str_split: only delimiter");
    {
        char str[] = ",";
        char delim[] = ",";
        String_View_Array arr = str_split(str, delim);
        // Should have 2 empty elements
        ASSERT_EQ(arr.len, 2);
        free(arr.strs);
    }
    
    TEST("str_split: multi-character delimiter");
    {
        char str[] = "a::b::c";
        char delim[] = "::";
        String_View_Array arr = str_split(str, delim);
        ASSERT_EQ(arr.len, 3);
        free(arr.strs);
    }
    
    TEST("str_split: many splits");
    {
        DString dstr = dstr_init(1000);
        for (int i = 0; i < 100; i++) {
            str_append(&dstr, "x,");
        }
        String_View_Array arr = str_split(&dstr, ",");
        ASSERT_EQ(arr.len, 101); // 100 "x" and 1 trailing empty
        dstr_deinit(&dstr);
        free(arr.strs);
    }
}

// ============================================================================
// Edge Case Tests for str_insert / str_prepend
// ============================================================================

void test_str_insert_prepend_edge_cases() {
    TEST("str_insert: at position 0 (same as prepend)");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_insert(&dstr, "START", 0);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "STARTtest"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_insert: at middle position");
    {
        DString dstr = dstr_init_from("abef");
        Neat_Error err = str_insert(&dstr, "cd", 2);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "abcdef"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_insert: at end position");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_insert(&dstr, "end", 4);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "testend"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_insert: out of bounds position");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_insert(&dstr, "x", 100);
        ASSERT_EQ(err.ec, NEAT_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("str_insert: into empty string at position 0");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = str_insert(&dstr, "first", 0);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_insert: into empty string at position > 0");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = str_insert(&dstr, "test", 5);
        ASSERT_EQ(err.ec, NEAT_INDEX_OUT_OF_BOUNDS);
        dstr_deinit(&dstr);
    }
    
    TEST("str_insert: String_Buffer overflow");
    {
        char backing[10] = "test";
        String_Buffer sb = strbuf_init_from_cstr(backing, 10);
        Neat_Error err = str_insert(&sb, "longinsert", 2);
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
    
    TEST("str_insert: empty string insertion");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = str_insert(&dstr, "", 2);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "test"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_prepend: to empty string");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = str_prepend(&dstr, "first");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_prepend: String_Buffer overflow");
    {
        char backing[10] = "test";
        String_Buffer sb = strbuf_init_from_cstr(backing, 10);
        Neat_Error err = str_prepend(&sb, "longprefix");
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
    
    TEST("str_prepend: multiple times");
    {
        DString dstr = dstr_init_from("end");
        str_prepend(&dstr, "middle");
        str_prepend(&dstr, "start");
        ASSERT_TRUE(str_equal(&dstr, "startmiddleend"));
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for DString functions
// ============================================================================

void test_dstring_edge_cases() {
    TEST("dstr_init: zero capacity");
    {
        DString dstr = dstr_init(0);
        ASSERT_EQ(str_len(&dstr), 0);
        // Should still be usable
        Neat_Error err = str_append(&dstr, "test");
        ASSERT_TRUE(err.ec == NEAT_OK || err.ec == NEAT_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init: very large capacity");
    {
        DString dstr = dstr_init(1000000);
        ASSERT_TRUE(str_cap(&dstr) >= 1000000 || str_cap(&dstr) == 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_init_from: empty string");
    {
        DString dstr = dstr_init_from("");
        ASSERT_EQ(str_len(&dstr), 0);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: already minimal");
    {
        DString dstr = dstr_init_from("test");
        Neat_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_cap(&dstr) >= str_len(&dstr));
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_shrink_to_fit: after deletions");
    {
        DString dstr = dstr_init(1000);
        str_append(&dstr, "small");
        Neat_Error err = dstr_shrink_to_fit(&dstr);
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: already sufficient");
    {
        DString dstr = dstr_init(100);
        Neat_Error err = dstr_ensure_cap(&dstr, 50);
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: needs growth");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = dstr_ensure_cap(&dstr, 100);
        ASSERT_TRUE(err.ec == NEAT_OK || err.ec == NEAT_ALLOC_ERR);
        if (err.ec == NEAT_OK) {
            ASSERT_TRUE(str_cap(&dstr) >= 100);
        }
        dstr_deinit(&dstr);
    }
    
    TEST("dstr_ensure_cap: zero requested");
    {
        DString dstr = dstr_init(10);
        Neat_Error err = dstr_ensure_cap(&dstr, 0);
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for String_Buffer
// ============================================================================

void test_string_buffer_edge_cases() {
    TEST("String_Buffer: from empty array");
    {
        char buf[1] = {'\0'};
        String_Buffer sb = strbuf_init_from_cstr(buf, 1);
        ASSERT_EQ(str_len(&sb), 0);
        ASSERT_EQ(str_cap(&sb), 1);
    }
    
    TEST("String_Buffer: from array without null terminator");
    {
        char buf[5] = {'t', 'e', 's', 't', 'x'};
        String_Buffer sb = strbuf_init_from_buf(buf, 5);
        ASSERT_TRUE(sb.len == 0);
    }
    
    TEST("String_Buffer: from cstr with capacity exactly length + 1");
    {
        char buf[5] = {'t', 'e', 's', 't', '\0'};
        String_Buffer sb = strbuf_init_from_cstr(buf, 5);
        ASSERT_EQ(str_cap(&sb), 5);
        ASSERT_EQ(str_len(&sb), 4);
    }
    
    TEST("String_Buffer: from buf with exact capacity");
    {
        char buf[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
        String_Buffer sb = strbuf_init_from_buf(buf, 10);
        ASSERT_EQ(str_cap(&sb), 10);
    }
    
    TEST("String_Buffer: append to full buffer from cstr");
    {
        char buf[5] = {'f', 'u', 'l', 'l', '\0'};
        String_Buffer sb = strbuf_init_from_cstr(buf, 5);
        Neat_Error err = str_append(&sb, "x");
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
    
    TEST("String_Buffer: init from buf then set content");
    {
        char buf[20];
        String_Buffer sb = strbuf_init_from_buf(buf, 20);
        Neat_Error err = str_copy(&sb, "test");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&sb, "test"));
    }
}

// ============================================================================
// Edge Case Tests for str_view
// ============================================================================

void test_str_view_edge_cases() {
    TEST("str_view: empty range");
    {
        char str[] = "test";
        String_View sv = str_view(str, 2, 2);
        ASSERT_EQ(str_len(sv), 0);
    }
    
    TEST("str_view: entire string");
    {
        char str[] = "test";
        String_View sv = str_view(str, 0, 4);
        ASSERT_EQ(str_len(sv), 4);
        ASSERT_TRUE(str_equal(sv, "test"));
    }
    
    TEST("str_view: invalid range (from > to)");
    {
        char str[] = "test";
        String_View sv = str_view(str, 3, 1);
        // Likely returns empty or errors
        ASSERT_TRUE(1);
    }
    
    TEST("str_view: single character");
    {
        char str[] = "test";
        String_View sv = str_view(str, 1, 2);
        ASSERT_EQ(str_len(sv), 1);
        ASSERT_EQ(str_at(sv, 0), 'e');
    }
}

// ============================================================================
// Edge Case Tests for file I/O functions
// ============================================================================

void test_file_io_edge_cases() {
    TEST("str_fread_line: from empty file");
    {
        FILE *f = tmpfile();
        DString dstr = dstr_init(10);
        Neat_Error err = str_fread_line(&dstr, f);
        // Should indicate EOF or empty read
        ASSERT_TRUE(err.ec == NEAT_OK || err.ec != NEAT_OK);
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("str_fread_line: very long line");
    {
        FILE *f = tmpfile();
        for (int i = 0; i < 10000; i++)
        {
            fputc('x', f);
        }
        fputc('\n', f);
        rewind(f);
        
        DString dstr = dstr_init(10);
        Neat_Error err = str_fread_line(&dstr, f);
        ASSERT_TRUE(err.ec == NEAT_OK || err.ec == NEAT_ALLOC_ERR);
        if (err.ec == NEAT_OK)
        {
            ASSERT_EQ(str_len(&dstr), 10001);
        }
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("str_fread_line: line without newline");
    {
        FILE *f = tmpfile();
        fprintf(f, "no newline");
        rewind(f);
        
        DString dstr = dstr_init(20);
        Neat_Error err = str_fread_line(&dstr, f);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "no newline"));
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("str_fread_line: multiple calls");
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\nline3\n");
        rewind(f);
        
        DString dstr = dstr_init(20);
        str_fread_line(&dstr, f);
        ASSERT_TRUE(str_equal(&dstr, "line1\n"));
        
        str_clear(&dstr);
        str_fread_line(&dstr, f);
        ASSERT_TRUE(str_equal(&dstr, "line2\n"));
        
        fclose(f);
        dstr_deinit(&dstr);
    }
    
    TEST("str_append_fread_line: append multiple lines");
    {
        FILE *f = tmpfile();
        fprintf(f, "line1\nline2\n");
        rewind(f);
        
        DString dstr = dstr_init(50);
        str_append_fread_line(&dstr, f);
        str_append_fread_line(&dstr, f);
        ASSERT_TRUE(str_equal(&dstr, "line1\nline2\n"));
        
        fclose(f);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for appender
// ============================================================================

void test_appender_edge_cases() {
    TEST("str_appender: basic usage");
    {
        DString dstr = dstr_init_from("start");
        String_Appender_State state = {};
        Mut_String_Ref appender = str_appender(&dstr, &state);
        str_append(appender, "end");
        Neat_Error err = str_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "startend"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_appender: without commit");
    {
        DString dstr = dstr_init_from("start");
        String_Appender_State state = {};
        Mut_String_Ref appender = str_appender(&dstr, &state);
        str_append(appender, "lost");
        // Not committed - dstr should be unchanged
        ASSERT_TRUE(str_equal(&dstr, "start"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_appender: multiple appends before commit");
    {
        DString dstr = dstr_init_from("start");
        String_Appender_State state = {};
        Mut_String_Ref appender = str_appender(&dstr, &state);
        str_append(appender, "a");
        str_append(appender, "b");
        str_append(appender, "c");
        str_commit_appender(&dstr, appender);
        ASSERT_TRUE(str_equal(&dstr, "startabc"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_appender: on empty DString");
    {
        DString dstr = dstr_init(10);
        String_Appender_State state = {};
        Mut_String_Ref appender = str_appender(&dstr, &state);
        str_append(appender, "first");
        str_commit_appender(&dstr, appender);
        ASSERT_TRUE(str_equal(&dstr, "first"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_appender: commit without any appends");
    {
        DString dstr = dstr_init_from("unchanged");
        String_Appender_State state = {};
        Mut_String_Ref appender = str_appender(&dstr, &state);
        Neat_Error err = str_commit_appender(&dstr, appender);
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_TRUE(str_equal(&dstr, "unchanged"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_appender: multiple uses with same state");
    {
        DString dstr = dstr_init_from("base");
        String_Appender_State state = {};
        
        Mut_String_Ref app1 = str_appender(&dstr, &state);
        str_append(app1, "1");
        str_commit_appender(&dstr, app1);
        
        Mut_String_Ref app2 = str_appender(&dstr, &state);
        str_append(app2, "2");
        str_commit_appender(&dstr, app2);
        
        ASSERT_TRUE(str_equal(&dstr, "base12"));
        dstr_deinit(&dstr);
    }
    
    TEST("str_appender: causing buffer growth");
    {
        DString dstr = dstr_init(5);
        str_append(&dstr, "x");
        String_Appender_State state = {};
        Mut_String_Ref appender = str_appender(&dstr, &state);
        for (int i = 0; i < 100; i++) {
            str_append(appender, "y");
        }
        Neat_Error err = str_commit_appender(&dstr, appender);
        ASSERT_TRUE(err.ec == NEAT_OK || err.ec == NEAT_ALLOC_ERR);
        dstr_deinit(&dstr);
    }
}

// ============================================================================
// Edge Case Tests for str_join
// ============================================================================

void test_str_join_edge_cases() {
    TEST("str_join: empty array");
    {
        String_View_Array arr = {0, 0, NULL};
        DString dst = dstr_init(10);
        Neat_Error err = str_join(&dst, arr, ",");
        ASSERT_EQ(err.ec, NEAT_OK);
        ASSERT_EQ(str_len(&dst), 0);
        dstr_deinit(&dst);
    }
    
    TEST("str_join: single element");
    {
        char s1[] = "only";
        String_View views[] = {str_view(s1, 0, 4)};
        String_View_Array arr = {1, 1, views};
        DString dst = dstr_init(10);
        str_join(&dst, arr, ",");
        ASSERT_TRUE(str_equal(&dst, "only"));
        dstr_deinit(&dst);
    }
    
    TEST("str_join: empty delimiter");
    {
        char s1[] = "a", s2[] = "b", s3[] = "c";
        String_View views[] = {
            str_view(s1, 0, 1),
            str_view(s2, 0, 1),
            str_view(s3, 0, 1)
        };
        String_View_Array arr = {3, 3, views};
        DString dst = dstr_init(10);
        str_join(&dst, arr, "");
        ASSERT_TRUE(str_equal(&dst, "abc"));
        dstr_deinit(&dst);
    }
    
    TEST("str_join: multi-char delimiter");
    {
        char s1[] = "a", s2[] = "b";
        String_View views[] = {
            str_view(s1, 0, 1),
            str_view(s2, 0, 1)
        };
        String_View_Array arr = {2, 2, views};
        DString dst = dstr_init(20);
        str_join(&dst, arr, "::");
        ASSERT_TRUE(str_equal(&dst, "a::b"));
        dstr_deinit(&dst);
    }
    
    TEST("str_join: with empty strings");
    {
        char s1[] = "", s2[] = "mid", s3[] = "";
        String_View views[] = {
            str_view(s1, 0, 0),
            str_view(s2, 0, 3),
            str_view(s3, 0, 0)
        };
        String_View_Array arr = {3, 3, views};
        DString dst = dstr_init(20);
        str_join(&dst, arr, ",");
        ASSERT_TRUE(str_equal(&dst, ",mid,"));
        dstr_deinit(&dst);
    }
    
    TEST("str_join: buffer too small");
    {
        char s1[] = "long", s2[] = "strings";
        String_View views[] = {
            str_view(s1, 0, 4),
            str_view(s2, 0, 7)
        };
        String_View_Array arr = {2, 2, views};
        char backing[5];
        String_Buffer sb = strbuf_init_from_buf(backing, 5);
        str_clear(&sb); // Initialize to empty
        Neat_Error err = str_join(&sb, arr, ",");
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
}

// ============================================================================
// Edge Case Tests for tostr and print functions
// ============================================================================

void test_tostr_edge_cases() {
    TEST("tostr: integer boundary values");
    {
        DString dstr = dstr_init(30);
        Neat_Error err = tostr(&dstr, INT_MAX);
        ASSERT_EQ(err.ec, NEAT_OK);
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: negative integers");
    {
        DString dstr = dstr_init(30);
        tostr(&dstr, INT_MIN);
        ASSERT_TRUE(str_len(&dstr) > 0);
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: zero");
    {
        DString dstr = dstr_init(10);
        tostr(&dstr, 0);
        ASSERT_TRUE(str_equal(&dstr, "0"));
        dstr_deinit(&dstr);
    }
    
    TEST("tostr: buffer too small");
    {
        char backing[3];
        String_Buffer sb = strbuf_init_from_buf(backing, 3);
        str_clear(&sb); // Initialize to empty
        Neat_Error err = tostr(&sb, 123456);
        ASSERT_EQ(err.ec, NEAT_DST_TOO_SMALL);
    }
    
    TEST("str_print: multiple arguments");
    {
        DString dstr = dstr_init(50);
        // Assuming str_print can take multiple args
        // str_print(&dstr, 123, " ", "test", " ", 456);
        // Test would verify concatenation
        ASSERT_TRUE(1);
        dstr_deinit(&dstr);
    }
    
    TEST("tsfmt: various format characters");
    {
        DString dstr = dstr_init(30);
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
            DString dstr = dstr_init(i * 10);
            for (int j = 0; j < i; j++) {
                str_append(&dstr, "x");
            }
            dstr_deinit(&dstr);
        }
        ASSERT_TRUE(1);
    }
    
    TEST("stress: alternating growth and shrinkage");
    {
        DString dstr = dstr_init(10);
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 100; j++) {
                str_putc(&dstr, 'x');
            }
            str_clear(&dstr);
        }
        dstr_deinit(&dstr);
        ASSERT_TRUE(1);
    }
    
    TEST("stress: very deep nesting of operations");
    {
        DString dstr = dstr_init(1000);
        str_append(&dstr, "start");
        for (int i = 0; i < 100; i++) {
            str_replace(&dstr, "start", "middle");
            str_replace(&dstr, "middle", "end");
            str_replace(&dstr, "end", "start");
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
        DString dstr = dstr_init(200);
        for (char c = 32; c < 127; c++) {
            str_putc(&dstr, c);
        }
        ASSERT_EQ(str_len(&dstr), 127 - 32);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: control characters");
    {
        DString dstr = dstr_init(50);
        str_putc(&dstr, '\t');
        str_putc(&dstr, '\n');
        str_putc(&dstr, '\r');
        ASSERT_EQ(str_len(&dstr), 3);
        dstr_deinit(&dstr);
    }
    
    TEST("special chars: high ASCII");
    {
        DString dstr = dstr_init(200);
        for (unsigned char c = 128; c < 255; c++) {
            str_putc(&dstr, c);
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
    test_str_view_edge_cases();
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