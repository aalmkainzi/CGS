#include <ctype.h>

#ifndef FXS_API
    // for functions exposed in the header
    #define FXS_API
#endif
#ifndef FXS_PRIVATE
    // for functions only in fxs.c
    #define FXS_PRIVATE
#endif
#ifndef FXS_PRIVATE_VAR
    // for global variables in fxs.c that user code may access
    #define FXS_PRIVATE_VAR
#endif

#include "fxs.h"

#if !defined(FXS__STR_C_INCLUDED)
#define FXS__STR_C_INCLUDED

#if !defined(unreachable)
    #if defined(_MSC_VER)
        #define unreachable() __assume(0)
    #elif defined(__GNUC__)
        #define unreachable() __builtin_unreachable()
    #else
        #define unreachable()
    #endif
#endif

FXS_PRIVATE FXS_Allocation fxs__default_allocator_alloc(FXS_Allocator *ctx, size_t alignment, size_t n);
FXS_PRIVATE void fxs__default_allocator_dealloc(FXS_Allocator *ctx, void *ptr, size_t n);
FXS_PRIVATE FXS_Allocation fxs__default_allocator_realloc(FXS_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size);

static FXS_Allocator fxs__default_allocator = {
    .alloc   = fxs__default_allocator_alloc,
    .dealloc = fxs__default_allocator_dealloc,
    .realloc = fxs__default_allocator_realloc,
};

static const FXS_StrView fxs__error_to_string[] = {
    [FXS_OK]                     = {.len = sizeof("OK")                     - 1, .chars = (unsigned char*) "OK"},
    [FXS_DST_TOO_SMALL]          = {.len = sizeof("DST_TOO_SMALL")          - 1, .chars = (unsigned char*) "DST_TOO_SMALL"},
    [FXS_ALLOC_ERR]              = {.len = sizeof("ALLOC_ERR")              - 1, .chars = (unsigned char*) "ALLOC_ERR"},
    [FXS_INDEX_OUT_OF_BOUNDS]    = {.len = sizeof("INDEX_OUT_OF_BOUNDS")    - 1, .chars = (unsigned char*) "INDEX_OUT_OF_BOUNDS"},
    [FXS_BAD_RANGE]              = {.len = sizeof("BAD_RANGE")              - 1, .chars = (unsigned char*) "BAD_RANGE"},
    [FXS_NOT_FOUND]              = {.len = sizeof("NOT_FOUND")              - 1, .chars = (unsigned char*) "NOT_FOUND"},
    [FXS_ALIASING_NOT_SUPPORTED] = {.len = sizeof("ALIASING_NOT_SUPPORTED") - 1, .chars = (unsigned char*) "ALIASING_NOT_SUPPORTED"},
    [FXS_INCORRECT_TYPE]         = {.len = sizeof("INCORRECT_TYPE")         - 1, .chars = (unsigned char*) "INCORRECT_TYPE"},
    [FXS_ENCODING_ERROR]         = {.len = sizeof("ENCODING_ERROR")         - 1, .chars = (unsigned char*) "ENCODING_ERROR"},
    [FXS_CALLBACK_EXIT]          = {.len = sizeof("CALLBACK_EXIT")          - 1, .chars = (unsigned char*) "CALLBACK_EXIT"}
};

static const long long fxs__ten_pows[] = {
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

static const unsigned long long fxs__ten_pows_ull[] = {
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

static const FXS_StrView fxs__uc_to_string[256] = {
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

static const FXS_StrView fxs__sc_to_string[] = {
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

static const char fxs__byte_to_hex[][2] = 
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

FXS_PRIVATE_VAR _Thread_local FXS_DStr fxs__fprint_tostr_dynamic_buffer = {
    .allocator = &fxs__default_allocator
};

FXS_API FXS__FixedMutStrRef fxs__buf_as_fmutstr_ref(FXS_Buffer buf, unsigned int *len_ptr)
{
    *len_ptr = strlen((char*) buf.ptr);
    FXS__FixedMutStrRef ret = {
        .chars = buf.ptr,
        .cap = buf.cap,
        .len = len_ptr
    };
    return ret;
}

FXS_API FXS__FixedMutStrRef fxs__strbuf_ptr_as_fmutstr_ref(FXS_StrBuf *strbuf)
{
    FXS__FixedMutStrRef ret = {
        .chars = strbuf->chars,
        .cap = strbuf->cap,
        .len = &strbuf->len
    };
    return ret;
}

FXS_API FXS__FixedMutStrRef fxs__dstr_ptr_as_fmutstr_ref(FXS_DStr *dstr)
{
    FXS__FixedMutStrRef ret = {
        .chars = dstr->chars,
        .cap = dstr->cap,
        .len = &dstr->len
    };
    return ret;
}

FXS_PRIVATE FXS_Allocation fxs__default_allocator_alloc(FXS_Allocator *ctx, size_t alignment, size_t n)
{
    (void) alignment;
    (void) ctx;
    void *mem = malloc(n);
    return (FXS_Allocation){
        .ptr = mem,
        .n = n
    };
}

FXS_PRIVATE void fxs__default_allocator_dealloc(FXS_Allocator *ctx, void *ptr, size_t n)
{
    (void) ctx;
    (void) n;
    free(ptr);
}

FXS_PRIVATE FXS_Allocation fxs__default_allocator_realloc(FXS_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) ctx;
    (void) alignment;
    (void) old_size;
    void *mem = realloc(ptr, new_size);
    return (FXS_Allocation){
        .ptr = mem,
        .n = new_size
    };
}

FXS_PRIVATE FXS_Allocation fxs__dstr_append_allocator_alloc(FXS_Allocator *allocator, size_t alignment, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) alignment;
    (void) n;
    return (FXS_Allocation){0};
}

FXS_PRIVATE void fxs__dstr_append_allocator_dealloc(FXS_Allocator *allocator, void *ptr, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) ptr;
    (void) n;
}

FXS_PRIVATE FXS_Allocation fxs__dstr_append_allocator_realloc(FXS_Allocator *allocator, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) alignment;
    
    FXS__DStrAppendAllocator *dstr_append_allocator = (__typeof__(dstr_append_allocator)) allocator;
    
    FXS_DStr *owner = dstr_append_allocator->owner;
    
    assert(old_size == owner->cap - owner->len);
    assert(((unsigned char*)ptr - owner->chars) == owner->len);
    
    fxs_dstr_ensure_cap(owner, owner->cap + (new_size - old_size));
    return (FXS_Allocation){
        .ptr = owner->chars + owner->len,
        .n = owner->cap - owner->len
    };
}

FXS_API FXS_Allocation fxs__allocator_invoke_alloc(FXS_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb)
{
    return allocator->alloc(allocator, alignment, nb * obj_size);
}

FXS_API void fxs__allocator_invoke_dealloc(FXS_Allocator *allocator, void *ptr, size_t obj_size, size_t nb)
{
    allocator->dealloc(allocator, ptr, nb * obj_size);
}

FXS_API FXS_Allocation fxs__allocator_invoke_realloc(FXS_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb)
{
    return allocator->realloc(allocator, ptr, alignment, old_nb * obj_size, new_nb * obj_size);
}

FXS_API FXS_Allocator *fxs_get_default_allocator()
{
    return &fxs__default_allocator;
}

FXS_PRIVATE void fxs__make_dstr_append_allocator(FXS_DStr *dstr, FXS__DStrAppendAllocator *out)
{
    *out = (FXS__DStrAppendAllocator){
        .base = {
            .alloc   = fxs__dstr_append_allocator_alloc,
            .dealloc = fxs__dstr_append_allocator_dealloc,
            .realloc = fxs__dstr_append_allocator_realloc,
        },
        .owner = dstr
    };
}

FXS_PRIVATE FXS_DStr fxs__make_appender_dstr(FXS_DStr *owner, FXS__DStrAppendAllocator *allocator)
{
    fxs__make_dstr_append_allocator(owner, allocator);
    return (FXS_DStr){
        .allocator = (void*) allocator,
        .cap = owner->cap - owner->len,
        .len = 0,
        .chars = owner->chars + owner->len
    };
}

FXS_PRIVATE FXS_StrBuf fxs__make_appender_strbuf(FXS_MutStrRef owner)
{
    return (FXS_StrBuf){
        .cap = fxs__mutstr_ref_cap(owner) - fxs__mutstr_ref_len(owner),
        .len = 0,
        .chars = (unsigned char*) fxs__mutstr_ref_as_cstr(owner) + fxs__mutstr_ref_len(owner)
    };
}

FXS_API FXS_MutStrRef fxs__make_appender_mutstr_ref(FXS_MutStrRef owner, FXS_StrAppenderState *state)
{
    switch(owner.ty)
    {
        case FXS__DSTR_TY    :
            state->appender_dstr = fxs__make_appender_dstr(owner.str.dstr, &state->dstr_append_allocator);
            return fxs__dstr_ptr_as_mutstr_ref(&state->appender_dstr);
        case FXS__STRBUF_TY  :
        case FXS__BUF_TY     :
            ;
            FXS_MutStrRef ret = {.ty = FXS__STRBUF_TY};
            ret.str.strbuf = &state->appender_buf;
            *ret.str.strbuf = fxs__make_appender_strbuf(owner);
            return ret;
        default               :
            unreachable();
    }
}

