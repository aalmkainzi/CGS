#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#define CGS_SHORT_NAMES
#include "cgs.c"

void test_00001_anystr_read_ptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_len(ptr);
    cgs_cap(ptr);
    cgs_chars(ptr);
    CGS_DStr dupped = cgs_dup(ptr, NULL);
    cgs_find(ptr, "a");
    cgs_starts_with(ptr, "a");
    cgs_ends_with(ptr, "a");
}

void test_00002_anystr_read_uptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_len(uptr);
    cgs_cap(uptr);
    cgs_chars(uptr);
    CGS_DStr dupped = cgs_dup(uptr, NULL);
    cgs_find(uptr, "a");
    cgs_starts_with(uptr, "a");
    cgs_ends_with(uptr, "a");
}

void test_00003_anystr_read_arr(void) {
    char arr[] = "a";
    cgs_len(arr);
    cgs_cap(arr);
    cgs_chars(arr);
    CGS_DStr dupped = cgs_dup(arr, NULL);
    cgs_find(arr, "a");
    cgs_starts_with(arr, "a");
    cgs_ends_with(arr, "a");
}

void test_00004_anystr_read_uarr(void) {
    unsigned char uarr[] = "a";
    cgs_len(uarr);
    cgs_cap(uarr);
    cgs_chars(uarr);
    CGS_DStr dupped = cgs_dup(uarr, NULL);
    cgs_find(uarr, "a");
    cgs_starts_with(uarr, "a");
    cgs_ends_with(uarr, "a");
}

void test_00005_anystr_read_sv(void) {
    CGS_StrView sv = cgs_strv("a");
    cgs_len(sv);
    cgs_cap(sv);
    cgs_chars(sv);
    CGS_DStr dupped = cgs_dup(sv, NULL);
    cgs_find(sv, "a");
    cgs_starts_with(sv, "a");
    cgs_ends_with(sv, "a");
}

void test_00006_anystr_read_ds(void) {
    CGS_DStr ds = cgs_dstr_init();
    cgs_len(ds);
    cgs_cap(ds);
    cgs_chars(ds);
    CGS_DStr dupped = cgs_dup(ds, NULL);
    cgs_find(ds, "a");
    cgs_starts_with(ds, "a");
    cgs_ends_with(ds, "a");
    cgs_dstr_deinit(&ds);
}

void test_00007_anystr_read_pds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_len(pds);
    cgs_cap(pds);
    cgs_chars(pds);
    CGS_DStr dupped = cgs_dup(pds, NULL);
    cgs_find(pds, "a");
    cgs_starts_with(pds, "a");
    cgs_ends_with(pds, "a");
    cgs_dstr_deinit(&ds_o);
}

void test_00008_anystr_read_sb(void) {
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_len(sb);
    cgs_cap(sb);
    cgs_chars(sb);
    CGS_DStr dupped = cgs_dup(sb, NULL);
    cgs_find(sb, "a");
    cgs_starts_with(sb, "a");
    cgs_ends_with(sb, "a");
}

void test_00009_anystr_read_psb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_len(psb);
    cgs_cap(psb);
    cgs_chars(psb);
    CGS_DStr dupped = cgs_dup(psb, NULL);
    cgs_find(psb, "a");
    cgs_starts_with(psb, "a");
    cgs_ends_with(psb, "a");
}

void test_00010_anystr_read_msr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_len(msr);
    cgs_cap(msr);
    cgs_chars(msr);
    CGS_DStr dupped = cgs_dup(msr, NULL);
    cgs_find(msr, "a");
    cgs_starts_with(msr, "a");
    cgs_ends_with(msr, "a");
}

void test_00011_mutstr_write_ptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_clear(ptr);
    cgs_tolower(ptr);
    cgs_toupper(ptr);
    cgs_del(ptr, 0, 1);
}

void test_00012_mutstr_write_uptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_clear(uptr);
    cgs_tolower(uptr);
    cgs_toupper(uptr);
    cgs_del(uptr, 0, 1);
}

void test_00013_mutstr_write_arr(void) {
    char arr[] = "a";
    cgs_clear(arr);
    cgs_tolower(arr);
    cgs_toupper(arr);
    cgs_del(arr, 0, 1);
}

void test_00014_mutstr_write_uarr(void) {
    unsigned char uarr[] = "a";
    cgs_clear(uarr);
    cgs_tolower(uarr);
    cgs_toupper(uarr);
    cgs_del(uarr, 0, 1);
}

void test_00015_mutstr_write_pds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_clear(pds);
    cgs_tolower(pds);
    cgs_toupper(pds);
    cgs_del(pds, 0, 1);
    cgs_dstr_deinit(&ds_o);
}

void test_00016_mutstr_write_psb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_clear(psb);
    cgs_tolower(psb);
    cgs_toupper(psb);
    cgs_del(psb, 0, 1);
}

void test_00017_mutstr_write_msr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_clear(msr);
    cgs_tolower(msr);
    cgs_toupper(msr);
    cgs_del(msr, 0, 1);
}

void test_00018_writer_cross_ptr_ptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(ptr, '!');
    cgs_append(ptr, ptr);
    cgs_tostr_append(ptr, 42);
}

void test_00019_writer_cross_ptr_uptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(ptr, '!');
    cgs_append(ptr, uptr);
    cgs_tostr_append(ptr, 42);
}

void test_00020_writer_cross_ptr_arr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char arr[] = "a";
    cgs_putc(ptr, '!');
    cgs_append(ptr, arr);
    cgs_tostr_append(ptr, 42);
}

void test_00021_writer_cross_ptr_uarr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    unsigned char uarr[] = "a";
    cgs_putc(ptr, '!');
    cgs_append(ptr, uarr);
    cgs_tostr_append(ptr, 42);
}

void test_00022_writer_cross_ptr_sv(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(ptr, '!');
    cgs_append(ptr, sv);
    cgs_tostr_append(ptr, 42);
}

void test_00023_writer_cross_ptr_ds(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(ptr, '!');
    cgs_append(ptr, ds);
    cgs_tostr_append(ptr, 42);
    cgs_dstr_deinit(&ds);
}

