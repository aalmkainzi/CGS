#include <ctype.h>

#ifndef SGS_API
    // for functions exposed in the header
    #define SGS_API
#endif
#ifndef SGS_PRIVATE
    // for functions only in sgs.c
    #define SGS_PRIVATE static inline
#endif
#ifndef SGS_GLOBAL_VAR
    // for global variables in sgs.c that user code may access
    #define SGS_GLOBAL_VAR
#endif

#include "sgs.h"

#if !defined(SGS__STR_C_INCLUDED)
#define SGS__STR_C_INCLUDED

#if !defined(unreachable)
    #if defined(_MSC_VER)
        #define unreachable() __assume(0)
    #elif defined(__GNUC__)
        #define unreachable() __builtin_unreachable()
    #else
        #define unreachable()
    #endif
#endif

SGS_PRIVATE SGS_Allocation sgs__default_allocator_alloc(SGS_Allocator *ctx, size_t alignment, size_t n);
SGS_PRIVATE void sgs__default_allocator_dealloc(SGS_Allocator *ctx, void *ptr, size_t n);
SGS_PRIVATE SGS_Allocation sgs__default_allocator_realloc(SGS_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size);

static SGS_Allocator sgs__default_allocator = {
    .alloc   = sgs__default_allocator_alloc,
    .dealloc = sgs__default_allocator_dealloc,
    .realloc = sgs__default_allocator_realloc,
};

static const SGS_StrView sgs__error_to_string[] = {
    [SGS_OK]                     = {.len = sizeof("OK")                     - 1, .chars = (unsigned char*) "OK"},
    [SGS_DST_TOO_SMALL]          = {.len = sizeof("DST_TOO_SMALL")          - 1, .chars = (unsigned char*) "DST_TOO_SMALL"},
    [SGS_ALLOC_ERR]              = {.len = sizeof("ALLOC_ERR")              - 1, .chars = (unsigned char*) "ALLOC_ERR"},
    [SGS_INDEX_OUT_OF_BOUNDS]    = {.len = sizeof("INDEX_OUT_OF_BOUNDS")    - 1, .chars = (unsigned char*) "INDEX_OUT_OF_BOUNDS"},
    [SGS_BAD_RANGE]              = {.len = sizeof("BAD_RANGE")              - 1, .chars = (unsigned char*) "BAD_RANGE"},
    [SGS_NOT_FOUND]              = {.len = sizeof("NOT_FOUND")              - 1, .chars = (unsigned char*) "NOT_FOUND"},
    [SGS_ALIASING_NOT_SUPPORTED] = {.len = sizeof("ALIASING_NOT_SUPPORTED") - 1, .chars = (unsigned char*) "ALIASING_NOT_SUPPORTED"},
    [SGS_INCORRECT_TYPE]         = {.len = sizeof("INCORRECT_TYPE")         - 1, .chars = (unsigned char*) "INCORRECT_TYPE"},
    [SGS_ENCODING_ERROR]         = {.len = sizeof("ENCODING_ERROR")         - 1, .chars = (unsigned char*) "ENCODING_ERROR"},
    [SGS_CALLBACK_EXIT]          = {.len = sizeof("CALLBACK_EXIT")          - 1, .chars = (unsigned char*) "CALLBACK_EXIT"}
};

static const long long sgs__ten_pows[] = {
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

static const unsigned long long sgs__ten_pows_ull[] = {
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

static const SGS_StrView sgs__uc_to_string[256] = {
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

static const SGS_StrView sgs__sc_to_string[] = {
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

static const char sgs__byte_to_hex[][2] = 
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

SGS_GLOBAL_VAR _Thread_local SGS_DStr sgs__fprint_tostr_dynamic_buffer = {
    .allocator = &sgs__default_allocator
};

SGS_API SGS__FixedMutStrRef sgs__buf_as_fmutstr_ref(SGS_Buffer buf, unsigned int *len_ptr)
{
    *len_ptr = strlen((char*) buf.ptr);
    SGS__FixedMutStrRef ret = {
        .chars = buf.ptr,
        .cap = buf.cap,
        .len = len_ptr
    };
    return ret;
}

SGS_API SGS__FixedMutStrRef sgs__strbuf_ptr_as_fmutstr_ref(SGS_StrBuf *strbuf)
{
    SGS__FixedMutStrRef ret = {
        .chars = strbuf->chars,
        .cap = strbuf->cap,
        .len = &strbuf->len
    };
    return ret;
}

SGS_API SGS__FixedMutStrRef sgs__dstr_ptr_as_fmutstr_ref(SGS_DStr *dstr)
{
    SGS__FixedMutStrRef ret = {
        .chars = dstr->chars,
        .cap = dstr->cap,
        .len = &dstr->len
    };
    return ret;
}

SGS_PRIVATE SGS_Allocation sgs__default_allocator_alloc(SGS_Allocator *ctx, size_t alignment, size_t n)
{
    (void) alignment;
    (void) ctx;
    void *mem = malloc(n);
    return (SGS_Allocation){
        .ptr = mem,
        .n = n
    };
}

SGS_PRIVATE void sgs__default_allocator_dealloc(SGS_Allocator *ctx, void *ptr, size_t n)
{
    (void) ctx;
    (void) n;
    free(ptr);
}

SGS_PRIVATE SGS_Allocation sgs__default_allocator_realloc(SGS_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) ctx;
    (void) alignment;
    (void) old_size;
    void *mem = realloc(ptr, new_size);
    return (SGS_Allocation){
        .ptr = mem,
        .n = new_size
    };
}

SGS_PRIVATE SGS_Allocation sgs__dstr_append_allocator_alloc(SGS_Allocator *allocator, size_t alignment, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) alignment;
    (void) n;
    return (SGS_Allocation){0};
}

SGS_PRIVATE void sgs__dstr_append_allocator_dealloc(SGS_Allocator *allocator, void *ptr, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) ptr;
    (void) n;
}

SGS_PRIVATE SGS_Allocation sgs__dstr_append_allocator_realloc(SGS_Allocator *allocator, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) alignment;
    
    SGS__DStrAppendAllocator *dstr_append_allocator = (__typeof__(dstr_append_allocator)) allocator;
    
    SGS_DStr *owner = dstr_append_allocator->owner;
    
    assert(old_size == owner->cap - owner->len);
    assert(((unsigned char*)ptr - owner->chars) == owner->len);
    
    sgs_dstr_ensure_cap(owner, owner->cap + (new_size - old_size));
    return (SGS_Allocation){
        .ptr = owner->chars + owner->len,
        .n = owner->cap - owner->len
    };
}

SGS_API SGS_Allocation sgs__allocator_invoke_alloc(SGS_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb)
{
    return allocator->alloc(allocator, alignment, nb * obj_size);
}

SGS_API void sgs__allocator_invoke_dealloc(SGS_Allocator *allocator, void *ptr, size_t obj_size, size_t nb)
{
    allocator->dealloc(allocator, ptr, nb * obj_size);
}

SGS_API SGS_Allocation sgs__allocator_invoke_realloc(SGS_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb)
{
    return allocator->realloc(allocator, ptr, alignment, old_nb * obj_size, new_nb * obj_size);
}

SGS_API SGS_Allocator *sgs_get_default_allocator()
{
    return &sgs__default_allocator;
}

SGS_PRIVATE void sgs__make_dstr_append_allocator(SGS_DStr *dstr, SGS__DStrAppendAllocator *out)
{
    *out = (SGS__DStrAppendAllocator){
        .base = {
            .alloc   = sgs__dstr_append_allocator_alloc,
            .dealloc = sgs__dstr_append_allocator_dealloc,
            .realloc = sgs__dstr_append_allocator_realloc,
        },
        .owner = dstr
    };
}

SGS_PRIVATE SGS_DStr sgs__make_appender_dstr(SGS_DStr *owner, SGS__DStrAppendAllocator *allocator)
{
    sgs__make_dstr_append_allocator(owner, allocator);
    return (SGS_DStr){
        .allocator = (void*) allocator,
        .cap = owner->cap - owner->len,
        .len = 0,
        .chars = owner->chars + owner->len
    };
}

SGS_PRIVATE SGS_StrBuf sgs__make_appender_strbuf(SGS_MutStrRef owner)
{
    return (SGS_StrBuf){
        .cap = sgs__mutstr_ref_cap(owner) - sgs__mutstr_ref_len(owner),
        .len = 0,
        .chars = (unsigned char*) sgs__mutstr_ref_as_cstr(owner) + sgs__mutstr_ref_len(owner)
    };
}

SGS_API SGS_MutStrRef sgs__make_appender_mutstr_ref(SGS_MutStrRef owner, SGS_StrAppenderState *state)
{
    switch(owner.ty)
    {
        case SGS__DSTR_TY    :
            state->appender_dstr = sgs__make_appender_dstr(owner.str.dstr, &state->dstr_append_allocator);
            return sgs__dstr_ptr_as_mutstr_ref(&state->appender_dstr);
        case SGS__STRBUF_TY  :
        case SGS__BUF_TY     :
            ;
            SGS_MutStrRef ret = {.ty = SGS__STRBUF_TY};
            ret.str.strbuf = &state->appender_buf;
            *ret.str.strbuf = sgs__make_appender_strbuf(owner);
            return ret;
        default               :
            unreachable();
    }
}

