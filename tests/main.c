#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define FXS_SHORT_NAMES
#define FXS_API static inline
#define FXS_PRIVATE static inline

#include "../fxs.c"

typedef struct S
{
    float f;
    int i;
} S;

FXS_Error s2str(MutStrRef dst, S s)
{
    fxs_sprint(dst, s.f, " -- ", s.i);
    return (FXS_Error){FXS_OK};
}

FXS_Error fp2str(MutStrRef dst, FILE *s)
{
    (void )s;
    fxs_sprint(dst, "FILE_PTR");
    return (FXS_Error){FXS_OK};
}

#define ADD_TOSTR (S, s2str)
#include "fxs.h"

#define ADD_TOSTR (FILE*, fp2str)
#include "fxs.h"

typedef struct MyAllocator
{
    FXS_Allocator funcs;
    int allocs;
    int frees;
    int reallocs;
} MyAllocator;

FXS_Allocation myalloc(FXS_Allocator *all, size_t a, size_t n)
{
    (void) a;
    MyAllocator *al = (MyAllocator*) all;
    al->allocs -= 1;
    return (FXS_Allocation){.ptr = malloc(n), .n = n};
}

void mydealloc(FXS_Allocator *all, void *ptr, size_t n)
{
    (void)n;
    MyAllocator *al = (MyAllocator*) all;
    al->frees += 1;
    free(ptr);
}

FXS_Allocation myrealloc(FXS_Allocator *all, void *p, size_t a, size_t n, size_t nn)
{
    (void)n;
    (void)a;
    MyAllocator *al = (MyAllocator*) all;
    al->reallocs += 1;
    return (FXS_Allocation){.ptr = realloc(p, nn), .n = nn};
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
    assert(fxs_equal(sv, arr->arr.strs[arr->cur]));
    arr->cur += 1;
    return true;
}

void test_split()
{
    fxs_split_iter("a,b,c", ",", expect_sv, &(StrvWalker){fxs_strv_arr("a","b","c")}); /* ["a","b","c"] */ println(" --- ");
    fxs_split_iter("abc", ",", expect_sv, &(StrvWalker){fxs_strv_arr("abc")}); /* ["abc"] */ println(" --- ");
    fxs_split_iter(",", ",", expect_sv, &(StrvWalker){fxs_strv_arr("","")}); /* ["",""] */ println(" --- ");
    fxs_split_iter("", ",", expect_sv, &(StrvWalker){fxs_strv_arr("")}); /* [""] */ println(" --- ");
    
    fxs_split_iter(",a,b", ",", expect_sv, &(StrvWalker){fxs_strv_arr("","a","b")}); /* ["","a","b"] */ println(" --- ");
    fxs_split_iter("a,b,", ",", expect_sv, &(StrvWalker){fxs_strv_arr("a","b","")}); /* ["a","b",""] */ println(" --- ");
    fxs_split_iter(",a,b,", ",", expect_sv, &(StrvWalker){fxs_strv_arr("","a","b","")}); /* ["","a","b",""] */ println(" --- ");
    
    fxs_split_iter("a,,b", ",", expect_sv, &(StrvWalker){fxs_strv_arr("a","","b")}); /* ["a","","b"] */ println(" --- ");
    fxs_split_iter(",,", ",", expect_sv, &(StrvWalker){fxs_strv_arr("","","")}); /* ["","",""] */ println(" --- ");
    fxs_split_iter("a,,,b", ",", expect_sv, &(StrvWalker){fxs_strv_arr("a","","","b")}); /* ["a","","","b"] */ println(" --- ");
    
    fxs_split_iter("aaabaaa", "aa", expect_sv, &(StrvWalker){fxs_strv_arr("","ab","a")}); /* ["","ab","a"] */ println(" --- ");
    fxs_split_iter("aaaa", "aa", expect_sv, &(StrvWalker){fxs_strv_arr("","","")}); /* ["","",""] */ println(" --- ");
    fxs_split_iter("aaa", "aa", expect_sv, &(StrvWalker){fxs_strv_arr("","a")}); /* ["","a"] */ println(" --- ");
    
    fxs_split_iter("aabaaab", "aa", expect_sv, &(StrvWalker){fxs_strv_arr("","b","ab")}); /* ["","b","ab"] */ println(" --- ");
    
    fxs_split_iter("aaaaa", "aaa", expect_sv, &(StrvWalker){fxs_strv_arr("","aa")}); /* ["","aa"] */ println(" --- ");
    fxs_split_iter("abababa", "aba", expect_sv, &(StrvWalker){fxs_strv_arr("","b","")}); /* ["","b",""] */ println(" --- ");
    
    fxs_split_iter("hello", "xyz", expect_sv, &(StrvWalker){fxs_strv_arr("hello")}); /* ["hello"] */ println(" --- ");
    fxs_split_iter("abc", "abc", expect_sv, &(StrvWalker){fxs_strv_arr("","")}); /* ["",""] */ println(" --- ");
    fxs_split_iter("abcabc", "abc", expect_sv, &(StrvWalker){fxs_strv_arr("","","")}); /* ["","",""] */ println(" --- ");
    
    fxs_split_iter("a", "aa", expect_sv, &(StrvWalker){fxs_strv_arr("a")}); /* ["a"] */ println(" --- ");
    fxs_split_iter("", "aa", expect_sv, &(StrvWalker){fxs_strv_arr("")}); /* [""] */ println(" --- ");
    
    fxs_split_iter("aaaa", "a", expect_sv, &(StrvWalker){fxs_strv_arr("","","","","")}); /* ["","","","",""] */ println(" --- ");
    fxs_split_iter("a", "a", expect_sv, &(StrvWalker){fxs_strv_arr("","")}); /* ["",""] */ println(" --- ");
    fxs_split_iter("ba", "a", expect_sv, &(StrvWalker){fxs_strv_arr("b","")}); /* ["b",""] */ println(" --- ");
}


