#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define NEAT_STR_SHORT_NAMES
#define NEAT_API static inline
#define NEAT_PRIVATE static inline

#include "neat_str.c"

typedef struct S
{
    float f;
    int i;
} S;

Neat_Error s2str(Neat_Mut_String_Ref dst, S s)
{
    str_print(dst, s.f, " -- ", s.i);
    return (Neat_Error){NEAT_OK};
}

Neat_Error fp2str(Neat_Mut_String_Ref dst, FILE *s)
{
    (void )s;
    str_print(dst, "FILE_PTR");
    return (Neat_Error){NEAT_OK};
}

#define ADD_TOSTR (S, s2str)
#include "neat_str.h"

#define ADD_TOSTR (FILE*, fp2str)
#include "neat_str.h"

typedef struct MyAllocator
{
    Neat_Allocator funcs;
    int allocs;
    int frees;
    int reallocs;
} MyAllocator;

Neat_Allocation myalloc(Neat_Allocator *all, size_t a, size_t n)
{
    (void) a;
    MyAllocator *al = (MyAllocator*) all;
    al->allocs -= 1;
    return (Neat_Allocation){.ptr = malloc(n), .n = n};
}

void mydealloc(Neat_Allocator *all, void *ptr, size_t n)
{
    (void)n;
    MyAllocator *al = (MyAllocator*) all;
    al->frees += 1;
    free(ptr);
}

Neat_Allocation myrealloc(Neat_Allocator *all, void *p, size_t a, size_t n, size_t nn)
{
    (void)n;
    (void)a;
    MyAllocator *al = (MyAllocator*) all;
    al->reallocs += 1;
    return (Neat_Allocation){.ptr = realloc(p, nn), .n = nn};
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
    String_View_Array arr;
    unsigned int cur;
} StrvWalker;

bool expect_sv(String_View sv, void *ctx)
{
    StrvWalker *arr = ctx;
    assert(str_equal(sv, arr->arr.strs[arr->cur]));
    arr->cur += 1;
    return true;
}

void test_split()
{
    str_split_iter("a,b,c", ",", expect_sv, &(StrvWalker){str_view_arr("a","b","c")}); /* ["a","b","c"] */ println(" --- ");
    str_split_iter("abc", ",", expect_sv, &(StrvWalker){str_view_arr("abc")}); /* ["abc"] */ println(" --- ");
    str_split_iter(",", ",", expect_sv, &(StrvWalker){str_view_arr("","")}); /* ["",""] */ println(" --- ");
    str_split_iter("", ",", expect_sv, &(StrvWalker){str_view_arr("")}); /* [""] */ println(" --- ");
    
    str_split_iter(",a,b", ",", expect_sv, &(StrvWalker){str_view_arr("","a","b")}); /* ["","a","b"] */ println(" --- ");
    str_split_iter("a,b,", ",", expect_sv, &(StrvWalker){str_view_arr("a","b","")}); /* ["a","b",""] */ println(" --- ");
    str_split_iter(",a,b,", ",", expect_sv, &(StrvWalker){str_view_arr("","a","b","")}); /* ["","a","b",""] */ println(" --- ");
    
    str_split_iter("a,,b", ",", expect_sv, &(StrvWalker){str_view_arr("a","","b")}); /* ["a","","b"] */ println(" --- ");
    str_split_iter(",,", ",", expect_sv, &(StrvWalker){str_view_arr("","","")}); /* ["","",""] */ println(" --- ");
    str_split_iter("a,,,b", ",", expect_sv, &(StrvWalker){str_view_arr("a","","","b")}); /* ["a","","","b"] */ println(" --- ");
    
    str_split_iter("aaabaaa", "aa", expect_sv, &(StrvWalker){str_view_arr("","ab","a")}); /* ["","ab","a"] */ println(" --- ");
    str_split_iter("aaaa", "aa", expect_sv, &(StrvWalker){str_view_arr("","","")}); /* ["","",""] */ println(" --- ");
    str_split_iter("aaa", "aa", expect_sv, &(StrvWalker){str_view_arr("","a")}); /* ["","a"] */ println(" --- ");
    
    str_split_iter("aabaaab", "aa", expect_sv, &(StrvWalker){str_view_arr("","b","ab")}); /* ["","b","ab"] */ println(" --- ");
    
    str_split_iter("aaaaa", "aaa", expect_sv, &(StrvWalker){str_view_arr("","aa")}); /* ["","aa"] */ println(" --- ");
    str_split_iter("abababa", "aba", expect_sv, &(StrvWalker){str_view_arr("","b","")}); /* ["","b",""] */ println(" --- ");
    
    str_split_iter("hello", "xyz", expect_sv, &(StrvWalker){str_view_arr("hello")}); /* ["hello"] */ println(" --- ");
    str_split_iter("abc", "abc", expect_sv, &(StrvWalker){str_view_arr("","")}); /* ["",""] */ println(" --- ");
    str_split_iter("abcabc", "abc", expect_sv, &(StrvWalker){str_view_arr("","","")}); /* ["","",""] */ println(" --- ");
    
    str_split_iter("a", "aa", expect_sv, &(StrvWalker){str_view_arr("a")}); /* ["a"] */ println(" --- ");
    str_split_iter("", "aa", expect_sv, &(StrvWalker){str_view_arr("")}); /* [""] */ println(" --- ");
    
    str_split_iter("aaaa", "a", expect_sv, &(StrvWalker){str_view_arr("","","","","")}); /* ["","","","",""] */ println(" --- ");
    str_split_iter("a", "a", expect_sv, &(StrvWalker){str_view_arr("","")}); /* ["",""] */ println(" --- ");
    str_split_iter("ba", "a", expect_sv, &(StrvWalker){str_view_arr("b","")}); /* ["b",""] */ println(" --- ");
}


