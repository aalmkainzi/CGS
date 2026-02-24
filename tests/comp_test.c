/*
 * AUTO-GENERATED compile test for the CGS string library.
 * Run: python3 gen_cgs_compile_test.py > cgs_compile_test.c
 *      gcc -std=c11 -Wall -Wextra -o /dev/null cgs_compile_test.c -lcgs
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CGS_SHORT_NAMES
#include "../cgs.c"

/* ===== strv ===== */
void test_0001(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView r1 = strv(cstr_ptr);
    StrView r2 = strv(cstr_ptr, 1);
    (void)r1; (void)r2;
}

void test_0002(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView r1 = strv(ucstr_ptr);
    StrView r2 = strv(ucstr_ptr, 1);
    (void)r1; (void)r2;
}

void test_0003(void) {
    char cstr_arr[] = "hello";
    StrView r1 = strv(cstr_arr);
    StrView r2 = strv(cstr_arr, 1);
    (void)r1; (void)r2;
}

void test_0004(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView r1 = strv(ucstr_arr);
    StrView r2 = strv(ucstr_arr, 1);
    (void)r1; (void)r2;
}

void test_0005(void) {
    StrView sv = strv("hello");
    StrView r1 = strv(sv);
    StrView r2 = strv(sv, 1);
    (void)r1; (void)r2;
}

void test_0006(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrView r1 = strv(dstr_val);
    StrView r2 = strv(dstr_val, 1);
    (void)r1; (void)r2;
}

void test_0007(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrView r1 = strv(dstr_ptr);
    StrView r2 = strv(dstr_ptr, 1);
    (void)r1; (void)r2;
}

void test_0008(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrView r1 = strv(strbuf_val);
    StrView r2 = strv(strbuf_val, 1);
    (void)r1; (void)r2;
}

void test_0009(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrView r1 = strv(strbuf_ptr);
    StrView r2 = strv(strbuf_ptr, 1);
    (void)r1; (void)r2;
}

void test_0010(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrView r1 = strv(msr);
    StrView r2 = strv(msr, 1);
    (void)r1; (void)r2;
}

/* ===== strbuf_init_from_cstr / strbuf_init_from_buf ===== */
void test_0011(void) {
    char      rp[64] = "hello";  char      ra[] = "hello";
    unsigned char up[64] = {'h',0}; unsigned char ua[] = {'h',0};
    StrBuf s1  = strbuf_init_from_cstr(rp);
    StrBuf s2  = strbuf_init_from_cstr(rp, 64);
    StrBuf s3  = strbuf_init_from_cstr(ra);
    StrBuf s4  = strbuf_init_from_cstr(ra, sizeof(ra));
    StrBuf s5  = strbuf_init_from_cstr(up);
    StrBuf s6  = strbuf_init_from_cstr(up, 64);
    StrBuf s7  = strbuf_init_from_cstr(ua);
    StrBuf s8  = strbuf_init_from_cstr(ua, sizeof(ua));
    StrBuf s9  = strbuf_init_from_buf(rp, 64);
    StrBuf s10 = strbuf_init_from_buf(ra, sizeof(ra));
    StrBuf s11 = strbuf_init_from_buf(up, 64);
    StrBuf s12 = strbuf_init_from_buf(ua, sizeof(ua));
    (void)s1;(void)s2;(void)s3;(void)s4;(void)s5;(void)s6;
    (void)s7;(void)s8;(void)s9;(void)s10;(void)s11;(void)s12;
}

/* ===== dstr_init / dstr_deinit / dstr_shrink_to_fit ===== */
void test_0012(void) {
    DStr d1 = dstr_init();
    DStr d2 = dstr_init(16, NULL);
    dstr_deinit(&d1);
    dstr_deinit(&d2);
}

