#include <ctype.h>

#ifndef CGS_API
    // for functions exposed in the header
    #define CGS_API
#endif
#ifndef CGS_PRIVATE
    // for functions only in sgs.c
    #define CGS_PRIVATE static inline
#endif
#ifndef CGS_GLOBAL_VAR
    // for global variables in sgs.c that user code may access
    #define CGS_GLOBAL_VAR
#endif

#include "cgs.h"

#if !defined(CGS__STR_C_INCLUDED)
#define CGS__STR_C_INCLUDED

#if !defined(unreachable)
    #if defined(_MSC_VER)
        #define unreachable() __assume(0)
    #elif defined(__GNUC__)
        #define unreachable() __builtin_unreachable()
    #else
        #define unreachable()
    #endif
#endif

CGS_PRIVATE CGS_Allocation cgs__default_allocator_alloc(CGS_Allocator *ctx, size_t alignment, size_t n);
CGS_PRIVATE void cgs__default_allocator_dealloc(CGS_Allocator *ctx, void *ptr, size_t n);
CGS_PRIVATE CGS_Allocation cgs__default_allocator_realloc(CGS_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size);

static CGS_Allocator cgs__default_allocator = {
    .alloc   = cgs__default_allocator_alloc,
    .dealloc = cgs__default_allocator_dealloc,
    .realloc = cgs__default_allocator_realloc,
};

static const CGS_StrView cgs__error_to_string[] = {
    [CGS_OK]                     = {.len = sizeof("OK")                     - 1, .chars = (char*) "OK"},
    [CGS_DST_TOO_SMALL]          = {.len = sizeof("DST_TOO_SMALL")          - 1, .chars = (char*) "DST_TOO_SMALL"},
    [CGS_ALLOC_ERR]              = {.len = sizeof("ALLOC_ERR")              - 1, .chars = (char*) "ALLOC_ERR"},
    [CGS_INDEX_OUT_OF_BOUNDS]    = {.len = sizeof("INDEX_OUT_OF_BOUNDS")    - 1, .chars = (char*) "INDEX_OUT_OF_BOUNDS"},
    [CGS_BAD_RANGE]              = {.len = sizeof("BAD_RANGE")              - 1, .chars = (char*) "BAD_RANGE"},
    [CGS_NOT_FOUND]              = {.len = sizeof("NOT_FOUND")              - 1, .chars = (char*) "NOT_FOUND"},
    [CGS_ALIASING_NOT_SUPPORTED] = {.len = sizeof("ALIASING_NOT_SUPPORTED") - 1, .chars = (char*) "ALIASING_NOT_SUPPORTED"},
    [CGS_INCORRECT_TYPE]         = {.len = sizeof("INCORRECT_TYPE")         - 1, .chars = (char*) "INCORRECT_TYPE"},
    [CGS_ENCODING_ERROR]         = {.len = sizeof("ENCODING_ERROR")         - 1, .chars = (char*) "ENCODING_ERROR"},
    [CGS_CALLBACK_EXIT]          = {.len = sizeof("CALLBACK_EXIT")          - 1, .chars = (char*) "CALLBACK_EXIT"}
};