void test_hex()
{
    char C[64] = {0};
    String_Buffer str = strbuf_init_from_buf(C);
    
    // Unsigned char / uint8_t
    tostr(&str, tsfmt((unsigned char)0, 'x'));
    println(str);
    assert(str_equal(str, "0"));
    
    tostr(&str, tsfmt((uint8_t)255, 'x'));
    println(str);
    assert(str_equal(str, "ff"));
    
    // Signed char / int8_t (Two's complement)
    tostr(&str, tsfmt((int8_t)-1, 'x'));
    println(str);
    assert(str_equal(str, "ff"));
    
    tostr(&str, tsfmt((int8_t)-128, 'x')); // SCHAR_MIN
    println(str);
    assert(str_equal(str, "80"));
    
    
    tostr(&str, tsfmt((unsigned short)0xABCD, 'x'));
    println(str);
    assert(str_equal(str, "abcd"));
    
    tostr(&str, tsfmt((int16_t)-2, 'x'));
    println(str);
    assert(str_equal(str, "fffe"));
    
    tostr(&str, tsfmt((uint16_t)65535, 'x')); // USHRT_MAX
    println(str);
    assert(str_equal(str, "ffff"));
    
    tostr(&str, tsfmt(0, 'x'));
    println(str);
    assert(str_equal(str, "0"));
    
    tostr(&str, tsfmt(2147483647, 'x')); // INT_MAX (32-bit)
    println(str);
    assert(str_equal(str, "7fffffff"));
    
    tostr(&str, tsfmt(-1, 'x')); // int -1
    println(str);
    assert(str_equal(str, "ffffffff"));
    
    tostr(&str, tsfmt(0x12345678, 'x'));
    println(str);
    assert(str_equal(str, "12345678"));
    
    tostr(&str, tsfmt(0xFFFFFFFFFFFFFFFFULL, 'x'));
    println(str);
    assert(str_equal(str, "ffffffffffffffff"));
    
    // 64-bit signed
    tostr(&str, tsfmt(-1LL, 'x'));
    println(str);
    assert(str_equal(str, "ffffffffffffffff"));
    
    tostr(&str, tsfmt(9223372036854775807LL, 'x')); // LLONG_MAX
    println(str);
    assert(str_equal(str, "7fffffffffffffff"));
    
    tostr(&str, tsfmt(-9223372036854775807LL - 1LL, 'x')); // LLONG_MIN
    assert(str_equal(str, "8000000000000000"));
    
    println(str);
}