void test_hex()
{
    char C[64] = {0};
    StrBuf str = strbuf_init_from_buf(C);
    
    // Unsigned char / uint8_t
    tostr(&str, tsfmt((unsigned char)0, 'x'));
    println(str);
    assert(fxs_equal(str, "0"));
    
    tostr(&str, tsfmt((uint8_t)255, 'x'));
    println(str);
    assert(fxs_equal(str, "ff"));
    
    // Signed char / int8_t (Two's complement)
    tostr(&str, tsfmt((int8_t)-1, 'x'));
    println(str);
    assert(fxs_equal(str, "ff"));
    
    tostr(&str, tsfmt((int8_t)-128, 'x')); // SCHAR_MIN
    println(str);
    assert(fxs_equal(str, "80"));
    
    
    tostr(&str, tsfmt((unsigned short)0xABCD, 'x'));
    println(str);
    assert(fxs_equal(str, "abcd"));
    
    tostr(&str, tsfmt((int16_t)-2, 'x'));
    println(str);
    assert(fxs_equal(str, "fffe"));
    
    tostr(&str, tsfmt((uint16_t)65535, 'x')); // USHRT_MAX
    println(str);
    assert(fxs_equal(str, "ffff"));
    
    tostr(&str, tsfmt(0, 'x'));
    println(str);
    assert(fxs_equal(str, "0"));
    
    tostr(&str, tsfmt(2147483647, 'x')); // INT_MAX (32-bit)
    println(str);
    assert(fxs_equal(str, "7fffffff"));
    
    tostr(&str, tsfmt(-1, 'x')); // int -1
    println(str);
    assert(fxs_equal(str, "ffffffff"));
    
    tostr(&str, tsfmt(0x12345678, 'x'));
    println(str);
    assert(fxs_equal(str, "12345678"));
    
    tostr(&str, tsfmt(0xFFFFFFFFFFFFFFFFULL, 'x'));
    println(str);
    assert(fxs_equal(str, "ffffffffffffffff"));
    
    // 64-bit signed
    tostr(&str, tsfmt(-1LL, 'x'));
    println(str);
    assert(fxs_equal(str, "ffffffffffffffff"));
    
    tostr(&str, tsfmt(9223372036854775807LL, 'x')); // LLONG_MAX
    println(str);
    assert(fxs_equal(str, "7fffffffffffffff"));
    
    tostr(&str, tsfmt(-9223372036854775807LL - 1LL, 'x')); // LLONG_MIN
    assert(fxs_equal(str, "8000000000000000"));
    
    println(str);
}