static const long long cgs__ten_pows[] = {
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

static const unsigned long long cgs__ten_pows_ull[] = {
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

static const CGS_StrView cgs__uc_to_string[256] = {
    {.chars = (char*) "0", .len = 1},
    {.chars = (char*) "1", .len = 1},
    {.chars = (char*) "2", .len = 1},
    {.chars = (char*) "3", .len = 1},
    {.chars = (char*) "4", .len = 1},
    {.chars = (char*) "5", .len = 1},
    {.chars = (char*) "6", .len = 1},
    {.chars = (char*) "7", .len = 1},
    {.chars = (char*) "8", .len = 1},
    {.chars = (char*) "9", .len = 1},
    {.chars = (char*) "10", .len = 2},
    {.chars = (char*) "11", .len = 2},
    {.chars = (char*) "12", .len = 2},
    {.chars = (char*) "13", .len = 2},
    {.chars = (char*) "14", .len = 2},
    {.chars = (char*) "15", .len = 2},
    {.chars = (char*) "16", .len = 2},
    {.chars = (char*) "17", .len = 2},
    {.chars = (char*) "18", .len = 2},
    {.chars = (char*) "19", .len = 2},
    {.chars = (char*) "20", .len = 2},
    {.chars = (char*) "21", .len = 2},
    {.chars = (char*) "22", .len = 2},
    {.chars = (char*) "23", .len = 2},
    {.chars = (char*) "24", .len = 2},
    {.chars = (char*) "25", .len = 2},
    {.chars = (char*) "26", .len = 2},
    {.chars = (char*) "27", .len = 2},
    {.chars = (char*) "28", .len = 2},
    {.chars = (char*) "29", .len = 2},
    {.chars = (char*) "30", .len = 2},
    {.chars = (char*) "31", .len = 2},
    {.chars = (char*) "32", .len = 2},
    {.chars = (char*) "33", .len = 2},
    {.chars = (char*) "34", .len = 2},
    {.chars = (char*) "35", .len = 2},
    {.chars = (char*) "36", .len = 2},
    {.chars = (char*) "37", .len = 2},
    {.chars = (char*) "38", .len = 2},
    {.chars = (char*) "39", .len = 2},
    {.chars = (char*) "40", .len = 2},
    {.chars = (char*) "41", .len = 2},
    {.chars = (char*) "42", .len = 2},
    {.chars = (char*) "43", .len = 2},
    {.chars = (char*) "44", .len = 2},
    {.chars = (char*) "45", .len = 2},
    {.chars = (char*) "46", .len = 2},
    {.chars = (char*) "47", .len = 2},
    {.chars = (char*) "48", .len = 2},
    {.chars = (char*) "49", .len = 2},
    {.chars = (char*) "50", .len = 2},
    {.chars = (char*) "51", .len = 2},
    {.chars = (char*) "52", .len = 2},
    {.chars = (char*) "53", .len = 2},
    {.chars = (char*) "54", .len = 2},
    {.chars = (char*) "55", .len = 2},
    {.chars = (char*) "56", .len = 2},
    {.chars = (char*) "57", .len = 2},
    {.chars = (char*) "58", .len = 2},
    {.chars = (char*) "59", .len = 2},
    {.chars = (char*) "60", .len = 2},
    {.chars = (char*) "61", .len = 2},
    {.chars = (char*) "62", .len = 2},
    {.chars = (char*) "63", .len = 2},
    {.chars = (char*) "64", .len = 2},
    {.chars = (char*) "65", .len = 2},
    {.chars = (char*) "66", .len = 2},
    {.chars = (char*) "67", .len = 2},
    {.chars = (char*) "68", .len = 2},
    {.chars = (char*) "69", .len = 2},
    {.chars = (char*) "70", .len = 2},
    {.chars = (char*) "71", .len = 2},
    {.chars = (char*) "72", .len = 2},
    {.chars = (char*) "73", .len = 2},
    {.chars = (char*) "74", .len = 2},
    {.chars = (char*) "75", .len = 2},
    {.chars = (char*) "76", .len = 2},
    {.chars = (char*) "77", .len = 2},
    {.chars = (char*) "78", .len = 2},
    {.chars = (char*) "79", .len = 2},
    {.chars = (char*) "80", .len = 2},
    {.chars = (char*) "81", .len = 2},
    {.chars = (char*) "82", .len = 2},
    {.chars = (char*) "83", .len = 2},
    {.chars = (char*) "84", .len = 2},
    {.chars = (char*) "85", .len = 2},
    {.chars = (char*) "86", .len = 2},
    {.chars = (char*) "87", .len = 2},
    {.chars = (char*) "88", .len = 2},
    {.chars = (char*) "89", .len = 2},
    {.chars = (char*) "90", .len = 2},
    {.chars = (char*) "91", .len = 2},
    {.chars = (char*) "92", .len = 2},
    {.chars = (char*) "93", .len = 2},
    {.chars = (char*) "94", .len = 2},
    {.chars = (char*) "95", .len = 2},
    {.chars = (char*) "96", .len = 2},
    {.chars = (char*) "97", .len = 2},
    {.chars = (char*) "98", .len = 2},
    {.chars = (char*) "99", .len = 2},
    {.chars = (char*) "100", .len = 3},
    {.chars = (char*) "101", .len = 3},
    {.chars = (char*) "102", .len = 3},
    {.chars = (char*) "103", .len = 3},
    {.chars = (char*) "104", .len = 3},
    {.chars = (char*) "105", .len = 3},
    {.chars = (char*) "106", .len = 3},
    {.chars = (char*) "107", .len = 3},
    {.chars = (char*) "108", .len = 3},
    {.chars = (char*) "109", .len = 3},
    {.chars = (char*) "110", .len = 3},
    {.chars = (char*) "111", .len = 3},
    {.chars = (char*) "112", .len = 3},
    {.chars = (char*) "113", .len = 3},
    {.chars = (char*) "114", .len = 3},
    {.chars = (char*) "115", .len = 3},
    {.chars = (char*) "116", .len = 3},
    {.chars = (char*) "117", .len = 3},
    {.chars = (char*) "118", .len = 3},
    {.chars = (char*) "119", .len = 3},
    {.chars = (char*) "120", .len = 3},
    {.chars = (char*) "121", .len = 3},
    {.chars = (char*) "122", .len = 3},
    {.chars = (char*) "123", .len = 3},
    {.chars = (char*) "124", .len = 3},
    {.chars = (char*) "125", .len = 3},
    {.chars = (char*) "126", .len = 3},
    {.chars = (char*) "127", .len = 3},
    {.chars = (char*) "128", .len = 3},
    {.chars = (char*) "129", .len = 3},
    {.chars = (char*) "130", .len = 3},
    {.chars = (char*) "131", .len = 3},
    {.chars = (char*) "132", .len = 3},
    {.chars = (char*) "133", .len = 3},
    {.chars = (char*) "134", .len = 3},
    {.chars = (char*) "135", .len = 3},
    {.chars = (char*) "136", .len = 3},
    {.chars = (char*) "137", .len = 3},
    {.chars = (char*) "138", .len = 3},
    {.chars = (char*) "139", .len = 3},
    {.chars = (char*) "140", .len = 3},
    {.chars = (char*) "141", .len = 3},
    {.chars = (char*) "142", .len = 3},
    {.chars = (char*) "143", .len = 3},
    {.chars = (char*) "144", .len = 3},
    {.chars = (char*) "145", .len = 3},
    {.chars = (char*) "146", .len = 3},
    {.chars = (char*) "147", .len = 3},
    {.chars = (char*) "148", .len = 3},
    {.chars = (char*) "149", .len = 3},
    {.chars = (char*) "150", .len = 3},
    {.chars = (char*) "151", .len = 3},
    {.chars = (char*) "152", .len = 3},
    {.chars = (char*) "153", .len = 3},
    {.chars = (char*) "154", .len = 3},
    {.chars = (char*) "155", .len = 3},
    {.chars = (char*) "156", .len = 3},
    {.chars = (char*) "157", .len = 3},
    {.chars = (char*) "158", .len = 3},
    {.chars = (char*) "159", .len = 3},
    {.chars = (char*) "160", .len = 3},
    {.chars = (char*) "161", .len = 3},
    {.chars = (char*) "162", .len = 3},
    {.chars = (char*) "163", .len = 3},
    {.chars = (char*) "164", .len = 3},
    {.chars = (char*) "165", .len = 3},
    {.chars = (char*) "166", .len = 3},
    {.chars = (char*) "167", .len = 3},
    {.chars = (char*) "168", .len = 3},
    {.chars = (char*) "169", .len = 3},
    {.chars = (char*) "170", .len = 3},
    {.chars = (char*) "171", .len = 3},
    {.chars = (char*) "172", .len = 3},
    {.chars = (char*) "173", .len = 3},
    {.chars = (char*) "174", .len = 3},
    {.chars = (char*) "175", .len = 3},
    {.chars = (char*) "176", .len = 3},
    {.chars = (char*) "177", .len = 3},
    {.chars = (char*) "178", .len = 3},
    {.chars = (char*) "179", .len = 3},
    {.chars = (char*) "180", .len = 3},
    {.chars = (char*) "181", .len = 3},
    {.chars = (char*) "182", .len = 3},
    {.chars = (char*) "183", .len = 3},
    {.chars = (char*) "184", .len = 3},
    {.chars = (char*) "185", .len = 3},
    {.chars = (char*) "186", .len = 3},
    {.chars = (char*) "187", .len = 3},
    {.chars = (char*) "188", .len = 3},
    {.chars = (char*) "189", .len = 3},
    {.chars = (char*) "190", .len = 3},
    {.chars = (char*) "191", .len = 3},
    {.chars = (char*) "192", .len = 3},
    {.chars = (char*) "193", .len = 3},
    {.chars = (char*) "194", .len = 3},
    {.chars = (char*) "195", .len = 3},
    {.chars = (char*) "196", .len = 3},
    {.chars = (char*) "197", .len = 3},
    {.chars = (char*) "198", .len = 3},
    {.chars = (char*) "199", .len = 3},
    {.chars = (char*) "200", .len = 3},
    {.chars = (char*) "201", .len = 3},
    {.chars = (char*) "202", .len = 3},
    {.chars = (char*) "203", .len = 3},
    {.chars = (char*) "204", .len = 3},
    {.chars = (char*) "205", .len = 3},
    {.chars = (char*) "206", .len = 3},
    {.chars = (char*) "207", .len = 3},
    {.chars = (char*) "208", .len = 3},
    {.chars = (char*) "209", .len = 3},
    {.chars = (char*) "210", .len = 3},
    {.chars = (char*) "211", .len = 3},
    {.chars = (char*) "212", .len = 3},
    {.chars = (char*) "213", .len = 3},
    {.chars = (char*) "214", .len = 3},
    {.chars = (char*) "215", .len = 3},
    {.chars = (char*) "216", .len = 3},
    {.chars = (char*) "217", .len = 3},
    {.chars = (char*) "218", .len = 3},
    {.chars = (char*) "219", .len = 3},
    {.chars = (char*) "220", .len = 3},
    {.chars = (char*) "221", .len = 3},
    {.chars = (char*) "222", .len = 3},
    {.chars = (char*) "223", .len = 3},
    {.chars = (char*) "224", .len = 3},
    {.chars = (char*) "225", .len = 3},
    {.chars = (char*) "226", .len = 3},
    {.chars = (char*) "227", .len = 3},
    {.chars = (char*) "228", .len = 3},
    {.chars = (char*) "229", .len = 3},
    {.chars = (char*) "230", .len = 3},
    {.chars = (char*) "231", .len = 3},
    {.chars = (char*) "232", .len = 3},
    {.chars = (char*) "233", .len = 3},
    {.chars = (char*) "234", .len = 3},
    {.chars = (char*) "235", .len = 3},
    {.chars = (char*) "236", .len = 3},
    {.chars = (char*) "237", .len = 3},
    {.chars = (char*) "238", .len = 3},
    {.chars = (char*) "239", .len = 3},
    {.chars = (char*) "240", .len = 3},
    {.chars = (char*) "241", .len = 3},
    {.chars = (char*) "242", .len = 3},
    {.chars = (char*) "243", .len = 3},
    {.chars = (char*) "244", .len = 3},
    {.chars = (char*) "245", .len = 3},
    {.chars = (char*) "246", .len = 3},
    {.chars = (char*) "247", .len = 3},
    {.chars = (char*) "248", .len = 3},
    {.chars = (char*) "249", .len = 3},
    {.chars = (char*) "250", .len = 3},
    {.chars = (char*) "251", .len = 3},
    {.chars = (char*) "252", .len = 3},
    {.chars = (char*) "253", .len = 3},
    {.chars = (char*) "254", .len = 3},
    {.chars = (char*) "255", .len = 3},
};

static const CGS_StrView cgs__sc_to_string[] = {
    {.chars = (char*) "0", .len = 1},
    {.chars = (char*) "1", .len = 1},
    {.chars = (char*) "2", .len = 1},
    {.chars = (char*) "3", .len = 1},
    {.chars = (char*) "4", .len = 1},
    {.chars = (char*) "5", .len = 1},
    {.chars = (char*) "6", .len = 1},
    {.chars = (char*) "7", .len = 1},
    {.chars = (char*) "8", .len = 1},
    {.chars = (char*) "9", .len = 1},
    {.chars = (char*) "10", .len = 2},
    {.chars = (char*) "11", .len = 2},
    {.chars = (char*) "12", .len = 2},
    {.chars = (char*) "13", .len = 2},
    {.chars = (char*) "14", .len = 2},
    {.chars = (char*) "15", .len = 2},
    {.chars = (char*) "16", .len = 2},
    {.chars = (char*) "17", .len = 2},
    {.chars = (char*) "18", .len = 2},
    {.chars = (char*) "19", .len = 2},
    {.chars = (char*) "20", .len = 2},
    {.chars = (char*) "21", .len = 2},
    {.chars = (char*) "22", .len = 2},
    {.chars = (char*) "23", .len = 2},
    {.chars = (char*) "24", .len = 2},
    {.chars = (char*) "25", .len = 2},
    {.chars = (char*) "26", .len = 2},
    {.chars = (char*) "27", .len = 2},
    {.chars = (char*) "28", .len = 2},
    {.chars = (char*) "29", .len = 2},
    {.chars = (char*) "30", .len = 2},
    {.chars = (char*) "31", .len = 2},
    {.chars = (char*) "32", .len = 2},
    {.chars = (char*) "33", .len = 2},
    {.chars = (char*) "34", .len = 2},
    {.chars = (char*) "35", .len = 2},
    {.chars = (char*) "36", .len = 2},
    {.chars = (char*) "37", .len = 2},
    {.chars = (char*) "38", .len = 2},
    {.chars = (char*) "39", .len = 2},
    {.chars = (char*) "40", .len = 2},
    {.chars = (char*) "41", .len = 2},
    {.chars = (char*) "42", .len = 2},
    {.chars = (char*) "43", .len = 2},
    {.chars = (char*) "44", .len = 2},
    {.chars = (char*) "45", .len = 2},
    {.chars = (char*) "46", .len = 2},
    {.chars = (char*) "47", .len = 2},
    {.chars = (char*) "48", .len = 2},
    {.chars = (char*) "49", .len = 2},
    {.chars = (char*) "50", .len = 2},
    {.chars = (char*) "51", .len = 2},
    {.chars = (char*) "52", .len = 2},
    {.chars = (char*) "53", .len = 2},
    {.chars = (char*) "54", .len = 2},
    {.chars = (char*) "55", .len = 2},
    {.chars = (char*) "56", .len = 2},
    {.chars = (char*) "57", .len = 2},
    {.chars = (char*) "58", .len = 2},
    {.chars = (char*) "59", .len = 2},
    {.chars = (char*) "60", .len = 2},
    {.chars = (char*) "61", .len = 2},
    {.chars = (char*) "62", .len = 2},
    {.chars = (char*) "63", .len = 2},
    {.chars = (char*) "64", .len = 2},
    {.chars = (char*) "65", .len = 2},
    {.chars = (char*) "66", .len = 2},
    {.chars = (char*) "67", .len = 2},
    {.chars = (char*) "68", .len = 2},
    {.chars = (char*) "69", .len = 2},
    {.chars = (char*) "70", .len = 2},
    {.chars = (char*) "71", .len = 2},
    {.chars = (char*) "72", .len = 2},
    {.chars = (char*) "73", .len = 2},
    {.chars = (char*) "74", .len = 2},
    {.chars = (char*) "75", .len = 2},
    {.chars = (char*) "76", .len = 2},
    {.chars = (char*) "77", .len = 2},
    {.chars = (char*) "78", .len = 2},
    {.chars = (char*) "79", .len = 2},
    {.chars = (char*) "80", .len = 2},
    {.chars = (char*) "81", .len = 2},
    {.chars = (char*) "82", .len = 2},
    {.chars = (char*) "83", .len = 2},
    {.chars = (char*) "84", .len = 2},
    {.chars = (char*) "85", .len = 2},
    {.chars = (char*) "86", .len = 2},
    {.chars = (char*) "87", .len = 2},
    {.chars = (char*) "88", .len = 2},
    {.chars = (char*) "89", .len = 2},
    {.chars = (char*) "90", .len = 2},
    {.chars = (char*) "91", .len = 2},
    {.chars = (char*) "92", .len = 2},
    {.chars = (char*) "93", .len = 2},
    {.chars = (char*) "94", .len = 2},
    {.chars = (char*) "95", .len = 2},
    {.chars = (char*) "96", .len = 2},
    {.chars = (char*) "97", .len = 2},
    {.chars = (char*) "98", .len = 2},
    {.chars = (char*) "99", .len = 2},
    {.chars = (char*) "100", .len = 3},
    {.chars = (char*) "101", .len = 3},
    {.chars = (char*) "102", .len = 3},
    {.chars = (char*) "103", .len = 3},
    {.chars = (char*) "104", .len = 3},
    {.chars = (char*) "105", .len = 3},
    {.chars = (char*) "106", .len = 3},
    {.chars = (char*) "107", .len = 3},
    {.chars = (char*) "108", .len = 3},
    {.chars = (char*) "109", .len = 3},
    {.chars = (char*) "110", .len = 3},
    {.chars = (char*) "111", .len = 3},
    {.chars = (char*) "112", .len = 3},
    {.chars = (char*) "113", .len = 3},
    {.chars = (char*) "114", .len = 3},
    {.chars = (char*) "115", .len = 3},
    {.chars = (char*) "116", .len = 3},
    {.chars = (char*) "117", .len = 3},
    {.chars = (char*) "118", .len = 3},
    {.chars = (char*) "119", .len = 3},
    {.chars = (char*) "120", .len = 3},
    {.chars = (char*) "121", .len = 3},
    {.chars = (char*) "122", .len = 3},
    {.chars = (char*) "123", .len = 3},
    {.chars = (char*) "124", .len = 3},
    {.chars = (char*) "125", .len = 3},
    {.chars = (char*) "126", .len = 3},
    {.chars = (char*) "127", .len = 3},
    {.chars = (char*) "-128", .len = 4},
    {.chars = (char*) "-127", .len = 4},
    {.chars = (char*) "-126", .len = 4},
    {.chars = (char*) "-125", .len = 4},
    {.chars = (char*) "-124", .len = 4},
    {.chars = (char*) "-123", .len = 4},
    {.chars = (char*) "-122", .len = 4},
    {.chars = (char*) "-121", .len = 4},
    {.chars = (char*) "-120", .len = 4},
    {.chars = (char*) "-119", .len = 4},
    {.chars = (char*) "-118", .len = 4},
    {.chars = (char*) "-117", .len = 4},
    {.chars = (char*) "-116", .len = 4},
    {.chars = (char*) "-115", .len = 4},
    {.chars = (char*) "-114", .len = 4},
    {.chars = (char*) "-113", .len = 4},
    {.chars = (char*) "-112", .len = 4},
    {.chars = (char*) "-111", .len = 4},
    {.chars = (char*) "-110", .len = 4},
    {.chars = (char*) "-109", .len = 4},
    {.chars = (char*) "-108", .len = 4},
    {.chars = (char*) "-107", .len = 4},
    {.chars = (char*) "-106", .len = 4},
    {.chars = (char*) "-105", .len = 4},
    {.chars = (char*) "-104", .len = 4},
    {.chars = (char*) "-103", .len = 4},
    {.chars = (char*) "-102", .len = 4},
    {.chars = (char*) "-101", .len = 4},
    {.chars = (char*) "-100", .len = 4},
    {.chars = (char*) "-99", .len = 3},
    {.chars = (char*) "-98", .len = 3},
    {.chars = (char*) "-97", .len = 3},
    {.chars = (char*) "-96", .len = 3},
    {.chars = (char*) "-95", .len = 3},
    {.chars = (char*) "-94", .len = 3},
    {.chars = (char*) "-93", .len = 3},
    {.chars = (char*) "-92", .len = 3},
    {.chars = (char*) "-91", .len = 3},
    {.chars = (char*) "-90", .len = 3},
    {.chars = (char*) "-89", .len = 3},
    {.chars = (char*) "-88", .len = 3},
    {.chars = (char*) "-87", .len = 3},
    {.chars = (char*) "-86", .len = 3},
    {.chars = (char*) "-85", .len = 3},
    {.chars = (char*) "-84", .len = 3},
    {.chars = (char*) "-83", .len = 3},
    {.chars = (char*) "-82", .len = 3},
    {.chars = (char*) "-81", .len = 3},
    {.chars = (char*) "-80", .len = 3},
    {.chars = (char*) "-79", .len = 3},
    {.chars = (char*) "-78", .len = 3},
    {.chars = (char*) "-77", .len = 3},
    {.chars = (char*) "-76", .len = 3},
    {.chars = (char*) "-75", .len = 3},
    {.chars = (char*) "-74", .len = 3},
    {.chars = (char*) "-73", .len = 3},
    {.chars = (char*) "-72", .len = 3},
    {.chars = (char*) "-71", .len = 3},
    {.chars = (char*) "-70", .len = 3},
    {.chars = (char*) "-69", .len = 3},
    {.chars = (char*) "-68", .len = 3},
    {.chars = (char*) "-67", .len = 3},
    {.chars = (char*) "-66", .len = 3},
    {.chars = (char*) "-65", .len = 3},
    {.chars = (char*) "-64", .len = 3},
    {.chars = (char*) "-63", .len = 3},
    {.chars = (char*) "-62", .len = 3},
    {.chars = (char*) "-61", .len = 3},
    {.chars = (char*) "-60", .len = 3},
    {.chars = (char*) "-59", .len = 3},
    {.chars = (char*) "-58", .len = 3},
    {.chars = (char*) "-57", .len = 3},
    {.chars = (char*) "-56", .len = 3},
    {.chars = (char*) "-55", .len = 3},
    {.chars = (char*) "-54", .len = 3},
    {.chars = (char*) "-53", .len = 3},
    {.chars = (char*) "-52", .len = 3},
    {.chars = (char*) "-51", .len = 3},
    {.chars = (char*) "-50", .len = 3},
    {.chars = (char*) "-49", .len = 3},
    {.chars = (char*) "-48", .len = 3},
    {.chars = (char*) "-47", .len = 3},
    {.chars = (char*) "-46", .len = 3},
    {.chars = (char*) "-45", .len = 3},
    {.chars = (char*) "-44", .len = 3},
    {.chars = (char*) "-43", .len = 3},
    {.chars = (char*) "-42", .len = 3},
    {.chars = (char*) "-41", .len = 3},
    {.chars = (char*) "-40", .len = 3},
    {.chars = (char*) "-39", .len = 3},
    {.chars = (char*) "-38", .len = 3},
    {.chars = (char*) "-37", .len = 3},
    {.chars = (char*) "-36", .len = 3},
    {.chars = (char*) "-35", .len = 3},
    {.chars = (char*) "-34", .len = 3},
    {.chars = (char*) "-33", .len = 3},
    {.chars = (char*) "-32", .len = 3},
    {.chars = (char*) "-31", .len = 3},
    {.chars = (char*) "-30", .len = 3},
    {.chars = (char*) "-29", .len = 3},
    {.chars = (char*) "-28", .len = 3},
    {.chars = (char*) "-27", .len = 3},
    {.chars = (char*) "-26", .len = 3},
    {.chars = (char*) "-25", .len = 3},
    {.chars = (char*) "-24", .len = 3},
    {.chars = (char*) "-23", .len = 3},
    {.chars = (char*) "-22", .len = 3},
    {.chars = (char*) "-21", .len = 3},
    {.chars = (char*) "-20", .len = 3},
    {.chars = (char*) "-19", .len = 3},
    {.chars = (char*) "-18", .len = 3},
    {.chars = (char*) "-17", .len = 3},
    {.chars = (char*) "-16", .len = 3},
    {.chars = (char*) "-15", .len = 3},
    {.chars = (char*) "-14", .len = 3},
    {.chars = (char*) "-13", .len = 3},
    {.chars = (char*) "-12", .len = 3},
    {.chars = (char*) "-11", .len = 3},
    {.chars = (char*) "-10", .len = 3},
    {.chars = (char*) "-9", .len = 2},
    {.chars = (char*) "-8", .len = 2},
    {.chars = (char*) "-7", .len = 2},
    {.chars = (char*) "-6", .len = 2},
    {.chars = (char*) "-5", .len = 2},
    {.chars = (char*) "-4", .len = 2},
    {.chars = (char*) "-3", .len = 2},
    {.chars = (char*) "-2", .len = 2},
    {.chars = (char*) "-1", .len = 2}
};

static const char cgs__byte_to_hex[][2] = 
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

static const char cgs__byte_to_heX[][2] = 
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
    {'0', 'A'},
    {'0', 'B'},
    {'0', 'C'},
    {'0', 'D'},
    {'0', 'E'},
    {'0', 'F'},
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
    {'1', 'A'},
    {'1', 'B'},
    {'1', 'C'},
    {'1', 'D'},
    {'1', 'E'},
    {'1', 'F'},
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
    {'2', 'A'},
    {'2', 'B'},
    {'2', 'C'},
    {'2', 'D'},
    {'2', 'E'},
    {'2', 'F'},
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
    {'3', 'A'},
    {'3', 'B'},
    {'3', 'C'},
    {'3', 'D'},
    {'3', 'E'},
    {'3', 'F'},
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
    {'4', 'A'},
    {'4', 'B'},
    {'4', 'C'},
    {'4', 'D'},
    {'4', 'E'},
    {'4', 'F'},
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
    {'5', 'A'},
    {'5', 'B'},
    {'5', 'C'},
    {'5', 'D'},
    {'5', 'E'},
    {'5', 'F'},
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
    {'6', 'A'},
    {'6', 'B'},
    {'6', 'C'},
    {'6', 'D'},
    {'6', 'E'},
    {'6', 'F'},
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
    {'7', 'A'},
    {'7', 'B'},
    {'7', 'C'},
    {'7', 'D'},
    {'7', 'E'},
    {'7', 'F'},
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
    {'8', 'A'},
    {'8', 'B'},
    {'8', 'C'},
    {'8', 'D'},
    {'8', 'E'},
    {'8', 'F'},
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
    {'9', 'A'},
    {'9', 'B'},
    {'9', 'C'},
    {'9', 'D'},
    {'9', 'E'},
    {'9', 'F'},
    {'A', '0'},
    {'A', '1'},
    {'A', '2'},
    {'A', '3'},
    {'A', '4'},
    {'A', '5'},
    {'A', '6'},
    {'A', '7'},
    {'A', '8'},
    {'A', '9'},
    {'A', 'A'},
    {'A', 'B'},
    {'A', 'C'},
    {'A', 'D'},
    {'A', 'E'},
    {'A', 'F'},
    {'B', '0'},
    {'B', '1'},
    {'B', '2'},
    {'B', '3'},
    {'B', '4'},
    {'B', '5'},
    {'B', '6'},
    {'B', '7'},
    {'B', '8'},
    {'B', '9'},
    {'B', 'A'},
    {'B', 'B'},
    {'B', 'C'},
    {'B', 'D'},
    {'B', 'E'},
    {'B', 'F'},
    {'C', '0'},
    {'C', '1'},
    {'C', '2'},
    {'C', '3'},
    {'C', '4'},
    {'C', '5'},
    {'C', '6'},
    {'C', '7'},
    {'C', '8'},
    {'C', '9'},
    {'C', 'A'},
    {'C', 'B'},
    {'C', 'C'},
    {'C', 'D'},
    {'C', 'E'},
    {'C', 'F'},
    {'D', '0'},
    {'D', '1'},
    {'D', '2'},
    {'D', '3'},
    {'D', '4'},
    {'D', '5'},
    {'D', '6'},
    {'D', '7'},
    {'D', '8'},
    {'D', '9'},
    {'D', 'A'},
    {'D', 'B'},
    {'D', 'C'},
    {'D', 'D'},
    {'D', 'E'},
    {'D', 'F'},
    {'E', '0'},
    {'E', '1'},
    {'E', '2'},
    {'E', '3'},
    {'E', '4'},
    {'E', '5'},
    {'E', '6'},
    {'E', '7'},
    {'E', '8'},
    {'E', '9'},
    {'E', 'A'},
    {'E', 'B'},
    {'E', 'C'},
    {'E', 'D'},
    {'E', 'E'},
    {'E', 'F'},
    {'F', '0'},
    {'F', '1'},
    {'F', '2'},
    {'F', '3'},
    {'F', '4'},
    {'F', '5'},
    {'F', '6'},
    {'F', '7'},
    {'F', '8'},
    {'F', '9'},
    {'F', 'A'},
    {'F', 'B'},
    {'F', 'C'},
    {'F', 'D'},
    {'F', 'E'},
    {'F', 'F'},
};

CGS_GLOBAL_VAR _Thread_local CGS_DStr cgs__fprint_tostr_dynamic_buffer = {
    .allocator = &cgs__default_allocator,
};

CGS_API CGS__FixedMutStrRef cgs__buf_as_fmutstr_ref(CGS_Buffer buf, unsigned int *len_ptr)
{
    *len_ptr = strlen((char*) buf.ptr);
    CGS__FixedMutStrRef ret = {
        .chars = buf.ptr,
        .cap = buf.cap,
        .len = len_ptr
    };
    return ret;
}

CGS_API CGS__FixedMutStrRef cgs__strbuf_ptr_as_fmutstr_ref(CGS_StrBuf *strbuf)
{
    CGS__FixedMutStrRef ret = {
        .chars = strbuf->chars,
        .cap = strbuf->cap,
        .len = &strbuf->len
    };
    return ret;
}

CGS_API CGS__FixedMutStrRef cgs__dstr_ptr_as_fmutstr_ref(CGS_DStr *dstr)
{
    CGS__FixedMutStrRef ret = {
        .chars = dstr->chars,
        .cap = dstr->cap,
        .len = &dstr->len
    };
    return ret;
}

CGS_PRIVATE CGS_Allocation cgs__default_allocator_alloc(CGS_Allocator *ctx, size_t alignment, size_t n)
{
    (void) alignment;
    (void) ctx;
    void *mem = malloc(n);
    return (CGS_Allocation){
        .ptr = mem,
        .n = n
    };
}

CGS_PRIVATE void cgs__default_allocator_dealloc(CGS_Allocator *ctx, void *ptr, size_t n)
{
    (void) ctx;
    (void) n;
    free(ptr);
}

CGS_PRIVATE CGS_Allocation cgs__default_allocator_realloc(CGS_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) ctx;
    (void) alignment;
    (void) old_size;
    void *mem = realloc(ptr, new_size);
    return (CGS_Allocation){
        .ptr = mem,
        .n = new_size
    };
}