void test_octal()
{
    char C[64] = { 0 };
    String_Buffer str = strbuf_init_from_buf(C);
    
    // --- Basic Positive Tests (Common for all types) ---
    tostr(&str, tsfmt(0, 'o'));
    println(str);
    assert(str_equal(str, "0"));
    
    tostr(&str, tsfmt(10, 'o'));
    println(str);
    assert(str_equal(str, "12"));
    
    tostr(&str, tsfmt(64, 'o'));
    println(str);
    assert(str_equal(str, "100"));
    
    tostr(&str, tsfmt(511, 'o'));
    println(str);
    assert(str_equal(str, "777"));
    
    // --- 8-bit types (int8_t / uint8_t) ---
    tostr(&str, tsfmt((uint8_t)255, 'o'));
    println(str);
    assert(str_equal(str, "377"));
    
    tostr(&str, tsfmt((int8_t)-1, 'o'));
    println(str);
    assert(str_equal(str, "377")); // -1 in 8-bit two's complement
    
    tostr(&str, tsfmt((int8_t)-128, 'o'));
    println(str);
    assert(str_equal(str, "200")); // -128 is 0x80
    
    // --- 16-bit types (int16_t / uint16_t) ---
    tostr(&str, tsfmt((uint16_t)65535, 'o'));
    println(str);
    assert(str_equal(str, "177777"));
    
    tostr(&str, tsfmt((int16_t)-1, 'o'));
    println(str);
    assert(str_equal(str, "177777"));
    
    tostr(&str, tsfmt((int16_t)4096, 'o'));
    println(str);
    assert(str_equal(str, "10000"));
    
    // --- 32-bit types (int32_t / uint32_t) ---
    tostr(&str, tsfmt((uint32_t)4294967295U, 'o'));
    println(str);
    assert(str_equal(str, "37777777777"));
    
    tostr(&str, tsfmt((int32_t)-1, 'o'));
    println(str);
    assert(str_equal(str, "37777777777"));
    
    tostr(&str, tsfmt((int32_t)123456, 'o'));
    println(str);
    assert(str_equal(str, "361100"));
    
    // --- 64-bit types (int64_t / uint64_t) ---
    tostr(&str, tsfmt((uint64_t)18446744073709551615ULL, 'o'));
    println(str);
    assert(str_equal(str, "1777777777777777777777"));
    
    tostr(&str, tsfmt((int64_t)-1, 'o'));
    println(str);
    assert(str_equal(str, "1777777777777777777777"));
    
    tostr(&str, tsfmt((int64_t)0x123456789ABCDEFLL, 'o'));
    println(str);
    assert(str_equal(str, "4432126361152746757"));
    
    // --- Size types (size_t / ssize_t) ---
    tostr(&str, tsfmt((size_t)1024, 'o'));
    println(str);
    assert(str_equal(str, "2000"));
    
    tostr(&str, tsfmt((long long)-2, 'o'));
    println(str);
    // On 64-bit: 1777777777777777777776. On 32-bit: 37777777776.
    // Adjust this assertion if you are testing on a specific architecture.
    #if __SIZEOF_SIZE_T__ == 8
    assert(str_equal(str, "1777777777777777777776"));
    #else
    assert(str_equal(str, "37777777776"));
    #endif
    
    // --- Edge cases for Signed/Unsigned logic ---
    tostr(&str, tsfmt((unsigned char)8, 'o'));
    println(str);
    assert(str_equal(str, "10"));
    
    tostr(&str, tsfmt((long long)0, 'o'));
    println(str);
    assert(str_equal(str, "0"));
}