void test_00024_writer_cross_ptr_pds(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(ptr, '!');
    cgs_append(ptr, pds);
    cgs_tostr_append(ptr, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00025_writer_cross_ptr_sb(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(ptr, '!');
    cgs_append(ptr, sb);
    cgs_tostr_append(ptr, 42);
}

void test_00026_writer_cross_ptr_psb(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(ptr, '!');
    cgs_append(ptr, psb);
    cgs_tostr_append(ptr, 42);
}

void test_00027_writer_cross_ptr_msr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(ptr, '!');
    cgs_append(ptr, msr);
    cgs_tostr_append(ptr, 42);
}

void test_00028_writer_cross_uptr_ptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(uptr, '!');
    cgs_append(uptr, ptr);
    cgs_tostr_append(uptr, 42);
}

void test_00029_writer_cross_uptr_uptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(uptr, '!');
    cgs_append(uptr, uptr);
    cgs_tostr_append(uptr, 42);
}

void test_00030_writer_cross_uptr_arr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char arr[] = "a";
    cgs_putc(uptr, '!');
    cgs_append(uptr, arr);
    cgs_tostr_append(uptr, 42);
}

void test_00031_writer_cross_uptr_uarr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    unsigned char uarr[] = "a";
    cgs_putc(uptr, '!');
    cgs_append(uptr, uarr);
    cgs_tostr_append(uptr, 42);
}

void test_00032_writer_cross_uptr_sv(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(uptr, '!');
    cgs_append(uptr, sv);
    cgs_tostr_append(uptr, 42);
}

void test_00033_writer_cross_uptr_ds(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(uptr, '!');
    cgs_append(uptr, ds);
    cgs_tostr_append(uptr, 42);
    cgs_dstr_deinit(&ds);
}

void test_00034_writer_cross_uptr_pds(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(uptr, '!');
    cgs_append(uptr, pds);
    cgs_tostr_append(uptr, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00035_writer_cross_uptr_sb(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(uptr, '!');
    cgs_append(uptr, sb);
    cgs_tostr_append(uptr, 42);
}

void test_00036_writer_cross_uptr_psb(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(uptr, '!');
    cgs_append(uptr, psb);
    cgs_tostr_append(uptr, 42);
}

void test_00037_writer_cross_uptr_msr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(uptr, '!');
    cgs_append(uptr, msr);
    cgs_tostr_append(uptr, 42);
}

void test_00038_writer_cross_arr_ptr(void) {
    char arr[] = "a";
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(arr, '!');
    cgs_append(arr, ptr);
    cgs_tostr_append(arr, 42);
}

void test_00039_writer_cross_arr_uptr(void) {
    char arr[] = "a";
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(arr, '!');
    cgs_append(arr, uptr);
    cgs_tostr_append(arr, 42);
}

void test_00040_writer_cross_arr_arr(void) {
    char arr[] = "a";
    cgs_putc(arr, '!');
    cgs_append(arr, arr);
    cgs_tostr_append(arr, 42);
}

void test_00041_writer_cross_arr_uarr(void) {
    char arr[] = "a";
    unsigned char uarr[] = "a";
    cgs_putc(arr, '!');
    cgs_append(arr, uarr);
    cgs_tostr_append(arr, 42);
}

void test_00042_writer_cross_arr_sv(void) {
    char arr[] = "a";
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(arr, '!');
    cgs_append(arr, sv);
    cgs_tostr_append(arr, 42);
}

void test_00043_writer_cross_arr_ds(void) {
    char arr[] = "a";
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(arr, '!');
    cgs_append(arr, ds);
    cgs_tostr_append(arr, 42);
    cgs_dstr_deinit(&ds);
}

void test_00044_writer_cross_arr_pds(void) {
    char arr[] = "a";
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(arr, '!');
    cgs_append(arr, pds);
    cgs_tostr_append(arr, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00045_writer_cross_arr_sb(void) {
    char arr[] = "a";
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(arr, '!');
    cgs_append(arr, sb);
    cgs_tostr_append(arr, 42);
}

void test_00046_writer_cross_arr_psb(void) {
    char arr[] = "a";
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(arr, '!');
    cgs_append(arr, psb);
    cgs_tostr_append(arr, 42);
}

void test_00047_writer_cross_arr_msr(void) {
    char arr[] = "a";
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(arr, '!');
    cgs_append(arr, msr);
    cgs_tostr_append(arr, 42);
}

void test_00048_writer_cross_uarr_ptr(void) {
    unsigned char uarr[] = "a";
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(uarr, '!');
    cgs_append(uarr, ptr);
    cgs_tostr_append(uarr, 42);
}

void test_00049_writer_cross_uarr_uptr(void) {
    unsigned char uarr[] = "a";
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(uarr, '!');
    cgs_append(uarr, uptr);
    cgs_tostr_append(uarr, 42);
}

void test_00050_writer_cross_uarr_arr(void) {
    unsigned char uarr[] = "a";
    char arr[] = "a";
    cgs_putc(uarr, '!');
    cgs_append(uarr, arr);
    cgs_tostr_append(uarr, 42);
}

void test_00051_writer_cross_uarr_uarr(void) {
    unsigned char uarr[] = "a";
    cgs_putc(uarr, '!');
    cgs_append(uarr, uarr);
    cgs_tostr_append(uarr, 42);
}

void test_00052_writer_cross_uarr_sv(void) {
    unsigned char uarr[] = "a";
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(uarr, '!');
    cgs_append(uarr, sv);
    cgs_tostr_append(uarr, 42);
}

void test_00053_writer_cross_uarr_ds(void) {
    unsigned char uarr[] = "a";
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(uarr, '!');
    cgs_append(uarr, ds);
    cgs_tostr_append(uarr, 42);
    cgs_dstr_deinit(&ds);
}

void test_00054_writer_cross_uarr_pds(void) {
    unsigned char uarr[] = "a";
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(uarr, '!');
    cgs_append(uarr, pds);
    cgs_tostr_append(uarr, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00055_writer_cross_uarr_sb(void) {
    unsigned char uarr[] = "a";
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(uarr, '!');
    cgs_append(uarr, sb);
    cgs_tostr_append(uarr, 42);
}

void test_00056_writer_cross_uarr_psb(void) {
    unsigned char uarr[] = "a";
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(uarr, '!');
    cgs_append(uarr, psb);
    cgs_tostr_append(uarr, 42);
}

void test_00057_writer_cross_uarr_msr(void) {
    unsigned char uarr[] = "a";
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(uarr, '!');
    cgs_append(uarr, msr);
    cgs_tostr_append(uarr, 42);
}

void test_00058_writer_cross_pds_ptr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(pds, '!');
    cgs_append(pds, ptr);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00059_writer_cross_pds_uptr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(pds, '!');
    cgs_append(pds, uptr);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00060_writer_cross_pds_arr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char arr[] = "a";
    cgs_putc(pds, '!');
    cgs_append(pds, arr);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00061_writer_cross_pds_uarr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    unsigned char uarr[] = "a";
    cgs_putc(pds, '!');
    cgs_append(pds, uarr);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00062_writer_cross_pds_sv(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(pds, '!');
    cgs_append(pds, sv);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00063_writer_cross_pds_ds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(pds, '!');
    cgs_append(pds, ds);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds);
    cgs_dstr_deinit(&ds_o);
}

void test_00064_writer_cross_pds_pds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(pds, '!');
    cgs_append(pds, pds);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00065_writer_cross_pds_sb(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(pds, '!');
    cgs_append(pds, sb);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00066_writer_cross_pds_psb(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(pds, '!');
    cgs_append(pds, psb);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00067_writer_cross_pds_msr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(pds, '!');
    cgs_append(pds, msr);
    cgs_tostr_append(pds, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00068_writer_cross_psb_ptr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(psb, '!');
    cgs_append(psb, ptr);
    cgs_tostr_append(psb, 42);
}

void test_00069_writer_cross_psb_uptr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(psb, '!');
    cgs_append(psb, uptr);
    cgs_tostr_append(psb, 42);
}

void test_00070_writer_cross_psb_arr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char arr[] = "a";
    cgs_putc(psb, '!');
    cgs_append(psb, arr);
    cgs_tostr_append(psb, 42);
}

void test_00071_writer_cross_psb_uarr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    unsigned char uarr[] = "a";
    cgs_putc(psb, '!');
    cgs_append(psb, uarr);
    cgs_tostr_append(psb, 42);
}

void test_00072_writer_cross_psb_sv(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(psb, '!');
    cgs_append(psb, sv);
    cgs_tostr_append(psb, 42);
}

void test_00073_writer_cross_psb_ds(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(psb, '!');
    cgs_append(psb, ds);
    cgs_tostr_append(psb, 42);
    cgs_dstr_deinit(&ds);
}

void test_00074_writer_cross_psb_pds(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(psb, '!');
    cgs_append(psb, pds);
    cgs_tostr_append(psb, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00075_writer_cross_psb_sb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(psb, '!');
    cgs_append(psb, sb);
    cgs_tostr_append(psb, 42);
}

void test_00076_writer_cross_psb_psb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(psb, '!');
    cgs_append(psb, psb);
    cgs_tostr_append(psb, 42);
}

void test_00077_writer_cross_psb_msr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(psb, '!');
    cgs_append(psb, msr);
    cgs_tostr_append(psb, 42);
}

void test_00078_writer_cross_msr_ptr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(msr, '!');
    cgs_append(msr, ptr);
    cgs_tostr_append(msr, 42);
}

void test_00079_writer_cross_msr_uptr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(msr, '!');
    cgs_append(msr, uptr);
    cgs_tostr_append(msr, 42);
}