CGS_PRIVATE CGS_Allocation cgs__dstr_append_allocator_alloc(CGS_Allocator *allocator, size_t alignment, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) alignment;
    (void) n;
    return (CGS_Allocation){0};
}

CGS_PRIVATE void cgs__dstr_append_allocator_dealloc(CGS_Allocator *allocator, void *ptr, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) ptr;
    (void) n;
}

CGS_PRIVATE CGS_Allocation cgs__dstr_append_allocator_realloc(CGS_Allocator *allocator, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) alignment;
    
    CGS__DStrAppendAllocator *dstr_append_allocator = (__typeof__(dstr_append_allocator)) allocator;
    
    CGS_DStr *owner = dstr_append_allocator->owner;
    
    assert(old_size == owner->cap - owner->len);
    assert(((char*)ptr - owner->chars) == owner->len);
    
    cgs_dstr_ensure_cap(owner, owner->cap + (new_size - old_size));
    return (CGS_Allocation){
        .ptr = owner->chars + owner->len,
        .n = owner->cap - owner->len
    };
}

CGS_API CGS_Allocation cgs__allocator_invoke_alloc(CGS_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb)
{
    return allocator->alloc(allocator, alignment, nb * obj_size);
}

CGS_API void cgs__allocator_invoke_dealloc(CGS_Allocator *allocator, void *ptr, size_t obj_size, size_t nb)
{
    allocator->dealloc(allocator, ptr, nb * obj_size);
}

CGS_API CGS_Allocation cgs__allocator_invoke_realloc(CGS_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb)
{
    return allocator->realloc(allocator, ptr, alignment, old_nb * obj_size, new_nb * obj_size);
}

CGS_API CGS_Allocator *cgs_get_default_allocator()
{
    return &cgs__default_allocator;
}

CGS_PRIVATE void cgs__make_dstr_append_allocator(CGS_DStr *dstr, CGS__DStrAppendAllocator *out)
{
    *out = (CGS__DStrAppendAllocator){
        .base = {
            .alloc   = cgs__dstr_append_allocator_alloc,
            .dealloc = cgs__dstr_append_allocator_dealloc,
            .realloc = cgs__dstr_append_allocator_realloc,
        },
        .owner = dstr
    };
}

CGS_PRIVATE CGS_DStr cgs__make_appender_dstr(CGS_DStr *owner, CGS__DStrAppendAllocator *allocator)
{
    cgs__make_dstr_append_allocator(owner, allocator);
    return (CGS_DStr){
        .allocator = (void*) allocator,
        .cap = owner->cap - owner->len,
        .len = 0,
        .chars = owner->chars + owner->len
    };
}

CGS_PRIVATE CGS_StrBuf cgs__make_appender_strbuf(CGS_MutStrRef owner)
{
    return (CGS_StrBuf){
        .cap = cgs__mutstr_ref_cap(owner) - cgs__mutstr_ref_len(owner),
        .len = 0,
        .chars = (char*) cgs__mutstr_ref_as_cstr(owner) + cgs__mutstr_ref_len(owner)
    };
}

CGS_API CGS_MutStrRef cgs__make_appender_mutstr_ref(CGS_MutStrRef owner, CGS_AppenderState *state)
{
    switch(owner.ty)
    {
        case CGS__DSTR_TY    :
            state->appender_dstr = cgs__make_appender_dstr(owner.str.dstr, &state->dstr_append_allocator);
            return cgs__dstr_ptr_as_mutstr_ref(&state->appender_dstr);
        case CGS__STRBUF_TY  :
        case CGS__BUF_TY     :
            ;
            CGS_MutStrRef ret = {.ty = CGS__STRBUF_TY};
            ret.str.strbuf = &state->appender_buf;
            *ret.str.strbuf = cgs__make_appender_strbuf(owner);
            return ret;
        default               :
            unreachable();
    }
}

CGS_PRIVATE unsigned int cgs__uint_min(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

CGS_PRIVATE unsigned int cgs__uint_max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

CGS_PRIVATE unsigned int cgs__chars_strlen(const char *chars, unsigned int cap)
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

CGS_API bool cgs__is_strv_within(CGS_StrView base, CGS_StrView sub)
{
    uintptr_t begin = (uintptr_t) base.chars;
    uintptr_t end = (uintptr_t) (base.chars + base.len);
    uintptr_t sub_begin = (uintptr_t) sub.chars;
    return sub_begin >= begin && sub_begin < end;
}

CGS__NODISCARD("discarding a new DString may cause memory leak")
CGS_API CGS_DStr cgs__dstr_init(unsigned int cap, CGS_Allocator *allocator)
{
    CGS_DStr ret = { 0 };
    
    ret.allocator = allocator;
    
    CGS_Allocation allocation = cgs_alloc(allocator, unsigned char, cap);
    ret.chars = allocation.ptr;
    ret.cap = allocation.n;
    
    if(ret.chars != NULL)
    {
        ret.chars[0] = '\0';
    }
    
    return ret;
}

CGS_API CGS_DStr cgs__dstr_init_from(const CGS_StrView str, CGS_Allocator *allocator)
{
    CGS_DStr ret = cgs__dstr_init(str.len + 1, allocator);
    
    cgs__dstr_copy(&ret, str);
    
    return ret;
}

CGS_API void cgs__dstr_deinit(CGS_DStr *dstr)
{
    cgs_dealloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap);
    dstr->cap = 0;
    dstr->len = 0;
    dstr->chars = NULL;
}

CGS_API CGS_Error cgs__dstr_shrink_to_fit(CGS_DStr *dstr)
{
    CGS_Allocation allocation = cgs_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, dstr->len + 1);
    if(allocation.ptr == NULL)
    {
        return (CGS_Error){CGS_ALLOC_ERR};
    }
    else
    {
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        return (CGS_Error){CGS_OK};
    }
}

CGS_PRIVATE CGS_Error cgs__dstr_maybe_grow(CGS_DStr *dstr, unsigned int len_to_append)
{
    return cgs__dstr_ensure_cap(dstr, dstr->len + len_to_append + 1);
}