void test_bin()
{
    String_Buffer str = strbuf_init_from_buf((char[128]){});
    
    // --- uint8_t Tests ---
    
    // Zero should return a single "0"
    tostr(&str, tsfmt((uint8_t)0, 'b'));
    println(str);
    assert(str_equal(str, "0"));
    
    // Single bit (no padding)
    tostr(&str, tsfmt((uint8_t)1, 'b'));
    println(str);
    assert(str_equal(str, "1"));
    
    // Value 10 (binary 1010)
    tostr(&str, tsfmt((uint8_t)10, 'b'));
    println(str);
    assert(str_equal(str, "1010"));
    
    // Max uint8 (255)
    tostr(&str, tsfmt((uint8_t)255, 'b'));
    println(str);
    assert(str_equal(str, "11111111"));
    
    // --- int8_t Tests (Two's Complement) ---
    
    // Negative 1 in 8-bit is 11111111
    tostr(&str, tsfmt((int8_t)-1, 'b'));
    println(str);
    assert(str_equal(str, "11111111"));
    
    // Positive 127 is 01111111, without padding it is seven 1s
    tostr(&str, tsfmt((int8_t)127, 'b'));
    println(str);
    assert(str_equal(str, "1111111"));
    
    // Minimum negative value (-128) is 10000000
    tostr(&str, tsfmt((int8_t)-128, 'b'));
    println(str);
    assert(str_equal(str, "10000000"));
    
    // --- uint16_t Tests ---
    
    // 256 is 1 followed by eight 0s
    tostr(&str, tsfmt((uint16_t)256, 'b'));
    println(str);
    assert(str_equal(str, "100000000"));
    
    // 1024 is 1 followed by ten 0s
    tostr(&str, tsfmt((uint16_t)1024, 'b'));
    println(str);
    assert(str_equal(str, "10000000000"));
    
    // --- int16_t Tests ---
    
    // -2 in 16-bit is 1111111111111110 (15 ones)
    tostr(&str, tsfmt((int16_t)-2, 'b'));
    println(str);
    assert(str_equal(str, "1111111111111110"));
    
    // --- uint32_t Tests ---
    
    // Power of 2 (2^31)
    tostr(&str, tsfmt((uint32_t)0x80000000, 'b'));
    println(str);
    assert(str_equal(str, "10000000000000000000000000000000"));
    
    // A random small value in a large type (checks no padding)
    tostr(&str, tsfmt((uint32_t)42, 'b'));
    println(str);
    assert(str_equal(str, "101010"));
    
    // --- uint64_t Tests ---
    
    // 64-bit Max (64 ones)
    tostr(&str, tsfmt((uint64_t)-1, 'b'));
    println(str);
    assert(str_equal(str, "1111111111111111111111111111111111111111111111111111111111111111"));
    
    // Large 64-bit number (1 followed by 60 zeros)
    tostr(&str, tsfmt((uint64_t)1ULL << 60, 'b'));
    println(str);
    assert(str_equal(str, "1000000000000000000000000000000000000000000000000000000000000"));
}

void test_ffmt()
{
    const float f_eps = 1e-6f;
    const double d_eps = f_eps;
    
    String_Buffer str = strbuf_init_from_buf((char[64]){0});
    float f;
    double d;
    Neat_Error er;
    
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
    DString str = dstr_init();
    
    {
        FILE *f_setup = fopen("test_basic.txt", "wb");
        fputs("hello world\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test_basic.txt", "rb");
        str_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "hello world\n"));
    }
str_clear(&str);
    
    // --- 2. Multi-line Reading ---
    {
        FILE *f_setup = fopen("test_multi.txt", "wb");
        fputs("line one\nline two\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test_multi.txt", "rb");
        
        str_fread_line(&str, f);
        assert(str_equal(str, "line one\n"));
        
        str_fread_line(&str, f);
        assert(str_equal(str, "line two\n"));
        
        fclose(f);
    }
str_clear(&str);
    
    // --- 3. No Trailing Newline ---
    {
        FILE *f_setup = fopen("test_no_nl.txt", "wb");
        fputs("missing newline", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test_no_nl.txt", "rb");
        str_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "missing newline"));
    }
