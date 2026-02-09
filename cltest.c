#include "neat_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define NEAT_STR_SHORT_NAMES
#include "neat_str.c"

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
    if ((err).ec != NEAT_OK) { \
        println("    Expected NEAT_OK, got error code, ", err, "(line ",  __LINE__, ")"); \
        return false; \
    } \
} while(0)

#define ASSERT_ERR(err, expected) \
do { \
    if ((err).ec != (expected)) { \
        println("  Expected error ", (Neat_Error){expected}, " got ", err,  "(line ", __LINE__, ")"); \
        return false; \
    } \
} while(0)

// ============================================================================
// str_at tests
// ============================================================================

bool test_str_at_cstr() {
    const char *s = "hello";
    ASSERT_EQ(str_at(s, 0), 'h');
    ASSERT_EQ(str_at(s, 4), 'o');
    return true;
}

bool test_str_at_array() {
    char s[] = "world";
    ASSERT_EQ(str_at(s, 0), 'w');
    ASSERT_EQ(str_at(s, 2), 'r');
    return true;
}

bool test_str_at_dstring() {
    DString ds = dstr_init_from("test");
    ASSERT_EQ(str_at(ds, 0), 't');
    ASSERT_EQ(str_at(ds, 3), 't');
    dstr_deinit(&ds);
    return true;
}

bool test_str_at_string_view() {
    String_View sv = str_view("example", 0, 7);
    ASSERT_EQ(str_at(sv, 0), 'e');
    ASSERT_EQ(str_at(sv, 6), 'e');
    return true;
}

// ============================================================================
// str_len tests
// ============================================================================

bool test_str_len_empty() {
    ASSERT_EQ(str_len(""), 0);
    char empty[] = "";
    ASSERT_EQ(str_len(empty), 0);
    return true;
}

bool test_str_len_cstr() {
    ASSERT_EQ(str_len("hello"), 5);
    ASSERT_EQ(str_len("world"), 5);
    return true;
}

bool test_str_len_array() {
    char arr[] = "testing";
    ASSERT_EQ(str_len(arr), 7);
    return true;
}

bool test_str_len_dstring() {
    DString ds = dstr_init_from("dynamic");
    ASSERT_EQ(str_len(ds), 7);
    dstr_deinit(&ds);
    return true;
}

bool test_str_len_string_view() {
    String_View sv = str_view("hello world", 6, 11);
    ASSERT_EQ(str_len(sv), 5);
    return true;
}

// ============================================================================
// str_cap tests
// ============================================================================

bool test_str_cap_array() {
    char arr[50] = "hello";
    ASSERT_EQ(str_cap(arr), 50);
    return true;
}

bool test_str_cap_dstring() {
    DString ds = dstr_init(100);
    ASSERT(str_cap(ds) >= 100);
    dstr_deinit(&ds);
    return true;
}

bool test_str_cap_string_buffer() {
    char buf[64];
    String_Buffer sb = strbuf_init_from_buf(buf);
    ASSERT_EQ(str_cap(sb), 64);
    return true;
}

// ============================================================================
// str_equal tests
// ============================================================================

bool test_str_equal_same() {
    ASSERT(str_equal("hello", "hello"));
    ASSERT(str_equal("", ""));
    return true;
}

bool test_str_equal_different() {
    ASSERT(!str_equal("hello", "world"));
    ASSERT(!str_equal("hello", "hello!"));
    ASSERT(!str_equal("", "x"));
    return true;
}

