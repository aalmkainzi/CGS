#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define CGS_SHORT_NAMES
#define CGS_API static inline
#define CGS_PRIVATE static inline

#include "../cgs.c"

typedef struct S
{
    float f;
    int i;
} S;

CGS_Error s2str(CGS_Writer dst, S s)
{
    cgs_append_tostr_all(dst, s.f, " -- ", s.i);
    return (CGS_Error){CGS_OK};
}

CGS_Error fp2str(CGS_Writer dst, FILE *s)
{
    (void )s;
    cgs_append_tostr_all(dst, "FILE_PTR");
    return (CGS_Error){CGS_OK};
}

#define ADD_TOSTR (S, s2str)
#include "../cgs.h"

#define ADD_TOSTR (FILE*, fp2str)
#include "../cgs.h"

typedef struct MyAllocator
{
    CGS_Allocator funcs;
    int allocs;
    int frees;
    int reallocs;
} MyAllocator;

CGS_Allocation myalloc(CGS_Allocator *all, size_t a, size_t n)
{
    (void) a;
    MyAllocator *al = (MyAllocator*) all;
    al->allocs -= 1;
    return (CGS_Allocation){.ptr = malloc(n), .n = n};
}

void mydealloc(CGS_Allocator *all, void *ptr, size_t n)
{
    (void)n;
    MyAllocator *al = (MyAllocator*) all;
    al->frees += 1;
    free(ptr);
}

CGS_Allocation myrealloc(CGS_Allocator *all, void *p, size_t a, size_t n, size_t nn)
{
    (void)n;
    (void)a;
    MyAllocator *al = (MyAllocator*) all;
    al->reallocs += 1;
    return (CGS_Allocation){.ptr = realloc(p, nn), .n = nn};
}

MyAllocator allocator = {
    .funcs = {
        .alloc   = myalloc,
        .dealloc = mydealloc,
        .realloc = myrealloc
    }
};

typedef struct StrvWalker
{
    StrViewArray arr;
    unsigned int cur;
} StrvWalker;

bool expect_sv(StrView sv, void *ctx)
{
    StrvWalker *arr = ctx;
    assert(cgs_equal(sv, arr->arr.strs[arr->cur]));
    arr->cur += 1;
    return true;
}

void test_split()
{
    cgs_split_iter("a,b,c", ",", expect_sv, &(StrvWalker){cgs_strv_arr("a","b","c")}); /* ["a","b","c"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("abc", ",", expect_sv, &(StrvWalker){cgs_strv_arr("abc")}); /* ["abc"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter(",", ",", expect_sv, &(StrvWalker){cgs_strv_arr("","")}); /* ["",""] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("", ",", expect_sv, &(StrvWalker){cgs_strv_arr("")}); /* [""] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter(",a,b", ",", expect_sv, &(StrvWalker){cgs_strv_arr("","a","b")}); /* ["","a","b"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("a,b,", ",", expect_sv, &(StrvWalker){cgs_strv_arr("a","b","")}); /* ["a","b",""] */ cgs_printfln("%?", " --- ");
    cgs_split_iter(",a,b,", ",", expect_sv, &(StrvWalker){cgs_strv_arr("","a","b","")}); /* ["","a","b",""] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter("a,,b", ",", expect_sv, &(StrvWalker){cgs_strv_arr("a","","b")}); /* ["a","","b"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter(",,", ",", expect_sv, &(StrvWalker){cgs_strv_arr("","","")}); /* ["","",""] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("a,,,b", ",", expect_sv, &(StrvWalker){cgs_strv_arr("a","","","b")}); /* ["a","","","b"] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter("aaabaaa", "aa", expect_sv, &(StrvWalker){cgs_strv_arr("","ab","a")}); /* ["","ab","a"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("aaaa", "aa", expect_sv, &(StrvWalker){cgs_strv_arr("","","")}); /* ["","",""] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("aaa", "aa", expect_sv, &(StrvWalker){cgs_strv_arr("","a")}); /* ["","a"] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter("aabaaab", "aa", expect_sv, &(StrvWalker){cgs_strv_arr("","b","ab")}); /* ["","b","ab"] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter("aaaaa", "aaa", expect_sv, &(StrvWalker){cgs_strv_arr("","aa")}); /* ["","aa"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("abababa", "aba", expect_sv, &(StrvWalker){cgs_strv_arr("","b","")}); /* ["","b",""] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter("hello", "xyz", expect_sv, &(StrvWalker){cgs_strv_arr("hello")}); /* ["hello"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("abc", "abc", expect_sv, &(StrvWalker){cgs_strv_arr("","")}); /* ["",""] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("abcabc", "abc", expect_sv, &(StrvWalker){cgs_strv_arr("","","")}); /* ["","",""] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter("a", "aa", expect_sv, &(StrvWalker){cgs_strv_arr("a")}); /* ["a"] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("", "aa", expect_sv, &(StrvWalker){cgs_strv_arr("")}); /* [""] */ cgs_printfln("%?", " --- ");
    
    cgs_split_iter("aaaa", "a", expect_sv, &(StrvWalker){cgs_strv_arr("","","","","")}); /* ["","","","",""] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("a", "a", expect_sv, &(StrvWalker){cgs_strv_arr("","")}); /* ["",""] */ cgs_printfln("%?", " --- ");
    cgs_split_iter("ba", "a", expect_sv, &(StrvWalker){cgs_strv_arr("b","")}); /* ["b",""] */ cgs_printfln("%?", " --- ");
}