str_clear(&str);
    
    // --- 4. Empty File ---
    {
        FILE *f_setup = fopen("test_empty.txt", "wb");
        fclose(f_setup);
        
        FILE *f = fopen("test_empty.txt", "rb");
        str_fread_line(&str, f);
        fclose(f);
        // Adjust this check based on your API's specific behavior for EOF/empty files
        assert(str_equal(str, "")); 
    }
str_clear(&str);
    
    // --- 5. Windows-style Line Endings (CRLF) ---
    {
        FILE *f_setup = fopen("test_crlf.txt", "wb");
        fputs("windows line\r\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test_crlf.txt", "rb");
        str_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "windows line\r\n"));
    }
str_clear(&str);
    
    // --- 6. Very Long Line (Testing Dynamic Growth) ---
    {
        FILE *f_setup = fopen("test_long.txt", "wb");
        for(int i = 0; i < 5000; i++) fputc('a', f_setup);
        fputc('\n', f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test_long.txt", "rb");
        str_fread_line(&str, f);
        fclose(f);
        
        assert(str_len(str) == 5001);
        assert(str_at(str, 0) == 'a');
        assert(str_at(str, 4999) == 'a');
        assert(str_at(str, 5000) == '\n');
    }
str_clear(&str);
    
    // --- 7. Multiple Consecutive Newlines ---
    {
        FILE *f_setup = fopen("test_newlines.txt", "wb");
        fputs("\n\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test_newlines.txt", "rb");
        
        str_fread_line(&str, f);
        assert(str_equal(str, "\n"));
        
        str_fread_line(&str, f);
        assert(str_equal(str, "\n"));
        
        fclose(f);
        
        str_clear(&str);
    }
    
    
    {
        FILE *f_setup = fopen("test1.txt", "wb");
        fputs("hello\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test1.txt", "rb");
        str_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "hello\n"));
        
        str_clear(&str);
    }
    
    // --- 2. Append to Existing Content ---
    {
        FILE *f_setup = fopen("test2.txt", "wb");
        fputs("world\n", f_setup);
        fclose(f_setup);
        
        str_copy(&str, "hello "); // Manually set initial content
        FILE *f = fopen("test2.txt", "rb");
        str_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "hello world\n"));
        
        str_clear(&str);
    }
    
    // --- 3. Consecutive Appends from Same File ---
    {
        FILE *f_setup = fopen("test3.txt", "wb");
        fputs("line1\nline2\n", f_setup);
        fclose(f_setup);
        
        FILE *f = fopen("test3.txt", "rb");
        str_append_fread_line(&str, f); // Appends "line1\n"
        str_append_fread_line(&str, f); // Appends "line2\n"
        println(str);
        fclose(f);
        assert(str_equal(str, "line1\nline2\n"));
        
        str_clear(&str);
    }
    
    // --- 4. Append No-Newline File to String with Newline ---
    {
        FILE *f_setup = fopen("test4.txt", "wb");
        fputs("part2", f_setup); // No newline at end
        fclose(f_setup);
        
        str_copy(&str, "part1\n");
        FILE *f = fopen("test4.txt", "rb");
        str_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "part1\npart2"));
        
        str_clear(&str);
    }
    
    // --- 5. Append from Empty File (Should change nothing) ---
    {
        FILE *f_setup = fopen("test5.txt", "wb");
        fclose(f_setup);
        
        str_copy(&str, "preserved");
        FILE *f = fopen("test5.txt", "rb");
        str_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "preserved"));
        
        str_clear(&str);
    }
    
    // --- 6. Large Append (Dynamic Memory Stress) ---
    {
        FILE *f_setup = fopen("test6.txt", "wb");
        for(int i = 0; i < 5000; i++) fputc('b', f_setup);
        fputc('\n', f_setup);
        fclose(f_setup);
        
        str_copy(&str, "aaaaa"); 
        FILE *f = fopen("test6.txt", "rb");
        str_append_fread_line(&str, f);
        fclose(f);
        
        assert(str_len(str) == 5006);
        assert(str_at(str, 0) == 'a');
        assert(str_at(str, 5) == 'b');
        assert(str_at(str, 5005) == '\n');
        
        str_clear(&str);
    }
    
    // --- 7. Append CRLF Line ---
    {
        FILE *f_setup = fopen("test7.txt", "wb");
        fputs("dos\r\n", f_setup);
        fclose(f_setup);
        
        str_copy(&str, "unix\n");
        FILE *f = fopen("test7.txt", "rb");
        str_append_fread_line(&str, f);
        println(str);
        fclose(f);
        assert(str_equal(str, "unix\ndos\r\n"));
        
        str_clear(&str);
    }
    
    dstr_deinit(&str);
}