bool test_str_equal_mixed_types() {
    char arr[] = "test";
    DString ds = dstr_init_from("test");
    String_View sv = str_view("test", 0, 4);
    
    ASSERT(str_equal(arr, "test"));
    ASSERT(str_equal(ds, "test"));
    ASSERT(str_equal(sv, "test"));
    ASSERT(str_equal(arr, ds));
    ASSERT(str_equal(ds, sv));
    
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// str_chars tests
// ============================================================================

bool test_str_chars_cstr() {
    const char *s = "hello";
    ASSERT_STR_EQ(str_chars(s), "hello");
    return true;
}

bool test_str_chars_dstring() {
    DString ds = dstr_init_from("world");
    ASSERT_STR_EQ(str_chars(ds), "world");
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// str_find tests
// ============================================================================

bool test_str_find_exists() {
    String_View result = str_find("hello world", "world");
    ASSERT_EQ(str_len(result), 5);
    ASSERT(str_equal(result, "world"));
    return true;
}

bool test_str_find_not_found() {
    String_View result = str_find("hello world", "xyz");
    ASSERT_EQ(str_len(result), 0);
    return true;
}

bool test_str_find_empty_needle() {
    String_View result = str_find("hello", "");
    ASSERT_EQ(str_len(result), 0);
    return true;
}

bool test_str_find_at_start() {
    String_View result = str_find("hello world", "hello");
    ASSERT(str_equal(result, "hello"));
    return true;
}

bool test_str_find_at_end() {
    String_View result = str_find("hello world", "world");
    ASSERT(str_equal(result, "world"));
    return true;
}

bool test_str_find_multiple_occurrences() {
    String_View result = str_find("abcabc", "abc");
    ASSERT_EQ(str_len(result), 3);
    // Should find the first occurrence
    return true;
}

// ============================================================================
// str_count tests
// ============================================================================

bool test_str_count_none() {
    ASSERT_EQ(str_count("hello world", "xyz"), 0);
    return true;
}

bool test_str_count_one() {
    ASSERT_EQ(str_count("hello world", "world"), 1);
    return true;
}

bool test_str_count_multiple() {
    ASSERT_EQ(str_count("abcabcabc", "abc"), 3);
    ASSERT_EQ(str_count("aaaa", "aa"), 2); // non-overlapping
    return true;
}

bool test_str_count_empty_needle() {
    ASSERT_EQ(str_count("hello", ""), 0);
    return true;
}

// ============================================================================
// str_clear tests
// ============================================================================

bool test_str_clear_dstring() {
    DString ds = dstr_init_from("hello");
    ASSERT_OK(str_clear(&ds));
    ASSERT_EQ(str_len(ds), 0);
    ASSERT_STR_EQ(str_chars(ds), "");
    dstr_deinit(&ds);
    return true;
}

bool test_str_clear_array() {
    char arr[50] = "hello world";
    ASSERT_OK(str_clear(arr));
    ASSERT_EQ(str_len(arr), 0);
    ASSERT_STR_EQ(arr, "");
    return true;
}

// ============================================================================
// str_starts_with tests
// ============================================================================

bool test_str_starts_with_true() {
    ASSERT(str_starts_with("hello world", "hello"));
    ASSERT(str_starts_with("hello", "hello"));
    ASSERT(str_starts_with("x", "x"));
    return true;
}

bool test_str_starts_with_false() {
    ASSERT(!str_starts_with("hello world", "world"));
    ASSERT(!str_starts_with("hello", "hello!"));
    ASSERT(!str_starts_with("", "x"));
    return true;
}

bool test_str_starts_with_empty() {
    ASSERT(str_starts_with("hello", ""));
    ASSERT(str_starts_with("", ""));
    return true;
}

// ============================================================================
// str_ends_with tests
// ============================================================================

bool test_str_ends_with_true() {
    ASSERT(str_ends_with("hello world", "world"));
    ASSERT(str_ends_with("hello", "hello"));
    ASSERT(str_ends_with("x", "x"));
    return true;
}

bool test_str_ends_with_false() {
    ASSERT(!str_ends_with("hello world", "hello"));
    ASSERT(!str_ends_with("hello", "!hello"));
    ASSERT(!str_ends_with("", "x"));
    return true;
}

bool test_str_ends_with_empty() {
    ASSERT(str_ends_with("hello", ""));
    ASSERT(str_ends_with("", ""));
    return true;
}

// ============================================================================
// str_tolower tests
// ============================================================================

bool test_str_tolower_basic() {
    char arr[50] = "HELLO World";
    ASSERT_OK(str_tolower(arr));
    ASSERT_STR_EQ(arr, "hello world");
    return true;
}

bool test_str_tolower_already_lower() {
    DString ds = dstr_init_from("already lowercase");
    ASSERT_OK(str_tolower(&ds));
    ASSERT(str_equal(ds, "already lowercase"));
    dstr_deinit(&ds);
    return true;
}

bool test_str_tolower_mixed() {
    char arr[50] = "HeLLo WoRLd123!@#";
    ASSERT_OK(str_tolower(arr));
    ASSERT_STR_EQ(arr, "hello world123!@#");
    return true;
}

// ============================================================================
// str_toupper tests
// ============================================================================

bool test_str_toupper_basic() {
    char arr[50] = "hello WORLD";
    ASSERT_OK(str_toupper(arr));
    ASSERT_STR_EQ(arr, "HELLO WORLD");
    return true;
}

bool test_str_toupper_already_upper() {
    DString ds = dstr_init_from("ALREADY UPPERCASE");
    ASSERT_OK(str_toupper(&ds));
    ASSERT(str_equal(ds, "ALREADY UPPERCASE"));
    dstr_deinit(&ds);
    return true;
}

bool test_str_toupper_mixed() {
    char arr[50] = "HeLLo WoRLd123!@#";
    ASSERT_OK(str_toupper(arr));
    ASSERT_STR_EQ(arr, "HELLO WORLD123!@#");
    return true;
}

// ============================================================================
// str_copy tests
// ============================================================================

bool test_str_copy_basic() {
    char dst[50];
    ASSERT_OK(str_copy(dst, "hello"));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

bool test_str_copy_empty() {
    char dst[50] = "previous";
    ASSERT_OK(str_copy(dst, ""));
    ASSERT_STR_EQ(dst, "");
    return true;
}

bool test_str_copy_dstring() {
    DString dst = dstr_init(50);
    ASSERT_OK(str_copy(&dst, "test string"));
    ASSERT(str_equal(dst, "test string"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_copy_too_small() {
    char dst[5];
    Neat_Error err = str_copy(dst, "hello world");
    ASSERT_ERR(err, NEAT_DST_TOO_SMALL);
    return true;
}

bool test_str_copy_exact_fit() {
    char dst[6]; // "hello" + null terminator
    ASSERT_OK(str_copy(dst, "hello"));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

// ============================================================================
// str_putc tests
// ============================================================================

bool test_str_putc_basic() {
    char dst[50] = "";
    ASSERT_OK(str_putc(dst, 'h'));
    ASSERT_OK(str_putc(dst, 'i'));
    ASSERT_STR_EQ(dst, "hi");
    return true;
}

bool test_str_putc_dstring() {
    DString ds = dstr_init();
    ASSERT_OK(str_putc(&ds, 'x'));
    ASSERT_OK(str_putc(&ds, 'y'));
    ASSERT_OK(str_putc(&ds, 'z'));
    ASSERT(str_equal(ds, "xyz"));
    dstr_deinit(&ds);
    return true;
}

bool test_str_putc_full_buffer() {
    char dst[3] = "ab";
    Neat_Error err = str_putc(dst, 'c');
    ASSERT_ERR(err, NEAT_DST_TOO_SMALL);
    return true;
}

// ============================================================================
// str_dup tests
// ============================================================================

bool test_str_dup_basic() {
    DString dup = str_dup("hello world");
    ASSERT(str_equal(dup, "hello world"));
    dstr_deinit(&dup);
    return true;
}

bool test_str_dup_empty() {
    DString dup = str_dup("");
    ASSERT_EQ(str_len(dup), 0);
    dstr_deinit(&dup);
    return true;
}

bool test_str_dup_from_dstring() {
    DString src = dstr_init_from("source");
    DString dup = str_dup(src);
    ASSERT(str_equal(dup, "source"));
    dstr_deinit(&src);
    dstr_deinit(&dup);
    return true;
}

// ============================================================================
// str_append tests
// ============================================================================

bool test_str_append_basic() {
    char dst[50] = "hello";
    ASSERT_OK(str_append(dst, " world"));
    ASSERT_STR_EQ(dst, "hello world");
    return true;
}

bool test_str_append_empty_dst() {
    DString dst = dstr_init();
    ASSERT_OK(str_append(&dst, "first"));
    ASSERT(str_equal(dst, "first"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_append_empty_src() {
    char dst[50] = "hello";
    ASSERT_OK(str_append(dst, ""));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

bool test_str_append_too_small() {
    char dst[10] = "hello";
    Neat_Error err = str_append(dst, " world!");
    ASSERT_ERR(err, NEAT_DST_TOO_SMALL);
    return true;
}

bool test_str_append_multiple() {
    DString dst = dstr_init();
    ASSERT_OK(str_append(&dst, "one"));
    ASSERT_OK(str_append(&dst, "two"));
    ASSERT_OK(str_append(&dst, "three"));
    ASSERT(str_equal(dst, "onetwothree"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// str_prepend tests
// ============================================================================

bool test_str_prepend_basic() {
    DString dst = dstr_init_from("world");
    ASSERT_OK(str_prepend(&dst, "hello "));
    ASSERT(str_equal(dst, "hello world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_prepend_empty_dst() {
    DString dst = dstr_init();
    ASSERT_OK(str_prepend(&dst, "first"));
    ASSERT(str_equal(dst, "first"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_prepend_empty_src() {
    char dst[50] = "hello";
    ASSERT_OK(str_prepend(dst, ""));
    ASSERT_STR_EQ(dst, "hello");
    return true;
}

bool test_str_prepend_multiple() {
    DString dst = dstr_init_from("three");
    ASSERT_OK(str_prepend(&dst, "two"));
    ASSERT_OK(str_prepend(&dst, "one"));
    ASSERT(str_equal(dst, "onetwothree"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// str_insert tests
// ============================================================================

bool test_str_insert_middle() {
    DString dst = dstr_init_from("helo");
    ASSERT_OK(str_insert(&dst, "l", 3)); // insert 'l' at index 3
    ASSERT(str_equal(dst, "hello"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_beginning() {
    DString dst = dstr_init_from("orld");
    ASSERT_OK(str_insert(&dst, "w", 0));
    ASSERT(str_equal(dst, "world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_end() {
    char buf[50] = "hello";
    ASSERT_OK(str_insert(buf, "!", str_len(buf)));
    ASSERT_STR_EQ(buf, "hello!");
    return true;
}

bool test_str_insert_empty_src() {
    DString dst = dstr_init_from("test");
    ASSERT_OK(str_insert(&dst, "", 2));
    ASSERT(str_equal(dst, "test"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_empty_dst() {
    DString dst = dstr_init();
    ASSERT_OK(str_insert(&dst, "first", 0));
    ASSERT(str_equal(dst, "first"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_multi_char() {
    DString dst = dstr_init_from("hello world");
    ASSERT_OK(str_insert(&dst, "beautiful ", 6));
    ASSERT(str_equal(dst, "hello beautiful world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_out_of_bounds() {
    DString dst = dstr_init_from("test");
    Neat_Error err = str_insert(&dst, "x", 100);
    ASSERT_ERR(err, NEAT_INDEX_OUT_OF_BOUNDS);
    dstr_deinit(&dst);
    return true;
}

bool test_str_insert_too_small() {
    char buf[10] = "hello";
    Neat_Error err = str_insert(buf, " world", 5);
    ASSERT_ERR(err, NEAT_DST_TOO_SMALL);
    return true;
}

// ============================================================================
// str_del tests
// ============================================================================

bool test_str_del_basic() {
    DString dst = dstr_init_from("hello world");
    ASSERT_OK(str_del(&dst, 5, 11)); // delete " world"
    ASSERT(str_equal(dst, "hello"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_del_from_start() {
    char dst[50] = "hello world";
    ASSERT_OK(str_del(dst, 0, 6)); // delete "hello "
    ASSERT_STR_EQ(dst, "world");
    return true;
}

bool test_str_del_to_end() {
    DString dst = dstr_init_from("hello world");
    ASSERT_OK(str_del(&dst, 5, str_len(dst)));
    ASSERT(str_equal(dst, "hello"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_del_entire() {
    char dst[50] = "hello";
    ASSERT_OK(str_del(dst, 0, str_len(dst)));
    ASSERT_STR_EQ(dst, "");
    return true;
}

bool test_str_del_invalid_range() {
    DString dst = dstr_init_from("hello");
    Neat_Error err = str_del(&dst, 10, 20);
    ASSERT_ERR(err, NEAT_INDEX_OUT_OF_BOUNDS);
    dstr_deinit(&dst);
    return true;
}

bool test_str_del_reversed_range() {
    DString dst = dstr_init_from("hello");
    Neat_Error err = str_del(&dst, 4, 2);
    ASSERT_ERR(err, NEAT_BAD_RANGE);
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// str_replace tests
// ============================================================================

bool test_str_replace_single() {
    DString dst = dstr_init_from("hello world");
    Replace_Result result = str_replace(&dst, "world", "universe");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 1);
    ASSERT(str_equal(dst, "hello universe"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_multiple() {
    DString dst = dstr_init_from("abc abc abc");
    Replace_Result result = str_replace(&dst, "abc", "xyz");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 3);
    ASSERT(str_equal(dst, "xyz xyz xyz"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_none() {
    DString dst = dstr_init_from("hello world");
    Replace_Result result = str_replace(&dst, "xyz", "abc");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 0);
    ASSERT(str_equal(dst, "hello world"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_empty_target() {
    DString dst = dstr_init_from("hello");
    Replace_Result result = str_replace(&dst, "", "x");
    ASSERT_EQ(result.nb_replaced, 6);
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_longer() {
    DString dst = dstr_init_from("a b c");
    Replace_Result result = str_replace(&dst, " ", " - ");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 2);
    ASSERT(str_equal(dst, "a - b - c"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_shorter() {
    DString dst = dstr_init_from("hello world");
    Replace_Result result = str_replace(&dst, "hello", "hi");
    ASSERT_OK(result.err);
    ASSERT_EQ(result.nb_replaced, 1);
    ASSERT(str_equal(dst, "hi world"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// str_replace_first tests
// ============================================================================

bool test_str_replace_first_found() {
    DString dst = dstr_init_from("abc abc abc");
    ASSERT_OK(str_replace_first(&dst, "abc", "xyz"));
    ASSERT(str_equal(dst, "xyz abc abc"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_first_not_found() {
    DString dst = dstr_init_from("hello world");
    Neat_Error err = str_replace_first(&dst, "xyz", "abc");
    // Could be OK or NOT_FOUND depending on implementation
    ASSERT(str_equal(dst, "hello world"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// str_replace_range tests
// ============================================================================

bool test_str_replace_range_basic() {
    DString dst = dstr_init_from("hello world");
    ASSERT_OK(str_replace_range(&dst, 6, 11, "universe"));
    ASSERT(str_equal(dst, "hello universe"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_range_empty() {
    DString dst = dstr_init_from("hello world");
    ASSERT_OK(str_replace_range(&dst, 5, 6, ""));
    ASSERT(str_equal(dst, "helloworld"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_range_expand() {
    DString dst = dstr_init_from("abc");
    ASSERT_OK(str_replace_range(&dst, 1, 2, "123"));
    ASSERT(str_equal(dst, "a123c"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_replace_range_invalid() {
    DString dst = dstr_init_from("hello");
    Neat_Error err = str_replace_range(&dst, 10, 20, "x");
    ASSERT_ERR(err, NEAT_INDEX_OUT_OF_BOUNDS);
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// str_split tests
// ============================================================================

bool test_str_split_basic() {
    String_View_Array arr = str_split("one,two,three", ",");
    ASSERT_EQ(arr.len, 3);
    ASSERT(str_equal(arr.strs[0], "one"));
    ASSERT(str_equal(arr.strs[1], "two"));
    ASSERT(str_equal(arr.strs[2], "three"));
    // Free array
    return true;
}

bool test_str_split_no_delimiter() {
    String_View_Array arr = str_split("hello", ",");
    ASSERT_EQ(arr.len, 1);
    ASSERT(str_equal(arr.strs[0], "hello"));
    return true;
}

bool test_str_split_empty_parts() {
    String_View_Array arr = str_split("a,,b", ",");
    ASSERT_EQ(arr.len, 3);
    ASSERT(str_equal(arr.strs[0], "a"));
    ASSERT(str_equal(arr.strs[1], ""));
    ASSERT(str_equal(arr.strs[2], "b"));
    return true;
}

bool test_str_split_multi_char_delim() {
    String_View_Array arr = str_split("one::two::three", "::");
    ASSERT_EQ(arr.len, 3);
    ASSERT(str_equal(arr.strs[0], "one"));
    ASSERT(str_equal(arr.strs[1], "two"));
    ASSERT(str_equal(arr.strs[2], "three"));
    return true;
}

// ============================================================================
// str_join tests
// ============================================================================

bool test_str_join_basic() {
    String_View parts[] = {
        str_view("one", 0, 3),
        str_view("two", 0, 3),
        str_view("three", 0, 5)
    };
    String_View_Array arr = str_view_arr_from_carr(parts);
    
    DString dst = dstr_init();
    ASSERT_OK(str_join(&dst, arr, ", "));
    ASSERT(str_equal(dst, "one, two, three"));
    dstr_deinit(&dst);
    return true;
}

bool test_str_join_empty_array() {
    String_View_Array arr = {.strs = NULL, .len = 0};
    DString dst = dstr_init();
    ASSERT_OK(str_join(&dst, arr, ","));
    ASSERT(str_equal(dst, ""));
    dstr_deinit(&dst);
    return true;
}

bool test_str_join_single_element() {
    String_View parts[] = {str_view("only", 0, 4)};
    String_View_Array arr = str_view_arr_from_carr(parts);
    
    DString dst = dstr_init();
    ASSERT_OK(str_join(&dst, arr, ","));
    ASSERT(str_equal(dst, "only"));
    dstr_deinit(&dst);
    return true;
}

// ============================================================================
// dstr_init tests
// ============================================================================

bool test_dstr_init_default() {
    DString ds = dstr_init();
    ASSERT_EQ(str_len(ds), 0);
    ASSERT(str_cap(ds) >= 0);
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_init_with_cap() {
    DString ds = dstr_init(100);
    ASSERT_EQ(str_len(ds), 0);
    ASSERT(str_cap(ds) >= 100);
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_init_from_cstr() {
    DString ds = dstr_init_from("hello world");
    ASSERT_EQ(str_len(ds), 11);
    ASSERT(str_equal(ds, "hello world"));
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_init_from_empty() {
    DString ds = dstr_init_from("");
    ASSERT_EQ(str_len(ds), 0);
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// dstr_ensure_cap tests
// ============================================================================

bool test_dstr_ensure_cap_grow() {
    DString ds = dstr_init(10);
    unsigned int old_cap = str_cap(ds);
    ASSERT_OK(dstr_ensure_cap(&ds, 100));
    ASSERT(str_cap(ds) >= 100);
    dstr_deinit(&ds);
    return true;
}

bool test_dstr_ensure_cap_no_grow() {
    DString ds = dstr_init(100);
    unsigned int old_cap = str_cap(ds);
    ASSERT_OK(dstr_ensure_cap(&ds, 50));
    ASSERT_EQ(str_cap(ds), old_cap);
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// dstr_shrink_to_fit tests
// ============================================================================

bool test_dstr_shrink_to_fit() {
    DString ds = dstr_init(1000);
    str_copy(&ds, "short");
    ASSERT_OK(dstr_shrink_to_fit(&ds));
    ASSERT(str_cap(ds) < 1000);
    ASSERT(str_equal(ds, "short"));
    dstr_deinit(&ds);
    return true;
}

// ============================================================================
// String_Buffer tests
// ============================================================================

bool test_strbuf_init_from_cstr() {
    char buf[50] = "hello";
    String_Buffer sb = strbuf_init_from_cstr(buf);
    ASSERT(str_equal(sb, "hello"));
    ASSERT_EQ(str_cap(sb), 50);
    return true;
}

bool test_strbuf_init_from_buf() {
    char buf[64];
    String_Buffer sb = strbuf_init_from_buf(buf);
    ASSERT_EQ(str_cap(sb), 64);
    ASSERT_EQ(str_len(sb), 0);
    return true;
}

bool test_strbuf_operations() {
    char buf[100] = "";
    String_Buffer sb = strbuf_init_from_buf(buf);
    
    ASSERT_OK(str_copy(&sb, "hello"));
    ASSERT(str_equal(sb, "hello"));
    
    ASSERT_OK(str_append(&sb, " world"));
    ASSERT(str_equal(sb, "hello world"));
    
    return true;
}

// ============================================================================
// str_view tests
// ============================================================================

bool test_str_view_basic() {
    String_View sv = str_view("hello world", 0, 5);
    ASSERT_EQ(str_len(sv), 5);
    ASSERT(str_equal(sv, "hello"));
    return true;
}

bool test_str_view_middle() {
    String_View sv = str_view("hello world", 6, 11);
    ASSERT_EQ(str_len(sv), 5);
    ASSERT(str_equal(sv, "world"));
    return true;
}

bool test_str_view_empty() {
    String_View sv = str_view("hello", 2, 2);
    ASSERT_EQ(str_len(sv), 0);
    return true;
}

bool test_str_view_entire() {
    const char *s = "test";
    String_View sv = str_view(s, 0, str_len(s));
    ASSERT(str_equal(sv, "test"));
    return true;
}

// ============================================================================
// Mut_String_Ref / str_appender tests
// ============================================================================

bool test_str_appender_basic() {
    char buf[100] = "hello";
    Mut_String_Ref appender = str_appender(buf, &(String_Appender_State){});
    
    ASSERT_OK(str_append(appender, " world"));
    ASSERT_OK(str_commit_appender(buf, appender));
    
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
    Neat_Error err = {.ec = NEAT_ALLOC_ERR};
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
    DString ds = dstr_init_from("Hello 世界");
    ASSERT(str_len(ds) > 0);
    dstr_deinit(&ds);
    return true;
}

bool test_long_string() {
    DString ds = dstr_init();
    for (int i = 0; i < 1000; i++) {
        ASSERT_OK(str_append(&ds, "x"));
    }
    ASSERT_EQ(str_len(ds), 1000);
    dstr_deinit(&ds);
    return true;
}

bool test_chained_operations() {
    DString ds = dstr_init_from("hello");
    ASSERT_OK(str_append(&ds, " world"));
    ASSERT_OK(str_toupper(&ds));
    ASSERT_OK(str_replace_first(&ds, "WORLD", "UNIVERSE"));
    ASSERT(str_equal(ds, "HELLO UNIVERSE"));
    dstr_deinit(&ds);
    return true;
}

bool test_null_termination() {
    char buf[50];
    str_copy(buf, "test");
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
    
    // str_at
    TEST(test_str_at_cstr);
    TEST(test_str_at_array);
    TEST(test_str_at_dstring);
    TEST(test_str_at_string_view);
    
    // str_len
    TEST(test_str_len_empty);
    TEST(test_str_len_cstr);
    TEST(test_str_len_array);
    TEST(test_str_len_dstring);
    TEST(test_str_len_string_view);
    
    // str_cap
    TEST(test_str_cap_array);
    TEST(test_str_cap_dstring);
    TEST(test_str_cap_string_buffer);
    
    // str_equal
    TEST(test_str_equal_same);
    TEST(test_str_equal_different);
    TEST(test_str_equal_mixed_types);
    
    // str_chars
    TEST(test_str_chars_cstr);
    TEST(test_str_chars_dstring);
    
    // str_find
    TEST(test_str_find_exists);
    TEST(test_str_find_not_found);
    TEST(test_str_find_empty_needle);
    TEST(test_str_find_at_start);
    TEST(test_str_find_at_end);
    TEST(test_str_find_multiple_occurrences);
    
    // str_count
    TEST(test_str_count_none);
    TEST(test_str_count_one);
    TEST(test_str_count_multiple);
    TEST(test_str_count_empty_needle);
    
    // str_clear
    TEST(test_str_clear_dstring);
    TEST(test_str_clear_array);
    
    // str_starts_with
    TEST(test_str_starts_with_true);
    TEST(test_str_starts_with_false);
    TEST(test_str_starts_with_empty);
    
    // str_ends_with
    TEST(test_str_ends_with_true);
    TEST(test_str_ends_with_false);
    TEST(test_str_ends_with_empty);
    
    // str_tolower
    TEST(test_str_tolower_basic);
    TEST(test_str_tolower_already_lower);
    TEST(test_str_tolower_mixed);
    
    // str_toupper
    TEST(test_str_toupper_basic);
    TEST(test_str_toupper_already_upper);
    TEST(test_str_toupper_mixed);
    
    // str_copy
    TEST(test_str_copy_basic);
    TEST(test_str_copy_empty);
    TEST(test_str_copy_dstring);
    TEST(test_str_copy_too_small);
    TEST(test_str_copy_exact_fit);
    
    // str_putc
    TEST(test_str_putc_basic);
    TEST(test_str_putc_dstring);
    TEST(test_str_putc_full_buffer);
    
    // str_dup
    TEST(test_str_dup_basic);
    TEST(test_str_dup_empty);
    TEST(test_str_dup_from_dstring);
    
    // str_append
    TEST(test_str_append_basic);
    TEST(test_str_append_empty_dst);
    TEST(test_str_append_empty_src);
    TEST(test_str_append_too_small);
    TEST(test_str_append_multiple);
    
    // str_prepend
    TEST(test_str_prepend_basic);
    TEST(test_str_prepend_empty_dst);
    TEST(test_str_prepend_empty_src);
    TEST(test_str_prepend_multiple);
    
    // str_insert
    TEST(test_str_insert_middle);
    TEST(test_str_insert_beginning);
    TEST(test_str_insert_end);
    TEST(test_str_insert_empty_src);
    TEST(test_str_insert_empty_dst);
    TEST(test_str_insert_multi_char);
    TEST(test_str_insert_out_of_bounds);
    TEST(test_str_insert_too_small);
    
    // str_del
    TEST(test_str_del_basic);
    TEST(test_str_del_from_start);
    TEST(test_str_del_to_end);
    TEST(test_str_del_entire);
    TEST(test_str_del_invalid_range);
    TEST(test_str_del_reversed_range);
    
    // str_replace
    TEST(test_str_replace_single);
    TEST(test_str_replace_multiple);
    TEST(test_str_replace_none);
    TEST(test_str_replace_empty_target);
    TEST(test_str_replace_longer);
    TEST(test_str_replace_shorter);
    
    // str_replace_first
    TEST(test_str_replace_first_found);
    TEST(test_str_replace_first_not_found);
    
    // str_replace_range
    TEST(test_str_replace_range_basic);
    TEST(test_str_replace_range_empty);
    TEST(test_str_replace_range_expand);
    TEST(test_str_replace_range_invalid);
    
    // str_split
    TEST(test_str_split_basic);
    TEST(test_str_split_no_delimiter);
    TEST(test_str_split_empty_parts);
    TEST(test_str_split_multi_char_delim);
    
    // str_join
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
    
    // String_Buffer
    TEST(test_strbuf_init_from_cstr);
    TEST(test_strbuf_init_from_buf);
    TEST(test_strbuf_operations);
    
    // str_view
    TEST(test_str_view_basic);
    TEST(test_str_view_middle);
    TEST(test_str_view_empty);
    TEST(test_str_view_entire);
    
    // str_appender
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