void test_00080_writer_cross_msr_arr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char arr[] = "a";
    cgs_putc(msr, '!');
    cgs_append(msr, arr);
    cgs_tostr_append(msr, 42);
}

void test_00081_writer_cross_msr_uarr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    unsigned char uarr[] = "a";
    cgs_putc(msr, '!');
    cgs_append(msr, uarr);
    cgs_tostr_append(msr, 42);
}

void test_00082_writer_cross_msr_sv(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(msr, '!');
    cgs_append(msr, sv);
    cgs_tostr_append(msr, 42);
}

void test_00083_writer_cross_msr_ds(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(msr, '!');
    cgs_append(msr, ds);
    cgs_tostr_append(msr, 42);
    cgs_dstr_deinit(&ds);
}

void test_00084_writer_cross_msr_pds(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(msr, '!');
    cgs_append(msr, pds);
    cgs_tostr_append(msr, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00085_writer_cross_msr_sb(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(msr, '!');
    cgs_append(msr, sb);
    cgs_tostr_append(msr, 42);
}

void test_00086_writer_cross_msr_psb(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(msr, '!');
    cgs_append(msr, psb);
    cgs_tostr_append(msr, 42);
}

void test_00087_writer_cross_msr_msr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(msr, '!');
    cgs_append(msr, msr);
    cgs_tostr_append(msr, 42);
}

void test_00088_writer_cross_fp_ptr(void) {
    FILE *fp = stdout;
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(fp, '!');
    cgs_append(fp, ptr);
    cgs_tostr_append(fp, 42);
}

void test_00089_writer_cross_fp_uptr(void) {
    FILE *fp = stdout;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(fp, '!');
    cgs_append(fp, uptr);
    cgs_tostr_append(fp, 42);
}

void test_00090_writer_cross_fp_arr(void) {
    FILE *fp = stdout;
    char arr[] = "a";
    cgs_putc(fp, '!');
    cgs_append(fp, arr);
    cgs_tostr_append(fp, 42);
}

void test_00091_writer_cross_fp_uarr(void) {
    FILE *fp = stdout;
    unsigned char uarr[] = "a";
    cgs_putc(fp, '!');
    cgs_append(fp, uarr);
    cgs_tostr_append(fp, 42);
}

void test_00092_writer_cross_fp_sv(void) {
    FILE *fp = stdout;
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(fp, '!');
    cgs_append(fp, sv);
    cgs_tostr_append(fp, 42);
}

void test_00093_writer_cross_fp_ds(void) {
    FILE *fp = stdout;
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(fp, '!');
    cgs_append(fp, ds);
    cgs_tostr_append(fp, 42);
    cgs_dstr_deinit(&ds);
}

void test_00094_writer_cross_fp_pds(void) {
    FILE *fp = stdout;
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(fp, '!');
    cgs_append(fp, pds);
    cgs_tostr_append(fp, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00095_writer_cross_fp_sb(void) {
    FILE *fp = stdout;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(fp, '!');
    cgs_append(fp, sb);
    cgs_tostr_append(fp, 42);
}

void test_00096_writer_cross_fp_psb(void) {
    FILE *fp = stdout;
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(fp, '!');
    cgs_append(fp, psb);
    cgs_tostr_append(fp, 42);
}

void test_00097_writer_cross_fp_msr(void) {
    FILE *fp = stdout;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(fp, '!');
    cgs_append(fp, msr);
    cgs_tostr_append(fp, 42);
}

void test_00098_writer_cross_wr_ptr(void) {
    CGS_Writer wr = cgs_writer(stdout);
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_putc(wr, '!');
    cgs_append(wr, ptr);
    cgs_tostr_append(wr, 42);
}

void test_00099_writer_cross_wr_uptr(void) {
    CGS_Writer wr = cgs_writer(stdout);
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_putc(wr, '!');
    cgs_append(wr, uptr);
    cgs_tostr_append(wr, 42);
}

void test_00100_writer_cross_wr_arr(void) {
    CGS_Writer wr = cgs_writer(stdout);
    char arr[] = "a";
    cgs_putc(wr, '!');
    cgs_append(wr, arr);
    cgs_tostr_append(wr, 42);
}

void test_00101_writer_cross_wr_uarr(void) {
    CGS_Writer wr = cgs_writer(stdout);
    unsigned char uarr[] = "a";
    cgs_putc(wr, '!');
    cgs_append(wr, uarr);
    cgs_tostr_append(wr, 42);
}

void test_00102_writer_cross_wr_sv(void) {
    CGS_Writer wr = cgs_writer(stdout);
    CGS_StrView sv = cgs_strv("a");
    cgs_putc(wr, '!');
    cgs_append(wr, sv);
    cgs_tostr_append(wr, 42);
}

void test_00103_writer_cross_wr_ds(void) {
    CGS_Writer wr = cgs_writer(stdout);
    CGS_DStr ds = cgs_dstr_init();
    cgs_putc(wr, '!');
    cgs_append(wr, ds);
    cgs_tostr_append(wr, 42);
    cgs_dstr_deinit(&ds);
}

void test_00104_writer_cross_wr_pds(void) {
    CGS_Writer wr = cgs_writer(stdout);
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_putc(wr, '!');
    cgs_append(wr, pds);
    cgs_tostr_append(wr, 42);
    cgs_dstr_deinit(&ds_o);
}

void test_00105_writer_cross_wr_sb(void) {
    CGS_Writer wr = cgs_writer(stdout);
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_putc(wr, '!');
    cgs_append(wr, sb);
    cgs_tostr_append(wr, 42);
}

void test_00106_writer_cross_wr_psb(void) {
    CGS_Writer wr = cgs_writer(stdout);
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_putc(wr, '!');
    cgs_append(wr, psb);
    cgs_tostr_append(wr, 42);
}

void test_00107_writer_cross_wr_msr(void) {
    CGS_Writer wr = cgs_writer(stdout);
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_putc(wr, '!');
    cgs_append(wr, msr);
    cgs_tostr_append(wr, 42);
}

void test_00108_replace_cross_ptr_ptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_replace(ptr, ptr, "x");
    cgs_replace_first(ptr, "x", ptr);
    cgs_replace_range(ptr, 0, 1, ptr);
}

void test_00109_replace_cross_ptr_uptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_replace(ptr, uptr, "x");
    cgs_replace_first(ptr, "x", uptr);
    cgs_replace_range(ptr, 0, 1, uptr);
}

void test_00110_replace_cross_ptr_arr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char arr[] = "a";
    cgs_replace(ptr, arr, "x");
    cgs_replace_first(ptr, "x", arr);
    cgs_replace_range(ptr, 0, 1, arr);
}