SGS_PRIVATE unsigned int sgs__uint_min(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

SGS_PRIVATE unsigned int sgs__uint_max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

SGS_PRIVATE unsigned int sgs__chars_strlen(const char *chars, unsigned int cap)
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

SGS_API bool sgs__is_strv_within(SGS_StrView base, SGS_StrView sub)
{
    uintptr_t begin = (uintptr_t) base.chars;
    uintptr_t end = (uintptr_t) (base.chars + base.len);
    uintptr_t sub_begin = (uintptr_t) sub.chars;
    return sub_begin >= begin && sub_begin < end;
}

SGS__NODISCARD("discarding a new DString may cause memory leak")
SGS_API SGS_DStr sgs__dstr_init(unsigned int cap, SGS_Allocator *allocator)
{
    SGS_DStr ret = { 0 };
    
    ret.allocator = allocator;
    
    SGS_Allocation allocation = sgs_alloc(allocator, unsigned char, cap);
    ret.chars = allocation.ptr;
    ret.cap = allocation.n;
    
    if(ret.chars != NULL)
    {
        ret.chars[0] = '\0';
    }
    
    return ret;
}

SGS_API SGS_DStr sgs__dstr_init_from(const SGS_StrView str, SGS_Allocator *allocator)
{
    SGS_DStr ret = sgs__dstr_init(str.len + 1, allocator);
    
    sgs__dstr_copy(&ret, str);
    
    return ret;
}

SGS_API void sgs__dstr_deinit(SGS_DStr *dstr)
{
    sgs_dealloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap);
    dstr->cap = 0;
    dstr->len = 0;
    dstr->chars = NULL;
}

SGS_API SGS_Error sgs__dstr_shrink_to_fit(SGS_DStr *dstr)
{
    SGS_Allocation allocation = sgs_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, dstr->len + 1);
    if(allocation.ptr == NULL)
    {
        return (SGS_Error){SGS_ALLOC_ERR};
    }
    else
    {
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        return (SGS_Error){SGS_OK};
    }
}

SGS_PRIVATE SGS_Error sgs__dstr_maybe_grow(SGS_DStr *dstr, unsigned int len_to_append)
{
    return sgs__dstr_ensure_cap(dstr, dstr->len + len_to_append + 1);
}