typedef struct S2
{
    char c;
    float f;
} S2;

Neat_Error s22str(Mut_String_Ref dst, S2 s)
{
    str_print(dst, s.c, "--", s.f);
    return (Neat_Error){NEAT_OK};
}

#define ADD_TOSTR (S2, s22str)
#include "neat_str.h"

#include <assert.h>
#define _GNU_SOURCE
#include <string.h>


struct FOO {
    int capacity;
    char drive;
};

Neat_Error foo_to_str(Mut_String_Ref dst, struct FOO f )
{
    str_print(dst, "FOO{ .drive=", f.drive, ":/", ", .capacity=", f.capacity, "}");
    return (Neat_Error){NEAT_OK};
}

struct BAR {
    bool b;
    int i;
};

Neat_Error bar_tostr(Mut_String_Ref str, struct BAR b)
{
    str_print(str, "BAR{ b=", b.b, ", i=", b.i, " }");
    return (Neat_Error){NEAT_OK};
}

#define ADD_TOSTR (struct FOO, foo_to_str)
#include "neat_str.h"

#define ADD_TOSTR (struct BAR, bar_tostr)
#include "neat_str.h"

void test_tostr()
{
    struct FOO a = {.capacity = 15, .drive = 'C'};
    DString a_str = dstr_init();
    tostr(&a_str, a);
    assert(str_equal(a_str, "FOO{ .drive=C:/, .capacity=15}"));
    free(a_str.chars);
    
    char C[128] = {0};
    String_Buffer sb = strbuf_init_from_buf(C);
    struct BAR bar = {.b = false, .i = 25};
    
    str_print(&sb, bar);
    assert(str_equal(sb, "BAR{ b=false, i=25 }"));
}

void test_str_del()
{
    char C[64] = {0};
    String_Buffer str = strbuf_init_from_buf(C);
    str_copy(&str, "hello[DELETE THIS] world");
    
    String_View found = str_find(str, "[DELETE THIS]");
    Neat_Error ok = str_del(&str, found.chars - str.chars, found.chars - str.chars + found.len);
    
    assert(ok.ec == 0);
    assert(str_equal(str, "hello world"));
}

void test_str_count()
{
    String_View str = str_view("aaabccdddd");
    assert(str_count(str, "a") == 3);
    assert(str_count(str, "b") == 1);
    assert(str_count(str, "c") == 2);
    assert(str_count(str, "d") == 4);
    println(str_count("vvv", "vv"));
    assert(str_count("vvv", "vv") == 1);
    assert(str_count(str, "") == 0);
    
    char C[] = "hello world";
    String_Buffer sb = strbuf_init_from_cstr(C);
    unsigned int L = str_len(mutstr_ref("hello world"));
    assert(L == str_len("hello world") && L == strlen("hello world") && L == str_len(sb) && L == str_len(C));
}

void test_str_find()
{
    String_View str = str_view("hello world");
    String_View empty = str_find(str, "");
    
    assert(empty.chars == str.chars && empty.len == 0);
    assert(str_equal(str_find(str, str), str));
    assert((str_find(str, "world").chars - str.chars) == 6);
    assert(str_find(str, "world").len == 5);
    assert(str_find(str, "F").chars == NULL);
}

