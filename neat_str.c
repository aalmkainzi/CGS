#include <ctype.h>

#ifndef NEAT_API
    // for functions exposed in the header
    #define NEAT_API
#endif
#ifndef NEAT_PRIVATE
    // for functions only in neat_str.c
    #define NEAT_PRIVATE
#endif

#define NEAT__SOURCE
#include "neat_str.h"

#if !defined(unreachable)
    #if defined(_MSC_VER)
        #define unreachable() __assume(0)
    #elif defined(__GNUC__)
        #define unreachable() __builtin_unreachable()
    #else
        #define unreachable()
    #endif
#endif

NEAT_PRIVATE Neat_Allocation neat__default_allocator_alloc(Neat_Allocator *ctx, size_t alignment, size_t n);
NEAT_PRIVATE void neat__default_allocator_dealloc(Neat_Allocator *ctx, void *ptr, size_t n);
NEAT_PRIVATE Neat_Allocation neat__default_allocator_realloc(Neat_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size);

static Neat_Allocator neat__default_allocator = {
    .alloc   = neat__default_allocator_alloc,
    .dealloc = neat__default_allocator_dealloc,
    .realloc = neat__default_allocator_realloc,
};

static const Neat_String_View neat__error_to_string[] = {
    [NEAT_OK]                     = {.len = sizeof("OK")                     - 1, .chars = (unsigned char*) "OK"},
    [NEAT_DST_TOO_SMALL]          = {.len = sizeof("DST_TOO_SMALL")          - 1, .chars = (unsigned char*) "DST_TOO_SMALL"},
    [NEAT_ALLOC_ERR]              = {.len = sizeof("ALLOC_ERR")              - 1, .chars = (unsigned char*) "ALLOC_ERR"},
    [NEAT_INDEX_OUT_OF_BOUNDS]    = {.len = sizeof("INDEX_OUT_OF_BOUNDS")    - 1, .chars = (unsigned char*) "INDEX_OUT_OF_BOUNDS"},
    [NEAT_BAD_RANGE]              = {.len = sizeof("BAD_RANGE")              - 1, .chars = (unsigned char*) "BAD_RANGE"},
    [NEAT_NOT_FOUND]              = {.len = sizeof("NOT_FOUND")              - 1, .chars = (unsigned char*) "NOT_FOUND"},
    [NEAT_ALIASING_NOT_SUPPORTED] = {.len = sizeof("ALIASING_NOT_SUPPORTED") - 1, .chars = (unsigned char*) "ALIASING_NOT_SUPPORTED"},
    [NEAT_INCORRECT_TYPE]         = {.len = sizeof("INCORRECT_TYPE")         - 1, .chars = (unsigned char*) "INCORRECT_TYPE"},
    [NEAT_ENCODING_ERROR]         = {.len = sizeof("ENCODING_ERROR")         - 1, .chars = (unsigned char*) "ENCODING_ERROR"},
    [NEAT_CALLBACK_EXIT]          = {.len = sizeof("CALLBACK_EXIT")          - 1, .chars = (unsigned char*) "CALLBACK_EXIT"}
};

static const long long neat__ten_pows[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
    1000000000000000,
    10000000000000000,
    100000000000000000,
    1000000000000000000,
};

static const unsigned long long neat__ten_pows_ull[] = {
    1ull,
    10ull,
    100ull,
    1000ull,
    10000ull,
    100000ull,
    1000000ull,
    10000000ull,
    100000000ull,
    1000000000ull,
    10000000000ull,
    100000000000ull,
    1000000000000ull,
    10000000000000ull,
    100000000000000ull,
    1000000000000000ull,
    10000000000000000ull,
    100000000000000000ull,
    1000000000000000000ull,
    10000000000000000000ull,
};

static const Neat_String_View neat__uc_to_string[256] = {
    {.chars = (unsigned char*) "0", .len = 1},
    {.chars = (unsigned char*) "1", .len = 1},
    {.chars = (unsigned char*) "2", .len = 1},
    {.chars = (unsigned char*) "3", .len = 1},
    {.chars = (unsigned char*) "4", .len = 1},
    {.chars = (unsigned char*) "5", .len = 1},
    {.chars = (unsigned char*) "6", .len = 1},
    {.chars = (unsigned char*) "7", .len = 1},
    {.chars = (unsigned char*) "8", .len = 1},
    {.chars = (unsigned char*) "9", .len = 1},
    {.chars = (unsigned char*) "10", .len = 2},
    {.chars = (unsigned char*) "11", .len = 2},
    {.chars = (unsigned char*) "12", .len = 2},
    {.chars = (unsigned char*) "13", .len = 2},
    {.chars = (unsigned char*) "14", .len = 2},
    {.chars = (unsigned char*) "15", .len = 2},
    {.chars = (unsigned char*) "16", .len = 2},
    {.chars = (unsigned char*) "17", .len = 2},
    {.chars = (unsigned char*) "18", .len = 2},
    {.chars = (unsigned char*) "19", .len = 2},
    {.chars = (unsigned char*) "20", .len = 2},
    {.chars = (unsigned char*) "21", .len = 2},
    {.chars = (unsigned char*) "22", .len = 2},
    {.chars = (unsigned char*) "23", .len = 2},
    {.chars = (unsigned char*) "24", .len = 2},
    {.chars = (unsigned char*) "25", .len = 2},
    {.chars = (unsigned char*) "26", .len = 2},
    {.chars = (unsigned char*) "27", .len = 2},
    {.chars = (unsigned char*) "28", .len = 2},
    {.chars = (unsigned char*) "29", .len = 2},
    {.chars = (unsigned char*) "30", .len = 2},
    {.chars = (unsigned char*) "31", .len = 2},
    {.chars = (unsigned char*) "32", .len = 2},
    {.chars = (unsigned char*) "33", .len = 2},
    {.chars = (unsigned char*) "34", .len = 2},
    {.chars = (unsigned char*) "35", .len = 2},
    {.chars = (unsigned char*) "36", .len = 2},
    {.chars = (unsigned char*) "37", .len = 2},
    {.chars = (unsigned char*) "38", .len = 2},
    {.chars = (unsigned char*) "39", .len = 2},
    {.chars = (unsigned char*) "40", .len = 2},
    {.chars = (unsigned char*) "41", .len = 2},
    {.chars = (unsigned char*) "42", .len = 2},
    {.chars = (unsigned char*) "43", .len = 2},
    {.chars = (unsigned char*) "44", .len = 2},
    {.chars = (unsigned char*) "45", .len = 2},
    {.chars = (unsigned char*) "46", .len = 2},
    {.chars = (unsigned char*) "47", .len = 2},
    {.chars = (unsigned char*) "48", .len = 2},
    {.chars = (unsigned char*) "49", .len = 2},
    {.chars = (unsigned char*) "50", .len = 2},
    {.chars = (unsigned char*) "51", .len = 2},
    {.chars = (unsigned char*) "52", .len = 2},
    {.chars = (unsigned char*) "53", .len = 2},
    {.chars = (unsigned char*) "54", .len = 2},
    {.chars = (unsigned char*) "55", .len = 2},
    {.chars = (unsigned char*) "56", .len = 2},
    {.chars = (unsigned char*) "57", .len = 2},
    {.chars = (unsigned char*) "58", .len = 2},
    {.chars = (unsigned char*) "59", .len = 2},
    {.chars = (unsigned char*) "60", .len = 2},
    {.chars = (unsigned char*) "61", .len = 2},
    {.chars = (unsigned char*) "62", .len = 2},
    {.chars = (unsigned char*) "63", .len = 2},
    {.chars = (unsigned char*) "64", .len = 2},
    {.chars = (unsigned char*) "65", .len = 2},
    {.chars = (unsigned char*) "66", .len = 2},
    {.chars = (unsigned char*) "67", .len = 2},
    {.chars = (unsigned char*) "68", .len = 2},
    {.chars = (unsigned char*) "69", .len = 2},
    {.chars = (unsigned char*) "70", .len = 2},
    {.chars = (unsigned char*) "71", .len = 2},
    {.chars = (unsigned char*) "72", .len = 2},
    {.chars = (unsigned char*) "73", .len = 2},
    {.chars = (unsigned char*) "74", .len = 2},
    {.chars = (unsigned char*) "75", .len = 2},
    {.chars = (unsigned char*) "76", .len = 2},
    {.chars = (unsigned char*) "77", .len = 2},
    {.chars = (unsigned char*) "78", .len = 2},
    {.chars = (unsigned char*) "79", .len = 2},
    {.chars = (unsigned char*) "80", .len = 2},
    {.chars = (unsigned char*) "81", .len = 2},
    {.chars = (unsigned char*) "82", .len = 2},
    {.chars = (unsigned char*) "83", .len = 2},
    {.chars = (unsigned char*) "84", .len = 2},
    {.chars = (unsigned char*) "85", .len = 2},
    {.chars = (unsigned char*) "86", .len = 2},
    {.chars = (unsigned char*) "87", .len = 2},
    {.chars = (unsigned char*) "88", .len = 2},
    {.chars = (unsigned char*) "89", .len = 2},
    {.chars = (unsigned char*) "90", .len = 2},
    {.chars = (unsigned char*) "91", .len = 2},
    {.chars = (unsigned char*) "92", .len = 2},
    {.chars = (unsigned char*) "93", .len = 2},
    {.chars = (unsigned char*) "94", .len = 2},
    {.chars = (unsigned char*) "95", .len = 2},
    {.chars = (unsigned char*) "96", .len = 2},
    {.chars = (unsigned char*) "97", .len = 2},
    {.chars = (unsigned char*) "98", .len = 2},
    {.chars = (unsigned char*) "99", .len = 2},
    {.chars = (unsigned char*) "100", .len = 3},
    {.chars = (unsigned char*) "101", .len = 3},
    {.chars = (unsigned char*) "102", .len = 3},
    {.chars = (unsigned char*) "103", .len = 3},
    {.chars = (unsigned char*) "104", .len = 3},
    {.chars = (unsigned char*) "105", .len = 3},
    {.chars = (unsigned char*) "106", .len = 3},
    {.chars = (unsigned char*) "107", .len = 3},
    {.chars = (unsigned char*) "108", .len = 3},
    {.chars = (unsigned char*) "109", .len = 3},
    {.chars = (unsigned char*) "110", .len = 3},
    {.chars = (unsigned char*) "111", .len = 3},
    {.chars = (unsigned char*) "112", .len = 3},
    {.chars = (unsigned char*) "113", .len = 3},
    {.chars = (unsigned char*) "114", .len = 3},
    {.chars = (unsigned char*) "115", .len = 3},
    {.chars = (unsigned char*) "116", .len = 3},
    {.chars = (unsigned char*) "117", .len = 3},
    {.chars = (unsigned char*) "118", .len = 3},
    {.chars = (unsigned char*) "119", .len = 3},
    {.chars = (unsigned char*) "120", .len = 3},
    {.chars = (unsigned char*) "121", .len = 3},
    {.chars = (unsigned char*) "122", .len = 3},
    {.chars = (unsigned char*) "123", .len = 3},
    {.chars = (unsigned char*) "124", .len = 3},
    {.chars = (unsigned char*) "125", .len = 3},
    {.chars = (unsigned char*) "126", .len = 3},
    {.chars = (unsigned char*) "127", .len = 3},
    {.chars = (unsigned char*) "128", .len = 3},
    {.chars = (unsigned char*) "129", .len = 3},
    {.chars = (unsigned char*) "130", .len = 3},
    {.chars = (unsigned char*) "131", .len = 3},
    {.chars = (unsigned char*) "132", .len = 3},
    {.chars = (unsigned char*) "133", .len = 3},
    {.chars = (unsigned char*) "134", .len = 3},
    {.chars = (unsigned char*) "135", .len = 3},
    {.chars = (unsigned char*) "136", .len = 3},
    {.chars = (unsigned char*) "137", .len = 3},
    {.chars = (unsigned char*) "138", .len = 3},
    {.chars = (unsigned char*) "139", .len = 3},
    {.chars = (unsigned char*) "140", .len = 3},
    {.chars = (unsigned char*) "141", .len = 3},
    {.chars = (unsigned char*) "142", .len = 3},
    {.chars = (unsigned char*) "143", .len = 3},
    {.chars = (unsigned char*) "144", .len = 3},
    {.chars = (unsigned char*) "145", .len = 3},
    {.chars = (unsigned char*) "146", .len = 3},
    {.chars = (unsigned char*) "147", .len = 3},
    {.chars = (unsigned char*) "148", .len = 3},
    {.chars = (unsigned char*) "149", .len = 3},
    {.chars = (unsigned char*) "150", .len = 3},
    {.chars = (unsigned char*) "151", .len = 3},
    {.chars = (unsigned char*) "152", .len = 3},
    {.chars = (unsigned char*) "153", .len = 3},
    {.chars = (unsigned char*) "154", .len = 3},
    {.chars = (unsigned char*) "155", .len = 3},
    {.chars = (unsigned char*) "156", .len = 3},
    {.chars = (unsigned char*) "157", .len = 3},
    {.chars = (unsigned char*) "158", .len = 3},
    {.chars = (unsigned char*) "159", .len = 3},
    {.chars = (unsigned char*) "160", .len = 3},
    {.chars = (unsigned char*) "161", .len = 3},
    {.chars = (unsigned char*) "162", .len = 3},
    {.chars = (unsigned char*) "163", .len = 3},
    {.chars = (unsigned char*) "164", .len = 3},
    {.chars = (unsigned char*) "165", .len = 3},
    {.chars = (unsigned char*) "166", .len = 3},
    {.chars = (unsigned char*) "167", .len = 3},
    {.chars = (unsigned char*) "168", .len = 3},
    {.chars = (unsigned char*) "169", .len = 3},
    {.chars = (unsigned char*) "170", .len = 3},
    {.chars = (unsigned char*) "171", .len = 3},
    {.chars = (unsigned char*) "172", .len = 3},
    {.chars = (unsigned char*) "173", .len = 3},
    {.chars = (unsigned char*) "174", .len = 3},
    {.chars = (unsigned char*) "175", .len = 3},
    {.chars = (unsigned char*) "176", .len = 3},
    {.chars = (unsigned char*) "177", .len = 3},
    {.chars = (unsigned char*) "178", .len = 3},
    {.chars = (unsigned char*) "179", .len = 3},
    {.chars = (unsigned char*) "180", .len = 3},
    {.chars = (unsigned char*) "181", .len = 3},
    {.chars = (unsigned char*) "182", .len = 3},
    {.chars = (unsigned char*) "183", .len = 3},
    {.chars = (unsigned char*) "184", .len = 3},
    {.chars = (unsigned char*) "185", .len = 3},
    {.chars = (unsigned char*) "186", .len = 3},
    {.chars = (unsigned char*) "187", .len = 3},
    {.chars = (unsigned char*) "188", .len = 3},
    {.chars = (unsigned char*) "189", .len = 3},
    {.chars = (unsigned char*) "190", .len = 3},
    {.chars = (unsigned char*) "191", .len = 3},
    {.chars = (unsigned char*) "192", .len = 3},
    {.chars = (unsigned char*) "193", .len = 3},
    {.chars = (unsigned char*) "194", .len = 3},
    {.chars = (unsigned char*) "195", .len = 3},
    {.chars = (unsigned char*) "196", .len = 3},
    {.chars = (unsigned char*) "197", .len = 3},
    {.chars = (unsigned char*) "198", .len = 3},
    {.chars = (unsigned char*) "199", .len = 3},
    {.chars = (unsigned char*) "200", .len = 3},
    {.chars = (unsigned char*) "201", .len = 3},
    {.chars = (unsigned char*) "202", .len = 3},
    {.chars = (unsigned char*) "203", .len = 3},
    {.chars = (unsigned char*) "204", .len = 3},
    {.chars = (unsigned char*) "205", .len = 3},
    {.chars = (unsigned char*) "206", .len = 3},
    {.chars = (unsigned char*) "207", .len = 3},
    {.chars = (unsigned char*) "208", .len = 3},
    {.chars = (unsigned char*) "209", .len = 3},
    {.chars = (unsigned char*) "210", .len = 3},
    {.chars = (unsigned char*) "211", .len = 3},
    {.chars = (unsigned char*) "212", .len = 3},
    {.chars = (unsigned char*) "213", .len = 3},
    {.chars = (unsigned char*) "214", .len = 3},
    {.chars = (unsigned char*) "215", .len = 3},
    {.chars = (unsigned char*) "216", .len = 3},
    {.chars = (unsigned char*) "217", .len = 3},
    {.chars = (unsigned char*) "218", .len = 3},
    {.chars = (unsigned char*) "219", .len = 3},
    {.chars = (unsigned char*) "220", .len = 3},
    {.chars = (unsigned char*) "221", .len = 3},
    {.chars = (unsigned char*) "222", .len = 3},
    {.chars = (unsigned char*) "223", .len = 3},
    {.chars = (unsigned char*) "224", .len = 3},
    {.chars = (unsigned char*) "225", .len = 3},
    {.chars = (unsigned char*) "226", .len = 3},
    {.chars = (unsigned char*) "227", .len = 3},
    {.chars = (unsigned char*) "228", .len = 3},
    {.chars = (unsigned char*) "229", .len = 3},
    {.chars = (unsigned char*) "230", .len = 3},
    {.chars = (unsigned char*) "231", .len = 3},
    {.chars = (unsigned char*) "232", .len = 3},
    {.chars = (unsigned char*) "233", .len = 3},
    {.chars = (unsigned char*) "234", .len = 3},
    {.chars = (unsigned char*) "235", .len = 3},
    {.chars = (unsigned char*) "236", .len = 3},
    {.chars = (unsigned char*) "237", .len = 3},
    {.chars = (unsigned char*) "238", .len = 3},
    {.chars = (unsigned char*) "239", .len = 3},
    {.chars = (unsigned char*) "240", .len = 3},
    {.chars = (unsigned char*) "241", .len = 3},
    {.chars = (unsigned char*) "242", .len = 3},
    {.chars = (unsigned char*) "243", .len = 3},
    {.chars = (unsigned char*) "244", .len = 3},
    {.chars = (unsigned char*) "245", .len = 3},
    {.chars = (unsigned char*) "246", .len = 3},
    {.chars = (unsigned char*) "247", .len = 3},
    {.chars = (unsigned char*) "248", .len = 3},
    {.chars = (unsigned char*) "249", .len = 3},
    {.chars = (unsigned char*) "250", .len = 3},
    {.chars = (unsigned char*) "251", .len = 3},
    {.chars = (unsigned char*) "252", .len = 3},
    {.chars = (unsigned char*) "253", .len = 3},
    {.chars = (unsigned char*) "254", .len = 3},
    {.chars = (unsigned char*) "255", .len = 3},
};