FXS_PRIVATE unsigned int fxs__uint_min(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

FXS_PRIVATE unsigned int fxs__uint_max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

FXS_PRIVATE unsigned int fxs__chars_strlen(const char *chars, unsigned int cap)
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

FXS_API bool fxs__is_strv_within(FXS_StrView base, FXS_StrView sub)
{
    uintptr_t begin = (uintptr_t) base.chars;
    uintptr_t end = (uintptr_t) (base.chars + base.len);
    uintptr_t sub_begin = (uintptr_t) sub.chars;
    return sub_begin >= begin && sub_begin < end;
}

FXS__NODISCARD("discarding a new DString may cause memory leak")
FXS_API FXS_DStr fxs__dstr_init(unsigned int cap, FXS_Allocator *allocator)
{
    FXS_DStr ret = { 0 };
    
    ret.allocator = allocator;
    
    FXS_Allocation allocation = fxs_alloc(allocator, unsigned char, cap);
    ret.chars = allocation.ptr;
    ret.cap = allocation.n;
    
    if(ret.chars != NULL)
    {
        ret.chars[0] = '\0';
    }
    
    return ret;
}

FXS_API FXS_DStr fxs__dstr_init_from(const FXS_StrView str, FXS_Allocator *allocator)
{
    FXS_DStr ret = fxs__dstr_init(str.len + 1, allocator);
    
    fxs__dstr_copy(&ret, str);
    
    return ret;
}

FXS_API void fxs__dstr_deinit(FXS_DStr *dstr)
{
    fxs_dealloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap);
    dstr->cap = 0;
    dstr->len = 0;
    dstr->chars = NULL;
}

FXS_API FXS_Error fxs__dstr_shrink_to_fit(FXS_DStr *dstr)
{
    FXS_Allocation allocation = fxs_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, dstr->len + 1);
    if(allocation.ptr == NULL)
    {
        return (FXS_Error){FXS_ALLOC_ERR};
    }
    else
    {
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        return (FXS_Error){FXS_OK};
    }
}

FXS_PRIVATE FXS_Error fxs__dstr_maybe_grow(FXS_DStr *dstr, unsigned int len_to_append)
{
    return fxs__dstr_ensure_cap(dstr, dstr->len + len_to_append + 1);
}