void test_hex()
{
    char C[64] = {0};
    StrBuf str = strbuf_init_from_buf(C);
    
    // Unsigned char / uint8_t
    tostr(&str, nfmt((unsigned char)0, 'x'));
    
    
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "0"));
    
    tostr(&str, nfmt((uint8_t)255, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "ff"));
    
    // Signed char / int8_t (Two's complement)
    tostr(&str, nfmt((int8_t)-1, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "ff"));
    
    tostr(&str, nfmt((int8_t)-128, 'x')); // SCHAR_MIN
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "80"));
    
    
    tostr(&str, nfmt((unsigned short)0xABCD, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "abcd"));
    
    tostr(&str, nfmt((int16_t)-2, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "fffe"));
    
    tostr(&str, nfmt((uint16_t)65535, 'x')); // USHRT_MAX
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "ffff"));
    
    tostr(&str, nfmt(0, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "0"));
    
    tostr(&str, nfmt(2147483647, 'x')); // INT_MAX (32-bit)
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "7fffffff"));
    
    tostr(&str, nfmt(-1, 'x')); // int -1
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "ffffffff"));
    
    tostr(&str, nfmt(0x12345678, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "12345678"));
    
    tostr(&str, nfmt(0xFFFFFFFFFFFFFFFFULL, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "ffffffffffffffff"));
    
    // 64-bit signed
    tostr(&str, nfmt(-1LL, 'x'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "ffffffffffffffff"));
    
    tostr(&str, nfmt(9223372036854775807LL, 'x')); // LLONG_MAX
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "7fffffffffffffff"));
    
    tostr(&str, nfmt(-9223372036854775807LL - 1LL, 'x')); // LLONG_MIN
    assert(cgs_equal(str, "8000000000000000"));
    
    cgs_append_tostr_all(stdout, str);
}