static const Neat_String_View neat__sc_to_string[] = {
    {.chars = (unsigned char*) "0", .len = 1},
    {.chars = (unsigned char*) "1", .len = 1},
    {.chars = (unsigned char*) "2", .len = 1},
    {.chars = (unsigned char*) "3", .len = 1},
    {.chars = (unsigned char*) "4", .len = 1},
    {.chars = (unsigned char*) "5", .len = 1},
    {.chars = (unsigned char*) "6", .len = 1},
    {.chars = (unsigned char*) "7", .len = 1},
    {.chars = (unsigned char*) "8", .len = 1},
    {.chars = (unsigned char*) "9", .len = 1},
    {.chars = (unsigned char*) "10", .len = 2},
    {.chars = (unsigned char*) "11", .len = 2},
    {.chars = (unsigned char*) "12", .len = 2},
    {.chars = (unsigned char*) "13", .len = 2},
    {.chars = (unsigned char*) "14", .len = 2},
    {.chars = (unsigned char*) "15", .len = 2},
    {.chars = (unsigned char*) "16", .len = 2},
    {.chars = (unsigned char*) "17", .len = 2},
    {.chars = (unsigned char*) "18", .len = 2},
    {.chars = (unsigned char*) "19", .len = 2},
    {.chars = (unsigned char*) "20", .len = 2},
    {.chars = (unsigned char*) "21", .len = 2},
    {.chars = (unsigned char*) "22", .len = 2},
    {.chars = (unsigned char*) "23", .len = 2},
    {.chars = (unsigned char*) "24", .len = 2},
    {.chars = (unsigned char*) "25", .len = 2},
    {.chars = (unsigned char*) "26", .len = 2},
    {.chars = (unsigned char*) "27", .len = 2},
    {.chars = (unsigned char*) "28", .len = 2},
    {.chars = (unsigned char*) "29", .len = 2},
    {.chars = (unsigned char*) "30", .len = 2},
    {.chars = (unsigned char*) "31", .len = 2},
    {.chars = (unsigned char*) "32", .len = 2},
    {.chars = (unsigned char*) "33", .len = 2},
    {.chars = (unsigned char*) "34", .len = 2},
    {.chars = (unsigned char*) "35", .len = 2},
    {.chars = (unsigned char*) "36", .len = 2},
    {.chars = (unsigned char*) "37", .len = 2},
    {.chars = (unsigned char*) "38", .len = 2},
    {.chars = (unsigned char*) "39", .len = 2},
    {.chars = (unsigned char*) "40", .len = 2},
    {.chars = (unsigned char*) "41", .len = 2},
    {.chars = (unsigned char*) "42", .len = 2},
    {.chars = (unsigned char*) "43", .len = 2},
    {.chars = (unsigned char*) "44", .len = 2},
    {.chars = (unsigned char*) "45", .len = 2},
    {.chars = (unsigned char*) "46", .len = 2},
    {.chars = (unsigned char*) "47", .len = 2},
    {.chars = (unsigned char*) "48", .len = 2},
    {.chars = (unsigned char*) "49", .len = 2},
    {.chars = (unsigned char*) "50", .len = 2},
    {.chars = (unsigned char*) "51", .len = 2},
    {.chars = (unsigned char*) "52", .len = 2},
    {.chars = (unsigned char*) "53", .len = 2},
    {.chars = (unsigned char*) "54", .len = 2},
    {.chars = (unsigned char*) "55", .len = 2},
    {.chars = (unsigned char*) "56", .len = 2},
    {.chars = (unsigned char*) "57", .len = 2},
    {.chars = (unsigned char*) "58", .len = 2},
    {.chars = (unsigned char*) "59", .len = 2},
    {.chars = (unsigned char*) "60", .len = 2},
    {.chars = (unsigned char*) "61", .len = 2},
    {.chars = (unsigned char*) "62", .len = 2},
    {.chars = (unsigned char*) "63", .len = 2},
    {.chars = (unsigned char*) "64", .len = 2},
    {.chars = (unsigned char*) "65", .len = 2},
    {.chars = (unsigned char*) "66", .len = 2},
    {.chars = (unsigned char*) "67", .len = 2},
    {.chars = (unsigned char*) "68", .len = 2},
    {.chars = (unsigned char*) "69", .len = 2},
    {.chars = (unsigned char*) "70", .len = 2},
    {.chars = (unsigned char*) "71", .len = 2},
    {.chars = (unsigned char*) "72", .len = 2},
    {.chars = (unsigned char*) "73", .len = 2},
    {.chars = (unsigned char*) "74", .len = 2},
    {.chars = (unsigned char*) "75", .len = 2},
    {.chars = (unsigned char*) "76", .len = 2},
    {.chars = (unsigned char*) "77", .len = 2},
    {.chars = (unsigned char*) "78", .len = 2},
    {.chars = (unsigned char*) "79", .len = 2},
    {.chars = (unsigned char*) "80", .len = 2},
    {.chars = (unsigned char*) "81", .len = 2},
    {.chars = (unsigned char*) "82", .len = 2},
    {.chars = (unsigned char*) "83", .len = 2},
    {.chars = (unsigned char*) "84", .len = 2},
    {.chars = (unsigned char*) "85", .len = 2},
    {.chars = (unsigned char*) "86", .len = 2},
    {.chars = (unsigned char*) "87", .len = 2},
    {.chars = (unsigned char*) "88", .len = 2},
    {.chars = (unsigned char*) "89", .len = 2},
    {.chars = (unsigned char*) "90", .len = 2},
    {.chars = (unsigned char*) "91", .len = 2},
    {.chars = (unsigned char*) "92", .len = 2},
    {.chars = (unsigned char*) "93", .len = 2},
    {.chars = (unsigned char*) "94", .len = 2},
    {.chars = (unsigned char*) "95", .len = 2},
    {.chars = (unsigned char*) "96", .len = 2},
    {.chars = (unsigned char*) "97", .len = 2},
    {.chars = (unsigned char*) "98", .len = 2},
    {.chars = (unsigned char*) "99", .len = 2},
    {.chars = (unsigned char*) "100", .len = 3},
    {.chars = (unsigned char*) "101", .len = 3},
    {.chars = (unsigned char*) "102", .len = 3},
    {.chars = (unsigned char*) "103", .len = 3},
    {.chars = (unsigned char*) "104", .len = 3},
    {.chars = (unsigned char*) "105", .len = 3},
    {.chars = (unsigned char*) "106", .len = 3},
    {.chars = (unsigned char*) "107", .len = 3},
    {.chars = (unsigned char*) "108", .len = 3},
    {.chars = (unsigned char*) "109", .len = 3},
    {.chars = (unsigned char*) "110", .len = 3},
    {.chars = (unsigned char*) "111", .len = 3},
    {.chars = (unsigned char*) "112", .len = 3},
    {.chars = (unsigned char*) "113", .len = 3},
    {.chars = (unsigned char*) "114", .len = 3},
    {.chars = (unsigned char*) "115", .len = 3},
    {.chars = (unsigned char*) "116", .len = 3},
    {.chars = (unsigned char*) "117", .len = 3},
    {.chars = (unsigned char*) "118", .len = 3},
    {.chars = (unsigned char*) "119", .len = 3},
    {.chars = (unsigned char*) "120", .len = 3},
    {.chars = (unsigned char*) "121", .len = 3},
    {.chars = (unsigned char*) "122", .len = 3},
    {.chars = (unsigned char*) "123", .len = 3},
    {.chars = (unsigned char*) "124", .len = 3},
    {.chars = (unsigned char*) "125", .len = 3},
    {.chars = (unsigned char*) "126", .len = 3},
    {.chars = (unsigned char*) "127", .len = 3},
    {.chars = (unsigned char*) "-128", .len = 4},
    {.chars = (unsigned char*) "-127", .len = 4},
    {.chars = (unsigned char*) "-126", .len = 4},
    {.chars = (unsigned char*) "-125", .len = 4},
    {.chars = (unsigned char*) "-124", .len = 4},
    {.chars = (unsigned char*) "-123", .len = 4},
    {.chars = (unsigned char*) "-122", .len = 4},
    {.chars = (unsigned char*) "-121", .len = 4},
    {.chars = (unsigned char*) "-120", .len = 4},
    {.chars = (unsigned char*) "-119", .len = 4},
    {.chars = (unsigned char*) "-118", .len = 4},
    {.chars = (unsigned char*) "-117", .len = 4},
    {.chars = (unsigned char*) "-116", .len = 4},
    {.chars = (unsigned char*) "-115", .len = 4},
    {.chars = (unsigned char*) "-114", .len = 4},
    {.chars = (unsigned char*) "-113", .len = 4},
    {.chars = (unsigned char*) "-112", .len = 4},
    {.chars = (unsigned char*) "-111", .len = 4},
    {.chars = (unsigned char*) "-110", .len = 4},
    {.chars = (unsigned char*) "-109", .len = 4},
    {.chars = (unsigned char*) "-108", .len = 4},
    {.chars = (unsigned char*) "-107", .len = 4},
    {.chars = (unsigned char*) "-106", .len = 4},
    {.chars = (unsigned char*) "-105", .len = 4},
    {.chars = (unsigned char*) "-104", .len = 4},
    {.chars = (unsigned char*) "-103", .len = 4},
    {.chars = (unsigned char*) "-102", .len = 4},
    {.chars = (unsigned char*) "-101", .len = 4},
    {.chars = (unsigned char*) "-100", .len = 4},
    {.chars = (unsigned char*) "-99", .len = 3},
    {.chars = (unsigned char*) "-98", .len = 3},
    {.chars = (unsigned char*) "-97", .len = 3},
    {.chars = (unsigned char*) "-96", .len = 3},
    {.chars = (unsigned char*) "-95", .len = 3},
    {.chars = (unsigned char*) "-94", .len = 3},
    {.chars = (unsigned char*) "-93", .len = 3},
    {.chars = (unsigned char*) "-92", .len = 3},
    {.chars = (unsigned char*) "-91", .len = 3},
    {.chars = (unsigned char*) "-90", .len = 3},
    {.chars = (unsigned char*) "-89", .len = 3},
    {.chars = (unsigned char*) "-88", .len = 3},
    {.chars = (unsigned char*) "-87", .len = 3},
    {.chars = (unsigned char*) "-86", .len = 3},
    {.chars = (unsigned char*) "-85", .len = 3},
    {.chars = (unsigned char*) "-84", .len = 3},
    {.chars = (unsigned char*) "-83", .len = 3},
    {.chars = (unsigned char*) "-82", .len = 3},
    {.chars = (unsigned char*) "-81", .len = 3},
    {.chars = (unsigned char*) "-80", .len = 3},
    {.chars = (unsigned char*) "-79", .len = 3},
    {.chars = (unsigned char*) "-78", .len = 3},
    {.chars = (unsigned char*) "-77", .len = 3},
    {.chars = (unsigned char*) "-76", .len = 3},
    {.chars = (unsigned char*) "-75", .len = 3},
    {.chars = (unsigned char*) "-74", .len = 3},
    {.chars = (unsigned char*) "-73", .len = 3},
    {.chars = (unsigned char*) "-72", .len = 3},
    {.chars = (unsigned char*) "-71", .len = 3},
    {.chars = (unsigned char*) "-70", .len = 3},
    {.chars = (unsigned char*) "-69", .len = 3},
    {.chars = (unsigned char*) "-68", .len = 3},
    {.chars = (unsigned char*) "-67", .len = 3},
    {.chars = (unsigned char*) "-66", .len = 3},
    {.chars = (unsigned char*) "-65", .len = 3},
    {.chars = (unsigned char*) "-64", .len = 3},
    {.chars = (unsigned char*) "-63", .len = 3},
    {.chars = (unsigned char*) "-62", .len = 3},
    {.chars = (unsigned char*) "-61", .len = 3},
    {.chars = (unsigned char*) "-60", .len = 3},
    {.chars = (unsigned char*) "-59", .len = 3},
    {.chars = (unsigned char*) "-58", .len = 3},
    {.chars = (unsigned char*) "-57", .len = 3},
    {.chars = (unsigned char*) "-56", .len = 3},
    {.chars = (unsigned char*) "-55", .len = 3},
    {.chars = (unsigned char*) "-54", .len = 3},
    {.chars = (unsigned char*) "-53", .len = 3},
    {.chars = (unsigned char*) "-52", .len = 3},
    {.chars = (unsigned char*) "-51", .len = 3},
    {.chars = (unsigned char*) "-50", .len = 3},
    {.chars = (unsigned char*) "-49", .len = 3},
    {.chars = (unsigned char*) "-48", .len = 3},
    {.chars = (unsigned char*) "-47", .len = 3},
    {.chars = (unsigned char*) "-46", .len = 3},
    {.chars = (unsigned char*) "-45", .len = 3},
    {.chars = (unsigned char*) "-44", .len = 3},
    {.chars = (unsigned char*) "-43", .len = 3},
    {.chars = (unsigned char*) "-42", .len = 3},
    {.chars = (unsigned char*) "-41", .len = 3},
    {.chars = (unsigned char*) "-40", .len = 3},
    {.chars = (unsigned char*) "-39", .len = 3},
    {.chars = (unsigned char*) "-38", .len = 3},
    {.chars = (unsigned char*) "-37", .len = 3},
    {.chars = (unsigned char*) "-36", .len = 3},
    {.chars = (unsigned char*) "-35", .len = 3},
    {.chars = (unsigned char*) "-34", .len = 3},
    {.chars = (unsigned char*) "-33", .len = 3},
    {.chars = (unsigned char*) "-32", .len = 3},
    {.chars = (unsigned char*) "-31", .len = 3},
    {.chars = (unsigned char*) "-30", .len = 3},
    {.chars = (unsigned char*) "-29", .len = 3},
    {.chars = (unsigned char*) "-28", .len = 3},
    {.chars = (unsigned char*) "-27", .len = 3},
    {.chars = (unsigned char*) "-26", .len = 3},
    {.chars = (unsigned char*) "-25", .len = 3},
    {.chars = (unsigned char*) "-24", .len = 3},
    {.chars = (unsigned char*) "-23", .len = 3},
    {.chars = (unsigned char*) "-22", .len = 3},
    {.chars = (unsigned char*) "-21", .len = 3},
    {.chars = (unsigned char*) "-20", .len = 3},
    {.chars = (unsigned char*) "-19", .len = 3},
    {.chars = (unsigned char*) "-18", .len = 3},
    {.chars = (unsigned char*) "-17", .len = 3},
    {.chars = (unsigned char*) "-16", .len = 3},
    {.chars = (unsigned char*) "-15", .len = 3},
    {.chars = (unsigned char*) "-14", .len = 3},
    {.chars = (unsigned char*) "-13", .len = 3},
    {.chars = (unsigned char*) "-12", .len = 3},
    {.chars = (unsigned char*) "-11", .len = 3},
    {.chars = (unsigned char*) "-10", .len = 3},
    {.chars = (unsigned char*) "-9", .len = 2},
    {.chars = (unsigned char*) "-8", .len = 2},
    {.chars = (unsigned char*) "-7", .len = 2},
    {.chars = (unsigned char*) "-6", .len = 2},
    {.chars = (unsigned char*) "-5", .len = 2},
    {.chars = (unsigned char*) "-4", .len = 2},
    {.chars = (unsigned char*) "-3", .len = 2},
    {.chars = (unsigned char*) "-2", .len = 2},
    {.chars = (unsigned char*) "-1", .len = 2}
};