SGS_API SGS_Error sgs__dstr_append(SGS_DStr *dstr, const SGS_StrView src)
{
    SGS_StrView to_append = src;
    SGS_Error err = (SGS_Error){SGS_OK};
    if(sgs__is_strv_within(sgs__strv_dstr_ptr2(dstr, 0), to_append))
    {
        unsigned int begin_idx = to_append.chars - dstr->chars;
        err = sgs__dstr_maybe_grow(dstr, to_append.len + 1);
        to_append = (SGS_StrView){
            .len   = to_append.len,
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = sgs__dstr_maybe_grow(dstr, to_append.len);
    }
    
    if(err.ec == SGS_OK)
    {
        memmove(dstr->chars + dstr->len, to_append.chars, to_append.len * sizeof(unsigned char));
        
        dstr->len += to_append.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

SGS_API SGS_Error sgs__dstr_prepend_strv(SGS_DStr *dstr, const SGS_StrView src)
{
    SGS_StrView to_prepend = src;
    SGS_Error err = (SGS_Error){SGS_OK};
    
    if(sgs__is_strv_within(sgs__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        err = sgs__dstr_maybe_grow(dstr, src.len);
        to_prepend = (SGS_StrView){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = sgs__dstr_maybe_grow(dstr, to_prepend.len);
    }
    
    if(err.ec == SGS_OK)
    {
        memmove(dstr->chars + to_prepend.len, dstr->chars, dstr->len);
        memmove(dstr->chars, to_prepend.chars, to_prepend.len);
        
        dstr->len += to_prepend.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

SGS_API SGS_Error sgs__dstr_insert(SGS_DStr *dstr, const SGS_StrView src, unsigned int idx)
{
    if(idx > dstr->len)
    {
        return (SGS_Error){SGS_INDEX_OUT_OF_BOUNDS};
    }
    
    SGS_StrView to_insert = src;
    
    if(sgs__is_strv_within(sgs__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        sgs__dstr_maybe_grow(dstr, src.len);
        to_insert = (SGS_StrView){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        sgs__dstr_maybe_grow(dstr, to_insert.len);
    }
    
    memmove(dstr->chars + idx + to_insert.len, dstr->chars + idx, dstr->len - idx);
    memmove(dstr->chars + idx, to_insert.chars, to_insert.len);
    
    dstr->len += to_insert.len;
    dstr->chars[dstr->len] = '\0';
    
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__dstr_ensure_cap(SGS_DStr *dstr, unsigned int at_least)
{
    if(dstr->cap < at_least)
    {
        unsigned char *save = dstr->chars;
        size_t new_cap = sgs__uint_max(at_least, dstr->cap * 2);
        SGS_Allocation allocation = sgs_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, new_cap);
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        
        if(dstr->chars == NULL)
        {
            dstr->chars = save;
            return (SGS_Error){SGS_ALLOC_ERR};
        }
        if(dstr->cap < new_cap)
        {
            return (SGS_Error){SGS_ALLOC_ERR};
        }
    }
    
    return (SGS_Error){SGS_OK};
}

SGS_API char *sgs__cstr_as_cstr(const char *str)
{
    return (char*) str;
}

SGS_API char *sgs__ucstr_as_cstr(const unsigned char *str)
{
    return (char*) str;
}

SGS_API char *sgs__dstr_as_cstr(const SGS_DStr str)
{
    return (char*) str.chars;
}

SGS_API char *sgs__dstr_ptr_as_cstr(const SGS_DStr *str)
{
    return (char*) str->chars;
}

SGS_API char *sgs__strv_as_cstr(const SGS_StrView str)
{
    return (char*) str.chars;
}

SGS_API char *sgs__strbuf_as_cstr(const SGS_StrBuf str)
{
    return (char*) str.chars;
}

SGS_API char *sgs__strbuf_ptr_as_cstr(const SGS_StrBuf *str)
{
    return (char*) str->chars;
}

SGS_API char *sgs__mutstr_ref_as_cstr(const SGS_MutStrRef str)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return (char*) str.str.dstr->chars;
        case SGS__STRBUF_TY   : return (char*) str.str.strbuf->chars;
        case SGS__BUF_TY      : return (char*) str.str.buf.ptr;
        default                : unreachable();
    };
}

SGS_API unsigned char sgs__cstr_char_at(const char *str, unsigned int idx)
{
    return str[idx];
}

SGS_API unsigned char sgs__ucstr_char_at(const unsigned char *str, unsigned int idx)
{
    return str[idx];
}

SGS_API unsigned char sgs__dstr_char_at(const SGS_DStr str, unsigned int idx)
{
    return str.chars[idx];
}

SGS_API unsigned char sgs__dstr_ptr_char_at(const SGS_DStr *str, unsigned int idx)
{
    return str->chars[idx];
}

SGS_API unsigned char sgs__strv_char_at(const SGS_StrView str, unsigned int idx)
{
    return str.chars[idx];
}

SGS_API unsigned char sgs__strbuf_char_at(const SGS_StrBuf str, unsigned int idx)
{
    return str.chars[idx];
}

SGS_API unsigned char sgs__strbuf_ptr_char_at(const SGS_StrBuf *str, unsigned int idx)
{
    return str->chars[idx];
}

SGS_API unsigned char sgs__mutstr_ref_char_at(const SGS_MutStrRef str, unsigned int idx)
{
    return sgs__mutstr_ref_as_cstr(str)[idx];
}

SGS_API SGS_Error sgs__mutstr_ref_set_len(SGS_MutStrRef str, unsigned int new_len)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     :
            str.str.dstr->len = new_len;
            str.str.dstr->chars[new_len] = '\0';
            assert(str.str.dstr->cap >= str.str.dstr->len);
            break;
        case SGS__STRBUF_TY   :
            str.str.strbuf->len = new_len;
            str.str.strbuf->chars[new_len] = '\0';
            assert(str.str.strbuf->cap >= str.str.strbuf->len);
            break;
        case SGS__BUF_TY      :
            str.str.buf.ptr[new_len] = '\0';
            break;
        default                :
            unreachable();
    };
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__mutstr_ref_commit_appender(SGS_MutStrRef owner, SGS_MutStrRef appender)
{
    return sgs__mutstr_ref_set_len(
        owner,
        sgs__mutstr_ref_len(owner) + sgs__mutstr_ref_len(appender) \
    );
}

SGS_API unsigned int sgs__dstr_cap(const SGS_DStr str)
{
    return str.cap;
}

SGS_API unsigned int sgs__dstr_ptr_cap(const SGS_DStr *str)
{
    return str->cap;
}

SGS_API unsigned int sgs__strbuf_cap(const SGS_StrBuf str)
{
    return str.cap;
}

SGS_API unsigned int sgs__strbuf_ptr_cap(const SGS_StrBuf *str)
{
    return str->cap;
}

SGS_API unsigned int sgs__buf_cap(const SGS_Buffer buf)
{
    return buf.cap;
}

SGS_API unsigned int sgs__mutstr_ref_cap(const SGS_MutStrRef str)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return str.str.dstr->cap;
        case SGS__STRBUF_TY   : return str.str.strbuf->cap;
        case SGS__BUF_TY      : return str.str.buf.cap;
        default                : unreachable();
    };
}

SGS_API unsigned int sgs__mutstr_ref_len(const SGS_MutStrRef str)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return str.str.dstr->len;
        case SGS__STRBUF_TY   : return str.str.strbuf->len;
        case SGS__BUF_TY      : return strlen((char*) str.str.buf.ptr);
        default                : unreachable();
    };
}

SGS_API SGS_Error sgs__fmutstr_ref_insert(SGS__FixedMutStrRef dst, const SGS_StrView src, unsigned int idx)
{
    unsigned int len = *dst.len;
    if(idx > len)
    {
        return (SGS_Error){SGS_INDEX_OUT_OF_BOUNDS};
    }
    
    unsigned int nb_chars_to_insert = sgs__uint_min(dst.cap - len - 1, src.len);
    
    // shift right
    memmove(dst.chars + idx + nb_chars_to_insert, dst.chars + idx, len - idx);
    
    // insert the src
    memmove(dst.chars + idx, src.chars, nb_chars_to_insert);
    
    len += nb_chars_to_insert;
    
    *dst.len = len;
    
    return nb_chars_to_insert == src.len ? (SGS_Error){SGS_OK} : (SGS_Error){SGS_DST_TOO_SMALL};
}

SGS_API SGS_Error sgs__mutstr_ref_insert(SGS_MutStrRef dst, const SGS_StrView src, unsigned int idx)
{
    switch(dst.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_insert(dst.str.dstr, src, idx);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_insert(sgs__fmutstr_ref(dst.str.strbuf), src, idx);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_insert(sgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src, idx);
        default                : unreachable();
    };
}

SGS_API bool sgs__strv_equal(const SGS_StrView str1, const SGS_StrView str2)
{
    return
    (str1.len == str2.len) &&
    (memcmp(str1.chars, str2.chars, str1.len) == 0);
}

SGS_API SGS_StrView sgs__strv_find(const SGS_StrView hay, const SGS_StrView needle)
{
    if(hay.chars == NULL || needle.chars == NULL || needle.len > hay.len)
        return (SGS_StrView){.chars = NULL, .len = 0};
    if(needle.len == 0)
        return (SGS_StrView){.chars = hay.chars, .len = 0};
    
    unsigned char *max_possible_ptr = &hay.chars[hay.len] - needle.len;
    unsigned char *first_char = hay.chars;
    unsigned int remaining_len = hay.len;
    
    while(first_char && first_char <= max_possible_ptr)
    {
        if(memcmp(first_char, needle.chars, needle.len) == 0)
            return (SGS_StrView){.chars = first_char, .len = needle.len};
        first_char = memchr(first_char + 1, needle.chars[0], remaining_len - 1);
        remaining_len = hay.len - (first_char - hay.chars);
    }
    
    return (SGS_StrView){.chars = NULL, .len = 0};
}

SGS_API SGS_Error sgs__fmutstr_ref_copy(SGS__FixedMutStrRef dst, const SGS_StrView src)
{
    unsigned int chars_to_copy = sgs__uint_min(src.len, dst.cap - 1);
    
    memmove(dst.chars, src.chars, chars_to_copy * sizeof(unsigned char));
    dst.chars[chars_to_copy] = '\0';
    
    *dst.len = chars_to_copy;
    
    return chars_to_copy == src.len ? (SGS_Error){SGS_OK} : (SGS_Error){SGS_DST_TOO_SMALL};
}

SGS_API SGS_Error sgs__dstr_copy(SGS_DStr *dstr, SGS_StrView src)
{
    SGS_Error err = sgs__dstr_ensure_cap(dstr, src.len + 1);
    
    if(err.ec == SGS_OK)
    {
        memmove(dstr->chars, src.chars, src.len * sizeof(unsigned char));
        
        dstr->len = src.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

SGS_API SGS_Error sgs__mutstr_ref_copy(SGS_MutStrRef dst, const SGS_StrView src)
{
    switch(dst.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_copy(dst.str.dstr, src);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_copy(sgs__fmutstr_ref(dst.str.strbuf), src);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_copy(sgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

SGS_API SGS_Error sgs__dstr_putc(SGS_DStr *dst, unsigned char c)
{
    SGS_Error err = sgs__dstr_ensure_cap(dst, dst->len + 2);
    if(err.ec != SGS_OK)
        return err;
    
    dst->chars[dst->len] = c;
    dst->chars[dst->len + 1] = '\0';
    dst->len += 1;
    
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__fmutstr_ref_putc(SGS__FixedMutStrRef dst, unsigned char c)
{
    if(dst.cap - *dst.len <= 1)
    {
        return (SGS_Error){SGS_DST_TOO_SMALL};
    }
    
    dst.chars[*dst.len] = c;
    dst.chars[*dst.len + 1] = '\0';
    *dst.len += 1;
    
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__mutstr_ref_putc(SGS_MutStrRef dst, unsigned char c)
{
    switch(dst.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_putc(dst.str.dstr, c);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_putc(sgs__fmutstr_ref(dst.str.strbuf), c);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_putc(sgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), c);
        default                : unreachable();
    }
}

SGS_API SGS_Error sgs__fmutstr_ref_append(SGS__FixedMutStrRef dst, const SGS_StrView src)
{
    unsigned int dst_len = *dst.len;
    
    unsigned int chars_to_copy = sgs__uint_min(src.len, dst.cap - dst_len - 1);
    memmove(dst.chars + dst_len, src.chars, chars_to_copy);
    
    dst_len += chars_to_copy;
    
    if(dst.len != NULL)
        *dst.len = dst_len;
    
    dst.chars[dst_len] = '\0';
    
    return chars_to_copy == src.len ? (SGS_Error){SGS_OK} : (SGS_Error){SGS_DST_TOO_SMALL};
}

SGS_API SGS_Error sgs__mutstr_ref_append(SGS_MutStrRef dst, const SGS_StrView src)
{
    switch(dst.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_append(dst.str.dstr, src);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_append(sgs__fmutstr_ref(dst.str.strbuf), src);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_append(sgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), src);
        default                : unreachable();
    };
}

SGS_API SGS_Error sgs__fmutstr_ref_delete_range(SGS__FixedMutStrRef str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
    if(end > len || begin > len)
    {
        return (SGS_Error){SGS_INDEX_OUT_OF_BOUNDS};
    }
    if(begin > end)
    {
        return (SGS_Error){SGS_BAD_RANGE};
    }
    
    unsigned int substr_len = end - begin;
    
    memmove(str.chars + begin, str.chars + begin + substr_len, len - begin - substr_len);
    
    len -= substr_len;
    
    str.chars[len] = '\0';
    
    if(str.len != NULL)
    {
        *str.len = len;
    }
    
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__mutstr_ref_delete_range(SGS_MutStrRef str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return sgs__fmutstr_ref_delete_range(sgs__fmutstr_ref(str.str.dstr), begin, end);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_delete_range(sgs__fmutstr_ref(str.str.strbuf), begin, end);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_delete_range(sgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    };
}

SGS_API SGS_StrViewArray sgs__strv_arr_from_carr(const SGS_StrView *carr, unsigned int nb)
{
    return (SGS_StrViewArray){
        .cap  = nb,
        .len  = nb,
        .strs = (SGS_StrView*) carr
    };
}

SGS_API SGS_Error sgs__strv_split_iter(const SGS_StrView str, const SGS_StrView delim, bool(*cb)(SGS_StrView found, void *ctx), void *ctx)
{
    if(delim.len > str.len)
    {
        return !cb(str, ctx) ? (SGS_Error){SGS_CALLBACK_EXIT} : (SGS_Error){SGS_OK};
    }
    else if(delim.len == 0)
    {
        for(unsigned int i = 0 ; i < str.len ; i++)
        {
            if(!cb(sgs__strv_strv3(str, i, i + 1), ctx))
            {
                return (SGS_Error){SGS_CALLBACK_EXIT};
            }
        }
        
        return (SGS_Error){SGS_OK};
    }
    else
    {
        unsigned int prev = 0;
        for(unsigned int i = 0 ; i <= str.len - delim.len ; )
        {
            SGS_StrView rem = sgs__strv_strv2(str, i);
            if(sgs__strv_starts_with(rem, delim))
            {
                SGS_StrView sub = sgs__strv_strv3(str, prev, i);
                if(!cb(sub, ctx))
                {
                    return (SGS_Error){SGS_CALLBACK_EXIT};
                }
                i += delim.len;
                prev = i;
            }
            else
            {
                i += 1;
            }
        }
        
        if(!cb(sgs__strv_strv3(str, prev, str.len), ctx))
        {
            return (SGS_Error){SGS_CALLBACK_EXIT};
        }
        else
        {
            return (SGS_Error){SGS_OK};
        }
    }
}

SGS_PRIVATE bool sgs__combine_views_into_array(SGS_StrView str, void *ctx)
{
    struct {
        SGS_Allocator *allocator;
        SGS_StrViewArray array;
    } *tctx = ctx;
    
    SGS_StrViewArray *array = &tctx->array;
    SGS_Allocator *allocator = tctx->allocator;
    
    if(array->cap <= array->len)
    {
        SGS_Allocation allocation = sgs_realloc(allocator, array->strs, SGS_StrView, array->cap, 2 * (array->len + 1));
        array->strs = allocation.ptr;
        array->cap = allocation.n / sizeof(SGS_StrView);
    }
    
    array->strs[array->len++] = str;
    
    return true;
}

SGS__NODISCARD("str_split returns new String_View_Array")
SGS_API SGS_StrViewArray sgs__strv_split(const SGS_StrView str, const SGS_StrView delim, SGS_Allocator *allocator)
{
    struct {
        SGS_Allocator *allocator;
        SGS_StrViewArray array;
    } ctx = {
        .allocator = allocator
    };
    
    sgs__strv_split_iter(str, delim, sgs__combine_views_into_array, &ctx);
    
    return ctx.array;
}

SGS_API SGS_Error sgs__strv_arr_join_into_dstr(SGS_DStr *dstr, const SGS_StrViewArray strs, const SGS_StrView delim)
{
    SGS_Error err = (SGS_Error){SGS_OK};
    
    if(strs.len > 0)
        err = sgs__dstr_copy(dstr, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == SGS_OK ; i++)
    {
        err = sgs__dstr_append(dstr, delim);
        err = sgs__dstr_append(dstr, strs.strs[i]);
    }
    
    return err;
}

SGS_API SGS_Error sgs__strv_arr_join_into_fmutstr_ref(SGS__FixedMutStrRef dst, const SGS_StrViewArray strs, const SGS_StrView delim)
{
    SGS_Error err = (SGS_Error){SGS_OK};
    
    if(strs.len > 0)
        err = sgs__fmutstr_ref_copy(dst, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err.ec == SGS_OK; i++)
    {
        err = sgs__fmutstr_ref_append(dst, delim);
        err = sgs__fmutstr_ref_append(dst, strs.strs[i]);
    }
    
    return err;
}

SGS_API SGS_Error sgs__strv_arr_join(SGS_MutStrRef dst, const SGS_StrViewArray strs, const SGS_StrView delim)
{
    switch(dst.ty)
    {
        case SGS__DSTR_TY     : return sgs__strv_arr_join_into_dstr(dst.str.dstr, strs, delim);
        case SGS__STRBUF_TY   : return sgs__strv_arr_join_into_fmutstr_ref(sgs__fmutstr_ref(dst.str.strbuf), strs, delim);
        case SGS__BUF_TY      : return sgs__strv_arr_join_into_fmutstr_ref(sgs__fmutstr_ref(dst.str.buf, &(unsigned int){0}), strs, delim);
        default                : unreachable();
    };
}

SGS_API SGS_Error sgs__dstr_replace_range(SGS_DStr *dstr, unsigned int begin, unsigned int end, const SGS_StrView replacement)
{
    if(begin > dstr->len || end > dstr->len)
        return (SGS_Error){SGS_INDEX_OUT_OF_BOUNDS};
    if(begin > end)
        return (SGS_Error){SGS_BAD_RANGE};
    if(sgs__is_strv_within(sgs__strv_dstr_ptr2(dstr, 0), replacement))
        return (SGS_Error){SGS_ALIASING_NOT_SUPPORTED};
    
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
        sgs__dstr_ensure_cap(dstr, dstr->len + replacement.len - len_to_delete + 1);
        
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
    return (SGS_Error){SGS_OK};
}

SGS_PRIVATE void sgs__fmutstr_ref_replace_range_unsafe(SGS__FixedMutStrRef str, unsigned int begin, unsigned int end, const SGS_StrView replacement)
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
        unsigned int new_space = sgs__uint_min(replacement.len - len_to_delete, str.cap - *str.len - 1);
        
        // shift right
        memmove(str.chars + begin + new_space, str.chars + begin, *str.len - begin);
        // insert the replacement
        memmove(str.chars + begin, replacement.chars, sgs__uint_min(replacement.len, len_to_delete + new_space));
        
        *str.len += new_space;
        
        str.chars[*str.len] = '\0';
    }
    else
    {
        memmove(str.chars + begin, replacement.chars, replacement.len);
    }
}

SGS_PRIVATE SGS_StrView sgs__strv_fmutstr_ref2(SGS__FixedMutStrRef str, unsigned int begin);

SGS_Error sgs__fmutstr_ref_replace_range(SGS__FixedMutStrRef str, unsigned int begin, unsigned int end, const SGS_StrView replacement)
{
    if(begin >= *str.len)
        return (SGS_Error){SGS_INDEX_OUT_OF_BOUNDS};
    if(begin >= end || end > *str.len)
        return (SGS_Error){SGS_BAD_RANGE};
    if(sgs__is_strv_within(sgs__strv_fmutstr_ref2(str, 0), replacement))
        return (SGS_Error){SGS_ALIASING_NOT_SUPPORTED};
    
    SGS_Error err = (*str.len - (end - begin) + replacement.len) >= str.cap ? (SGS_Error){SGS_DST_TOO_SMALL} : (SGS_Error){SGS_OK};
    sgs__fmutstr_ref_replace_range_unsafe(str, begin, end, replacement);
    
    return err;
}

SGS_API SGS_Error sgs__mutstr_ref_replace_range(SGS_MutStrRef str, unsigned int begin, unsigned int end, const SGS_StrView replacement)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_replace_range(str.str.dstr, begin, end, replacement);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_replace_range(sgs__fmutstr_ref(str.str.strbuf), begin, end, replacement);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_replace_range(sgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end, replacement);
        default                : unreachable();
    };
}

SGS_API SGS_ReplaceResult sgs__fmutstr_ref_replace(SGS__FixedMutStrRef str, const SGS_StrView target, const SGS_StrView replacement)
{
    SGS_StrView as_strv = sgs__strv_fmutstr_ref2(str, 0);
    if(sgs__is_strv_within(as_strv, target) || sgs__is_strv_within(as_strv, replacement))
    {
        return (SGS_ReplaceResult){.nb_replaced = 0, .err = {SGS_ALIASING_NOT_SUPPORTED}};
    }
    
    SGS_Error err = {SGS_OK};
    unsigned int replace_count = 0;
    
    if(target.len == 0)
    {
        for(unsigned int i = 0 ; i <= *str.len && (err.ec == SGS_OK) ; i += replacement.len + 1)
        {
            err = sgs__fmutstr_ref_insert(str, replacement, i);
            replace_count += 1;
        }
        goto out;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len ; )
        {
            SGS_StrView match = sgs__strv_find(sgs__strv_fmutstr_ref2(str, i), target);
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
                    err = (SGS_Error){SGS_DST_TOO_SMALL};
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
            SGS_StrView match = sgs__strv_find(sgs__strv_fmutstr_ref2(str, i), target);
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
            SGS_StrView match = sgs__strv_find(sgs__strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                err.ec = SGS_OK;
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
        err.ec = SGS_NOT_FOUND;
    return (SGS_ReplaceResult){.nb_replaced = replace_count, .err = err};
}

SGS_API SGS_ReplaceResult sgs__dstr_replace(SGS_DStr *dstr, const SGS_StrView target, const SGS_StrView replacement)
{
    SGS_StrView as_strv = sgs__strv_dstr_ptr2(dstr, 0);
    if(sgs__is_strv_within(as_strv, target) || sgs__is_strv_within(as_strv, replacement))
    {
        return (SGS_ReplaceResult){.nb_replaced = 0, .err = {SGS_ALIASING_NOT_SUPPORTED}};
    }
    
    SGS_Error err = {SGS_OK};
    unsigned int replace_count = 0;
    
    if(target.len == 0)
    {
        err.ec = SGS_OK;
        for(unsigned int i = 0 ; i <= dstr->len && (err.ec == SGS_OK) ; i += replacement.len + 1)
        {
            err = sgs__dstr_insert(dstr, replacement, i);
            replace_count += 1;
        }
        goto out;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len; )
        {
            SGS_StrView match = sgs__strv_find(sgs__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                err = sgs__dstr_ensure_cap(dstr, dstr->len + (replacement.len - target.len) + 1);
                
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
            SGS_StrView match = sgs__strv_find(sgs__strv_dstr_ptr2(dstr, i), target);
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
            SGS_StrView match = sgs__strv_find(sgs__strv_dstr_ptr2(dstr, i), target);
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
        err.ec = SGS_NOT_FOUND;
    return (SGS_ReplaceResult){.nb_replaced = replace_count, .err = err};
}

SGS_API SGS_ReplaceResult sgs__mutstr_ref_replace(SGS_MutStrRef str, const SGS_StrView target, const SGS_StrView replacement)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_replace(str.str.dstr, target, replacement);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_replace(sgs__fmutstr_ref(str.str.strbuf), target, replacement);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_replace(sgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

SGS_API SGS_Error sgs__dstr_replace_first(SGS_DStr *dstr, const SGS_StrView target, const SGS_StrView replacement)
{
    SGS_Error err = {SGS_NOT_FOUND};
    
    SGS_StrView match = sgs__strv_find(sgs__strv_dstr_ptr2(dstr, 0), target);
    if(match.chars != NULL)
    {
        unsigned int begin = match.chars - dstr->chars;
        unsigned int end = begin + match.len;
        err = sgs__dstr_replace_range(dstr, begin, end, replacement);
    }
    
    return err;
}

SGS_API SGS_Error sgs__fmutstr_ref_replace_first(SGS__FixedMutStrRef str, const SGS_StrView target, const SGS_StrView replacement)
{
    SGS_Error err = {SGS_NOT_FOUND};
    
    SGS_StrView match = sgs__strv_find(sgs__strv_fmutstr_ref2(str, 0), target);
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
            
            err.ec = SGS_OK;
        }
        else
        {
            err.ec = SGS_DST_TOO_SMALL;
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    
    return err;
}

SGS_API SGS_Error sgs__mutstr_ref_replace_first(SGS_MutStrRef str, const SGS_StrView target, const SGS_StrView replacement)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_replace_first(str.str.dstr, target, replacement);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_replace_first(sgs__fmutstr_ref(str.str.strbuf), target, replacement);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_replace_first(sgs__fmutstr_ref(str.str.buf, &(unsigned int){0}), target, replacement);
        default                : unreachable();
    };
}

SGS_API unsigned int sgs__strv_count(const SGS_StrView hay, const SGS_StrView needle)
{
    if(needle.len == 0)
        return 0;
    
    unsigned int count = 0;
    SGS_StrView found = sgs__strv_find(hay, needle);
    
    while(found.chars != NULL)
    {
        count += 1;
        found = sgs__strv_find(sgs__strv_strv2(hay, (found.chars - hay.chars) + found.len), needle);
    }
    
    return count;
}

SGS_API bool sgs__strv_starts_with(const SGS_StrView hay, const SGS_StrView needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars, needle.chars, needle.len) == 0);
}

SGS_API bool sgs__strv_ends_with(const SGS_StrView hay, const SGS_StrView needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars + hay.len - needle.len, needle.chars, needle.len) == 0);
}

SGS_API void sgs__chars_tolower(SGS_StrView str)
{
    for(unsigned int i = 0 ; i < str.len ; i++)
    {
        str.chars[i] = tolower(str.chars[i]);
    }
}

SGS_API void sgs__chars_toupper(SGS_StrView str)
{
    for(unsigned int i = 0 ; i < str.len ; i++)
    {
        str.chars[i] = toupper(str.chars[i]);
    }
}

SGS_API SGS_Error sgs__fmutstr_ref_clear(SGS__FixedMutStrRef fmutstr_ref)
{
    *fmutstr_ref.len = 0;
    if(fmutstr_ref.cap > 0)
    {
        fmutstr_ref.chars[0] = '\0';
    }
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__mutstr_ref_clear(SGS_MutStrRef str)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY:
            sgs__fmutstr_ref_clear(sgs__dstr_ptr_as_fmutstr_ref(str.str.dstr));
            break;
        case SGS__STRBUF_TY:
            sgs__fmutstr_ref_clear(sgs__strbuf_ptr_as_fmutstr_ref(str.str.strbuf));
            break;
        case SGS__BUF_TY:
            sgs__fmutstr_ref_clear(sgs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}));
            break;
    }
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_MutStrRef sgs__cstr_as_mutstr_ref(const char *str)
{
    unsigned int len = (unsigned int) strlen(str);
    
    SGS_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return sgs__buf_as_mutstr_ref(asbuf);
}

SGS_API SGS_MutStrRef sgs__ucstr_as_mutstr_ref(const unsigned char *str)
{
    unsigned int len = (unsigned int) strlen((char*) str);
    
    SGS_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return sgs__buf_as_mutstr_ref(asbuf);
}

SGS_API SGS_MutStrRef sgs__buf_as_mutstr_ref(const SGS_Buffer str)
{
    return (SGS_MutStrRef){
        .ty = SGS__BUF_TY,
        .str.buf = *(SGS_Buffer*) &str
    };
}

SGS_API SGS_MutStrRef sgs__dstr_ptr_as_mutstr_ref(const SGS_DStr *str)
{
    return (SGS_MutStrRef){
        .ty = SGS__DSTR_TY,
        .str.dstr = (SGS_DStr*) str
    };
}

SGS_API SGS_MutStrRef sgs__strbuf_ptr_as_mutstr_ref(const SGS_StrBuf *str)
{
    return (SGS_MutStrRef){
        .ty = SGS__STRBUF_TY,
        .str.strbuf = (SGS_StrBuf*) str
    };
}

SGS_API SGS_MutStrRef sgs__mutstr_ref_as_mutstr_ref(const SGS_MutStrRef str)
{
    return str;
}

SGS_API SGS_StrBuf sgs__strbuf_from_cstr(const char *ptr, unsigned int cap)
{
    unsigned int len = sgs__chars_strlen(ptr, cap);
    
    return (SGS_StrBuf){
        .cap = cap,
        .len = len,
        .chars = (unsigned char*) ptr
    };
}

SGS_API SGS_StrBuf sgs__strbuf_from_buf(const SGS_Buffer buf)
{
    SGS_StrBuf ret = {
        .cap = buf.cap,
        .len = 0,
        .chars = buf.ptr
    };
    
    if(ret.cap > 0)
        ret.chars[0] = '\0';
    
    return ret;
}

SGS_API SGS_Buffer sgs__buf_from_cstr(const char *str)
{
    return (SGS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = strlen(str) + 1
    };
}

SGS_API SGS_Buffer sgs__buf_from_ucstr(const unsigned char *str)
{
    return (SGS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = strlen((char*) str) + 1
    };
}

SGS_API SGS_Buffer sgs__buf_from_carr(const char *str, size_t cap)
{
    return (SGS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = cap
    };
}

SGS_API SGS_Buffer sgs__buf_from_ucarr(const unsigned char *str, size_t cap)
{
    return (SGS_Buffer){
        .ptr = (unsigned char*) str,
        .cap = cap
    };
}

SGS_API SGS_StrView sgs__strv_cstr1(const char *str)
{
    return (SGS_StrView){
        .chars = (unsigned char*) str,
        .len = strlen(str)
    };
}

SGS_API SGS_StrView sgs__strv_ucstr1(const unsigned char *str)
{
    return (SGS_StrView){
        .chars = (unsigned char*) str,
        .len = strlen((char*)str)
    };
}

SGS_API SGS_StrView sgs__strv_dstr1(const SGS_DStr str)
{
    return (SGS_StrView){
        .chars = str.chars,
        .len = str.len
    };
}

SGS_API SGS_StrView sgs__strv_dstr_ptr1(const SGS_DStr *str)
{
    return (SGS_StrView){
        .chars = str->chars,
        .len = str->len
    };
}

SGS_API SGS_StrView sgs__strv_strv1(const SGS_StrView str)
{
    return str;
}

SGS_API SGS_StrView sgs__strv_strbuf1(const SGS_StrBuf str)
{
    return (SGS_StrView){
        .chars = str.chars,
        .len = str.len
    };
}

SGS_API SGS_StrView sgs__strv_strbuf_ptr1(const SGS_StrBuf *str)
{
    return (SGS_StrView){
        .chars = str->chars,
        .len = str->len
    };
}

SGS_API SGS_StrView sgs__strv_mutstr_ref1(const SGS_MutStrRef str)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return sgs__strv_dstr_ptr1(str.str.dstr);
        case SGS__STRBUF_TY   : return sgs__strv_strbuf_ptr1(str.str.strbuf);
        case SGS__BUF_TY      : return sgs__strv_ucstr1(str.str.buf.ptr);
        default                : unreachable();
    }
}