void test_00111_replace_cross_ptr_uarr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    unsigned char uarr[] = "a";
    cgs_replace(ptr, uarr, "x");
    cgs_replace_first(ptr, "x", uarr);
    cgs_replace_range(ptr, 0, 1, uarr);
}

void test_00112_replace_cross_ptr_sv(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    CGS_StrView sv = cgs_strv("a");
    cgs_replace(ptr, sv, "x");
    cgs_replace_first(ptr, "x", sv);
    cgs_replace_range(ptr, 0, 1, sv);
}

void test_00113_replace_cross_ptr_ds(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    CGS_DStr ds = cgs_dstr_init();
    cgs_replace(ptr, ds, "x");
    cgs_replace_first(ptr, "x", ds);
    cgs_replace_range(ptr, 0, 1, ds);
    cgs_dstr_deinit(&ds);
}

void test_00114_replace_cross_ptr_pds(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_replace(ptr, pds, "x");
    cgs_replace_first(ptr, "x", pds);
    cgs_replace_range(ptr, 0, 1, pds);
    cgs_dstr_deinit(&ds_o);
}

void test_00115_replace_cross_ptr_sb(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_replace(ptr, sb, "x");
    cgs_replace_first(ptr, "x", sb);
    cgs_replace_range(ptr, 0, 1, sb);
}

void test_00116_replace_cross_ptr_psb(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_replace(ptr, psb, "x");
    cgs_replace_first(ptr, "x", psb);
    cgs_replace_range(ptr, 0, 1, psb);
}

void test_00117_replace_cross_ptr_msr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_replace(ptr, msr, "x");
    cgs_replace_first(ptr, "x", msr);
    cgs_replace_range(ptr, 0, 1, msr);
}

void test_00118_replace_cross_uptr_ptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_replace(uptr, ptr, "x");
    cgs_replace_first(uptr, "x", ptr);
    cgs_replace_range(uptr, 0, 1, ptr);
}