const char neat__byte_to_hex[][2] = 
{
    {'0', '0'},
    {'0', '1'},
    {'0', '2'},
    {'0', '3'},
    {'0', '4'},
    {'0', '5'},
    {'0', '6'},
    {'0', '7'},
    {'0', '8'},
    {'0', '9'},
    {'0', 'a'},
    {'0', 'b'},
    {'0', 'c'},
    {'0', 'd'},
    {'0', 'e'},
    {'0', 'f'},
    {'1', '0'},
    {'1', '1'},
    {'1', '2'},
    {'1', '3'},
    {'1', '4'},
    {'1', '5'},
    {'1', '6'},
    {'1', '7'},
    {'1', '8'},
    {'1', '9'},
    {'1', 'a'},
    {'1', 'b'},
    {'1', 'c'},
    {'1', 'd'},
    {'1', 'e'},
    {'1', 'f'},
    {'2', '0'},
    {'2', '1'},
    {'2', '2'},
    {'2', '3'},
    {'2', '4'},
    {'2', '5'},
    {'2', '6'},
    {'2', '7'},
    {'2', '8'},
    {'2', '9'},
    {'2', 'a'},
    {'2', 'b'},
    {'2', 'c'},
    {'2', 'd'},
    {'2', 'e'},
    {'2', 'f'},
    {'3', '0'},
    {'3', '1'},
    {'3', '2'},
    {'3', '3'},
    {'3', '4'},
    {'3', '5'},
    {'3', '6'},
    {'3', '7'},
    {'3', '8'},
    {'3', '9'},
    {'3', 'a'},
    {'3', 'b'},
    {'3', 'c'},
    {'3', 'd'},
    {'3', 'e'},
    {'3', 'f'},
    {'4', '0'},
    {'4', '1'},
    {'4', '2'},
    {'4', '3'},
    {'4', '4'},
    {'4', '5'},
    {'4', '6'},
    {'4', '7'},
    {'4', '8'},
    {'4', '9'},
    {'4', 'a'},
    {'4', 'b'},
    {'4', 'c'},
    {'4', 'd'},
    {'4', 'e'},
    {'4', 'f'},
    {'5', '0'},
    {'5', '1'},
    {'5', '2'},
    {'5', '3'},
    {'5', '4'},
    {'5', '5'},
    {'5', '6'},
    {'5', '7'},
    {'5', '8'},
    {'5', '9'},
    {'5', 'a'},
    {'5', 'b'},
    {'5', 'c'},
    {'5', 'd'},
    {'5', 'e'},
    {'5', 'f'},
    {'6', '0'},
    {'6', '1'},
    {'6', '2'},
    {'6', '3'},
    {'6', '4'},
    {'6', '5'},
    {'6', '6'},
    {'6', '7'},
    {'6', '8'},
    {'6', '9'},
    {'6', 'a'},
    {'6', 'b'},
    {'6', 'c'},
    {'6', 'd'},
    {'6', 'e'},
    {'6', 'f'},
    {'7', '0'},
    {'7', '1'},
    {'7', '2'},
    {'7', '3'},
    {'7', '4'},
    {'7', '5'},
    {'7', '6'},
    {'7', '7'},
    {'7', '8'},
    {'7', '9'},
    {'7', 'a'},
    {'7', 'b'},
    {'7', 'c'},
    {'7', 'd'},
    {'7', 'e'},
    {'7', 'f'},
    {'8', '0'},
    {'8', '1'},
    {'8', '2'},
    {'8', '3'},
    {'8', '4'},
    {'8', '5'},
    {'8', '6'},
    {'8', '7'},
    {'8', '8'},
    {'8', '9'},
    {'8', 'a'},
    {'8', 'b'},
    {'8', 'c'},
    {'8', 'd'},
    {'8', 'e'},
    {'8', 'f'},
    {'9', '0'},
    {'9', '1'},
    {'9', '2'},
    {'9', '3'},
    {'9', '4'},
    {'9', '5'},
    {'9', '6'},
    {'9', '7'},
    {'9', '8'},
    {'9', '9'},
    {'9', 'a'},
    {'9', 'b'},
    {'9', 'c'},
    {'9', 'd'},
    {'9', 'e'},
    {'9', 'f'},
    {'a', '0'},
    {'a', '1'},
    {'a', '2'},
    {'a', '3'},
    {'a', '4'},
    {'a', '5'},
    {'a', '6'},
    {'a', '7'},
    {'a', '8'},
    {'a', '9'},
    {'a', 'a'},
    {'a', 'b'},
    {'a', 'c'},
    {'a', 'd'},
    {'a', 'e'},
    {'a', 'f'},
    {'b', '0'},
    {'b', '1'},
    {'b', '2'},
    {'b', '3'},
    {'b', '4'},
    {'b', '5'},
    {'b', '6'},
    {'b', '7'},
    {'b', '8'},
    {'b', '9'},
    {'b', 'a'},
    {'b', 'b'},
    {'b', 'c'},
    {'b', 'd'},
    {'b', 'e'},
    {'b', 'f'},
    {'c', '0'},
    {'c', '1'},
    {'c', '2'},
    {'c', '3'},
    {'c', '4'},
    {'c', '5'},
    {'c', '6'},
    {'c', '7'},
    {'c', '8'},
    {'c', '9'},
    {'c', 'a'},
    {'c', 'b'},
    {'c', 'c'},
    {'c', 'd'},
    {'c', 'e'},
    {'c', 'f'},
    {'d', '0'},
    {'d', '1'},
    {'d', '2'},
    {'d', '3'},
    {'d', '4'},
    {'d', '5'},
    {'d', '6'},
    {'d', '7'},
    {'d', '8'},
    {'d', '9'},
    {'d', 'a'},
    {'d', 'b'},
    {'d', 'c'},
    {'d', 'd'},
    {'d', 'e'},
    {'d', 'f'},
    {'e', '0'},
    {'e', '1'},
    {'e', '2'},
    {'e', '3'},
    {'e', '4'},
    {'e', '5'},
    {'e', '6'},
    {'e', '7'},
    {'e', '8'},
    {'e', '9'},
    {'e', 'a'},
    {'e', 'b'},
    {'e', 'c'},
    {'e', 'd'},
    {'e', 'e'},
    {'e', 'f'},
    {'f', '0'},
    {'f', '1'},
    {'f', '2'},
    {'f', '3'},
    {'f', '4'},
    {'f', '5'},
    {'f', '6'},
    {'f', '7'},
    {'f', '8'},
    {'f', '9'},
    {'f', 'a'},
    {'f', 'b'},
    {'f', 'c'},
    {'f', 'd'},
    {'f', 'e'},
    {'f', 'f'}
};

_Thread_local Neat_DString neat__fprint_tostr_dynamic_buffer = {
    .allocator = &neat__default_allocator
};

NEAT_API Neat__Fixed_Mut_String_Ref neat__buf_as_fmutstr_ref(Neat_Buffer buf, unsigned int *len_ptr)
{
    *len_ptr = strlen((char*) buf.ptr);
    Neat__Fixed_Mut_String_Ref ret = {
        .chars = buf.ptr,
        .cap = buf.cap,
        .len = len_ptr
    };
    return ret;
}

NEAT_API Neat__Fixed_Mut_String_Ref neat__strbuf_ptr_as_fmutstr_ref(Neat_String_Buffer *strbuf)
{
    Neat__Fixed_Mut_String_Ref ret = {
        .chars = strbuf->chars,
        .cap = strbuf->cap,
        .len = &strbuf->len
    };
    return ret;
}

NEAT_API Neat__Fixed_Mut_String_Ref neat__dstr_ptr_as_fmutstr_ref(Neat_DString *dstr)
{
    Neat__Fixed_Mut_String_Ref ret = {
        .chars = dstr->chars,
        .cap = dstr->cap,
        .len = &dstr->len
    };
    return ret;
}

NEAT_PRIVATE Neat_Allocation neat__default_allocator_alloc(Neat_Allocator *ctx, size_t alignment, size_t n)
{
    (void) alignment;
    (void) ctx;
    void *mem = malloc(n);
    return (Neat_Allocation){
        .ptr = mem,
        .n = n
    };
}

NEAT_PRIVATE void neat__default_allocator_dealloc(Neat_Allocator *ctx, void *ptr, size_t n)
{
    (void) ctx;
    (void) n;
    free(ptr);
}

NEAT_PRIVATE Neat_Allocation neat__default_allocator_realloc(Neat_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) ctx;
    (void) alignment;
    (void) old_size;
    void *mem = realloc(ptr, new_size);
    return (Neat_Allocation){
        .ptr = mem,
        .n = new_size
    };
}

NEAT_PRIVATE Neat_Allocation neat__dstr_append_allocator_alloc(Neat_Allocator *allocator, size_t alignment, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) alignment;
    (void) n;
    return (Neat_Allocation){0};
}

NEAT_PRIVATE void neat__dstr_append_allocator_dealloc(Neat_Allocator *allocator, void *ptr, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) ptr;
    (void) n;
}

NEAT_PRIVATE Neat_Allocation neat__dstr_append_allocator_realloc(Neat_Allocator *allocator, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) alignment;
    
    Neat__DString_Append_Allocator *dstr_append_allocator = (__typeof__(dstr_append_allocator)) allocator;
    
    Neat_DString *owner = dstr_append_allocator->owner;
    
    assert(old_size == owner->cap - owner->len);
    assert(((unsigned char*)ptr - owner->chars) == owner->len);
    
    neat_dstr_ensure_cap(owner, owner->cap + (new_size - old_size));
    return (Neat_Allocation){
        .ptr = owner->chars + owner->len,
        .n = owner->cap - owner->len
    };
}