void test_str_replace()
{
    char C[64] = {0};
    String_Buffer sb = strbuf_init_from_buf(C);
    str_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    Replace_Result replaced = str_replace(&sb, "-", "");
    println("replaced :: ", replaced.nb_replaced);
    assert(str_equal(sb, "hello, world"));
    assert(replaced.nb_replaced == 11);
    
    str_copy(&sb, "hello world");
    replaced = str_replace(&sb, "-", ",");
    assert(str_equal(sb, "hello world"));
    assert(replaced.nb_replaced == 0);
    
    str_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    replaced = str_replace(&sb, "-", "_-_");
    assert(str_equal(sb, "h_-_e_-_l_-_l_-_o_-_,_-_ _-_w_-_o_-_r_-_l_-_d"));
    assert(replaced.nb_replaced == 11);
    
    str_copy(&sb, "h_-_e_-_l_-_l_-_o_-_,_-_ _-_w_-_o_-_r_-_l_-_d");
    replaced = str_replace(&sb, "_-_", "X");
    assert(str_equal(sb, "hXeXlXlXoX,X XwXoXrXlXd"));
    assert(replaced.nb_replaced == 11);
    
    str_copy(&sb, "hello world");
    str_replace(&sb, "", "-");
    assert(str_equal(sb, "-h-e-l-l-o- -w-o-r-l-d-"));
    
    str_copy(&sb, "hello world");
    str_replace(&sb, "", "XX");
    assert(str_equal(sb, "XXhXXeXXlXXlXXoXX XXwXXoXXrXXlXXdXX"));
}

void test_str_replace_first()
{
    char C[64] = {0};
    String_Buffer sb = strbuf_init_from_buf(C);
    str_copy(&sb, "h-e-l-l-o-,- -w-o-r-l-d");
    Neat_Error replaced = str_replace_first(&sb, "-", "");
    assert(str_equal(sb, "he-l-l-o-,- -w-o-r-l-d"));
    assert(replaced.ec != NEAT_NOT_FOUND);
    
    str_copy(&sb, "dont replace here");
    Replace_Result res = str_replace(&sb, "XX", "BIGGGGGGSTRINGGGGGG");
    assert(str_equal(sb, "dont replace here"));
    assert(res.nb_replaced == 0);
    
    str_copy(&sb, "hello world");
    str_replace_first(&sb, "", "---");
    assert(str_equal(sb, "---hello world"));
}

void test_read2()
{
    String_Buffer sb = strbuf_init_from_buf((char[64]){});
    
    FILE *f = fopen("file", "rb");
    str_fread_line(&sb, f);
    println(sb.len, " :: '", sb, "'");
    assert(str_equal(sb, "this is the first line\r\n"));
    unsigned int linelen = str_len(sb);
    str_append_fread_line(&sb, f);
    assert(str_equal(str_view(sb, linelen, sb.len), "no newline here"));
    
    assert(feof(f));
    
    fclose(f);
    free(sb.chars);
    
    f = fopen("file", "r");
    
    DString line = dstr_init();
    
    dstr_fread_line(&line, f);
    assert(str_equal(line, "this is the first line\n"));
    
    dstr_append_fread_line(&line, f);
    assert(str_equal(line, "this is the first line\nno newline here"));
    
    dstr_deinit(&line);
}

void test_misc()
{
    char *s = "this is my cstr";
    String_Buffer sb = strbuf_init_from_buf((char[128]){0});
    for(unsigned i = 0, len = str_len(s) ; i < len ; i++)
    {
        str_print_append(&sb, str_at(s, i));
    }
    println("sb == ", sb);
    assert(str_equal(sb, "this is my cstr"));
    assert(str_equal(sb, s));
    assert(str_starts_with(sb, sb));
    assert(str_ends_with(sb, sb));
    assert(str_starts_with(sb, "this"));
    assert(str_ends_with(sb, "cstr"));
    
    String_View_Array split = str_split("hello,world", "");
    DString d = dstr_init();
    str_join(&d, split, "-");
    assert(str_equal(d, "h-e-l-l-o-,-w-o-r-l-d"));
    
    split = str_split("abc", "a");
    
    str_join(&d, split, "X");
    assert(str_equal(d, "Xbc"));
    
    free(d.chars);
    free(split.strs);
}