void test_00119_replace_cross_uptr_uptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_replace(uptr, uptr, "x");
    cgs_replace_first(uptr, "x", uptr);
    cgs_replace_range(uptr, 0, 1, uptr);
}

void test_00120_replace_cross_uptr_arr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char arr[] = "a";
    cgs_replace(uptr, arr, "x");
    cgs_replace_first(uptr, "x", arr);
    cgs_replace_range(uptr, 0, 1, arr);
}

void test_00121_replace_cross_uptr_uarr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    unsigned char uarr[] = "a";
    cgs_replace(uptr, uarr, "x");
    cgs_replace_first(uptr, "x", uarr);
    cgs_replace_range(uptr, 0, 1, uarr);
}

void test_00122_replace_cross_uptr_sv(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    CGS_StrView sv = cgs_strv("a");
    cgs_replace(uptr, sv, "x");
    cgs_replace_first(uptr, "x", sv);
    cgs_replace_range(uptr, 0, 1, sv);
}

void test_00123_replace_cross_uptr_ds(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    CGS_DStr ds = cgs_dstr_init();
    cgs_replace(uptr, ds, "x");
    cgs_replace_first(uptr, "x", ds);
    cgs_replace_range(uptr, 0, 1, ds);
    cgs_dstr_deinit(&ds);
}

void test_00124_replace_cross_uptr_pds(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_replace(uptr, pds, "x");
    cgs_replace_first(uptr, "x", pds);
    cgs_replace_range(uptr, 0, 1, pds);
    cgs_dstr_deinit(&ds_o);
}

void test_00125_replace_cross_uptr_sb(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_replace(uptr, sb, "x");
    cgs_replace_first(uptr, "x", sb);
    cgs_replace_range(uptr, 0, 1, sb);
}

void test_00126_replace_cross_uptr_psb(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_replace(uptr, psb, "x");
    cgs_replace_first(uptr, "x", psb);
    cgs_replace_range(uptr, 0, 1, psb);
}

void test_00127_replace_cross_uptr_msr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_replace(uptr, msr, "x");
    cgs_replace_first(uptr, "x", msr);
    cgs_replace_range(uptr, 0, 1, msr);
}

void test_00128_replace_cross_arr_ptr(void) {
    char arr[] = "a";
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_replace(arr, ptr, "x");
    cgs_replace_first(arr, "x", ptr);
    cgs_replace_range(arr, 0, 1, ptr);
}

void test_00129_replace_cross_arr_uptr(void) {
    char arr[] = "a";
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_replace(arr, uptr, "x");
    cgs_replace_first(arr, "x", uptr);
    cgs_replace_range(arr, 0, 1, uptr);
}

void test_00130_replace_cross_arr_arr(void) {
    char arr[] = "a";
    cgs_replace(arr, arr, "x");
    cgs_replace_first(arr, "x", arr);
    cgs_replace_range(arr, 0, 1, arr);
}

void test_00131_replace_cross_arr_uarr(void) {
    char arr[] = "a";
    unsigned char uarr[] = "a";
    cgs_replace(arr, uarr, "x");
    cgs_replace_first(arr, "x", uarr);
    cgs_replace_range(arr, 0, 1, uarr);
}

void test_00132_replace_cross_arr_sv(void) {
    char arr[] = "a";
    CGS_StrView sv = cgs_strv("a");
    cgs_replace(arr, sv, "x");
    cgs_replace_first(arr, "x", sv);
    cgs_replace_range(arr, 0, 1, sv);
}

void test_00133_replace_cross_arr_ds(void) {
    char arr[] = "a";
    CGS_DStr ds = cgs_dstr_init();
    cgs_replace(arr, ds, "x");
    cgs_replace_first(arr, "x", ds);
    cgs_replace_range(arr, 0, 1, ds);
    cgs_dstr_deinit(&ds);
}

void test_00134_replace_cross_arr_pds(void) {
    char arr[] = "a";
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_replace(arr, pds, "x");
    cgs_replace_first(arr, "x", pds);
    cgs_replace_range(arr, 0, 1, pds);
    cgs_dstr_deinit(&ds_o);
}

void test_00135_replace_cross_arr_sb(void) {
    char arr[] = "a";
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_replace(arr, sb, "x");
    cgs_replace_first(arr, "x", sb);
    cgs_replace_range(arr, 0, 1, sb);
}

void test_00136_replace_cross_arr_psb(void) {
    char arr[] = "a";
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_replace(arr, psb, "x");
    cgs_replace_first(arr, "x", psb);
    cgs_replace_range(arr, 0, 1, psb);
}

void test_00137_replace_cross_arr_msr(void) {
    char arr[] = "a";
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_replace(arr, msr, "x");
    cgs_replace_first(arr, "x", msr);
    cgs_replace_range(arr, 0, 1, msr);
}

void test_00138_replace_cross_uarr_ptr(void) {
    unsigned char uarr[] = "a";
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_replace(uarr, ptr, "x");
    cgs_replace_first(uarr, "x", ptr);
    cgs_replace_range(uarr, 0, 1, ptr);
}

void test_00139_replace_cross_uarr_uptr(void) {
    unsigned char uarr[] = "a";
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_replace(uarr, uptr, "x");
    cgs_replace_first(uarr, "x", uptr);
    cgs_replace_range(uarr, 0, 1, uptr);
}

void test_00140_replace_cross_uarr_arr(void) {
    unsigned char uarr[] = "a";
    char arr[] = "a";
    cgs_replace(uarr, arr, "x");
    cgs_replace_first(uarr, "x", arr);
    cgs_replace_range(uarr, 0, 1, arr);
}

void test_00141_replace_cross_uarr_uarr(void) {
    unsigned char uarr[] = "a";
    cgs_replace(uarr, uarr, "x");
    cgs_replace_first(uarr, "x", uarr);
    cgs_replace_range(uarr, 0, 1, uarr);
}

void test_00142_replace_cross_uarr_sv(void) {
    unsigned char uarr[] = "a";
    CGS_StrView sv = cgs_strv("a");
    cgs_replace(uarr, sv, "x");
    cgs_replace_first(uarr, "x", sv);
    cgs_replace_range(uarr, 0, 1, sv);
}