NEAT_API Neat_Allocation neat__allocator_invoke_alloc(Neat_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb)
{
    return allocator->alloc(allocator, alignment, nb * obj_size);
}

NEAT_API void neat__allocator_invoke_dealloc(Neat_Allocator *allocator, void *ptr, size_t obj_size, size_t nb)
{
    allocator->dealloc(allocator, ptr, nb * obj_size);
}

NEAT_API Neat_Allocation neat__allocator_invoke_realloc(Neat_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb)
{
    return allocator->realloc(allocator, ptr, alignment, old_nb * obj_size, new_nb * obj_size);
}

NEAT_API Neat_Allocator *neat_get_default_allocator()
{
    return &neat__default_allocator;
}

NEAT_PRIVATE void neat__make_dstr_append_allocator(Neat_DString *dstr, Neat__DString_Append_Allocator *out)
{
    *out = (Neat__DString_Append_Allocator){
        .base = {
            .alloc   = neat__dstr_append_allocator_alloc,
            .dealloc = neat__dstr_append_allocator_dealloc,
            .realloc = neat__dstr_append_allocator_realloc,
        },
        .owner = dstr
    };
}

NEAT_PRIVATE Neat_DString neat__make_appender_dstr(Neat_DString *owner, Neat__DString_Append_Allocator *allocator)
{
    neat__make_dstr_append_allocator(owner, allocator);
    return (Neat_DString){
        .allocator = (void*) allocator,
        .cap = owner->cap - owner->len,
        .len = 0,
        .chars = owner->chars + owner->len
    };
}

NEAT_PRIVATE Neat_String_Buffer neat__make_appender_strbuf(Neat_Mut_String_Ref owner)
{
    return (Neat_String_Buffer){
        .cap = neat_str_cap(owner) - neat__mutstr_ref_len(owner),
        .len = 0,
        .chars = (unsigned char*)neat_str_chars(owner) + neat__mutstr_ref_len(owner)
    };
}

NEAT_API Neat_Mut_String_Ref neat__make_appender_mutstr_ref(Neat_Mut_String_Ref owner, Neat_Appender_State *state)
{
    switch(owner.ty)
    {
        case NEAT__DSTR_TY    :
            state->appender_dstr = neat__make_appender_dstr(owner.str.dstr, &state->dstr_append_allocator);
            return neat__dstr_ptr_as_mutstr_ref(&state->appender_dstr);
        case NEAT__STRBUF_TY  :
        case NEAT__BUF_TY     :
            ;
            Neat_Mut_String_Ref ret = {.ty = NEAT__STRBUF_TY};
            ret.str.strbuf = &state->appender_buf;
            *ret.str.strbuf = neat__make_appender_strbuf(owner);
            return ret;
        default               :
            unreachable();
    }
}

NEAT_PRIVATE unsigned int neat__uint_min(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

NEAT_PRIVATE unsigned int neat__uint_max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

NEAT_PRIVATE unsigned int neat__chars_strlen(const char *chars, unsigned int cap)
{
    char *str_end = memchr(chars, '\0', cap);
    unsigned int len;
    
    if(str_end != NULL)
    {
        len = str_end - chars;
    }
    else
    {
        len = cap - 1;
    }
    
    return len;
}

NEAT_API bool neat__is_strv_within(Neat_String_View base, Neat_String_View sub)
{
    uintptr_t begin = (uintptr_t) base.chars;
    uintptr_t end = (uintptr_t) (base.chars + base.len);
    uintptr_t sub_begin = (uintptr_t) sub.chars;
    return sub_begin >= begin && sub_begin < end;
}

NEAT__NODISCARD("discarding a new DString may cause memory leak")
NEAT_API Neat_DString neat__dstr_init(unsigned int cap, Neat_Allocator *allocator)
{
    Neat_DString ret = { 0 };
    
    ret.allocator = allocator;
    size_t actual_allocated_cap = 0;
    
    if(cap > 0)
    {
        Neat_Allocation allocation = neat_alloc(allocator, unsigned char, cap);
        ret.chars = allocation.ptr;
        actual_allocated_cap = allocation.n;
    }
    ret.cap = actual_allocated_cap;
    
    if(ret.chars != NULL && ret.cap > 0)
    {
        ret.chars[0] = '\0';
    }
    
    return ret;
}

NEAT_API Neat_DString neat__dstr_init_from(const Neat_String_View str, Neat_Allocator *allocator)
{
    Neat_DString ret = neat__dstr_init(str.len + 1, allocator);
    
    neat__dstr_copy(&ret, str);
    
    return ret;
}

NEAT_API void neat__dstr_deinit(Neat_DString *dstr)
{
    neat_dealloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap);
    dstr->cap = 0;
    dstr->len = 0;
    dstr->chars = NULL;
}

NEAT_API void neat__dstr_shrink_to_fit(Neat_DString *dstr)
{
    Neat_Allocation allocation = neat_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, dstr->len + 1);
    dstr->chars = allocation.ptr;
    dstr->cap = allocation.n;
}

NEAT_PRIVATE Neat_Error neat__dstr_maybe_grow(Neat_DString *dstr, unsigned int len_to_append)
{
    return neat__dstr_ensure_cap(dstr, dstr->len + len_to_append + 1);
}

NEAT_API Neat_Error neat__dstr_append_strv(Neat_DString *dstr, const Neat_String_View src)
{
    Neat_String_View to_append = src;
    Neat_Error err = (Neat_Error){NEAT_OK};
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), to_append))
    {
        unsigned int begin_idx = to_append.chars - dstr->chars;
        err = neat__dstr_maybe_grow(dstr, to_append.len + 1);
        to_append = (Neat_String_View){
            .len   = to_append.len,
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = neat__dstr_maybe_grow(dstr, to_append.len);
    }
    
    if(err.ec == NEAT_OK)
    {
        memmove(dstr->chars + dstr->len, to_append.chars, to_append.len * sizeof(unsigned char));
        
        dstr->len += to_append.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

NEAT_API Neat_Error neat__dstr_prepend_strv(Neat_DString *dstr, const Neat_String_View src)
{
    Neat_String_View to_prepend = src;
    Neat_Error err = (Neat_Error){NEAT_OK};
    
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        err = neat__dstr_maybe_grow(dstr, src.len);
        to_prepend = (Neat_String_View){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = neat__dstr_maybe_grow(dstr, to_prepend.len);
    }
    
    if(err.ec == NEAT_OK)
    {
        memmove(dstr->chars + to_prepend.len, dstr->chars, dstr->len);
        memmove(dstr->chars, to_prepend.chars, to_prepend.len);
        
        dstr->len += to_prepend.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

NEAT_API Neat_Error neat__dstr_insert_strv(Neat_DString *dstr, const Neat_String_View src, unsigned int idx)
{
    if(idx > dstr->len)
    {
        return (Neat_Error){NEAT_INDEX_OUT_OF_BOUNDS};
    }
    
    Neat_String_View to_insert = src;
    
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        neat__dstr_maybe_grow(dstr, src.len);
        to_insert = (Neat_String_View){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        neat__dstr_maybe_grow(dstr, to_insert.len);
    }
    
    memmove(dstr->chars + idx + to_insert.len, dstr->chars + idx, dstr->len - idx);
    memmove(dstr->chars + idx, to_insert.chars, to_insert.len);
    
    dstr->len += to_insert.len;
    dstr->chars[dstr->len] = '\0';
    
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__dstr_ensure_cap(Neat_DString *dstr, unsigned int at_least)
{
    if(dstr->cap < at_least)
    {
        unsigned char *save = dstr->chars;
        size_t new_cap = neat__uint_max(at_least, dstr->cap * 2);
        Neat_Allocation allocation = neat_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, new_cap);
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        
        if(dstr->chars == NULL)
        {
            dstr->chars = save;
            return (Neat_Error){NEAT_ALLOC_ERR};
        }
        if(dstr->cap < new_cap)
        {
            return (Neat_Error){NEAT_ALLOC_ERR};
        }
    }
    
    return (Neat_Error){NEAT_OK};
}

NEAT_API char *neat__cstr_as_cstr(const char *str)
{
    return (char*) str;
}

NEAT_API char *neat__ucstr_as_cstr(const unsigned char *str)
{
    return (char*) str;
}

NEAT_API char *neat__dstr_as_cstr(const Neat_DString str)
{
    return (char*) str.chars;
}

NEAT_API char *neat__dstr_ptr_as_cstr(const Neat_DString *str)
{
    return (char*) str->chars;
}

NEAT_API char *neat__strv_as_cstr(const Neat_String_View str)
{
    return (char*) str.chars;
}

NEAT_API char *neat__strbuf_as_cstr(const Neat_String_Buffer str)
{
    return (char*) str.chars;
}

NEAT_API char *neat__strbuf_ptr_as_cstr(const Neat_String_Buffer *str)
{
    return (char*) str->chars;
}

NEAT_API char *neat__mutstr_ref_as_cstr(const Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return (char*) str.str.dstr->chars;
        case NEAT__STRBUF_TY   : return (char*) str.str.strbuf->chars;
        case NEAT__BUF_TY      : return (char*) str.str.buf.ptr;
        default                : unreachable();
    };
}

NEAT_API unsigned char neat__cstr_char_at(const char *str, unsigned int idx)
{
    return str[idx];
}

NEAT_API unsigned char neat__ucstr_char_at(const unsigned char *str, unsigned int idx)
{
    return str[idx];
}

NEAT_API unsigned char neat__dstr_char_at(const Neat_DString str, unsigned int idx)
{
    return str.chars[idx];
}

NEAT_API unsigned char neat__dstr_ptr_char_at(const Neat_DString *str, unsigned int idx)
{
    return str->chars[idx];
}

NEAT_API unsigned char neat__strv_char_at(const Neat_String_View str, unsigned int idx)
{
    return str.chars[idx];
}

NEAT_API unsigned char neat__strbuf_char_at(const Neat_String_Buffer str, unsigned int idx)
{
    return str.chars[idx];
}

NEAT_API unsigned char neat__strbuf_ptr_char_at(const Neat_String_Buffer *str, unsigned int idx)
{
    return str->chars[idx];
}

NEAT_API unsigned char neat__mutstr_ref_char_at(const Neat_Mut_String_Ref str, unsigned int idx)
{
    return neat__mutstr_ref_as_cstr(str)[idx];
}

NEAT_API Neat_Error neat__mutstr_ref_set_len(Neat_Mut_String_Ref str, unsigned int new_len)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     :
            str.str.dstr->len = new_len;
            assert(str.str.dstr->cap >= str.str.dstr->len);
            break;
        case NEAT__STRBUF_TY   :
            str.str.strbuf->len = new_len;
            assert(str.str.strbuf->cap >= str.str.strbuf->len);
            break;
        case NEAT__BUF_TY      :
            return (Neat_Error){NEAT_INCORRECT_TYPE};
        default                :
            unreachable();
    };
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__mutstr_ref_commit_appender(Neat_Mut_String_Ref owner, Neat_Mut_String_Ref appender)
{
    return neat__mutstr_ref_set_len(
        owner,
        neat__mutstr_ref_len(owner) + neat__mutstr_ref_len(appender) \
    );
}

NEAT_API unsigned int neat__dstr_cap(const Neat_DString str)
{
    return str.cap;
}

NEAT_API unsigned int neat__dstr_ptr_cap(const Neat_DString *str)
{
    return str->cap;
}

NEAT_API unsigned int neat__strbuf_cap(const Neat_String_Buffer str)
{
    return str.cap;
}

NEAT_API unsigned int neat__strbuf_ptr_cap(const Neat_String_Buffer *str)
{
    return str->cap;
}

NEAT_API unsigned int neat__buf_cap(const Neat_Buffer buf)
{
    return buf.cap;
}

NEAT_API unsigned int neat__mutstr_ref_cap(const Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return str.str.dstr->cap;
        case NEAT__STRBUF_TY   : return str.str.strbuf->cap;
        case NEAT__BUF_TY      : return str.str.buf.cap;
        default                : unreachable();
    };
}

NEAT_API unsigned int neat__mutstr_ref_len(const Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return str.str.dstr->len;
        case NEAT__STRBUF_TY   : return str.str.strbuf->len;
        case NEAT__BUF_TY      : return strlen((char*) str.str.buf.ptr);
        default                : unreachable();
    };
}

NEAT_API Neat_Error neat__fmutstr_ref_insert(Neat__Fixed_Mut_String_Ref dst, const Neat_String_View src, unsigned int idx)
{
    unsigned int len = *dst.len;
    if(idx > len)
    {
        return (Neat_Error){NEAT_INDEX_OUT_OF_BOUNDS};
    }
    
    unsigned int nb_chars_to_insert = neat__uint_min(dst.cap - len - 1, src.len);
    
    // shift right
    memmove(dst.chars + idx + nb_chars_to_insert, dst.chars + idx, len - idx);
    
    // insert the src
    memmove(dst.chars + idx, src.chars, nb_chars_to_insert);
    
    len += nb_chars_to_insert;
    
    *dst.len = len;
    
    return nb_chars_to_insert == src.len ? (Neat_Error){NEAT_OK} : (Neat_Error){NEAT_DST_TOO_SMALL};
}

NEAT_API Neat_Error neat__mutstr_ref_insert(Neat_Mut_String_Ref dst, const Neat_String_View src, unsigned int idx)
{
    switch(dst.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_insert_strv(dst.str.dstr, src, idx);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_insert(neat__fmutstr_ref(dst.str.strbuf), src, idx);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_insert(neat__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src, idx);
        default                : unreachable();
    };
}

NEAT_API bool neat__strv_equal(const Neat_String_View str1, const Neat_String_View str2)
{
    return
    (str1.len == str2.len) &&
    (memcmp(str1.chars, str2.chars, str1.len) == 0);
}

NEAT_API Neat_String_View neat__strv_find(const Neat_String_View hay, const Neat_String_View needle)
{
    if(hay.chars == NULL || needle.chars == NULL || hay.len == 0 || needle.len > hay.len)
        return (Neat_String_View){.chars = NULL, .len = 0};
    if(needle.len == 0)
        return (Neat_String_View){.chars = hay.chars, .len = 0};
    
    unsigned char *max_possible_ptr = &hay.chars[hay.len] - needle.len;
    unsigned char *first_char = hay.chars;
    unsigned int remaining_len = hay.len;
    
    while(first_char && first_char <= max_possible_ptr)
    {
        if(memcmp(first_char, needle.chars, needle.len) == 0)
            return (Neat_String_View){.chars = first_char, .len = needle.len};
        first_char = memchr(first_char + 1, needle.chars[0], remaining_len - 1);
        remaining_len = hay.len - (first_char - hay.chars);
    }
    
    return (Neat_String_View){.chars = NULL, .len = 0};
}