FXS_API FXS_Error fxs__dstr_append(FXS_DStr *dstr, const FXS_StrView src)
{
    FXS_StrView to_append = src;
    FXS_Error err = (FXS_Error){FXS_OK};
    if(fxs__is_strv_within(fxs__strv_dstr_ptr2(dstr, 0), to_append))
    {
        unsigned int begin_idx = to_append.chars - dstr->chars;
        err = fxs__dstr_maybe_grow(dstr, to_append.len + 1);
        to_append = (FXS_StrView){
            .len   = to_append.len,
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = fxs__dstr_maybe_grow(dstr, to_append.len);
    }
    
    if(err.ec == FXS_OK)
    {
        memmove(dstr->chars + dstr->len, to_append.chars, to_append.len * sizeof(unsigned char));
        
        dstr->len += to_append.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

FXS_API FXS_Error fxs__dstr_prepend_strv(FXS_DStr *dstr, const FXS_StrView src)
{
    FXS_StrView to_prepend = src;
    FXS_Error err = (FXS_Error){FXS_OK};
    
    if(fxs__is_strv_within(fxs__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        err = fxs__dstr_maybe_grow(dstr, src.len);
        to_prepend = (FXS_StrView){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = fxs__dstr_maybe_grow(dstr, to_prepend.len);
    }
    
    if(err.ec == FXS_OK)
    {
        memmove(dstr->chars + to_prepend.len, dstr->chars, dstr->len);
        memmove(dstr->chars, to_prepend.chars, to_prepend.len);
        
        dstr->len += to_prepend.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

FXS_API FXS_Error fxs__dstr_insert(FXS_DStr *dstr, const FXS_StrView src, unsigned int idx)
{
    if(idx > dstr->len)
    {
        return (FXS_Error){FXS_INDEX_OUT_OF_BOUNDS};
    }
    
    FXS_StrView to_insert = src;
    
    if(fxs__is_strv_within(fxs__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        fxs__dstr_maybe_grow(dstr, src.len);
        to_insert = (FXS_StrView){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        fxs__dstr_maybe_grow(dstr, to_insert.len);
    }
    
    memmove(dstr->chars + idx + to_insert.len, dstr->chars + idx, dstr->len - idx);
    memmove(dstr->chars + idx, to_insert.chars, to_insert.len);
    
    dstr->len += to_insert.len;
    dstr->chars[dstr->len] = '\0';
    
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__dstr_ensure_cap(FXS_DStr *dstr, unsigned int at_least)
{
    if(dstr->cap < at_least)
    {
        unsigned char *save = dstr->chars;
        size_t new_cap = fxs__uint_max(at_least, dstr->cap * 2);
        FXS_Allocation allocation = fxs_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, new_cap);
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        
        if(dstr->chars == NULL)
        {
            dstr->chars = save;
            return (FXS_Error){FXS_ALLOC_ERR};
        }
        if(dstr->cap < new_cap)
        {
            return (FXS_Error){FXS_ALLOC_ERR};
        }
    }
    
    return (FXS_Error){FXS_OK};
}

FXS_API char *fxs__cstr_as_cstr(const char *str)
{
    return (char*) str;
}

FXS_API char *fxs__ucstr_as_cstr(const unsigned char *str)
{
    return (char*) str;
}

FXS_API char *fxs__dstr_as_cstr(const FXS_DStr str)
{
    return (char*) str.chars;
}

FXS_API char *fxs__dstr_ptr_as_cstr(const FXS_DStr *str)
{
    return (char*) str->chars;
}

FXS_API char *fxs__strv_as_cstr(const FXS_StrView str)
{
    return (char*) str.chars;
}

FXS_API char *fxs__strbuf_as_cstr(const FXS_StrBuf str)
{
    return (char*) str.chars;
}

FXS_API char *fxs__strbuf_ptr_as_cstr(const FXS_StrBuf *str)
{
    return (char*) str->chars;
}

FXS_API char *fxs__mutstr_ref_as_cstr(const FXS_MutStrRef str)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return (char*) str.str.dstr->chars;
        case FXS__STRBUF_TY   : return (char*) str.str.strbuf->chars;
        case FXS__BUF_TY      : return (char*) str.str.buf.ptr;
        default                : unreachable();
    };
}

FXS_API unsigned char fxs__cstr_char_at(const char *str, unsigned int idx)
{
    return str[idx];
}

FXS_API unsigned char fxs__ucstr_char_at(const unsigned char *str, unsigned int idx)
{
    return str[idx];
}

FXS_API unsigned char fxs__dstr_char_at(const FXS_DStr str, unsigned int idx)
{
    return str.chars[idx];
}

FXS_API unsigned char fxs__dstr_ptr_char_at(const FXS_DStr *str, unsigned int idx)
{
    return str->chars[idx];
}

FXS_API unsigned char fxs__strv_char_at(const FXS_StrView str, unsigned int idx)
{
    return str.chars[idx];
}

FXS_API unsigned char fxs__strbuf_char_at(const FXS_StrBuf str, unsigned int idx)
{
    return str.chars[idx];
}

FXS_API unsigned char fxs__strbuf_ptr_char_at(const FXS_StrBuf *str, unsigned int idx)
{
    return str->chars[idx];
}

FXS_API unsigned char fxs__mutstr_ref_char_at(const FXS_MutStrRef str, unsigned int idx)
{
    return fxs__mutstr_ref_as_cstr(str)[idx];
}

FXS_API FXS_Error fxs__mutstr_ref_set_len(FXS_MutStrRef str, unsigned int new_len)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     :
            str.str.dstr->len = new_len;
            str.str.dstr->chars[new_len] = '\0';
            assert(str.str.dstr->cap >= str.str.dstr->len);
            break;
        case FXS__STRBUF_TY   :
            str.str.strbuf->len = new_len;
            str.str.strbuf->chars[new_len] = '\0';
            assert(str.str.strbuf->cap >= str.str.strbuf->len);
            break;
        case FXS__BUF_TY      :
            str.str.buf.ptr[new_len] = '\0';
            break;
        default                :
            unreachable();
    };
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__mutstr_ref_commit_appender(FXS_MutStrRef owner, FXS_MutStrRef appender)
{
    return fxs__mutstr_ref_set_len(
        owner,
        fxs__mutstr_ref_len(owner) + fxs__mutstr_ref_len(appender) \
    );
}

FXS_API unsigned int fxs__dstr_cap(const FXS_DStr str)
{
    return str.cap;
}

FXS_API unsigned int fxs__dstr_ptr_cap(const FXS_DStr *str)
{
    return str->cap;
}

FXS_API unsigned int fxs__strbuf_cap(const FXS_StrBuf str)
{
    return str.cap;
}

FXS_API unsigned int fxs__strbuf_ptr_cap(const FXS_StrBuf *str)
{
    return str->cap;
}

FXS_API unsigned int fxs__buf_cap(const FXS_Buffer buf)
{
    return buf.cap;
}

FXS_API unsigned int fxs__mutstr_ref_cap(const FXS_MutStrRef str)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return str.str.dstr->cap;
        case FXS__STRBUF_TY   : return str.str.strbuf->cap;
        case FXS__BUF_TY      : return str.str.buf.cap;
        default                : unreachable();
    };
}

FXS_API unsigned int fxs__mutstr_ref_len(const FXS_MutStrRef str)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return str.str.dstr->len;
        case FXS__STRBUF_TY   : return str.str.strbuf->len;
        case FXS__BUF_TY      : return strlen((char*) str.str.buf.ptr);
        default                : unreachable();
    };
}

FXS_API FXS_Error fxs__fmutstr_ref_insert(FXS__FixedMutStrRef dst, const FXS_StrView src, unsigned int idx)
{
    unsigned int len = *dst.len;
    if(idx > len)
    {
        return (FXS_Error){FXS_INDEX_OUT_OF_BOUNDS};
    }
    
    unsigned int nb_chars_to_insert = fxs__uint_min(dst.cap - len - 1, src.len);
    
    // shift right
    memmove(dst.chars + idx + nb_chars_to_insert, dst.chars + idx, len - idx);
    
    // insert the src
    memmove(dst.chars + idx, src.chars, nb_chars_to_insert);
    
    len += nb_chars_to_insert;
    
    *dst.len = len;
    
    return nb_chars_to_insert == src.len ? (FXS_Error){FXS_OK} : (FXS_Error){FXS_DST_TOO_SMALL};
}

FXS_API FXS_Error fxs__mutstr_ref_insert(FXS_MutStrRef dst, const FXS_StrView src, unsigned int idx)
{
    switch(dst.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_insert(dst.str.dstr, src, idx);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_insert(fxs__fmutstr_ref(dst.str.strbuf), src, idx);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_insert(fxs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src, idx);
        default                : unreachable();
    };
}

FXS_API bool fxs__strv_equal(const FXS_StrView str1, const FXS_StrView str2)
{
    return
    (str1.len == str2.len) &&
    (memcmp(str1.chars, str2.chars, str1.len) == 0);
}

FXS_API FXS_StrView fxs__strv_find(const FXS_StrView hay, const FXS_StrView needle)
{
    if(hay.chars == NULL || needle.chars == NULL || hay.len == 0 || needle.len > hay.len)
        return (FXS_StrView){.chars = NULL, .len = 0};
    if(needle.len == 0)
        return (FXS_StrView){.chars = hay.chars, .len = 0};
    
    unsigned char *max_possible_ptr = &hay.chars[hay.len] - needle.len;
    unsigned char *first_char = hay.chars;
    unsigned int remaining_len = hay.len;
    
    while(first_char && first_char <= max_possible_ptr)
    {
        if(memcmp(first_char, needle.chars, needle.len) == 0)
            return (FXS_StrView){.chars = first_char, .len = needle.len};
        first_char = memchr(first_char + 1, needle.chars[0], remaining_len - 1);
        remaining_len = hay.len - (first_char - hay.chars);
    }
    
    return (FXS_StrView){.chars = NULL, .len = 0};
}

FXS_API FXS_Error fxs__fmutstr_ref_copy(FXS__FixedMutStrRef dst, const FXS_StrView src)
{
    unsigned int chars_to_copy = fxs__uint_min(src.len, dst.cap - 1);
    
    memmove(dst.chars, src.chars, chars_to_copy * sizeof(unsigned char));
    dst.chars[chars_to_copy] = '\0';
    
    *dst.len = chars_to_copy;
    
    return chars_to_copy == src.len ? (FXS_Error){FXS_OK} : (FXS_Error){FXS_DST_TOO_SMALL};
}

FXS_API FXS_Error fxs__dstr_copy(FXS_DStr *dstr, FXS_StrView src)
{
    FXS_Error err = fxs__dstr_ensure_cap(dstr, src.len + 1);
    
    if(err.ec == FXS_OK)
    {
        memmove(dstr->chars, src.chars, src.len * sizeof(unsigned char));
        
        dstr->len = src.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

FXS_API FXS_Error fxs__mutstr_ref_copy(FXS_MutStrRef dst, const FXS_StrView src)
{
    switch(dst.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_copy(dst.str.dstr, src);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_copy(fxs__fmutstr_ref(dst.str.strbuf), src);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_copy(fxs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

FXS_API FXS_Error fxs__dstr_putc(FXS_DStr *dst, unsigned char c)
{
    FXS_Error err = fxs__dstr_ensure_cap(dst, dst->len + 2);
    if(err.ec != FXS_OK)
        return err;
    
    dst->chars[dst->len] = c;
    dst->chars[dst->len + 1] = '\0';
    dst->len += 1;
    
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__fmutstr_ref_putc(FXS__FixedMutStrRef dst, unsigned char c)
{
    if(dst.cap - *dst.len <= 1)
    {
        return (FXS_Error){FXS_DST_TOO_SMALL};
    }
    
    dst.chars[*dst.len] = c;
    dst.chars[*dst.len + 1] = '\0';
    *dst.len += 1;
    
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__mutstr_ref_putc(FXS_MutStrRef dst, unsigned char c)
{
    switch(dst.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_putc(dst.str.dstr, c);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_putc(fxs__fmutstr_ref(dst.str.strbuf), c);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_putc(fxs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), c);
        default                : unreachable();
    }
}

FXS_API FXS_Error fxs__fmutstr_ref_append(FXS__FixedMutStrRef dst, const FXS_StrView src)
{
    unsigned int dst_len = *dst.len;
    
    unsigned int chars_to_copy = fxs__uint_min(src.len, dst.cap - dst_len - 1);
    memmove(dst.chars + dst_len, src.chars, chars_to_copy);
    
    dst_len += chars_to_copy;
    
    if(dst.len != NULL)
        *dst.len = dst_len;
    
    dst.chars[dst_len] = '\0';
    
    return chars_to_copy == src.len ? (FXS_Error){FXS_OK} : (FXS_Error){FXS_DST_TOO_SMALL};
}

FXS_API FXS_Error fxs__mutstr_ref_append(FXS_MutStrRef dst, const FXS_StrView src)
{
    switch(dst.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_append(dst.str.dstr, src);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_append(fxs__fmutstr_ref(dst.str.strbuf), src);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_append(fxs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

FXS_API FXS_Error fxs__fmutstr_ref_delete_range(FXS__FixedMutStrRef str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
    if(end > len || begin > len)
    {
        return (FXS_Error){FXS_INDEX_OUT_OF_BOUNDS};
    }
    if(begin > end)
    {
        return (FXS_Error){FXS_BAD_RANGE};
    }
    
    unsigned int substr_len = end - begin;
    
    memmove(str.chars + begin, str.chars + begin + substr_len, len - begin - substr_len);
    
    len -= substr_len;
    
    str.chars[len] = '\0';
    
    if(str.len != NULL)
    {
        *str.len = len;
    }
    
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__mutstr_ref_delete_range(FXS_MutStrRef str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return fxs__fmutstr_ref_delete_range(fxs__fmutstr_ref(str.str.dstr), begin, end);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_delete_range(fxs__fmutstr_ref(str.str.strbuf), begin, end);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_delete_range(fxs__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    };
}

FXS_API FXS_StrViewArray fxs__strv_arr_from_carr(const FXS_StrView *carr, unsigned int nb)
{
    return (FXS_StrViewArray){
        .cap  = nb,
        .len  = nb,
        .strs = (FXS_StrView*) carr
    };
}

FXS_API FXS_Error fxs__strv_split_iter(const FXS_StrView str, const FXS_StrView delim, bool(*cb)(FXS_StrView found, void *ctx), void *ctx)
{
    if(delim.len > str.len)
    {
        return !cb(str, ctx) ? (FXS_Error){FXS_CALLBACK_EXIT} : (FXS_Error){FXS_OK};
    }
    else if(delim.len == 0)
    {
        for(unsigned int i = 0 ; i < str.len ; i++)
        {
            if(!cb(fxs__strv_strv3(str, i, i + 1), ctx))
            {
                return (FXS_Error){FXS_CALLBACK_EXIT};
            }
        }
        
        return (FXS_Error){FXS_OK};
    }
    else
    {
        unsigned int prev = 0;
        for(unsigned int i = 0 ; i <= str.len - delim.len ; )
        {
            FXS_StrView rem = fxs__strv_strv2(str, i);
            if(fxs__strv_starts_with(rem, delim))
            {
                FXS_StrView sub = fxs__strv_strv3(str, prev, i);
                if(!cb(sub, ctx))
                {
                    return (FXS_Error){FXS_CALLBACK_EXIT};
                }
                i += delim.len;
                prev = i;
            }
            else
            {
                i += 1;
            }
        }
        
        if(!cb(fxs__strv_strv3(str, prev, str.len), ctx))
        {
            return (FXS_Error){FXS_CALLBACK_EXIT};
        }
        else
        {
            return (FXS_Error){FXS_OK};
        }
    }
}

FXS_PRIVATE bool fxs__combine_views_into_array(FXS_StrView str, void *ctx)
{
    struct {
        FXS_Allocator *allocator;
        FXS_StrViewArray array;
    } *tctx = ctx;
    
    FXS_StrViewArray *array = &tctx->array;
    FXS_Allocator *allocator = tctx->allocator;
    
    if(array->cap <= array->len)
    {
        FXS_Allocation allocation = fxs_realloc(allocator, array->strs, FXS_StrView, array->cap, 2 * (array->len + 1));
        array->strs = allocation.ptr;
        array->cap = allocation.n / sizeof(FXS_StrView);
    }
    
    array->strs[array->len++] = str;
    
    return true;
}

FXS__NODISCARD("str_split returns new String_View_Array")
FXS_API FXS_StrViewArray fxs__strv_split(const FXS_StrView str, const FXS_StrView delim, FXS_Allocator *allocator)
{
    struct {
        FXS_Allocator *allocator;
        FXS_StrViewArray array;
    } ctx = {
        .allocator = allocator
    };
    
    fxs__strv_split_iter(str, delim, fxs__combine_views_into_array, &ctx);
    
    return ctx.array;
}

FXS_API FXS_Error fxs__strv_arr_join_into_dstr(FXS_DStr *dstr, const FXS_StrViewArray strs, const FXS_StrView delim)
{
    FXS_Error err = (FXS_Error){FXS_OK};
    
    if(strs.len > 0)
        err = fxs__dstr_copy(dstr, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == FXS_OK ; i++)
    {
        err = fxs__dstr_append(dstr, delim);
        err = fxs__dstr_append(dstr, strs.strs[i]);
    }
    
    return err;
}

FXS_API FXS_Error fxs__strv_arr_join_into_fmutstr_ref(FXS__FixedMutStrRef dst, const FXS_StrViewArray strs, const FXS_StrView delim)
{
    FXS_Error err = (FXS_Error){FXS_OK};
    
    if(strs.len > 0)
        err = fxs__fmutstr_ref_copy(dst, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == FXS_OK; i++)
    {
        err = fxs__fmutstr_ref_append(dst, delim);
        err = fxs__fmutstr_ref_append(dst, strs.strs[i]);
    }
    
    return err;
}

FXS_API FXS_Error fxs__strv_arr_join(FXS_MutStrRef dst, const FXS_StrViewArray strs, const FXS_StrView delim)
{
    switch(dst.ty)
    {
        case FXS__DSTR_TY     : return fxs__strv_arr_join_into_dstr(dst.str.dstr, strs, delim);
        case FXS__STRBUF_TY   : return fxs__strv_arr_join_into_fmutstr_ref(fxs__fmutstr_ref(dst.str.strbuf), strs, delim);
        case FXS__BUF_TY      : return fxs__strv_arr_join_into_fmutstr_ref(fxs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), strs, delim);
        default                : unreachable();
    };
}

FXS_API FXS_Error fxs__dstr_replace_range(FXS_DStr *dstr, unsigned int begin, unsigned int end, const FXS_StrView replacement)
{
    if(begin > dstr->len || end > dstr->len)
        return (FXS_Error){FXS_INDEX_OUT_OF_BOUNDS};
    if(begin > end)
        return (FXS_Error){FXS_BAD_RANGE};
    if(fxs__is_strv_within(fxs__strv_dstr_ptr2(dstr, 0), replacement))
        return (FXS_Error){FXS_ALIASING_NOT_SUPPORTED};
    
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
        fxs__dstr_ensure_cap(dstr, dstr->len + replacement.len - len_to_delete + 1);
        
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
    return (FXS_Error){FXS_OK};
}

FXS_PRIVATE void fxs__fmutstr_ref_replace_range_unsafe(FXS__FixedMutStrRef str, unsigned int begin, unsigned int end, const FXS_StrView replacement)
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
        unsigned int new_space = fxs__uint_min(replacement.len - len_to_delete, str.cap - *str.len - 1);
        
        // shift right
        memmove(str.chars + begin + new_space, str.chars + begin, *str.len - begin);
        // insert the replacement
        memmove(str.chars + begin, replacement.chars, fxs__uint_min(replacement.len, len_to_delete + new_space));
        
        *str.len += new_space;
        
        str.chars[*str.len] = '\0';
    }
    else
    {
        memmove(str.chars + begin, replacement.chars, replacement.len);
    }
}

FXS_PRIVATE FXS_StrView fxs__strv_fmutstr_ref2(FXS__FixedMutStrRef str, unsigned int begin);

FXS_Error fxs__fmutstr_ref_replace_range(FXS__FixedMutStrRef str, unsigned int begin, unsigned int end, const FXS_StrView replacement)
{
    if(begin >= *str.len)
        return (FXS_Error){FXS_INDEX_OUT_OF_BOUNDS};
    if(begin >= end || end > *str.len)
        return (FXS_Error){FXS_BAD_RANGE};
    if(fxs__is_strv_within(fxs__strv_fmutstr_ref2(str, 0), replacement))
        return (FXS_Error){FXS_ALIASING_NOT_SUPPORTED};
    
    FXS_Error err = (*str.len - (end - begin) + replacement.len) >= str.cap ? (FXS_Error){FXS_DST_TOO_SMALL} : (FXS_Error){FXS_OK};
    fxs__fmutstr_ref_replace_range_unsafe(str, begin, end, replacement);
    
    return err;
}

FXS_API FXS_Error fxs__mutstr_ref_replace_range(FXS_MutStrRef str, unsigned int begin, unsigned int end, const FXS_StrView replacement)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_replace_range(str.str.dstr, begin, end, replacement);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_replace_range(fxs__fmutstr_ref(str.str.strbuf), begin, end, replacement);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_replace_range(fxs__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end, replacement);
        default                : unreachable();
    };
}

FXS_API FXS_ReplaceResult fxs__fmutstr_ref_replace(FXS__FixedMutStrRef str, const FXS_StrView target, const FXS_StrView replacement)
{
    FXS_StrView as_strv = fxs__strv_fmutstr_ref2(str, 0);
    if(fxs__is_strv_within(as_strv, target) || fxs__is_strv_within(as_strv, replacement))
    {
        return (FXS_ReplaceResult){.nb_replaced = 0, .err = {FXS_ALIASING_NOT_SUPPORTED}};
    }
    
    FXS_Error err = {FXS_OK};
    unsigned int replace_count = 0;
    
    if(target.len == 0)
    {
        for(unsigned int i = 0 ; i <= *str.len && (err.ec == FXS_OK) ; i += replacement.len + 1)
        {
            err = fxs__fmutstr_ref_insert(str, replacement, i);
            replace_count += 1;
        }
        goto out;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len ; )
        {
            FXS_StrView match = fxs__strv_find(fxs__strv_fmutstr_ref2(str, i), target);
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
                    err = (FXS_Error){FXS_DST_TOO_SMALL};
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
            FXS_StrView match = fxs__strv_find(fxs__strv_fmutstr_ref2(str, i), target);
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
            FXS_StrView match = fxs__strv_find(fxs__strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                err.ec = FXS_OK;
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
    if(replace_count == 0)
        err.ec = FXS_NOT_FOUND;
    return (FXS_ReplaceResult){.nb_replaced = replace_count, .err = err};
}

FXS_API FXS_ReplaceResult fxs__dstr_replace(FXS_DStr *dstr, const FXS_StrView target, const FXS_StrView replacement)
{
    FXS_StrView as_strv = fxs__strv_dstr_ptr2(dstr, 0);
    if(fxs__is_strv_within(as_strv, target) || fxs__is_strv_within(as_strv, replacement))
    {
        return (FXS_ReplaceResult){.nb_replaced = 0, .err = {FXS_ALIASING_NOT_SUPPORTED}};
    }
    
    FXS_Error err = {FXS_OK};
    unsigned int replace_count = 0;
    
    if(target.len == 0)
    {
        err.ec = FXS_OK;
        for(unsigned int i = 0 ; i <= dstr->len && (err.ec == FXS_OK) ; i += replacement.len + 1)
        {
            err = fxs__dstr_insert(dstr, replacement, i);
            replace_count += 1;
        }
        goto out;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len; )
        {
            FXS_StrView match = fxs__strv_find(fxs__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                err = fxs__dstr_ensure_cap(dstr, dstr->len + (replacement.len - target.len) + 1);
                
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
            FXS_StrView match = fxs__strv_find(fxs__strv_dstr_ptr2(dstr, i), target);
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
            FXS_StrView match = fxs__strv_find(fxs__strv_dstr_ptr2(dstr, i), target);
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
        err.ec = FXS_NOT_FOUND;
    return (FXS_ReplaceResult){.nb_replaced = replace_count, .err = err};
}

FXS_API FXS_ReplaceResult fxs__mutstr_ref_replace(FXS_MutStrRef str, const FXS_StrView target, const FXS_StrView replacement)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_replace(str.str.dstr, target, replacement);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_replace(fxs__fmutstr_ref(str.str.strbuf), target, replacement);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_replace(fxs__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

FXS_API FXS_Error fxs__dstr_replace_first(FXS_DStr *dstr, const FXS_StrView target, const FXS_StrView replacement)
{
    FXS_Error err = {FXS_NOT_FOUND};
    
    FXS_StrView match = fxs__strv_find(fxs__strv_dstr_ptr2(dstr, 0), target);
    if(match.chars != NULL)
    {
        unsigned int begin = match.chars - dstr->chars;
        unsigned int end = begin + match.len;
        err = fxs__dstr_replace_range(dstr, begin, end, replacement);
    }
    
    return err;
}

FXS_API FXS_Error fxs__fmutstr_ref_replace_first(FXS__FixedMutStrRef str, const FXS_StrView target, const FXS_StrView replacement)
{
    FXS_Error err = {FXS_NOT_FOUND};
    
    FXS_StrView match = fxs__strv_find(fxs__strv_fmutstr_ref2(str, 0), target);
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
            
            err.ec = FXS_OK;
        }
        else
        {
            err.ec = FXS_DST_TOO_SMALL;
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    
    return err;
}

FXS_API FXS_Error fxs__mutstr_ref_replace_first(FXS_MutStrRef str, const FXS_StrView target, const FXS_StrView replacement)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_replace_first(str.str.dstr, target, replacement);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_replace_first(fxs__fmutstr_ref(str.str.strbuf), target, replacement);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_replace_first(fxs__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

FXS_API unsigned int fxs__strv_count(const FXS_StrView hay, const FXS_StrView needle)
{
    if(needle.len == 0)
        return 0;
    
    unsigned int count = 0;
    FXS_StrView found = fxs__strv_find(hay, needle);
    
    while(found.chars != NULL)
    {
        count += 1;
        found = fxs__strv_find(fxs__strv_strv2(hay, (found.chars - hay.chars) + found.len), needle);
    }
    
    return count;
}

FXS_API bool fxs__strv_starts_with(const FXS_StrView hay, const FXS_StrView needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars, needle.chars, needle.len) == 0);
}

FXS_API bool fxs__strv_ends_with(const FXS_StrView hay, const FXS_StrView needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars + hay.len - needle.len, needle.chars, needle.len) == 0);
}

FXS_API void fxs__chars_tolower(FXS_StrView str)
{
    for(unsigned int i = 0 ; i < str.len ; i++)
    {
        str.chars[i] = tolower(str.chars[i]);
    }
}

FXS_API void fxs__chars_toupper(FXS_StrView str)
{
    for(unsigned int i = 0 ; i < str.len ; i++)
    {
        str.chars[i] = toupper(str.chars[i]);
    }
}

FXS_API FXS_Error fxs__fmutstr_ref_clear(FXS__FixedMutStrRef fmutstr_ref)
{
    *fmutstr_ref.len = 0;
    if(fmutstr_ref.cap > 0)
    {
        fmutstr_ref.chars[0] = '\0';
    }
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__mutstr_ref_clear(FXS_MutStrRef str)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY:
            fxs__fmutstr_ref_clear(fxs__dstr_ptr_as_fmutstr_ref(str.str.dstr));
            break;
        case FXS__STRBUF_TY:
            fxs__fmutstr_ref_clear(fxs__strbuf_ptr_as_fmutstr_ref(str.str.strbuf));
            break;
        case FXS__BUF_TY:
            fxs__fmutstr_ref_clear(fxs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}));
            break;
    }
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_MutStrRef fxs__cstr_as_mutstr_ref(const char *str)
{
    unsigned int len = (unsigned int) strlen(str);
    
    FXS_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return fxs__buf_as_mutstr_ref(asbuf);
}

FXS_API FXS_MutStrRef fxs__ucstr_as_mutstr_ref(const unsigned char *str)
{
    unsigned int len = (unsigned int) strlen((char*) str);
    
    FXS_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return fxs__buf_as_mutstr_ref(asbuf);
}

FXS_API FXS_MutStrRef fxs__buf_as_mutstr_ref(const FXS_Buffer str)
{
    return (FXS_MutStrRef){
        .ty = FXS__BUF_TY,
        .str.buf = *(FXS_Buffer*) &str
    };
}

FXS_API FXS_MutStrRef fxs__dstr_ptr_as_mutstr_ref(const FXS_DStr *str)
{
    return (FXS_MutStrRef){
        .ty = FXS__DSTR_TY,
        .str.dstr = (FXS_DStr*) str
    };
}

FXS_API FXS_MutStrRef fxs__strbuf_ptr_as_mutstr_ref(const FXS_StrBuf *str)
{
    return (FXS_MutStrRef){
        .ty = FXS__STRBUF_TY,
        .str.strbuf = (FXS_StrBuf*) str
    };
}

FXS_API FXS_MutStrRef fxs__mutstr_ref_as_mutstr_ref(const FXS_MutStrRef str)
{
    return str;
}

FXS_API FXS_StrBuf fxs__strbuf_from_cstr(const char *ptr, unsigned int cap)
{
    unsigned int len = fxs__chars_strlen(ptr, cap);
    
    return (FXS_StrBuf){
        .cap = cap,
        .len = len,
        .chars = (unsigned char*) ptr
    };
}

FXS_API FXS_StrBuf fxs__strbuf_from_buf(const FXS_Buffer buf)
{
    FXS_StrBuf ret = {
        .cap = buf.cap,
        .len = 0,
        .chars = buf.ptr
    };
    
    if(ret.cap > 0)
        ret.chars[0] = '\0';
    
    return ret;
}

FXS_API FXS_Buffer fxs__buf_from_cstr(const char *str)
{
    return (FXS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = strlen(str) + 1
    };
}

FXS_API FXS_Buffer fxs__buf_from_ucstr(const unsigned char *str)
{
    return (FXS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = strlen((char*) str) + 1
    };
}

FXS_API FXS_Buffer fxs__buf_from_carr(const char *str, size_t cap)
{
    return (FXS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = cap
    };
}

FXS_API FXS_Buffer fxs__buf_from_ucarr(const unsigned char *str, size_t cap)
{
    return (FXS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = cap
    };
}

FXS_API FXS_StrView fxs__strv_cstr1(const char *str)
{
    return (FXS_StrView){
        .chars = (unsigned char*) str,
        .len = strlen(str)
    };
}

FXS_API FXS_StrView fxs__strv_ucstr1(const unsigned char *str)
{
    return (FXS_StrView){
        .chars = (unsigned char*) str,
        .len = strlen((char*)str)
    };
}

FXS_API FXS_StrView fxs__strv_dstr1(const FXS_DStr str)
{
    return (FXS_StrView){
        .chars = str.chars,
        .len = str.len
    };
}

FXS_API FXS_StrView fxs__strv_dstr_ptr1(const FXS_DStr *str)
{
    return (FXS_StrView){
        .chars = str->chars,
        .len = str->len
    };
}

FXS_API FXS_StrView fxs__strv_strv1(const FXS_StrView str)
{
    return str;
}

FXS_API FXS_StrView fxs__strv_strbuf1(const FXS_StrBuf str)
{
    return (FXS_StrView){
        .chars = str.chars,
        .len = str.len
    };
}

FXS_API FXS_StrView fxs__strv_strbuf_ptr1(const FXS_StrBuf *str)
{
    return (FXS_StrView){
        .chars = str->chars,
        .len = str->len
    };
}

FXS_API FXS_StrView fxs__strv_mutstr_ref1(const FXS_MutStrRef str)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return fxs__strv_dstr_ptr1(str.str.dstr);
        case FXS__STRBUF_TY   : return fxs__strv_strbuf_ptr1(str.str.strbuf);
        case FXS__BUF_TY      : return fxs__strv_ucstr1(str.str.buf.ptr);
        default                : unreachable();
    }
}

FXS_API FXS_StrView fxs__strv_cstr2(const char *str, unsigned int begin)
{
    unsigned int len = strlen(str);
    
#if !defined(FXS_NDEBUG)
    if(begin > len)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

FXS_API FXS_StrView fxs__strv_ucstr2(const unsigned char *str, unsigned int begin)
{
    unsigned int len = strlen((char*) str);
    
#if !defined(FXS_NDEBUG)
    if(begin > len)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

FXS_API FXS_StrView fxs__strv_dstr_ptr2(const FXS_DStr *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (FXS_StrView){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_dstr2(const FXS_DStr str, unsigned int begin)
{
    return fxs__strv_dstr_ptr2(&str, begin);
}

FXS_API FXS_StrView fxs__strv_strv2(const FXS_StrView str, unsigned int begin)
{
#if !defined(FXS_NDEBUG)
    if(begin > str.len)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = str.len   - begin,
        .chars = str.chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_strbuf_ptr2(const FXS_StrBuf *str, unsigned int begin)
{
#if !defined(FXS_NDEBUG)
    if(begin > str->len)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_strbuf2(const FXS_StrBuf str, unsigned int begin)
{
    return fxs__strv_strbuf_ptr2(&str, begin);
}

FXS_API FXS_StrView fxs__strv_mutstr_ref2(const FXS_MutStrRef str, unsigned int begin)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return fxs__strv_dstr_ptr2(str.str.dstr, begin);
        case FXS__STRBUF_TY   : return fxs__strv_strbuf_ptr2(str.str.strbuf, begin);
        case FXS__BUF_TY      : return fxs__strv_fmutstr_ref2(fxs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin);
        default                : unreachable();
    }
}

FXS_PRIVATE FXS_StrView fxs__strv_fmutstr_ref2(const FXS__FixedMutStrRef str, unsigned int begin)
{
    unsigned int len = *str.len;
    
#if !defined(FXS_NDEBUG)
    if(begin > len)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = len       - begin,
        .chars = str.chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_fmutstr_ref3(const FXS__FixedMutStrRef str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
#if !defined(FXS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_cstr3(const char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen(str);
    
#if !defined(FXS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

FXS_API FXS_StrView fxs__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen((char*) str);
    
#if !defined(FXS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

FXS_API FXS_StrView fxs__strv_dstr_ptr3(const FXS_DStr *str, unsigned int begin, unsigned int end)
{
#if !defined(FXS_NDEBUG)
    if(begin > str->len || end > str->len || begin > end)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_strbuf_ptr3(const FXS_StrBuf *str, unsigned int begin, unsigned int end)
{
#if !defined(FXS_NDEBUG)
    if(begin > str->len || end > str->len || begin > end)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (FXS_StrView){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_mutstr_ref3(FXS_MutStrRef str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case FXS__DSTR_TY     : return fxs__strv_dstr_ptr3(str.str.dstr, begin, end);
        case FXS__STRBUF_TY   : return fxs__strv_strbuf_ptr3(str.str.strbuf, begin, end);
        case FXS__BUF_TY      : return fxs__strv_fmutstr_ref3(fxs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    }
}

FXS_API FXS_StrView fxs__strv_dstr3(FXS_DStr str, unsigned int begin, unsigned int end)
{
    return fxs__strv_dstr_ptr3(&str, begin, end);
}

FXS_API FXS_StrView fxs__strv_strv3(FXS_StrView str, unsigned int begin, unsigned int end)
{
    if(begin > str.len || end > str.len || begin > end)
    {
        return (FXS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (FXS_StrView){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

FXS_API FXS_StrView fxs__strv_strbuf3(FXS_StrBuf str, unsigned int begin, unsigned int end)
{
    return fxs__strv_strbuf_ptr3(&str, begin, end);
}

FXS_API FXS_Error fxs__dstr_fread_line(FXS_DStr *dstr, FILE *stream)
{
    dstr->len = 0;
    if(dstr->cap > 0)
    {
        dstr->chars[0] = '\0';
    }
    
    return fxs__dstr_append_fread_line(dstr, stream);
}

FXS_API FXS_Error fxs__dstr_append_fread_line(FXS_DStr *dstr, FILE *stream)
{
    FXS_Error err = {FXS_OK};
    int c = 0;
    while(c != EOF && c != '\n')
    {
        err = fxs__dstr_maybe_grow(dstr, 64);
        if(err.ec != FXS_OK)
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
    
    return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__fmutstr_ref_fread_line(FXS__FixedMutStrRef dst, FILE *stream)
{
    if(dst.cap == 0)
    {
        return (FXS_Error){FXS_DST_TOO_SMALL};
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
        return (FXS_Error){FXS_DST_TOO_SMALL};
    else
        return (FXS_Error){FXS_OK};
}

FXS_API FXS_Error fxs__mutstr_ref_fread_line(FXS_MutStrRef dst, FILE *stream)
{
    switch(dst.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_fread_line(dst.str.dstr, stream);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_fread_line(fxs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_fread_line(fxs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

FXS_API FXS_Error fxs__fmutstr_ref_append_fread_line(FXS__FixedMutStrRef dst, FILE *stream)
{
    if(dst.cap <= *dst.len - 1)
        return (FXS_Error){FXS_DST_TOO_SMALL};
    
    unsigned int appended_len = 0;
    
    FXS__FixedMutStrRef right = {
        .cap = dst.cap - *dst.len,
        .len = &appended_len,
        .chars = dst.chars + *dst.len
    };
    
    FXS_Error err = fxs__fmutstr_ref_fread_line(right, stream);
    
    *dst.len += *right.len;
    
    dst.chars[*dst.len] = '\0';
    
    return err;
}

FXS_API FXS_Error fxs__mutstr_ref_append_fread_line(FXS_MutStrRef dst, FILE *stream)
{
    switch(dst.ty)
    {
        case FXS__DSTR_TY     : return fxs__dstr_append_fread_line(dst.str.dstr, stream);
        case FXS__STRBUF_TY   : return fxs__fmutstr_ref_append_fread_line(fxs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case FXS__BUF_TY      : return fxs__fmutstr_ref_append_fread_line(fxs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

FXS_API unsigned int fxs__fprint_strv(FILE *stream, FXS_StrView str)
{
    assert(str.chars != NULL);
    return fwrite(str.chars, sizeof(unsigned char), str.len, stream);
}

FXS_API unsigned int fxs__fprintln_strv(FILE *stream, FXS_StrView str)
{
    unsigned int written = fwrite(str.chars, sizeof(unsigned char), str.len, stream);
    int err = fputc('\n', stream);
    
    return written + (err != EOF);
}

FXS_PRIVATE unsigned int fxs__numstr_len(unsigned long long num)
{
    unsigned int len = 1;
    for(unsigned int i = 1 ; i < FXS__CARR_LEN(fxs__ten_pows_ull) && num >= fxs__ten_pows_ull[i++] ; len++);
    return len;
}

#define fxs__sinteger_min(ty) \
_Generic((ty){0},              \
signed char: SCHAR_MIN,        \
short      : SHRT_MIN,         \
int        : INT_MIN,          \
long       : LONG_MIN,         \
long long  : LLONG_MIN         \
)

#define fxs__min_tostr(ty)        \
_Generic((ty){0},                  \
signed char: fxs__schar_min_into, \
short      : fxs__short_min_into, \
int        : fxs__int_min_into,   \
long       : fxs__long_min_into,  \
long long  : fxs__llong_min_into  \
)

FXS_PRIVATE FXS_Error fxs__schar_min_into(FXS_MutStrRef dst)
{
    if(SCHAR_MIN == -128)
    {
        const char *numstr = "-128";
        FXS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return fxs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hhd", SCHAR_MIN);
        return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

FXS_PRIVATE FXS_Error fxs__short_min_into(FXS_MutStrRef dst)
{
    if(SHRT_MIN == -32768)
    {
        const char *numstr = "-32768";
        FXS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return fxs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hd", SHRT_MIN);
        return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

FXS_PRIVATE FXS_Error fxs__int_min_into(FXS_MutStrRef dst)
{
    if(INT_MIN == -2147483648)
    {
        const char *numstr = "-2147483648";
        FXS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return fxs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%d", INT_MIN);
        return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

FXS_PRIVATE FXS_Error fxs__long_min_into(FXS_MutStrRef dst)
{
    if(LONG_MIN == INT_MIN)
    {
        return fxs__int_min_into(dst);
    }
    else if(LONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        FXS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return fxs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%ld", LONG_MIN);
        return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

FXS_PRIVATE FXS_Error fxs__llong_min_into(FXS_MutStrRef dst)
{
    if(LLONG_MIN == LONG_MIN)
    {
        return fxs__long_min_into(dst);
    }
    else if(LLONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        FXS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return fxs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%lld", LLONG_MIN);
        return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

#define fxs__sintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (FXS_Error){FXS_DST_TOO_SMALL}; \
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
        err.ec = FXS_DST_TOO_SMALL; \
        chars_to_copy = fmutstr.cap - (1 + isneg); \
    } \
    num /= fxs__ten_pows[numlen - chars_to_copy]; \
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

#define fxs__sinteger_tostr_dstr(dstr) \
do { \
    err = fxs__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != FXS_OK) \
        return err; \
    \
    FXS__FixedMutStrRef as_fixed = fxs__dstr_ptr_as_fmutstr_ref(dstr); \
    fxs__sintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define fxs__sinteger_tostr() \
do { \
    /*fxs__mutstr_ref_clear(dst);*/ \
    FXS_Error err = {FXS_OK}; \
    if(obj == fxs__sinteger_min(__typeof__(obj))) \
    { \
        return fxs__min_tostr(__typeof__(obj))(dst); \
    } \
    bool isneg = false; \
    if(obj < 0) \
    { \
        isneg = true; \
        obj *= -1; \
    } \
    unsigned int numlen = fxs__numstr_len(obj); \
    switch(dst.ty) \
    { \
        case FXS__DSTR_TY: \
        { \
            fxs__sinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case FXS__STRBUF_TY: \
        { \
            FXS__FixedMutStrRef strbuf_as_fixed = fxs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            fxs__sintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case FXS__BUF_TY: \
        { \
            FXS__FixedMutStrRef buf_as_fixed = fxs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            fxs__sintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

#define fxs__uinteger_tostr_dstr(dstr) \
do { \
    err = fxs__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != FXS_OK) \
        return err; \
    \
    FXS__FixedMutStrRef as_fixed = { \
        .chars = dstr->chars, \
        .len = &dstr->len, \
        .cap = dstr->cap \
    }; \
    fxs__uintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define fxs__uintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (FXS_Error){FXS_DST_TOO_SMALL}; \
    __typeof__(obj) num = obj; \
    unsigned int chars_to_copy; \
    if(numlen < fmutstr.cap) \
    { \
        chars_to_copy = numlen; \
    } \
    else \
    { \
        err.ec = FXS_DST_TOO_SMALL; \
        chars_to_copy = fmutstr.cap - 1; \
    } \
    num /= fxs__ten_pows[numlen - chars_to_copy]; \
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

#define fxs__uinteger_tostr() \
do { \
    /*fxs__mutstr_ref_clear(dst);*/ \
    FXS_Error err = {FXS_OK}; \
    unsigned int numlen = fxs__numstr_len(obj); \
    switch(dst.ty) \
    { \
        case FXS__DSTR_TY: \
        { \
            fxs__uinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case FXS__STRBUF_TY: \
        { \
            FXS__FixedMutStrRef strbuf_as_fixed = fxs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            fxs__uintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case FXS__BUF_TY: \
        { \
            FXS__FixedMutStrRef buf_as_fixed = fxs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            fxs__uintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

FXS_API FXS_Error fxs__bool_tostr(FXS_MutStrRef dst, bool obj)
{
    FXS_StrView res = obj ? fxs__strv_cstr1("true") : fxs__strv_cstr1("false");
    return fxs__mutstr_ref_copy(dst, res);
}

FXS_API FXS_Error fxs__cstr_tostr(FXS_MutStrRef dst, const char *obj)
{
    return fxs__mutstr_ref_copy(
        dst,
        (FXS_StrView){
            .chars = (unsigned char*) obj,
            .len = strlen(obj)
        }
    );
}

FXS_API FXS_Error fxs__ucstr_tostr(FXS_MutStrRef dst, const unsigned char *obj)
{
    return fxs__mutstr_ref_copy(
        dst,
        (FXS_StrView){
            .chars = (unsigned char*) obj,
            .len = strlen((char*) obj)
        }
    );
}

FXS_API FXS_Error fxs__char_tostr(FXS_MutStrRef dst, char obj)
{
    fxs__mutstr_ref_clear(dst);
    return fxs__mutstr_ref_putc(dst, obj);
}

FXS_API FXS_Error fxs__schar_tostr(FXS_MutStrRef dst, signed char obj)
{
    return fxs__mutstr_ref_copy(dst, fxs__sc_to_string[(unsigned char)obj]);
}

FXS_API FXS_Error fxs__uchar_tostr(FXS_MutStrRef dst, unsigned char obj)
{
    fxs__mutstr_ref_clear(dst);
    return fxs__mutstr_ref_putc(dst, obj);
}

FXS_API FXS_Error fxs__short_tostr(FXS_MutStrRef dst, short obj)
{
    fxs__sinteger_tostr();
}

FXS_API FXS_Error fxs__ushort_tostr(FXS_MutStrRef dst, unsigned short obj)
{
    fxs__uinteger_tostr();
}

FXS_API FXS_Error fxs__int_tostr(FXS_MutStrRef dst, int obj)
{
    fxs__sinteger_tostr();
}

FXS_API FXS_Error fxs__uint_tostr(FXS_MutStrRef dst, unsigned int obj)
{
    fxs__uinteger_tostr();
}

FXS_API FXS_Error fxs__long_tostr(FXS_MutStrRef dst, long obj)
{
    fxs__sinteger_tostr();
}

FXS_API FXS_Error fxs__ulong_tostr(FXS_MutStrRef dst, unsigned long obj)
{
    fxs__uinteger_tostr();
}

FXS_API FXS_Error fxs__llong_tostr(FXS_MutStrRef dst, long long obj)
{
    fxs__sinteger_tostr();
}

FXS_API FXS_Error fxs__ullong_tostr(FXS_MutStrRef dst, unsigned long long obj)
{
    fxs__uinteger_tostr();
}

FXS_API FXS_Error fxs__float_tostr(FXS_MutStrRef dst, float obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return fxs__mutstr_ref_copy(
        dst,
        (FXS_StrView){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

FXS_API FXS_Error fxs__double_tostr(FXS_MutStrRef dst, double obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return fxs__mutstr_ref_copy(
        dst,
        (FXS_StrView){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

FXS_API FXS_Error fxs__error_tostr(FXS_MutStrRef dst, FXS_Error obj)
{
    return fxs__mutstr_ref_copy(dst, fxs__error_to_string[obj.ec]);
}

FXS_API FXS_Error fxs__array_fmt_tostr(FXS_MutStrRef dst, FXS_ArrayFmt obj)
{
    fxs__mutstr_ref_clear(dst);
    
    FXS_StrAppenderState appender_state;
    
    FXS_Error err = fxs__mutstr_ref_append(dst, obj.open);
    
    const uint8_t *arr = obj.array;
    
    if(obj.nb > 0)
    {
        for(size_t i = 0 ; i < obj.nb - 1 ; i++)
        {
            
            FXS_MutStrRef appender = fxs__make_appender_mutstr_ref(dst, &appender_state);
            
            err = obj.elm_tostr(appender, arr + (obj.elm_size * i));
            // TODO return if err?
            
            err = fxs__mutstr_ref_append(appender, obj.separator);
            
            fxs__mutstr_ref_commit_appender(dst, appender);
        }
        
        FXS_MutStrRef appender = fxs__make_appender_mutstr_ref(dst, &appender_state);
        err = obj.elm_tostr(appender, arr + obj.elm_size * (obj.nb - 1));
        fxs__mutstr_ref_commit_appender(dst, appender);
        
        err = fxs__mutstr_ref_append(dst, obj.trailing_separator);
    }
    
    err = fxs__mutstr_ref_append(dst, obj.close);
    
    return err;
}

FXS_API FXS_Error fxs__dstr_tostr(FXS_MutStrRef dst, const FXS_DStr obj)
{
    return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = obj.chars, .len = obj.len});
}

FXS_API FXS_Error fxs__dstr_ptr_tostr(FXS_MutStrRef dst, const FXS_DStr *obj)
{
    return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = obj->chars, .len = obj->len});
}

FXS_API FXS_Error fxs__strv_tostr(FXS_MutStrRef dst, const FXS_StrView obj)
{
    return fxs__mutstr_ref_copy(dst, obj);
}

FXS_API FXS_Error fxs__strbuf_tostr(FXS_MutStrRef dst, const FXS_StrBuf obj)
{
    return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = obj.chars, .len = obj.len});
}

FXS_API FXS_Error fxs__strbuf_ptr_tostr(FXS_MutStrRef dst, const FXS_StrBuf *obj)
{
    return fxs__mutstr_ref_copy(dst, (FXS_StrView){.chars = obj->chars, .len = obj->len});
}

FXS_API FXS_Error fxs__mutstr_ref_tostr(FXS_MutStrRef dst, const FXS_MutStrRef obj)
{
    return fxs__mutstr_ref_copy(dst, fxs__strv_mutstr_ref2(obj, 0));
}

FXS_PRIVATE FXS_Error fxs__uchar_d_tostr(FXS_MutStrRef dst, unsigned char obj)
{
    fxs__mutstr_ref_clear(dst);
    return fxs__mutstr_ref_append(dst, fxs__uc_to_string[obj]);
}

#define fxs__if_else(cond, then, else) \
_Generic((char(*)[(cond) + 1])0, char(*)[1]: else, char(*)[2]: then)

#define fxs__unsigned_of_size(sz)  \
__typeof__(_Generic((char(*)[sz])0, \
    char(*)[1]: (uint8_t) 0,        \
    char(*)[2]: (uint16_t)0,        \
    char(*)[4]: (uint32_t)0,        \
    char(*)[8]: (uint64_t)0         \
))

#define fxs__as_unsigned(n) \
((fxs__unsigned_of_size(sizeof(n))) n)

#define fxs__integer_d_Fmt_tostr(dst, num) \
return _Generic(num, \
    char: fxs__if_else(CHAR_MIN < 0, fxs__schar_tostr, fxs__uchar_d_tostr), \
    signed char: fxs__schar_tostr, \
    unsigned char: fxs__uchar_d_tostr, \
    short: fxs__short_tostr, \
    unsigned short: fxs__ushort_tostr, \
    int: fxs__int_tostr, \
    unsigned int: fxs__uint_tostr, \
    long: fxs__long_tostr, \
    unsigned long: fxs__ulong_tostr, \
    long long: fxs__llong_tostr, \
    unsigned long long: fxs__ullong_tostr \
)(dst, num)

#define fxs__integer_x_Fmt_tostr(dst, num) \
do \
{ \
    fxs__mutstr_ref_clear(dst); \
    FXS_Error err = {FXS_OK}; \
    size_t sz = sizeof(num); \
    uint8_t *num_bytes = ((uint8_t*) &num) + sizeof(num) - 1; \
    bool zero_pad = true; \
    while(sz--) \
    { \
        if(num_bytes == (uint8_t*)&num || !zero_pad || *num_bytes != 0) \
        { \
            FXS_StrView hex_sv = {.chars = (unsigned char*) fxs__byte_to_hex[*num_bytes], .len = 2}; \
            if(zero_pad && hex_sv.chars[0] == '0') \
            { \
                hex_sv.chars += 1; \
                hex_sv.len -= 1; \
            } \
            zero_pad = false; \
            err = fxs__mutstr_ref_append(dst, hex_sv); \
        } \
        num_bytes -= 1; \
    } \
    fxs__mutstr_ref_set_len(dst, fxs__mutstr_ref_len(dst)); \
    return err; \
} while(0)

#define fxs__bswap(num)                \
_Generic((char(*)[sizeof(num)])0,       \
    char(*)[1]: num,                    \
    char(*)[2]: __builtin_bswap16(num), \
    char(*)[4]: __builtin_bswap32(num), \
    char(*)[8]: __builtin_bswap64(num)  \
)

#define fxs__highest_bit(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b1) << (sizeof(n) * 8 - 1))))

#define fxs__highest_bit_as_u8(n) \
(fxs__highest_bit(n) >> ((sizeof(n) - 1) * 8))

#define fxs__highest_3bits(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b111) << (sizeof(n) * 8 - 3))))

#define fxs__highest_3bits_as_u8(n) \
(fxs__highest_3bits(n) >> ((sizeof(n) - 1) * 8))

// TODO optimize these. dont clear then append chars.
// instead, write from beginning of chars up to cap, then put the nul
#define fxs__integer_o_Fmt_tostr(dst, num) \
do \
{ \
    fxs__mutstr_ref_clear(dst); \
    fxs__unsigned_of_size(sizeof(num)) unum = num; \
    FXS_Error err = {FXS_OK}; \
    const size_t bits = (sizeof(unum) * 8); \
    int iters = bits / 3; \
    uint8_t extra_bits = 3 - ((sizeof(unum) * 8) % 3); \
    uint8_t high3 = fxs__highest_3bits_as_u8(unum); \
    uint8_t first_3bits = high3 >> extra_bits; \
    first_3bits = first_3bits >> 5; \
    bool zero_pad = true; \
    if(first_3bits != 0) \
    { \
        zero_pad = false; \
        FXS_StrView octal_sv = {.chars = &(unsigned char){'0' + first_3bits}, .len = 1}; \
        err = fxs__mutstr_ref_append(dst, octal_sv); \
    } \
    unum = unum << (3 - extra_bits); \
    \
    for(int i = 0 ; i < iters ; i++) \
    { \
        high3 = fxs__highest_3bits_as_u8(unum); \
        first_3bits = high3 >> (8 - 3); \
        if(i == (iters - 1) || !zero_pad || (first_3bits != 0)) \
        { \
            zero_pad =  false; \
            FXS_StrView octal_sv = {.chars = &(unsigned char){'0' + first_3bits}, .len = 1}; \
            err = fxs__mutstr_ref_append(dst, octal_sv); \
        } \
        unum = unum << 3; \
    } \
    fxs__mutstr_ref_set_len(dst, fxs__mutstr_ref_len(dst)); \
    return err; \
} while(0)

#define fxs__integer_b_Fmt_tostr(dst, num) \
do \
{ \
    fxs__mutstr_ref_clear(dst); \
    FXS_Error err = {FXS_OK}; \
    fxs__unsigned_of_size(sizeof(num)) unum = num; \
    size_t sz; \
    if(dst.ty == FXS__DSTR_TY) \
    { \
        sz = sizeof(unum) * 8; \
        fxs__dstr_maybe_grow(dst.str.dstr, sizeof(unum) * 8 + 1); \
    } \
    else \
    { \
        sz = fxs__mutstr_ref_cap(dst) - 1; \
    } \
    char *bytes = fxs__mutstr_ref_as_cstr(dst); \
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
    fxs__mutstr_ref_set_len(dst, written); \
    return err; \
} while(0)

#define FXS__X(ty, extra) \
FXS_API FXS_Error fxs__Integer_d_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_d_Fmt_##ty obj) \
{ \
    fxs__integer_d_Fmt_tostr(dst, obj.obj); \
} \
FXS_API FXS_Error fxs__Integer_x_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_x_Fmt_##ty obj) \
{ \
    fxs__mutstr_ref_clear(dst); \
    fxs__integer_x_Fmt_tostr(dst, obj.obj); \
} \
FXS_API FXS_Error fxs__Integer_o_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_o_Fmt_##ty obj) \
{ \
    fxs__mutstr_ref_clear(dst); \
    fxs__integer_o_Fmt_tostr(dst, obj.obj); \
} \
FXS_API FXS_Error fxs__Integer_b_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_b_Fmt_##ty obj) \
{ \
    fxs__mutstr_ref_clear(dst); \
    fxs__integer_b_Fmt_tostr(dst, obj.obj); \
} \
\
\
FXS_API FXS_Error fxs__Integer_d_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_d_Fmt_##ty *obj) \
{ \
    return fxs__Integer_d_Fmt_##ty##_tostr(dst, *obj); \
} \
FXS_API FXS_Error fxs__Integer_x_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_x_Fmt_##ty *obj) \
{ \
    return fxs__Integer_x_Fmt_##ty##_tostr(dst, *obj); \
} \
FXS_API FXS_Error fxs__Integer_o_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_o_Fmt_##ty *obj) \
{ \
    return fxs__Integer_o_Fmt_##ty##_tostr(dst, *obj); \
} \
FXS_API FXS_Error fxs__Integer_b_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_b_Fmt_##ty *obj) \
{ \
    return fxs__Integer_b_Fmt_##ty##_tostr(dst, *obj); \
}

FXS__INTEGER_TYPES(FXS__X, ignore)

#undef FXS__X

#define FXS__X(type, extra) \
FXS_API FXS_Error fxs__Floating_f_Fmt_##type##_tostr(FXS_MutStrRef dst, FXS__Floating_f_Fmt_##type obj) \
{ \
    fxs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*f", obj.precision, obj.obj); \
    if(dst.ty == FXS__DSTR_TY) \
    { \
        fxs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(fxs__mutstr_ref_as_cstr(dst), fxs__mutstr_ref_cap(dst), "%.*f", obj.precision, obj.obj); \
    if(fxs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        fxs__mutstr_ref_set_len(dst, fxs__mutstr_ref_cap(dst) - 1); \
        return (FXS_Error){FXS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        fxs__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (FXS_Error){FXS_ENCODING_ERROR}; \
    return (FXS_Error){FXS_OK}; \
} \
FXS_API FXS_Error fxs__Floating_g_Fmt_##type##_tostr(FXS_MutStrRef dst, FXS__Floating_g_Fmt_##type obj) \
{ \
    fxs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*g", obj.precision, obj.obj); \
    if(dst.ty == FXS__DSTR_TY) \
    { \
        fxs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(fxs__mutstr_ref_as_cstr(dst), fxs__mutstr_ref_cap(dst), "%.*g", obj.precision, obj.obj); \
    if(fxs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        fxs__mutstr_ref_set_len(dst, fxs__mutstr_ref_cap(dst) - 1); \
        return (FXS_Error){FXS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        fxs__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (FXS_Error){FXS_ENCODING_ERROR}; \
    return (FXS_Error){FXS_OK}; \
} \
FXS_API FXS_Error fxs__Floating_e_Fmt_##type##_tostr(FXS_MutStrRef dst, FXS__Floating_e_Fmt_##type obj) \
{ \
    fxs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*e", obj.precision, obj.obj); \
    if(dst.ty == FXS__DSTR_TY) \
    { \
        fxs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(fxs__mutstr_ref_as_cstr(dst), fxs__mutstr_ref_cap(dst), "%.*e", obj.precision, obj.obj); \
    if(fxs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        fxs__mutstr_ref_set_len(dst, fxs__mutstr_ref_cap(dst) - 1); \
        return (FXS_Error){FXS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        fxs__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (FXS_Error){FXS_ENCODING_ERROR}; \
    return (FXS_Error){FXS_OK}; \
} \
FXS_API FXS_Error fxs__Floating_a_Fmt_##type##_tostr(FXS_MutStrRef dst, FXS__Floating_a_Fmt_##type obj) \
{ \
    fxs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*a", obj.precision, obj.obj); \
    if(dst.ty == FXS__DSTR_TY) \
    { \
        fxs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(fxs__mutstr_ref_as_cstr(dst), fxs__mutstr_ref_cap(dst), "%.*a", obj.precision, obj.obj); \
    if(fxs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        fxs__mutstr_ref_set_len(dst, fxs__mutstr_ref_cap(dst) - 1); \
        return (FXS_Error){FXS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        fxs__mutstr_ref_set_len(dst, len); \
    } \
    \
    if(err < 0) \
        return (FXS_Error){FXS_ENCODING_ERROR}; \
    return (FXS_Error){FXS_OK}; \
} \
\
\
FXS_API FXS_Error fxs__Floating_f_Fmt_##type##_tostr_p(FXS_MutStrRef dst, FXS__Floating_f_Fmt_##type *obj) \
{ \
    return fxs__Floating_f_Fmt_##type##_tostr(dst, *obj); \
} \
FXS_API FXS_Error fxs__Floating_g_Fmt_##type##_tostr_p(FXS_MutStrRef dst, FXS__Floating_g_Fmt_##type *obj) \
{ \
    return fxs__Floating_g_Fmt_##type##_tostr(dst, *obj); \
} \
FXS_API FXS_Error fxs__Floating_e_Fmt_##type##_tostr_p(FXS_MutStrRef dst, FXS__Floating_e_Fmt_##type *obj) \
{ \
    return fxs__Floating_e_Fmt_##type##_tostr(dst, *obj); \
} \
FXS_API FXS_Error fxs__Floating_a_Fmt_##type##_tostr_p(FXS_MutStrRef dst, FXS__Floating_a_Fmt_##type *obj) \
{ \
    return fxs__Floating_a_Fmt_##type##_tostr(dst, *obj); \
}

FXS__FLOATING_TYPES(FXS__X, ignore, FXS__X)

#undef FXS__X

FXS_API FXS_Error fxs__bool_tostr_p(FXS_MutStrRef dst, bool *obj)
{
    return fxs__bool_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__cstr_tostr_p(FXS_MutStrRef dst, const char **obj)
{
    return fxs__cstr_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__ucstr_tostr_p(FXS_MutStrRef dst, const unsigned char **obj)
{
    return fxs__ucstr_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__char_tostr_p(FXS_MutStrRef dst, char *obj)
{
    return fxs__char_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__schar_tostr_p(FXS_MutStrRef dst, signed char *obj)
{
    return fxs__schar_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__uchar_tostr_p(FXS_MutStrRef dst, unsigned char *obj)
{
    return fxs__uchar_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__short_tostr_p(FXS_MutStrRef dst, short *obj)
{
    return fxs__short_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__ushort_tostr_p(FXS_MutStrRef dst, unsigned short *obj)
{
    return fxs__ushort_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__int_tostr_p(FXS_MutStrRef dst, int *obj)
{
    return fxs__int_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__uint_tostr_p(FXS_MutStrRef dst, unsigned int *obj)
{
    return fxs__uint_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__long_tostr_p(FXS_MutStrRef dst, long *obj)
{
    return fxs__long_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__ulong_tostr_p(FXS_MutStrRef dst, unsigned long *obj)
{
    return fxs__ulong_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__llong_tostr_p(FXS_MutStrRef dst, long long *obj)
{
    return fxs__llong_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__ullong_tostr_p(FXS_MutStrRef dst, unsigned long long *obj)
{
    return fxs__ullong_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__float_tostr_p(FXS_MutStrRef dst, float *obj)
{
    return fxs__float_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__double_tostr_p(FXS_MutStrRef dst, double *obj)
{
    return fxs__double_tostr(dst, *obj);
}

FXS_API FXS_Error fxs__dstr_tostr_p(FXS_MutStrRef dst, const FXS_DStr *obj)
{
    return fxs__dstr_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__dstr_ptr_tostr_p(FXS_MutStrRef dst, const FXS_DStr **obj)
{
    return fxs__dstr_ptr_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__strv_tostr_p(FXS_MutStrRef dst, const FXS_StrView *obj)
{
    return fxs__strv_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__strbuf_tostr_p(FXS_MutStrRef dst, const FXS_StrBuf *obj)
{
    return fxs__strbuf_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__strbuf_ptr_tostr_p(FXS_MutStrRef dst, const FXS_StrBuf **obj)
{
    return fxs__strbuf_ptr_tostr(dst, *obj);
}
FXS_API FXS_Error fxs__mutstr_ref_tostr_p(FXS_MutStrRef dst, const FXS_MutStrRef *obj)
{
    return fxs__mutstr_ref_tostr(dst, *obj);
}

FXS_API FXS_Error fxs__error_tostr_p(FXS_MutStrRef dst, FXS_Error *obj)
{
    return fxs__error_tostr(dst, *obj);
}

FXS_API FXS_Error fxs__array_fmt_tostr_p(FXS_MutStrRef dst, FXS_ArrayFmt *obj)
{
    return fxs__array_fmt_tostr(dst, *obj);
}

#endif // FXS__STR_C_INCLUDED