CGS_API CGS_Error cgs__dstr_append(CGS_DStr *dstr, const CGS_StrView src)
{
    CGS_StrView to_append = src;
    CGS_Error err = (CGS_Error){CGS_OK};
    if(cgs__is_strv_within(cgs__strv_dstr_ptr2(dstr, 0), to_append))
    {
        unsigned int begin_idx = to_append.chars - dstr->chars;
        err = cgs__dstr_maybe_grow(dstr, to_append.len + 1);
        to_append = (CGS_StrView){
            .len   = to_append.len,
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = cgs__dstr_maybe_grow(dstr, to_append.len);
    }
    
    if(err.ec == CGS_OK)
    {
        memmove(dstr->chars + dstr->len, to_append.chars, to_append.len * sizeof(unsigned char));
        
        dstr->len += to_append.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

CGS_API CGS_Error cgs__dstr_prepend_strv(CGS_DStr *dstr, const CGS_StrView src)
{
    CGS_StrView to_prepend = src;
    CGS_Error err = (CGS_Error){CGS_OK};
    
    if(cgs__is_strv_within(cgs__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        err = cgs__dstr_maybe_grow(dstr, src.len);
        to_prepend = (CGS_StrView){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = cgs__dstr_maybe_grow(dstr, to_prepend.len);
    }
    
    if(err.ec == CGS_OK)
    {
        memmove(dstr->chars + to_prepend.len, dstr->chars, dstr->len);
        memmove(dstr->chars, to_prepend.chars, to_prepend.len);
        
        dstr->len += to_prepend.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

CGS_API CGS_Error cgs__dstr_insert(CGS_DStr *dstr, const CGS_StrView src, unsigned int idx)
{
    if(idx > dstr->len)
    {
        return (CGS_Error){CGS_INDEX_OUT_OF_BOUNDS};
    }
    
    CGS_StrView to_insert = src;
    
    if(cgs__is_strv_within(cgs__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        cgs__dstr_maybe_grow(dstr, src.len);
        to_insert = (CGS_StrView){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        cgs__dstr_maybe_grow(dstr, to_insert.len);
    }
    
    memmove(dstr->chars + idx + to_insert.len, dstr->chars + idx, dstr->len - idx);
    memmove(dstr->chars + idx, to_insert.chars, to_insert.len);
    
    dstr->len += to_insert.len;
    dstr->chars[dstr->len] = '\0';
    
    return (CGS_Error){CGS_OK};
}

CGS_API CGS_Error cgs__dstr_ensure_cap(CGS_DStr *dstr, unsigned int at_least)
{
    if(dstr->cap < at_least)
    {
        char *save = dstr->chars;
        size_t new_cap = cgs__uint_max(at_least, dstr->cap * 2);
        CGS_Allocation allocation = cgs_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, new_cap);
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        
        if(dstr->chars == NULL)
        {
            dstr->chars = save;
            return (CGS_Error){CGS_ALLOC_ERR};
        }
        if(dstr->cap < new_cap)
        {
            return (CGS_Error){CGS_ALLOC_ERR};
        }
    }
    
    return (CGS_Error){CGS_OK};
}

CGS_API char *cgs__cstr_as_cstr(const char *str)
{
    return (char*) str;
}

CGS_API char *cgs__ucstr_as_cstr(const unsigned char *str)
{
    return (char*) str;
}

CGS_API char *cgs__dstr_as_cstr(const CGS_DStr str)
{
    return str.chars;
}

CGS_API char *cgs__dstr_ptr_as_cstr(const CGS_DStr *str)
{
    return str->chars;
}

CGS_API char *cgs__strv_as_cstr(const CGS_StrView str)
{
    return str.chars;
}

CGS_API char *cgs__strbuf_as_cstr(const CGS_StrBuf str)
{
    return str.chars;
}

CGS_API char *cgs__strbuf_ptr_as_cstr(const CGS_StrBuf *str)
{
    return str->chars;
}

CGS_API char *cgs__mutstr_ref_as_cstr(const CGS_MutStrRef str)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return str.str.dstr->chars;
        case CGS__STRBUF_TY   : return str.str.strbuf->chars;
        case CGS__BUF_TY      : return str.str.buf.ptr;
        default                : unreachable();
    };
}

CGS_API unsigned char cgs__cstr_char_at(const char *str, unsigned int idx)
{
    return str[idx];
}

CGS_API unsigned char cgs__ucstr_char_at(const unsigned char *str, unsigned int idx)
{
    return str[idx];
}

CGS_API unsigned char cgs__dstr_char_at(const CGS_DStr str, unsigned int idx)
{
    return str.chars[idx];
}

CGS_API unsigned char cgs__dstr_ptr_char_at(const CGS_DStr *str, unsigned int idx)
{
    return str->chars[idx];
}

CGS_API unsigned char cgs__strv_char_at(const CGS_StrView str, unsigned int idx)
{
    return str.chars[idx];
}

CGS_API unsigned char cgs__strbuf_char_at(const CGS_StrBuf str, unsigned int idx)
{
    return str.chars[idx];
}

CGS_API unsigned char cgs__strbuf_ptr_char_at(const CGS_StrBuf *str, unsigned int idx)
{
    return str->chars[idx];
}

CGS_API unsigned char cgs__mutstr_ref_char_at(const CGS_MutStrRef str, unsigned int idx)
{
    return cgs__mutstr_ref_as_cstr(str)[idx];
}

CGS_API CGS_Error cgs__mutstr_ref_set_len(CGS_MutStrRef str, unsigned int new_len)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     :
            str.str.dstr->len = new_len;
            str.str.dstr->chars[new_len] = '\0';
            assert(str.str.dstr->cap >= str.str.dstr->len);
            break;
        case CGS__STRBUF_TY   :
            str.str.strbuf->len = new_len;
            str.str.strbuf->chars[new_len] = '\0';
            assert(str.str.strbuf->cap >= str.str.strbuf->len);
            break;
        case CGS__BUF_TY      :
            str.str.buf.ptr[new_len] = '\0';
            break;
        default                :
            unreachable();
    };
    return (CGS_Error){CGS_OK};
}

CGS_API CGS_Error cgs__mutstr_ref_commit_appender(CGS_MutStrRef owner, CGS_MutStrRef appender)
{
    return cgs__mutstr_ref_set_len(
        owner,
        cgs__mutstr_ref_len(owner) + cgs__mutstr_ref_len(appender) \
    );
}

CGS_API unsigned int cgs__dstr_cap(const CGS_DStr str)
{
    return str.cap;
}

CGS_API unsigned int cgs__dstr_ptr_cap(const CGS_DStr *str)
{
    return str->cap;
}

CGS_API unsigned int cgs__strbuf_cap(const CGS_StrBuf str)
{
    return str.cap;
}

CGS_API unsigned int cgs__strbuf_ptr_cap(const CGS_StrBuf *str)
{
    return str->cap;
}

CGS_API unsigned int cgs__buf_cap(const CGS_Buffer buf)
{
    return buf.cap;
}

CGS_API unsigned int cgs__mutstr_ref_cap(const CGS_MutStrRef str)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return str.str.dstr->cap;
        case CGS__STRBUF_TY   : return str.str.strbuf->cap;
        case CGS__BUF_TY      : return str.str.buf.cap;
        default                : unreachable();
    };
}

CGS_API unsigned int cgs__mutstr_ref_len(const CGS_MutStrRef str)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return str.str.dstr->len;
        case CGS__STRBUF_TY   : return str.str.strbuf->len;
        case CGS__BUF_TY      : return strlen(str.str.buf.ptr);
        default               : unreachable();
    };
}

CGS_API CGS_Error cgs__fmutstr_ref_insert(CGS__FixedMutStrRef dst, const CGS_StrView src, unsigned int idx)
{
    unsigned int len = *dst.len;
    if(idx > len)
    {
        return (CGS_Error){CGS_INDEX_OUT_OF_BOUNDS};
    }
    
    unsigned int nb_chars_to_insert = cgs__uint_min(dst.cap - len - 1, src.len);
    
    // shift right
    memmove(dst.chars + idx + nb_chars_to_insert, dst.chars + idx, len - idx);
    
    // insert the src
    memmove(dst.chars + idx, src.chars, nb_chars_to_insert);
    
    len += nb_chars_to_insert;
    
    *dst.len = len;
    
    return nb_chars_to_insert == src.len ? (CGS_Error){CGS_OK} : (CGS_Error){CGS_DST_TOO_SMALL};
}

CGS_API CGS_Error cgs__mutstr_ref_insert(CGS_MutStrRef dst, const CGS_StrView src, unsigned int idx)
{
    switch(dst.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_insert(dst.str.dstr, src, idx);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_insert(cgs__fmutstr_ref(dst.str.strbuf), src, idx);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_insert(cgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src, idx);
        default                : unreachable();
    };
}

CGS_API bool cgs__strv_equal(const CGS_StrView str1, const CGS_StrView str2)
{
    return
    (str1.len == str2.len) &&
    (memcmp(str1.chars, str2.chars, str1.len) == 0);
}

CGS_API CGS_StrView cgs__strv_find(const CGS_StrView hay, const CGS_StrView needle)
{
    if(hay.chars == NULL || needle.chars == NULL || needle.len > hay.len)
        return (CGS_StrView){.chars = NULL, .len = 0};
    if(needle.len == 0)
        return (CGS_StrView){.chars = hay.chars, .len = 0};
    
    char *max_possible_ptr = &hay.chars[hay.len] - needle.len;
    char *first_char = hay.chars;
    unsigned int remaining_len = hay.len;
    
    while(first_char && first_char <= max_possible_ptr)
    {
        if(memcmp(first_char, needle.chars, needle.len) == 0)
            return (CGS_StrView){.chars = first_char, .len = needle.len};
        first_char = memchr(first_char + 1, needle.chars[0], remaining_len - 1);
        remaining_len = hay.len - (first_char - hay.chars);
    }
    
    return (CGS_StrView){.chars = NULL, .len = 0};
}

CGS_API CGS_Error cgs__fmutstr_ref_copy(CGS__FixedMutStrRef dst, const CGS_StrView src)
{
    unsigned int chars_to_copy = cgs__uint_min(src.len, dst.cap - 1);
    
    memmove(dst.chars, src.chars, chars_to_copy * sizeof(unsigned char));
    dst.chars[chars_to_copy] = '\0';
    
    *dst.len = chars_to_copy;
    
    return chars_to_copy == src.len ? (CGS_Error){CGS_OK} : (CGS_Error){CGS_DST_TOO_SMALL};
}