void test_octal()
{
    char C[64] = { 0 };
    StrBuf str = strbuf_init_from_buf(C);
    
    // --- Basic Positive Tests (Common for all types) ---
    tostr(&str, tsfmt(0, 'o'));
    println(str);
    assert(fxs_equal(str, "0"));
    
    tostr(&str, tsfmt(10, 'o'));
    println(str);
    assert(fxs_equal(str, "12"));
    
    tostr(&str, tsfmt(64, 'o'));
    println(str);
    assert(fxs_equal(str, "100"));
    
    tostr(&str, tsfmt(511, 'o'));
    println(str);
    assert(fxs_equal(str, "777"));
    
    // --- 8-bit types (int8_t / uint8_t) ---
    tostr(&str, tsfmt((uint8_t)255, 'o'));
    println(str);
    assert(fxs_equal(str, "377"));
    
    tostr(&str, tsfmt((int8_t)-1, 'o'));
    println(str);
    assert(fxs_equal(str, "377")); // -1 in 8-bit two's complement
    
    tostr(&str, tsfmt((int8_t)-128, 'o'));
    println(str);
    assert(fxs_equal(str, "200")); // -128 is 0x80
    
    // --- 16-bit types (int16_t / uint16_t) ---
    tostr(&str, tsfmt((uint16_t)65535, 'o'));
    println(str);
    assert(fxs_equal(str, "177777"));
    
    tostr(&str, tsfmt((int16_t)-1, 'o'));
    println(str);
    assert(fxs_equal(str, "177777"));
    
    tostr(&str, tsfmt((int16_t)4096, 'o'));
    println(str);
    assert(fxs_equal(str, "10000"));
    
    // --- 32-bit types (int32_t / uint32_t) ---
    tostr(&str, tsfmt((uint32_t)4294967295U, 'o'));
    println(str);
    assert(fxs_equal(str, "37777777777"));
    
    tostr(&str, tsfmt((int32_t)-1, 'o'));
    println(str);
    assert(fxs_equal(str, "37777777777"));
    
    tostr(&str, tsfmt((int32_t)123456, 'o'));
    println(str);
    assert(fxs_equal(str, "361100"));
    
    // --- 64-bit types (int64_t / uint64_t) ---
    tostr(&str, tsfmt((uint64_t)18446744073709551615ULL, 'o'));
    println(str);
    assert(fxs_equal(str, "1777777777777777777777"));
    
    tostr(&str, tsfmt((int64_t)-1, 'o'));
    println(str);
    assert(fxs_equal(str, "1777777777777777777777"));
    
    tostr(&str, tsfmt((int64_t)0x123456789ABCDEFLL, 'o'));
    println(str);
    assert(fxs_equal(str, "4432126361152746757"));
    
    // --- Size types (size_t / ssize_t) ---
    tostr(&str, tsfmt((size_t)1024, 'o'));
    println(str);
    assert(fxs_equal(str, "2000"));
    
    tostr(&str, tsfmt((long long)-2, 'o'));
    println(str);
    // On 64-bit: 1777777777777777777776. On 32-bit: 37777777776.
    // Adjust this assertion if you are testing on a specific architecture.
    #if __SIZEOF_SIZE_T__ == 8
    assert(fxs_equal(str, "1777777777777777777776"));
    #else
    assert(fxs_equal(str, "37777777776"));
    #endif
    
    // --- Edge cases for Signed/Unsigned logic ---
    tostr(&str, tsfmt((unsigned char)8, 'o'));
    println(str);
    assert(fxs_equal(str, "10"));
    
    tostr(&str, tsfmt((long long)0, 'o'));
    println(str);
    assert(fxs_equal(str, "0"));
}