void test_00143_replace_cross_uarr_ds(void) {
    unsigned char uarr[] = "a";
    CGS_DStr ds = cgs_dstr_init();
    cgs_replace(uarr, ds, "x");
    cgs_replace_first(uarr, "x", ds);
    cgs_replace_range(uarr, 0, 1, ds);
    cgs_dstr_deinit(&ds);
}

void test_00144_replace_cross_uarr_pds(void) {
    unsigned char uarr[] = "a";
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_replace(uarr, pds, "x");
    cgs_replace_first(uarr, "x", pds);
    cgs_replace_range(uarr, 0, 1, pds);
    cgs_dstr_deinit(&ds_o);
}

void test_00145_replace_cross_uarr_sb(void) {
    unsigned char uarr[] = "a";
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_replace(uarr, sb, "x");
    cgs_replace_first(uarr, "x", sb);
    cgs_replace_range(uarr, 0, 1, sb);
}

void test_00146_replace_cross_uarr_psb(void) {
    unsigned char uarr[] = "a";
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_replace(uarr, psb, "x");
    cgs_replace_first(uarr, "x", psb);
    cgs_replace_range(uarr, 0, 1, psb);
}

void test_00147_replace_cross_uarr_msr(void) {
    unsigned char uarr[] = "a";
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_replace(uarr, msr, "x");
    cgs_replace_first(uarr, "x", msr);
    cgs_replace_range(uarr, 0, 1, msr);
}

void test_00148_replace_cross_pds_ptr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_replace(pds, ptr, "x");
    cgs_replace_first(pds, "x", ptr);
    cgs_replace_range(pds, 0, 1, ptr);
    cgs_dstr_deinit(&ds_o);
}

void test_00149_replace_cross_pds_uptr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_replace(pds, uptr, "x");
    cgs_replace_first(pds, "x", uptr);
    cgs_replace_range(pds, 0, 1, uptr);
    cgs_dstr_deinit(&ds_o);
}

void test_00150_replace_cross_pds_arr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char arr[] = "a";
    cgs_replace(pds, arr, "x");
    cgs_replace_first(pds, "x", arr);
    cgs_replace_range(pds, 0, 1, arr);
    cgs_dstr_deinit(&ds_o);
}

void test_00151_replace_cross_pds_uarr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    unsigned char uarr[] = "a";
    cgs_replace(pds, uarr, "x");
    cgs_replace_first(pds, "x", uarr);
    cgs_replace_range(pds, 0, 1, uarr);
    cgs_dstr_deinit(&ds_o);
}

void test_00152_replace_cross_pds_sv(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    CGS_StrView sv = cgs_strv("a");
    cgs_replace(pds, sv, "x");
    cgs_replace_first(pds, "x", sv);
    cgs_replace_range(pds, 0, 1, sv);
    cgs_dstr_deinit(&ds_o);
}

void test_00153_replace_cross_pds_ds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    CGS_DStr ds = cgs_dstr_init();
    cgs_replace(pds, ds, "x");
    cgs_replace_first(pds, "x", ds);
    cgs_replace_range(pds, 0, 1, ds);
    cgs_dstr_deinit(&ds);
    cgs_dstr_deinit(&ds_o);
}

void test_00154_replace_cross_pds_pds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_replace(pds, pds, "x");
    cgs_replace_first(pds, "x", pds);
    cgs_replace_range(pds, 0, 1, pds);
    cgs_dstr_deinit(&ds_o);
}

void test_00155_replace_cross_pds_sb(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_replace(pds, sb, "x");
    cgs_replace_first(pds, "x", sb);
    cgs_replace_range(pds, 0, 1, sb);
    cgs_dstr_deinit(&ds_o);
}

void test_00156_replace_cross_pds_psb(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_replace(pds, psb, "x");
    cgs_replace_first(pds, "x", psb);
    cgs_replace_range(pds, 0, 1, psb);
    cgs_dstr_deinit(&ds_o);
}

void test_00157_replace_cross_pds_msr(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_replace(pds, msr, "x");
    cgs_replace_first(pds, "x", msr);
    cgs_replace_range(pds, 0, 1, msr);
    cgs_dstr_deinit(&ds_o);
}

void test_00158_replace_cross_psb_ptr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_replace(psb, ptr, "x");
    cgs_replace_first(psb, "x", ptr);
    cgs_replace_range(psb, 0, 1, ptr);
}

void test_00159_replace_cross_psb_uptr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_replace(psb, uptr, "x");
    cgs_replace_first(psb, "x", uptr);
    cgs_replace_range(psb, 0, 1, uptr);
}

void test_00160_replace_cross_psb_arr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char arr[] = "a";
    cgs_replace(psb, arr, "x");
    cgs_replace_first(psb, "x", arr);
    cgs_replace_range(psb, 0, 1, arr);
}

void test_00161_replace_cross_psb_uarr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    unsigned char uarr[] = "a";
    cgs_replace(psb, uarr, "x");
    cgs_replace_first(psb, "x", uarr);
    cgs_replace_range(psb, 0, 1, uarr);
}

void test_00162_replace_cross_psb_sv(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    CGS_StrView sv = cgs_strv("a");
    cgs_replace(psb, sv, "x");
    cgs_replace_first(psb, "x", sv);
    cgs_replace_range(psb, 0, 1, sv);
}

void test_00163_replace_cross_psb_ds(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    CGS_DStr ds = cgs_dstr_init();
    cgs_replace(psb, ds, "x");
    cgs_replace_first(psb, "x", ds);
    cgs_replace_range(psb, 0, 1, ds);
    cgs_dstr_deinit(&ds);
}

void test_00164_replace_cross_psb_pds(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_replace(psb, pds, "x");
    cgs_replace_first(psb, "x", pds);
    cgs_replace_range(psb, 0, 1, pds);
    cgs_dstr_deinit(&ds_o);
}

void test_00165_replace_cross_psb_sb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_replace(psb, sb, "x");
    cgs_replace_first(psb, "x", sb);
    cgs_replace_range(psb, 0, 1, sb);
}