CGS_API CGS_Error cgs__dstr_copy(CGS_DStr *dstr, CGS_StrView src)
{
    CGS_Error err = cgs__dstr_ensure_cap(dstr, src.len + 1);
    
    if(err.ec == CGS_OK)
    {
        memmove(dstr->chars, src.chars, src.len * sizeof(unsigned char));
        
        dstr->len = src.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

CGS_API CGS_Error cgs__mutstr_ref_copy(CGS_MutStrRef dst, const CGS_StrView src)
{
    switch(dst.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_copy(dst.str.dstr, src);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_copy(cgs__fmutstr_ref(dst.str.strbuf), src);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_copy(cgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

CGS_API CGS_Error cgs__dstr_putc(CGS_DStr *dst, unsigned char c)
{
    CGS_Error err = cgs__dstr_ensure_cap(dst, dst->len + 2);
    if(err.ec != CGS_OK)
        return err;
    
    dst->chars[dst->len] = c;
    dst->chars[dst->len + 1] = '\0';
    dst->len += 1;
    
    return err;
}

CGS_API CGS_Error cgs__fmutstr_ref_putc(CGS__FixedMutStrRef dst, unsigned char c)
{
    if(dst.cap - *dst.len <= 1)
    {
        return (CGS_Error){CGS_DST_TOO_SMALL};
    }
    
    dst.chars[*dst.len] = c;
    dst.chars[*dst.len + 1] = '\0';
    *dst.len += 1;
    
    return (CGS_Error){CGS_OK};
}

CGS_API CGS_Error cgs__mutstr_ref_putc(CGS_MutStrRef dst, unsigned char c)
{
    switch(dst.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_putc(dst.str.dstr, c);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_putc(cgs__fmutstr_ref(dst.str.strbuf), c);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_putc(cgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), c);
        default                : unreachable();
    }
}

CGS_API CGS_Error cgs__fmutstr_ref_append(CGS__FixedMutStrRef dst, const CGS_StrView src)
{
    unsigned int dst_len = *dst.len;
    
    unsigned int chars_to_copy = cgs__uint_min(src.len, dst.cap - dst_len - 1);
    memmove(dst.chars + dst_len, src.chars, chars_to_copy);
    
    dst_len += chars_to_copy;
    
    if(dst.len != NULL)
        *dst.len = dst_len;
    
    dst.chars[dst_len] = '\0';
    
    return chars_to_copy == src.len ? (CGS_Error){CGS_OK} : (CGS_Error){CGS_DST_TOO_SMALL};
}

CGS_API CGS_Error cgs__mutstr_ref_append(CGS_MutStrRef dst, const CGS_StrView src)
{
    switch(dst.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_append(dst.str.dstr, src);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_append(cgs__fmutstr_ref(dst.str.strbuf), src);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_append(cgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

CGS_API CGS_Error cgs__fmutstr_ref_delete_range(CGS__FixedMutStrRef str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
    if(end > len || begin > len)
    {
        return (CGS_Error){CGS_INDEX_OUT_OF_BOUNDS};
    }
    if(begin > end)
    {
        return (CGS_Error){CGS_BAD_RANGE};
    }
    
    unsigned int substr_len = end - begin;
    
    memmove(str.chars + begin, str.chars + begin + substr_len, len - begin - substr_len);
    
    len -= substr_len;
    
    str.chars[len] = '\0';
    
    if(str.len != NULL)
    {
        *str.len = len;
    }
    
    return (CGS_Error){CGS_OK};
}

CGS_API CGS_Error cgs__mutstr_ref_delete_range(CGS_MutStrRef str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return cgs__fmutstr_ref_delete_range(cgs__fmutstr_ref(str.str.dstr), begin, end);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_delete_range(cgs__fmutstr_ref(str.str.strbuf), begin, end);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_delete_range(cgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    };
}

CGS_API CGS_StrViewArray cgs__strv_arr_from_carr(const CGS_StrView *carr, unsigned int nb)
{
    return (CGS_StrViewArray){
        .cap  = nb,
        .len  = nb,
        .strs = (CGS_StrView*) carr
    };
}

CGS_API CGS_Error cgs__strv_split_iter(const CGS_StrView str, const CGS_StrView delim, bool(*cb)(CGS_StrView found, void *ctx), void *ctx)
{
    if(delim.len > str.len || str.len == 0)
    {
        return !cb(str, ctx) ? (CGS_Error){CGS_CALLBACK_EXIT} : (CGS_Error){CGS_OK};
    }
    else if(delim.len == 0)
    {
        for(unsigned int i = 0 ; i < str.len ; i++)
        {
            if(!cb(cgs__strv_strv3(str, i, i + 1), ctx))
            {
                return (CGS_Error){CGS_CALLBACK_EXIT};
            }
        }
        
        return (CGS_Error){CGS_OK};
    }
    else
    {
        unsigned int prev = 0;
        for(unsigned int i = 0 ; i <= str.len - delim.len ; )
        {
            CGS_StrView rem = cgs__strv_strv2(str, i);
            if(cgs__strv_starts_with(rem, delim))
            {
                CGS_StrView sub = cgs__strv_strv3(str, prev, i);
                if(!cb(sub, ctx))
                {
                    return (CGS_Error){CGS_CALLBACK_EXIT};
                }
                i += delim.len;
                prev = i;
            }
            else
            {
                i += 1;
            }
        }
        
        if(!cb(cgs__strv_strv3(str, prev, str.len), ctx))
        {
            return (CGS_Error){CGS_CALLBACK_EXIT};
        }
        else
        {
            return (CGS_Error){CGS_OK};
        }
    }
}

CGS_PRIVATE bool cgs__combine_views_into_array(CGS_StrView str, void *ctx)
{
    struct {
        CGS_Allocator *allocator;
        CGS_StrViewArray array;
    } *tctx = ctx;
    
    CGS_StrViewArray *array = &tctx->array;
    CGS_Allocator *allocator = tctx->allocator;
    
    if(array->cap <= array->len)
    {
        CGS_Allocation allocation = cgs_realloc(allocator, array->strs, CGS_StrView, array->cap, 2 * (array->len + 1));
        array->strs = allocation.ptr;
        array->cap = allocation.n / sizeof(CGS_StrView);
    }
    
    array->strs[array->len++] = str;
    
    return true;
}

CGS__NODISCARD("str_split returns new String_View_Array")
CGS_API CGS_StrViewArray cgs__strv_split(const CGS_StrView str, const CGS_StrView delim, CGS_Allocator *allocator)
{
    struct {
        CGS_Allocator *allocator;
        CGS_StrViewArray array;
    } ctx = {
        .allocator = allocator
    };
    
    cgs__strv_split_iter(str, delim, cgs__combine_views_into_array, &ctx);
    
    return ctx.array;
}

CGS_API CGS_Error cgs__strv_arr_join_into_dstr(CGS_DStr *dstr, const CGS_StrViewArray strs, const CGS_StrView delim)
{
    CGS_Error err = (CGS_Error){CGS_OK};
    
    if(strs.len > 0)
        err = cgs__dstr_copy(dstr, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == CGS_OK ; i++)
    {
        err = cgs__dstr_append(dstr, delim);
        err = cgs__dstr_append(dstr, strs.strs[i]);
    }
    
    return err;
}

CGS_API CGS_Error cgs__strv_arr_join_into_fmutstr_ref(CGS__FixedMutStrRef dst, const CGS_StrViewArray strs, const CGS_StrView delim)
{
    CGS_Error err = (CGS_Error){CGS_OK};
    
    if(strs.len > 0)
        err = cgs__fmutstr_ref_copy(dst, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == CGS_OK; i++)
    {
        err = cgs__fmutstr_ref_append(dst, delim);
        err = cgs__fmutstr_ref_append(dst, strs.strs[i]);
    }
    
    return err;
}

CGS_API CGS_Error cgs__strv_arr_join(CGS_MutStrRef dst, const CGS_StrViewArray strs, const CGS_StrView delim)
{
    switch(dst.ty)
    {
        case CGS__DSTR_TY     : return cgs__strv_arr_join_into_dstr(dst.str.dstr, strs, delim);
        case CGS__STRBUF_TY   : return cgs__strv_arr_join_into_fmutstr_ref(cgs__fmutstr_ref(dst.str.strbuf), strs, delim);
        case CGS__BUF_TY      : return cgs__strv_arr_join_into_fmutstr_ref(cgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), strs, delim);
        default                : unreachable();
    };
}

CGS_API CGS_Error cgs__dstr_replace_range(CGS_DStr *dstr, unsigned int begin, unsigned int end, const CGS_StrView replacement)
{
    if(begin > dstr->len || end > dstr->len)
        return (CGS_Error){CGS_INDEX_OUT_OF_BOUNDS};
    if(begin > end)
        return (CGS_Error){CGS_BAD_RANGE};
    if(cgs__is_strv_within(cgs__strv_dstr_ptr2(dstr, 0), replacement))
        return (CGS_Error){CGS_ALIASING_NOT_SUPPORTED};
    
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
        cgs__dstr_ensure_cap(dstr, dstr->len + replacement.len - len_to_delete + 1);
        
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
    return (CGS_Error){CGS_OK};
}

CGS_PRIVATE void cgs__fmutstr_ref_replace_range_unsafe(CGS__FixedMutStrRef str, unsigned int begin, unsigned int end, const CGS_StrView replacement)
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
        unsigned int new_space = cgs__uint_min(replacement.len - len_to_delete, str.cap - *str.len - 1);
        
        // shift right
        memmove(str.chars + begin + new_space, str.chars + begin, *str.len - begin);
        // insert the replacement
        memmove(str.chars + begin, replacement.chars, cgs__uint_min(replacement.len, len_to_delete + new_space));
        
        *str.len += new_space;
        
        str.chars[*str.len] = '\0';
    }
    else
    {
        memmove(str.chars + begin, replacement.chars, replacement.len);
    }
}

CGS_PRIVATE CGS_StrView cgs__strv_fmutstr_ref2(CGS__FixedMutStrRef str, unsigned int begin);

CGS_Error cgs__fmutstr_ref_replace_range(CGS__FixedMutStrRef str, unsigned int begin, unsigned int end, const CGS_StrView replacement)
{
    if(begin >= *str.len)
        return (CGS_Error){CGS_INDEX_OUT_OF_BOUNDS};
    if(begin >= end || end > *str.len)
        return (CGS_Error){CGS_BAD_RANGE};
    if(cgs__is_strv_within(cgs__strv_fmutstr_ref2(str, 0), replacement))
        return (CGS_Error){CGS_ALIASING_NOT_SUPPORTED};
    
    CGS_Error err = (*str.len - (end - begin) + replacement.len) >= str.cap ? (CGS_Error){CGS_DST_TOO_SMALL} : (CGS_Error){CGS_OK};
    cgs__fmutstr_ref_replace_range_unsafe(str, begin, end, replacement);
    
    return err;
}

CGS_API CGS_Error cgs__mutstr_ref_replace_range(CGS_MutStrRef str, unsigned int begin, unsigned int end, const CGS_StrView replacement)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_replace_range(str.str.dstr, begin, end, replacement);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_replace_range(cgs__fmutstr_ref(str.str.strbuf), begin, end, replacement);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_replace_range(cgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end, replacement);
        default                : unreachable();
    };
}

CGS_API CGS_ReplaceResult cgs__fmutstr_ref_replace(CGS__FixedMutStrRef str, const CGS_StrView target, const CGS_StrView replacement)
{
    CGS_StrView as_strv = cgs__strv_fmutstr_ref2(str, 0);
    if(cgs__is_strv_within(as_strv, target) || cgs__is_strv_within(as_strv, replacement))
    {
        return (CGS_ReplaceResult){.nb_replaced = 0, .err = {CGS_ALIASING_NOT_SUPPORTED}};
    }
    
    CGS_Error err = {CGS_OK};
    unsigned int replace_count = 0;
    
    if(target.len == 0)
    {
        for(unsigned int i = 0 ; i <= *str.len && (err.ec == CGS_OK) ; i += replacement.len + 1)
        {
            err = cgs__fmutstr_ref_insert(str, replacement, i);
            replace_count += 1;
        }
        goto out;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len ; )
        {
            CGS_StrView match = cgs__strv_find(cgs__strv_fmutstr_ref2(str, i), target);
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
                    
                    replace_count += 1;
                }
                else
                {
                    err = (CGS_Error){CGS_DST_TOO_SMALL};
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
        for(unsigned int i = 0 ; i <= *str.len - target.len ; )
        {
            CGS_StrView match = cgs__strv_find(cgs__strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - str.chars;
                
                // shift left
                memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                *str.len -= (target.len - replacement.len);
                
                i = idx + replacement.len;
                
                replace_count += 1;
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
            CGS_StrView match = cgs__strv_find(cgs__strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                err.ec = CGS_OK;
                unsigned int idx = match.chars - str.chars;
                
                // put the replacement
                memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                i = idx + replacement.len;
                
                replace_count += 1;
            }
            else
            {
                break;
            }
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    
    out:
    if(replace_count == 0 && err.ec == CGS_OK)
        err.ec = CGS_NOT_FOUND;
    return (CGS_ReplaceResult){.nb_replaced = replace_count, .err = err};
}

CGS_API CGS_ReplaceResult cgs__dstr_replace(CGS_DStr *dstr, const CGS_StrView target, const CGS_StrView replacement)
{
    CGS_StrView as_strv = cgs__strv_dstr_ptr2(dstr, 0);
    if(cgs__is_strv_within(as_strv, target) || cgs__is_strv_within(as_strv, replacement))
    {
        return (CGS_ReplaceResult){.nb_replaced = 0, .err = {CGS_ALIASING_NOT_SUPPORTED}};
    }
    
    CGS_Error err = {CGS_OK};
    unsigned int replace_count = 0;
    
    if(target.len == 0)
    {
        err.ec = CGS_OK;
        for(unsigned int i = 0 ; i <= dstr->len && (err.ec == CGS_OK) ; i += replacement.len + 1)
        {
            err = cgs__dstr_insert(dstr, replacement, i);
            replace_count += 1;
        }
        goto out;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len; )
        {
            CGS_StrView match = cgs__strv_find(cgs__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                err = cgs__dstr_ensure_cap(dstr, dstr->len + (replacement.len - target.len) + 1);
                
                // shift right
                memmove(dstr->chars + idx + replacement.len, dstr->chars + idx + target.len, (dstr->len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                dstr->len += (replacement.len - target.len);
                
                i = idx + replacement.len;
                
                replace_count += 1;
            }
            else
            {
                break;
            }
        }
    }
    else if(target.len > replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len ; )
        {
            CGS_StrView match = cgs__strv_find(cgs__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                // shift left
                memmove(dstr->chars + idx + replacement.len, dstr->chars + idx + target.len, (dstr->len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                dstr->len -= (target.len - replacement.len);
                
                i = idx + replacement.len;
                
                replace_count += 1;
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
            CGS_StrView match = cgs__strv_find(cgs__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                i = idx + replacement.len;
                
                replace_count += 1;
            }
            else
            {
                break;
            }
        }
    }
    
    dstr->chars[dstr->len] = '\0';
    
    out:
    if(replace_count == 0)
        err.ec = CGS_NOT_FOUND;
    return (CGS_ReplaceResult){.nb_replaced = replace_count, .err = err};
}

CGS_API CGS_ReplaceResult cgs__mutstr_ref_replace(CGS_MutStrRef str, const CGS_StrView target, const CGS_StrView replacement)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_replace(str.str.dstr, target, replacement);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_replace(cgs__fmutstr_ref(str.str.strbuf), target, replacement);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_replace(cgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

CGS_API CGS_Error cgs__dstr_replace_first(CGS_DStr *dstr, const CGS_StrView target, const CGS_StrView replacement)
{
    CGS_Error err = {CGS_NOT_FOUND};
    
    CGS_StrView match = cgs__strv_find(cgs__strv_dstr_ptr2(dstr, 0), target);
    if(match.chars != NULL)
    {
        unsigned int begin = match.chars - dstr->chars;
        unsigned int end = begin + match.len;
        err = cgs__dstr_replace_range(dstr, begin, end, replacement);
    }
    
    return err;
}

CGS_API CGS_Error cgs__fmutstr_ref_replace_first(CGS__FixedMutStrRef str, const CGS_StrView target, const CGS_StrView replacement)
{
    CGS_Error err = {CGS_NOT_FOUND};
    
    CGS_StrView match = cgs__strv_find(cgs__strv_fmutstr_ref2(str, 0), target);
    if(match.chars != NULL)
    {
        // TODO make this fill as much as possible. just call replace_range
        if(str.cap > 0 && str.cap - 1 > *str.len + (replacement.len - target.len))
        {
            unsigned int idx = match.chars - str.chars;
            
            // shift
            memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
            
            // put the replacement
            memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
            
            *str.len += (replacement.len - target.len);
            
            err.ec = CGS_OK;
        }
        else
        {
            err.ec = CGS_DST_TOO_SMALL;
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    
    return err;
}

CGS_API CGS_Error cgs__mutstr_ref_replace_first(CGS_MutStrRef str, const CGS_StrView target, const CGS_StrView replacement)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_replace_first(str.str.dstr, target, replacement);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_replace_first(cgs__fmutstr_ref(str.str.strbuf), target, replacement);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_replace_first(cgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

CGS_API unsigned int cgs__strv_count(const CGS_StrView hay, const CGS_StrView needle)
{
    if(needle.len == 0)
        return hay.len + 1;
    
    unsigned int count = 0;
    CGS_StrView found = cgs__strv_find(hay, needle);
    
    while(found.chars != NULL)
    {
        count += 1;
        found = cgs__strv_find(cgs__strv_strv2(hay, (found.chars - hay.chars) + found.len), needle);
    }
    
    return count;
}

CGS_API bool cgs__strv_starts_with(const CGS_StrView hay, const CGS_StrView needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars, needle.chars, needle.len) == 0);
}

CGS_API bool cgs__strv_ends_with(const CGS_StrView hay, const CGS_StrView needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars + hay.len - needle.len, needle.chars, needle.len) == 0);
}

CGS_API void cgs__chars_tolower(CGS_StrView str)
{
    for(unsigned int i = 0 ; i < str.len ; i++)
    {
        str.chars[i] = tolower(str.chars[i]);
    }
}

CGS_API void cgs__chars_toupper(CGS_StrView str)
{
    for(unsigned int i = 0 ; i < str.len ; i++)
    {
        str.chars[i] = toupper(str.chars[i]);
    }
}

CGS_API CGS_Error cgs__fmutstr_ref_clear(CGS__FixedMutStrRef fmutstr_ref)
{
    *fmutstr_ref.len = 0;
    if(fmutstr_ref.cap > 0)
    {
        fmutstr_ref.chars[0] = '\0';
    }
    return (CGS_Error){CGS_OK};
}

CGS_API CGS_Error cgs__mutstr_ref_clear(CGS_MutStrRef str)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY:
            cgs__fmutstr_ref_clear(cgs__dstr_ptr_as_fmutstr_ref(str.str.dstr));
            break;
        case CGS__STRBUF_TY:
            cgs__fmutstr_ref_clear(cgs__strbuf_ptr_as_fmutstr_ref(str.str.strbuf));
            break;
        case CGS__BUF_TY:
            cgs__fmutstr_ref_clear(cgs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}));
            break;
    }
    return (CGS_Error){CGS_OK};
}

CGS_API CGS_MutStrRef cgs__cstr_as_mutstr_ref(const char *str)
{
    unsigned int len = (unsigned int) strlen(str);
    
    CGS_Buffer asbuf = {
        .ptr = (char*) str,
        .cap = len + 1
    };
    
    return cgs__buf_as_mutstr_ref(asbuf);
}

CGS_API CGS_MutStrRef cgs__ucstr_as_mutstr_ref(const unsigned char *str)
{
    unsigned int len = (unsigned int) strlen((char*) str);
    
    CGS_Buffer asbuf = {
        .ptr = (char*) str,
        .cap = len + 1
    };
    
    return cgs__buf_as_mutstr_ref(asbuf);
}

CGS_API CGS_MutStrRef cgs__buf_as_mutstr_ref(const CGS_Buffer str)
{
    return (CGS_MutStrRef){
        .ty = CGS__BUF_TY,
        .str.buf = *(CGS_Buffer*) &str
    };
}

CGS_API CGS_MutStrRef cgs__dstr_ptr_as_mutstr_ref(const CGS_DStr *str)
{
    return (CGS_MutStrRef){
        .ty = CGS__DSTR_TY,
        .str.dstr = (CGS_DStr*) str
    };
}

CGS_API CGS_MutStrRef cgs__strbuf_ptr_as_mutstr_ref(const CGS_StrBuf *str)
{
    return (CGS_MutStrRef){
        .ty = CGS__STRBUF_TY,
        .str.strbuf = (CGS_StrBuf*) str
    };
}

CGS_API CGS_MutStrRef cgs__mutstr_ref_as_mutstr_ref(const CGS_MutStrRef str)
{
    return str;
}

CGS_API CGS_StrBuf cgs__strbuf_from_cstr(const char *ptr)
{
    unsigned int len = strlen(ptr);
    unsigned int cap = len + 1;
    
    return (CGS_StrBuf){
        .cap = cap,
        .len = len,
        .chars = (char*) ptr
    };
}

CGS_API CGS_StrBuf cgs__strbuf_from_cstr_cap(const char *ptr, unsigned int cap)
{
    unsigned int len = cgs__chars_strlen(ptr, cap);
    
    return (CGS_StrBuf){
        .cap = cap,
        .len = len,
        .chars = (char*) ptr
    };
}

CGS_API CGS_StrBuf cgs__strbuf_from_buf(const CGS_Buffer buf)
{
    CGS_StrBuf ret = {
        .cap = buf.cap,
        .len = 0,
        .chars = buf.ptr
    };
    
    if(ret.cap > 0)
        ret.chars[0] = '\0';
    
    return ret;
}

CGS_API CGS_Buffer cgs__buf_from_cstr(const char *str)
{
    return (CGS_Buffer){
        .ptr = (char*) str,
        .cap = strlen(str) + 1
    };
}

CGS_API CGS_Buffer cgs__buf_from_ucstr(const unsigned char *str)
{
    return (CGS_Buffer){
        .ptr = (char*) str,
        .cap = strlen((char*) str) + 1
    };
}

CGS_API CGS_Buffer cgs__buf_from_carr(const char *str, size_t cap)
{
    return (CGS_Buffer){
        .ptr = (char*) str,
        .cap = cap
    };
}

CGS_API CGS_Buffer cgs__buf_from_ucarr(const unsigned char *str, size_t cap)
{
    return (CGS_Buffer){
        .ptr = (char*) str,
        .cap = cap
    };
}

CGS_API CGS_StrView cgs__strv_cstr1(const char *str)
{
    return (CGS_StrView){
        .chars = (char*) str,
        .len = strlen(str)
    };
}

CGS_API CGS_StrView cgs__strv_ucstr1(const unsigned char *str)
{
    return (CGS_StrView){
        .chars = (char*) str,
        .len = strlen((char*)str)
    };
}

CGS_API CGS_StrView cgs__strv_dstr1(const CGS_DStr str)
{
    return (CGS_StrView){
        .chars = str.chars,
        .len = str.len
    };
}

CGS_API CGS_StrView cgs__strv_dstr_ptr1(const CGS_DStr *str)
{
    return (CGS_StrView){
        .chars = str->chars,
        .len = str->len
    };
}

CGS_API CGS_StrView cgs__strv_strv1(const CGS_StrView str)
{
    return str;
}

CGS_API CGS_StrView cgs__strv_strbuf1(const CGS_StrBuf str)
{
    return (CGS_StrView){
        .chars = str.chars,
        .len = str.len
    };
}

CGS_API CGS_StrView cgs__strv_strbuf_ptr1(const CGS_StrBuf *str)
{
    return (CGS_StrView){
        .chars = str->chars,
        .len = str->len
    };
}

CGS_API CGS_StrView cgs__strv_mutstr_ref1(const CGS_MutStrRef str)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY   : return cgs__strv_dstr_ptr1(str.str.dstr);
        case CGS__STRBUF_TY : return cgs__strv_strbuf_ptr1(str.str.strbuf);
        case CGS__BUF_TY    : return cgs__strv_cstr1(str.str.buf.ptr);
        default             : unreachable();
    }
}

CGS_API CGS_StrView cgs__strv_cstr2(const char *str, unsigned int begin)
{
    unsigned int len = strlen(str);
    
#if !defined(CGS_NDEBUG)
    if(begin > len)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = len - begin,
        .chars = (char*) str + begin
    };
}

CGS_API CGS_StrView cgs__strv_ucstr2(const unsigned char *str, unsigned int begin)
{
    unsigned int len = strlen((char*) str);
    
#if !defined(CGS_NDEBUG)
    if(begin > len)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = len - begin,
        .chars = (char*) str + begin
    };
}