void test_bin()
{
    StrBuf str = strbuf_init_from_buf((char[128]){});
    
    // --- uint8_t Tests ---
    
    // Zero should return a single "0"
    tostr(&str, tsfmt((uint8_t)0, 'b'));
    println(str);
    assert(fxs_equal(str, "0"));
    
    // Single bit (no padding)
    tostr(&str, tsfmt((uint8_t)1, 'b'));
    println(str);
    assert(fxs_equal(str, "1"));
    
    // Value 10 (binary 1010)
    tostr(&str, tsfmt((uint8_t)10, 'b'));
    println(str);
    assert(fxs_equal(str, "1010"));
    
    // Max uint8 (255)
    tostr(&str, tsfmt((uint8_t)255, 'b'));
    println(str);
    assert(fxs_equal(str, "11111111"));
    
    // --- int8_t Tests (Two's Complement) ---
    
    // Negative 1 in 8-bit is 11111111
    tostr(&str, tsfmt((int8_t)-1, 'b'));
    println(str);
    assert(fxs_equal(str, "11111111"));
    
    // Positive 127 is 01111111, without padding it is seven 1s
    tostr(&str, tsfmt((int8_t)127, 'b'));
    println(str);
    assert(fxs_equal(str, "1111111"));
    
    // Minimum negative value (-128) is 10000000
    tostr(&str, tsfmt((int8_t)-128, 'b'));
    println(str);
    assert(fxs_equal(str, "10000000"));
    
    // --- uint16_t Tests ---
    
    // 256 is 1 followed by eight 0s
    tostr(&str, tsfmt((uint16_t)256, 'b'));
    println(str);
    assert(fxs_equal(str, "100000000"));
    
    // 1024 is 1 followed by ten 0s
    tostr(&str, tsfmt((uint16_t)1024, 'b'));
    println(str);
    assert(fxs_equal(str, "10000000000"));
    
    // --- int16_t Tests ---
    
    // -2 in 16-bit is 1111111111111110 (15 ones)
    tostr(&str, tsfmt((int16_t)-2, 'b'));
    println(str);
    assert(fxs_equal(str, "1111111111111110"));
    
    // --- uint32_t Tests ---
    
    // Power of 2 (2^31)
    tostr(&str, tsfmt((uint32_t)0x80000000, 'b'));
    println(str);
    assert(fxs_equal(str, "10000000000000000000000000000000"));
    
    // A random small value in a large type (checks no padding)
    tostr(&str, tsfmt((uint32_t)42, 'b'));
    println(str);
    assert(fxs_equal(str, "101010"));
    
    // --- uint64_t Tests ---
    
    // 64-bit Max (64 ones)
    tostr(&str, tsfmt((uint64_t)-1, 'b'));
    println(str);
    assert(fxs_equal(str, "1111111111111111111111111111111111111111111111111111111111111111"));
    
    // Large 64-bit number (1 followed by 60 zeros)
    tostr(&str, tsfmt((uint64_t)1ULL << 60, 'b'));
    println(str);
    assert(fxs_equal(str, "1000000000000000000000000000000000000000000000000000000000000"));
}