SGS_API SGS_StrView sgs__strv_cstr2(const char *str, unsigned int begin)
{
    unsigned int len = strlen(str);
    
#if !defined(SGS_NDEBUG)
    if(begin > len)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

SGS_API SGS_StrView sgs__strv_ucstr2(const unsigned char *str, unsigned int begin)
{
    unsigned int len = strlen((char*) str);
    
#if !defined(SGS_NDEBUG)
    if(begin > len)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

SGS_API SGS_StrView sgs__strv_dstr_ptr2(const SGS_DStr *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (SGS_StrView){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_dstr2(const SGS_DStr str, unsigned int begin)
{
    return sgs__strv_dstr_ptr2(&str, begin);
}

SGS_API SGS_StrView sgs__strv_strv2(const SGS_StrView str, unsigned int begin)
{
#if !defined(SGS_NDEBUG)
    if(begin > str.len)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = str.len   - begin,
        .chars = str.chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_strbuf_ptr2(const SGS_StrBuf *str, unsigned int begin)
{
#if !defined(SGS_NDEBUG)
    if(begin > str->len)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_strbuf2(const SGS_StrBuf str, unsigned int begin)
{
    return sgs__strv_strbuf_ptr2(&str, begin);
}

SGS_API SGS_StrView sgs__strv_mutstr_ref2(const SGS_MutStrRef str, unsigned int begin)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return sgs__strv_dstr_ptr2(str.str.dstr, begin);
        case SGS__STRBUF_TY   : return sgs__strv_strbuf_ptr2(str.str.strbuf, begin);
        case SGS__BUF_TY      : return sgs__strv_fmutstr_ref2(sgs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin);
        default                : unreachable();
    }
}

SGS_PRIVATE SGS_StrView sgs__strv_fmutstr_ref2(const SGS__FixedMutStrRef str, unsigned int begin)
{
    unsigned int len = *str.len;
    
#if !defined(SGS_NDEBUG)
    if(begin > len)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = len       - begin,
        .chars = str.chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_fmutstr_ref3(const SGS__FixedMutStrRef str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
#if !defined(SGS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_cstr3(const char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen(str);
    
#if !defined(SGS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

SGS_API SGS_StrView sgs__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen((char*) str);
    
#if !defined(SGS_NDEBUG)
    if(begin > len || end > len || begin > end)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

SGS_API SGS_StrView sgs__strv_dstr_ptr3(const SGS_DStr *str, unsigned int begin, unsigned int end)
{
#if !defined(SGS_NDEBUG)
    if(begin > str->len || end > str->len || begin > end)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_strbuf_ptr3(const SGS_StrBuf *str, unsigned int begin, unsigned int end)
{
#if !defined(SGS_NDEBUG)
    if(begin > str->len || end > str->len || begin > end)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
#endif
    
    return (SGS_StrView){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_mutstr_ref3(SGS_MutStrRef str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case SGS__DSTR_TY     : return sgs__strv_dstr_ptr3(str.str.dstr, begin, end);
        case SGS__STRBUF_TY   : return sgs__strv_strbuf_ptr3(str.str.strbuf, begin, end);
        case SGS__BUF_TY      : return sgs__strv_fmutstr_ref3(sgs__buf_as_fmutstr_ref(str.str.buf, &(unsigned int){0}), begin, end);
        default                : unreachable();
    }
}

SGS_API SGS_StrView sgs__strv_dstr3(SGS_DStr str, unsigned int begin, unsigned int end)
{
    return sgs__strv_dstr_ptr3(&str, begin, end);
}

SGS_API SGS_StrView sgs__strv_strv3(SGS_StrView str, unsigned int begin, unsigned int end)
{
    if(begin > str.len || end > str.len || begin > end)
    {
        return (SGS_StrView){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (SGS_StrView){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

SGS_API SGS_StrView sgs__strv_strbuf3(SGS_StrBuf str, unsigned int begin, unsigned int end)
{
    return sgs__strv_strbuf_ptr3(&str, begin, end);
}

SGS_API SGS_Error sgs__dstr_fread_line(SGS_DStr *dstr, FILE *stream)
{
    dstr->len = 0;
    if(dstr->cap > 0)
    {
        dstr->chars[0] = '\0';
    }
    
    return sgs__dstr_append_fread_line(dstr, stream);
}

SGS_API SGS_Error sgs__dstr_append_fread_line(SGS_DStr *dstr, FILE *stream)
{
    SGS_Error err = {SGS_OK};
    int c = 0;
    while(c != EOF && c != '\n')
    {
        err = sgs__dstr_maybe_grow(dstr, 64);
        if(err.ec != SGS_OK)
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
    
    return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__fmutstr_ref_fread_line(SGS__FixedMutStrRef dst, FILE *stream)
{
    if(dst.cap == 0)
    {
        return (SGS_Error){SGS_DST_TOO_SMALL};
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
        return (SGS_Error){SGS_DST_TOO_SMALL};
    else
        return (SGS_Error){SGS_OK};
}

SGS_API SGS_Error sgs__mutstr_ref_fread_line(SGS_MutStrRef dst, FILE *stream)
{
    switch(dst.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_fread_line(dst.str.dstr, stream);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_fread_line(sgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_fread_line(sgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

SGS_API SGS_Error sgs__fmutstr_ref_append_fread_line(SGS__FixedMutStrRef dst, FILE *stream)
{
    if(dst.cap <= *dst.len - 1)
        return (SGS_Error){SGS_DST_TOO_SMALL};
    
    unsigned int appended_len = 0;
    
    SGS__FixedMutStrRef right = {
        .cap = dst.cap - *dst.len,
        .len = &appended_len,
        .chars = dst.chars + *dst.len
    };
    
    SGS_Error err = sgs__fmutstr_ref_fread_line(right, stream);
    
    *dst.len += *right.len;
    
    dst.chars[*dst.len] = '\0';
    
    return err;
}

SGS_API SGS_Error sgs__mutstr_ref_append_fread_line(SGS_MutStrRef dst, FILE *stream)
{
    switch(dst.ty)
    {
        case SGS__DSTR_TY     : return sgs__dstr_append_fread_line(dst.str.dstr, stream);
        case SGS__STRBUF_TY   : return sgs__fmutstr_ref_append_fread_line(sgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf), stream);
        case SGS__BUF_TY      : return sgs__fmutstr_ref_append_fread_line(sgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}), stream);
        default                : unreachable();
    };
}

SGS_API unsigned int sgs__fprint_strv(FILE *stream, SGS_StrView str)
{
    assert(str.chars != NULL);
    return fwrite(str.chars, sizeof(unsigned char), str.len, stream);
}

SGS_API unsigned int sgs__fprintln_strv(FILE *stream, SGS_StrView str)
{
    unsigned int written = fwrite(str.chars, sizeof(unsigned char), str.len, stream);
    int err = fputc('\n', stream);
    
    return written + (err != EOF);
}

SGS_PRIVATE unsigned int sgs__numstr_len(unsigned long long num)
{
    unsigned int len = 1;
    for(unsigned int i = 1 ; i < SGS__CARR_LEN(sgs__ten_pows_ull) && num >= sgs__ten_pows_ull[i++] ; len++);
    return len;
}

#define sgs__sinteger_min(ty) \
_Generic((ty){0},              \
signed char: SCHAR_MIN,        \
short      : SHRT_MIN,         \
int        : INT_MIN,          \
long       : LONG_MIN,         \
long long  : LLONG_MIN         \
)

#define sgs__min_tostr(ty)        \
_Generic((ty){0},                  \
signed char: sgs__schar_min_into, \
short      : sgs__short_min_into, \
int        : sgs__int_min_into,   \
long       : sgs__long_min_into,  \
long long  : sgs__llong_min_into  \
)

SGS_PRIVATE SGS_Error sgs__schar_min_into(SGS_MutStrRef dst)
{
    if(SCHAR_MIN == -128)
    {
        const char *numstr = "-128";
        SGS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return sgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hhd", SCHAR_MIN);
        return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

SGS_PRIVATE SGS_Error sgs__short_min_into(SGS_MutStrRef dst)
{
    if(SHRT_MIN == -32768)
    {
        const char *numstr = "-32768";
        SGS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return sgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hd", SHRT_MIN);
        return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

SGS_PRIVATE SGS_Error sgs__int_min_into(SGS_MutStrRef dst)
{
    if(INT_MIN == -2147483648)
    {
        const char *numstr = "-2147483648";
        SGS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return sgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%d", INT_MIN);
        return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

SGS_PRIVATE SGS_Error sgs__long_min_into(SGS_MutStrRef dst)
{
    if(LONG_MIN == INT_MIN)
    {
        return sgs__int_min_into(dst);
    }
    else if(LONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        SGS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return sgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%ld", LONG_MIN);
        return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

SGS_PRIVATE SGS_Error sgs__llong_min_into(SGS_MutStrRef dst)
{
    if(LLONG_MIN == LONG_MIN)
    {
        return sgs__long_min_into(dst);
    }
    else if(LLONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        SGS_StrView s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return sgs__mutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%lld", LLONG_MIN);
        return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = (unsigned char*) temp, .len = len});
    }
}

#define sgs__sintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (SGS_Error){SGS_DST_TOO_SMALL}; \
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
        err.ec = SGS_DST_TOO_SMALL; \
        chars_to_copy = fmutstr.cap - (1 + isneg); \
    } \
    num /= sgs__ten_pows[numlen - chars_to_copy]; \
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

#define sgs__sinteger_tostr_dstr(dstr) \
do { \
    err = sgs__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != SGS_OK) \
        return err; \
    \
    SGS__FixedMutStrRef as_fixed = sgs__dstr_ptr_as_fmutstr_ref(dstr); \
    sgs__sintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define sgs__sinteger_tostr() \
do { \
    /*sgs__mutstr_ref_clear(dst);*/ \
    SGS_Error err = {SGS_OK}; \
    if(obj == sgs__sinteger_min(__typeof__(obj))) \
    { \
        return sgs__min_tostr(__typeof__(obj))(dst); \
    } \
    bool isneg = false; \
    if(obj < 0) \
    { \
        isneg = true; \
        obj *= -1; \
    } \
    unsigned int numlen = sgs__numstr_len(obj); \
    switch(dst.ty) \
    { \
        case SGS__DSTR_TY: \
        { \
            sgs__sinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case SGS__STRBUF_TY: \
        { \
            SGS__FixedMutStrRef strbuf_as_fixed = sgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            sgs__sintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case SGS__BUF_TY: \
        { \
            SGS__FixedMutStrRef buf_as_fixed = sgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            sgs__sintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

#define sgs__uinteger_tostr_dstr(dstr) \
do { \
    err = sgs__dstr_ensure_cap(dstr, numlen + 1); \
    if(err.ec != SGS_OK) \
        return err; \
    \
    SGS__FixedMutStrRef as_fixed = { \
        .chars = dstr->chars, \
        .len = &dstr->len, \
        .cap = dstr->cap \
    }; \
    sgs__uintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define sgs__uintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return (SGS_Error){SGS_DST_TOO_SMALL}; \
    __typeof__(obj) num = obj; \
    unsigned int chars_to_copy; \
    if(numlen < fmutstr.cap) \
    { \
        chars_to_copy = numlen; \
    } \
    else \
    { \
        err.ec = SGS_DST_TOO_SMALL; \
        chars_to_copy = fmutstr.cap - 1; \
    } \
    num /= sgs__ten_pows[numlen - chars_to_copy]; \
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

#define sgs__uinteger_tostr() \
do { \
    /*sgs__mutstr_ref_clear(dst);*/ \
    SGS_Error err = {SGS_OK}; \
    unsigned int numlen = sgs__numstr_len(obj); \
    switch(dst.ty) \
    { \
        case SGS__DSTR_TY: \
        { \
            sgs__uinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case SGS__STRBUF_TY: \
        { \
            SGS__FixedMutStrRef strbuf_as_fixed = sgs__strbuf_ptr_as_fmutstr_ref(dst.str.strbuf); \
            sgs__uintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case SGS__BUF_TY: \
        { \
            SGS__FixedMutStrRef buf_as_fixed = sgs__buf_as_fmutstr_ref(dst.str.buf, &(unsigned int){0}); \
            sgs__uintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

SGS_API SGS_Error sgs__bool_tostr(SGS_MutStrRef dst, bool obj)
{
    SGS_StrView res = obj ? sgs__strv_cstr1("true") : sgs__strv_cstr1("false");
    return sgs__mutstr_ref_copy(dst, res);
}

SGS_API SGS_Error sgs__cstr_tostr(SGS_MutStrRef dst, const char *obj)
{
    return sgs__mutstr_ref_copy(
        dst,
        (SGS_StrView){
            .chars = (unsigned char*) obj,
            .len = strlen(obj)
        }
    );
}

SGS_API SGS_Error sgs__ucstr_tostr(SGS_MutStrRef dst, const unsigned char *obj)
{
    return sgs__mutstr_ref_copy(
        dst,
        (SGS_StrView){
            .chars = (unsigned char*) obj,
            .len = strlen((char*) obj)
        }
    );
}

SGS_API SGS_Error sgs__char_tostr(SGS_MutStrRef dst, char obj)
{
    sgs__mutstr_ref_clear(dst);
    return sgs__mutstr_ref_putc(dst, obj);
}

SGS_API SGS_Error sgs__schar_tostr(SGS_MutStrRef dst, signed char obj)
{
    return sgs__mutstr_ref_copy(dst, sgs__sc_to_string[(unsigned char)obj]);
}

SGS_API SGS_Error sgs__uchar_tostr(SGS_MutStrRef dst, unsigned char obj)
{
    sgs__mutstr_ref_clear(dst);
    return sgs__mutstr_ref_putc(dst, obj);
}

SGS_API SGS_Error sgs__short_tostr(SGS_MutStrRef dst, short obj)
{
    sgs__sinteger_tostr();
}

SGS_API SGS_Error sgs__ushort_tostr(SGS_MutStrRef dst, unsigned short obj)
{
    sgs__uinteger_tostr();
}

SGS_API SGS_Error sgs__int_tostr(SGS_MutStrRef dst, int obj)
{
    sgs__sinteger_tostr();
}

SGS_API SGS_Error sgs__uint_tostr(SGS_MutStrRef dst, unsigned int obj)
{
    sgs__uinteger_tostr();
}

SGS_API SGS_Error sgs__long_tostr(SGS_MutStrRef dst, long obj)
{
    sgs__sinteger_tostr();
}

SGS_API SGS_Error sgs__ulong_tostr(SGS_MutStrRef dst, unsigned long obj)
{
    sgs__uinteger_tostr();
}

SGS_API SGS_Error sgs__llong_tostr(SGS_MutStrRef dst, long long obj)
{
    sgs__sinteger_tostr();
}

SGS_API SGS_Error sgs__ullong_tostr(SGS_MutStrRef dst, unsigned long long obj)
{
    sgs__uinteger_tostr();
}

SGS_API SGS_Error sgs__float_tostr(SGS_MutStrRef dst, float obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return sgs__mutstr_ref_copy(
        dst,
        (SGS_StrView){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

SGS_API SGS_Error sgs__double_tostr(SGS_MutStrRef dst, double obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return sgs__mutstr_ref_copy(
        dst,
        (SGS_StrView){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

SGS_API SGS_Error sgs__error_tostr(SGS_MutStrRef dst, SGS_Error obj)
{
    return sgs__mutstr_ref_copy(dst, sgs__error_to_string[obj.ec]);
}

SGS_API SGS_Error sgs__array_fmt_tostr(SGS_MutStrRef dst, SGS_ArrayFmt obj)
{
    sgs__mutstr_ref_clear(dst);
    
    SGS_StrAppenderState appender_state;
    
    SGS_Error err = sgs__mutstr_ref_append(dst, obj.open);
    
    const uint8_t *arr = obj.array;
    
    if(obj.nb > 0)
    {
        for(size_t i = 0 ; i < obj.nb - 1 ; i++)
        {
            
            SGS_MutStrRef appender = sgs__make_appender_mutstr_ref(dst, &appender_state);
            
            err = obj.elm_tostr(appender, arr + (obj.elm_size * i));
            // TODO return if err?
            
            err = sgs__mutstr_ref_append(appender, obj.separator);
            
            sgs__mutstr_ref_commit_appender(dst, appender);
        }
        
        SGS_MutStrRef appender = sgs__make_appender_mutstr_ref(dst, &appender_state);
        err = obj.elm_tostr(appender, arr + obj.elm_size * (obj.nb - 1));
        sgs__mutstr_ref_commit_appender(dst, appender);
        
        err = sgs__mutstr_ref_append(dst, obj.trailing_separator);
    }
    
    err = sgs__mutstr_ref_append(dst, obj.close);
    
    return err;
}

SGS_API SGS_Error sgs__dstr_tostr(SGS_MutStrRef dst, const SGS_DStr obj)
{
    return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = obj.chars, .len = obj.len});
}

SGS_API SGS_Error sgs__dstr_ptr_tostr(SGS_MutStrRef dst, const SGS_DStr *obj)
{
    return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = obj->chars, .len = obj->len});
}

SGS_API SGS_Error sgs__strv_tostr(SGS_MutStrRef dst, const SGS_StrView obj)
{
    return sgs__mutstr_ref_copy(dst, obj);
}

SGS_API SGS_Error sgs__strbuf_tostr(SGS_MutStrRef dst, const SGS_StrBuf obj)
{
    return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = obj.chars, .len = obj.len});
}

SGS_API SGS_Error sgs__strbuf_ptr_tostr(SGS_MutStrRef dst, const SGS_StrBuf *obj)
{
    return sgs__mutstr_ref_copy(dst, (SGS_StrView){.chars = obj->chars, .len = obj->len});
}

SGS_API SGS_Error sgs__mutstr_ref_tostr(SGS_MutStrRef dst, const SGS_MutStrRef obj)
{
    return sgs__mutstr_ref_copy(dst, sgs__strv_mutstr_ref2(obj, 0));
}

SGS_PRIVATE SGS_Error sgs__uchar_d_tostr(SGS_MutStrRef dst, unsigned char obj)
{
    sgs__mutstr_ref_clear(dst);
    return sgs__mutstr_ref_append(dst, sgs__uc_to_string[obj]);
}

#define sgs__if_else(cond, then, else) \
_Generic((char(*)[(cond) + 1])0, char(*)[1]: else, char(*)[2]: then)

#define sgs__unsigned_of_size(sz)  \
__typeof__(_Generic((char(*)[sz])0, \
    char(*)[1]: (uint8_t) 0,        \
    char(*)[2]: (uint16_t)0,        \
    char(*)[4]: (uint32_t)0,        \
    char(*)[8]: (uint64_t)0         \
))

#define sgs__as_unsigned(n) \
((sgs__unsigned_of_size(sizeof(n))) n)

#define sgs__integer_d_Fmt_tostr(dst, num) \
return _Generic(num, \
    char: sgs__if_else(CHAR_MIN < 0, sgs__schar_tostr, sgs__uchar_d_tostr), \
    signed char: sgs__schar_tostr, \
    unsigned char: sgs__uchar_d_tostr, \
    short: sgs__short_tostr, \
    unsigned short: sgs__ushort_tostr, \
    int: sgs__int_tostr, \
    unsigned int: sgs__uint_tostr, \
    long: sgs__long_tostr, \
    unsigned long: sgs__ulong_tostr, \
    long long: sgs__llong_tostr, \
    unsigned long long: sgs__ullong_tostr \
)(dst, num)

#define sgs__integer_x_Fmt_tostr(dst, num) \
do \
{ \
    sgs__mutstr_ref_clear(dst); \
    SGS_Error err = {SGS_OK}; \
    size_t sz = sizeof(num); \
    uint8_t *num_bytes = ((uint8_t*) &num) + sizeof(num) - 1; \
    bool zero_pad = true; \
    while(sz--) \
    { \
        if(num_bytes == (uint8_t*)&num || !zero_pad || *num_bytes != 0) \
        { \
            SGS_StrView hex_sv = {.chars = (unsigned char*) sgs__byte_to_hex[*num_bytes], .len = 2}; \
            if(zero_pad && hex_sv.chars[0] == '0') \
            { \
                hex_sv.chars += 1; \
                hex_sv.len -= 1; \
            } \
            zero_pad = false; \
            err = sgs__mutstr_ref_append(dst, hex_sv); \
        } \
        num_bytes -= 1; \
    } \
    sgs__mutstr_ref_set_len(dst, sgs__mutstr_ref_len(dst)); \
    return err; \
} while(0)

#define sgs__bswap(num)                \
_Generic((char(*)[sizeof(num)])0,       \
    char(*)[1]: num,                    \
    char(*)[2]: __builtin_bswap16(num), \
    char(*)[4]: __builtin_bswap32(num), \
    char(*)[8]: __builtin_bswap64(num)  \
)

#define sgs__highest_bit(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b1) << (sizeof(n) * 8 - 1))))

#define sgs__highest_bit_as_u8(n) \
(sgs__highest_bit(n) >> ((sizeof(n) - 1) * 8))

#define sgs__highest_3bits(n) \
((__typeof__(n))((n) & (((__typeof__(n)) 0b111) << (sizeof(n) * 8 - 3))))

#define sgs__highest_3bits_as_u8(n) \
(sgs__highest_3bits(n) >> ((sizeof(n) - 1) * 8))

// TODO optimize these. dont clear then append chars.
// instead, write from beginning of chars up to cap, then put the nul
#define sgs__integer_o_Fmt_tostr(dst, num) \
do \
{ \
    sgs__mutstr_ref_clear(dst); \
    sgs__unsigned_of_size(sizeof(num)) unum = num; \
    SGS_Error err = {SGS_OK}; \
    const size_t bits = (sizeof(unum) * 8); \
    int iters = bits / 3; \
    uint8_t extra_bits = 3 - ((sizeof(unum) * 8) % 3); \
    uint8_t high3 = sgs__highest_3bits_as_u8(unum); \
    uint8_t first_3bits = high3 >> extra_bits; \
    first_3bits = first_3bits >> 5; \
    bool zero_pad = true; \
    if(first_3bits != 0) \
    { \
        zero_pad = false; \
        SGS_StrView octal_sv = {.chars = &(unsigned char){'0' + first_3bits}, .len = 1}; \
        err = sgs__mutstr_ref_append(dst, octal_sv); \
    } \
    unum = unum << (3 - extra_bits); \
    \
    for(int i = 0 ; i < iters ; i++) \
    { \
        high3 = sgs__highest_3bits_as_u8(unum); \
        first_3bits = high3 >> (8 - 3); \
        if(i == (iters - 1) || !zero_pad || (first_3bits != 0)) \
        { \
            zero_pad =  false; \
            SGS_StrView octal_sv = {.chars = &(unsigned char){'0' + first_3bits}, .len = 1}; \
            err = sgs__mutstr_ref_append(dst, octal_sv); \
        } \
        unum = unum << 3; \
    } \
    sgs__mutstr_ref_set_len(dst, sgs__mutstr_ref_len(dst)); \
    return err; \
} while(0)

#define sgs__integer_b_Fmt_tostr(dst, num) \
do \
{ \
    sgs__mutstr_ref_clear(dst); \
    SGS_Error err = {SGS_OK}; \
    sgs__unsigned_of_size(sizeof(num)) unum = num; \
    size_t sz; \
    if(dst.ty == SGS__DSTR_TY) \
    { \
        sz = sizeof(unum) * 8; \
        sgs__dstr_maybe_grow(dst.str.dstr, sizeof(unum) * 8 + 1); \
    } \
    else \
    { \
        sz = sgs__mutstr_ref_cap(dst) - 1; \
    } \
    char *bytes = sgs__mutstr_ref_as_cstr(dst); \
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
    sgs__mutstr_ref_set_len(dst, written); \
    return err; \
} while(0)

#define SGS__X(ty, extra) \
SGS_API SGS_Error sgs__Integer_d_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_d_Fmt_##ty obj) \
{ \
    sgs__integer_d_Fmt_tostr(dst, obj.obj); \
} \
SGS_API SGS_Error sgs__Integer_x_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_x_Fmt_##ty obj) \
{ \
    sgs__mutstr_ref_clear(dst); \
    sgs__integer_x_Fmt_tostr(dst, obj.obj); \
} \
SGS_API SGS_Error sgs__Integer_o_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_o_Fmt_##ty obj) \
{ \
    sgs__mutstr_ref_clear(dst); \
    sgs__integer_o_Fmt_tostr(dst, obj.obj); \
} \
SGS_API SGS_Error sgs__Integer_b_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_b_Fmt_##ty obj) \
{ \
    sgs__mutstr_ref_clear(dst); \
    sgs__integer_b_Fmt_tostr(dst, obj.obj); \
} \
\
\
SGS_API SGS_Error sgs__Integer_d_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_d_Fmt_##ty *obj) \
{ \
    return sgs__Integer_d_Fmt_##ty##_tostr(dst, *obj); \
} \
SGS_API SGS_Error sgs__Integer_x_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_x_Fmt_##ty *obj) \
{ \
    return sgs__Integer_x_Fmt_##ty##_tostr(dst, *obj); \
} \
SGS_API SGS_Error sgs__Integer_o_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_o_Fmt_##ty *obj) \
{ \
    return sgs__Integer_o_Fmt_##ty##_tostr(dst, *obj); \
} \
SGS_API SGS_Error sgs__Integer_b_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_b_Fmt_##ty *obj) \
{ \
    return sgs__Integer_b_Fmt_##ty##_tostr(dst, *obj); \
}

SGS__INTEGER_TYPES(SGS__X, ignore)

#undef SGS__X

#define SGS__X(type, extra) \
SGS_API SGS_Error sgs__Floating_f_Fmt_##type##_tostr(SGS_MutStrRef dst, SGS__Floating_f_Fmt_##type obj) \
{ \
    sgs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*f", obj.precision, obj.obj); \
    if(dst.ty == SGS__DSTR_TY) \
    { \
        sgs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(sgs__mutstr_ref_as_cstr(dst), sgs__mutstr_ref_cap(dst), "%.*f", obj.precision, obj.obj); \
    if(sgs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        sgs__mutstr_ref_set_len(dst, sgs__mutstr_ref_cap(dst) - 1); \
        return (SGS_Error){SGS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        sgs__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (SGS_Error){SGS_ENCODING_ERROR}; \
    return (SGS_Error){SGS_OK}; \
} \
SGS_API SGS_Error sgs__Floating_g_Fmt_##type##_tostr(SGS_MutStrRef dst, SGS__Floating_g_Fmt_##type obj) \
{ \
    sgs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*g", obj.precision, obj.obj); \
    if(dst.ty == SGS__DSTR_TY) \
    { \
        sgs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(sgs__mutstr_ref_as_cstr(dst), sgs__mutstr_ref_cap(dst), "%.*g", obj.precision, obj.obj); \
    if(sgs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        sgs__mutstr_ref_set_len(dst, sgs__mutstr_ref_cap(dst) - 1); \
        return (SGS_Error){SGS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        sgs__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (SGS_Error){SGS_ENCODING_ERROR}; \
    return (SGS_Error){SGS_OK}; \
} \
SGS_API SGS_Error sgs__Floating_e_Fmt_##type##_tostr(SGS_MutStrRef dst, SGS__Floating_e_Fmt_##type obj) \
{ \
    sgs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*e", obj.precision, obj.obj); \
    if(dst.ty == SGS__DSTR_TY) \
    { \
        sgs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(sgs__mutstr_ref_as_cstr(dst), sgs__mutstr_ref_cap(dst), "%.*e", obj.precision, obj.obj); \
    if(sgs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        sgs__mutstr_ref_set_len(dst, sgs__mutstr_ref_cap(dst) - 1); \
        return (SGS_Error){SGS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        sgs__mutstr_ref_set_len(dst, len); \
    } \
    if(err < 0) \
        return (SGS_Error){SGS_ENCODING_ERROR}; \
    return (SGS_Error){SGS_OK}; \
} \
SGS_API SGS_Error sgs__Floating_a_Fmt_##type##_tostr(SGS_MutStrRef dst, SGS__Floating_a_Fmt_##type obj) \
{ \
    sgs__mutstr_ref_clear(dst); \
    int len = snprintf(0, 0, "%.*a", obj.precision, obj.obj); \
    if(dst.ty == SGS__DSTR_TY) \
    { \
        sgs__dstr_ensure_cap(dst.str.dstr, len + 1); \
    } \
    int err = snprintf(sgs__mutstr_ref_as_cstr(dst), sgs__mutstr_ref_cap(dst), "%.*a", obj.precision, obj.obj); \
    if(sgs__mutstr_ref_cap(dst) - 1 < (unsigned int) len) \
    { \
        sgs__mutstr_ref_set_len(dst, sgs__mutstr_ref_cap(dst) - 1); \
        return (SGS_Error){SGS_DST_TOO_SMALL}; \
    } \
    else \
    { \
        sgs__mutstr_ref_set_len(dst, len); \
    } \
    \
    if(err < 0) \
        return (SGS_Error){SGS_ENCODING_ERROR}; \
    return (SGS_Error){SGS_OK}; \
} \
\
\
SGS_API SGS_Error sgs__Floating_f_Fmt_##type##_tostr_p(SGS_MutStrRef dst, SGS__Floating_f_Fmt_##type *obj) \
{ \
    return sgs__Floating_f_Fmt_##type##_tostr(dst, *obj); \
} \
SGS_API SGS_Error sgs__Floating_g_Fmt_##type##_tostr_p(SGS_MutStrRef dst, SGS__Floating_g_Fmt_##type *obj) \
{ \
    return sgs__Floating_g_Fmt_##type##_tostr(dst, *obj); \
} \
SGS_API SGS_Error sgs__Floating_e_Fmt_##type##_tostr_p(SGS_MutStrRef dst, SGS__Floating_e_Fmt_##type *obj) \
{ \
    return sgs__Floating_e_Fmt_##type##_tostr(dst, *obj); \
} \
SGS_API SGS_Error sgs__Floating_a_Fmt_##type##_tostr_p(SGS_MutStrRef dst, SGS__Floating_a_Fmt_##type *obj) \
{ \
    return sgs__Floating_a_Fmt_##type##_tostr(dst, *obj); \
}

SGS__FLOATING_TYPES(SGS__X, ignore, SGS__X)

#undef SGS__X

SGS_API SGS_Error sgs__bool_tostr_p(SGS_MutStrRef dst, bool *obj)
{
    return sgs__bool_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__cstr_tostr_p(SGS_MutStrRef dst, const char **obj)
{
    return sgs__cstr_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__ucstr_tostr_p(SGS_MutStrRef dst, const unsigned char **obj)
{
    return sgs__ucstr_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__char_tostr_p(SGS_MutStrRef dst, char *obj)
{
    return sgs__char_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__schar_tostr_p(SGS_MutStrRef dst, signed char *obj)
{
    return sgs__schar_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__uchar_tostr_p(SGS_MutStrRef dst, unsigned char *obj)
{
    return sgs__uchar_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__short_tostr_p(SGS_MutStrRef dst, short *obj)
{
    return sgs__short_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__ushort_tostr_p(SGS_MutStrRef dst, unsigned short *obj)
{
    return sgs__ushort_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__int_tostr_p(SGS_MutStrRef dst, int *obj)
{
    return sgs__int_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__uint_tostr_p(SGS_MutStrRef dst, unsigned int *obj)
{
    return sgs__uint_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__long_tostr_p(SGS_MutStrRef dst, long *obj)
{
    return sgs__long_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__ulong_tostr_p(SGS_MutStrRef dst, unsigned long *obj)
{
    return sgs__ulong_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__llong_tostr_p(SGS_MutStrRef dst, long long *obj)
{
    return sgs__llong_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__ullong_tostr_p(SGS_MutStrRef dst, unsigned long long *obj)
{
    return sgs__ullong_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__float_tostr_p(SGS_MutStrRef dst, float *obj)
{
    return sgs__float_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__double_tostr_p(SGS_MutStrRef dst, double *obj)
{
    return sgs__double_tostr(dst, *obj);
}

SGS_API SGS_Error sgs__dstr_tostr_p(SGS_MutStrRef dst, const SGS_DStr *obj)
{
    return sgs__dstr_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__dstr_ptr_tostr_p(SGS_MutStrRef dst, const SGS_DStr **obj)
{
    return sgs__dstr_ptr_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__strv_tostr_p(SGS_MutStrRef dst, const SGS_StrView *obj)
{
    return sgs__strv_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__strbuf_tostr_p(SGS_MutStrRef dst, const SGS_StrBuf *obj)
{
    return sgs__strbuf_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__strbuf_ptr_tostr_p(SGS_MutStrRef dst, const SGS_StrBuf **obj)
{
    return sgs__strbuf_ptr_tostr(dst, *obj);
}
SGS_API SGS_Error sgs__mutstr_ref_tostr_p(SGS_MutStrRef dst, const SGS_MutStrRef *obj)
{
    return sgs__mutstr_ref_tostr(dst, *obj);
}

SGS_API SGS_Error sgs__error_tostr_p(SGS_MutStrRef dst, SGS_Error *obj)
{
    return sgs__error_tostr(dst, *obj);
}

SGS_API SGS_Error sgs__array_fmt_tostr_p(SGS_MutStrRef dst, SGS_ArrayFmt *obj)
{
    return sgs__array_fmt_tostr(dst, *obj);
}

#endif // SGS__STR_C_INCLUDED