void test_0013(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr d = dstr_init_from(cstr_ptr, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0014(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr d = dstr_init_from(ucstr_ptr, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0015(void) {
    char cstr_arr[] = "hello";
    DStr d = dstr_init_from(cstr_arr, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0016(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr d = dstr_init_from(ucstr_arr, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0017(void) {
    StrView sv = strv("hello");
    DStr d = dstr_init_from(sv, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0018(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr d = dstr_init_from(dstr_val, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0019(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    DStr d = dstr_init_from(dstr_ptr, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0020(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    DStr d = dstr_init_from(strbuf_val, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0021(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    DStr d = dstr_init_from(strbuf_ptr, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

void test_0022(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    DStr d = dstr_init_from(msr, NULL);
    CGS_Error e = dstr_shrink_to_fit(&d);
    (void)e; dstr_deinit(&d);
}

/* ===== mutstr_ref ===== */
void test_0023(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    MutStrRef ref = mutstr_ref(cstr_ptr);
    (void)ref;
}

void test_0024(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    MutStrRef ref = mutstr_ref(ucstr_ptr);
    (void)ref;
}

void test_0025(void) {
    char cstr_arr[] = "hello";
    MutStrRef ref = mutstr_ref(cstr_arr);
    (void)ref;
}

void test_0026(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    MutStrRef ref = mutstr_ref(ucstr_arr);
    (void)ref;
}

void test_0027(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    MutStrRef ref = mutstr_ref(dstr_ptr);
    (void)ref;
}

void test_0028(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    MutStrRef ref = mutstr_ref(strbuf_ptr);
    (void)ref;
}

void test_0029(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    MutStrRef ref = mutstr_ref(msr);
    (void)ref;
}

/* ===== strv_arr / strv_arr_from_carr ===== */
void test_0030(void) {
    StrViewArray va1 = strv_arr("a", "b", "c");
    StrView items[2] = { strv("x"), strv("y") };
    StrViewArray va2 = strv_arr_from_carr(items, 2);
    StrViewArray va3 = strv_arr_from_carr(items);
    (void)va1; (void)va2; (void)va3;
}

/* ===== single-arg read ops (anystr) ===== */
void test_0031(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned int len = cgs_len(cstr_ptr);
    unsigned int cap = cgs_cap(cstr_ptr);
    char        *ch  = cgs_chars(cstr_ptr);
    (void)len; (void)cap; (void)ch;
}

void test_0032(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned int len = cgs_len(ucstr_ptr);
    unsigned int cap = cgs_cap(ucstr_ptr);
    char        *ch  = cgs_chars(ucstr_ptr);
    (void)len; (void)cap; (void)ch;
}

void test_0033(void) {
    char cstr_arr[] = "hello";
    unsigned int len = cgs_len(cstr_arr);
    unsigned int cap = cgs_cap(cstr_arr);
    char        *ch  = cgs_chars(cstr_arr);
    (void)len; (void)cap; (void)ch;
}

void test_0034(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    unsigned int len = cgs_len(ucstr_arr);
    unsigned int cap = cgs_cap(ucstr_arr);
    char        *ch  = cgs_chars(ucstr_arr);
    (void)len; (void)cap; (void)ch;
}

void test_0035(void) {
    StrView sv = strv("hello");
    unsigned int len = cgs_len(sv);
    unsigned int cap = cgs_cap(sv);
    char        *ch  = cgs_chars(sv);
    (void)len; (void)cap; (void)ch;
}

void test_0036(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    unsigned int len = cgs_len(dstr_val);
    unsigned int cap = cgs_cap(dstr_val);
    char        *ch  = cgs_chars(dstr_val);
    (void)len; (void)cap; (void)ch;
}

void test_0037(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    unsigned int len = cgs_len(dstr_ptr);
    unsigned int cap = cgs_cap(dstr_ptr);
    char        *ch  = cgs_chars(dstr_ptr);
    (void)len; (void)cap; (void)ch;
}

void test_0038(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    unsigned int len = cgs_len(strbuf_val);
    unsigned int cap = cgs_cap(strbuf_val);
    char        *ch  = cgs_chars(strbuf_val);
    (void)len; (void)cap; (void)ch;
}

void test_0039(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    unsigned int len = cgs_len(strbuf_ptr);
    unsigned int cap = cgs_cap(strbuf_ptr);
    char        *ch  = cgs_chars(strbuf_ptr);
    (void)len; (void)cap; (void)ch;
}

void test_0040(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    unsigned int len = cgs_len(msr);
    unsigned int cap = cgs_cap(msr);
    char        *ch  = cgs_chars(msr);
    (void)len; (void)cap; (void)ch;
}

/* ===== two-arg read ops (anystr x anystr) ===== */
void test_0041(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    bool         eq    = cgs_equal(cstr_ptr, cstr_ptr);
    StrView      found = cgs_find(cstr_ptr, cstr_ptr);
    unsigned int cnt   = cgs_count(cstr_ptr, cstr_ptr);
    bool         sw    = cgs_starts_with(cstr_ptr, cstr_ptr);
    bool         ew    = cgs_ends_with(cstr_ptr, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0042(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    bool         eq    = cgs_equal(cstr_ptr, ucstr_ptr);
    StrView      found = cgs_find(cstr_ptr, ucstr_ptr);
    unsigned int cnt   = cgs_count(cstr_ptr, ucstr_ptr);
    bool         sw    = cgs_starts_with(cstr_ptr, ucstr_ptr);
    bool         ew    = cgs_ends_with(cstr_ptr, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0043(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    bool         eq    = cgs_equal(cstr_ptr, cstr_arr);
    StrView      found = cgs_find(cstr_ptr, cstr_arr);
    unsigned int cnt   = cgs_count(cstr_ptr, cstr_arr);
    bool         sw    = cgs_starts_with(cstr_ptr, cstr_arr);
    bool         ew    = cgs_ends_with(cstr_ptr, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0044(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    bool         eq    = cgs_equal(cstr_ptr, ucstr_arr);
    StrView      found = cgs_find(cstr_ptr, ucstr_arr);
    unsigned int cnt   = cgs_count(cstr_ptr, ucstr_arr);
    bool         sw    = cgs_starts_with(cstr_ptr, ucstr_arr);
    bool         ew    = cgs_ends_with(cstr_ptr, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0045(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(cstr_ptr, sv);
    StrView      found = cgs_find(cstr_ptr, sv);
    unsigned int cnt   = cgs_count(cstr_ptr, sv);
    bool         sw    = cgs_starts_with(cstr_ptr, sv);
    bool         ew    = cgs_ends_with(cstr_ptr, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0046(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(cstr_ptr, dstr_val);
    StrView      found = cgs_find(cstr_ptr, dstr_val);
    unsigned int cnt   = cgs_count(cstr_ptr, dstr_val);
    bool         sw    = cgs_starts_with(cstr_ptr, dstr_val);
    bool         ew    = cgs_ends_with(cstr_ptr, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0047(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(cstr_ptr, dstr_ptr);
    StrView      found = cgs_find(cstr_ptr, dstr_ptr);
    unsigned int cnt   = cgs_count(cstr_ptr, dstr_ptr);
    bool         sw    = cgs_starts_with(cstr_ptr, dstr_ptr);
    bool         ew    = cgs_ends_with(cstr_ptr, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0048(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(cstr_ptr, strbuf_val);
    StrView      found = cgs_find(cstr_ptr, strbuf_val);
    unsigned int cnt   = cgs_count(cstr_ptr, strbuf_val);
    bool         sw    = cgs_starts_with(cstr_ptr, strbuf_val);
    bool         ew    = cgs_ends_with(cstr_ptr, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0049(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(cstr_ptr, strbuf_ptr);
    StrView      found = cgs_find(cstr_ptr, strbuf_ptr);
    unsigned int cnt   = cgs_count(cstr_ptr, strbuf_ptr);
    bool         sw    = cgs_starts_with(cstr_ptr, strbuf_ptr);
    bool         ew    = cgs_ends_with(cstr_ptr, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0050(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(cstr_ptr, msr);
    StrView      found = cgs_find(cstr_ptr, msr);
    unsigned int cnt   = cgs_count(cstr_ptr, msr);
    bool         sw    = cgs_starts_with(cstr_ptr, msr);
    bool         ew    = cgs_ends_with(cstr_ptr, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0051(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    bool         eq    = cgs_equal(ucstr_ptr, cstr_ptr);
    StrView      found = cgs_find(ucstr_ptr, cstr_ptr);
    unsigned int cnt   = cgs_count(ucstr_ptr, cstr_ptr);
    bool         sw    = cgs_starts_with(ucstr_ptr, cstr_ptr);
    bool         ew    = cgs_ends_with(ucstr_ptr, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0052(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    bool         eq    = cgs_equal(ucstr_ptr, ucstr_ptr);
    StrView      found = cgs_find(ucstr_ptr, ucstr_ptr);
    unsigned int cnt   = cgs_count(ucstr_ptr, ucstr_ptr);
    bool         sw    = cgs_starts_with(ucstr_ptr, ucstr_ptr);
    bool         ew    = cgs_ends_with(ucstr_ptr, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0053(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    bool         eq    = cgs_equal(ucstr_ptr, cstr_arr);
    StrView      found = cgs_find(ucstr_ptr, cstr_arr);
    unsigned int cnt   = cgs_count(ucstr_ptr, cstr_arr);
    bool         sw    = cgs_starts_with(ucstr_ptr, cstr_arr);
    bool         ew    = cgs_ends_with(ucstr_ptr, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0054(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    bool         eq    = cgs_equal(ucstr_ptr, ucstr_arr);
    StrView      found = cgs_find(ucstr_ptr, ucstr_arr);
    unsigned int cnt   = cgs_count(ucstr_ptr, ucstr_arr);
    bool         sw    = cgs_starts_with(ucstr_ptr, ucstr_arr);
    bool         ew    = cgs_ends_with(ucstr_ptr, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0055(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(ucstr_ptr, sv);
    StrView      found = cgs_find(ucstr_ptr, sv);
    unsigned int cnt   = cgs_count(ucstr_ptr, sv);
    bool         sw    = cgs_starts_with(ucstr_ptr, sv);
    bool         ew    = cgs_ends_with(ucstr_ptr, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0056(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(ucstr_ptr, dstr_val);
    StrView      found = cgs_find(ucstr_ptr, dstr_val);
    unsigned int cnt   = cgs_count(ucstr_ptr, dstr_val);
    bool         sw    = cgs_starts_with(ucstr_ptr, dstr_val);
    bool         ew    = cgs_ends_with(ucstr_ptr, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0057(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(ucstr_ptr, dstr_ptr);
    StrView      found = cgs_find(ucstr_ptr, dstr_ptr);
    unsigned int cnt   = cgs_count(ucstr_ptr, dstr_ptr);
    bool         sw    = cgs_starts_with(ucstr_ptr, dstr_ptr);
    bool         ew    = cgs_ends_with(ucstr_ptr, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0058(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(ucstr_ptr, strbuf_val);
    StrView      found = cgs_find(ucstr_ptr, strbuf_val);
    unsigned int cnt   = cgs_count(ucstr_ptr, strbuf_val);
    bool         sw    = cgs_starts_with(ucstr_ptr, strbuf_val);
    bool         ew    = cgs_ends_with(ucstr_ptr, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0059(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(ucstr_ptr, strbuf_ptr);
    StrView      found = cgs_find(ucstr_ptr, strbuf_ptr);
    unsigned int cnt   = cgs_count(ucstr_ptr, strbuf_ptr);
    bool         sw    = cgs_starts_with(ucstr_ptr, strbuf_ptr);
    bool         ew    = cgs_ends_with(ucstr_ptr, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0060(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(ucstr_ptr, msr);
    StrView      found = cgs_find(ucstr_ptr, msr);
    unsigned int cnt   = cgs_count(ucstr_ptr, msr);
    bool         sw    = cgs_starts_with(ucstr_ptr, msr);
    bool         ew    = cgs_ends_with(ucstr_ptr, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0061(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    bool         eq    = cgs_equal(cstr_arr, cstr_ptr);
    StrView      found = cgs_find(cstr_arr, cstr_ptr);
    unsigned int cnt   = cgs_count(cstr_arr, cstr_ptr);
    bool         sw    = cgs_starts_with(cstr_arr, cstr_ptr);
    bool         ew    = cgs_ends_with(cstr_arr, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0062(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    bool         eq    = cgs_equal(cstr_arr, ucstr_ptr);
    StrView      found = cgs_find(cstr_arr, ucstr_ptr);
    unsigned int cnt   = cgs_count(cstr_arr, ucstr_ptr);
    bool         sw    = cgs_starts_with(cstr_arr, ucstr_ptr);
    bool         ew    = cgs_ends_with(cstr_arr, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0063(void) {
    char cstr_arr[] = "hello";
    bool         eq    = cgs_equal(cstr_arr, cstr_arr);
    StrView      found = cgs_find(cstr_arr, cstr_arr);
    unsigned int cnt   = cgs_count(cstr_arr, cstr_arr);
    bool         sw    = cgs_starts_with(cstr_arr, cstr_arr);
    bool         ew    = cgs_ends_with(cstr_arr, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0064(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    bool         eq    = cgs_equal(cstr_arr, ucstr_arr);
    StrView      found = cgs_find(cstr_arr, ucstr_arr);
    unsigned int cnt   = cgs_count(cstr_arr, ucstr_arr);
    bool         sw    = cgs_starts_with(cstr_arr, ucstr_arr);
    bool         ew    = cgs_ends_with(cstr_arr, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0065(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(cstr_arr, sv);
    StrView      found = cgs_find(cstr_arr, sv);
    unsigned int cnt   = cgs_count(cstr_arr, sv);
    bool         sw    = cgs_starts_with(cstr_arr, sv);
    bool         ew    = cgs_ends_with(cstr_arr, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0066(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(cstr_arr, dstr_val);
    StrView      found = cgs_find(cstr_arr, dstr_val);
    unsigned int cnt   = cgs_count(cstr_arr, dstr_val);
    bool         sw    = cgs_starts_with(cstr_arr, dstr_val);
    bool         ew    = cgs_ends_with(cstr_arr, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0067(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(cstr_arr, dstr_ptr);
    StrView      found = cgs_find(cstr_arr, dstr_ptr);
    unsigned int cnt   = cgs_count(cstr_arr, dstr_ptr);
    bool         sw    = cgs_starts_with(cstr_arr, dstr_ptr);
    bool         ew    = cgs_ends_with(cstr_arr, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0068(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(cstr_arr, strbuf_val);
    StrView      found = cgs_find(cstr_arr, strbuf_val);
    unsigned int cnt   = cgs_count(cstr_arr, strbuf_val);
    bool         sw    = cgs_starts_with(cstr_arr, strbuf_val);
    bool         ew    = cgs_ends_with(cstr_arr, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0069(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(cstr_arr, strbuf_ptr);
    StrView      found = cgs_find(cstr_arr, strbuf_ptr);
    unsigned int cnt   = cgs_count(cstr_arr, strbuf_ptr);
    bool         sw    = cgs_starts_with(cstr_arr, strbuf_ptr);
    bool         ew    = cgs_ends_with(cstr_arr, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0070(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(cstr_arr, msr);
    StrView      found = cgs_find(cstr_arr, msr);
    unsigned int cnt   = cgs_count(cstr_arr, msr);
    bool         sw    = cgs_starts_with(cstr_arr, msr);
    bool         ew    = cgs_ends_with(cstr_arr, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0071(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    bool         eq    = cgs_equal(ucstr_arr, cstr_ptr);
    StrView      found = cgs_find(ucstr_arr, cstr_ptr);
    unsigned int cnt   = cgs_count(ucstr_arr, cstr_ptr);
    bool         sw    = cgs_starts_with(ucstr_arr, cstr_ptr);
    bool         ew    = cgs_ends_with(ucstr_arr, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0072(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    bool         eq    = cgs_equal(ucstr_arr, ucstr_ptr);
    StrView      found = cgs_find(ucstr_arr, ucstr_ptr);
    unsigned int cnt   = cgs_count(ucstr_arr, ucstr_ptr);
    bool         sw    = cgs_starts_with(ucstr_arr, ucstr_ptr);
    bool         ew    = cgs_ends_with(ucstr_arr, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0073(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    bool         eq    = cgs_equal(ucstr_arr, cstr_arr);
    StrView      found = cgs_find(ucstr_arr, cstr_arr);
    unsigned int cnt   = cgs_count(ucstr_arr, cstr_arr);
    bool         sw    = cgs_starts_with(ucstr_arr, cstr_arr);
    bool         ew    = cgs_ends_with(ucstr_arr, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0074(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    bool         eq    = cgs_equal(ucstr_arr, ucstr_arr);
    StrView      found = cgs_find(ucstr_arr, ucstr_arr);
    unsigned int cnt   = cgs_count(ucstr_arr, ucstr_arr);
    bool         sw    = cgs_starts_with(ucstr_arr, ucstr_arr);
    bool         ew    = cgs_ends_with(ucstr_arr, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0075(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(ucstr_arr, sv);
    StrView      found = cgs_find(ucstr_arr, sv);
    unsigned int cnt   = cgs_count(ucstr_arr, sv);
    bool         sw    = cgs_starts_with(ucstr_arr, sv);
    bool         ew    = cgs_ends_with(ucstr_arr, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0076(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(ucstr_arr, dstr_val);
    StrView      found = cgs_find(ucstr_arr, dstr_val);
    unsigned int cnt   = cgs_count(ucstr_arr, dstr_val);
    bool         sw    = cgs_starts_with(ucstr_arr, dstr_val);
    bool         ew    = cgs_ends_with(ucstr_arr, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0077(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(ucstr_arr, dstr_ptr);
    StrView      found = cgs_find(ucstr_arr, dstr_ptr);
    unsigned int cnt   = cgs_count(ucstr_arr, dstr_ptr);
    bool         sw    = cgs_starts_with(ucstr_arr, dstr_ptr);
    bool         ew    = cgs_ends_with(ucstr_arr, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0078(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(ucstr_arr, strbuf_val);
    StrView      found = cgs_find(ucstr_arr, strbuf_val);
    unsigned int cnt   = cgs_count(ucstr_arr, strbuf_val);
    bool         sw    = cgs_starts_with(ucstr_arr, strbuf_val);
    bool         ew    = cgs_ends_with(ucstr_arr, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0079(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(ucstr_arr, strbuf_ptr);
    StrView      found = cgs_find(ucstr_arr, strbuf_ptr);
    unsigned int cnt   = cgs_count(ucstr_arr, strbuf_ptr);
    bool         sw    = cgs_starts_with(ucstr_arr, strbuf_ptr);
    bool         ew    = cgs_ends_with(ucstr_arr, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0080(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(ucstr_arr, msr);
    StrView      found = cgs_find(ucstr_arr, msr);
    unsigned int cnt   = cgs_count(ucstr_arr, msr);
    bool         sw    = cgs_starts_with(ucstr_arr, msr);
    bool         ew    = cgs_ends_with(ucstr_arr, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0081(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(sv, cstr_ptr);
    StrView      found = cgs_find(sv, cstr_ptr);
    unsigned int cnt   = cgs_count(sv, cstr_ptr);
    bool         sw    = cgs_starts_with(sv, cstr_ptr);
    bool         ew    = cgs_ends_with(sv, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0082(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(sv, ucstr_ptr);
    StrView      found = cgs_find(sv, ucstr_ptr);
    unsigned int cnt   = cgs_count(sv, ucstr_ptr);
    bool         sw    = cgs_starts_with(sv, ucstr_ptr);
    bool         ew    = cgs_ends_with(sv, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0083(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(sv, cstr_arr);
    StrView      found = cgs_find(sv, cstr_arr);
    unsigned int cnt   = cgs_count(sv, cstr_arr);
    bool         sw    = cgs_starts_with(sv, cstr_arr);
    bool         ew    = cgs_ends_with(sv, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0084(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(sv, ucstr_arr);
    StrView      found = cgs_find(sv, ucstr_arr);
    unsigned int cnt   = cgs_count(sv, ucstr_arr);
    bool         sw    = cgs_starts_with(sv, ucstr_arr);
    bool         ew    = cgs_ends_with(sv, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0085(void) {
    StrView sv = strv("hello");
    bool         eq    = cgs_equal(sv, sv);
    StrView      found = cgs_find(sv, sv);
    unsigned int cnt   = cgs_count(sv, sv);
    bool         sw    = cgs_starts_with(sv, sv);
    bool         ew    = cgs_ends_with(sv, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0086(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(sv, dstr_val);
    StrView      found = cgs_find(sv, dstr_val);
    unsigned int cnt   = cgs_count(sv, dstr_val);
    bool         sw    = cgs_starts_with(sv, dstr_val);
    bool         ew    = cgs_ends_with(sv, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0087(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(sv, dstr_ptr);
    StrView      found = cgs_find(sv, dstr_ptr);
    unsigned int cnt   = cgs_count(sv, dstr_ptr);
    bool         sw    = cgs_starts_with(sv, dstr_ptr);
    bool         ew    = cgs_ends_with(sv, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0088(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(sv, strbuf_val);
    StrView      found = cgs_find(sv, strbuf_val);
    unsigned int cnt   = cgs_count(sv, strbuf_val);
    bool         sw    = cgs_starts_with(sv, strbuf_val);
    bool         ew    = cgs_ends_with(sv, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0089(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(sv, strbuf_ptr);
    StrView      found = cgs_find(sv, strbuf_ptr);
    unsigned int cnt   = cgs_count(sv, strbuf_ptr);
    bool         sw    = cgs_starts_with(sv, strbuf_ptr);
    bool         ew    = cgs_ends_with(sv, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0090(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(sv, msr);
    StrView      found = cgs_find(sv, msr);
    unsigned int cnt   = cgs_count(sv, msr);
    bool         sw    = cgs_starts_with(sv, msr);
    bool         ew    = cgs_ends_with(sv, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0091(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(dstr_val, cstr_ptr);
    StrView      found = cgs_find(dstr_val, cstr_ptr);
    unsigned int cnt   = cgs_count(dstr_val, cstr_ptr);
    bool         sw    = cgs_starts_with(dstr_val, cstr_ptr);
    bool         ew    = cgs_ends_with(dstr_val, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0092(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(dstr_val, ucstr_ptr);
    StrView      found = cgs_find(dstr_val, ucstr_ptr);
    unsigned int cnt   = cgs_count(dstr_val, ucstr_ptr);
    bool         sw    = cgs_starts_with(dstr_val, ucstr_ptr);
    bool         ew    = cgs_ends_with(dstr_val, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0093(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(dstr_val, cstr_arr);
    StrView      found = cgs_find(dstr_val, cstr_arr);
    unsigned int cnt   = cgs_count(dstr_val, cstr_arr);
    bool         sw    = cgs_starts_with(dstr_val, cstr_arr);
    bool         ew    = cgs_ends_with(dstr_val, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0094(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(dstr_val, ucstr_arr);
    StrView      found = cgs_find(dstr_val, ucstr_arr);
    unsigned int cnt   = cgs_count(dstr_val, ucstr_arr);
    bool         sw    = cgs_starts_with(dstr_val, ucstr_arr);
    bool         ew    = cgs_ends_with(dstr_val, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0095(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(dstr_val, sv);
    StrView      found = cgs_find(dstr_val, sv);
    unsigned int cnt   = cgs_count(dstr_val, sv);
    bool         sw    = cgs_starts_with(dstr_val, sv);
    bool         ew    = cgs_ends_with(dstr_val, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0096(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    bool         eq    = cgs_equal(dstr_val, dstr_val);
    StrView      found = cgs_find(dstr_val, dstr_val);
    unsigned int cnt   = cgs_count(dstr_val, dstr_val);
    bool         sw    = cgs_starts_with(dstr_val, dstr_val);
    bool         ew    = cgs_ends_with(dstr_val, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0097(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_val, dstr_ptr);
    StrView      found = cgs_find(dstr_val, dstr_ptr);
    unsigned int cnt   = cgs_count(dstr_val, dstr_ptr);
    bool         sw    = cgs_starts_with(dstr_val, dstr_ptr);
    bool         ew    = cgs_ends_with(dstr_val, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0098(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(dstr_val, strbuf_val);
    StrView      found = cgs_find(dstr_val, strbuf_val);
    unsigned int cnt   = cgs_count(dstr_val, strbuf_val);
    bool         sw    = cgs_starts_with(dstr_val, strbuf_val);
    bool         ew    = cgs_ends_with(dstr_val, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0099(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(dstr_val, strbuf_ptr);
    StrView      found = cgs_find(dstr_val, strbuf_ptr);
    unsigned int cnt   = cgs_count(dstr_val, strbuf_ptr);
    bool         sw    = cgs_starts_with(dstr_val, strbuf_ptr);
    bool         ew    = cgs_ends_with(dstr_val, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0100(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(dstr_val, msr);
    StrView      found = cgs_find(dstr_val, msr);
    unsigned int cnt   = cgs_count(dstr_val, msr);
    bool         sw    = cgs_starts_with(dstr_val, msr);
    bool         ew    = cgs_ends_with(dstr_val, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0101(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, cstr_ptr);
    StrView      found = cgs_find(dstr_ptr, cstr_ptr);
    unsigned int cnt   = cgs_count(dstr_ptr, cstr_ptr);
    bool         sw    = cgs_starts_with(dstr_ptr, cstr_ptr);
    bool         ew    = cgs_ends_with(dstr_ptr, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0102(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, ucstr_ptr);
    StrView      found = cgs_find(dstr_ptr, ucstr_ptr);
    unsigned int cnt   = cgs_count(dstr_ptr, ucstr_ptr);
    bool         sw    = cgs_starts_with(dstr_ptr, ucstr_ptr);
    bool         ew    = cgs_ends_with(dstr_ptr, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0103(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, cstr_arr);
    StrView      found = cgs_find(dstr_ptr, cstr_arr);
    unsigned int cnt   = cgs_count(dstr_ptr, cstr_arr);
    bool         sw    = cgs_starts_with(dstr_ptr, cstr_arr);
    bool         ew    = cgs_ends_with(dstr_ptr, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0104(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, ucstr_arr);
    StrView      found = cgs_find(dstr_ptr, ucstr_arr);
    unsigned int cnt   = cgs_count(dstr_ptr, ucstr_arr);
    bool         sw    = cgs_starts_with(dstr_ptr, ucstr_arr);
    bool         ew    = cgs_ends_with(dstr_ptr, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0105(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, sv);
    StrView      found = cgs_find(dstr_ptr, sv);
    unsigned int cnt   = cgs_count(dstr_ptr, sv);
    bool         sw    = cgs_starts_with(dstr_ptr, sv);
    bool         ew    = cgs_ends_with(dstr_ptr, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0106(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, dstr_val);
    StrView      found = cgs_find(dstr_ptr, dstr_val);
    unsigned int cnt   = cgs_count(dstr_ptr, dstr_val);
    bool         sw    = cgs_starts_with(dstr_ptr, dstr_val);
    bool         ew    = cgs_ends_with(dstr_ptr, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0107(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, dstr_ptr);
    StrView      found = cgs_find(dstr_ptr, dstr_ptr);
    unsigned int cnt   = cgs_count(dstr_ptr, dstr_ptr);
    bool         sw    = cgs_starts_with(dstr_ptr, dstr_ptr);
    bool         ew    = cgs_ends_with(dstr_ptr, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0108(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(dstr_ptr, strbuf_val);
    StrView      found = cgs_find(dstr_ptr, strbuf_val);
    unsigned int cnt   = cgs_count(dstr_ptr, strbuf_val);
    bool         sw    = cgs_starts_with(dstr_ptr, strbuf_val);
    bool         ew    = cgs_ends_with(dstr_ptr, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0109(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(dstr_ptr, strbuf_ptr);
    StrView      found = cgs_find(dstr_ptr, strbuf_ptr);
    unsigned int cnt   = cgs_count(dstr_ptr, strbuf_ptr);
    bool         sw    = cgs_starts_with(dstr_ptr, strbuf_ptr);
    bool         ew    = cgs_ends_with(dstr_ptr, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0110(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(dstr_ptr, msr);
    StrView      found = cgs_find(dstr_ptr, msr);
    unsigned int cnt   = cgs_count(dstr_ptr, msr);
    bool         sw    = cgs_starts_with(dstr_ptr, msr);
    bool         ew    = cgs_ends_with(dstr_ptr, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0111(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, cstr_ptr);
    StrView      found = cgs_find(strbuf_val, cstr_ptr);
    unsigned int cnt   = cgs_count(strbuf_val, cstr_ptr);
    bool         sw    = cgs_starts_with(strbuf_val, cstr_ptr);
    bool         ew    = cgs_ends_with(strbuf_val, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0112(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, ucstr_ptr);
    StrView      found = cgs_find(strbuf_val, ucstr_ptr);
    unsigned int cnt   = cgs_count(strbuf_val, ucstr_ptr);
    bool         sw    = cgs_starts_with(strbuf_val, ucstr_ptr);
    bool         ew    = cgs_ends_with(strbuf_val, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0113(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, cstr_arr);
    StrView      found = cgs_find(strbuf_val, cstr_arr);
    unsigned int cnt   = cgs_count(strbuf_val, cstr_arr);
    bool         sw    = cgs_starts_with(strbuf_val, cstr_arr);
    bool         ew    = cgs_ends_with(strbuf_val, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0114(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, ucstr_arr);
    StrView      found = cgs_find(strbuf_val, ucstr_arr);
    unsigned int cnt   = cgs_count(strbuf_val, ucstr_arr);
    bool         sw    = cgs_starts_with(strbuf_val, ucstr_arr);
    bool         ew    = cgs_ends_with(strbuf_val, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0115(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, sv);
    StrView      found = cgs_find(strbuf_val, sv);
    unsigned int cnt   = cgs_count(strbuf_val, sv);
    bool         sw    = cgs_starts_with(strbuf_val, sv);
    bool         ew    = cgs_ends_with(strbuf_val, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0116(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, dstr_val);
    StrView      found = cgs_find(strbuf_val, dstr_val);
    unsigned int cnt   = cgs_count(strbuf_val, dstr_val);
    bool         sw    = cgs_starts_with(strbuf_val, dstr_val);
    bool         ew    = cgs_ends_with(strbuf_val, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0117(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, dstr_ptr);
    StrView      found = cgs_find(strbuf_val, dstr_ptr);
    unsigned int cnt   = cgs_count(strbuf_val, dstr_ptr);
    bool         sw    = cgs_starts_with(strbuf_val, dstr_ptr);
    bool         ew    = cgs_ends_with(strbuf_val, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0118(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    bool         eq    = cgs_equal(strbuf_val, strbuf_val);
    StrView      found = cgs_find(strbuf_val, strbuf_val);
    unsigned int cnt   = cgs_count(strbuf_val, strbuf_val);
    bool         sw    = cgs_starts_with(strbuf_val, strbuf_val);
    bool         ew    = cgs_ends_with(strbuf_val, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0119(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_val, strbuf_ptr);
    StrView      found = cgs_find(strbuf_val, strbuf_ptr);
    unsigned int cnt   = cgs_count(strbuf_val, strbuf_ptr);
    bool         sw    = cgs_starts_with(strbuf_val, strbuf_ptr);
    bool         ew    = cgs_ends_with(strbuf_val, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0120(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(strbuf_val, msr);
    StrView      found = cgs_find(strbuf_val, msr);
    unsigned int cnt   = cgs_count(strbuf_val, msr);
    bool         sw    = cgs_starts_with(strbuf_val, msr);
    bool         ew    = cgs_ends_with(strbuf_val, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0121(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, cstr_ptr);
    StrView      found = cgs_find(strbuf_ptr, cstr_ptr);
    unsigned int cnt   = cgs_count(strbuf_ptr, cstr_ptr);
    bool         sw    = cgs_starts_with(strbuf_ptr, cstr_ptr);
    bool         ew    = cgs_ends_with(strbuf_ptr, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0122(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, ucstr_ptr);
    StrView      found = cgs_find(strbuf_ptr, ucstr_ptr);
    unsigned int cnt   = cgs_count(strbuf_ptr, ucstr_ptr);
    bool         sw    = cgs_starts_with(strbuf_ptr, ucstr_ptr);
    bool         ew    = cgs_ends_with(strbuf_ptr, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0123(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, cstr_arr);
    StrView      found = cgs_find(strbuf_ptr, cstr_arr);
    unsigned int cnt   = cgs_count(strbuf_ptr, cstr_arr);
    bool         sw    = cgs_starts_with(strbuf_ptr, cstr_arr);
    bool         ew    = cgs_ends_with(strbuf_ptr, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0124(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, ucstr_arr);
    StrView      found = cgs_find(strbuf_ptr, ucstr_arr);
    unsigned int cnt   = cgs_count(strbuf_ptr, ucstr_arr);
    bool         sw    = cgs_starts_with(strbuf_ptr, ucstr_arr);
    bool         ew    = cgs_ends_with(strbuf_ptr, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0125(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, sv);
    StrView      found = cgs_find(strbuf_ptr, sv);
    unsigned int cnt   = cgs_count(strbuf_ptr, sv);
    bool         sw    = cgs_starts_with(strbuf_ptr, sv);
    bool         ew    = cgs_ends_with(strbuf_ptr, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0126(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, dstr_val);
    StrView      found = cgs_find(strbuf_ptr, dstr_val);
    unsigned int cnt   = cgs_count(strbuf_ptr, dstr_val);
    bool         sw    = cgs_starts_with(strbuf_ptr, dstr_val);
    bool         ew    = cgs_ends_with(strbuf_ptr, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0127(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, dstr_ptr);
    StrView      found = cgs_find(strbuf_ptr, dstr_ptr);
    unsigned int cnt   = cgs_count(strbuf_ptr, dstr_ptr);
    bool         sw    = cgs_starts_with(strbuf_ptr, dstr_ptr);
    bool         ew    = cgs_ends_with(strbuf_ptr, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0128(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, strbuf_val);
    StrView      found = cgs_find(strbuf_ptr, strbuf_val);
    unsigned int cnt   = cgs_count(strbuf_ptr, strbuf_val);
    bool         sw    = cgs_starts_with(strbuf_ptr, strbuf_val);
    bool         ew    = cgs_ends_with(strbuf_ptr, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0129(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    bool         eq    = cgs_equal(strbuf_ptr, strbuf_ptr);
    StrView      found = cgs_find(strbuf_ptr, strbuf_ptr);
    unsigned int cnt   = cgs_count(strbuf_ptr, strbuf_ptr);
    bool         sw    = cgs_starts_with(strbuf_ptr, strbuf_ptr);
    bool         ew    = cgs_ends_with(strbuf_ptr, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0130(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(strbuf_ptr, msr);
    StrView      found = cgs_find(strbuf_ptr, msr);
    unsigned int cnt   = cgs_count(strbuf_ptr, msr);
    bool         sw    = cgs_starts_with(strbuf_ptr, msr);
    bool         ew    = cgs_ends_with(strbuf_ptr, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0131(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, cstr_ptr);
    StrView      found = cgs_find(msr, cstr_ptr);
    unsigned int cnt   = cgs_count(msr, cstr_ptr);
    bool         sw    = cgs_starts_with(msr, cstr_ptr);
    bool         ew    = cgs_ends_with(msr, cstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0132(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, ucstr_ptr);
    StrView      found = cgs_find(msr, ucstr_ptr);
    unsigned int cnt   = cgs_count(msr, ucstr_ptr);
    bool         sw    = cgs_starts_with(msr, ucstr_ptr);
    bool         ew    = cgs_ends_with(msr, ucstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0133(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, cstr_arr);
    StrView      found = cgs_find(msr, cstr_arr);
    unsigned int cnt   = cgs_count(msr, cstr_arr);
    bool         sw    = cgs_starts_with(msr, cstr_arr);
    bool         ew    = cgs_ends_with(msr, cstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0134(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, ucstr_arr);
    StrView      found = cgs_find(msr, ucstr_arr);
    unsigned int cnt   = cgs_count(msr, ucstr_arr);
    bool         sw    = cgs_starts_with(msr, ucstr_arr);
    bool         ew    = cgs_ends_with(msr, ucstr_arr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0135(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, sv);
    StrView      found = cgs_find(msr, sv);
    unsigned int cnt   = cgs_count(msr, sv);
    bool         sw    = cgs_starts_with(msr, sv);
    bool         ew    = cgs_ends_with(msr, sv);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0136(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, dstr_val);
    StrView      found = cgs_find(msr, dstr_val);
    unsigned int cnt   = cgs_count(msr, dstr_val);
    bool         sw    = cgs_starts_with(msr, dstr_val);
    bool         ew    = cgs_ends_with(msr, dstr_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0137(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, dstr_ptr);
    StrView      found = cgs_find(msr, dstr_ptr);
    unsigned int cnt   = cgs_count(msr, dstr_ptr);
    bool         sw    = cgs_starts_with(msr, dstr_ptr);
    bool         ew    = cgs_ends_with(msr, dstr_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0138(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, strbuf_val);
    StrView      found = cgs_find(msr, strbuf_val);
    unsigned int cnt   = cgs_count(msr, strbuf_val);
    bool         sw    = cgs_starts_with(msr, strbuf_val);
    bool         ew    = cgs_ends_with(msr, strbuf_val);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0139(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, strbuf_ptr);
    StrView      found = cgs_find(msr, strbuf_ptr);
    unsigned int cnt   = cgs_count(msr, strbuf_ptr);
    bool         sw    = cgs_starts_with(msr, strbuf_ptr);
    bool         ew    = cgs_ends_with(msr, strbuf_ptr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

void test_0140(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    bool         eq    = cgs_equal(msr, msr);
    StrView      found = cgs_find(msr, msr);
    unsigned int cnt   = cgs_count(msr, msr);
    bool         sw    = cgs_starts_with(msr, msr);
    bool         ew    = cgs_ends_with(msr, msr);
    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;
}

/* ===== cgs_clear / cgs_tolower / cgs_toupper / cgs_putc (mutstr) ===== */
void test_0141(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e1 = cgs_clear(cstr_ptr);
    cgs_tolower(cstr_ptr);
    cgs_toupper(cstr_ptr);
    CGS_Error e2 = cgs_putc(cstr_ptr, 'x');
    (void)e1; (void)e2;
}

void test_0142(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e1 = cgs_clear(ucstr_ptr);
    cgs_tolower(ucstr_ptr);
    cgs_toupper(ucstr_ptr);
    CGS_Error e2 = cgs_putc(ucstr_ptr, 'x');
    (void)e1; (void)e2;
}

void test_0143(void) {
    char cstr_arr[] = "hello";
    CGS_Error e1 = cgs_clear(cstr_arr);
    cgs_tolower(cstr_arr);
    cgs_toupper(cstr_arr);
    CGS_Error e2 = cgs_putc(cstr_arr, 'x');
    (void)e1; (void)e2;
}

void test_0144(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_clear(ucstr_arr);
    cgs_tolower(ucstr_arr);
    cgs_toupper(ucstr_arr);
    CGS_Error e2 = cgs_putc(ucstr_arr, 'x');
    (void)e1; (void)e2;
}

void test_0145(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_clear(dstr_ptr);
    cgs_tolower(dstr_ptr);
    cgs_toupper(dstr_ptr);
    CGS_Error e2 = cgs_putc(dstr_ptr, 'x');
    (void)e1; (void)e2;
}

void test_0146(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_clear(strbuf_ptr);
    cgs_tolower(strbuf_ptr);
    cgs_toupper(strbuf_ptr);
    CGS_Error e2 = cgs_putc(strbuf_ptr, 'x');
    (void)e1; (void)e2;
}

void test_0147(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_clear(msr);
    cgs_tolower(msr);
    cgs_toupper(msr);
    CGS_Error e2 = cgs_putc(msr, 'x');
    (void)e1; (void)e2;
}

/* ===== cgs_map_chars (mutstr x callback) ===== */
static bool map_chars_cb(char *c, void *arg) { (void)c; (void)arg; return true; }
void test_0148(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e = cgs_map_chars(cstr_ptr, map_chars_cb, NULL);
    (void)e;
}

void test_0149(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_map_chars(ucstr_ptr, map_chars_cb, NULL);
    (void)e;
}

void test_0150(void) {
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_map_chars(cstr_arr, map_chars_cb, NULL);
    (void)e;
}

void test_0151(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_map_chars(ucstr_arr, map_chars_cb, NULL);
    (void)e;
}

void test_0152(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_map_chars(dstr_ptr, map_chars_cb, NULL);
    (void)e;
}

void test_0153(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_map_chars(strbuf_ptr, map_chars_cb, NULL);
    (void)e;
}

void test_0154(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_map_chars(msr, map_chars_cb, NULL);
    (void)e;
}

/* ===== cgs_copy / cgs_append / cgs_prepend (mutstr x anystr) ===== */
void test_0155(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e1 = cgs_copy(cstr_ptr, cstr_ptr);
    CGS_Error e2 = cgs_append(cstr_ptr, cstr_ptr);
    CGS_Error e3 = cgs_prepend(cstr_ptr, cstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0156(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e1 = cgs_copy(cstr_ptr, ucstr_ptr);
    CGS_Error e2 = cgs_append(cstr_ptr, ucstr_ptr);
    CGS_Error e3 = cgs_prepend(cstr_ptr, ucstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0157(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e1 = cgs_copy(cstr_ptr, cstr_arr);
    CGS_Error e2 = cgs_append(cstr_ptr, cstr_arr);
    CGS_Error e3 = cgs_prepend(cstr_ptr, cstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0158(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_copy(cstr_ptr, ucstr_arr);
    CGS_Error e2 = cgs_append(cstr_ptr, ucstr_arr);
    CGS_Error e3 = cgs_prepend(cstr_ptr, ucstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0159(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e1 = cgs_copy(cstr_ptr, sv);
    CGS_Error e2 = cgs_append(cstr_ptr, sv);
    CGS_Error e3 = cgs_prepend(cstr_ptr, sv);
    (void)e1; (void)e2; (void)e3;
}

void test_0160(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e1 = cgs_copy(cstr_ptr, dstr_val);
    CGS_Error e2 = cgs_append(cstr_ptr, dstr_val);
    CGS_Error e3 = cgs_prepend(cstr_ptr, dstr_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0161(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(cstr_ptr, dstr_ptr);
    CGS_Error e2 = cgs_append(cstr_ptr, dstr_ptr);
    CGS_Error e3 = cgs_prepend(cstr_ptr, dstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0162(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e1 = cgs_copy(cstr_ptr, strbuf_val);
    CGS_Error e2 = cgs_append(cstr_ptr, strbuf_val);
    CGS_Error e3 = cgs_prepend(cstr_ptr, strbuf_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0163(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(cstr_ptr, strbuf_ptr);
    CGS_Error e2 = cgs_append(cstr_ptr, strbuf_ptr);
    CGS_Error e3 = cgs_prepend(cstr_ptr, strbuf_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0164(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(cstr_ptr, msr);
    CGS_Error e2 = cgs_append(cstr_ptr, msr);
    CGS_Error e3 = cgs_prepend(cstr_ptr, msr);
    (void)e1; (void)e2; (void)e3;
}

void test_0165(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e1 = cgs_copy(ucstr_ptr, cstr_ptr);
    CGS_Error e2 = cgs_append(ucstr_ptr, cstr_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, cstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0166(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e1 = cgs_copy(ucstr_ptr, ucstr_ptr);
    CGS_Error e2 = cgs_append(ucstr_ptr, ucstr_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, ucstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0167(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e1 = cgs_copy(ucstr_ptr, cstr_arr);
    CGS_Error e2 = cgs_append(ucstr_ptr, cstr_arr);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, cstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0168(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_copy(ucstr_ptr, ucstr_arr);
    CGS_Error e2 = cgs_append(ucstr_ptr, ucstr_arr);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, ucstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0169(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e1 = cgs_copy(ucstr_ptr, sv);
    CGS_Error e2 = cgs_append(ucstr_ptr, sv);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, sv);
    (void)e1; (void)e2; (void)e3;
}

void test_0170(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e1 = cgs_copy(ucstr_ptr, dstr_val);
    CGS_Error e2 = cgs_append(ucstr_ptr, dstr_val);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, dstr_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0171(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(ucstr_ptr, dstr_ptr);
    CGS_Error e2 = cgs_append(ucstr_ptr, dstr_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, dstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0172(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e1 = cgs_copy(ucstr_ptr, strbuf_val);
    CGS_Error e2 = cgs_append(ucstr_ptr, strbuf_val);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, strbuf_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0173(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(ucstr_ptr, strbuf_ptr);
    CGS_Error e2 = cgs_append(ucstr_ptr, strbuf_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, strbuf_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0174(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(ucstr_ptr, msr);
    CGS_Error e2 = cgs_append(ucstr_ptr, msr);
    CGS_Error e3 = cgs_prepend(ucstr_ptr, msr);
    (void)e1; (void)e2; (void)e3;
}

void test_0175(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e1 = cgs_copy(cstr_arr, cstr_ptr);
    CGS_Error e2 = cgs_append(cstr_arr, cstr_ptr);
    CGS_Error e3 = cgs_prepend(cstr_arr, cstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0176(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e1 = cgs_copy(cstr_arr, ucstr_ptr);
    CGS_Error e2 = cgs_append(cstr_arr, ucstr_ptr);
    CGS_Error e3 = cgs_prepend(cstr_arr, ucstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0177(void) {
    char cstr_arr[] = "hello";
    CGS_Error e1 = cgs_copy(cstr_arr, cstr_arr);
    CGS_Error e2 = cgs_append(cstr_arr, cstr_arr);
    CGS_Error e3 = cgs_prepend(cstr_arr, cstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0178(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_copy(cstr_arr, ucstr_arr);
    CGS_Error e2 = cgs_append(cstr_arr, ucstr_arr);
    CGS_Error e3 = cgs_prepend(cstr_arr, ucstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0179(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    CGS_Error e1 = cgs_copy(cstr_arr, sv);
    CGS_Error e2 = cgs_append(cstr_arr, sv);
    CGS_Error e3 = cgs_prepend(cstr_arr, sv);
    (void)e1; (void)e2; (void)e3;
}

void test_0180(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e1 = cgs_copy(cstr_arr, dstr_val);
    CGS_Error e2 = cgs_append(cstr_arr, dstr_val);
    CGS_Error e3 = cgs_prepend(cstr_arr, dstr_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0181(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(cstr_arr, dstr_ptr);
    CGS_Error e2 = cgs_append(cstr_arr, dstr_ptr);
    CGS_Error e3 = cgs_prepend(cstr_arr, dstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0182(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e1 = cgs_copy(cstr_arr, strbuf_val);
    CGS_Error e2 = cgs_append(cstr_arr, strbuf_val);
    CGS_Error e3 = cgs_prepend(cstr_arr, strbuf_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0183(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(cstr_arr, strbuf_ptr);
    CGS_Error e2 = cgs_append(cstr_arr, strbuf_ptr);
    CGS_Error e3 = cgs_prepend(cstr_arr, strbuf_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0184(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(cstr_arr, msr);
    CGS_Error e2 = cgs_append(cstr_arr, msr);
    CGS_Error e3 = cgs_prepend(cstr_arr, msr);
    (void)e1; (void)e2; (void)e3;
}

void test_0185(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_copy(ucstr_arr, cstr_ptr);
    CGS_Error e2 = cgs_append(ucstr_arr, cstr_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_arr, cstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0186(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_copy(ucstr_arr, ucstr_ptr);
    CGS_Error e2 = cgs_append(ucstr_arr, ucstr_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_arr, ucstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0187(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_copy(ucstr_arr, cstr_arr);
    CGS_Error e2 = cgs_append(ucstr_arr, cstr_arr);
    CGS_Error e3 = cgs_prepend(ucstr_arr, cstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0188(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_copy(ucstr_arr, ucstr_arr);
    CGS_Error e2 = cgs_append(ucstr_arr, ucstr_arr);
    CGS_Error e3 = cgs_prepend(ucstr_arr, ucstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0189(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    CGS_Error e1 = cgs_copy(ucstr_arr, sv);
    CGS_Error e2 = cgs_append(ucstr_arr, sv);
    CGS_Error e3 = cgs_prepend(ucstr_arr, sv);
    (void)e1; (void)e2; (void)e3;
}

void test_0190(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e1 = cgs_copy(ucstr_arr, dstr_val);
    CGS_Error e2 = cgs_append(ucstr_arr, dstr_val);
    CGS_Error e3 = cgs_prepend(ucstr_arr, dstr_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0191(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(ucstr_arr, dstr_ptr);
    CGS_Error e2 = cgs_append(ucstr_arr, dstr_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_arr, dstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0192(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e1 = cgs_copy(ucstr_arr, strbuf_val);
    CGS_Error e2 = cgs_append(ucstr_arr, strbuf_val);
    CGS_Error e3 = cgs_prepend(ucstr_arr, strbuf_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0193(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(ucstr_arr, strbuf_ptr);
    CGS_Error e2 = cgs_append(ucstr_arr, strbuf_ptr);
    CGS_Error e3 = cgs_prepend(ucstr_arr, strbuf_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0194(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(ucstr_arr, msr);
    CGS_Error e2 = cgs_append(ucstr_arr, msr);
    CGS_Error e3 = cgs_prepend(ucstr_arr, msr);
    (void)e1; (void)e2; (void)e3;
}

void test_0195(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, cstr_ptr);
    CGS_Error e2 = cgs_append(dstr_ptr, cstr_ptr);
    CGS_Error e3 = cgs_prepend(dstr_ptr, cstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0196(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, ucstr_ptr);
    CGS_Error e2 = cgs_append(dstr_ptr, ucstr_ptr);
    CGS_Error e3 = cgs_prepend(dstr_ptr, ucstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0197(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, cstr_arr);
    CGS_Error e2 = cgs_append(dstr_ptr, cstr_arr);
    CGS_Error e3 = cgs_prepend(dstr_ptr, cstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0198(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, ucstr_arr);
    CGS_Error e2 = cgs_append(dstr_ptr, ucstr_arr);
    CGS_Error e3 = cgs_prepend(dstr_ptr, ucstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0199(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, sv);
    CGS_Error e2 = cgs_append(dstr_ptr, sv);
    CGS_Error e3 = cgs_prepend(dstr_ptr, sv);
    (void)e1; (void)e2; (void)e3;
}

void test_0200(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, dstr_val);
    CGS_Error e2 = cgs_append(dstr_ptr, dstr_val);
    CGS_Error e3 = cgs_prepend(dstr_ptr, dstr_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0201(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, dstr_ptr);
    CGS_Error e2 = cgs_append(dstr_ptr, dstr_ptr);
    CGS_Error e3 = cgs_prepend(dstr_ptr, dstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0202(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e1 = cgs_copy(dstr_ptr, strbuf_val);
    CGS_Error e2 = cgs_append(dstr_ptr, strbuf_val);
    CGS_Error e3 = cgs_prepend(dstr_ptr, strbuf_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0203(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(dstr_ptr, strbuf_ptr);
    CGS_Error e2 = cgs_append(dstr_ptr, strbuf_ptr);
    CGS_Error e3 = cgs_prepend(dstr_ptr, strbuf_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0204(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(dstr_ptr, msr);
    CGS_Error e2 = cgs_append(dstr_ptr, msr);
    CGS_Error e3 = cgs_prepend(dstr_ptr, msr);
    (void)e1; (void)e2; (void)e3;
}

void test_0205(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, cstr_ptr);
    CGS_Error e2 = cgs_append(strbuf_ptr, cstr_ptr);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, cstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0206(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, ucstr_ptr);
    CGS_Error e2 = cgs_append(strbuf_ptr, ucstr_ptr);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, ucstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0207(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, cstr_arr);
    CGS_Error e2 = cgs_append(strbuf_ptr, cstr_arr);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, cstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0208(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, ucstr_arr);
    CGS_Error e2 = cgs_append(strbuf_ptr, ucstr_arr);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, ucstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0209(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, sv);
    CGS_Error e2 = cgs_append(strbuf_ptr, sv);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, sv);
    (void)e1; (void)e2; (void)e3;
}

void test_0210(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, dstr_val);
    CGS_Error e2 = cgs_append(strbuf_ptr, dstr_val);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, dstr_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0211(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, dstr_ptr);
    CGS_Error e2 = cgs_append(strbuf_ptr, dstr_ptr);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, dstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0212(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, strbuf_val);
    CGS_Error e2 = cgs_append(strbuf_ptr, strbuf_val);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, strbuf_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0213(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_copy(strbuf_ptr, strbuf_ptr);
    CGS_Error e2 = cgs_append(strbuf_ptr, strbuf_ptr);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, strbuf_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0214(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(strbuf_ptr, msr);
    CGS_Error e2 = cgs_append(strbuf_ptr, msr);
    CGS_Error e3 = cgs_prepend(strbuf_ptr, msr);
    (void)e1; (void)e2; (void)e3;
}

void test_0215(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, cstr_ptr);
    CGS_Error e2 = cgs_append(msr, cstr_ptr);
    CGS_Error e3 = cgs_prepend(msr, cstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0216(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, ucstr_ptr);
    CGS_Error e2 = cgs_append(msr, ucstr_ptr);
    CGS_Error e3 = cgs_prepend(msr, ucstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0217(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, cstr_arr);
    CGS_Error e2 = cgs_append(msr, cstr_arr);
    CGS_Error e3 = cgs_prepend(msr, cstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0218(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, ucstr_arr);
    CGS_Error e2 = cgs_append(msr, ucstr_arr);
    CGS_Error e3 = cgs_prepend(msr, ucstr_arr);
    (void)e1; (void)e2; (void)e3;
}

void test_0219(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, sv);
    CGS_Error e2 = cgs_append(msr, sv);
    CGS_Error e3 = cgs_prepend(msr, sv);
    (void)e1; (void)e2; (void)e3;
}

void test_0220(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, dstr_val);
    CGS_Error e2 = cgs_append(msr, dstr_val);
    CGS_Error e3 = cgs_prepend(msr, dstr_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0221(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, dstr_ptr);
    CGS_Error e2 = cgs_append(msr, dstr_ptr);
    CGS_Error e3 = cgs_prepend(msr, dstr_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0222(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, strbuf_val);
    CGS_Error e2 = cgs_append(msr, strbuf_val);
    CGS_Error e3 = cgs_prepend(msr, strbuf_val);
    (void)e1; (void)e2; (void)e3;
}

void test_0223(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, strbuf_ptr);
    CGS_Error e2 = cgs_append(msr, strbuf_ptr);
    CGS_Error e3 = cgs_prepend(msr, strbuf_ptr);
    (void)e1; (void)e2; (void)e3;
}

void test_0224(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_copy(msr, msr);
    CGS_Error e2 = cgs_append(msr, msr);
    CGS_Error e3 = cgs_prepend(msr, msr);
    (void)e1; (void)e2; (void)e3;
}

/* ===== cgs_insert (mutstr x anystr x pos) ===== */
void test_0225(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e = cgs_insert(cstr_ptr, cstr_ptr, 1);
    (void)e;
}

void test_0226(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_insert(cstr_ptr, ucstr_ptr, 1);
    (void)e;
}

void test_0227(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_insert(cstr_ptr, cstr_arr, 1);
    (void)e;
}

void test_0228(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_insert(cstr_ptr, ucstr_arr, 1);
    (void)e;
}

void test_0229(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_insert(cstr_ptr, sv, 1);
    (void)e;
}

void test_0230(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_insert(cstr_ptr, dstr_val, 1);
    (void)e;
}

void test_0231(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(cstr_ptr, dstr_ptr, 1);
    (void)e;
}

void test_0232(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_insert(cstr_ptr, strbuf_val, 1);
    (void)e;
}

void test_0233(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(cstr_ptr, strbuf_ptr, 1);
    (void)e;
}

void test_0234(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(cstr_ptr, msr, 1);
    (void)e;
}

void test_0235(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_insert(ucstr_ptr, cstr_ptr, 1);
    (void)e;
}

void test_0236(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_insert(ucstr_ptr, ucstr_ptr, 1);
    (void)e;
}

void test_0237(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_insert(ucstr_ptr, cstr_arr, 1);
    (void)e;
}

void test_0238(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_insert(ucstr_ptr, ucstr_arr, 1);
    (void)e;
}

void test_0239(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_insert(ucstr_ptr, sv, 1);
    (void)e;
}

void test_0240(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_insert(ucstr_ptr, dstr_val, 1);
    (void)e;
}

void test_0241(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(ucstr_ptr, dstr_ptr, 1);
    (void)e;
}

void test_0242(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_insert(ucstr_ptr, strbuf_val, 1);
    (void)e;
}

void test_0243(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(ucstr_ptr, strbuf_ptr, 1);
    (void)e;
}

void test_0244(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(ucstr_ptr, msr, 1);
    (void)e;
}

void test_0245(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_insert(cstr_arr, cstr_ptr, 1);
    (void)e;
}

void test_0246(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_insert(cstr_arr, ucstr_ptr, 1);
    (void)e;
}

void test_0247(void) {
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_insert(cstr_arr, cstr_arr, 1);
    (void)e;
}

void test_0248(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_insert(cstr_arr, ucstr_arr, 1);
    (void)e;
}

void test_0249(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    CGS_Error e = cgs_insert(cstr_arr, sv, 1);
    (void)e;
}

void test_0250(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_insert(cstr_arr, dstr_val, 1);
    (void)e;
}

void test_0251(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(cstr_arr, dstr_ptr, 1);
    (void)e;
}

void test_0252(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_insert(cstr_arr, strbuf_val, 1);
    (void)e;
}

void test_0253(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(cstr_arr, strbuf_ptr, 1);
    (void)e;
}

void test_0254(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(cstr_arr, msr, 1);
    (void)e;
}

void test_0255(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_insert(ucstr_arr, cstr_ptr, 1);
    (void)e;
}

void test_0256(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_insert(ucstr_arr, ucstr_ptr, 1);
    (void)e;
}

void test_0257(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_insert(ucstr_arr, cstr_arr, 1);
    (void)e;
}

void test_0258(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_insert(ucstr_arr, ucstr_arr, 1);
    (void)e;
}

void test_0259(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    CGS_Error e = cgs_insert(ucstr_arr, sv, 1);
    (void)e;
}

void test_0260(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_insert(ucstr_arr, dstr_val, 1);
    (void)e;
}

void test_0261(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(ucstr_arr, dstr_ptr, 1);
    (void)e;
}

void test_0262(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_insert(ucstr_arr, strbuf_val, 1);
    (void)e;
}

void test_0263(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(ucstr_arr, strbuf_ptr, 1);
    (void)e;
}

void test_0264(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(ucstr_arr, msr, 1);
    (void)e;
}

void test_0265(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, cstr_ptr, 1);
    (void)e;
}

void test_0266(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, ucstr_ptr, 1);
    (void)e;
}

void test_0267(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, cstr_arr, 1);
    (void)e;
}

void test_0268(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, ucstr_arr, 1);
    (void)e;
}

void test_0269(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, sv, 1);
    (void)e;
}

void test_0270(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, dstr_val, 1);
    (void)e;
}

void test_0271(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, dstr_ptr, 1);
    (void)e;
}

void test_0272(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_insert(dstr_ptr, strbuf_val, 1);
    (void)e;
}

void test_0273(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(dstr_ptr, strbuf_ptr, 1);
    (void)e;
}

void test_0274(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(dstr_ptr, msr, 1);
    (void)e;
}

void test_0275(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, cstr_ptr, 1);
    (void)e;
}

void test_0276(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, ucstr_ptr, 1);
    (void)e;
}

void test_0277(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, cstr_arr, 1);
    (void)e;
}

void test_0278(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, ucstr_arr, 1);
    (void)e;
}

void test_0279(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, sv, 1);
    (void)e;
}

void test_0280(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, dstr_val, 1);
    (void)e;
}

void test_0281(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, dstr_ptr, 1);
    (void)e;
}

void test_0282(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, strbuf_val, 1);
    (void)e;
}

void test_0283(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_insert(strbuf_ptr, strbuf_ptr, 1);
    (void)e;
}

void test_0284(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(strbuf_ptr, msr, 1);
    (void)e;
}

void test_0285(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, cstr_ptr, 1);
    (void)e;
}

void test_0286(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, ucstr_ptr, 1);
    (void)e;
}

void test_0287(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, cstr_arr, 1);
    (void)e;
}

void test_0288(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, ucstr_arr, 1);
    (void)e;
}

void test_0289(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, sv, 1);
    (void)e;
}

void test_0290(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, dstr_val, 1);
    (void)e;
}

void test_0291(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, dstr_ptr, 1);
    (void)e;
}

void test_0292(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, strbuf_val, 1);
    (void)e;
}

void test_0293(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, strbuf_ptr, 1);
    (void)e;
}

void test_0294(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_insert(msr, msr, 1);
    (void)e;
}

/* ===== cgs_del (mutstr x from x to) ===== */
void test_0295(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e = cgs_del(cstr_ptr, 0, 1);
    (void)e;
}

void test_0296(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_del(ucstr_ptr, 0, 1);
    (void)e;
}

void test_0297(void) {
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_del(cstr_arr, 0, 1);
    (void)e;
}

void test_0298(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_del(ucstr_arr, 0, 1);
    (void)e;
}

void test_0299(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_del(dstr_ptr, 0, 1);
    (void)e;
}

void test_0300(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_del(strbuf_ptr, 0, 1);
    (void)e;
}

void test_0301(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_del(msr, 0, 1);
    (void)e;
}

/* ===== cgs_dup (anystr) ===== */
void test_0302(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr d = cgs_dup(cstr_ptr, NULL);
    dstr_deinit(&d);
}

void test_0303(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr d = cgs_dup(ucstr_ptr, NULL);
    dstr_deinit(&d);
}

void test_0304(void) {
    char cstr_arr[] = "hello";
    DStr d = cgs_dup(cstr_arr, NULL);
    dstr_deinit(&d);
}

void test_0305(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr d = cgs_dup(ucstr_arr, NULL);
    dstr_deinit(&d);
}

void test_0306(void) {
    StrView sv = strv("hello");
    DStr d = cgs_dup(sv, NULL);
    dstr_deinit(&d);
}

void test_0307(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr d = cgs_dup(dstr_val, NULL);
    dstr_deinit(&d);
}

void test_0308(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    DStr d = cgs_dup(dstr_ptr, NULL);
    dstr_deinit(&d);
}

void test_0309(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    DStr d = cgs_dup(strbuf_val, NULL);
    dstr_deinit(&d);
}

void test_0310(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    DStr d = cgs_dup(strbuf_ptr, NULL);
    dstr_deinit(&d);
}

void test_0311(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    DStr d = cgs_dup(msr, NULL);
    dstr_deinit(&d);
}

/* ===== cgs_replace / cgs_replace_first (mutstr x anystr x anystr) ===== */
void test_0312(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0313(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0314(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0315(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0316(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0317(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0318(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0319(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0320(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0321(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0322(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0323(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0324(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0325(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0326(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0327(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0328(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0329(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0330(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0331(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0332(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0333(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0334(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0335(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0336(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, sv);
    (void)rr; (void)e;
}

void test_0337(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0338(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0339(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0340(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0341(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, cstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, cstr_arr, msr);
    (void)rr; (void)e;
}

void test_0342(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0343(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0344(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0345(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0346(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, sv);
    (void)rr; (void)e;
}

void test_0347(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0348(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0349(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0350(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0351(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, ucstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, ucstr_arr, msr);
    (void)rr; (void)e;
}

void test_0352(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, cstr_ptr);
    (void)rr; (void)e;
}

void test_0353(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0354(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, cstr_arr);
    (void)rr; (void)e;
}

void test_0355(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, ucstr_arr);
    (void)rr; (void)e;
}

void test_0356(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, sv);
    (void)rr; (void)e;
}

void test_0357(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, dstr_val);
    (void)rr; (void)e;
}

void test_0358(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, dstr_ptr);
    (void)rr; (void)e;
}

void test_0359(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, strbuf_val);
    (void)rr; (void)e;
}

void test_0360(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0361(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, sv, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, sv, msr);
    (void)rr; (void)e;
}

void test_0362(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0363(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0364(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0365(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0366(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, sv);
    (void)rr; (void)e;
}

void test_0367(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, dstr_val);
    (void)rr; (void)e;
}

void test_0368(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0369(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0370(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0371(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_val, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_val, msr);
    (void)rr; (void)e;
}

void test_0372(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0373(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0374(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0375(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0376(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0377(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0378(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0379(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0380(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0381(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, dstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, dstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0382(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0383(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0384(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0385(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0386(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, sv);
    (void)rr; (void)e;
}

void test_0387(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, dstr_val);
    (void)rr; (void)e;
}

void test_0388(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0389(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0390(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0391(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_val, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_val, msr);
    (void)rr; (void)e;
}

void test_0392(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0393(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0394(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0395(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0396(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, sv);
    (void)rr; (void)e;
}

void test_0397(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0398(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0399(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0400(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0401(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, strbuf_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, strbuf_ptr, msr);
    (void)rr; (void)e;
}

void test_0402(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0403(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0404(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, cstr_arr);
    (void)rr; (void)e;
}

void test_0405(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0406(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, sv);
    (void)rr; (void)e;
}

void test_0407(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, dstr_val);
    (void)rr; (void)e;
}

void test_0408(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0409(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, strbuf_val);
    (void)rr; (void)e;
}

void test_0410(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0411(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_ptr, msr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_ptr, msr, msr);
    (void)rr; (void)e;
}

void test_0412(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0413(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0414(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0415(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0416(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0417(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0418(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0419(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0420(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0421(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0422(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0423(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0424(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0425(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0426(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0427(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0428(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0429(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0430(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0431(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0432(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0433(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0434(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0435(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0436(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, sv);
    (void)rr; (void)e;
}

void test_0437(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0438(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0439(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0440(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0441(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, cstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, cstr_arr, msr);
    (void)rr; (void)e;
}

void test_0442(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0443(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0444(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0445(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0446(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, sv);
    (void)rr; (void)e;
}

void test_0447(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0448(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0449(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0450(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0451(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, ucstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, ucstr_arr, msr);
    (void)rr; (void)e;
}

void test_0452(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, cstr_ptr);
    (void)rr; (void)e;
}

void test_0453(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0454(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, cstr_arr);
    (void)rr; (void)e;
}

void test_0455(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, ucstr_arr);
    (void)rr; (void)e;
}

void test_0456(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, sv);
    (void)rr; (void)e;
}

void test_0457(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, dstr_val);
    (void)rr; (void)e;
}

void test_0458(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, dstr_ptr);
    (void)rr; (void)e;
}

void test_0459(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, strbuf_val);
    (void)rr; (void)e;
}

void test_0460(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0461(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, sv, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, sv, msr);
    (void)rr; (void)e;
}

void test_0462(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0463(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0464(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0465(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0466(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, sv);
    (void)rr; (void)e;
}

void test_0467(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, dstr_val);
    (void)rr; (void)e;
}

void test_0468(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0469(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0470(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0471(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_val, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_val, msr);
    (void)rr; (void)e;
}

void test_0472(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0473(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0474(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0475(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0476(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0477(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0478(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0479(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0480(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0481(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, dstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, dstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0482(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0483(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0484(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0485(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0486(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, sv);
    (void)rr; (void)e;
}

void test_0487(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, dstr_val);
    (void)rr; (void)e;
}

void test_0488(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0489(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0490(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0491(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_val, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_val, msr);
    (void)rr; (void)e;
}

void test_0492(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0493(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0494(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0495(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0496(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, sv);
    (void)rr; (void)e;
}

void test_0497(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0498(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0499(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0500(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0501(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, strbuf_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, strbuf_ptr, msr);
    (void)rr; (void)e;
}

void test_0502(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0503(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0504(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, cstr_arr);
    (void)rr; (void)e;
}

void test_0505(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0506(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, sv);
    (void)rr; (void)e;
}

void test_0507(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, dstr_val);
    (void)rr; (void)e;
}

void test_0508(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0509(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, strbuf_val);
    (void)rr; (void)e;
}

void test_0510(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0511(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_ptr, msr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_ptr, msr, msr);
    (void)rr; (void)e;
}

void test_0512(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0513(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0514(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0515(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0516(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0517(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0518(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0519(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0520(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0521(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0522(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0523(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0524(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0525(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0526(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0527(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0528(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0529(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0530(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0531(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0532(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0533(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0534(void) {
    char cstr_arr[] = "hello";
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0535(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0536(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, sv);
    (void)rr; (void)e;
}

void test_0537(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0538(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0539(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0540(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0541(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, cstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, cstr_arr, msr);
    (void)rr; (void)e;
}

void test_0542(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0543(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0544(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0545(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0546(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, sv);
    (void)rr; (void)e;
}

void test_0547(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0548(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0549(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0550(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0551(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, ucstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, ucstr_arr, msr);
    (void)rr; (void)e;
}

void test_0552(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, sv, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, cstr_ptr);
    (void)rr; (void)e;
}

void test_0553(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, sv, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0554(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, sv, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, cstr_arr);
    (void)rr; (void)e;
}

void test_0555(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, sv, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, ucstr_arr);
    (void)rr; (void)e;
}

void test_0556(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(cstr_arr, sv, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, sv);
    (void)rr; (void)e;
}

void test_0557(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, sv, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, dstr_val);
    (void)rr; (void)e;
}

void test_0558(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, sv, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, dstr_ptr);
    (void)rr; (void)e;
}

void test_0559(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, sv, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, strbuf_val);
    (void)rr; (void)e;
}

void test_0560(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, sv, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0561(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, sv, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, sv, msr);
    (void)rr; (void)e;
}

void test_0562(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0563(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0564(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0565(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0566(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, sv);
    (void)rr; (void)e;
}

void test_0567(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, dstr_val);
    (void)rr; (void)e;
}

void test_0568(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0569(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0570(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0571(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_val, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_val, msr);
    (void)rr; (void)e;
}

void test_0572(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0573(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0574(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0575(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0576(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0577(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0578(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0579(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0580(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0581(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, dstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, dstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0582(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0583(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0584(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0585(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0586(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, sv);
    (void)rr; (void)e;
}

void test_0587(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, dstr_val);
    (void)rr; (void)e;
}

void test_0588(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0589(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0590(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0591(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_val, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_val, msr);
    (void)rr; (void)e;
}

void test_0592(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0593(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0594(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0595(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0596(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, sv);
    (void)rr; (void)e;
}

void test_0597(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0598(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0599(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0600(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0601(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, strbuf_ptr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, strbuf_ptr, msr);
    (void)rr; (void)e;
}

void test_0602(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0603(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0604(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, cstr_arr);
    (void)rr; (void)e;
}

void test_0605(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0606(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, sv);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, sv);
    (void)rr; (void)e;
}

void test_0607(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, dstr_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, dstr_val);
    (void)rr; (void)e;
}

void test_0608(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0609(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, strbuf_val);
    (void)rr; (void)e;
}

void test_0610(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0611(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(cstr_arr, msr, msr);
    CGS_Error     e  = cgs_replace_first(cstr_arr, msr, msr);
    (void)rr; (void)e;
}

void test_0612(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0613(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0614(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0615(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0616(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0617(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0618(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0619(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0620(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0621(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0622(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0623(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0624(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0625(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0626(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0627(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0628(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0629(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0630(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0631(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0632(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0633(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0634(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0635(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0636(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, sv);
    (void)rr; (void)e;
}

void test_0637(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0638(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0639(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0640(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0641(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, cstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, cstr_arr, msr);
    (void)rr; (void)e;
}

void test_0642(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0643(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0644(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0645(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0646(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, sv);
    (void)rr; (void)e;
}

void test_0647(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0648(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0649(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0650(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0651(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, ucstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, ucstr_arr, msr);
    (void)rr; (void)e;
}

void test_0652(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, cstr_ptr);
    (void)rr; (void)e;
}

void test_0653(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0654(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, cstr_arr);
    (void)rr; (void)e;
}

void test_0655(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, ucstr_arr);
    (void)rr; (void)e;
}

void test_0656(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, sv);
    (void)rr; (void)e;
}

void test_0657(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, dstr_val);
    (void)rr; (void)e;
}

void test_0658(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, dstr_ptr);
    (void)rr; (void)e;
}

void test_0659(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, strbuf_val);
    (void)rr; (void)e;
}

void test_0660(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0661(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, sv, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, sv, msr);
    (void)rr; (void)e;
}

void test_0662(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0663(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0664(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0665(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0666(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, sv);
    (void)rr; (void)e;
}

void test_0667(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, dstr_val);
    (void)rr; (void)e;
}

void test_0668(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0669(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0670(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0671(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_val, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_val, msr);
    (void)rr; (void)e;
}

void test_0672(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0673(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0674(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0675(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0676(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0677(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0678(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0679(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0680(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0681(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, dstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, dstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0682(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0683(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0684(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0685(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0686(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, sv);
    (void)rr; (void)e;
}

void test_0687(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, dstr_val);
    (void)rr; (void)e;
}

void test_0688(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0689(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0690(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0691(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_val, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_val, msr);
    (void)rr; (void)e;
}

void test_0692(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0693(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0694(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0695(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0696(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, sv);
    (void)rr; (void)e;
}

void test_0697(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0698(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0699(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0700(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0701(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, strbuf_ptr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, strbuf_ptr, msr);
    (void)rr; (void)e;
}

void test_0702(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0703(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0704(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, cstr_arr);
    (void)rr; (void)e;
}

void test_0705(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0706(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, sv);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, sv);
    (void)rr; (void)e;
}

void test_0707(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, dstr_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, dstr_val);
    (void)rr; (void)e;
}

void test_0708(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0709(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, strbuf_val);
    (void)rr; (void)e;
}

void test_0710(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0711(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(ucstr_arr, msr, msr);
    CGS_Error     e  = cgs_replace_first(ucstr_arr, msr, msr);
    (void)rr; (void)e;
}

void test_0712(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0713(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0714(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0715(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0716(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0717(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0718(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0719(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0720(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0721(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0722(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0723(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0724(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0725(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0726(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0727(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0728(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0729(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0730(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0731(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0732(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0733(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0734(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0735(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0736(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, sv);
    (void)rr; (void)e;
}

void test_0737(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0738(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0739(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0740(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0741(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, cstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, cstr_arr, msr);
    (void)rr; (void)e;
}

void test_0742(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0743(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0744(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0745(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0746(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, sv);
    (void)rr; (void)e;
}

void test_0747(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0748(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0749(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0750(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0751(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, ucstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, ucstr_arr, msr);
    (void)rr; (void)e;
}

void test_0752(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, cstr_ptr);
    (void)rr; (void)e;
}

void test_0753(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0754(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, cstr_arr);
    (void)rr; (void)e;
}

void test_0755(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, ucstr_arr);
    (void)rr; (void)e;
}

void test_0756(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, sv);
    (void)rr; (void)e;
}

void test_0757(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, dstr_val);
    (void)rr; (void)e;
}

void test_0758(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, dstr_ptr);
    (void)rr; (void)e;
}

void test_0759(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, strbuf_val);
    (void)rr; (void)e;
}

void test_0760(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0761(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, sv, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, sv, msr);
    (void)rr; (void)e;
}

void test_0762(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0763(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0764(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0765(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0766(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, sv);
    (void)rr; (void)e;
}

void test_0767(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, dstr_val);
    (void)rr; (void)e;
}

void test_0768(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0769(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0770(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0771(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_val, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_val, msr);
    (void)rr; (void)e;
}

void test_0772(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0773(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0774(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0775(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0776(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0777(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0778(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0779(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0780(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0781(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, dstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, dstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0782(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0783(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0784(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0785(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0786(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, sv);
    (void)rr; (void)e;
}

void test_0787(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, dstr_val);
    (void)rr; (void)e;
}

void test_0788(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0789(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0790(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0791(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_val, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_val, msr);
    (void)rr; (void)e;
}

void test_0792(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0793(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0794(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0795(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0796(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, sv);
    (void)rr; (void)e;
}

void test_0797(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0798(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0799(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0800(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0801(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, strbuf_ptr, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, strbuf_ptr, msr);
    (void)rr; (void)e;
}

void test_0802(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0803(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0804(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, cstr_arr);
    (void)rr; (void)e;
}

void test_0805(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0806(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, sv);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, sv);
    (void)rr; (void)e;
}

void test_0807(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, dstr_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, dstr_val);
    (void)rr; (void)e;
}

void test_0808(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0809(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, strbuf_val);
    (void)rr; (void)e;
}

void test_0810(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0811(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(dstr_ptr, msr, msr);
    CGS_Error     e  = cgs_replace_first(dstr_ptr, msr, msr);
    (void)rr; (void)e;
}

void test_0812(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0813(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0814(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0815(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0816(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0817(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0818(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0819(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0820(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0821(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0822(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0823(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0824(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0825(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0826(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0827(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0828(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0829(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0830(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0831(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0832(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0833(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0834(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0835(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0836(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, sv);
    (void)rr; (void)e;
}

void test_0837(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0838(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0839(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0840(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0841(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, cstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, cstr_arr, msr);
    (void)rr; (void)e;
}

void test_0842(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0843(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0844(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0845(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0846(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, sv);
    (void)rr; (void)e;
}

void test_0847(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0848(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0849(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0850(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0851(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, ucstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, ucstr_arr, msr);
    (void)rr; (void)e;
}

void test_0852(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, cstr_ptr);
    (void)rr; (void)e;
}

void test_0853(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0854(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, cstr_arr);
    (void)rr; (void)e;
}

void test_0855(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, ucstr_arr);
    (void)rr; (void)e;
}

void test_0856(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, sv);
    (void)rr; (void)e;
}

void test_0857(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, dstr_val);
    (void)rr; (void)e;
}

void test_0858(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, dstr_ptr);
    (void)rr; (void)e;
}

void test_0859(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, strbuf_val);
    (void)rr; (void)e;
}

void test_0860(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0861(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, sv, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, sv, msr);
    (void)rr; (void)e;
}

void test_0862(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0863(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0864(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0865(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0866(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, sv);
    (void)rr; (void)e;
}

void test_0867(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, dstr_val);
    (void)rr; (void)e;
}

void test_0868(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0869(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0870(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0871(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_val, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_val, msr);
    (void)rr; (void)e;
}

void test_0872(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0873(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0874(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0875(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0876(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0877(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0878(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0879(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0880(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0881(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, dstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, dstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0882(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0883(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0884(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0885(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0886(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, sv);
    (void)rr; (void)e;
}

void test_0887(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, dstr_val);
    (void)rr; (void)e;
}

void test_0888(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0889(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0890(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0891(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_val, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_val, msr);
    (void)rr; (void)e;
}

void test_0892(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0893(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0894(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0895(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0896(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, sv);
    (void)rr; (void)e;
}

void test_0897(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0898(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0899(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0900(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0901(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, strbuf_ptr, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, strbuf_ptr, msr);
    (void)rr; (void)e;
}

void test_0902(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0903(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0904(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, cstr_arr);
    (void)rr; (void)e;
}

void test_0905(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0906(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, sv);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, sv);
    (void)rr; (void)e;
}

void test_0907(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, dstr_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, dstr_val);
    (void)rr; (void)e;
}

void test_0908(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0909(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, strbuf_val);
    (void)rr; (void)e;
}

void test_0910(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0911(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(strbuf_ptr, msr, msr);
    CGS_Error     e  = cgs_replace_first(strbuf_ptr, msr, msr);
    (void)rr; (void)e;
}

void test_0912(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0913(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0914(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0915(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0916(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0917(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0918(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0919(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0920(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0921(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0922(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0923(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0924(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0925(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0926(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0927(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0928(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0929(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0930(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0931(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0932(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0933(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0934(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0935(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0936(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, sv);
    (void)rr; (void)e;
}

void test_0937(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0938(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0939(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0940(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0941(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, cstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(msr, cstr_arr, msr);
    (void)rr; (void)e;
}

void test_0942(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0943(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0944(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, cstr_arr);
    (void)rr; (void)e;
}

void test_0945(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0946(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, sv);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, sv);
    (void)rr; (void)e;
}

void test_0947(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, dstr_val);
    (void)rr; (void)e;
}

void test_0948(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0949(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, strbuf_val);
    (void)rr; (void)e;
}

void test_0950(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0951(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, ucstr_arr, msr);
    CGS_Error     e  = cgs_replace_first(msr, ucstr_arr, msr);
    (void)rr; (void)e;
}

void test_0952(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, sv, cstr_ptr);
    (void)rr; (void)e;
}

void test_0953(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, sv, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0954(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, sv, cstr_arr);
    (void)rr; (void)e;
}

void test_0955(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, sv, ucstr_arr);
    (void)rr; (void)e;
}

void test_0956(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, sv);
    CGS_Error     e  = cgs_replace_first(msr, sv, sv);
    (void)rr; (void)e;
}

void test_0957(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, sv, dstr_val);
    (void)rr; (void)e;
}

void test_0958(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, sv, dstr_ptr);
    (void)rr; (void)e;
}

void test_0959(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, sv, strbuf_val);
    (void)rr; (void)e;
}

void test_0960(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, sv, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0961(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, sv, msr);
    CGS_Error     e  = cgs_replace_first(msr, sv, msr);
    (void)rr; (void)e;
}

void test_0962(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0963(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0964(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0965(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0966(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, sv);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, sv);
    (void)rr; (void)e;
}

void test_0967(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, dstr_val);
    (void)rr; (void)e;
}

void test_0968(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0969(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0970(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0971(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_val, msr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_val, msr);
    (void)rr; (void)e;
}

void test_0972(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0973(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0974(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0975(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0976(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, sv);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, sv);
    (void)rr; (void)e;
}

void test_0977(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0978(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0979(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_0980(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0981(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, dstr_ptr, msr);
    CGS_Error     e  = cgs_replace_first(msr, dstr_ptr, msr);
    (void)rr; (void)e;
}

void test_0982(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, cstr_ptr);
    (void)rr; (void)e;
}

void test_0983(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0984(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, cstr_arr);
    (void)rr; (void)e;
}

void test_0985(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, ucstr_arr);
    (void)rr; (void)e;
}

void test_0986(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, sv);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, sv);
    (void)rr; (void)e;
}

void test_0987(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, dstr_val);
    (void)rr; (void)e;
}

void test_0988(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, dstr_ptr);
    (void)rr; (void)e;
}

void test_0989(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, strbuf_val);
    (void)rr; (void)e;
}

void test_0990(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, strbuf_ptr);
    (void)rr; (void)e;
}

void test_0991(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_val, msr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_val, msr);
    (void)rr; (void)e;
}

void test_0992(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, cstr_ptr);
    (void)rr; (void)e;
}

void test_0993(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_0994(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, cstr_arr);
    (void)rr; (void)e;
}

void test_0995(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, ucstr_arr);
    (void)rr; (void)e;
}

void test_0996(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, sv);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, sv);
    (void)rr; (void)e;
}

void test_0997(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, dstr_val);
    (void)rr; (void)e;
}

void test_0998(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, dstr_ptr);
    (void)rr; (void)e;
}

void test_0999(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, strbuf_val);
    (void)rr; (void)e;
}

void test_1000(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_1001(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, strbuf_ptr, msr);
    CGS_Error     e  = cgs_replace_first(msr, strbuf_ptr, msr);
    (void)rr; (void)e;
}

void test_1002(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, cstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, msr, cstr_ptr);
    (void)rr; (void)e;
}

void test_1003(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, ucstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, msr, ucstr_ptr);
    (void)rr; (void)e;
}

void test_1004(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, cstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, msr, cstr_arr);
    (void)rr; (void)e;
}

void test_1005(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, ucstr_arr);
    CGS_Error     e  = cgs_replace_first(msr, msr, ucstr_arr);
    (void)rr; (void)e;
}

void test_1006(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, sv);
    CGS_Error     e  = cgs_replace_first(msr, msr, sv);
    (void)rr; (void)e;
}

void test_1007(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, dstr_val);
    CGS_Error     e  = cgs_replace_first(msr, msr, dstr_val);
    (void)rr; (void)e;
}

void test_1008(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, dstr_ptr);
    CGS_Error     e  = cgs_replace_first(msr, msr, dstr_ptr);
    (void)rr; (void)e;
}

void test_1009(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, strbuf_val);
    CGS_Error     e  = cgs_replace_first(msr, msr, strbuf_val);
    (void)rr; (void)e;
}

void test_1010(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, strbuf_ptr);
    CGS_Error     e  = cgs_replace_first(msr, msr, strbuf_ptr);
    (void)rr; (void)e;
}

void test_1011(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    ReplaceResult rr = cgs_replace(msr, msr, msr);
    CGS_Error     e  = cgs_replace_first(msr, msr, msr);
    (void)rr; (void)e;
}

/* ===== cgs_replace_range (mutstr x from x to x anystr) ===== */
void test_1012(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, cstr_ptr);
    (void)e;
}

void test_1013(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, ucstr_ptr);
    (void)e;
}

void test_1014(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, cstr_arr);
    (void)e;
}

void test_1015(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, ucstr_arr);
    (void)e;
}

void test_1016(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, sv);
    (void)e;
}

void test_1017(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, dstr_val);
    (void)e;
}

void test_1018(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, dstr_ptr);
    (void)e;
}

void test_1019(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, strbuf_val);
    (void)e;
}

void test_1020(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, strbuf_ptr);
    (void)e;
}

void test_1021(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(cstr_ptr, 0, 1, msr);
    (void)e;
}

void test_1022(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, cstr_ptr);
    (void)e;
}

void test_1023(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, ucstr_ptr);
    (void)e;
}

void test_1024(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, cstr_arr);
    (void)e;
}

void test_1025(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, ucstr_arr);
    (void)e;
}

void test_1026(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, sv);
    (void)e;
}

void test_1027(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, dstr_val);
    (void)e;
}

void test_1028(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, dstr_ptr);
    (void)e;
}

void test_1029(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, strbuf_val);
    (void)e;
}

void test_1030(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, strbuf_ptr);
    (void)e;
}

void test_1031(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(ucstr_ptr, 0, 1, msr);
    (void)e;
}

void test_1032(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, cstr_ptr);
    (void)e;
}

void test_1033(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, ucstr_ptr);
    (void)e;
}

void test_1034(void) {
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, cstr_arr);
    (void)e;
}

void test_1035(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, ucstr_arr);
    (void)e;
}

void test_1036(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, sv);
    (void)e;
}

void test_1037(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, dstr_val);
    (void)e;
}

void test_1038(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, dstr_ptr);
    (void)e;
}

void test_1039(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, strbuf_val);
    (void)e;
}

void test_1040(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, strbuf_ptr);
    (void)e;
}

void test_1041(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(cstr_arr, 0, 1, msr);
    (void)e;
}

void test_1042(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, cstr_ptr);
    (void)e;
}

void test_1043(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, ucstr_ptr);
    (void)e;
}

void test_1044(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, cstr_arr);
    (void)e;
}

void test_1045(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, ucstr_arr);
    (void)e;
}

void test_1046(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, sv);
    (void)e;
}

void test_1047(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, dstr_val);
    (void)e;
}

void test_1048(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, dstr_ptr);
    (void)e;
}

void test_1049(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, strbuf_val);
    (void)e;
}

void test_1050(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, strbuf_ptr);
    (void)e;
}

void test_1051(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(ucstr_arr, 0, 1, msr);
    (void)e;
}

void test_1052(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, cstr_ptr);
    (void)e;
}

void test_1053(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, ucstr_ptr);
    (void)e;
}

void test_1054(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, cstr_arr);
    (void)e;
}

void test_1055(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, ucstr_arr);
    (void)e;
}

void test_1056(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, sv);
    (void)e;
}

void test_1057(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, dstr_val);
    (void)e;
}

void test_1058(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, dstr_ptr);
    (void)e;
}

void test_1059(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, strbuf_val);
    (void)e;
}

void test_1060(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, strbuf_ptr);
    (void)e;
}

void test_1061(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(dstr_ptr, 0, 1, msr);
    (void)e;
}

void test_1062(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, cstr_ptr);
    (void)e;
}

void test_1063(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, ucstr_ptr);
    (void)e;
}

void test_1064(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, cstr_arr);
    (void)e;
}

void test_1065(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, ucstr_arr);
    (void)e;
}

void test_1066(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, sv);
    (void)e;
}

void test_1067(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, dstr_val);
    (void)e;
}

void test_1068(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, dstr_ptr);
    (void)e;
}

void test_1069(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, strbuf_val);
    (void)e;
}

void test_1070(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, strbuf_ptr);
    (void)e;
}

void test_1071(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(strbuf_ptr, 0, 1, msr);
    (void)e;
}

void test_1072(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, cstr_ptr);
    (void)e;
}

void test_1073(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, ucstr_ptr);
    (void)e;
}

void test_1074(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, cstr_arr);
    (void)e;
}

void test_1075(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, ucstr_arr);
    (void)e;
}

void test_1076(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, sv);
    (void)e;
}

void test_1077(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, dstr_val);
    (void)e;
}

void test_1078(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, dstr_ptr);
    (void)e;
}

void test_1079(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, strbuf_val);
    (void)e;
}

void test_1080(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, strbuf_ptr);
    (void)e;
}

void test_1081(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_replace_range(msr, 0, 1, msr);
    (void)e;
}

/* ===== cgs_split (anystr x anystr) ===== */
void test_1082(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrViewArray arr = cgs_split(cstr_ptr, cstr_ptr, NULL);
    (void)arr;
}

void test_1083(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrViewArray arr = cgs_split(cstr_ptr, ucstr_ptr, NULL);
    (void)arr;
}

void test_1084(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = cgs_split(cstr_ptr, cstr_arr, NULL);
    (void)arr;
}

void test_1085(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = cgs_split(cstr_ptr, ucstr_arr, NULL);
    (void)arr;
}

void test_1086(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(cstr_ptr, sv, NULL);
    (void)arr;
}

void test_1087(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(cstr_ptr, dstr_val, NULL);
    (void)arr;
}

void test_1088(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(cstr_ptr, dstr_ptr, NULL);
    (void)arr;
}

void test_1089(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(cstr_ptr, strbuf_val, NULL);
    (void)arr;
}

void test_1090(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(cstr_ptr, strbuf_ptr, NULL);
    (void)arr;
}

void test_1091(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(cstr_ptr, msr, NULL);
    (void)arr;
}

void test_1092(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrViewArray arr = cgs_split(ucstr_ptr, cstr_ptr, NULL);
    (void)arr;
}

void test_1093(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrViewArray arr = cgs_split(ucstr_ptr, ucstr_ptr, NULL);
    (void)arr;
}

void test_1094(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = cgs_split(ucstr_ptr, cstr_arr, NULL);
    (void)arr;
}

void test_1095(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = cgs_split(ucstr_ptr, ucstr_arr, NULL);
    (void)arr;
}

void test_1096(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(ucstr_ptr, sv, NULL);
    (void)arr;
}

void test_1097(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(ucstr_ptr, dstr_val, NULL);
    (void)arr;
}

void test_1098(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(ucstr_ptr, dstr_ptr, NULL);
    (void)arr;
}

void test_1099(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(ucstr_ptr, strbuf_val, NULL);
    (void)arr;
}

void test_1100(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(ucstr_ptr, strbuf_ptr, NULL);
    (void)arr;
}

void test_1101(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(ucstr_ptr, msr, NULL);
    (void)arr;
}

void test_1102(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = cgs_split(cstr_arr, cstr_ptr, NULL);
    (void)arr;
}

void test_1103(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = cgs_split(cstr_arr, ucstr_ptr, NULL);
    (void)arr;
}

void test_1104(void) {
    char cstr_arr[] = "hello";
    StrViewArray arr = cgs_split(cstr_arr, cstr_arr, NULL);
    (void)arr;
}

void test_1105(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = cgs_split(cstr_arr, ucstr_arr, NULL);
    (void)arr;
}

void test_1106(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(cstr_arr, sv, NULL);
    (void)arr;
}

void test_1107(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(cstr_arr, dstr_val, NULL);
    (void)arr;
}

void test_1108(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(cstr_arr, dstr_ptr, NULL);
    (void)arr;
}

void test_1109(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(cstr_arr, strbuf_val, NULL);
    (void)arr;
}

void test_1110(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(cstr_arr, strbuf_ptr, NULL);
    (void)arr;
}

void test_1111(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(cstr_arr, msr, NULL);
    (void)arr;
}

void test_1112(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = cgs_split(ucstr_arr, cstr_ptr, NULL);
    (void)arr;
}

void test_1113(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = cgs_split(ucstr_arr, ucstr_ptr, NULL);
    (void)arr;
}

void test_1114(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = cgs_split(ucstr_arr, cstr_arr, NULL);
    (void)arr;
}

void test_1115(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = cgs_split(ucstr_arr, ucstr_arr, NULL);
    (void)arr;
}

void test_1116(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(ucstr_arr, sv, NULL);
    (void)arr;
}

void test_1117(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(ucstr_arr, dstr_val, NULL);
    (void)arr;
}

void test_1118(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(ucstr_arr, dstr_ptr, NULL);
    (void)arr;
}

void test_1119(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(ucstr_arr, strbuf_val, NULL);
    (void)arr;
}

void test_1120(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(ucstr_arr, strbuf_ptr, NULL);
    (void)arr;
}

void test_1121(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(ucstr_arr, msr, NULL);
    (void)arr;
}

void test_1122(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(sv, cstr_ptr, NULL);
    (void)arr;
}

void test_1123(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(sv, ucstr_ptr, NULL);
    (void)arr;
}

void test_1124(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(sv, cstr_arr, NULL);
    (void)arr;
}

void test_1125(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(sv, ucstr_arr, NULL);
    (void)arr;
}

void test_1126(void) {
    StrView sv = strv("hello");
    StrViewArray arr = cgs_split(sv, sv, NULL);
    (void)arr;
}

void test_1127(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(sv, dstr_val, NULL);
    (void)arr;
}

void test_1128(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(sv, dstr_ptr, NULL);
    (void)arr;
}

void test_1129(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(sv, strbuf_val, NULL);
    (void)arr;
}

void test_1130(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(sv, strbuf_ptr, NULL);
    (void)arr;
}

void test_1131(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(sv, msr, NULL);
    (void)arr;
}

void test_1132(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(dstr_val, cstr_ptr, NULL);
    (void)arr;
}

void test_1133(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(dstr_val, ucstr_ptr, NULL);
    (void)arr;
}

void test_1134(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(dstr_val, cstr_arr, NULL);
    (void)arr;
}

void test_1135(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(dstr_val, ucstr_arr, NULL);
    (void)arr;
}

void test_1136(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(dstr_val, sv, NULL);
    (void)arr;
}

void test_1137(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = cgs_split(dstr_val, dstr_val, NULL);
    (void)arr;
}

void test_1138(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_val, dstr_ptr, NULL);
    (void)arr;
}

void test_1139(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(dstr_val, strbuf_val, NULL);
    (void)arr;
}

void test_1140(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(dstr_val, strbuf_ptr, NULL);
    (void)arr;
}

void test_1141(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(dstr_val, msr, NULL);
    (void)arr;
}

void test_1142(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, cstr_ptr, NULL);
    (void)arr;
}

void test_1143(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, ucstr_ptr, NULL);
    (void)arr;
}

void test_1144(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, cstr_arr, NULL);
    (void)arr;
}

void test_1145(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, ucstr_arr, NULL);
    (void)arr;
}

void test_1146(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, sv, NULL);
    (void)arr;
}

void test_1147(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, dstr_val, NULL);
    (void)arr;
}

void test_1148(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, dstr_ptr, NULL);
    (void)arr;
}

void test_1149(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(dstr_ptr, strbuf_val, NULL);
    (void)arr;
}

void test_1150(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(dstr_ptr, strbuf_ptr, NULL);
    (void)arr;
}

void test_1151(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(dstr_ptr, msr, NULL);
    (void)arr;
}

void test_1152(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, cstr_ptr, NULL);
    (void)arr;
}

void test_1153(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, ucstr_ptr, NULL);
    (void)arr;
}

void test_1154(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, cstr_arr, NULL);
    (void)arr;
}

void test_1155(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, ucstr_arr, NULL);
    (void)arr;
}

void test_1156(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, sv, NULL);
    (void)arr;
}

void test_1157(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, dstr_val, NULL);
    (void)arr;
}

void test_1158(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, dstr_ptr, NULL);
    (void)arr;
}

void test_1159(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = cgs_split(strbuf_val, strbuf_val, NULL);
    (void)arr;
}

void test_1160(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_val, strbuf_ptr, NULL);
    (void)arr;
}

void test_1161(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(strbuf_val, msr, NULL);
    (void)arr;
}

void test_1162(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, cstr_ptr, NULL);
    (void)arr;
}

void test_1163(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, ucstr_ptr, NULL);
    (void)arr;
}

void test_1164(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, cstr_arr, NULL);
    (void)arr;
}

void test_1165(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, ucstr_arr, NULL);
    (void)arr;
}

void test_1166(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, sv, NULL);
    (void)arr;
}

void test_1167(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, dstr_val, NULL);
    (void)arr;
}

void test_1168(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, dstr_ptr, NULL);
    (void)arr;
}

void test_1169(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, strbuf_val, NULL);
    (void)arr;
}

void test_1170(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = cgs_split(strbuf_ptr, strbuf_ptr, NULL);
    (void)arr;
}

void test_1171(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(strbuf_ptr, msr, NULL);
    (void)arr;
}

void test_1172(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, cstr_ptr, NULL);
    (void)arr;
}

void test_1173(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, ucstr_ptr, NULL);
    (void)arr;
}

void test_1174(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, cstr_arr, NULL);
    (void)arr;
}

void test_1175(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, ucstr_arr, NULL);
    (void)arr;
}

void test_1176(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, sv, NULL);
    (void)arr;
}

void test_1177(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, dstr_val, NULL);
    (void)arr;
}

void test_1178(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, dstr_ptr, NULL);
    (void)arr;
}

void test_1179(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, strbuf_val, NULL);
    (void)arr;
}

void test_1180(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, strbuf_ptr, NULL);
    (void)arr;
}

void test_1181(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = cgs_split(msr, msr, NULL);
    (void)arr;
}

/* ===== cgs_split_iter (anystr x anystr x callback) ===== */
static bool split_iter_cb(StrView found, void *arg) { (void)found; (void)arg; return true; }
void test_1182(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e = cgs_split_iter(cstr_ptr, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1183(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_split_iter(cstr_ptr, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1184(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_split_iter(cstr_ptr, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1185(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_split_iter(cstr_ptr, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1186(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(cstr_ptr, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1187(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(cstr_ptr, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1188(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(cstr_ptr, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1189(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(cstr_ptr, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1190(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(cstr_ptr, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1191(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(cstr_ptr, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1192(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_split_iter(ucstr_ptr, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1193(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = cgs_split_iter(ucstr_ptr, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1194(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_split_iter(ucstr_ptr, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1195(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_split_iter(ucstr_ptr, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1196(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(ucstr_ptr, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1197(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(ucstr_ptr, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1198(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(ucstr_ptr, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1199(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(ucstr_ptr, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1200(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(ucstr_ptr, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1201(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(ucstr_ptr, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1202(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_split_iter(cstr_arr, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1203(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_split_iter(cstr_arr, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1204(void) {
    char cstr_arr[] = "hello";
    CGS_Error e = cgs_split_iter(cstr_arr, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1205(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_split_iter(cstr_arr, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1206(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(cstr_arr, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1207(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(cstr_arr, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1208(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(cstr_arr, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1209(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(cstr_arr, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1210(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(cstr_arr, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1211(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(cstr_arr, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1212(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_split_iter(ucstr_arr, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1213(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_split_iter(ucstr_arr, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1214(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_split_iter(ucstr_arr, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1215(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = cgs_split_iter(ucstr_arr, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1216(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(ucstr_arr, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1217(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(ucstr_arr, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1218(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(ucstr_arr, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1219(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(ucstr_arr, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1220(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(ucstr_arr, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1221(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(ucstr_arr, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1222(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(sv, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1223(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(sv, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1224(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(sv, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1225(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(sv, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1226(void) {
    StrView sv = strv("hello");
    CGS_Error e = cgs_split_iter(sv, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1227(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(sv, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1228(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(sv, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1229(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(sv, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1230(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(sv, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1231(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(sv, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1232(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(dstr_val, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1233(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(dstr_val, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1234(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(dstr_val, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1235(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(dstr_val, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1236(void) {
    StrView sv = strv("hello");
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(dstr_val, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1237(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = cgs_split_iter(dstr_val, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1238(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_val, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1239(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(dstr_val, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1240(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_val, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1241(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(dstr_val, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1242(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1243(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1244(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1245(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1246(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1247(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1248(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1249(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(dstr_ptr, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1250(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(dstr_ptr, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1251(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(dstr_ptr, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1252(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1253(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1254(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1255(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1256(void) {
    StrView sv = strv("hello");
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1257(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1258(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1259(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = cgs_split_iter(strbuf_val, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1260(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_val, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1261(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(strbuf_val, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1262(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1263(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1264(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1265(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1266(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1267(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1268(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1269(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1270(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = cgs_split_iter(strbuf_ptr, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1271(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(strbuf_ptr, msr, split_iter_cb, NULL);
    (void)e;
}

void test_1272(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, cstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1273(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, ucstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1274(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, cstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1275(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, ucstr_arr, split_iter_cb, NULL);
    (void)e;
}

void test_1276(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, sv, split_iter_cb, NULL);
    (void)e;
}

void test_1277(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, dstr_val, split_iter_cb, NULL);
    (void)e;
}

void test_1278(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, dstr_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1279(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, strbuf_val, split_iter_cb, NULL);
    (void)e;
}

void test_1280(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, strbuf_ptr, split_iter_cb, NULL);
    (void)e;
}

void test_1281(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = cgs_split_iter(msr, msr, split_iter_cb, NULL);
    (void)e;
}

/* ===== cgs_join (mutstr x StrViewArray x anystr) ===== */
void test_1282(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, cstr_ptr);
    (void)e;
}

void test_1283(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, ucstr_ptr);
    (void)e;
}

void test_1284(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, cstr_arr);
    (void)e;
}

void test_1285(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, ucstr_arr);
    (void)e;
}

void test_1286(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, sv);
    (void)e;
}

void test_1287(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, dstr_val);
    (void)e;
}

void test_1288(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, dstr_ptr);
    (void)e;
}

void test_1289(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, strbuf_val);
    (void)e;
}

void test_1290(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, strbuf_ptr);
    (void)e;
}

void test_1291(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_ptr, arr, msr);
    (void)e;
}

void test_1292(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, cstr_ptr);
    (void)e;
}

void test_1293(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, ucstr_ptr);
    (void)e;
}

void test_1294(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, cstr_arr);
    (void)e;
}

void test_1295(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, ucstr_arr);
    (void)e;
}

void test_1296(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, sv);
    (void)e;
}

void test_1297(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, dstr_val);
    (void)e;
}

void test_1298(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, dstr_ptr);
    (void)e;
}

void test_1299(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, strbuf_val);
    (void)e;
}

void test_1300(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, strbuf_ptr);
    (void)e;
}

void test_1301(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_ptr, arr, msr);
    (void)e;
}

void test_1302(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, cstr_ptr);
    (void)e;
}

void test_1303(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, ucstr_ptr);
    (void)e;
}

void test_1304(void) {
    char cstr_arr[] = "hello";
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, cstr_arr);
    (void)e;
}

void test_1305(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, ucstr_arr);
    (void)e;
}

void test_1306(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, sv);
    (void)e;
}

void test_1307(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, dstr_val);
    (void)e;
}

void test_1308(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, dstr_ptr);
    (void)e;
}

void test_1309(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, strbuf_val);
    (void)e;
}

void test_1310(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, strbuf_ptr);
    (void)e;
}

void test_1311(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(cstr_arr, arr, msr);
    (void)e;
}

void test_1312(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, cstr_ptr);
    (void)e;
}

void test_1313(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, ucstr_ptr);
    (void)e;
}

void test_1314(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, cstr_arr);
    (void)e;
}

void test_1315(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, ucstr_arr);
    (void)e;
}

void test_1316(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, sv);
    (void)e;
}

void test_1317(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, dstr_val);
    (void)e;
}

void test_1318(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, dstr_ptr);
    (void)e;
}

void test_1319(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, strbuf_val);
    (void)e;
}

void test_1320(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, strbuf_ptr);
    (void)e;
}

void test_1321(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(ucstr_arr, arr, msr);
    (void)e;
}

void test_1322(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, cstr_ptr);
    (void)e;
}

void test_1323(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, ucstr_ptr);
    (void)e;
}

void test_1324(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, cstr_arr);
    (void)e;
}

void test_1325(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, ucstr_arr);
    (void)e;
}

void test_1326(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, sv);
    (void)e;
}

void test_1327(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, dstr_val);
    (void)e;
}

void test_1328(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, dstr_ptr);
    (void)e;
}

void test_1329(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, strbuf_val);
    (void)e;
}

void test_1330(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, strbuf_ptr);
    (void)e;
}

void test_1331(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(dstr_ptr, arr, msr);
    (void)e;
}

void test_1332(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, cstr_ptr);
    (void)e;
}

void test_1333(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, ucstr_ptr);
    (void)e;
}

void test_1334(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, cstr_arr);
    (void)e;
}

void test_1335(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, ucstr_arr);
    (void)e;
}

void test_1336(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, sv);
    (void)e;
}

void test_1337(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, dstr_val);
    (void)e;
}

void test_1338(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, dstr_ptr);
    (void)e;
}

void test_1339(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, strbuf_val);
    (void)e;
}

void test_1340(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, strbuf_ptr);
    (void)e;
}

void test_1341(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(strbuf_ptr, arr, msr);
    (void)e;
}

void test_1342(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, cstr_ptr);
    (void)e;
}

void test_1343(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, ucstr_ptr);
    (void)e;
}

void test_1344(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, cstr_arr);
    (void)e;
}

void test_1345(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, ucstr_arr);
    (void)e;
}

void test_1346(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, sv);
    (void)e;
}

void test_1347(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, dstr_val);
    (void)e;
}

void test_1348(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, dstr_ptr);
    (void)e;
}

void test_1349(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, strbuf_val);
    (void)e;
}

void test_1350(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, strbuf_ptr);
    (void)e;
}

void test_1351(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    StrViewArray arr = strv_arr("a", "b");
    CGS_Error e = cgs_join(msr, arr, msr);
    (void)e;
}

/* ===== line reading (mutstr) ===== */
void test_1352(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e1 = cgs_fread_line(cstr_ptr, stdin);
    CGS_Error e2 = cgs_append_fread_line(cstr_ptr, stdin);
    CGS_Error e3 = cgs_read_line(cstr_ptr);
    CGS_Error e4 = cgs_append_read_line(cstr_ptr);
    (void)e1; (void)e2; (void)e3; (void)e4;
}

void test_1353(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e1 = cgs_fread_line(ucstr_ptr, stdin);
    CGS_Error e2 = cgs_append_fread_line(ucstr_ptr, stdin);
    CGS_Error e3 = cgs_read_line(ucstr_ptr);
    CGS_Error e4 = cgs_append_read_line(ucstr_ptr);
    (void)e1; (void)e2; (void)e3; (void)e4;
}

void test_1354(void) {
    char cstr_arr[] = "hello";
    CGS_Error e1 = cgs_fread_line(cstr_arr, stdin);
    CGS_Error e2 = cgs_append_fread_line(cstr_arr, stdin);
    CGS_Error e3 = cgs_read_line(cstr_arr);
    CGS_Error e4 = cgs_append_read_line(cstr_arr);
    (void)e1; (void)e2; (void)e3; (void)e4;
}

void test_1355(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e1 = cgs_fread_line(ucstr_arr, stdin);
    CGS_Error e2 = cgs_append_fread_line(ucstr_arr, stdin);
    CGS_Error e3 = cgs_read_line(ucstr_arr);
    CGS_Error e4 = cgs_append_read_line(ucstr_arr);
    (void)e1; (void)e2; (void)e3; (void)e4;
}

void test_1356(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e1 = cgs_fread_line(dstr_ptr, stdin);
    CGS_Error e2 = cgs_append_fread_line(dstr_ptr, stdin);
    CGS_Error e3 = cgs_read_line(dstr_ptr);
    CGS_Error e4 = cgs_append_read_line(dstr_ptr);
    (void)e1; (void)e2; (void)e3; (void)e4;
}

void test_1357(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e1 = cgs_fread_line(strbuf_ptr, stdin);
    CGS_Error e2 = cgs_append_fread_line(strbuf_ptr, stdin);
    CGS_Error e3 = cgs_read_line(strbuf_ptr);
    CGS_Error e4 = cgs_append_read_line(strbuf_ptr);
    (void)e1; (void)e2; (void)e3; (void)e4;
}

void test_1358(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e1 = cgs_fread_line(msr, stdin);
    CGS_Error e2 = cgs_append_fread_line(msr, stdin);
    CGS_Error e3 = cgs_read_line(msr);
    CGS_Error e4 = cgs_append_read_line(msr);
    (void)e1; (void)e2; (void)e3; (void)e4;
}

/* ===== cgs_sprint / cgs_sprint_append (mutstr) ===== */
void test_1359(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    cgs_sprint(cstr_ptr, 42, 3.14f, "hi", (double)1.0);
    cgs_sprint_append(cstr_ptr, 42, 3.14f, "hi");
}

void test_1360(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    cgs_sprint(ucstr_ptr, 42, 3.14f, "hi", (double)1.0);
    cgs_sprint_append(ucstr_ptr, 42, 3.14f, "hi");
}

void test_1361(void) {
    char cstr_arr[] = "hello";
    cgs_sprint(cstr_arr, 42, 3.14f, "hi", (double)1.0);
    cgs_sprint_append(cstr_arr, 42, 3.14f, "hi");
}

void test_1362(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    cgs_sprint(ucstr_arr, 42, 3.14f, "hi", (double)1.0);
    cgs_sprint_append(ucstr_arr, 42, 3.14f, "hi");
}

void test_1363(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    cgs_sprint(dstr_ptr, 42, 3.14f, "hi", (double)1.0);
    cgs_sprint_append(dstr_ptr, 42, 3.14f, "hi");
}

void test_1364(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    cgs_sprint(strbuf_ptr, 42, 3.14f, "hi", (double)1.0);
    cgs_sprint_append(strbuf_ptr, 42, 3.14f, "hi");
}

void test_1365(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    cgs_sprint(msr, 42, 3.14f, "hi", (double)1.0);
    cgs_sprint_append(msr, 42, 3.14f, "hi");
}

/* ===== dstr_ensure_cap ===== */
void test_1366(void) {
    DStr d = dstr_init();
    CGS_Error e = dstr_ensure_cap(&d, 128);
    (void)e; dstr_deinit(&d);
}

/* ===== cgs_appender / cgs_commit_appender (mutstr) ===== */
void test_1367(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    AppenderState state;
    MutStrRef appender = cgs_appender(cstr_ptr, &state);
    CGS_Error e = cgs_commit_appender(cstr_ptr, appender);
    (void)e;
}

void test_1368(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    AppenderState state;
    MutStrRef appender = cgs_appender(ucstr_ptr, &state);
    CGS_Error e = cgs_commit_appender(ucstr_ptr, appender);
    (void)e;
}

void test_1369(void) {
    char cstr_arr[] = "hello";
    AppenderState state;
    MutStrRef appender = cgs_appender(cstr_arr, &state);
    CGS_Error e = cgs_commit_appender(cstr_arr, appender);
    (void)e;
}

void test_1370(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    AppenderState state;
    MutStrRef appender = cgs_appender(ucstr_arr, &state);
    CGS_Error e = cgs_commit_appender(ucstr_arr, appender);
    (void)e;
}

void test_1371(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    AppenderState state;
    MutStrRef appender = cgs_appender(dstr_ptr, &state);
    CGS_Error e = cgs_commit_appender(dstr_ptr, appender);
    (void)e;
}

void test_1372(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    AppenderState state;
    MutStrRef appender = cgs_appender(strbuf_ptr, &state);
    CGS_Error e = cgs_commit_appender(strbuf_ptr, appender);
    (void)e;
}

void test_1373(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    AppenderState state;
    MutStrRef appender = cgs_appender(msr, &state);
    CGS_Error e = cgs_commit_appender(msr, appender);
    (void)e;
}

/* ===== tostr / tostr_p (mutstr x scalar) ===== */
void test_1374(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    int int_v = 42;
    { CGS_Error e = tostr(cstr_ptr, int_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_ptr, &int_v); (void)e; }
    unsigned int unsigned_int_v = 42u;
    { CGS_Error e = tostr(cstr_ptr, unsigned_int_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_ptr, &unsigned_int_v); (void)e; }
    long long_v = 42L;
    { CGS_Error e = tostr(cstr_ptr, long_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_ptr, &long_v); (void)e; }
    long long long_long_v = 42LL;
    { CGS_Error e = tostr(cstr_ptr, long_long_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_ptr, &long_long_v); (void)e; }
    float float_v = 3.14f;
    { CGS_Error e = tostr(cstr_ptr, float_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_ptr, &float_v); (void)e; }
    double double_v = 3.14;
    { CGS_Error e = tostr(cstr_ptr, double_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_ptr, &double_v); (void)e; }
}

void test_1375(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    int int_v = 42;
    { CGS_Error e = tostr(ucstr_ptr, int_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_ptr, &int_v); (void)e; }
    unsigned int unsigned_int_v = 42u;
    { CGS_Error e = tostr(ucstr_ptr, unsigned_int_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_ptr, &unsigned_int_v); (void)e; }
    long long_v = 42L;
    { CGS_Error e = tostr(ucstr_ptr, long_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_ptr, &long_v); (void)e; }
    long long long_long_v = 42LL;
    { CGS_Error e = tostr(ucstr_ptr, long_long_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_ptr, &long_long_v); (void)e; }
    float float_v = 3.14f;
    { CGS_Error e = tostr(ucstr_ptr, float_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_ptr, &float_v); (void)e; }
    double double_v = 3.14;
    { CGS_Error e = tostr(ucstr_ptr, double_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_ptr, &double_v); (void)e; }
}

void test_1376(void) {
    char cstr_arr[] = "hello";
    int int_v = 42;
    { CGS_Error e = tostr(cstr_arr, int_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_arr, &int_v); (void)e; }
    unsigned int unsigned_int_v = 42u;
    { CGS_Error e = tostr(cstr_arr, unsigned_int_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_arr, &unsigned_int_v); (void)e; }
    long long_v = 42L;
    { CGS_Error e = tostr(cstr_arr, long_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_arr, &long_v); (void)e; }
    long long long_long_v = 42LL;
    { CGS_Error e = tostr(cstr_arr, long_long_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_arr, &long_long_v); (void)e; }
    float float_v = 3.14f;
    { CGS_Error e = tostr(cstr_arr, float_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_arr, &float_v); (void)e; }
    double double_v = 3.14;
    { CGS_Error e = tostr(cstr_arr, double_v); (void)e; }
    { CGS_Error e = tostr_p(cstr_arr, &double_v); (void)e; }
}

void test_1377(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    int int_v = 42;
    { CGS_Error e = tostr(ucstr_arr, int_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_arr, &int_v); (void)e; }
    unsigned int unsigned_int_v = 42u;
    { CGS_Error e = tostr(ucstr_arr, unsigned_int_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_arr, &unsigned_int_v); (void)e; }
    long long_v = 42L;
    { CGS_Error e = tostr(ucstr_arr, long_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_arr, &long_v); (void)e; }
    long long long_long_v = 42LL;
    { CGS_Error e = tostr(ucstr_arr, long_long_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_arr, &long_long_v); (void)e; }
    float float_v = 3.14f;
    { CGS_Error e = tostr(ucstr_arr, float_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_arr, &float_v); (void)e; }
    double double_v = 3.14;
    { CGS_Error e = tostr(ucstr_arr, double_v); (void)e; }
    { CGS_Error e = tostr_p(ucstr_arr, &double_v); (void)e; }
}

void test_1378(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    int int_v = 42;
    { CGS_Error e = tostr(dstr_ptr, int_v); (void)e; }
    { CGS_Error e = tostr_p(dstr_ptr, &int_v); (void)e; }
    unsigned int unsigned_int_v = 42u;
    { CGS_Error e = tostr(dstr_ptr, unsigned_int_v); (void)e; }
    { CGS_Error e = tostr_p(dstr_ptr, &unsigned_int_v); (void)e; }
    long long_v = 42L;
    { CGS_Error e = tostr(dstr_ptr, long_v); (void)e; }
    { CGS_Error e = tostr_p(dstr_ptr, &long_v); (void)e; }
    long long long_long_v = 42LL;
    { CGS_Error e = tostr(dstr_ptr, long_long_v); (void)e; }
    { CGS_Error e = tostr_p(dstr_ptr, &long_long_v); (void)e; }
    float float_v = 3.14f;
    { CGS_Error e = tostr(dstr_ptr, float_v); (void)e; }
    { CGS_Error e = tostr_p(dstr_ptr, &float_v); (void)e; }
    double double_v = 3.14;
    { CGS_Error e = tostr(dstr_ptr, double_v); (void)e; }
    { CGS_Error e = tostr_p(dstr_ptr, &double_v); (void)e; }
}

void test_1379(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    int int_v = 42;
    { CGS_Error e = tostr(strbuf_ptr, int_v); (void)e; }
    { CGS_Error e = tostr_p(strbuf_ptr, &int_v); (void)e; }
    unsigned int unsigned_int_v = 42u;
    { CGS_Error e = tostr(strbuf_ptr, unsigned_int_v); (void)e; }
    { CGS_Error e = tostr_p(strbuf_ptr, &unsigned_int_v); (void)e; }
    long long_v = 42L;
    { CGS_Error e = tostr(strbuf_ptr, long_v); (void)e; }
    { CGS_Error e = tostr_p(strbuf_ptr, &long_v); (void)e; }
    long long long_long_v = 42LL;
    { CGS_Error e = tostr(strbuf_ptr, long_long_v); (void)e; }
    { CGS_Error e = tostr_p(strbuf_ptr, &long_long_v); (void)e; }
    float float_v = 3.14f;
    { CGS_Error e = tostr(strbuf_ptr, float_v); (void)e; }
    { CGS_Error e = tostr_p(strbuf_ptr, &float_v); (void)e; }
    double double_v = 3.14;
    { CGS_Error e = tostr(strbuf_ptr, double_v); (void)e; }
    { CGS_Error e = tostr_p(strbuf_ptr, &double_v); (void)e; }
}

void test_1380(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    int int_v = 42;
    { CGS_Error e = tostr(msr, int_v); (void)e; }
    { CGS_Error e = tostr_p(msr, &int_v); (void)e; }
    unsigned int unsigned_int_v = 42u;
    { CGS_Error e = tostr(msr, unsigned_int_v); (void)e; }
    { CGS_Error e = tostr_p(msr, &unsigned_int_v); (void)e; }
    long long_v = 42L;
    { CGS_Error e = tostr(msr, long_v); (void)e; }
    { CGS_Error e = tostr_p(msr, &long_v); (void)e; }
    long long long_long_v = 42LL;
    { CGS_Error e = tostr(msr, long_long_v); (void)e; }
    { CGS_Error e = tostr_p(msr, &long_long_v); (void)e; }
    float float_v = 3.14f;
    { CGS_Error e = tostr(msr, float_v); (void)e; }
    { CGS_Error e = tostr_p(msr, &float_v); (void)e; }
    double double_v = 3.14;
    { CGS_Error e = tostr(msr, double_v); (void)e; }
    { CGS_Error e = tostr_p(msr, &double_v); (void)e; }
}

/* ===== tostr (mutstr x anystr) ===== */
void test_1381(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    CGS_Error e = tostr(cstr_ptr, cstr_ptr);
    (void)e;
}

void test_1382(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = tostr(cstr_ptr, ucstr_ptr);
    (void)e;
}

void test_1383(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = tostr(cstr_ptr, cstr_arr);
    (void)e;
}

void test_1384(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = tostr(cstr_ptr, ucstr_arr);
    (void)e;
}

void test_1385(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = tostr(cstr_ptr, sv);
    (void)e;
}

void test_1386(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = tostr(cstr_ptr, dstr_val);
    (void)e;
}

void test_1387(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(cstr_ptr, dstr_ptr);
    (void)e;
}

void test_1388(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = tostr(cstr_ptr, strbuf_val);
    (void)e;
}

void test_1389(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(cstr_ptr, strbuf_ptr);
    (void)e;
}

void test_1390(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(cstr_ptr, msr);
    (void)e;
}

void test_1391(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = tostr(ucstr_ptr, cstr_ptr);
    (void)e;
}

void test_1392(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    CGS_Error e = tostr(ucstr_ptr, ucstr_ptr);
    (void)e;
}

void test_1393(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = tostr(ucstr_ptr, cstr_arr);
    (void)e;
}

void test_1394(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = tostr(ucstr_ptr, ucstr_arr);
    (void)e;
}

void test_1395(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    StrView sv = strv("hello");
    CGS_Error e = tostr(ucstr_ptr, sv);
    (void)e;
}

void test_1396(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = tostr(ucstr_ptr, dstr_val);
    (void)e;
}

void test_1397(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(ucstr_ptr, dstr_ptr);
    (void)e;
}

void test_1398(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = tostr(ucstr_ptr, strbuf_val);
    (void)e;
}

void test_1399(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(ucstr_ptr, strbuf_ptr);
    (void)e;
}

void test_1400(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(ucstr_ptr, msr);
    (void)e;
}

void test_1401(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = tostr(cstr_arr, cstr_ptr);
    (void)e;
}

void test_1402(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char cstr_arr[] = "hello";
    CGS_Error e = tostr(cstr_arr, ucstr_ptr);
    (void)e;
}

void test_1403(void) {
    char cstr_arr[] = "hello";
    CGS_Error e = tostr(cstr_arr, cstr_arr);
    (void)e;
}

void test_1404(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = tostr(cstr_arr, ucstr_arr);
    (void)e;
}

void test_1405(void) {
    char cstr_arr[] = "hello";
    StrView sv = strv("hello");
    CGS_Error e = tostr(cstr_arr, sv);
    (void)e;
}

void test_1406(void) {
    char cstr_arr[] = "hello";
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = tostr(cstr_arr, dstr_val);
    (void)e;
}

void test_1407(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(cstr_arr, dstr_ptr);
    (void)e;
}

void test_1408(void) {
    char cstr_arr[] = "hello";
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = tostr(cstr_arr, strbuf_val);
    (void)e;
}

void test_1409(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(cstr_arr, strbuf_ptr);
    (void)e;
}

void test_1410(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(cstr_arr, msr);
    (void)e;
}

void test_1411(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = tostr(ucstr_arr, cstr_ptr);
    (void)e;
}

void test_1412(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = tostr(ucstr_arr, ucstr_ptr);
    (void)e;
}

void test_1413(void) {
    char cstr_arr[] = "hello";
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = tostr(ucstr_arr, cstr_arr);
    (void)e;
}

void test_1414(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    CGS_Error e = tostr(ucstr_arr, ucstr_arr);
    (void)e;
}

void test_1415(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    StrView sv = strv("hello");
    CGS_Error e = tostr(ucstr_arr, sv);
    (void)e;
}

void test_1416(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_val = dstr_init_from("hello", NULL);
    CGS_Error e = tostr(ucstr_arr, dstr_val);
    (void)e;
}

void test_1417(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(ucstr_arr, dstr_ptr);
    (void)e;
}

void test_1418(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = tostr(ucstr_arr, strbuf_val);
    (void)e;
}

void test_1419(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(ucstr_arr, strbuf_ptr);
    (void)e;
}

void test_1420(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(ucstr_arr, msr);
    (void)e;
}

void test_1421(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, cstr_ptr);
    (void)e;
}

void test_1422(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, ucstr_ptr);
    (void)e;
}

void test_1423(void) {
    char cstr_arr[] = "hello";
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, cstr_arr);
    (void)e;
}

void test_1424(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, ucstr_arr);
    (void)e;
}

void test_1425(void) {
    StrView sv = strv("hello");
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, sv);
    (void)e;
}

void test_1426(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, dstr_val);
    (void)e;
}

void test_1427(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, dstr_ptr);
    (void)e;
}

void test_1428(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    CGS_Error e = tostr(dstr_ptr, strbuf_val);
    (void)e;
}

void test_1429(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(dstr_ptr, strbuf_ptr);
    (void)e;
}

void test_1430(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(dstr_ptr, msr);
    (void)e;
}

void test_1431(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, cstr_ptr);
    (void)e;
}

void test_1432(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, ucstr_ptr);
    (void)e;
}

void test_1433(void) {
    char cstr_arr[] = "hello";
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, cstr_arr);
    (void)e;
}

void test_1434(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, ucstr_arr);
    (void)e;
}

void test_1435(void) {
    StrView sv = strv("hello");
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, sv);
    (void)e;
}

void test_1436(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, dstr_val);
    (void)e;
}

void test_1437(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, dstr_ptr);
    (void)e;
}

void test_1438(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, strbuf_val);
    (void)e;
}

void test_1439(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    CGS_Error e = tostr(strbuf_ptr, strbuf_ptr);
    (void)e;
}

void test_1440(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(strbuf_ptr, msr);
    (void)e;
}

void test_1441(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, cstr_ptr);
    (void)e;
}

void test_1442(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, ucstr_ptr);
    (void)e;
}

void test_1443(void) {
    char cstr_arr[] = "hello";
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, cstr_arr);
    (void)e;
}

void test_1444(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, ucstr_arr);
    (void)e;
}

void test_1445(void) {
    StrView sv = strv("hello");
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, sv);
    (void)e;
}

void test_1446(void) {
    DStr dstr_val = dstr_init_from("hello", NULL);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, dstr_val);
    (void)e;
}

void test_1447(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, dstr_ptr);
    (void)e;
}

void test_1448(void) {
    char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, strbuf_val);
    (void)e;
}

void test_1449(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, strbuf_ptr);
    (void)e;
}

void test_1450(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    CGS_Error e = tostr(msr, msr);
    (void)e;
}

/* ===== print / println / fprint / fprintln ===== */
void test_1451(void) {
    print(42, " ", 3.14, " ", "hello");
    println(42, " ", 3.14);
    fprint(stdout, 42, " ", "world");
    fprintln(stdout, 1, 2, 3);
}

/* ===== tsfmt / arrfmt — construction and tostr ===== */
void test_1452(void) {
    tsfmt_t(int, 'x')   hex_val  = tsfmt(255, 'x');
    tsfmt_t(int, 'o')   oct_val  = tsfmt(255, 'o');
    tsfmt_t(float, 'e') sci_valf = tsfmt(3.14f, 'e', 2);
    tsfmt_t(double,'a') hex_vald = tsfmt(3.14, 'a');
    int arr_data[] = {1, 2, 3};
    ArrayFmt af1 = arrfmt(arr_data, 3);
    ArrayFmt af2 = arrfmt(arr_data, 3, "[", "]", ", ", ",");
    print(hex_val, " ", oct_val, " ", sci_valf, " ", hex_vald);
    println(af1, " ", af2);
    fprint(stdout, hex_val, " ", af1);
    fprintln(stdout, oct_val, " ", af2);
}

/* ===== tsfmt / arrfmt via tostr / cgs_sprint (mutstr) ===== */
void test_1453(void) {
    char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;
    tsfmt_t(int, 'x') hex_v = tsfmt(255, 'x');
    tsfmt_t(double, 'e') sci_v = tsfmt(1.5, 'e', 3);
    int arr_d[] = {1, 2, 3};
    ArrayFmt af = arrfmt(arr_d, 3);
    { CGS_Error e = tostr(cstr_ptr, hex_v); (void)e; }
    { CGS_Error e = tostr(cstr_ptr, sci_v); (void)e; }
    { CGS_Error e = tostr(cstr_ptr, af);    (void)e; }
    cgs_sprint(cstr_ptr, hex_v, " ", sci_v, " ", af);
    cgs_sprint_append(cstr_ptr, af, " ", hex_v);
}

void test_1454(void) {
    unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;
    tsfmt_t(int, 'x') hex_v = tsfmt(255, 'x');
    tsfmt_t(double, 'e') sci_v = tsfmt(1.5, 'e', 3);
    int arr_d[] = {1, 2, 3};
    ArrayFmt af = arrfmt(arr_d, 3);
    { CGS_Error e = tostr(ucstr_ptr, hex_v); (void)e; }
    { CGS_Error e = tostr(ucstr_ptr, sci_v); (void)e; }
    { CGS_Error e = tostr(ucstr_ptr, af);    (void)e; }
    cgs_sprint(ucstr_ptr, hex_v, " ", sci_v, " ", af);
    cgs_sprint_append(ucstr_ptr, af, " ", hex_v);
}

void test_1455(void) {
    char cstr_arr[] = "hello";
    tsfmt_t(int, 'x') hex_v = tsfmt(255, 'x');
    tsfmt_t(double, 'e') sci_v = tsfmt(1.5, 'e', 3);
    int arr_d[] = {1, 2, 3};
    ArrayFmt af = arrfmt(arr_d, 3);
    { CGS_Error e = tostr(cstr_arr, hex_v); (void)e; }
    { CGS_Error e = tostr(cstr_arr, sci_v); (void)e; }
    { CGS_Error e = tostr(cstr_arr, af);    (void)e; }
    cgs_sprint(cstr_arr, hex_v, " ", sci_v, " ", af);
    cgs_sprint_append(cstr_arr, af, " ", hex_v);
}

void test_1456(void) {
    unsigned char ucstr_arr[] = {'h','i',0};
    tsfmt_t(int, 'x') hex_v = tsfmt(255, 'x');
    tsfmt_t(double, 'e') sci_v = tsfmt(1.5, 'e', 3);
    int arr_d[] = {1, 2, 3};
    ArrayFmt af = arrfmt(arr_d, 3);
    { CGS_Error e = tostr(ucstr_arr, hex_v); (void)e; }
    { CGS_Error e = tostr(ucstr_arr, sci_v); (void)e; }
    { CGS_Error e = tostr(ucstr_arr, af);    (void)e; }
    cgs_sprint(ucstr_arr, hex_v, " ", sci_v, " ", af);
    cgs_sprint_append(ucstr_arr, af, " ", hex_v);
}

void test_1457(void) {
    DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;
    tsfmt_t(int, 'x') hex_v = tsfmt(255, 'x');
    tsfmt_t(double, 'e') sci_v = tsfmt(1.5, 'e', 3);
    int arr_d[] = {1, 2, 3};
    ArrayFmt af = arrfmt(arr_d, 3);
    { CGS_Error e = tostr(dstr_ptr, hex_v); (void)e; }
    { CGS_Error e = tostr(dstr_ptr, sci_v); (void)e; }
    { CGS_Error e = tostr(dstr_ptr, af);    (void)e; }
    cgs_sprint(dstr_ptr, hex_v, " ", sci_v, " ", af);
    cgs_sprint_append(dstr_ptr, af, " ", hex_v);
}

void test_1458(void) {
    char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;
    tsfmt_t(int, 'x') hex_v = tsfmt(255, 'x');
    tsfmt_t(double, 'e') sci_v = tsfmt(1.5, 'e', 3);
    int arr_d[] = {1, 2, 3};
    ArrayFmt af = arrfmt(arr_d, 3);
    { CGS_Error e = tostr(strbuf_ptr, hex_v); (void)e; }
    { CGS_Error e = tostr(strbuf_ptr, sci_v); (void)e; }
    { CGS_Error e = tostr(strbuf_ptr, af);    (void)e; }
    cgs_sprint(strbuf_ptr, hex_v, " ", sci_v, " ", af);
    cgs_sprint_append(strbuf_ptr, af, " ", hex_v);
}

void test_1459(void) {
    char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);
    tsfmt_t(int, 'x') hex_v = tsfmt(255, 'x');
    tsfmt_t(double, 'e') sci_v = tsfmt(1.5, 'e', 3);
    int arr_d[] = {1, 2, 3};
    ArrayFmt af = arrfmt(arr_d, 3);
    { CGS_Error e = tostr(msr, hex_v); (void)e; }
    { CGS_Error e = tostr(msr, sci_v); (void)e; }
    { CGS_Error e = tostr(msr, af);    (void)e; }
    cgs_sprint(msr, hex_v, " ", sci_v, " ", af);
    cgs_sprint_append(msr, af, " ", hex_v);
}

/* 1459 test functions generated */
int main(void) { return 0; }