void test_00166_replace_cross_psb_psb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_replace(psb, psb, "x");
    cgs_replace_first(psb, "x", psb);
    cgs_replace_range(psb, 0, 1, psb);
}

void test_00167_replace_cross_psb_msr(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_replace(psb, msr, "x");
    cgs_replace_first(psb, "x", msr);
    cgs_replace_range(psb, 0, 1, msr);
}

void test_00168_replace_cross_msr_ptr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_replace(msr, ptr, "x");
    cgs_replace_first(msr, "x", ptr);
    cgs_replace_range(msr, 0, 1, ptr);
}

void test_00169_replace_cross_msr_uptr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_replace(msr, uptr, "x");
    cgs_replace_first(msr, "x", uptr);
    cgs_replace_range(msr, 0, 1, uptr);
}

void test_00170_replace_cross_msr_arr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char arr[] = "a";
    cgs_replace(msr, arr, "x");
    cgs_replace_first(msr, "x", arr);
    cgs_replace_range(msr, 0, 1, arr);
}

void test_00171_replace_cross_msr_uarr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    unsigned char uarr[] = "a";
    cgs_replace(msr, uarr, "x");
    cgs_replace_first(msr, "x", uarr);
    cgs_replace_range(msr, 0, 1, uarr);
}

void test_00172_replace_cross_msr_sv(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    CGS_StrView sv = cgs_strv("a");
    cgs_replace(msr, sv, "x");
    cgs_replace_first(msr, "x", sv);
    cgs_replace_range(msr, 0, 1, sv);
}

void test_00173_replace_cross_msr_ds(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    CGS_DStr ds = cgs_dstr_init();
    cgs_replace(msr, ds, "x");
    cgs_replace_first(msr, "x", ds);
    cgs_replace_range(msr, 0, 1, ds);
    cgs_dstr_deinit(&ds);
}

void test_00174_replace_cross_msr_pds(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_replace(msr, pds, "x");
    cgs_replace_first(msr, "x", pds);
    cgs_replace_range(msr, 0, 1, pds);
    cgs_dstr_deinit(&ds_o);
}

void test_00175_replace_cross_msr_sb(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    cgs_replace(msr, sb, "x");
    cgs_replace_first(msr, "x", sb);
    cgs_replace_range(msr, 0, 1, sb);
}

void test_00176_replace_cross_msr_psb(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_replace(msr, psb, "x");
    cgs_replace_first(msr, "x", psb);
    cgs_replace_range(msr, 0, 1, psb);
}

void test_00177_replace_cross_msr_msr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_replace(msr, msr, "x");
    cgs_replace_first(msr, "x", msr);
    cgs_replace_range(msr, 0, 1, msr);
}

void test_00178_io_reading_ptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    cgs_fread_line(ptr, stdin);
    cgs_append_fread_line(ptr, stdin);
    cgs_read_line(ptr);
    cgs_append_read_line(ptr);
    cgs_fread_until(ptr, stdin, ':');
    cgs_fread_until(ptr, stdin, EOF);
    cgs_read_until(ptr, ',');
    cgs_read_until(ptr, EOF);
}

void test_00179_io_reading_uptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    cgs_fread_line(uptr, stdin);
    cgs_append_fread_line(uptr, stdin);
    cgs_read_line(uptr);
    cgs_append_read_line(uptr);
    cgs_fread_until(uptr, stdin, ':');
    cgs_fread_until(uptr, stdin, EOF);
    cgs_read_until(uptr, ',');
    cgs_read_until(uptr, EOF);
}

void test_00180_io_reading_arr(void) {
    char arr[] = "a";
    cgs_fread_line(arr, stdin);
    cgs_append_fread_line(arr, stdin);
    cgs_read_line(arr);
    cgs_append_read_line(arr);
    cgs_fread_until(arr, stdin, ':');
    cgs_fread_until(arr, stdin, EOF);
    cgs_read_until(arr, ',');
    cgs_read_until(arr, EOF);
}

void test_00181_io_reading_uarr(void) {
    unsigned char uarr[] = "a";
    cgs_fread_line(uarr, stdin);
    cgs_append_fread_line(uarr, stdin);
    cgs_read_line(uarr);
    cgs_append_read_line(uarr);
    cgs_fread_until(uarr, stdin, ':');
    cgs_fread_until(uarr, stdin, EOF);
    cgs_read_until(uarr, ',');
    cgs_read_until(uarr, EOF);
}

void test_00182_io_reading_pds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    cgs_fread_line(pds, stdin);
    cgs_append_fread_line(pds, stdin);
    cgs_read_line(pds);
    cgs_append_read_line(pds);
    cgs_fread_until(pds, stdin, ':');
    cgs_fread_until(pds, stdin, EOF);
    cgs_read_until(pds, ',');
    cgs_read_until(pds, EOF);
    cgs_dstr_deinit(&ds_o);
}

void test_00183_io_reading_psb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    cgs_fread_line(psb, stdin);
    cgs_append_fread_line(psb, stdin);
    cgs_read_line(psb);
    cgs_append_read_line(psb);
    cgs_fread_until(psb, stdin, ':');
    cgs_fread_until(psb, stdin, EOF);
    cgs_read_until(psb, ',');
    cgs_read_until(psb, EOF);
}

void test_00184_io_reading_msr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_fread_line(msr, stdin);
    cgs_append_fread_line(msr, stdin);
    cgs_read_line(msr);
    cgs_append_read_line(msr);
    cgs_fread_until(msr, stdin, ':');
    cgs_fread_until(msr, stdin, EOF);
    cgs_read_until(msr, ',');
    cgs_read_until(msr, EOF);
}

void test_00185_nfmt_int_int_d(void) {
    int val = 10;
    cgs_nfmt(val, 'd');
}

void test_00186_nfmt_int_int_x(void) {
    int val = 10;
    cgs_nfmt(val, 'x');
}

void test_00187_nfmt_int_int_o(void) {
    int val = 10;
    cgs_nfmt(val, 'o');
}

