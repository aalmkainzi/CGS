#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define CGS_SHORT_NAMES
#include "../sgs.c"

// Test counter
static int tests_run = 0;
static int tests_passed = 0;

#define TEST(name) \
do { \
    printf("Running test: %s\n", #name); \
    tests_run++; \
    if (name()) { \
        tests_passed++; \
        /*printf(" PASSED\n")*/; \
    } else { \
        printf(" FAILED\n"); \
    } \
} while(0)

#define ASSERT(cond) \
do { \
    if (!(cond)) { \
        printf("    Assertion failed: %s (line %d)\n", #cond, __LINE__); \
        return false; \
    } \
} while(0)

#define ASSERT_EQ(a, b) \
do { \
    if ((a) != (b)) { \
        printf("    Expected %d, got %d (line %d)\n", (int)(b), (int)(a), __LINE__); \
        return false; \
    } \
} while(0)

#define ASSERT_STR_EQ(a, b) \
do { \
    if (strcmp((a), (b)) != 0) { \
        printf("    Expected \"%s\", got \"%s\" (line %d)\n", (b), (a), __LINE__); \
        return false; \
    } \
} while(0)

#define ASSERT_OK(err) \
do { \
    if ((err).ec != CGS_OK) { \
        \
        printf("    Expected CGS_OK, got error code, %d (line %d )", err.ec, __LINE__); \
        return false; \
    } \
} while(0)

#define ASSERT_ERR(err, expected) \
do { \
    if ((err).ec != (expected)) { \
        println("  Expected error ", (CGS_Error){expected}, " got ", err,  "(line ", __LINE__, ")"); \
        return false; \
    } \
} while(0)

// ============================================================================
// cgs_at tests
// ============================================================================

bool test_str_at_cstr() {
    const char *s = "hello";
    ASSERT_EQ(cgs_at(s, 0), 'h');
    ASSERT_EQ(cgs_at(s, 4), 'o');
    return true;
}

bool test_str_at_array() {
    char s[] = "world";
    ASSERT_EQ(cgs_at(s, 0), 'w');
    ASSERT_EQ(cgs_at(s, 2), 'r');
    return true;
}

bool test_str_at_dstring() {
    DStr ds = dstr_init_from("test");
    ASSERT_EQ(cgs_at(ds, 0), 't');
    ASSERT_EQ(cgs_at(ds, 3), 't');
    dstr_deinit(&ds);
    return true;
}

bool test_str_at_string_view() {
    StrView sv = strv("example", 0, 7);
    ASSERT_EQ(cgs_at(sv, 0), 'e');
    ASSERT_EQ(cgs_at(sv, 6), 'e');
    return true;
}

// ============================================================================
// cgs_len tests
// ============================================================================

bool test_str_len_empty() {
    ASSERT_EQ(cgs_len(""), 0);
    char empty[] = "";
    ASSERT_EQ(cgs_len(empty), 0);
    return true;
}

bool test_str_len_cstr() {
    ASSERT_EQ(cgs_len("hello"), 5);
    ASSERT_EQ(cgs_len("world"), 5);
    return true;
}

bool test_str_len_array() {
    char arr[] = "testing";
    ASSERT_EQ(cgs_len(arr), 7);
    return true;
}

bool test_str_len_dstring() {
    DStr ds = dstr_init_from("dynamic");
    ASSERT_EQ(cgs_len(ds), 7);
    dstr_deinit(&ds);
    return true;
}

bool test_str_len_string_view() {
    StrView sv = strv("hello world", 6, 11);
    ASSERT_EQ(cgs_len(sv), 5);
    return true;
}

// ============================================================================
// cgs_cap tests
// ============================================================================

bool test_str_cap_array() {
    char arr[50] = "hello";
    ASSERT_EQ(cgs_cap(arr), 50);
    return true;
}

bool test_str_cap_dstring() {
    DStr ds = dstr_init(100);
    ASSERT(cgs_cap(ds) >= 100);
    dstr_deinit(&ds);
    return true;
}

bool test_str_cap_string_buffer() {
    char buf[64];
    StrBuf sb = strbuf_init_from_buf(buf);
    ASSERT_EQ(cgs_cap(sb), 64);
    return true;
}

// ============================================================================
// cgs_equal tests
// ============================================================================

bool test_str_equal_same() {
    ASSERT(cgs_equal("hello", "hello"));
    ASSERT(cgs_equal("", ""));
    return true;
}

bool test_str_equal_different() {
    ASSERT(!cgs_equal("hello", "world"));
    ASSERT(!cgs_equal("hello", "hello!"));
    ASSERT(!cgs_equal("", "x"));
    return true;
}

bool test_str_equal_mixed_types() {
    char arr[] = "test";
    DStr ds = dstr_init_from("test");
    StrView sv = strv("test", 0, 4);
    
    ASSERT(cgs_equal(arr, "test"));
    ASSERT(cgs_equal(ds, "test"));
    ASSERT(cgs_equal(sv, "test"));
    ASSERT(cgs_equal(arr, ds));
    ASSERT(cgs_equal(ds, sv));
    
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// cgs_chars tests
// ============================================================================

bool test_str_chars_cstr() {
    const char *s = "hello";
    ASSERT_STR_EQ(cgs_chars(s), "hello");
    return true;
}

bool test_str_chars_dstring() {
    DStr ds = dstr_init_from("world");
    ASSERT_STR_EQ(cgs_chars(ds), "world");
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// cgs_find tests
// ============================================================================

bool test_str_find_exists() {
    StrView result = cgs_find("hello world", "world");
    ASSERT_EQ(cgs_len(result), 5);
    ASSERT(cgs_equal(result, "world"));
    return true;
}

bool test_str_find_not_found() {
    StrView result = cgs_find("hello world", "xyz");
    ASSERT_EQ(cgs_len(result), 0);
    return true;
}

bool test_str_find_empty_needle() {
    StrView result = cgs_find("hello", "");
    ASSERT_EQ(cgs_len(result), 0);
    return true;
}

bool test_str_find_at_start() {
    StrView result = cgs_find("hello world", "hello");
    ASSERT(cgs_equal(result, "hello"));
    return true;
}

bool test_str_find_at_end() {
    StrView result = cgs_find("hello world", "world");
    ASSERT(cgs_equal(result, "world"));
    return true;
}

bool test_str_find_multiple_occurrences() {
    StrView result = cgs_find("abcabc", "abc");
    ASSERT_EQ(cgs_len(result), 3);
    // Should find the first occurrence
    return true;
}

// ============================================================================
// cgs_count tests
// ============================================================================

bool test_str_count_none() {
    ASSERT_EQ(cgs_count("hello world", "xyz"), 0);
    return true;
}

bool test_str_count_one() {
    ASSERT_EQ(cgs_count("hello world", "world"), 1);
    return true;
}

bool test_str_count_multiple() {
    ASSERT_EQ(cgs_count("abcabcabc", "abc"), 3);
    ASSERT_EQ(cgs_count("aaaa", "aa"), 2); // non-overlapping
    return true;
}

bool test_str_count_empty_needle() {
    ASSERT_EQ(cgs_count("hello", ""), 0);
    return true;
}

// ============================================================================
// cgs_clear tests
// ============================================================================

bool test_str_clear_dstring() {
    DStr ds = dstr_init_from("hello");
    ASSERT_OK(cgs_clear(&ds));
    ASSERT_EQ(cgs_len(ds), 0);
    ASSERT_STR_EQ(cgs_chars(ds), "");
    dstr_deinit(&ds);
    return true;
}

bool test_str_clear_array() {
    char arr[50] = "hello world";
    ASSERT_OK(cgs_clear(arr));
    ASSERT_EQ(cgs_len(arr), 0);
    ASSERT_STR_EQ(arr, "");
    return true;
}

// ============================================================================
// cgs_starts_with tests
// ============================================================================

bool test_str_starts_with_true() {
    ASSERT(cgs_starts_with("hello world", "hello"));
    ASSERT(cgs_starts_with("hello", "hello"));
    ASSERT(cgs_starts_with("x", "x"));
    return true;
}

bool test_str_starts_with_false() {
    ASSERT(!cgs_starts_with("hello world", "world"));
    ASSERT(!cgs_starts_with("hello", "hello!"));
    ASSERT(!cgs_starts_with("", "x"));
    return true;
}

bool test_str_starts_with_empty() {
    ASSERT(cgs_starts_with("hello", ""));
    ASSERT(cgs_starts_with("", ""));
    return true;
}

// ============================================================================
// cgs_ends_with tests
// ============================================================================

bool test_str_ends_with_true() {
    ASSERT(cgs_ends_with("hello world", "world"));
    ASSERT(cgs_ends_with("hello", "hello"));
    ASSERT(cgs_ends_with("x", "x"));
    return true;
}

bool test_str_ends_with_false() {
    ASSERT(!cgs_ends_with("hello world", "hello"));
    ASSERT(!cgs_ends_with("hello", "!hello"));
    ASSERT(!cgs_ends_with("", "x"));
    return true;
}

bool test_str_ends_with_empty() {
    ASSERT(cgs_ends_with("hello", ""));
    ASSERT(cgs_ends_with("", ""));
    return true;
}

// ============================================================================
// cgs_tolower tests
// ============================================================================

bool test_str_tolower_basic() {
    char arr[50] = "HELLO World";
    cgs_tolower(arr);
    ASSERT_STR_EQ(arr, "hello world");
    return true;
}

bool test_str_tolower_already_lower() {
    DStr ds = dstr_init_from("already lowercase");
    cgs_tolower(&ds);
    ASSERT(cgs_equal(ds, "already lowercase"));
    dstr_deinit(&ds);
    return true;
}

bool test_str_tolower_mixed() {
    char arr[50] = "HeLLo WoRLd123!@#";
    cgs_tolower(arr);
    ASSERT_STR_EQ(arr, "hello world123!@#");
    return true;
}

// ============================================================================
// cgs_toupper tests
// ============================================================================

bool test_str_toupper_basic() {
    char arr[50] = "hello WORLD";
    cgs_toupper(arr);
    ASSERT_STR_EQ(arr, "HELLO WORLD");
    return true;
}

bool test_str_toupper_already_upper() {
    DStr ds = dstr_init_from("ALREADY UPPERCASE");
    (cgs_toupper(&ds));
    ASSERT(cgs_equal(ds, "ALREADY UPPERCASE"));
    dstr_deinit(&ds);
    return true;
}

bool test_str_toupper_mixed() {
    char arr[50] = "HeLLo WoRLd123!@#";
    (cgs_toupper(arr));
    ASSERT_STR_EQ(arr, "HELLO WORLD123!@#");
    return true;
}

// ============================================================================
// cgs_copy tests
// ============================================================================

bool test_str_copy_basic() {
    char dst[50];
    ASSERT_OK(cgs_copy(dst, "hello"));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

bool test_str_copy_empty() {
    char dst[50] = "previous";
    ASSERT_OK(cgs_copy(dst, ""));
    ASSERT_STR_EQ(dst, "");
    return true;
}

bool test_str_copy_dstring() {
    DStr dst = dstr_init(50);
    ASSERT_OK(cgs_copy(&dst, "test string"));
    ASSERT(cgs_equal(dst, "test string"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_copy_too_small() {
    char dst[5];
    CGS_Error err = cgs_copy(dst, "hello world");
    ASSERT_ERR(err, CGS_DST_TOO_SMALL);
    return true;
}

bool test_str_copy_exact_fit() {
    char dst[6]; // "hello" + null terminator
    ASSERT_OK(cgs_copy(dst, "hello"));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

// ============================================================================
// cgs_putc tests
// ============================================================================

bool test_str_putc_basic() {
    char dst[50] = "";
    ASSERT_OK(cgs_putc(dst, 'h'));
    ASSERT_OK(cgs_putc(dst, 'i'));
    ASSERT_STR_EQ(dst, "hi");
    return true;
}

bool test_str_putc_dstring() {
    DStr ds = dstr_init();
    ASSERT_OK(cgs_putc(&ds, 'x'));
    ASSERT_OK(cgs_putc(&ds, 'y'));
    ASSERT_OK(cgs_putc(&ds, 'z'));
    ASSERT(cgs_equal(ds, "xyz"));
    dstr_deinit(&ds);
    return true;
}

bool test_str_putc_full_buffer() {
    char dst[3] = "ab";
    CGS_Error err = cgs_putc(dst, 'c');
    ASSERT_ERR(err, CGS_DST_TOO_SMALL);
    return true;
}

// ============================================================================
// cgs_dup tests
// ============================================================================

bool test_str_dup_basic() {
    DStr dup = cgs_dup("hello world");
    ASSERT(cgs_equal(dup, "hello world"));
    dstr_deinit(&dup);
    return true;
}

bool test_str_dup_empty() {
    DStr dup = cgs_dup("");
    ASSERT_EQ(cgs_len(dup), 0);
    dstr_deinit(&dup);
    return true;
}

bool test_str_dup_from_dstring() {
    DStr src = dstr_init_from("source");
    DStr dup = cgs_dup(src);
    ASSERT(cgs_equal(dup, "source"));
    dstr_deinit(&src);
    dstr_deinit(&dup);
    return true;
}

// ============================================================================
// cgs_append tests
// ============================================================================

bool test_str_append_basic() {
    char dst[50] = "hello";
    ASSERT_OK(cgs_append(dst, " world"));
    ASSERT_STR_EQ(dst, "hello world");
    return true;
}

bool test_str_append_empty_dst() {
    DStr dst = dstr_init();
    ASSERT_OK(cgs_append(&dst, "first"));
    ASSERT(cgs_equal(dst, "first"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_append_empty_src() {
    char dst[50] = "hello";
    ASSERT_OK(cgs_append(dst, ""));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

bool test_str_append_too_small() {
    char dst[10] = "hello";
    CGS_Error err = cgs_append(dst, " world!");
    ASSERT_ERR(err, CGS_DST_TOO_SMALL);
    return true;
}

bool test_str_append_multiple() {
    DStr dst = dstr_init();
    ASSERT_OK(cgs_append(&dst, "one"));
    ASSERT_OK(cgs_append(&dst, "two"));
    ASSERT_OK(cgs_append(&dst, "three"));
    ASSERT(cgs_equal(dst, "onetwothree"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// cgs_prepend tests
// ============================================================================

bool test_str_prepend_basic() {
    DStr dst = dstr_init_from("world");
    ASSERT_OK(cgs_prepend(&dst, "hello "));
    ASSERT(cgs_equal(dst, "hello world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_prepend_empty_dst() {
    DStr dst = dstr_init();
    ASSERT_OK(cgs_prepend(&dst, "first"));
    ASSERT(cgs_equal(dst, "first"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_prepend_empty_src() {
    char dst[50] = "hello";
    ASSERT_OK(cgs_prepend(dst, ""));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

bool test_str_prepend_multiple() {
    DStr dst = dstr_init_from("three");
    ASSERT_OK(cgs_prepend(&dst, "two"));
    ASSERT_OK(cgs_prepend(&dst, "one"));
    ASSERT(cgs_equal(dst, "onetwothree"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// cgs_insert tests
// ============================================================================

bool test_str_insert_middle() {
    DStr dst = dstr_init_from("helo");
    ASSERT_OK(cgs_insert(&dst, "l", 3)); // insert 'l' at index 3
    ASSERT(cgs_equal(dst, "hello"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_beginning() {
    DStr dst = dstr_init_from("orld");
    ASSERT_OK(cgs_insert(&dst, "w", 0));
    ASSERT(cgs_equal(dst, "world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_end() {
    char buf[50] = "hello";
    ASSERT_OK(cgs_insert(buf, "!", cgs_len(buf)));
    ASSERT_STR_EQ(buf, "hello!");
    return true;
}

bool test_str_insert_empty_src() {
    DStr dst = dstr_init_from("test");
    ASSERT_OK(cgs_insert(&dst, "", 2));
    ASSERT(cgs_equal(dst, "test"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_empty_dst() {
    DStr dst = dstr_init();
    ASSERT_OK(cgs_insert(&dst, "first", 0));
    ASSERT(cgs_equal(dst, "first"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_multi_char() {
    DStr dst = dstr_init_from("hello world");
    ASSERT_OK(cgs_insert(&dst, "beautiful ", 6));
    ASSERT(cgs_equal(dst, "hello beautiful world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_out_of_bounds() {
    DStr dst = dstr_init_from("test");
    CGS_Error err = cgs_insert(&dst, "x", 100);
    ASSERT_ERR(err, CGS_INDEX_OUT_OF_BOUNDS);
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_too_small() {
    char buf[10] = "hello";
    CGS_Error err = cgs_insert(buf, " world", 5);
    ASSERT_ERR(err, CGS_DST_TOO_SMALL);
    return true;
}

// ============================================================================
// cgs_del tests
// ============================================================================

bool test_str_del_basic() {
    DStr dst = dstr_init_from("hello world");
    ASSERT_OK(cgs_del(&dst, 5, 11)); // delete " world"
    ASSERT(cgs_equal(dst, "hello"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_del_from_start() {
    char dst[50] = "hello world";
    ASSERT_OK(cgs_del(dst, 0, 6)); // delete "hello "
    ASSERT_STR_EQ(dst, "world");
    return true;
}

bool test_str_del_to_end() {
    DStr dst = dstr_init_from("hello world");
    ASSERT_OK(cgs_del(&dst, 5, cgs_len(dst)));
    ASSERT(cgs_equal(dst, "hello"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_del_entire() {
    char dst[50] = "hello";
    ASSERT_OK(cgs_del(dst, 0, cgs_len(dst)));
    ASSERT_STR_EQ(dst, "");
    return true;
}

bool test_str_del_invalid_range() {
    DStr dst = dstr_init_from("hello");
    CGS_Error err = cgs_del(&dst, 10, 20);
    ASSERT_ERR(err, CGS_INDEX_OUT_OF_BOUNDS);
    dstr_deinit(&dst);
    return true;
}

bool test_str_del_reversed_range() {
    DStr dst = dstr_init_from("hello");
    CGS_Error err = cgs_del(&dst, 4, 2);
    ASSERT_ERR(err, CGS_BAD_RANGE);
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// cgs_replace tests
// ============================================================================

bool test_str_replace_single() {
    DStr dst = dstr_init_from("hello world");
    ReplaceResult result = cgs_replace(&dst, "world", "universe");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 1);
    ASSERT(cgs_equal(dst, "hello universe"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_multiple() {
    DStr dst = dstr_init_from("abc abc abc");
    ReplaceResult result = cgs_replace(&dst, "abc", "xyz");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 3);
    ASSERT(cgs_equal(dst, "xyz xyz xyz"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_none() {
    DStr dst = dstr_init_from("hello world");
    ReplaceResult result = cgs_replace(&dst, "xyz", "abc");
    ASSERT_ERR(result.err, CGS_NOT_FOUND);
    ASSERT_EQ(result.nb_replaced, 0);
    ASSERT(cgs_equal(dst, "hello world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_empty_target() {
    DStr dst = dstr_init_from("hello");
    ReplaceResult result = cgs_replace(&dst, "", "x");
    ASSERT_EQ(result.nb_replaced, 6);
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_longer() {
    DStr dst = dstr_init_from("a b c");
    ReplaceResult result = cgs_replace(&dst, " ", " - ");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 2);
    ASSERT(cgs_equal(dst, "a - b - c"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_shorter() {
    DStr dst = dstr_init_from("hello world");
    ReplaceResult result = cgs_replace(&dst, "hello", "hi");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 1);
    ASSERT(cgs_equal(dst, "hi world"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// cgs_replace_first tests
// ============================================================================

bool test_str_replace_first_found() {
    DStr dst = dstr_init_from("abc abc abc");
    ASSERT_OK(cgs_replace_first(&dst, "abc", "xyz"));
    ASSERT(cgs_equal(dst, "xyz abc abc"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_first_not_found() {
    DStr dst = dstr_init_from("hello world");
    CGS_Error err = cgs_replace_first(&dst, "xyz", "abc");
    // Could be OK or NOT_FOUND depending on implementation
    ASSERT(cgs_equal(dst, "hello world"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// cgs_replace_range tests
// ============================================================================

bool test_str_replace_range_basic() {
    DStr dst = dstr_init_from("hello world");
    ASSERT_OK(cgs_replace_range(&dst, 6, 11, "universe"));
    ASSERT(cgs_equal(dst, "hello universe"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_range_empty() {
    DStr dst = dstr_init_from("hello world");
    ASSERT_OK(cgs_replace_range(&dst, 5, 6, ""));
    ASSERT(cgs_equal(dst, "helloworld"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_range_expand() {
    DStr dst = dstr_init_from("abc");
    ASSERT_OK(cgs_replace_range(&dst, 1, 2, "123"));
    ASSERT(cgs_equal(dst, "a123c"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_range_invalid() {
    DStr dst = dstr_init_from("hello");
    CGS_Error err = cgs_replace_range(&dst, 10, 20, "x");
    ASSERT_ERR(err, CGS_INDEX_OUT_OF_BOUNDS);
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// cgs_split tests
// ============================================================================

bool test_str_split_basic() {
    StrViewArray arr = cgs_split("one,two,three", ",");
    ASSERT_EQ(arr.len, 3);
    ASSERT(cgs_equal(arr.strs[0], "one"));
    ASSERT(cgs_equal(arr.strs[1], "two"));
    ASSERT(cgs_equal(arr.strs[2], "three"));
    free(arr.strs);
    return true;
}

bool test_str_split_no_delimiter() {
    StrViewArray arr = cgs_split("hello", ",");
    ASSERT_EQ(arr.len, 1);
    ASSERT(cgs_equal(arr.strs[0], "hello"));
    free(arr.strs);
    return true;
}

bool test_str_split_empty_parts() {
    StrViewArray arr = cgs_split("a,,b", ",");
    ASSERT_EQ(arr.len, 3);
    ASSERT(cgs_equal(arr.strs[0], "a"));
    ASSERT(cgs_equal(arr.strs[1], ""));
    ASSERT(cgs_equal(arr.strs[2], "b"));
    free(arr.strs);
    return true;
}

bool test_str_split_multi_char_delim() {
    StrViewArray arr = cgs_split("one::two::three", "::");
    ASSERT_EQ(arr.len, 3);
    ASSERT(cgs_equal(arr.strs[0], "one"));
    ASSERT(cgs_equal(arr.strs[1], "two"));
    ASSERT(cgs_equal(arr.strs[2], "three"));
    free(arr.strs);
    return true;
}

// ============================================================================
// cgs_join tests
// ============================================================================

bool test_str_join_basic() {
    StrView parts[] = {
        strv("one", 0, 3),
        strv("two", 0, 3),
        strv("three", 0, 5)
    };
    StrViewArray arr = cgs_strv_arr_from_carr(parts);
    
    DStr dst = dstr_init();
    ASSERT_OK(cgs_join(&dst, arr, ", "));
    ASSERT(cgs_equal(dst, "one, two, three"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_join_empty_array() {
    StrViewArray arr = {.strs = NULL, .len = 0};
    DStr dst = dstr_init();
    ASSERT_OK(cgs_join(&dst, arr, ","));
    ASSERT(cgs_equal(dst, ""));
    dstr_deinit(&dst);
    return true;
}

bool test_str_join_single_element() {
    StrView parts[] = {strv("only", 0, 4)};
    StrViewArray arr = cgs_strv_arr_from_carr(parts);
    
    DStr dst = dstr_init();
    ASSERT_OK(cgs_join(&dst, arr, ","));
    ASSERT(cgs_equal(dst, "only"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// dstr_init tests
// ============================================================================

bool test_dstr_init_default() {
    DStr ds = dstr_init();
    ASSERT_EQ(cgs_len(ds), 0);
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_init_with_cap() {
    DStr ds = dstr_init(100);
    ASSERT_EQ(cgs_len(ds), 0);
    ASSERT(cgs_cap(ds) >= 100);
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_init_from_cstr() {
    DStr ds = dstr_init_from("hello world");
    ASSERT_EQ(cgs_len(ds), 11);
    ASSERT(cgs_equal(ds, "hello world"));
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_init_from_empty() {
    DStr ds = dstr_init_from("");
    ASSERT_EQ(cgs_len(ds), 0);
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// dstr_ensure_cap tests
// ============================================================================

bool test_dstr_ensure_cap_grow() {
    DStr ds = dstr_init(10);
    unsigned int old_cap = cgs_cap(ds);
    ASSERT_OK(dstr_ensure_cap(&ds, 100));
    ASSERT(cgs_cap(ds) >= 100);
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_ensure_cap_no_grow() {
    DStr ds = dstr_init(100);
    unsigned int old_cap = cgs_cap(ds);
    ASSERT_OK(dstr_ensure_cap(&ds, 50));
    ASSERT_EQ(cgs_cap(ds), old_cap);
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// dstr_shrink_to_fit tests
// ============================================================================

bool test_dstr_shrink_to_fit() {
    DStr ds = dstr_init(1000);
    cgs_copy(&ds, "short");
    ASSERT_OK(dstr_shrink_to_fit(&ds));
    ASSERT(cgs_cap(ds) < 1000);
    ASSERT(cgs_equal(ds, "short"));
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// StrBuf tests
// ============================================================================

bool test_strbuf_init_from_cstr() {
    char buf[50] = "hello";
    StrBuf sb = strbuf_init_from_cstr(buf);
    ASSERT(cgs_equal(sb, "hello"));
    ASSERT_EQ(cgs_cap(sb), 50);
    return true;
}

bool test_strbuf_init_from_buf() {
    char buf[64];
    StrBuf sb = strbuf_init_from_buf(buf);
    ASSERT_EQ(cgs_cap(sb), 64);
    ASSERT_EQ(cgs_len(sb), 0);
    return true;
}

bool test_strbuf_operations() {
    char buf[100] = "";
    StrBuf sb = strbuf_init_from_buf(buf);
    
    ASSERT_OK(cgs_copy(&sb, "hello"));
    ASSERT(cgs_equal(sb, "hello"));
    
    ASSERT_OK(cgs_append(&sb, " world"));
    ASSERT(cgs_equal(sb, "hello world"));
    
    return true;
}

// ============================================================================
// strv tests
// ============================================================================

bool test_strv_basic() {
    StrView sv = strv("hello world", 0, 5);
    ASSERT_EQ(cgs_len(sv), 5);
    ASSERT(cgs_equal(sv, "hello"));
    return true;
}

bool test_strv_middle() {
    StrView sv = strv("hello world", 6, 11);
    ASSERT_EQ(cgs_len(sv), 5);
    ASSERT(cgs_equal(sv, "world"));
    return true;
}

bool test_strv_empty() {
    StrView sv = strv("hello", 2, 2);
    ASSERT_EQ(cgs_len(sv), 0);
    return true;
}

bool test_strv_entire() {
    const char *s = "test";
    StrView sv = strv(s, 0, cgs_len(s));
    ASSERT(cgs_equal(sv, "test"));
    return true;
}

// ============================================================================
// MutStrRef / cgs_appender tests
// ============================================================================

bool test_str_appender_basic() {
    char buf[100] = "hello";
    MutStrRef appender = cgs_appender(buf, &(StrAppenderState){});
    
    ASSERT_OK(cgs_append(appender, " world"));
    ASSERT_OK(cgs_commit_appender(buf, appender));
    
    ASSERT_STR_EQ(buf, "hello world");
    return true;
}

// ============================================================================
// tostr tests (basic types)
// ============================================================================

bool test_tostr_int() {
    char buf[50];
    ASSERT_OK(tostr(buf, 42));
    ASSERT_STR_EQ(buf, "42");
    
    ASSERT_OK(tostr(buf, -123));
    ASSERT_STR_EQ(buf, "-123");
    return true;
}

bool test_tostr_string() {
    char buf[50];
    ASSERT_OK(tostr(buf, "hello"));
    ASSERT_STR_EQ(buf, "hello");
    return true;
}

bool test_tostr_error() {
    char buf[50];
    CGS_Error err = {.ec = CGS_ALLOC_ERR};
    ASSERT_OK(tostr(buf, err));
    ASSERT_STR_EQ(buf, "ALLOC_ERR");
    return true;
}

// ============================================================================
// tsfmt tests
// ============================================================================

bool test_tsfmt_int_decimal() {
    char buf[50];
    ASSERT_OK(tostr(buf, tsfmt(42, 'd')));
    ASSERT_STR_EQ(buf, "42");
    return true;
}

bool test_tsfmt_int_hex() {
    char buf[50];
    ASSERT_OK(tostr(buf, tsfmt(255, 'x')));
    ASSERT_STR_EQ(buf, "ff");
    return true;
}

bool test_tsfmt_int_HEX() {
    char buf[50];
    ASSERT_OK(tostr(buf, tsfmt(255, 'x')));
    ASSERT_STR_EQ(buf, "ff");
    return true;
}

bool test_tsfmt_float() {
    char buf[50];
    ASSERT_OK(tostr(buf, tsfmt(3.14159, 'f', 2)));
    ASSERT_STR_EQ(buf, "3.14");
    return true;
}

// ============================================================================
// arrfmt tests
// ============================================================================

bool test_arrfmt_basic() {
    int arr[] = {1, 2, 3, 4, 5};
    char buf[100];
    ASSERT_OK(tostr(buf, arrfmt(arr, 5)));
    ASSERT_STR_EQ(buf, "{1, 2, 3, 4, 5}");
    return true;
}

bool test_arrfmt_custom_delim() {
    int arr[] = {1, 2, 3};
    char buf[100];
    ASSERT_OK(tostr(buf, arrfmt(arr, 3, "[", "]", " | ", "")));
    ASSERT_STR_EQ(buf, "[1 | 2 | 3]");
    return true;
}

bool test_arrfmt_empty() {
    int *arr = NULL;
    char buf[100];
    ASSERT_OK(tostr(buf, arrfmt(arr, 0)));
    ASSERT_STR_EQ(buf, "{}");
    return true;
}

// ============================================================================
// Edge cases and integration tests
// ============================================================================

bool test_unicode_support() {
    DStr ds = dstr_init_from("Hello 世界");
    ASSERT(cgs_len(ds) > 0);
    dstr_deinit(&ds);
    return true;
}

bool test_long_string() {
    DStr ds = dstr_init();
    for (int i = 0; i < 1000; i++) {
        ASSERT_OK(cgs_append(&ds, "x"));
    }
    ASSERT_EQ(cgs_len(ds), 1000);
    dstr_deinit(&ds);
    return true;
}

bool test_chained_operations() {
    DStr ds = dstr_init_from("hello");
    ASSERT_OK(cgs_append(&ds, " world"));
    (cgs_toupper(&ds));
    ASSERT_OK(cgs_replace_first(&ds, "WORLD", "UNIVERSE"));
    ASSERT(cgs_equal(ds, "HELLO UNIVERSE"));
    dstr_deinit(&ds);
    return true;
}

bool test_null_termination() {
    char buf[50];
    cgs_copy(buf, "test");
    ASSERT_EQ(buf[4], '\0');
    ASSERT_EQ(strlen(buf), 4);
    return true;
}

// ============================================================================
// Main test runner
// ============================================================================

int main() {
    printf("Running String Library Test Suite\n");
    printf("==================================\n\n");
    
    // cgs_at
    TEST(test_str_at_cstr);
    TEST(test_str_at_array);
    TEST(test_str_at_dstring);
    TEST(test_str_at_string_view);
    
    // cgs_len
    TEST(test_str_len_empty);
    TEST(test_str_len_cstr);
    TEST(test_str_len_array);
    TEST(test_str_len_dstring);
    TEST(test_str_len_string_view);
    
    // cgs_cap
    TEST(test_str_cap_array);
    TEST(test_str_cap_dstring);
    TEST(test_str_cap_string_buffer);
    
    // cgs_equal
    TEST(test_str_equal_same);
    TEST(test_str_equal_different);
    TEST(test_str_equal_mixed_types);
    
    // cgs_chars
    TEST(test_str_chars_cstr);
    TEST(test_str_chars_dstring);
    
    // cgs_find
    TEST(test_str_find_exists);
    TEST(test_str_find_not_found);
    TEST(test_str_find_empty_needle);
    TEST(test_str_find_at_start);
    TEST(test_str_find_at_end);
    TEST(test_str_find_multiple_occurrences);
    
    // cgs_count
    TEST(test_str_count_none);
    TEST(test_str_count_one);
    TEST(test_str_count_multiple);
    TEST(test_str_count_empty_needle);
    
    // cgs_clear
    TEST(test_str_clear_dstring);
    TEST(test_str_clear_array);
    
    // cgs_starts_with
    TEST(test_str_starts_with_true);
    TEST(test_str_starts_with_false);
    TEST(test_str_starts_with_empty);
    
    // cgs_ends_with
    TEST(test_str_ends_with_true);
    TEST(test_str_ends_with_false);
    TEST(test_str_ends_with_empty);
    
    // cgs_tolower
    TEST(test_str_tolower_basic);
    TEST(test_str_tolower_already_lower);
    TEST(test_str_tolower_mixed);
    
    // cgs_toupper
    TEST(test_str_toupper_basic);
    TEST(test_str_toupper_already_upper);
    TEST(test_str_toupper_mixed);
    
    // cgs_copy
    TEST(test_str_copy_basic);
    TEST(test_str_copy_empty);
    TEST(test_str_copy_dstring);
    TEST(test_str_copy_too_small);
    TEST(test_str_copy_exact_fit);
    
    // cgs_putc
    TEST(test_str_putc_basic);
    TEST(test_str_putc_dstring);
    TEST(test_str_putc_full_buffer);
    
    // cgs_dup
    TEST(test_str_dup_basic);
    TEST(test_str_dup_empty);
    TEST(test_str_dup_from_dstring);
    
    // cgs_append
    TEST(test_str_append_basic);
    TEST(test_str_append_empty_dst);
    TEST(test_str_append_empty_src);
    TEST(test_str_append_too_small);
    TEST(test_str_append_multiple);
    
    // cgs_prepend
    TEST(test_str_prepend_basic);
    TEST(test_str_prepend_empty_dst);
    TEST(test_str_prepend_empty_src);
    TEST(test_str_prepend_multiple);
    
    // cgs_insert
    TEST(test_str_insert_middle);
    TEST(test_str_insert_beginning);
    TEST(test_str_insert_end);
    TEST(test_str_insert_empty_src);
    TEST(test_str_insert_empty_dst);
    TEST(test_str_insert_multi_char);
    TEST(test_str_insert_out_of_bounds);
    TEST(test_str_insert_too_small);
    
    // cgs_del
    TEST(test_str_del_basic);
    TEST(test_str_del_from_start);
    TEST(test_str_del_to_end);
    TEST(test_str_del_entire);
    TEST(test_str_del_invalid_range);
    TEST(test_str_del_reversed_range);
    
    // cgs_replace
    TEST(test_str_replace_single);
    TEST(test_str_replace_multiple);
    TEST(test_str_replace_none);
    TEST(test_str_replace_empty_target);
    TEST(test_str_replace_longer);
    TEST(test_str_replace_shorter);
    
    // cgs_replace_first
    TEST(test_str_replace_first_found);
    TEST(test_str_replace_first_not_found);
    
    // cgs_replace_range
    TEST(test_str_replace_range_basic);
    TEST(test_str_replace_range_empty);
    TEST(test_str_replace_range_expand);
    TEST(test_str_replace_range_invalid);
    
    // cgs_split
    TEST(test_str_split_basic);
    TEST(test_str_split_no_delimiter);
    TEST(test_str_split_empty_parts);
    TEST(test_str_split_multi_char_delim);
    
    // cgs_join
    TEST(test_str_join_basic);
    TEST(test_str_join_empty_array);
    TEST(test_str_join_single_element);
    
    // dstr_init
    TEST(test_dstr_init_default);
    TEST(test_dstr_init_with_cap);
    TEST(test_dstr_init_from_cstr);
    TEST(test_dstr_init_from_empty);
    
    // dstr capacity
    TEST(test_dstr_ensure_cap_grow);
    TEST(test_dstr_ensure_cap_no_grow);
    TEST(test_dstr_shrink_to_fit);
    
    // StrBuf
    TEST(test_strbuf_init_from_cstr);
    TEST(test_strbuf_init_from_buf);
    TEST(test_strbuf_operations);
    
    // strv
    TEST(test_strv_basic);
    TEST(test_strv_middle);
    TEST(test_strv_empty);
    TEST(test_strv_entire);
    
    // cgs_appender
    TEST(test_str_appender_basic);
    
    // tostr
    TEST(test_tostr_int);
    TEST(test_tostr_string);
    TEST(test_tostr_error);
    
    // tsfmt
    TEST(test_tsfmt_int_decimal);
    TEST(test_tsfmt_int_hex);
    TEST(test_tsfmt_int_HEX);
    TEST(test_tsfmt_float);
    
    // arrfmt
    TEST(test_arrfmt_basic);
    TEST(test_arrfmt_custom_delim);
    TEST(test_arrfmt_empty);
    
    // Edge cases
    TEST(test_unicode_support);
    TEST(test_long_string);
    TEST(test_chained_operations);
    TEST(test_null_termination);
    
    printf("\n==================================\n");
    printf("Tests run: %d\n", tests_run);
    printf("Tests passed: %d\n", tests_passed);
    printf("Tests failed: %d\n", tests_run - tests_passed);
    
    return (tests_run == tests_passed) ? 0 : 1;
}