void test_sprint()
{
    char C[128] = {0};
    String_Buffer sb = strbuf_init_from_buf(C);
    
    str_print(&sb, sb);
    assert(str_equal(sb, ""));
    
    str_copy(&sb, "WOW");
    str_print_append(&sb, 5);
    assert(str_equal(sb, "WOW5"));
    
    str_print(&sb, "w", sb, "w", ".");
    assert(str_equal(sb, "www."));
    
    str_print(&sb, "hello", " ", "world", 123);
    assert(str_equal(&sb, "hello world123"));
    
    str_print_append(&sb, sb);
    assert(str_equal(sb, "hello world123hello world123"));
    
    str_copy(&sb, "hello world123");
    str_append(&sb, sb);
    assert(str_equal(sb, "hello world123hello world123"));
    
    str_copy(&sb, "X-");
    str_print_append(&sb, sb, sb);
    assert(str_equal(sb, "X-X-X-X-"));
    
    unsigned char CC2[256] = {0};
    String_Buffer sb2 = strbuf_init_from_buf(CC2);
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
    str_print(&sb2,signed_char_min, " ", short_min, " ", int_min, " ", long_min, " ", long_long_min, " ", signed_char_max, " ", short_max, " ", int_max, " ", long_max, " "
    , long_long_max, " ",unsigned_short_max, " ", unsigned_int_max, " ", unsigned_long_max, " ", unsigned_long_long_max);
    
    println("sb2 == '", sb2, "'");
    
    assert(str_equal(sb2, "-128 -32768 -2147483648 -9223372036854775808 -9223372036854775808 127 32767 2147483647 9223372036854775807 9223372036854775807 65535 4294967295 18446744073709551615 18446744073709551615"));
    
    str_print(&sb2, 0);
    assert(str_equal(sb2, "0"));
    
    unsigned char CC3[3] = {0};
    String_Buffer sb3 = strbuf_init_from_buf(CC3);
    str_print(&sb3, 123456);
    assert(str_equal(sb3, "12"));
    str_print(&sb3, (unsigned long long) 5678);
    assert(str_equal(sb3, "56"));
}

void test_insert()
{
    char C[256] = {0};
    String_Buffer sb = strbuf_init_from_buf(C);
    
    str_insert(&sb, "hello world", 0);
    assert(str_equal(sb, "hello world"));
    
    str_insert(&sb, ",", 5);
    assert(str_equal(sb, "hello, world"));
}

void tests_memmem()
{
    unsigned char h[] = "hello world";
    unsigned char w[] = "world";
    String_View found = str_find((h), (w));
    assert(found.len == strlen((char*) w) && found.chars == h + 6);
    
    unsigned char S[] = "-_-_-_-__-_-_";
    String_View found2 = str_find((S), ("-__"));
    assert(found2.len == 3 && found2.chars == S + 6);
}

int main()
{
//     test_tostr();
//     test_str_del();
//     test_str_count();
//     test_str_find();
//     test_str_replace();
//     test_str_replace_first();
//     test_read();
//     test_misc();
//     test_sprint();
//     test_insert();
//     tests_memmem();
//
//     test_bin();
//     test_ffmt();
//     test_octal();
//     test_read2();
//     test_ffmt();
//     test_split();
//     //
//     String_Buffer str = strbuf_init_from_buf((char[512]){});
//
//     int arr[5] = {1,2,3,4,5};
//     tostr(&str, arrfmt((Neat__Integer_b_Fmt_neat__i*) arr, 5, "{\n    ", "\n}", ",\n    ", ","));
//
//     println(str);
//
//     tostr(&str, arrfmt(arr, 5));
//
//     println(str);
//
//     Mut_String_Ref appender = str_appender(&str, &(Neat_Appender_State){0});
//
//     str_append(appender, "---''");
//
//     println(str);
//     println(appender);
//
//     str_commit_appender(&str, appender);
//
//     println(str);
//
//     S2 s2 = {'a', 15.2f};
//     tostr_p(&str, &s2);
//
//     println(str);
    
    int arr[10];
    for(int i = 0 ; i < 10 ; i++)
        arr[i] = rand() % 100;
    println(arrfmt(arr, 10));
}