void test_octal()
{
    char C[64] = { 0 };
    StrBuf str = strbuf_init_from_buf(C);
    
    // --- Basic Positive Tests (Common for all types) ---
    tostr(&str, nfmt(0, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "0"));
    
    tostr(&str, nfmt(10, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "12"));
    
    tostr(&str, nfmt(64, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "100"));
    
    tostr(&str, nfmt(511, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "777"));
    
    // --- 8-bit types (int8_t / uint8_t) ---
    tostr(&str, nfmt((uint8_t)255, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "377"));
    
    tostr(&str, nfmt((int8_t)-1, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "377")); // -1 in 8-bit two's complement
    
    tostr(&str, nfmt((int8_t)-128, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "200")); // -128 is 0x80
    
    // --- 16-bit types (int16_t / uint16_t) ---
    tostr(&str, nfmt((uint16_t)65535, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "177777"));
    
    tostr(&str, nfmt((int16_t)-1, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "177777"));
    
    tostr(&str, nfmt((int16_t)4096, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "10000"));
    
    // --- 32-bit types (int32_t / uint32_t) ---
    tostr(&str, nfmt((uint32_t)4294967295U, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "37777777777"));
    
    tostr(&str, nfmt((int32_t)-1, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "37777777777"));
    
    tostr(&str, nfmt((int32_t)123456, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "361100"));
    
    // --- 64-bit types (int64_t / uint64_t) ---
    tostr(&str, nfmt((uint64_t)18446744073709551615ULL, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1777777777777777777777"));
    
    tostr(&str, nfmt((int64_t)-1, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1777777777777777777777"));
    
    tostr(&str, nfmt((int64_t)0x123456789ABCDEFLL, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "4432126361152746757"));
    
    // --- Size types (size_t / ssize_t) ---
    tostr(&str, nfmt((size_t)1024, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "2000"));
    
    tostr(&str, nfmt((long long)-2, 'o'));
    cgs_append_tostr_all(stdout, str);
    // On 64-bit: 1777777777777777777776. On 32-bit: 37777777776.
    // Adjust this assertion if you are testing on a specific architecture.
    #if __SIZEOF_SIZE_T__ == 8
    assert(cgs_equal(str, "1777777777777777777776"));
    #else
    assert(cgs_equal(str, "37777777776"));
    #endif
    
    // --- Edge cases for Signed/Unsigned logic ---
    tostr(&str, nfmt((unsigned char)8, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "10"));
    
    tostr(&str, nfmt((long long)0, 'o'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "0"));
}

void test_bin()
{
    StrBuf str = strbuf_init_from_buf((char[128]){});
    
    // --- uint8_t Tests ---
    
    // Zero should return a single "0"
    tostr(&str, nfmt((uint8_t)0, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "0"));
    
    // Single bit (no padding)
    tostr(&str, nfmt((uint8_t)1, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1"));
    
    // Value 10 (binary 1010)
    tostr(&str, nfmt((uint8_t)10, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1010"));
    
    // Max uint8 (255)
    tostr(&str, nfmt((uint8_t)255, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "11111111"));
    
    // --- int8_t Tests (Two's Complement) ---
    
    // Negative 1 in 8-bit is 11111111
    tostr(&str, nfmt((int8_t)-1, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "11111111"));
    
    // Positive 127 is 01111111, without padding it is seven 1s
    tostr(&str, nfmt((int8_t)127, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1111111"));
    
    // Minimum negative value (-128) is 10000000
    tostr(&str, nfmt((int8_t)-128, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "10000000"));
    
    // --- uint16_t Tests ---
    
    // 256 is 1 followed by eight 0s
    tostr(&str, nfmt((uint16_t)256, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "100000000"));
    
    // 1024 is 1 followed by ten 0s
    tostr(&str, nfmt((uint16_t)1024, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "10000000000"));
    
    // --- int16_t Tests ---
    
    // -2 in 16-bit is 1111111111111110 (15 ones)
    tostr(&str, nfmt((int16_t)-2, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1111111111111110"));
    
    // --- uint32_t Tests ---
    
    // Power of 2 (2^31)
    tostr(&str, nfmt((uint32_t)0x80000000, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "10000000000000000000000000000000"));
    
    // A random small value in a large type (checks no padding)
    tostr(&str, nfmt((uint32_t)42, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "101010"));
    
    // --- uint64_t Tests ---
    
    // 64-bit Max (64 ones)
    tostr(&str, nfmt((uint64_t)-1, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1111111111111111111111111111111111111111111111111111111111111111"));
    
    // Large 64-bit number (1 followed by 60 zeros)
    tostr(&str, nfmt((uint64_t)1ULL << 60, 'b'));
    cgs_append_tostr_all(stdout, str);
    assert(cgs_equal(str, "1000000000000000000000000000000000000000000000000000000000000"));
}

void test_ffmt()
{
    const float f_eps = 1e-6f;
    const double d_eps = f_eps;
    
    StrBuf str = strbuf_init_from_buf((char[64]){0});
    float f;
    double d;
    CGS_Error er;
    
    er = tostr(&str, nfmt(10.5f, 'f'));
    cgs_append_tostr_all(stdout, er);
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(10.5f - f) < f_eps);
    
    // 2. Negative Fixed-point
    tostr(&str, nfmt(-123.456f, 'f'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(-123.456f - f) < f_eps);
    
    // 3. Scientific Notation (Small)
    tostr(&str, nfmt(0.0000123f, 'e'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(0.0000123f - f) < 1e-10f);
    
    // 4. Scientific Notation (Large)
    tostr(&str, nfmt(1234567.0f, 'e'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(1234567.0f - f) < 1.0f);
    
    // 5. Shortest Representation (No trailing zeros)
    tostr(&str, nfmt(100.0f, 'g'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(100.0f - f) < f_eps);
    
    // 6. Hex-Float (Exact representation)
    tostr(&str, nfmt(10.5f, 'a'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(10.5f == f); 
    
    // --- DOUBLE TESTS ---
    
    // 7. Double Precision Fixed
    tostr(&str, nfmt(3.14159265358979, 'f'));
    cgs_append_tostr_all(stdout, str);
    d = strtod((char*)str.chars, NULL);
    assert(fabs(3.14159265358979 - d) < d_eps);
    
    // 8. Double Precision Scientific
    tostr(&str, nfmt(1.2345678901234e-20, 'e'));
    cgs_append_tostr_all(stdout, str);
    d = strtod((char*)str.chars, NULL);
    assert(fabs(1.2345678901234e-20 - d) < d_eps);
    
    // 9. Double Hex-Float
    tostr(&str, nfmt(0.1, 'a'));
    cgs_append_tostr_all(stdout, str);
    d = strtod((char*)str.chars, NULL);
    printf("printf: %a\n", 0.1);
    assert(0.1 == d);
    
    // --- SPECIAL CASES ---
    
    // 10. Positive Zero
    tostr(&str, nfmt(0.0f, 'f'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(f == 0.0f);
    
    // 11. Negative Zero (Must show '-' sign)
    tostr(&str, nfmt(-0.0f, 'f'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(f == 0.0f && signbit(f));
    
    // 12. Infinity
    tostr(&str, nfmt(INFINITY, 'f'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(isinf(f) && f > 0);
    
    // 13. Negative Infinity
    tostr(&str, nfmt(-INFINITY, 'f'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(isinf(f) && f < 0);
    
    // 14. NaN
    tostr(&str, nfmt(NAN, 'f'));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(isnan(f));
    
    // 15. FLT_MAX
    tostr(&str, nfmt(FLT_MAX, 'e', 8));
    cgs_append_tostr_all(stdout, str);
    f = strtof((char*)str.chars, NULL);
    assert(fabs(f - FLT_MAX) <= (f_eps));
    
    // 16. DBL_MIN
    tostr(&str, nfmt(DBL_MIN, 'e'));
    cgs_append_tostr_all(stdout, str);
    d = strtod((char*)str.chars, NULL);
    assert(fabs(d - DBL_MIN) <= (d_eps));
    
    tostr(&str, nfmt(100, 'x'));
    
    // auto fobj = nfmt(100L, 'o');
    // size_t sz = sizeof(fobj);
}

void test_read()
{
    DStr str = dstr_init();
    
    {
        FILE *f_setup = fopen("files/test_basic.txt", "wb");
        fputs("hello world\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_basic.txt", "rb");
        cgs_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "hello world\n"));
    }
cgs_clear(&str);
    
    // --- 2. Multi-line Reading ---
    {
        FILE *f_setup = fopen("files/test_multi.txt", "wb");
        fputs("line one\nline two\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_multi.txt", "rb");
        
        cgs_fread_line(&str, f);
        assert(cgs_equal(str, "line one\n"));
        
        cgs_fread_line(&str, f);
        assert(cgs_equal(str, "line two\n"));
        
        fclose(f);
    }
cgs_clear(&str);
    
    // --- 3. No Trailing Newline ---
    {
        FILE *f_setup = fopen("files/test_no_nl.txt", "wb");
        fputs("missing newline", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_no_nl.txt", "rb");
        cgs_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "missing newline"));
    }
cgs_clear(&str);
    
    // --- 4. Empty File ---
    {
        FILE *f_setup = fopen("files/test_empty.txt", "wb");
        fclose(f_setup);
        
        FILE *f = fopen("files/test_empty.txt", "rb");
        cgs_fread_line(&str, f);
        fclose(f);
        // Adjust this check based on your API's specific behavior for EOF/empty files
        assert(cgs_equal(str, "")); 
    }
cgs_clear(&str);
    
    // --- 5. Windows-style Line Endings (CRLF) ---
    {
        FILE *f_setup = fopen("files/test_crlf.txt", "wb");
        fputs("windows line\r\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_crlf.txt", "rb");
        cgs_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "windows line\r\n"));
    }
cgs_clear(&str);
    
    // --- 6. Very Long Line (Testing Dynamic Growth) ---
    {
        FILE *f_setup = fopen("files/test_long.txt", "wb");
        for(int i = 0; i < 5000; i++) fputc('a', f_setup);
        fputc('\n', f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_long.txt", "rb");
        cgs_fread_line(&str, f);
        fclose(f);
        
        assert(cgs_len(str) == 5001);
        assert(str.chars[ 0] == 'a');
        assert(str.chars[ 4999] == 'a');
        assert(str.chars[ 5000] == '\n');
    }
cgs_clear(&str);
    
    // --- 7. Multiple Consecutive Newlines ---
    {
        FILE *f_setup = fopen("files/test_newlines.txt", "wb");
        fputs("\n\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_newlines.txt", "rb");
        
        cgs_fread_line(&str, f);
        assert(cgs_equal(str, "\n"));
        
        cgs_fread_line(&str, f);
        assert(cgs_equal(str, "\n"));
        
        fclose(f);
        
        cgs_clear(&str);
    }
    
    
    {
        FILE *f_setup = fopen("files/test1.txt", "wb");
        fputs("hello\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test1.txt", "rb");
        cgs_append_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "hello\n"));
        
        cgs_clear(&str);
    }
    
    // --- 2. Append to Existing Content ---
    {
        FILE *f_setup = fopen("files/test2.txt", "wb");
        fputs("world\n", f_setup);
        fclose(f_setup);
        
        cgs_copy(&str, "hello "); // Manually set initial content
        FILE *f = fopen("files/test2.txt", "rb");
        cgs_append_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "hello world\n"));
        
        cgs_clear(&str);
    }
    
    // --- 3. Consecutive Appends from Same File ---
    {
        FILE *f_setup = fopen("files/test3.txt", "wb");
        fputs("line1\nline2\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test3.txt", "rb");
        cgs_append_fread_line(&str, f); // Appends "line1\n"
        cgs_append_fread_line(&str, f); // Appends "line2\n"
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "line1\nline2\n"));
        
        cgs_clear(&str);
    }
    
    // --- 4. Append No-Newline File to String with Newline ---
    {
        FILE *f_setup = fopen("files/test4.txt", "wb");
        fputs("part2", f_setup); // No newline at end
        fclose(f_setup);
        
        cgs_copy(&str, "part1\n");
        FILE *f = fopen("files/test4.txt", "rb");
        cgs_append_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "part1\npart2"));
        
        cgs_clear(&str);
    }
    
    // --- 5. Append from Empty File (Should change nothing) ---
    {
        FILE *f_setup = fopen("files/test5.txt", "wb");
        fclose(f_setup);
        
        cgs_copy(&str, "preserved");
        FILE *f = fopen("files/test5.txt", "rb");
        cgs_append_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "preserved"));
        
        cgs_clear(&str);
    }
    
    // --- 6. Large Append (Dynamic Memory Stress) ---
    {
        FILE *f_setup = fopen("files/test6.txt", "wb");
        for(int i = 0; i < 5000; i++) fputc('b', f_setup);
        fputc('\n', f_setup);
        fclose(f_setup);
        
        cgs_copy(&str, "aaaaa"); 
        FILE *f = fopen("files/test6.txt", "rb");
        cgs_append_fread_line(&str, f);
        fclose(f);
        
        assert(cgs_len(str) == 5006);
        assert(str.chars[ 0] == 'a');
        assert(str.chars[ 5] == 'b');
        assert(str.chars[ 5005] == '\n');
        
        cgs_clear(&str);
    }
    
    // --- 7. Append CRLF Line ---
    {
        FILE *f_setup = fopen("files/test7.txt", "wb");
        fputs("dos\r\n", f_setup);
        fclose(f_setup);
        
        cgs_copy(&str, "unix\n");
        FILE *f = fopen("files/test7.txt", "rb");
        cgs_append_fread_line(&str, f);
        cgs_append_tostr_all(stdout, str);
        fclose(f);
        assert(cgs_equal(str, "unix\ndos\r\n"));
        
        cgs_clear(&str);
    }
    
    dstr_deinit(&str);
}

typedef struct S2
{
    char c;
    float f;
} S2;

CGS_Error s22str(CGS_Writer dst, S2 s)
{
    cgs_append_tostr_all(dst, s.c, "--", s.f);
    return (CGS_Error){CGS_OK};
}

#define ADD_TOSTR (S2, s22str)
#include "cgs.h"

#include <assert.h>
#define _GNU_SOURCE
#include <string.h>


struct FOO {
    int capacity;
    char drive;
};

CGS_Error foo_to_str(CGS_Writer dst, struct FOO f )
{
    cgs_append_tostr_all(dst, "FOO{ .drive=", f.drive, ":/", ", .capacity=", f.capacity, "}");
    return (CGS_Error){CGS_OK};
}

struct BAR {
    bool b;
    int i;
};

CGS_Error bar_tostr(CGS_Writer str, struct BAR b)
{
    cgs_append_tostr_all(str, "BAR{ b=", b.b, ", i=", b.i, " }");
    return (CGS_Error){CGS_OK};
}

#define ADD_TOSTR (struct FOO, foo_to_str)
#include "cgs.h"

#define ADD_TOSTR (struct BAR, bar_tostr)
#include "cgs.h"

void test_tostr()
{
    struct FOO a = {.capacity = 15, .drive = 'C'};
    DStr a_str = dstr_init();
    tostr(&a_str, a);
    assert(cgs_equal(a_str, "FOO{ .drive=C:/, .capacity=15}"));
    free(a_str.chars);
    
    char C[128] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    struct BAR bar = {.b = false, .i = 25};
    
    cgs_tostr(&sb, bar);
    assert(cgs_equal(sb, "BAR{ b=false, i=25 }"));
}

void test_str_del()
{
    char C[64] = {0};
    StrBuf str = strbuf_init_from_buf(C);
    cgs_copy(&str, "hello[DELETE THIS] world");
    
    StrView found = cgs_find(str, "[DELETE THIS]");
    CGS_Error ok = cgs_del(&str, found.chars - str.chars, found.chars - str.chars + found.len);
    
    assert(ok.ec == 0);
    assert(cgs_equal(str, "hello world"));
}

void test_str_count()
{
    StrView str = strv("aaabccdddd");
    assert(cgs_count(str, "a") == 3);
    assert(cgs_count(str, "b") == 1);
    assert(cgs_count(str, "c") == 2);
    assert(cgs_count(str, "d") == 4);
    cgs_append_tostr_all(stdout, cgs_count("vvv", "vv"));
    assert(cgs_count("vvv", "vv") == 1);
    assert(cgs_count(str, "") == str.len + 1);
    
    char C[] = "hello world";
    StrBuf sb = strbuf_init_from_cstr(C);
    unsigned int L = cgs_len(mutstr_ref("hello world"));
    assert(L == cgs_len("hello world") && L == strlen("hello world") && L == cgs_len(sb) && L == cgs_len(C));
}

void test_str_find()
{
    StrView str = cgs_strv("hello world");
    StrView empty = cgs_find(str, "");
    
    assert(empty.chars == str.chars && empty.len == 0);
    assert(cgs_equal(cgs_find(str, str), str));
    assert((cgs_find(str, "world").chars - str.chars) == 6);
    assert(cgs_find(str, "world").len == 5);
    assert(cgs_find(str, "F").chars == NULL);
}

void test_str_replace()
{
    char C[64] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    cgs_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    ReplaceResult replaced = cgs_replace(&sb, "-", "");
    cgs_append_tostr_all(stdout, "replaced :: ", replaced.nb_replaced);
    assert(cgs_equal(sb, "hello, world"));
    assert(replaced.nb_replaced == 11);
    
    cgs_copy(&sb, "hello world");
    replaced = cgs_replace(&sb, "-", ",");
    assert(cgs_equal(sb, "hello world"));
    assert(replaced.nb_replaced == 0);
    
    cgs_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    replaced = cgs_replace(&sb, "-", "_-_");
    assert(cgs_equal(sb, "h_-_e_-_l_-_l_-_o_-_,_-_ _-_w_-_o_-_r_-_l_-_d"));
    assert(replaced.nb_replaced == 11);
    
    cgs_copy(&sb, "h_-_e_-_l_-_l_-_o_-_,_-_ _-_w_-_o_-_r_-_l_-_d");
    replaced = cgs_replace(&sb, "_-_", "X");
    assert(cgs_equal(sb, "hXeXlXlXoX,X XwXoXrXlXd"));
    assert(replaced.nb_replaced == 11);
    
    cgs_copy(&sb, "hello world");
    cgs_replace(&sb, "", "-");
    assert(cgs_equal(sb, "-h-e-l-l-o- -w-o-r-l-d-"));
    
    cgs_copy(&sb, "hello world");
    cgs_replace(&sb, "", "XX");
    assert(cgs_equal(sb, "XXhXXeXXlXXlXXoXX XXwXXoXXrXXlXXdXX"));
}

void test_str_replace_first()
{
    char C[64] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    cgs_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    CGS_Error replaced = cgs_replace_first(&sb, "-", "");
    assert(cgs_equal(sb, "he-l-l-o-,- -w-o-r-l-d"));
    assert(replaced.ec != CGS_NOT_FOUND);
    
    cgs_copy(&sb, "dont replace here");
    ReplaceResult res = cgs_replace(&sb, "XX", "BIGGGGGGSTRINGGGGGG");
    assert(cgs_equal(sb, "dont replace here"));
    assert(res.nb_replaced == 0);
    
    cgs_copy(&sb, "hello world");
    cgs_replace_first(&sb, "", "---");
    assert(cgs_equal(sb, "---hello world"));
}

void test_read2()
{
    StrBuf sb = strbuf_init_from_buf((char[64]){});
    
    FILE *f = fopen("file", "rb");
    cgs_fread_line(&sb, f);
    cgs_append_tostr_all(stdout, sb.len, " :: '", sb, "'");
    assert(cgs_equal(sb, "this is the first line\n"));
    unsigned int linelen = cgs_len(sb);
    cgs_append_fread_line(&sb, f);
    assert(cgs_equal(cgs_strv(sb, linelen, sb.len), "no newline here"));
    
    assert(feof(f));
    
    fclose(f);
    
    f = fopen("file", "rb");
    
    DStr line = dstr_init();
    
    cgs_fread_line(&line, f);
    assert(cgs_equal(line, "this is the first line\n"));
    
    cgs_append_fread_line(&line, f);
    assert(cgs_equal(line, "this is the first line\nno newline here"));
    
    dstr_deinit(&line);
}

void test_misc()
{
    char *s = "this is my cstr";
    StrBuf sb = strbuf_init_from_buf((char[128]){0});
    for(unsigned i = 0, len = cgs_len(s) ; i < len ; i++)
    {
        cgs_append_tostr(&sb, (s[ i ]));
    }
    cgs_append_tostr_all(stdout, "sb == ", sb);
    assert(cgs_equal(sb, "this is my cstr"));
    assert(cgs_equal(sb, s));
    assert(cgs_starts_with(sb, sb));
    assert(cgs_ends_with(sb, sb));
    assert(cgs_starts_with(sb, "this"));
    assert(cgs_ends_with(sb, "cstr"));
    
    StrViewArray split = cgs_split("hello,world", "");
    DStr d = dstr_init();
    cgs_join(&d, split, "-");
    assert(cgs_equal(d, "h-e-l-l-o-,-w-o-r-l-d"));
    
    free(split.strs);
    split = cgs_split("abc", "a");
    
    cgs_join(&d, split, "X");
    assert(cgs_equal(d, "Xbc"));
    
    free(d.chars);
    free(split.strs);
}

void test_sprint()
{
    char C[128] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    
    cgs_append_tostr(&sb, sb);
    assert(cgs_equal(sb, ""));
    
    cgs_copy(&sb, "WOW");
    cgs_append_tostr_all(&sb, 5);
    assert(cgs_equal(sb, "WOW5"));
    
    cgs_tostr_all(&sb, "w", sb, "w", ".");
    assert(cgs_equal(sb, "www."));
    
    cgs_tostr_all(&sb, "hello", " ", "world", 123);
    assert(cgs_equal(&sb, "hello world123"));
    
    cgs_append_tostr_all(&sb, sb);
    assert(cgs_equal(sb, "hello world123hello world123"));
    
    cgs_copy(&sb, "hello world123");
    cgs_append_tostr_all(&sb, sb);
    assert(cgs_equal(sb, "hello world123hello world123"));
    
    cgs_copy(&sb, "X-");
    cgs_append_tostr_all(&sb, sb, sb);
    assert(cgs_equal(sb, "X-X-X-X-"));
    
    unsigned char CC2[256] = {0};
    StrBuf sb2 = strbuf_init_from_buf(CC2);
    unsigned short unsigned_short_max = -1;
    unsigned int unsigned_int_max = -1;
    unsigned long long unsigned_long_max = -1;
    unsigned long long unsigned_long_long_max = -1;
    signed char signed_char_min = -128;
    signed char signed_char_max = 127;
    short short_min = -32768;
    short short_max = 32767;
    int int_min = -2147483648;
    int int_max = 2147483647;
    long long long_min = LLONG_MIN;
    long long long_max = LLONG_MAX;
    long long long_long_min = LLONG_MIN;
    long long long_long_max = LLONG_MAX;
    cgs_append_tostr_all(&sb2,signed_char_min, " ", short_min, " ", int_min, " ", long_min, " ", long_long_min, " ", signed_char_max, " ", short_max, " ", int_max, " ", long_max, " "
    , long_long_max, " ",unsigned_short_max, " ", unsigned_int_max, " ", unsigned_long_max, " ", unsigned_long_long_max);
    
    cgs_append_tostr_all(stdout, "sb2 == '", sb2, "'");
    
    assert(cgs_equal(sb2, "-128 -32768 -2147483648 -9223372036854775808 -9223372036854775808 127 32767 2147483647 9223372036854775807 9223372036854775807 65535 4294967295 18446744073709551615 18446744073709551615"));
    
    cgs_tostr_all(&sb2, 0);
    assert(cgs_equal(sb2, "0"));
    
    unsigned char CC3[3] = {0};
    StrBuf sb3 = strbuf_init_from_buf(CC3);
    cgs_append_tostr_all(&sb3, 123456);
    assert(cgs_equal(sb3, "12"));
    cgs_tostr_all(&sb3, (unsigned long long) 5678);
    assert(cgs_equal(sb3, "56"));
}

void test_insert()
{
    char C[256] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    
    cgs_insert(&sb, "hello world", 0);
    assert(cgs_equal(sb, "hello world"));
    
    cgs_insert(&sb, ",", 5);
    assert(cgs_equal(sb, "hello, world"));
}

void tests_memmem()
{
    char h[] = "hello world";
    char w[] = "world";
    StrView found = cgs_find((h), (w));
    assert(found.len == strlen((char*) w) && found.chars == h + 6);
    
    char S[] = "-_-_-_-__-_-_";
    StrView found2 = cgs_find((S), ("-__"));
    assert(found2.len == 3 && found2.chars == S + 6);
}

bool split_cb(StrView found, void *arg) { (void)found; (void)arg; return true; }

void comp_check()
{
    // Mock callback for split_iter
    // --- 1. SETUP TYPES ---
    
    // Raw types
    char c_arr[] = "hello";
    unsigned char uc_arr[] = "world";
    char* c_ptr = c_arr;
    unsigned char* uc_ptr = uc_arr;

    // Library types
    DStr d = dstr_init_from("dynamic");
    StrBuf sb = strbuf_init_from_cstr(c_arr, sizeof(c_arr));
    StrView sv = strv("view");
    MutStrRef mr = mutstr_ref(&d);

    // --- 2. CONSTRUCTORS & INITIALIZERS ---
    
    // strv combinations
    StrView v1 = strv(c_arr);               // anystr: char[]
    StrView v2 = strv(c_ptr, 1, 3);         // anystr: char*
    StrView v3 = strv(d);                   // anystr: DStr
    StrView v4 = strv(&d);                  // anystr: DStr*
    StrView v5 = strv(mr);                  // anystr: MutStrRef

    // strbuf combinations
    StrBuf sb1 = strbuf_init_from_cstr(c_arr);          // char[]
    StrBuf sb2 = strbuf_init_from_cstr(uc_ptr, 10);     // unsigned char* + cap
    StrBuf sb3 = strbuf_init_from_buf(c_ptr, 20);       // char* + cap
    StrBuf sb4 = strbuf_init_from_buf(c_arr);       // char* + cap
    StrBuf sb5 = strbuf_init_from_buf(uc_arr);       // char* + cap
    
    // dstr combinations
    DStr d1 = dstr_init();                              // defaults
    DStr d2 = dstr_init(100);                           // custom cap
    DStr d3 = dstr_init_from(sv);                       // anystr: StrView
    DStr d4 = dstr_init_from(&sb);                      // anystr: StrBuf*

    // --- 3. ANYSTR (READ-ONLY) GENERIC DISPATCH ---
    
    // We'll use cgs_len and cgs_equal to test anystr variety
    unsigned int l = 0;
    l += cgs_len(c_arr);    l += cgs_len(uc_arr);
    l += cgs_len(c_ptr);    l += cgs_len(uc_ptr);
    l += cgs_len(sv);       l += cgs_len(d);
    l += cgs_len(&d);       l += cgs_len(sb);
    l += cgs_len(&sb);      l += cgs_len(mr);

    bool eq = false;
    eq = cgs_equal(c_arr, uc_arr);
    eq = cgs_equal(&d, sv);
    eq = cgs_equal(mr, sb);

    char c = d.chars[ 0];
    char* raw = cgs_chars(&sb);
    unsigned int cap = cgs_cap(mr);

    StrView f = cgs_find(d, "needle");
    unsigned int count = cgs_count(d, "a");
    bool sw = cgs_starts_with(sv, c_arr);
    bool ew = cgs_ends_with(&d, uc_ptr);
    
    // --- 4. MUTSTR (MUTATING) GENERIC DISPATCH ---
    
    // Testing dispatch on char*, char[], DStr*, StrBuf*, MutStrRef
    cgs_clear(c_ptr);
    cgs_clear(c_arr);
    cgs_clear(&d);
    cgs_clear(&sb);
    cgs_clear(mr);

    cgs_tolower(c_ptr);
    cgs_toupper(&d);
    
    cgs_copy(&d, sv);                   // mutstr, anystr
    cgs_putc(mr, '!');                  // mutstr
    cgs_append_tostr_all(&sb, "tail");            // mutstr, anystr
    cgs_insert(c_ptr, d, 1);            // mutstr, anystr
    cgs_prepend(mr, uc_arr);            // mutstr, anystr
    cgs_del(&d, 0, 2);                  // mutstr
    
    cgs_replace(&d, "old", "new");      // mutstr, anystr, anystr
    cgs_replace_first(mr, sv, "");      // mutstr, anystr, anystr
    cgs_replace_range(&sb, 1, 2, d);    // mutstr, uint, uint, anystr

    // --- 5. SPLIT & JOIN ---

    StrViewArray arr = cgs_split(d, ",");       // anystr, anystr
    cgs_split_iter(sv, " ", split_cb, NULL);    // anystr, anystr
    cgs_join(&d, arr, "::");                    // mutstr, array, anystr
    free(arr.strs);

    // --- 6. I/O OPERATIONS ---

    // cgs_read_line(&d);
    // cgs_append_read_line(mr);
    // cgs_fread_line(&sb, stdin); // Commented to prevent blocking during test run

    // --- 7. VARIADIC & TOSTR (THE "PRINT" FAMILY) ---

    // Types supporting tostr: ints, floats, all strings, Errors, Fmt types
    int i = 42;
    double f_val = 3.14;
    CGS_Error err = {CGS_OK};
    int int_arr[] = {1, 2, 3};
    ArrayFmt af = arrfmt(int_arr, 3);

    // Variadic compile check
    cgs_append_tostr_all(stdout, "Values:", i, f_val, d, sv, err, af, nfmt(255, 'X'));
    cgs_append_tostr_all(stdout, c_arr, uc_ptr, &sb, mr);
    
    // Sprint variants
    cgs_append_tostr_all(&d, "Result: ", nfmt(1.234, 'f', 2));
    cgs_append_tostr_all(mr, " more ", i);

    // Explicit tostr calls
    tostr(&d, i);
    tostr_p(mr, &f_val);
    
    bool has = has_tostr(i);

    // --- 8. ADVANCED / DSTR SPECIFICS ---

    dstr_shrink_to_fit(&d);
    dstr_ensure_cap(&d, 512);
    DStr d_dup = cgs_dup(c_arr);

    // Appender pattern
    AppenderState state;
    MutStrRef app = cgs_appender(&d, &state);
    cgs_append_tostr_all(app, "chunk");
    cgs_commit_appender(&d, app);

    // StrView Array helpers
    StrViewArray sva = cgs_strv_arr("a", d, sv, c_ptr);
    StrViewArray sva2 = cgs_strv_arr_from_carr(sva.strs, sva.len);

    // --- 9. CLEANUP ---
    dstr_deinit(&d);
    dstr_deinit(&d1);
    dstr_deinit(&d2);
    dstr_deinit(&d3);
    dstr_deinit(&d4);
    dstr_deinit(&d_dup);
}

int main()
{
    comp_check();
    
    
    test_tostr();
    test_str_del();
    test_str_count();
    test_str_find();
    test_str_replace();
    test_str_replace_first();
    test_read();
    test_misc();
    test_sprint();
    test_insert();
    tests_memmem();

    test_bin();
    test_ffmt();
    test_octal();
    test_read2();
    test_ffmt();
    test_split();
}