CGS_API CGS_StrView cgs__strv_dstr_ptr2(const CGS_DStr *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (CGS_StrView){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_dstr2(const CGS_DStr str, unsigned int begin)
{
    return cgs__strv_dstr_ptr2(&str, begin);
}

CGS_API CGS_StrView cgs__strv_strv2(const CGS_StrView str, unsigned int begin)
{
#if !defined(CGS_NDEBUG)
    if(begin > str.len)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = str.len   - begin,
        .chars = str.chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_strbuf_ptr2(const CGS_StrBuf *str, unsigned int begin)
{
#if !defined(CGS_NDEBUG)
    if(begin > str->len)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_strbuf2(const CGS_StrBuf str, unsigned int begin)
{
    return cgs__strv_strbuf_ptr2(&str, begin);
}

CGS_API CGS_StrView cgs__strv_mutstr_ref2(const CGS_MutStrRef str, unsigned int begin)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return cgs__strv_dstr_ptr2(str.str.dstr, begin);
        case CGS__STRBUF_TY   : return cgs__strv_strbuf_ptr2(str.str.strbuf, begin);
        case CGS__BUF_TY      : return cgs__strv_fmutstr_ref2(cgs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin);
        default                : unreachable();
    }
}

CGS_PRIVATE CGS_StrView cgs__strv_fmutstr_ref2(const CGS__FixedMutStrRef str, unsigned int begin)
{
    unsigned int len = *str.len;
    
#if !defined(CGS_NDEBUG)
    if(begin > len)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = len       - begin,
        .chars = str.chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_fmutstr_ref3(const CGS__FixedMutStrRef str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
#if !defined(CGS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_cstr3(const char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen(str);
    
#if !defined(CGS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = end - begin,
        .chars = (char*) str + begin
    };
}

CGS_API CGS_StrView cgs__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen((char*) str);
    
#if !defined(CGS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = end - begin,
        .chars = (char*) str + begin
    };
}