void test_ffmt()
{
    const float f_eps = 1e-6f;
    const double d_eps = f_eps;
    
    StrBuf str = strbuf_init_from_buf((char[64]){0});
    float f;
    double d;
    FXS_Error er;
    
    er = tostr(&str, tsfmt(10.5f, 'f'));
    println(er);
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(10.5f - f) < f_eps);
    
    // 2. Negative Fixed-point
    tostr(&str, tsfmt(-123.456f, 'f'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(-123.456f - f) < f_eps);
    
    // 3. Scientific Notation (Small)
    tostr(&str, tsfmt(0.0000123f, 'e'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(0.0000123f - f) < 1e-10f);
    
    // 4. Scientific Notation (Large)
    tostr(&str, tsfmt(1234567.0f, 'e'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(1234567.0f - f) < 1.0f);
    
    // 5. Shortest Representation (No trailing zeros)
    tostr(&str, tsfmt(100.0f, 'g'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(fabsf(100.0f - f) < f_eps);
    
    // 6. Hex-Float (Exact representation)
    tostr(&str, tsfmt(10.5f, 'a'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(10.5f == f); 
    
    // --- DOUBLE TESTS ---
    
    // 7. Double Precision Fixed
    tostr(&str, tsfmt(3.14159265358979, 'f'));
    println(str);
    d = strtod((char*)str.chars, NULL);
    assert(fabs(3.14159265358979 - d) < d_eps);
    
    // 8. Double Precision Scientific
    tostr(&str, tsfmt(1.2345678901234e-20, 'e'));
    println(str);
    d = strtod((char*)str.chars, NULL);
    assert(fabs(1.2345678901234e-20 - d) < d_eps);
    
    // 9. Double Hex-Float
    tostr(&str, tsfmt(0.1, 'a'));
    println(str);
    d = strtod((char*)str.chars, NULL);
    printf("printf: %a\n", 0.1);
    assert(0.1 == d);
    
    // --- SPECIAL CASES ---
    
    // 10. Positive Zero
    tostr(&str, tsfmt(0.0f, 'f'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(f == 0.0f);
    
    // 11. Negative Zero (Must show '-' sign)
    tostr(&str, tsfmt(-0.0f, 'f'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(f == 0.0f && signbit(f));
    
    // 12. Infinity
    tostr(&str, tsfmt(INFINITY, 'f'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(isinf(f) && f > 0);
    
    // 13. Negative Infinity
    tostr(&str, tsfmt(-INFINITY, 'f'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(isinf(f) && f < 0);
    
    // 14. NaN
    tostr(&str, tsfmt(NAN, 'f'));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(isnan(f));
    
    // 15. FLT_MAX
    tostr(&str, tsfmt(FLT_MAX, 'e', 8));
    println(str);
    f = strtof((char*)str.chars, NULL);
    assert(fabs(f - FLT_MAX) <= (f_eps));
    
    // 16. DBL_MIN
    tostr(&str, tsfmt(DBL_MIN, 'e'));
    println(str);
    d = strtod((char*)str.chars, NULL);
    assert(fabs(d - DBL_MIN) <= (d_eps));
    
    tostr(&str, tsfmt(100, 'x'));
    
    // auto fobj = tsfmt(100L, 'o');
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
        fxs_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "hello world\n"));
    }
fxs_clear(&str);
    
    // --- 2. Multi-line Reading ---
    {
        FILE *f_setup = fopen("files/test_multi.txt", "wb");
        fputs("line one\nline two\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_multi.txt", "rb");
        
        fxs_fread_line(&str, f);
        assert(fxs_equal(str, "line one\n"));
        
        fxs_fread_line(&str, f);
        assert(fxs_equal(str, "line two\n"));
        
        fclose(f);
    }
fxs_clear(&str);
    
    // --- 3. No Trailing Newline ---
    {
        FILE *f_setup = fopen("files/test_no_nl.txt", "wb");
        fputs("missing newline", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_no_nl.txt", "rb");
        fxs_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "missing newline"));
    }
fxs_clear(&str);
    
    // --- 4. Empty File ---
    {
        FILE *f_setup = fopen("files/test_empty.txt", "wb");
        fclose(f_setup);
        
        FILE *f = fopen("files/test_empty.txt", "rb");
        fxs_fread_line(&str, f);
        fclose(f);
        // Adjust this check based on your API's specific behavior for EOF/empty files
        assert(fxs_equal(str, "")); 
    }
fxs_clear(&str);
    
    // --- 5. Windows-style Line Endings (CRLF) ---
    {
        FILE *f_setup = fopen("files/test_crlf.txt", "wb");
        fputs("windows line\r\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_crlf.txt", "rb");
        fxs_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "windows line\r\n"));
    }
fxs_clear(&str);
    
    // --- 6. Very Long Line (Testing Dynamic Growth) ---
    {
        FILE *f_setup = fopen("files/test_long.txt", "wb");
        for(int i = 0; i < 5000; i++) fputc('a', f_setup);
        fputc('\n', f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_long.txt", "rb");
        fxs_fread_line(&str, f);
        fclose(f);
        
        assert(fxs_len(str) == 5001);
        assert(fxs_at(str, 0) == 'a');
        assert(fxs_at(str, 4999) == 'a');
        assert(fxs_at(str, 5000) == '\n');
    }
fxs_clear(&str);
    
    // --- 7. Multiple Consecutive Newlines ---
    {
        FILE *f_setup = fopen("files/test_newlines.txt", "wb");
        fputs("\n\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test_newlines.txt", "rb");
        
        fxs_fread_line(&str, f);
        assert(fxs_equal(str, "\n"));
        
        fxs_fread_line(&str, f);
        assert(fxs_equal(str, "\n"));
        
        fclose(f);
        
        fxs_clear(&str);
    }
    
    
    {
        FILE *f_setup = fopen("files/test1.txt", "wb");
        fputs("hello\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test1.txt", "rb");
        fxs_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "hello\n"));
        
        fxs_clear(&str);
    }
    
    // --- 2. Append to Existing Content ---
    {
        FILE *f_setup = fopen("files/test2.txt", "wb");
        fputs("world\n", f_setup);
        fclose(f_setup);
        
        fxs_copy(&str, "hello "); // Manually set initial content
        FILE *f = fopen("files/test2.txt", "rb");
        fxs_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "hello world\n"));
        
        fxs_clear(&str);
    }
    
    // --- 3. Consecutive Appends from Same File ---
    {
        FILE *f_setup = fopen("files/test3.txt", "wb");
        fputs("line1\nline2\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("files/test3.txt", "rb");
        fxs_append_fread_line(&str, f); // Appends "line1\n"
        fxs_append_fread_line(&str, f); // Appends "line2\n"
        println(str);
        fclose(f);
        assert(fxs_equal(str, "line1\nline2\n"));
        
        fxs_clear(&str);
    }
    
    // --- 4. Append No-Newline File to String with Newline ---
    {
        FILE *f_setup = fopen("files/test4.txt", "wb");
        fputs("part2", f_setup); // No newline at end
        fclose(f_setup);
        
        fxs_copy(&str, "part1\n");
        FILE *f = fopen("files/test4.txt", "rb");
        fxs_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "part1\npart2"));
        
        fxs_clear(&str);
    }
    
    // --- 5. Append from Empty File (Should change nothing) ---
    {
        FILE *f_setup = fopen("files/test5.txt", "wb");
        fclose(f_setup);
        
        fxs_copy(&str, "preserved");
        FILE *f = fopen("files/test5.txt", "rb");
        fxs_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "preserved"));
        
        fxs_clear(&str);
    }
    
    // --- 6. Large Append (Dynamic Memory Stress) ---
    {
        FILE *f_setup = fopen("files/test6.txt", "wb");
        for(int i = 0; i < 5000; i++) fputc('b', f_setup);
        fputc('\n', f_setup);
        fclose(f_setup);
        
        fxs_copy(&str, "aaaaa"); 
        FILE *f = fopen("files/test6.txt", "rb");
        fxs_append_fread_line(&str, f);
        fclose(f);
        
        assert(fxs_len(str) == 5006);
        assert(fxs_at(str, 0) == 'a');
        assert(fxs_at(str, 5) == 'b');
        assert(fxs_at(str, 5005) == '\n');
        
        fxs_clear(&str);
    }
    
    // --- 7. Append CRLF Line ---
    {
        FILE *f_setup = fopen("files/test7.txt", "wb");
        fputs("dos\r\n", f_setup);
        fclose(f_setup);
        
        fxs_copy(&str, "unix\n");
        FILE *f = fopen("files/test7.txt", "rb");
        fxs_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(fxs_equal(str, "unix\ndos\r\n"));
        
        fxs_clear(&str);
    }
    
    dstr_deinit(&str);
}

typedef struct S2
{
    char c;
    float f;
} S2;

FXS_Error s22str(MutStrRef dst, S2 s)
{
    fxs_sprint(dst, s.c, "--", s.f);
    return (FXS_Error){FXS_OK};
}

#define ADD_TOSTR (S2, s22str)
#include "fxs.h"

#include <assert.h>
#define _GNU_SOURCE
#include <string.h>


struct FOO {
    int capacity;
    char drive;
};

FXS_Error foo_to_str(MutStrRef dst, struct FOO f )
{
    fxs_sprint(dst, "FOO{ .drive=", f.drive, ":/", ", .capacity=", f.capacity, "}");
    return (FXS_Error){FXS_OK};
}

struct BAR {
    bool b;
    int i;
};

FXS_Error bar_tostr(MutStrRef str, struct BAR b)
{
    fxs_sprint(str, "BAR{ b=", b.b, ", i=", b.i, " }");
    return (FXS_Error){FXS_OK};
}

#define ADD_TOSTR (struct FOO, foo_to_str)
#include "fxs.h"

#define ADD_TOSTR (struct BAR, bar_tostr)
#include "fxs.h"

void test_tostr()
{
    struct FOO a = {.capacity = 15, .drive = 'C'};
    DStr a_str = dstr_init();
    tostr(&a_str, a);
    assert(fxs_equal(a_str, "FOO{ .drive=C:/, .capacity=15}"));
    free(a_str.chars);
    
    char C[128] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    struct BAR bar = {.b = false, .i = 25};
    
    fxs_sprint(&sb, bar);
    assert(fxs_equal(sb, "BAR{ b=false, i=25 }"));
}

void test_str_del()
{
    char C[64] = {0};
    StrBuf str = strbuf_init_from_buf(C);
    fxs_copy(&str, "hello[DELETE THIS] world");
    
    StrView found = fxs_find(str, "[DELETE THIS]");
    FXS_Error ok = fxs_del(&str, found.chars - str.chars, found.chars - str.chars + found.len);
    
    assert(ok.ec == 0);
    assert(fxs_equal(str, "hello world"));
}

void test_str_count()
{
    StrView str = strv("aaabccdddd");
    assert(fxs_count(str, "a") == 3);
    assert(fxs_count(str, "b") == 1);
    assert(fxs_count(str, "c") == 2);
    assert(fxs_count(str, "d") == 4);
    println(fxs_count("vvv", "vv"));
    assert(fxs_count("vvv", "vv") == 1);
    assert(fxs_count(str, "") == 0);
    
    char C[] = "hello world";
    StrBuf sb = strbuf_init_from_cstr(C);
    unsigned int L = fxs_len(mutstr_ref("hello world"));
    assert(L == fxs_len("hello world") && L == strlen("hello world") && L == fxs_len(sb) && L == fxs_len(C));
}

void test_str_find()
{
    StrView str = fxs_strv("hello world");
    StrView empty = fxs_find(str, "");
    
    assert(empty.chars == str.chars && empty.len == 0);
    assert(fxs_equal(fxs_find(str, str), str));
    assert((fxs_find(str, "world").chars - str.chars) == 6);
    assert(fxs_find(str, "world").len == 5);
    assert(fxs_find(str, "F").chars == NULL);
}

void test_str_replace()
{
    char C[64] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    fxs_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    ReplaceResult replaced = fxs_replace(&sb, "-", "");
    println("replaced :: ", replaced.nb_replaced);
    assert(fxs_equal(sb, "hello, world"));
    assert(replaced.nb_replaced == 11);
    
    fxs_copy(&sb, "hello world");
    replaced = fxs_replace(&sb, "-", ",");
    assert(fxs_equal(sb, "hello world"));
    assert(replaced.nb_replaced == 0);
    
    fxs_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    replaced = fxs_replace(&sb, "-", "_-_");
    assert(fxs_equal(sb, "h_-_e_-_l_-_l_-_o_-_,_-_ _-_w_-_o_-_r_-_l_-_d"));
    assert(replaced.nb_replaced == 11);
    
    fxs_copy(&sb, "h_-_e_-_l_-_l_-_o_-_,_-_ _-_w_-_o_-_r_-_l_-_d");
    replaced = fxs_replace(&sb, "_-_", "X");
    assert(fxs_equal(sb, "hXeXlXlXoX,X XwXoXrXlXd"));
    assert(replaced.nb_replaced == 11);
    
    fxs_copy(&sb, "hello world");
    fxs_replace(&sb, "", "-");
    assert(fxs_equal(sb, "-h-e-l-l-o- -w-o-r-l-d-"));
    
    fxs_copy(&sb, "hello world");
    fxs_replace(&sb, "", "XX");
    assert(fxs_equal(sb, "XXhXXeXXlXXlXXoXX XXwXXoXXrXXlXXdXX"));
}

void test_str_replace_first()
{
    char C[64] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    fxs_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    FXS_Error replaced = fxs_replace_first(&sb, "-", "");
    assert(fxs_equal(sb, "he-l-l-o-,- -w-o-r-l-d"));
    assert(replaced.ec != FXS_NOT_FOUND);
    
    fxs_copy(&sb, "dont replace here");
    ReplaceResult res = fxs_replace(&sb, "XX", "BIGGGGGGSTRINGGGGGG");
    assert(fxs_equal(sb, "dont replace here"));
    assert(res.nb_replaced == 0);
    
    fxs_copy(&sb, "hello world");
    fxs_replace_first(&sb, "", "---");
    assert(fxs_equal(sb, "---hello world"));
}

void test_read2()
{
    StrBuf sb = strbuf_init_from_buf((char[64]){});
    
    FILE *f = fopen("files/file", "rb");
    fxs_fread_line(&sb, f);
    println(sb.len, " :: '", sb, "'");
    assert(fxs_equal(sb, "this is the first line\n"));
    unsigned int linelen = fxs_len(sb);
    fxs_append_fread_line(&sb, f);
    assert(fxs_equal(fxs_strv(sb, linelen, sb.len), "no newline here"));
    
    assert(feof(f));
    
    fclose(f);
    
    f = fopen("files/file", "rb");
    
    DStr line = dstr_init();
    
    dstr_fread_line(&line, f);
    assert(fxs_equal(line, "this is the first line\n"));
    
    dstr_append_fread_line(&line, f);
    assert(fxs_equal(line, "this is the first line\nno newline here"));
    
    dstr_deinit(&line);
}

void test_misc()
{
    char *s = "this is my cstr";
    StrBuf sb = strbuf_init_from_buf((char[128]){0});
    for(unsigned i = 0, len = fxs_len(s) ; i < len ; i++)
    {
        fxs_sprint_append(&sb, fxs_at(s, i));
    }
    println("sb == ", sb);
    assert(fxs_equal(sb, "this is my cstr"));
    assert(fxs_equal(sb, s));
    assert(fxs_starts_with(sb, sb));
    assert(fxs_ends_with(sb, sb));
    assert(fxs_starts_with(sb, "this"));
    assert(fxs_ends_with(sb, "cstr"));
    
    StrViewArray split = fxs_split("hello,world", "");
    DStr d = dstr_init();
    fxs_join(&d, split, "-");
    assert(fxs_equal(d, "h-e-l-l-o-,-w-o-r-l-d"));
    
    free(split.strs);
    split = fxs_split("abc", "a");
    
    fxs_join(&d, split, "X");
    assert(fxs_equal(d, "Xbc"));
    
    free(d.chars);
    free(split.strs);
}

void test_sprint()
{
    char C[128] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    
    fxs_sprint(&sb, sb);
    assert(fxs_equal(sb, ""));
    
    fxs_copy(&sb, "WOW");
    fxs_sprint_append(&sb, 5);
    assert(fxs_equal(sb, "WOW5"));
    
    fxs_sprint(&sb, "w", sb, "w", ".");
    assert(fxs_equal(sb, "www."));
    
    fxs_sprint(&sb, "hello", " ", "world", 123);
    assert(fxs_equal(&sb, "hello world123"));
    
    fxs_sprint_append(&sb, sb);
    assert(fxs_equal(sb, "hello world123hello world123"));
    
    fxs_copy(&sb, "hello world123");
    fxs_append(&sb, sb);
    assert(fxs_equal(sb, "hello world123hello world123"));
    
    fxs_copy(&sb, "X-");
    fxs_sprint_append(&sb, sb, sb);
    assert(fxs_equal(sb, "X-X-X-X-"));
    
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
    fxs_sprint(&sb2,signed_char_min, " ", short_min, " ", int_min, " ", long_min, " ", long_long_min, " ", signed_char_max, " ", short_max, " ", int_max, " ", long_max, " "
    , long_long_max, " ",unsigned_short_max, " ", unsigned_int_max, " ", unsigned_long_max, " ", unsigned_long_long_max);
    
    println("sb2 == '", sb2, "'");
    
    assert(fxs_equal(sb2, "-128 -32768 -2147483648 -9223372036854775808 -9223372036854775808 127 32767 2147483647 9223372036854775807 9223372036854775807 65535 4294967295 18446744073709551615 18446744073709551615"));
    
    fxs_sprint(&sb2, 0);
    assert(fxs_equal(sb2, "0"));
    
    unsigned char CC3[3] = {0};
    StrBuf sb3 = strbuf_init_from_buf(CC3);
    fxs_sprint(&sb3, 123456);
    assert(fxs_equal(sb3, "12"));
    fxs_sprint(&sb3, (unsigned long long) 5678);
    assert(fxs_equal(sb3, "56"));
}

void test_insert()
{
    char C[256] = {0};
    StrBuf sb = strbuf_init_from_buf(C);
    
    fxs_insert(&sb, "hello world", 0);
    assert(fxs_equal(sb, "hello world"));
    
    fxs_insert(&sb, ",", 5);
    assert(fxs_equal(sb, "hello, world"));
}

void tests_memmem()
{
    unsigned char h[] = "hello world";
    unsigned char w[] = "world";
    StrView found = fxs_find((h), (w));
    assert(found.len == strlen((char*) w) && found.chars == h + 6);
    
    unsigned char S[] = "-_-_-_-__-_-_";
    StrView found2 = fxs_find((S), ("-__"));
    assert(found2.len == 3 && found2.chars == S + 6);
}

int main()
{
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