NEAT_API Neat_Error neat__fmutstr_ref_copy(Neat__Fixed_Mut_String_Ref dst, const Neat_String_View src)
{
    unsigned int chars_to_copy = neat__uint_min(src.len, dst.cap - 1);
    
    memmove(dst.chars, src.chars, chars_to_copy * sizeof(unsigned char));
    dst.chars[chars_to_copy] = '\0';
    
    *dst.len = chars_to_copy;
    
    return chars_to_copy == src.len ? (Neat_Error){NEAT_OK} : (Neat_Error){NEAT_DST_TOO_SMALL};
}

NEAT_API Neat_Error neat__dstr_copy(Neat_DString *dstr, Neat_String_View src)
{
    Neat_Error err = neat__dstr_ensure_cap(dstr, src.len + 1);
    
    if(err.ec == NEAT_OK)
    {
        memmove(dstr->chars, src.chars, src.len * sizeof(unsigned char));
        
        dstr->len = src.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

NEAT_API Neat_Error neat__mutstr_ref_copy(Neat_Mut_String_Ref dst, const Neat_String_View src)
{
    switch(dst.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_copy(dst.str.dstr, src);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_copy(neat__fmutstr_ref(dst.str.strbuf), src);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_copy(neat__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

NEAT_API Neat_Error neat__dstr_putc(Neat_DString *dst, unsigned char c)
{
    Neat_Error err = neat__dstr_ensure_cap(dst, dst->len + 2);
    if(err.ec != NEAT_OK)
        return err;
    
    dst->chars[dst->len] = c;
    dst->chars[dst->len + 1] = '\0';
    dst->len += 1;
    
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__fmutstr_ref_putc(Neat__Fixed_Mut_String_Ref dst, unsigned char c)
{
    if(dst.cap - *dst.len <= 1)
    {
        return (Neat_Error){NEAT_DST_TOO_SMALL};
    }
    
    dst.chars[*dst.len] = c;
    dst.chars[*dst.len + 1] = '\0';
    *dst.len += 1;
    
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__mutstr_ref_putc(Neat_Mut_String_Ref dst, unsigned char c)
{
    switch(dst.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_putc(dst.str.dstr, c);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_putc(neat__fmutstr_ref(dst.str.strbuf), c);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_putc(neat__fmutstr_ref(dst.str.buf, &(unsigned int){0}), c);
        default                : unreachable();
    }
}

NEAT_API Neat_Error neat__fmutstr_ref_append_strv(Neat__Fixed_Mut_String_Ref dst, const Neat_String_View src)
{
    unsigned int dst_len = *dst.len;
    
    unsigned int chars_to_copy = neat__uint_min(src.len, dst.cap - dst_len - 1);
    memmove(dst.chars + dst_len, src.chars, chars_to_copy);
    
    dst_len += chars_to_copy;
    
    if(dst.len != NULL)
        *dst.len = dst_len;
    
    dst.chars[dst_len] = '\0';
    
    return chars_to_copy == src.len ? (Neat_Error){NEAT_OK} : (Neat_Error){NEAT_DST_TOO_SMALL};
}

NEAT_API Neat_Error neat__mutstr_ref_append(Neat_Mut_String_Ref dst, const Neat_String_View src)
{
    switch(dst.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_append_strv(dst.str.dstr, src);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_append_strv(neat__fmutstr_ref(dst.str.strbuf), src);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_append_strv(neat__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

NEAT_API Neat_Error neat__fmutstr_ref_delete_range(Neat__Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
    if(end > len || begin >= end)
    {
        return (Neat_Error){NEAT_BAD_RANGE};
    }
    
    unsigned int substr_len = end - begin;
    
    memmove(str.chars + begin, str.chars + begin + substr_len, len - begin - substr_len);
    
    len -= substr_len;
    
    str.chars[len] = '\0';
    
    if(str.len != NULL)
    {
        *str.len = len;
    }
    
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__mutstr_ref_delete_range(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return neat__fmutstr_ref_delete_range(neat__fmutstr_ref(str.str.dstr), begin, end);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_delete_range(neat__fmutstr_ref(str.str.strbuf), begin, end);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_delete_range(neat__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    };
}

NEAT_API Neat_String_View_Array neat__strv_arr_from_carr(const Neat_String_View *carr, unsigned int nb)
{
    return (Neat_String_View_Array){
        .cap  = nb,
        .len  = nb,
        .strs = (Neat_String_View*) carr
    };
}

NEAT_API Neat_Error neat__strv_split_iter(const Neat_String_View str, const Neat_String_View delim, bool(*cb)(Neat_String_View found, void *ctx), void *ctx)
{
    if(delim.len > str.len)
    {
        return !cb(str, ctx) ? (Neat_Error){NEAT_CALLBACK_EXIT} : (Neat_Error){NEAT_OK};
    }
    else if(delim.len == 0)
    {
        for(unsigned int i = 0 ; i < str.len ; i++)
        {
            if(!cb(neat__strv_strv3(str, i, i + 1), ctx))
            {
                return (Neat_Error){NEAT_CALLBACK_EXIT};
            }
        }
        
        return (Neat_Error){NEAT_OK};
    }
    else
    {
        unsigned int prev = 0;
        for(unsigned int i = 0 ; i <= str.len - delim.len ; )
        {
            Neat_String_View rem = neat__strv_strv2(str, i);
            if(neat__strv_starts_with(rem, delim))
            {
                Neat_String_View sub = neat__strv_strv3(str, prev, i);
                if(!cb(sub, ctx))
                {
                    return (Neat_Error){NEAT_CALLBACK_EXIT};
                }
                i += delim.len;
                prev = i;
            }
            else
            {
                i += 1;
            }
        }
        
        if(!cb(neat__strv_strv3(str, prev, str.len), ctx))
        {
            return (Neat_Error){NEAT_CALLBACK_EXIT};
        }
        else
        {
            return (Neat_Error){NEAT_OK};
        }
    }
}

NEAT_PRIVATE bool neat__combine_views_into_array(Neat_String_View str, void *ctx)
{
    struct {
        Neat_Allocator *allocator;
        Neat_String_View_Array array;
    } *tctx = ctx;
    
    Neat_String_View_Array *array = &tctx->array;
    Neat_Allocator *allocator = tctx->allocator;
    
    if(array->cap <= array->len)
    {
        Neat_Allocation allocation = neat_realloc(allocator, array->strs, Neat_String_View, array->cap, (array->len + 1));
        array->strs = allocation.ptr;
        array->cap = allocation.n / sizeof(Neat_String_View);
    }
    
    array->strs[array->len++] = str;
    
    return true;
}

NEAT__NODISCARD("str_split returns new String_View_Array")
NEAT_API Neat_String_View_Array neat__strv_split(const Neat_String_View str, const Neat_String_View delim, Neat_Allocator *allocator)
{
    struct {
        Neat_Allocator *allocator;
        Neat_String_View_Array array;
    } ctx = {
        .allocator = allocator
    };
    
    neat__strv_split_iter(str, delim, neat__combine_views_into_array, &ctx);
    
    return ctx.array;
}

// TODO not currently in header, but should be
NEAT_API Neat_Error neat__strv_arr_join_into_dstr(Neat_DString *dstr, const Neat_String_View_Array strs, const Neat_String_View delim)
{
    Neat_Error err = (Neat_Error){NEAT_OK};
    
    if(strs.len > 0)
        err = neat__dstr_copy(dstr, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == NEAT_OK ; i++)
    {
        neat__dstr_append_strv(dstr, delim);
        err = neat__dstr_append_strv(dstr, strs.strs[i]);
    }
    
    return err;
}

// TODO no currently API, but should be
NEAT_API Neat_Error neat__strv_arr_join_into_fmutstr_ref(Neat__Fixed_Mut_String_Ref dst, const Neat_String_View_Array strs, const Neat_String_View delim)
{
    Neat_Error err = (Neat_Error){NEAT_OK};
    
    if(strs.len > 0)
        err = neat__fmutstr_ref_copy(dst, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == NEAT_OK; i++)
    {
        neat__fmutstr_ref_append_strv(dst, delim);
        err = neat__fmutstr_ref_append_strv(dst, strs.strs[i]);
    }
    
    return err;
}

NEAT_API Neat_Error neat__strv_arr_join(Neat_Mut_String_Ref dst, const Neat_String_View_Array strs, const Neat_String_View delim)
{
    switch(dst.ty)
    {
        case NEAT__DSTR_TY     : return neat__strv_arr_join_into_dstr(dst.str.dstr, strs, delim);
        case NEAT__STRBUF_TY   : return neat__strv_arr_join_into_fmutstr_ref(neat__fmutstr_ref(dst.str.strbuf), strs, delim);
        case NEAT__BUF_TY      : return neat__strv_arr_join_into_fmutstr_ref(neat__fmutstr_ref(dst.str.buf, &(unsigned int){0}), strs, delim);
        default                : unreachable();
    };
}

NEAT_API Neat_Error neat__dstr_replace_range(Neat_DString *dstr, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    if(begin >= dstr->len)
        return (Neat_Error){NEAT_INDEX_OUT_OF_BOUNDS};
    if(begin >= end || end > dstr->len)
        return (Neat_Error){NEAT_BAD_RANGE};
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), replacement))
        return (Neat_Error){NEAT_ALIASING_NOT_SUPPORTED};
    
    unsigned int len_to_delete = end - begin;
    if(len_to_delete > replacement.len)
    {
        // shift left
        memmove(dstr->chars + begin + replacement.len, dstr->chars + end, dstr->len - end + 1);
        // insert the replacement
        memmove(dstr->chars + begin, replacement.chars, replacement.len);
    }
    else if(len_to_delete < replacement.len)
    {
        neat__dstr_ensure_cap(dstr, dstr->len + replacement.len - len_to_delete + 1);
        
        // shift right
        memmove(dstr->chars + end + (replacement.len - len_to_delete), dstr->chars + end, dstr->len - end + 1);
        // insert the replacement
        memmove(dstr->chars + begin, replacement.chars, replacement.len);
    }
    else
    {
        memmove(dstr->chars + begin, replacement.chars, replacement.len);
    }
    
    dstr->len = dstr->len - (len_to_delete) + replacement.len;
    return (Neat_Error){NEAT_OK};
}

NEAT_PRIVATE void neat__fmutstr_ref_replace_range_unsafe(Neat__Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    unsigned int len_to_delete = end - begin;
    if(len_to_delete > replacement.len)
    {
        // shift left
        memmove(str.chars + begin + replacement.len, str.chars + end, *str.len - end + 1);
        // insert the replacement
        memmove(str.chars + begin, replacement.chars, replacement.len);
        
        *str.len -= len_to_delete - replacement.len;
    }
    else if(len_to_delete < replacement.len)
    {
        unsigned int new_space = neat__uint_min(replacement.len - len_to_delete, str.cap - *str.len - 1);
        
        // shift right
        memmove(str.chars + begin + new_space, str.chars + begin, *str.len - begin);
        // insert the replacement
        memmove(str.chars + begin, replacement.chars, neat__uint_min(replacement.len, len_to_delete + new_space));
        
        *str.len += new_space;
        
        str.chars[*str.len] = '\0';
    }
    else
    {
        memmove(str.chars + begin, replacement.chars, replacement.len);
    }
}

NEAT_PRIVATE Neat_String_View neat__strv_fmutstr_ref2(Neat__Fixed_Mut_String_Ref str, unsigned int begin);

Neat_Error neat__fmutstr_ref_replace_range(Neat__Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    if(begin >= *str.len)
        return (Neat_Error){NEAT_INDEX_OUT_OF_BOUNDS};
    if(begin >= end || end > *str.len)
        return (Neat_Error){NEAT_BAD_RANGE};
    if(neat__is_strv_within(neat__strv_fmutstr_ref2(str, 0), replacement))
        return (Neat_Error){NEAT_ALIASING_NOT_SUPPORTED};
    
    Neat_Error err = (*str.len - (end - begin) + replacement.len) >= str.cap ? (Neat_Error){NEAT_DST_TOO_SMALL} : (Neat_Error){NEAT_OK};
    neat__fmutstr_ref_replace_range_unsafe(str, begin, end, replacement);
    
    return err;
}

NEAT_API Neat_Error neat__mutstr_ref_replace_range(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_replace_range(str.str.dstr, begin, end, replacement);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_replace_range(neat__fmutstr_ref(str.str.strbuf), begin, end, replacement);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_replace_range(neat__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end, replacement);
        default                : unreachable();
    };
}

NEAT_API Neat_Error neat__fmutstr_ref_replace(Neat__Fixed_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_String_View as_strv = neat__strv_fmutstr_ref2(str, 0);
    if(neat__is_strv_within(as_strv, target) || neat__is_strv_within(as_strv, replacement))
    {
        return (Neat_Error){NEAT_ALIASING_NOT_SUPPORTED};
    }
    
    Neat_Error err = (Neat_Error){NEAT_OK};
    
    if(target.len == 0)
    {
        for(unsigned int i = 0 ; i <= *str.len && err.ec == NEAT_OK ; i += replacement.len + 1)
        {
            err = neat__fmutstr_ref_insert(str, replacement, i);
        }
        return err;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - str.chars;
                
                if(str.cap > *str.len + (replacement.len - target.len))
                {
                    // shift right
                    memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
                    
                    // put the replacement
                    memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                    
                    *str.len += (replacement.len - target.len);
                    
                    i = idx + replacement.len;
                }
                else
                {
                    err = (Neat_Error){NEAT_DST_TOO_SMALL};
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    else if(target.len > replacement.len)
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - str.chars;
                
                // shift left
                memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                *str.len -= (target.len - replacement.len);
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - str.chars;
                
                // put the replacement
                memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    return err;
}

// TODO not used in header, but should be
NEAT_API Neat_Error neat__dstr_replace(Neat_DString *dstr, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_String_View as_strv = neat__strv_dstr_ptr2(dstr, 0);
    if(neat__is_strv_within(as_strv, target) || neat__is_strv_within(as_strv, replacement))
    {
        return (Neat_Error){NEAT_ALIASING_NOT_SUPPORTED};
    }
    
    Neat_Error err = (Neat_Error){NEAT_OK};
    
    if(target.len == 0)
    {
        for(unsigned int i = 0 ; i <= dstr->len && err.ec == NEAT_OK ; i += replacement.len + 1)
        {
            err = neat__dstr_insert_strv(dstr, replacement, i);
        }
        return err;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                neat__dstr_ensure_cap(dstr, dstr->len + (replacement.len - target.len) + 1);
                
                // shift right
                memmove(dstr->chars + idx + replacement.len, dstr->chars + idx + target.len, (dstr->len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                dstr->len += (replacement.len - target.len);
                
                i = idx + replacement.len;
            }
        }
    }
    else if(target.len > replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len ; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                // shift left
                memmove(dstr->chars + idx + replacement.len, dstr->chars + idx + target.len, (dstr->len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                dstr->len -= (target.len - replacement.len);
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    
    dstr->chars[dstr->len] = '\0';
    
    return err;
}

NEAT_API Neat_Error neat__mutstr_ref_replace(Neat_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_replace(str.str.dstr, target, replacement);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_replace(neat__fmutstr_ref(str.str.strbuf), target, replacement);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_replace(neat__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

// TODO not used in header, but should be
NEAT_API Neat_Error neat__dstr_replace_first(Neat_DString *dstr, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_Error err = (Neat_Error){NEAT_NOT_FOUND};
    
    Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, 0), target);
    if(match.chars != NULL)
    {
        if(dstr->cap > 0 && dstr->cap - 1 > dstr->len + (replacement.len - target.len))
        {
            unsigned int begin = match.chars - dstr->chars;
            unsigned int end = begin + match.len;
            err = neat__dstr_replace_range(dstr, begin, end, replacement);
        }
    }
    
    if(dstr->cap > 0)
        dstr->chars[dstr->len] = '\0';
    
    return err;
}

NEAT_API Neat_Error neat__fmutstr_ref_replace_first(Neat__Fixed_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_Error err = (Neat_Error){NEAT_NOT_FOUND};
    
    Neat_String_View match = neat__strv_find(neat__strv_fmutstr_ref2(str, 0), target);
    if(match.chars != NULL)
    {
        if(str.cap > 0 && str.cap - 1 > *str.len + (replacement.len - target.len))
        {
            unsigned int idx = match.chars - str.chars;
            
            // shift
            memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
            
            // put the replacement
            memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
            
            *str.len += (replacement.len - target.len);
            
            err = (Neat_Error){NEAT_OK};
        }
        else
        {
            err = (Neat_Error){NEAT_DST_TOO_SMALL};
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    
    return err;
}

NEAT_API Neat_Error neat__mutstr_ref_replace_first(Neat_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_replace_first(str.str.dstr, target, replacement);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_replace_first(neat__fmutstr_ref(str.str.strbuf), target, replacement);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_replace_first(neat__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

NEAT_API unsigned int neat__strv_count(const Neat_String_View hay, const Neat_String_View needle)
{
    if(needle.len == 0)
        return 0;
    
    unsigned int count = 0;
    Neat_String_View found = neat__strv_find(hay, needle);
    
    while(found.chars != NULL)
    {
        count += 1;
        found = neat__strv_find(neat__strv_strv2(hay, (found.chars - hay.chars) + 1), needle);
    }
    
    return count;
}

NEAT_API bool neat__strv_starts_with(const Neat_String_View hay, const Neat_String_View needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars, needle.chars, needle.len) == 0);
}

NEAT_API bool neat__strv_ends_with(const Neat_String_View hay, const Neat_String_View needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars + hay.len - needle.len, needle.chars, needle.len) == 0);
}

NEAT_PRIVATE void neat__chars_tolower(unsigned char *chars, unsigned int len)
{
    for(unsigned int i = 0 ; i < len ; i++)
    {
        chars[i] = tolower(chars[i]);
    }
}

NEAT_PRIVATE void neat__chars_toupper(unsigned char *chars, unsigned int len)
{
    for(unsigned int i = 0 ; i < len ; i++)
    {
        chars[i] = toupper(chars[i]);
    }
}

NEAT_API Neat_Error neat__mutstr_ref_toupper(Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY:
            neat__chars_toupper(str.str.dstr->chars, str.str.dstr->len);
            break;
        case NEAT__STRBUF_TY:
            neat__chars_toupper(str.str.strbuf->chars, str.str.strbuf->len);
            break;
        case NEAT__BUF_TY:
            neat__chars_toupper(str.str.buf.ptr, strlen((char*) str.str.buf.ptr));
            break;
    }
    
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__mutstr_ref_clear(Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY:
            str.str.dstr->len = 0;
            if(str.str.dstr->cap > 0)
            {
                str.str.dstr->chars[0] = '\0';
            }
            break;
        case NEAT__STRBUF_TY:
            str.str.strbuf->len = 0;
            if(str.str.strbuf->cap > 0)
            {
                str.str.strbuf->chars[0] = '\0';
            }
            break;
        case NEAT__BUF_TY:
            if(str.str.buf.cap > 0)
                str.str.buf.ptr[0] = '\0';
            break;
    }
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Mut_String_Ref neat__cstr_as_mutstr_ref(const char *str)
{
    unsigned int len = (unsigned int) strlen(str);
    
    Neat_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return neat__buf_as_mutstr_ref(asbuf);
}

NEAT_API Neat_Mut_String_Ref neat__ucstr_as_mutstr_ref(const unsigned char *str)
{
    unsigned int len = (unsigned int) strlen((char*) str);
    
    Neat_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return neat__buf_as_mutstr_ref(asbuf);
}

NEAT_API Neat_Mut_String_Ref neat__buf_as_mutstr_ref(const Neat_Buffer str)
{
    return (Neat_Mut_String_Ref){
        .ty = NEAT__BUF_TY,
        .str.buf = *(Neat_Buffer*) &str
    };
}

NEAT_API Neat_Mut_String_Ref neat__dstr_ptr_as_mutstr_ref(const Neat_DString *str)
{
    return (Neat_Mut_String_Ref){
        .ty = NEAT__DSTR_TY,
        .str.dstr = (Neat_DString*) str
    };
}

NEAT_API Neat_Mut_String_Ref neat__strbuf_ptr_as_mutstr_ref(const Neat_String_Buffer *str)
{
    return (Neat_Mut_String_Ref){
        .ty = NEAT__STRBUF_TY,
        .str.strbuf = (Neat_String_Buffer*) str
    };
}

NEAT_API Neat_Mut_String_Ref neat__mutstr_ref_as_mutstr_ref(const Neat_Mut_String_Ref str)
{
    return str;
}

NEAT_API Neat_String_Buffer neat__strbuf_from_cstr(const char *ptr, unsigned int cap)
{
    unsigned int len = neat__chars_strlen(ptr, cap);
    
    return (Neat_String_Buffer){
        .cap = cap,
        .len = len,
        .chars = (unsigned char*) ptr
    };
}

NEAT_API Neat_String_Buffer neat__strbuf_from_buf(const Neat_Buffer buf)
{
    Neat_String_Buffer ret = {
        .cap = buf.cap,
        .len = 0,
        .chars = buf.ptr
    };
    
    if(ret.cap > 0)
        ret.chars[0] = '\0';
    
    return ret;
}

NEAT_API Neat_Buffer neat__buf_from_cstr(const char *str)
{
    return (Neat_Buffer){
        .ptr = (unsigned char*) str,
        .cap = strlen(str) + 1
    };
}

NEAT_API Neat_Buffer neat__buf_from_ucstr(const unsigned char *str)
{
    return (Neat_Buffer){
        .ptr = (unsigned char*) str,
        .cap = strlen((char*) str) + 1
    };
}

NEAT_API Neat_Buffer neat__buf_from_carr(const char *str, size_t cap)
{
    return (Neat_Buffer){
        .ptr = (unsigned char*) str,
        .cap = cap
    };
}

NEAT_API Neat_Buffer neat__buf_from_ucarr(const unsigned char *str, size_t cap)
{
    return (Neat_Buffer){
        .ptr = (unsigned char*) str,
        .cap = cap
    };
}

NEAT_API Neat_String_View neat__strv_cstr1(const char *str)
{
    return (Neat_String_View){
        .chars = (unsigned char*) str,
        .len = strlen(str)
    };
}

NEAT_API Neat_String_View neat__strv_ucstr1(const unsigned char *str)
{
    return (Neat_String_View){
        .chars = (unsigned char*) str,
        .len = strlen((char*)str)
    };
}

NEAT_API Neat_String_View neat__strv_dstr1(const Neat_DString str)
{
    return (Neat_String_View){
        .chars = str.chars,
        .len = str.len
    };
}

NEAT_API Neat_String_View neat__strv_dstr_ptr1(const Neat_DString *str)
{
    return (Neat_String_View){
        .chars = str->chars,
        .len = str->len
    };
}

NEAT_API Neat_String_View neat__strv_strv1(const Neat_String_View str)
{
    return str;
}

NEAT_API Neat_String_View neat__strv_strbuf1(const Neat_String_Buffer str)
{
    return (Neat_String_View){
        .chars = str.chars,
        .len = str.len
    };
}

NEAT_API Neat_String_View neat__strv_strbuf_ptr1(const Neat_String_Buffer *str)
{
    return (Neat_String_View){
        .chars = str->chars,
        .len = str->len
    };
}

NEAT_API Neat_String_View neat__strv_mutstr_ref1(const Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return neat__strv_dstr_ptr1(str.str.dstr);
        case NEAT__STRBUF_TY   : return neat__strv_strbuf_ptr1(str.str.strbuf);
        case NEAT__BUF_TY      : return neat__strv_ucstr1(str.str.buf.ptr);
        default                : unreachable();
    }
}

NEAT_API Neat_String_View neat__strv_cstr2(const char *str, unsigned int begin)
{
    unsigned int len = strlen(str);
    
    if(begin > len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

NEAT_API Neat_String_View neat__strv_ucstr2(const unsigned char *str, unsigned int begin)
{
    unsigned int len = strlen((char*) str);
    
    if(begin > len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

NEAT_API Neat_String_View neat__strv_dstr2(const Neat_DString str, unsigned int begin)
{
    return neat__strv_dstr_ptr2(&str, begin);
}

NEAT_API Neat_String_View neat__strv_dstr_ptr2(const Neat_DString *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_strv2(const Neat_String_View str, unsigned int begin)
{
    if(begin > str.len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = str.len   - begin,
        .chars = str.chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_strbuf_ptr2(const Neat_String_Buffer *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_strbuf2(const Neat_String_Buffer str, unsigned int begin)
{
    return neat__strv_strbuf_ptr2(&str, begin);
}

NEAT_API Neat_String_View neat__strv_mutstr_ref2(const Neat_Mut_String_Ref str, unsigned int begin)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return neat__strv_dstr_ptr2(str.str.dstr, begin);
        case NEAT__STRBUF_TY   : return neat__strv_strbuf_ptr2(str.str.strbuf, begin);
        case NEAT__BUF_TY      : return neat__strv_fmutstr_ref2(neat__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin);
        default                : unreachable();
    }
}

NEAT_PRIVATE Neat_String_View neat__strv_fmutstr_ref2(const Neat__Fixed_Mut_String_Ref str, unsigned int begin)
{
    unsigned int len = *str.len;
    
    if(begin > len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = len       - begin,
        .chars = str.chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_fmutstr_ref3(const Neat__Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
    if(begin > len || end > len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_cstr3(const char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen(str);
    
    if(begin > len || end > len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

NEAT_API Neat_String_View neat__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen((char*) str);
    
    if(begin > len || end > len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

NEAT_API Neat_String_View neat__strv_dstr_ptr3(const Neat_DString *str, unsigned int begin, unsigned int end)
{
    if(begin > str->len || end > str->len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_strbuf_ptr3(const Neat_String_Buffer *str, unsigned int begin, unsigned int end)
{
    if(begin > str->len || end > str->len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_mutstr_ref3(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case NEAT__DSTR_TY     : return neat__strv_dstr_ptr3(str.str.dstr, begin, end);
        case NEAT__STRBUF_TY   : return neat__strv_strbuf_ptr3(str.str.strbuf, begin, end);
        case NEAT__BUF_TY      : return neat__strv_fmutstr_ref3(neat__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    }
}

NEAT_API Neat_String_View neat__strv_dstr3(Neat_DString str, unsigned int begin, unsigned int end)
{
    return neat__strv_dstr_ptr3(&str, begin, end);
}

NEAT_API Neat_String_View neat__strv_strv3(Neat_String_View str, unsigned int begin, unsigned int end)
{
    if(begin > str.len || end > str.len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

NEAT_API Neat_String_View neat__strv_strbuf3(Neat_String_Buffer str, unsigned int begin, unsigned int end)
{
    return neat__strv_strbuf_ptr3(&str, begin, end);
}

NEAT_API Neat_Error neat__dstr_fread_line(Neat_DString *dstr, FILE *stream)
{
    dstr->len = 0;
    if(dstr->cap > 0)
    {
        dstr->chars[0] = '\0';
    }
    
    return neat__dstr_append_fread_line(dstr, stream);
}

NEAT_API Neat_Error neat__dstr_append_fread_line(Neat_DString *dstr, FILE *stream)
{
    Neat_Error err = {NEAT_OK};
    int c = 0;
    while(c != EOF && c != '\n')
    {
        err = neat__dstr_maybe_grow(dstr, 64);
        if(err.ec != NEAT_OK)
            return err;
        
        int count = 0;
        while(c != '\n' && count < 64 && (c=fgetc(stream)) != EOF)
        {
            unsigned char as_char = c;
            dstr->chars[dstr->len + count] = as_char;
            count += 1;
        }
        dstr->len += count;
    }
    
    return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__fmutstr_ref_fread_line(Neat__Fixed_Mut_String_Ref dst, FILE *stream)
{
    if(dst.cap == 0)
    {
        return (Neat_Error){NEAT_DST_TOO_SMALL};
    }
    
    unsigned int len = 0;
    int c = 0;
    while(len < dst.cap - 1 && c != '\n' && (c=fgetc(stream)) != EOF)
    {
        dst.chars[len] = c;
        len += 1;
    }
    
    dst.chars[len] = '\0';
    *dst.len = len;
    
    bool dst_too_small = (len == dst.cap - 1) && (c != '\n') && (c != EOF);
    
    if(dst_too_small)
        return (Neat_Error){NEAT_DST_TOO_SMALL};
    else
        return (Neat_Error){NEAT_OK};
}

NEAT_API Neat_Error neat__mutstr_ref_fread_line(Neat_Mut_String_Ref dst, FILE *stream)
{
    switch(dst.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_fread_line(dst.str.dstr, stream);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_fread_line(neat__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_fread_line(neat__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

NEAT_API Neat_Error neat__fmutstr_ref_append_fread_line(Neat__Fixed_Mut_String_Ref dst, FILE *stream)
{
    if(dst.cap <= *dst.len - 1)
        return (Neat_Error){NEAT_DST_TOO_SMALL};
    
    unsigned int appended_len = 0;
    
    Neat__Fixed_Mut_String_Ref right = {
        .cap = dst.cap - *dst.len,
        .len = &appended_len,
        .chars = dst.chars + *dst.len
    };
    
    Neat_Error err = neat__fmutstr_ref_fread_line(right, stream);
    
    *dst.len += *right.len;
    
    dst.chars[*dst.len] = '\0';
    
    return err;
}

NEAT_API Neat_Error neat__mutstr_ref_append_fread_line(Neat_Mut_String_Ref dst, FILE *stream)
{
    switch(dst.ty)
    {
        case NEAT__DSTR_TY     : return neat__dstr_append_fread_line(dst.str.dstr, stream);
        case NEAT__STRBUF_TY   : return neat__fmutstr_ref_append_fread_line(neat__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case NEAT__BUF_TY      : return neat__fmutstr_ref_append_fread_line(neat__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

NEAT_API unsigned int neat__fprint_strv(FILE *stream, Neat_String_View str)
{
    assert(str.chars != NULL);
    return fwrite(str.chars, sizeof(unsigned char), str.len, stream);
}

NEAT_API unsigned int neat__fprintln_strv(FILE *stream, Neat_String_View str)
{
    unsigned int written = fwrite(str.chars, sizeof(unsigned char), str.len, stream);
    int err = fputc('\n', stream);
    
    return written + (err != EOF);
}

NEAT_PRIVATE unsigned int neat__numstr_len(long long num)
{
    unsigned int len = 1;
    if(num < 0)
    {
        num *= -1;
        len += 1;
    }
    for(unsigned int i = 1 ; i < NEAT__CARR_LEN(neat__ten_pows) && num >= neat__ten_pows[i++] ; len++);
    return len;
}

NEAT_PRIVATE unsigned int neat_numstr_len_ull(unsigned long long num)
{
    unsigned int len = 1;
    for(unsigned int i = 1 ; i < NEAT__CARR_LEN(neat__ten_pows_ull) && num >= neat__ten_pows_ull[i++] ; len++);
    return len;
}

#define neat__sinteger_min(ty) \
_Generic((ty){0},              \
signed char: SCHAR_MIN,        \
short      : SHRT_MIN,         \
int        : INT_MIN,          \
long       : LONG_MIN,         \
long long  : LLONG_MIN         \
)

#define neat__min_tostr(ty)                    \
_Generic((ty){0},                              \
signed char: neat__schar_min_into_fmutstr_ref, \
short      : neat__short_min_into_fmutstr_ref, \
int        : neat__int_min_into_fmutstr_ref,   \
long       : neat__long_min_into_fmutstr_ref,  \
long long  : neat__llong_min_into_fmutstr_ref  \
)

NEAT_PRIVATE Neat_Error neat__schar_min_into_fmutstr_ref(Neat__Fixed_Mut_String_Ref dst)
{
    if(SCHAR_MIN == -128)
    {
        const char *numstr = "-128";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat__fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hhd", SCHAR_MIN);
        return neat__fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

NEAT_PRIVATE Neat_Error neat__short_min_into_fmutstr_ref(Neat__Fixed_Mut_String_Ref dst)
{
    if(SHRT_MIN == -32768)
    {
        const char *numstr = "-32768";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat__fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hd", SHRT_MIN);
        return neat__fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

NEAT_PRIVATE Neat_Error neat__int_min_into_fmutstr_ref(Neat__Fixed_Mut_String_Ref dst)
{
    if(INT_MIN == -2147483648)
    {
        const char *numstr = "-2147483648";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat__fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%d", INT_MIN);
        return neat__fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

NEAT_PRIVATE Neat_Error neat__long_min_into_fmutstr_ref(Neat__Fixed_Mut_String_Ref dst)
{
    if(LONG_MIN == INT_MIN)
    {
        return neat__int_min_into_fmutstr_ref(dst);
    }
    else if(LONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat__fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%ld", LONG_MIN);
        return neat__fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

NEAT_PRIVATE Neat_Error neat__llong_min_into_fmutstr_ref(Neat__Fixed_Mut_String_Ref dst)
{
    if(LLONG_MIN == LONG_MIN)
    {
        return neat__long_min_into_fmutstr_ref(dst);
    }
    else if(LLONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat__fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%lld", LLONG_MIN);
        return neat__fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

#define neat__sintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (Neat_Error){NEAT_DST_TOO_SMALL}; \
    if(obj == neat__sinteger_min(__typeof__(obj))) \
    { \
        return neat__min_tostr(__typeof__(obj))(fmutstr); \
    } \
    __typeof__(obj) num = obj; \
    \
    bool isneg = num < 0; \
    if(isneg) \
    { \
        num *= -1; \
        if(fmutstr.cap > 1) \
        { \
            neat__fmutstr_ref_putc(fmutstr, '-'); \
        } \
    } \
    unsigned int numstr_len = neat__numstr_len(num); \
    unsigned int chars_to_copy = neat__uint_min(fmutstr.cap - (1 + isneg), numstr_len); \
    num /= neat__ten_pows[numstr_len - chars_to_copy]; \
    for (unsigned int i = 0; i < chars_to_copy ; i++) \
    { \
        unsigned int rem = num % 10; \
        num = num / 10; \
        fmutstr.chars[isneg + chars_to_copy - (i + 1)] = rem + '0'; \
    } \
    \
    *fmutstr.len = chars_to_copy + isneg; \
} while(0)

#define neat__sinteger_tostr_dstr(dstr) \
do { \
    unsigned int numlen = neat__numstr_len(obj); \
    err = neat__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != NEAT_OK) \
        return err; \
    \
    Neat__Fixed_Mut_String_Ref as_fixed = neat__dstr_ptr_as_fmutstr_ref(dstr); \
    neat__sintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define neat__sinteger_tostr() \
do { \
    Neat_Error err = (Neat_Error){NEAT_OK}; \
    switch(dst.ty) \
    { \
        case NEAT__DSTR_TY: \
        { \
            neat__sinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case NEAT__STRBUF_TY: \
        { \
            Neat__Fixed_Mut_String_Ref strbuf_as_fixed = neat__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            neat__sintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case NEAT__BUF_TY: \
        { \
            Neat__Fixed_Mut_String_Ref buf_as_fixed = neat__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            neat__sintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

#define neat__uinteger_tostr_dstr(dstr) \
do { \
    unsigned int numlen = neat_numstr_len_ull(obj); \
    err = neat__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != NEAT_OK) \
        return err; \
    \
    Neat__Fixed_Mut_String_Ref as_fixed = { \
        .chars = dstr->chars, \
        .len = &dstr->len, \
        .cap = dstr->cap \
    }; \
    neat__uintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define neat__uintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (Neat_Error){NEAT_DST_TOO_SMALL}; \
    __typeof__(obj) num = obj; \
    unsigned int numstr_len = neat_numstr_len_ull(num); \
    unsigned int chars_to_copy = neat__uint_min(fmutstr.cap - 1, numstr_len); \
    num /= neat__ten_pows[numstr_len - chars_to_copy]; \
    for (unsigned int i = 0; i < chars_to_copy ; i++) \
    { \
        unsigned int rem = num % 10; \
        num = num / 10; \
        fmutstr.chars[chars_to_copy - (i + 1)] = rem + '0'; \
    } \
    \
    *fmutstr.len = chars_to_copy; \
} while(0)

#define neat__uinteger_tostr() \
do { \
    Neat_Error err = (Neat_Error){NEAT_OK}; \
    switch(dst.ty) \
    { \
        case NEAT__DSTR_TY: \
        { \
            neat__uinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case NEAT__STRBUF_TY: \
        { \
            Neat__Fixed_Mut_String_Ref strbuf_as_fixed = neat__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            neat__uintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case NEAT__BUF_TY: \
        { \
            Neat__Fixed_Mut_String_Ref buf_as_fixed = neat__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            neat__uintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

NEAT_API Neat_Error neat__bool_tostr(Neat_Mut_String_Ref dst, bool obj)
{
    Neat_String_View res = obj ? neat__strv_cstr1("true") : neat__strv_cstr1("false");
    return neat__mutstr_ref_copy(dst, res);
}

NEAT_API Neat_Error neat__cstr_tostr(Neat_Mut_String_Ref dst, const char *obj)
{
    return neat__mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = (unsigned char*) obj,
            .len = strlen(obj)
        }
    );
}

NEAT_API Neat_Error neat__ucstr_tostr(Neat_Mut_String_Ref dst, const unsigned char *obj)
{
    return neat__mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = (unsigned char*) obj,
            .len = strlen((char*) obj)
        }
    );
}

NEAT_API Neat_Error neat__char_tostr(Neat_Mut_String_Ref dst, char obj)
{
    neat__mutstr_ref_clear(dst);
    return neat__mutstr_ref_putc(dst, obj);
}

NEAT_API Neat_Error neat__schar_tostr(Neat_Mut_String_Ref dst, signed char obj)
{
    return neat__mutstr_ref_copy(dst, neat__sc_to_string[obj]);
}

NEAT_API Neat_Error neat__uchar_tostr(Neat_Mut_String_Ref dst, unsigned char obj)
{
    neat__mutstr_ref_clear(dst);
    return neat__mutstr_ref_putc(dst, obj);
}

NEAT_API Neat_Error neat__short_tostr(Neat_Mut_String_Ref dst, short obj)
{
    neat__sinteger_tostr();
}

NEAT_API Neat_Error neat__ushort_tostr(Neat_Mut_String_Ref dst, unsigned short obj)
{
    neat__uinteger_tostr();
}

NEAT_API Neat_Error neat__int_tostr(Neat_Mut_String_Ref dst, int obj)
{
    neat__sinteger_tostr();
}

NEAT_API Neat_Error neat__uint_tostr(Neat_Mut_String_Ref dst, unsigned int obj)
{
    neat__uinteger_tostr();
}

NEAT_API Neat_Error neat__long_tostr(Neat_Mut_String_Ref dst, long obj)
{
    neat__sinteger_tostr();
}

NEAT_API Neat_Error neat__ulong_tostr(Neat_Mut_String_Ref dst, unsigned long obj)
{
    neat__uinteger_tostr();
}

NEAT_API Neat_Error neat__llong_tostr(Neat_Mut_String_Ref dst, long long obj)
{
    neat__sinteger_tostr();
}

NEAT_API Neat_Error neat__ullong_tostr(Neat_Mut_String_Ref dst, unsigned long long obj)
{
    neat__uinteger_tostr();
}

// TODO optimize
// should check if dstr, and do the current impl if so,
// otherwise write directly to dst
NEAT_API Neat_Error neat__float_tostr(Neat_Mut_String_Ref dst, float obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return neat__mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

NEAT_API Neat_Error neat__double_tostr(Neat_Mut_String_Ref dst, double obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return neat__mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

NEAT_API Neat_Error neat__error_tostr(Neat_Mut_String_Ref dst, Neat_Error obj)
{
    return neat__mutstr_ref_copy(dst, neat__error_to_string[obj.ec]);
}

NEAT_API Neat_Error neat__array_fmt_tostr(Neat_Mut_String_Ref dst, Neat__Array_Fmt obj)
{
    neat__mutstr_ref_clear(dst);
    
    Neat_Appender_State appender_state;
    
    Neat_Error err = neat__mutstr_ref_append(dst, obj.open);
    
    const uint8_t *arr = obj.array;
    
    if(obj.nb > 0)
    {
        for(size_t i = 0 ; i < obj.nb - 1 ; i++)
        {
            
            Neat_Mut_String_Ref appender = neat__make_appender_mutstr_ref(dst, &appender_state);
            
            err = obj.elm_tostr(appender, arr + (obj.elm_size * i));
            // TODO return if err?
            
            err = neat__mutstr_ref_append(appender, obj.separator);
            
            neat__mutstr_ref_commit_appender(dst, appender);
        }
        
        Neat_Mut_String_Ref appender = neat__make_appender_mutstr_ref(dst, &appender_state);
        err = obj.elm_tostr(appender, arr + obj.elm_size * (obj.nb - 1));
        neat__mutstr_ref_commit_appender(dst, appender);
        
        err = neat__mutstr_ref_append(dst, obj.trailing_separator);
    }
    
    err = neat__mutstr_ref_append(dst, obj.close);
    
    return err;
}

NEAT_API Neat_Error neat__dstr_tostr(Neat_Mut_String_Ref dst, const Neat_DString obj)
{
    return neat__mutstr_ref_copy(dst, (Neat_String_View){.chars = obj.chars, .len = obj.len});
}

NEAT_API Neat_Error neat__dstr_ptr_tostr(Neat_Mut_String_Ref dst, const Neat_DString *obj)
{
    return neat__mutstr_ref_copy(dst, (Neat_String_View){.chars = obj->chars, .len = obj->len});
}

NEAT_API Neat_Error neat__strv_tostr(Neat_Mut_String_Ref dst, const Neat_String_View obj)
{
    return neat__mutstr_ref_copy(dst, obj);
}

NEAT_API Neat_Error neat__strbuf_tostr(Neat_Mut_String_Ref dst, const Neat_String_Buffer obj)
{
    return neat__mutstr_ref_copy(dst, (Neat_String_View){.chars = obj.chars, .len = obj.len});
}

NEAT_API Neat_Error neat__strbuf_ptr_tostr(Neat_Mut_String_Ref dst, const Neat_String_Buffer *obj)
{
    return neat__mutstr_ref_copy(dst, (Neat_String_View){.chars = obj->chars, .len = obj->len});
}

NEAT_API Neat_Error neat__mutstr_ref_tostr(Neat_Mut_String_Ref dst, const Neat_Mut_String_Ref obj)
{
    return neat__mutstr_ref_copy(dst, neat__strv_mutstr_ref2(obj, 0));
}

NEAT_PRIVATE Neat_Error neat__uchar_d_tostr(Neat_Mut_String_Ref dst, unsigned char obj)
{
    neat__mutstr_ref_clear(dst);
    return neat__mutstr_ref_append(dst, neat__uc_to_string[obj]);
}

#define neat__if_else(cond, then, else) \
_Generic((char(*)[(cond) + 1])0, char(*)[1]: else, char(*)[2]: then)

#define neat__unsigned_of_size(sz)  \
__typeof__(_Generic((char(*)[sz])0, \
    char(*)[1]: (uint8_t) 0,        \
    char(*)[2]: (uint16_t)0,        \
    char(*)[4]: (uint32_t)0,        \
    char(*)[8]: (uint64_t)0         \
))

#define neat__as_unsigned(n) \
((neat__unsigned_of_size(sizeof(n))) n)

#define neat__integer_d_Fmt_tostr(dst, num) \
return _Generic(num, \
    char: neat__if_else(CHAR_MIN < 0, neat__schar_tostr, neat__uchar_d_tostr), \
    signed char: neat__schar_tostr, \
    unsigned char: neat__uchar_d_tostr, \
    short: neat__short_tostr, \
    unsigned short: neat__ushort_tostr, \
    int: neat__int_tostr, \
    unsigned int: neat__uint_tostr, \
    long: neat__long_tostr, \
    unsigned long: neat__ulong_tostr, \
    long long: neat__llong_tostr, \
    unsigned long long: neat__ullong_tostr \
)(dst, num)

#define neat__integer_x_Fmt_tostr(dst, num) \
do \
{ \
    Neat_Error err = {NEAT_OK}; \
    size_t sz = sizeof(num); \
    uint8_t *num_bytes = ((uint8_t*) &num) + sizeof(num) - 1; \
    bool zero_pad = true; \
    while(sz--) \
    { \
        if(num_bytes == (uint8_t*)&num || !zero_pad || *num_bytes != 0) \
        { \
            Neat_String_View hex_sv = {.chars = (unsigned char*) neat__byte_to_hex[*num_bytes], .len = 2}; \
            if(zero_pad && hex_sv.chars[0] == '0') \
            { \
                hex_sv.chars += 1; \
                hex_sv.len -= 1; \
            } \
            zero_pad = false; \
            err = neat__mutstr_ref_append(dst, hex_sv); \
        } \
        num_bytes -= 1; \
    } \
    return err; \
} while(0)

#define neat__bswap(num)                \
_Generic((char(*)[sizeof(num)])0,       \
    char(*)[1]: num,                    \
    char(*)[2]: __builtin_bswap16(num), \
    char(*)[4]: __builtin_bswap32(num), \
    char(*)[8]: __builtin_bswap64(num)  \
)

#define neat__highest_bit(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b1) << (sizeof(n) * 8 - 1))))

#define neat__highest_bit_as_u8(n) \
(neat__highest_bit(n) >> ((sizeof(n) - 1) * 8))

#define neat__highest_3bits(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b111) << (sizeof(n) * 8 - 3))))

#define neat__highest_3bits_as_u8(n) \
(neat__highest_3bits(n) >> ((sizeof(n) - 1) * 8))

#define neat__integer_o_Fmt_tostr(dst, num) \
do \
{ \
    neat__unsigned_of_size(sizeof(num)) unum = num; \
    Neat_Error err = {NEAT_OK}; \
    const size_t bits = (sizeof(unum) * 8); \
    int iters = bits / 3; \
    uint8_t extra_bits = 3 - ((sizeof(unum) * 8) % 3); \
    uint8_t high3 = neat__highest_3bits_as_u8(unum); \
    uint8_t first_3bits = high3 >> extra_bits; \
    first_3bits = first_3bits >> 5; \
    bool zero_pad = true; \
    if(first_3bits != 0) \
    { \
        zero_pad = false; \
        Neat_String_View octal_sv = {.chars = &(unsigned char){'0' + first_3bits}, .len = 1}; \
        err = neat__mutstr_ref_append(dst, octal_sv); \
    } \
    unum = unum << (3 - extra_bits); \
    \
    for(int i = 0 ; i < iters ; i++) \
    { \
        high3 = neat__highest_3bits_as_u8(unum); \
        first_3bits = high3 >> (8 - 3); \
        if(i == (iters - 1) || !zero_pad || (first_3bits != 0)) \
        { \
            zero_pad =  false; \
            Neat_String_View octal_sv = {.chars = &(unsigned char){'0' + first_3bits}, .len = 1}; \
            err = neat__mutstr_ref_append(dst, octal_sv); \
        } \
        unum = unum << 3; \
    } \
    return err; \
} while(0)

#define neat__integer_b_Fmt_tostr(dst, num) \
do \
{ \
    Neat_Error err = {NEAT_OK}; \
    neat__unsigned_of_size(sizeof(num)) unum = num; \
    size_t sz; \
    if(dst.ty == NEAT__DSTR_TY) \
    { \
        sz = sizeof(unum) * 8; \
        neat__dstr_maybe_grow(dst.str.dstr, sizeof(unum) * 8 + 1); \
    } \
    else \
    { \
        sz = neat__mutstr_ref_cap(dst) - 1; \
    } \
    char *bytes = neat__mutstr_ref_as_cstr(dst); \
    size_t written = 0; \
    size_t counter = sizeof(unum) * 8; \
    bool zero_pad = true; \
    while(written < sz && counter != 0) \
    { \
        bool bit = unum & (((__typeof__(unum)) 1) << (sizeof(unum) * 8 - 1)) ; \
        if(bit) \
        { \
            zero_pad = false; \
            bytes[written++] = '1'; \
        } \
        else if(!zero_pad || counter == 1) \
        { \
            bytes[written++] = '0'; \
        } \
        unum = unum << 1; \
        counter -= 1; \
    } \
    neat__mutstr_ref_set_len(dst, written); \
    return err; \
} while(0)

#define NEAT__X(ty, extra) \
NEAT_API Neat_Error neat__Integer_d_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_d_Fmt_##ty obj) \
{ \
    neat__integer_d_Fmt_tostr(dst, obj.obj); \
} \
NEAT_API Neat_Error neat__Integer_x_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_x_Fmt_##ty obj) \
{ \
    neat__mutstr_ref_clear(dst); \
    neat__integer_x_Fmt_tostr(dst, obj.obj); \
} \
NEAT_API Neat_Error neat__Integer_o_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_o_Fmt_##ty obj) \
{ \
    neat__mutstr_ref_clear(dst); \
    neat__integer_o_Fmt_tostr(dst, obj.obj); \
} \
NEAT_API Neat_Error neat__Integer_b_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_b_Fmt_##ty obj) \
{ \
    neat__mutstr_ref_clear(dst); \
    neat__integer_b_Fmt_tostr(dst, obj.obj); \
} \
\
\
NEAT_API Neat_Error neat__Integer_d_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_d_Fmt_##ty *obj) \
{ \
    return neat__Integer_d_Fmt_##ty##_tostr(dst, *obj); \
} \
NEAT_API Neat_Error neat__Integer_x_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_x_Fmt_##ty *obj) \
{ \
    return neat__Integer_x_Fmt_##ty##_tostr(dst, *obj); \
} \
NEAT_API Neat_Error neat__Integer_o_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_o_Fmt_##ty *obj) \
{ \
    return neat__Integer_o_Fmt_##ty##_tostr(dst, *obj); \
} \
NEAT_API Neat_Error neat__Integer_b_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_b_Fmt_##ty *obj) \
{ \
    return neat__Integer_b_Fmt_##ty##_tostr(dst, *obj); \
}

NEAT__INTEGER_TYPES(NEAT__X, ignore)

#undef NEAT__X

#define NEAT__X(type, extra) \
NEAT_API Neat_Error neat__Floating_f_Fmt_##type##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_f_Fmt_##type obj) \
{ \
    neat__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*f", obj.precision, obj.obj); \
    if(dst.ty == NEAT__DSTR_TY) \
    { \
        neat__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(neat__mutstr_ref_as_cstr(dst), neat__mutstr_ref_cap(dst), "%.*f", obj.precision, obj.obj); \
    if(neat__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        neat__mutstr_ref_set_len(dst, neat__mutstr_ref_cap(dst) - 1); \
        return (Neat_Error){NEAT_DST_TOO_SMALL}; \
    } \
    else \
    { \
        neat__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (Neat_Error){NEAT_ENCODING_ERROR}; \
    return (Neat_Error){NEAT_OK}; \
} \
NEAT_API Neat_Error neat__Floating_g_Fmt_##type##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_g_Fmt_##type obj) \
{ \
    neat__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*g", obj.precision, obj.obj); \
    if(dst.ty == NEAT__DSTR_TY) \
    { \
        neat__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(neat__mutstr_ref_as_cstr(dst), neat__mutstr_ref_cap(dst), "%.*g", obj.precision, obj.obj); \
    if(neat__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        neat__mutstr_ref_set_len(dst, neat__mutstr_ref_cap(dst) - 1); \
        return (Neat_Error){NEAT_DST_TOO_SMALL}; \
    } \
    else \
    { \
        neat__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (Neat_Error){NEAT_ENCODING_ERROR}; \
    return (Neat_Error){NEAT_OK}; \
} \
NEAT_API Neat_Error neat__Floating_e_Fmt_##type##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_e_Fmt_##type obj) \
{ \
    neat__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*e", obj.precision, obj.obj); \
    if(dst.ty == NEAT__DSTR_TY) \
    { \
        neat__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(neat__mutstr_ref_as_cstr(dst), neat__mutstr_ref_cap(dst), "%.*e", obj.precision, obj.obj); \
    if(neat__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        neat__mutstr_ref_set_len(dst, neat__mutstr_ref_cap(dst) - 1); \
        return (Neat_Error){NEAT_DST_TOO_SMALL}; \
    } \
    else \
    { \
        neat__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (Neat_Error){NEAT_ENCODING_ERROR}; \
    return (Neat_Error){NEAT_OK}; \
} \
NEAT_API Neat_Error neat__Floating_a_Fmt_##type##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_a_Fmt_##type obj) \
{ \
    neat__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*a", obj.precision, obj.obj); \
    if(dst.ty == NEAT__DSTR_TY) \
    { \
        neat__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(neat__mutstr_ref_as_cstr(dst), neat__mutstr_ref_cap(dst), "%.*a", obj.precision, obj.obj); \
    if(neat__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        neat__mutstr_ref_set_len(dst, neat__mutstr_ref_cap(dst) - 1); \
        return (Neat_Error){NEAT_DST_TOO_SMALL}; \
    } \
    else \
    { \
        neat__mutstr_ref_set_len(dst, len); \
    } \
    \
    if(err < 0) \
        return (Neat_Error){NEAT_ENCODING_ERROR}; \
    return (Neat_Error){NEAT_OK}; \
} \
\
\
NEAT_API Neat_Error neat__Floating_f_Fmt_##type##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_f_Fmt_##type *obj) \
{ \
    return neat__Floating_f_Fmt_##type##_tostr(dst, *obj); \
} \
NEAT_API Neat_Error neat__Floating_g_Fmt_##type##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_g_Fmt_##type *obj) \
{ \
    return neat__Floating_g_Fmt_##type##_tostr(dst, *obj); \
} \
NEAT_API Neat_Error neat__Floating_e_Fmt_##type##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_e_Fmt_##type *obj) \
{ \
    return neat__Floating_e_Fmt_##type##_tostr(dst, *obj); \
} \
NEAT_API Neat_Error neat__Floating_a_Fmt_##type##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_a_Fmt_##type *obj) \
{ \
    return neat__Floating_a_Fmt_##type##_tostr(dst, *obj); \
}

NEAT__FLOATING_TYPES(NEAT__X, ignore, NEAT__X)

#undef NEAT__X


NEAT_API Neat_Error neat__bool_tostr_p(Neat_Mut_String_Ref dst, bool *obj)
{
    return neat__bool_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__cstr_tostr_p(Neat_Mut_String_Ref dst, const char **obj)
{
    return neat__cstr_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__ucstr_tostr_p(Neat_Mut_String_Ref dst, const unsigned char **obj)
{
    return neat__ucstr_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__char_tostr_p(Neat_Mut_String_Ref dst, char *obj)
{
    return neat__char_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__schar_tostr_p(Neat_Mut_String_Ref dst, signed char *obj)
{
    return neat__schar_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__uchar_tostr_p(Neat_Mut_String_Ref dst, unsigned char *obj)
{
    return neat__uchar_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__short_tostr_p(Neat_Mut_String_Ref dst, short *obj)
{
    return neat__short_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__ushort_tostr_p(Neat_Mut_String_Ref dst, unsigned short *obj)
{
    return neat__ushort_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__int_tostr_p(Neat_Mut_String_Ref dst, int *obj)
{
    return neat__int_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__uint_tostr_p(Neat_Mut_String_Ref dst, unsigned int *obj)
{
    return neat__uint_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__long_tostr_p(Neat_Mut_String_Ref dst, long *obj)
{
    return neat__long_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__ulong_tostr_p(Neat_Mut_String_Ref dst, unsigned long *obj)
{
    return neat__ulong_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__llong_tostr_p(Neat_Mut_String_Ref dst, long long *obj)
{
    return neat__llong_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__ullong_tostr_p(Neat_Mut_String_Ref dst, unsigned long long *obj)
{
    return neat__ullong_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__float_tostr_p(Neat_Mut_String_Ref dst, float *obj)
{
    return neat__float_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__double_tostr_p(Neat_Mut_String_Ref dst, double *obj)
{
    return neat__double_tostr(dst, *obj);
}

NEAT_API Neat_Error neat__dstr_tostr_p(Neat_Mut_String_Ref dst, const Neat_DString *obj)
{
    return neat__dstr_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__dstr_ptr_tostr_p(Neat_Mut_String_Ref dst, const Neat_DString **obj)
{
    return neat__dstr_ptr_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__strv_tostr_p(Neat_Mut_String_Ref dst, const Neat_String_View *obj)
{
    return neat__strv_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__strbuf_tostr_p(Neat_Mut_String_Ref dst, const Neat_String_Buffer *obj)
{
    return neat__strbuf_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__strbuf_ptr_tostr_p(Neat_Mut_String_Ref dst, const Neat_String_Buffer **obj)
{
    return neat__strbuf_ptr_tostr(dst, *obj);
}
NEAT_API Neat_Error neat__mutstr_ref_tostr_p(Neat_Mut_String_Ref dst, const Neat_Mut_String_Ref *obj)
{
    return neat__mutstr_ref_tostr(dst, *obj);
}

NEAT_API Neat_Error neat__error_tostr_p(Neat_Mut_String_Ref dst, Neat_Error *obj)
{
    return neat__error_tostr(dst, *obj);
}