void test_00188_nfmt_int_int_b(void) {
    int val = 10;
    cgs_nfmt(val, 'b');
}

void test_00189_nfmt_int_int_X(void) {
    int val = 10;
    cgs_nfmt(val, 'X');
}

void test_00190_nfmt_int_long_d(void) {
    long val = 10;
    cgs_nfmt(val, 'd');
}

void test_00191_nfmt_int_long_x(void) {
    long val = 10;
    cgs_nfmt(val, 'x');
}

void test_00192_nfmt_int_long_o(void) {
    long val = 10;
    cgs_nfmt(val, 'o');
}

void test_00193_nfmt_int_long_b(void) {
    long val = 10;
    cgs_nfmt(val, 'b');
}

void test_00194_nfmt_int_long_X(void) {
    long val = 10;
    cgs_nfmt(val, 'X');
}

void test_00195_nfmt_int_long_long_d(void) {
    long long val = 10;
    cgs_nfmt(val, 'd');
}

void test_00196_nfmt_int_long_long_x(void) {
    long long val = 10;
    cgs_nfmt(val, 'x');
}

void test_00197_nfmt_int_long_long_o(void) {
    long long val = 10;
    cgs_nfmt(val, 'o');
}

void test_00198_nfmt_int_long_long_b(void) {
    long long val = 10;
    cgs_nfmt(val, 'b');
}

void test_00199_nfmt_int_long_long_X(void) {
    long long val = 10;
    cgs_nfmt(val, 'X');
}

void test_00200_nfmt_int_int32_t_d(void) {
    int32_t val = 10;
    cgs_nfmt(val, 'd');
}

void test_00201_nfmt_int_int32_t_x(void) {
    int32_t val = 10;
    cgs_nfmt(val, 'x');
}

void test_00202_nfmt_int_int32_t_o(void) {
    int32_t val = 10;
    cgs_nfmt(val, 'o');
}

void test_00203_nfmt_int_int32_t_b(void) {
    int32_t val = 10;
    cgs_nfmt(val, 'b');
}

void test_00204_nfmt_int_int32_t_X(void) {
    int32_t val = 10;
    cgs_nfmt(val, 'X');
}

void test_00205_nfmt_int_uint64_t_d(void) {
    uint64_t val = 10;
    cgs_nfmt(val, 'd');
}

void test_00206_nfmt_int_uint64_t_x(void) {
    uint64_t val = 10;
    cgs_nfmt(val, 'x');
}

void test_00207_nfmt_int_uint64_t_o(void) {
    uint64_t val = 10;
    cgs_nfmt(val, 'o');
}

void test_00208_nfmt_int_uint64_t_b(void) {
    uint64_t val = 10;
    cgs_nfmt(val, 'b');
}

void test_00209_nfmt_int_uint64_t_X(void) {
    uint64_t val = 10;
    cgs_nfmt(val, 'X');
}

void test_00210_nfmt_int_size_t_d(void) {
    size_t val = 10;
    cgs_nfmt(val, 'd');
}

void test_00211_nfmt_int_size_t_x(void) {
    size_t val = 10;
    cgs_nfmt(val, 'x');
}

void test_00212_nfmt_int_size_t_o(void) {
    size_t val = 10;
    cgs_nfmt(val, 'o');
}

void test_00213_nfmt_int_size_t_b(void) {
    size_t val = 10;
    cgs_nfmt(val, 'b');
}

void test_00214_nfmt_int_size_t_X(void) {
    size_t val = 10;
    cgs_nfmt(val, 'X');
}

void test_00215_appender_ptr(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    CGS_AppenderState state;
    CGS_MutStrRef ap = cgs_appender(ptr, &state);
    cgs_commit_appender(ptr, ap);
}

void test_00216_appender_uptr(void) {
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    CGS_AppenderState state;
    CGS_MutStrRef ap = cgs_appender(uptr, &state);
    cgs_commit_appender(uptr, ap);
}

void test_00217_appender_arr(void) {
    char arr[] = "a";
    CGS_AppenderState state;
    CGS_MutStrRef ap = cgs_appender(arr, &state);
    cgs_commit_appender(arr, ap);
}

void test_00218_appender_uarr(void) {
    unsigned char uarr[] = "a";
    CGS_AppenderState state;
    CGS_MutStrRef ap = cgs_appender(uarr, &state);
    cgs_commit_appender(uarr, ap);
}

void test_00219_appender_pds(void) {
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    CGS_AppenderState state;
    CGS_MutStrRef ap = cgs_appender(pds, &state);
    cgs_commit_appender(pds, ap);
    cgs_dstr_deinit(&ds_o);
}

void test_00220_appender_psb(void) {
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    CGS_AppenderState state;
    CGS_MutStrRef ap = cgs_appender(psb, &state);
    cgs_commit_appender(psb, ap);
}

void test_00221_appender_msr(void) {
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    CGS_AppenderState state;
    CGS_MutStrRef ap = cgs_appender(msr, &state);
    cgs_commit_appender(msr, ap);
}

void test_00222_variadic_kitchen_sink(void) {
    char ptr_b[8] = "a"; char *ptr = ptr_b;
    unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;
    char arr[] = "a";
    unsigned char uarr[] = "a";
    CGS_StrView sv = cgs_strv("a");
    CGS_DStr ds = cgs_dstr_init();
    CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;
    char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);
    char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;
    char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);
    cgs_print(ptr, uptr, arr, uarr, sv, ds, pds, sb, psb, msr);
    cgs_println(ptr, uptr, arr, uarr, sv, ds, pds, sb, psb, msr);
    cgs_fprint(stdout, ptr, uptr, arr, uarr, sv, ds, pds, sb, psb, msr);
    cgs_sprint(pds, ptr, uptr, arr, uarr, sv, ds, pds, sb, psb, msr);
    cgs_dstr_deinit(&ds);
    cgs_dstr_deinit(&ds_o);
}

void test_00223_array_fmt(void) {
    int a[3] = {1,2,3};
    cgs_arrfmt(a, 3);
    cgs_arrfmt(a, 3, "[", "]", ",", "");
}

int main(void) { return 0; }