CGS_API CGS_StrView cgs__strv_dstr_ptr3(const CGS_DStr *str, unsigned int begin, unsigned int end)
{
#if !defined(CGS_NDEBUG)
    if(begin > str->len || end > str->len || begin > end)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_strbuf_ptr3(const CGS_StrBuf *str, unsigned int begin, unsigned int end)
{
#if !defined(CGS_NDEBUG)
    if(begin > str->len || end > str->len || begin > end)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (CGS_StrView){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_mutstr_ref3(CGS_MutStrRef str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case CGS__DSTR_TY     : return cgs__strv_dstr_ptr3(str.str.dstr, begin, end);
        case CGS__STRBUF_TY   : return cgs__strv_strbuf_ptr3(str.str.strbuf, begin, end);
        case CGS__BUF_TY      : return cgs__strv_fmutstr_ref3(cgs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    }
}

CGS_API CGS_StrView cgs__strv_dstr3(CGS_DStr str, unsigned int begin, unsigned int end)
{
    return cgs__strv_dstr_ptr3(&str, begin, end);
}

CGS_API CGS_StrView cgs__strv_strv3(CGS_StrView str, unsigned int begin, unsigned int end)
{
    if(begin > str.len || end > str.len || begin > end)
    {
        return (CGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (CGS_StrView){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

CGS_API CGS_StrView cgs__strv_strbuf3(CGS_StrBuf str, unsigned int begin, unsigned int end)
{
    return cgs__strv_strbuf_ptr3(&str, begin, end);
}

CGS_API CGS_Error cgs__dstr_fread_line(CGS_DStr *dstr, FILE *stream)
{
    dstr->len = 0;
    if(dstr->cap > 0)
    {
        dstr->chars[0] = '\0';
    }
    
    return cgs__dstr_append_fread_line(dstr, stream);
}

CGS_API CGS_Error cgs__dstr_append_fread_line(CGS_DStr *dstr, FILE *stream)
{
    CGS_Error err = {CGS_OK};
    int c = 0;
    while(c != EOF && c != '\n')
    {
        err = cgs__dstr_maybe_grow(dstr, 64);
        if(err.ec != CGS_OK)
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
    
    return (CGS_Error){CGS_OK};
}

CGS_API CGS_Error cgs__fmutstr_ref_fread_line(CGS__FixedMutStrRef dst, FILE *stream)
{
    if(dst.cap == 0)
    {
        return (CGS_Error){CGS_DST_TOO_SMALL};
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
        return (CGS_Error){CGS_DST_TOO_SMALL};
    else
        return (CGS_Error){CGS_OK};
}

CGS_API CGS_Error cgs__mutstr_ref_fread_line(CGS_MutStrRef dst, FILE *stream)
{
    switch(dst.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_fread_line(dst.str.dstr, stream);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_fread_line(cgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_fread_line(cgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

CGS_API CGS_Error cgs__fmutstr_ref_append_fread_line(CGS__FixedMutStrRef dst, FILE *stream)
{
    if(dst.cap <= *dst.len - 1)
        return (CGS_Error){CGS_DST_TOO_SMALL};
    
    unsigned int appended_len = 0;
    
    CGS__FixedMutStrRef right = {
        .cap = dst.cap - *dst.len,
        .len = &appended_len,
        .chars = dst.chars + *dst.len
    };
    
    CGS_Error err = cgs__fmutstr_ref_fread_line(right, stream);
    
    *dst.len += *right.len;
    
    dst.chars[*dst.len] = '\0';
    
    return err;
}

CGS_API CGS_Error cgs__mutstr_ref_append_fread_line(CGS_MutStrRef dst, FILE *stream)
{
    switch(dst.ty)
    {
        case CGS__DSTR_TY     : return cgs__dstr_append_fread_line(dst.str.dstr, stream);
        case CGS__STRBUF_TY   : return cgs__fmutstr_ref_append_fread_line(cgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case CGS__BUF_TY      : return cgs__fmutstr_ref_append_fread_line(cgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

CGS_API unsigned int cgs__fprint_strv(FILE *stream, CGS_StrView str)
{
    assert(str.chars != NULL);
    return fwrite(str.chars, sizeof(unsigned char), str.len, stream);
}

CGS_API unsigned int cgs__fprintln_strv(FILE *stream, CGS_StrView str)
{
    unsigned int written = fwrite(str.chars, sizeof(unsigned char), str.len, stream);
    int err = fputc('\n', stream);
    
    return written + (err != EOF);
}

CGS_PRIVATE unsigned int cgs__numstr_len(unsigned long long num)
{
    unsigned int len = 1;
    for(unsigned int i = 1 ; i < CGS__CARR_LEN(cgs__ten_pows_ull) && num >= cgs__ten_pows_ull[i++] ; len++);
    return len;
}

#define cgs__sinteger_min(ty) \
_Generic((ty){0},              \
signed char: SCHAR_MIN,        \
short      : SHRT_MIN,         \
int        : INT_MIN,          \
long       : LONG_MIN,         \
long long  : LLONG_MIN         \
)

#define cgs__min_tostr(ty)        \
_Generic((ty){0},                  \
signed char: cgs__schar_min_into, \
short      : cgs__short_min_into, \
int        : cgs__int_min_into,   \
long       : cgs__long_min_into,  \
long long  : cgs__llong_min_into  \
)

CGS_PRIVATE CGS_Error cgs__schar_min_into(CGS_MutStrRef dst)
{
    if(SCHAR_MIN == -128)
    {
        const char *numstr = "-128";
        CGS_StrView s = {.chars = (char*) numstr, .len = strlen(numstr)};
        return cgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hhd", SCHAR_MIN);
        return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = (char*) temp, .len = len});
    }
}

CGS_PRIVATE CGS_Error cgs__short_min_into(CGS_MutStrRef dst)
{
    if(SHRT_MIN == -32768)
    {
        const char *numstr = "-32768";
        CGS_StrView s = {.chars = (char*) numstr, .len = strlen(numstr)};
        return cgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hd", SHRT_MIN);
        return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = (char*) temp, .len = len});
    }
}

CGS_PRIVATE CGS_Error cgs__int_min_into(CGS_MutStrRef dst)
{
    if(INT_MIN == -2147483648)
    {
        const char *numstr = "-2147483648";
        CGS_StrView s = {.chars = (char*) numstr, .len = strlen(numstr)};
        return cgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%d", INT_MIN);
        return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = (char*) temp, .len = len});
    }
}

CGS_PRIVATE CGS_Error cgs__long_min_into(CGS_MutStrRef dst)
{
    if(LONG_MIN == INT_MIN)
    {
        return cgs__int_min_into(dst);
    }
    else if(LONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        CGS_StrView s = {.chars = (char*) numstr, .len = strlen(numstr)};
        return cgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%ld", LONG_MIN);
        return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = (char*) temp, .len = len});
    }
}

CGS_PRIVATE CGS_Error cgs__llong_min_into(CGS_MutStrRef dst)
{
    if(LLONG_MIN == LONG_MIN)
    {
        return cgs__long_min_into(dst);
    }
    else if(LLONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        CGS_StrView s = {.chars = (char*) numstr, .len = strlen(numstr)};
        return cgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%lld", LLONG_MIN);
        return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = (char*) temp, .len = len});
    }
}

#define cgs__sintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (CGS_Error){CGS_DST_TOO_SMALL}; \
    __typeof__(obj) num = obj; \
    \
    if(isneg) \
    { \
        fmutstr.chars[0] = '-'; \
    } \
    unsigned int chars_to_copy; \
    if(fmutstr.cap > numlen) \
    { \
        chars_to_copy = numlen; \
    } \
    else \
    { \
        err.ec = CGS_DST_TOO_SMALL; \
        chars_to_copy = fmutstr.cap - (1 + isneg); \
    } \
    num /= cgs__ten_pows[numlen - chars_to_copy]; \
    for (unsigned int i = 0; i < chars_to_copy ; i++) \
    { \
        unsigned int rem = num % 10; \
        num = num / 10; \
        fmutstr.chars[isneg + chars_to_copy - (i + 1)] = rem + '0'; \
    } \
    \
    *fmutstr.len = chars_to_copy + isneg; \
    fmutstr.chars[*fmutstr.len] = '\0'; \
} while(0)

#define cgs__sinteger_tostr_dstr(dstr) \
do { \
    err = cgs__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != CGS_OK) \
        return err; \
    \
    CGS__FixedMutStrRef as_fixed = cgs__dstr_ptr_as_fmutstr_ref(dstr); \
    cgs__sintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define cgs__sinteger_tostr() \
do { \
    /*cgs__mutstr_ref_clear(dst);*/ \
    CGS_Error err = {CGS_OK}; \
    if(obj == cgs__sinteger_min(__typeof__(obj))) \
    { \
        return cgs__min_tostr(__typeof__(obj))(dst); \
    } \
    bool isneg = false; \
    if(obj < 0) \
    { \
        isneg = true; \
        obj *= -1; \
    } \
    unsigned int numlen = cgs__numstr_len(obj); \
    switch(dst.ty) \
    { \
        case CGS__DSTR_TY: \
        { \
            cgs__sinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case CGS__STRBUF_TY: \
        { \
            CGS__FixedMutStrRef strbuf_as_fixed = cgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            cgs__sintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case CGS__BUF_TY: \
        { \
            CGS__FixedMutStrRef buf_as_fixed = cgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            cgs__sintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

#define cgs__uinteger_tostr_dstr(dstr) \
do { \
    err = cgs__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != CGS_OK) \
        return err; \
    \
    CGS__FixedMutStrRef as_fixed = { \
        .chars = dstr->chars, \
        .len = &dstr->len, \
        .cap = dstr->cap \
    }; \
    cgs__uintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define cgs__uintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (CGS_Error){CGS_DST_TOO_SMALL}; \
    __typeof__(obj) num = obj; \
    unsigned int chars_to_copy; \
    if(numlen < fmutstr.cap) \
    { \
        chars_to_copy = numlen; \
    } \
    else \
    { \
        err.ec = CGS_DST_TOO_SMALL; \
        chars_to_copy = fmutstr.cap - 1; \
    } \
    num /= cgs__ten_pows[numlen - chars_to_copy]; \
    for (unsigned int i = 0; i < chars_to_copy ; i++) \
    { \
        unsigned int rem = num % 10; \
        num = num / 10; \
        fmutstr.chars[chars_to_copy - (i + 1)] = rem + '0'; \
    } \
    \
    *fmutstr.len = chars_to_copy; \
    fmutstr.chars[*fmutstr.len] = '\0'; \
} while(0)

#define cgs__uinteger_tostr() \
do { \
    /*cgs__mutstr_ref_clear(dst);*/ \
    CGS_Error err = {CGS_OK}; \
    unsigned int numlen = cgs__numstr_len(obj); \
    switch(dst.ty) \
    { \
        case CGS__DSTR_TY: \
        { \
            cgs__uinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case CGS__STRBUF_TY: \
        { \
            CGS__FixedMutStrRef strbuf_as_fixed = cgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            cgs__uintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case CGS__BUF_TY: \
        { \
            CGS__FixedMutStrRef buf_as_fixed = cgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            cgs__uintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

CGS_API CGS_Error cgs__bool_tostr(CGS_MutStrRef dst, bool obj)
{
    CGS_StrView res = obj ? cgs__strv_cstr1("true") : cgs__strv_cstr1("false");
    return cgs__mutstr_ref_copy(dst, res);
}

CGS_API CGS_Error cgs__cstr_tostr(CGS_MutStrRef dst, const char *obj)
{
    return cgs__mutstr_ref_copy(
        dst,
        (CGS_StrView){
            .chars = (char*) obj,
            .len = strlen(obj)
        }
    );
}

CGS_API CGS_Error cgs__ucstr_tostr(CGS_MutStrRef dst, const unsigned char *obj)
{
    return cgs__mutstr_ref_copy(
        dst,
        (CGS_StrView){
            .chars = (char*) obj,
            .len = strlen((char*) obj)
        }
    );
}

CGS_API CGS_Error cgs__char_tostr(CGS_MutStrRef dst, char obj)
{
    cgs__mutstr_ref_clear(dst);
    return cgs__mutstr_ref_putc(dst, obj);
}

CGS_API CGS_Error cgs__schar_tostr(CGS_MutStrRef dst, signed char obj)
{
    return cgs__mutstr_ref_copy(dst, cgs__sc_to_string[(unsigned char)obj]);
}

CGS_API CGS_Error cgs__uchar_tostr(CGS_MutStrRef dst, unsigned char obj)
{
    cgs__mutstr_ref_clear(dst);
    return cgs__mutstr_ref_putc(dst, obj);
}

CGS_API CGS_Error cgs__short_tostr(CGS_MutStrRef dst, short obj)
{
    cgs__sinteger_tostr();
}

CGS_API CGS_Error cgs__ushort_tostr(CGS_MutStrRef dst, unsigned short obj)
{
    cgs__uinteger_tostr();
}

CGS_API CGS_Error cgs__int_tostr(CGS_MutStrRef dst, int obj)
{
    cgs__sinteger_tostr();
}

CGS_API CGS_Error cgs__uint_tostr(CGS_MutStrRef dst, unsigned int obj)
{
    cgs__uinteger_tostr();
}

CGS_API CGS_Error cgs__long_tostr(CGS_MutStrRef dst, long obj)
{
    cgs__sinteger_tostr();
}

CGS_API CGS_Error cgs__ulong_tostr(CGS_MutStrRef dst, unsigned long obj)
{
    cgs__uinteger_tostr();
}

CGS_API CGS_Error cgs__llong_tostr(CGS_MutStrRef dst, long long obj)
{
    cgs__sinteger_tostr();
}

CGS_API CGS_Error cgs__ullong_tostr(CGS_MutStrRef dst, unsigned long long obj)
{
    cgs__uinteger_tostr();
}

CGS_API CGS_Error cgs__float_tostr(CGS_MutStrRef dst, float obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return cgs__mutstr_ref_copy(
        dst,
        (CGS_StrView){
            .chars = (char*) tmp,
            .len = len
        }
    );
}

CGS_API CGS_Error cgs__double_tostr(CGS_MutStrRef dst, double obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return cgs__mutstr_ref_copy(
        dst,
        (CGS_StrView){
            .chars = (char*) tmp,
            .len = len
        }
    );
}

CGS_API CGS_Error cgs__error_tostr(CGS_MutStrRef dst, CGS_Error obj)
{
    return cgs__mutstr_ref_copy(dst, cgs__error_to_string[obj.ec]);
}

CGS_API CGS_Error cgs__array_fmt_tostr(CGS_MutStrRef dst, CGS_ArrayFmt obj)
{
    cgs__mutstr_ref_clear(dst);
    
    CGS_AppenderState appender_state;
    
    CGS_Error err = cgs__mutstr_ref_append(dst, obj.open);
    
    const uint8_t *arr = obj.array;
    
    if(obj.nb > 0)
    {
        for(size_t i = 0 ; i < obj.nb - 1 ; i++)
        {
            
            CGS_MutStrRef appender = cgs__make_appender_mutstr_ref(dst, &appender_state);
            
            err = obj.elm_tostr(appender, arr + (obj.elm_size * i));
            // TODO return if err?
            
            err = cgs__mutstr_ref_append(appender, obj.separator);
            
            cgs__mutstr_ref_commit_appender(dst, appender);
        }
        
        CGS_MutStrRef appender = cgs__make_appender_mutstr_ref(dst, &appender_state);
        err = obj.elm_tostr(appender, arr + obj.elm_size * (obj.nb - 1));
        cgs__mutstr_ref_commit_appender(dst, appender);
        
        err = cgs__mutstr_ref_append(dst, obj.trailing_separator);
    }
    
    err = cgs__mutstr_ref_append(dst, obj.close);
    
    return err;
}

CGS_API CGS_Error cgs__dstr_tostr(CGS_MutStrRef dst, const CGS_DStr obj)
{
    return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = obj.chars, .len = obj.len});
}

CGS_API CGS_Error cgs__dstr_ptr_tostr(CGS_MutStrRef dst, const CGS_DStr *obj)
{
    return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = obj->chars, .len = obj->len});
}

CGS_API CGS_Error cgs__strv_tostr(CGS_MutStrRef dst, const CGS_StrView obj)
{
    return cgs__mutstr_ref_copy(dst, obj);
}

CGS_API CGS_Error cgs__strbuf_tostr(CGS_MutStrRef dst, const CGS_StrBuf obj)
{
    return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = obj.chars, .len = obj.len});
}

CGS_API CGS_Error cgs__strbuf_ptr_tostr(CGS_MutStrRef dst, const CGS_StrBuf *obj)
{
    return cgs__mutstr_ref_copy(dst, (CGS_StrView){.chars = obj->chars, .len = obj->len});
}

CGS_API CGS_Error cgs__mutstr_ref_tostr(CGS_MutStrRef dst, const CGS_MutStrRef obj)
{
    return cgs__mutstr_ref_copy(dst, cgs__strv_mutstr_ref2(obj, 0));
}

CGS_PRIVATE CGS_Error cgs__uchar_d_tostr(CGS_MutStrRef dst, unsigned char obj)
{
    cgs__mutstr_ref_clear(dst);
    return cgs__mutstr_ref_append(dst, cgs__uc_to_string[obj]);
}

#define cgs__if_else(cond, then, else) \
_Generic((char(*)[(cond) + 1])0, char(*)[1]: else, char(*)[2]: then)

#define cgs__unsigned_of_size(sz)  \
__typeof__(_Generic((char(*)[sz])0, \
    char(*)[1]: (uint8_t) 0,        \
    char(*)[2]: (uint16_t)0,        \
    char(*)[4]: (uint32_t)0,        \
    char(*)[8]: (uint64_t)0         \
))

#define cgs__as_unsigned(n) \
((cgs__unsigned_of_size(sizeof(n))) n)

#define cgs__integer_d_Fmt_tostr(dst, num) \
return _Generic(num, \
    char: cgs__if_else(CHAR_MIN < 0, cgs__schar_tostr, cgs__uchar_d_tostr), \
    signed char: cgs__schar_tostr, \
    unsigned char: cgs__uchar_d_tostr, \
    short: cgs__short_tostr, \
    unsigned short: cgs__ushort_tostr, \
    int: cgs__int_tostr, \
    unsigned int: cgs__uint_tostr, \
    long: cgs__long_tostr, \
    unsigned long: cgs__ulong_tostr, \
    long long: cgs__llong_tostr, \
    unsigned long long: cgs__ullong_tostr \
)(dst, num)

#define cgs__integer_x_Fmt_tostr(dst, num, byte2hex) \
do \
{ \
    cgs__mutstr_ref_clear(dst); \
    CGS_Error err = {CGS_OK}; \
    size_t sz = sizeof(num); \
    uint8_t *num_bytes = ((uint8_t*) &num) + sizeof(num) - 1; \
    bool zero_pad = true; \
    while(sz--) \
    { \
        if(num_bytes == (uint8_t*)&num || !zero_pad || *num_bytes != 0) \
        { \
            CGS_StrView hex_sv = {.chars = (char*) byte2hex[*num_bytes], .len = 2}; \
            if(zero_pad && hex_sv.chars[0] == '0') \
            { \
                hex_sv.chars += 1; \
                hex_sv.len -= 1; \
            } \
            zero_pad = false; \
            err = cgs__mutstr_ref_append(dst, hex_sv); \
        } \
        num_bytes -= 1; \
    } \
    cgs__mutstr_ref_set_len(dst, cgs__mutstr_ref_len(dst)); \
    return err; \
} while(0)

#define cgs__bswap(num)                \
_Generic((char(*)[sizeof(num)])0,       \
    char(*)[1]: num,                    \
    char(*)[2]: __builtin_bswap16(num), \
    char(*)[4]: __builtin_bswap32(num), \
    char(*)[8]: __builtin_bswap64(num)  \
)

#define cgs__highest_bit(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b1) << (sizeof(n) * 8 - 1))))

#define cgs__highest_bit_as_u8(n) \
(cgs__highest_bit(n) >> ((sizeof(n) - 1) * 8))

#define cgs__highest_3bits(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b111) << (sizeof(n) * 8 - 3))))

#define cgs__highest_3bits_as_u8(n) \
(cgs__highest_3bits(n) >> ((sizeof(n) - 1) * 8))

// TODO optimize these. dont clear then append chars.
// instead, write from beginning of chars up to cap, then put the nul
#define cgs__integer_o_Fmt_tostr(dst, num) \
do \
{ \
    cgs__mutstr_ref_clear(dst); \
    cgs__unsigned_of_size(sizeof(num)) unum = num; \
    CGS_Error err = {CGS_OK}; \
    const size_t bits = (sizeof(unum) * 8); \
    int iters = bits / 3; \
    uint8_t extra_bits = 3 - ((sizeof(unum) * 8) % 3); \
    uint8_t high3 = cgs__highest_3bits_as_u8(unum); \
    uint8_t first_3bits = high3 >> extra_bits; \
    first_3bits = first_3bits >> 5; \
    bool zero_pad = true; \
    if(first_3bits != 0) \
    { \
        zero_pad = false; \
        CGS_StrView octal_sv = {.chars = &(char){'0' + first_3bits}, .len = 1}; \
        err = cgs__mutstr_ref_append(dst, octal_sv); \
    } \
    unum = unum << (3 - extra_bits); \
    \
    for(int i = 0 ; i < iters ; i++) \
    { \
        high3 = cgs__highest_3bits_as_u8(unum); \
        first_3bits = high3 >> (8 - 3); \
        if(i == (iters - 1) || !zero_pad || (first_3bits != 0)) \
        { \
            zero_pad =  false; \
            CGS_StrView octal_sv = {.chars = &(char){'0' + first_3bits}, .len = 1}; \
            err = cgs__mutstr_ref_append(dst, octal_sv); \
        } \
        unum = unum << 3; \
    } \
    cgs__mutstr_ref_set_len(dst, cgs__mutstr_ref_len(dst)); \
    return err; \
} while(0)

#define cgs__integer_b_Fmt_tostr(dst, num) \
do \
{ \
    cgs__mutstr_ref_clear(dst); \
    CGS_Error err = {CGS_OK}; \
    cgs__unsigned_of_size(sizeof(num)) unum = num; \
    size_t sz; \
    if(dst.ty == CGS__DSTR_TY) \
    { \
        sz = sizeof(unum) * 8; \
        cgs__dstr_maybe_grow(dst.str.dstr, sizeof(unum) * 8 + 1); \
    } \
    else \
    { \
        sz = cgs__mutstr_ref_cap(dst) - 1; \
    } \
    char *bytes = cgs__mutstr_ref_as_cstr(dst); \
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
    cgs__mutstr_ref_set_len(dst, written); \
    return err; \
} while(0)

#define CGS__X(ty, extra) \
CGS_API CGS_Error cgs__Integer_d_Fmt_##ty##_tostr(CGS_MutStrRef dst, CGS__Integer_d_Fmt_##ty obj) \
{ \
    cgs__integer_d_Fmt_tostr(dst, obj.obj); \
} \
CGS_API CGS_Error cgs__Integer_x_Fmt_##ty##_tostr(CGS_MutStrRef dst, CGS__Integer_x_Fmt_##ty obj) \
{ \
    cgs__mutstr_ref_clear(dst); \
    cgs__integer_x_Fmt_tostr(dst, obj.obj, cgs__byte_to_hex); \
} \
CGS_API CGS_Error cgs__Integer_o_Fmt_##ty##_tostr(CGS_MutStrRef dst, CGS__Integer_o_Fmt_##ty obj) \
{ \
    cgs__mutstr_ref_clear(dst); \
    cgs__integer_o_Fmt_tostr(dst, obj.obj); \
} \
CGS_API CGS_Error cgs__Integer_b_Fmt_##ty##_tostr(CGS_MutStrRef dst, CGS__Integer_b_Fmt_##ty obj) \
{ \
    cgs__mutstr_ref_clear(dst); \
    cgs__integer_b_Fmt_tostr(dst, obj.obj); \
} \
CGS_API CGS_Error cgs__Integer_X_Fmt_##ty##_tostr(CGS_MutStrRef dst, CGS__Integer_X_Fmt_##ty obj) \
{ \
    cgs__mutstr_ref_clear(dst); \
    cgs__integer_x_Fmt_tostr(dst, obj.obj, cgs__byte_to_heX); \
} \
\
\
CGS_API CGS_Error cgs__Integer_d_Fmt_##ty##_tostr_p(CGS_MutStrRef dst, CGS__Integer_d_Fmt_##ty *obj) \
{ \
    return cgs__Integer_d_Fmt_##ty##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Integer_x_Fmt_##ty##_tostr_p(CGS_MutStrRef dst, CGS__Integer_x_Fmt_##ty *obj) \
{ \
    return cgs__Integer_x_Fmt_##ty##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Integer_o_Fmt_##ty##_tostr_p(CGS_MutStrRef dst, CGS__Integer_o_Fmt_##ty *obj) \
{ \
    return cgs__Integer_o_Fmt_##ty##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Integer_b_Fmt_##ty##_tostr_p(CGS_MutStrRef dst, CGS__Integer_b_Fmt_##ty *obj) \
{ \
    return cgs__Integer_b_Fmt_##ty##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Integer_X_Fmt_##ty##_tostr_p(CGS_MutStrRef dst, CGS__Integer_X_Fmt_##ty *obj) \
{ \
    return cgs__Integer_X_Fmt_##ty##_tostr(dst, *obj); \
} \

CGS__INTEGER_TYPES(CGS__X, ignore)

#undef CGS__X

#define cgs__floating_fmt(fmt_strlit) \
    cgs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, fmt_strlit, obj.precision, obj.obj); \
    if(dst.ty == CGS__DSTR_TY) \
    { \
        cgs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(cgs__mutstr_ref_as_cstr(dst), cgs__mutstr_ref_cap(dst), fmt_strlit, obj.precision, obj.obj); \
    if(cgs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        cgs__mutstr_ref_set_len(dst, cgs__mutstr_ref_cap(dst) - 1); \
        return (CGS_Error){CGS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        cgs__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (CGS_Error){CGS_ENCODING_ERROR}; \
    return (CGS_Error){CGS_OK};

#define CGS__X(type, extra) \
CGS_API CGS_Error cgs__Floating_f_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_f_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*f") \
} \
CGS_API CGS_Error cgs__Floating_g_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_g_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*g") \
} \
CGS_API CGS_Error cgs__Floating_e_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_e_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*e") \
} \
CGS_API CGS_Error cgs__Floating_a_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_a_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*a") \
} \
CGS_API CGS_Error cgs__Floating_F_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_F_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*F") \
} \
CGS_API CGS_Error cgs__Floating_G_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_G_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*G") \
} \
CGS_API CGS_Error cgs__Floating_E_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_E_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*E") \
} \
CGS_API CGS_Error cgs__Floating_A_Fmt_##type##_tostr(CGS_MutStrRef dst, CGS__Floating_A_Fmt_##type obj) \
{ \
    cgs__floating_fmt("%.*A") \
} \
\
\
CGS_API CGS_Error cgs__Floating_f_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_f_Fmt_##type *obj) \
{ \
    return cgs__Floating_f_Fmt_##type##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Floating_g_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_g_Fmt_##type *obj) \
{ \
    return cgs__Floating_g_Fmt_##type##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Floating_e_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_e_Fmt_##type *obj) \
{ \
    return cgs__Floating_e_Fmt_##type##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Floating_a_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_a_Fmt_##type *obj) \
{ \
    return cgs__Floating_a_Fmt_##type##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Floating_F_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_F_Fmt_##type *obj) \
{ \
    return cgs__Floating_F_Fmt_##type##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Floating_G_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_G_Fmt_##type *obj) \
{ \
    return cgs__Floating_G_Fmt_##type##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Floating_E_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_E_Fmt_##type *obj) \
{ \
    return cgs__Floating_E_Fmt_##type##_tostr(dst, *obj); \
} \
CGS_API CGS_Error cgs__Floating_A_Fmt_##type##_tostr_p(CGS_MutStrRef dst, CGS__Floating_A_Fmt_##type *obj) \
{ \
    return cgs__Floating_A_Fmt_##type##_tostr(dst, *obj); \
}

CGS__FLOATING_TYPES(CGS__X, ignore, CGS__X)

#undef CGS__X

CGS_API CGS_Error cgs__bool_tostr_p(CGS_MutStrRef dst, bool *obj)
{
    return cgs__bool_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__cstr_tostr_p(CGS_MutStrRef dst, const char **obj)
{
    return cgs__cstr_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__ucstr_tostr_p(CGS_MutStrRef dst, const unsigned char **obj)
{
    return cgs__ucstr_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__char_tostr_p(CGS_MutStrRef dst, char *obj)
{
    return cgs__char_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__schar_tostr_p(CGS_MutStrRef dst, signed char *obj)
{
    return cgs__schar_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__uchar_tostr_p(CGS_MutStrRef dst, unsigned char *obj)
{
    return cgs__uchar_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__short_tostr_p(CGS_MutStrRef dst, short *obj)
{
    return cgs__short_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__ushort_tostr_p(CGS_MutStrRef dst, unsigned short *obj)
{
    return cgs__ushort_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__int_tostr_p(CGS_MutStrRef dst, int *obj)
{
    return cgs__int_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__uint_tostr_p(CGS_MutStrRef dst, unsigned int *obj)
{
    return cgs__uint_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__long_tostr_p(CGS_MutStrRef dst, long *obj)
{
    return cgs__long_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__ulong_tostr_p(CGS_MutStrRef dst, unsigned long *obj)
{
    return cgs__ulong_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__llong_tostr_p(CGS_MutStrRef dst, long long *obj)
{
    return cgs__llong_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__ullong_tostr_p(CGS_MutStrRef dst, unsigned long long *obj)
{
    return cgs__ullong_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__float_tostr_p(CGS_MutStrRef dst, float *obj)
{
    return cgs__float_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__double_tostr_p(CGS_MutStrRef dst, double *obj)
{
    return cgs__double_tostr(dst, *obj);
}

CGS_API CGS_Error cgs__dstr_tostr_p(CGS_MutStrRef dst, const CGS_DStr *obj)
{
    return cgs__dstr_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__dstr_ptr_tostr_p(CGS_MutStrRef dst, const CGS_DStr **obj)
{
    return cgs__dstr_ptr_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__strv_tostr_p(CGS_MutStrRef dst, const CGS_StrView *obj)
{
    return cgs__strv_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__strbuf_tostr_p(CGS_MutStrRef dst, const CGS_StrBuf *obj)
{
    return cgs__strbuf_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__strbuf_ptr_tostr_p(CGS_MutStrRef dst, const CGS_StrBuf **obj)
{
    return cgs__strbuf_ptr_tostr(dst, *obj);
}
CGS_API CGS_Error cgs__mutstr_ref_tostr_p(CGS_MutStrRef dst, const CGS_MutStrRef *obj)
{
    return cgs__mutstr_ref_tostr(dst, *obj);
}

CGS_API CGS_Error cgs__error_tostr_p(CGS_MutStrRef dst, CGS_Error *obj)
{
    return cgs__error_tostr(dst, *obj);
}

CGS_API CGS_Error cgs__array_fmt_tostr_p(CGS_MutStrRef dst, CGS_ArrayFmt *obj)
{
    return cgs__array_fmt_tostr(dst, *obj);
}

#endif // CGS__STR_C_INCLUDED