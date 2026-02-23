#!/usr/bin/env python3
"""
Generates a C source file that calls every meaningful combination of the CGS string API,
covering all anystr/mutstr overload types. The output is intended as a compile-only test.

Usage: python3 gen_cgs_compile_test.py > cgs_compile_test.c
       gcc -std=c11 -Wall -Wextra -o /dev/null cgs_compile_test.c -lcgs
"""

def emit(s=""):
    print(s)

# ---------------------------------------------------------------------------
# Type categories
# ---------------------------------------------------------------------------

# Each entry: (type_label, variable_name, declaration_statement)
#
# anystr = char* | unsigned char* | char[] | unsigned char[] | StrView | DStr | DStr* | StrBuf | StrBuf* | MutStrRef
# mutstr = char* | unsigned char* | char[] | unsigned char[] |          DStr* |         StrBuf* | MutStrRef

ANYSTR_VARS = [
    ("char*",           "cstr_ptr",   'char cstr_ptr_buf[] = "hello"; char *cstr_ptr = cstr_ptr_buf;'),
    ("unsigned char*",  "ucstr_ptr",  "unsigned char ucstr_ptr_buf[] = {'h','i',0}; unsigned char *ucstr_ptr = ucstr_ptr_buf;"),
    ("char[]",          "cstr_arr",   'char cstr_arr[] = "hello";'),
    ("unsigned char[]", "ucstr_arr",  "unsigned char ucstr_arr[] = {'h','i',0};"),
    ("StrView",         "sv",         'StrView sv = strv("hello");'),
    ("DStr",            "dstr_val",   'DStr dstr_val = dstr_init_from("hello", NULL);'),
    ("DStr*",           "dstr_ptr",   'DStr dstr_ptr_obj = dstr_init_from("hello", NULL); DStr *dstr_ptr = &dstr_ptr_obj;'),
    ("StrBuf",          "strbuf_val", 'char strbuf_val_buf[64] = "hello"; StrBuf strbuf_val = strbuf_init_from_cstr(strbuf_val_buf, 64);'),
    ("StrBuf*",         "strbuf_ptr", 'char strbuf_ptr_buf[64] = "hello"; StrBuf strbuf_ptr_obj = strbuf_init_from_cstr(strbuf_ptr_buf, 64); StrBuf *strbuf_ptr = &strbuf_ptr_obj;'),
    ("MutStrRef",       "msr",        'char msr_buf[64] = "hello"; MutStrRef msr = mutstr_ref(msr_buf);'),
]

# mutstr excludes StrView, DStr (by value), StrBuf (by value)
MUTSTR_VARS = [v for v in ANYSTR_VARS if v[0] in {
    "char*", "unsigned char*", "char[]", "unsigned char[]",
    "DStr*", "StrBuf*", "MutStrRef"
}]

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

fn_counter = [0]

def begin_fn():
    fn_counter[0] += 1
    emit(f"static void test_{fn_counter[0]:04d}(void) {{")

def end_fn():
    emit("}")
    emit()

def setup(*names):
    """Emit declarations for the requested variable names, in ANYSTR_VARS order, deduped."""
    seen = set()
    for _, vname, decl in ANYSTR_VARS:
        if vname in names and vname not in seen:
            emit(f"    {decl}")
            seen.add(vname)

# ---------------------------------------------------------------------------
# Header
# ---------------------------------------------------------------------------

emit("/*")
emit(" * AUTO-GENERATED compile test for the CGS string library.")
emit(" * Run: python3 gen_cgs_compile_test.py > cgs_compile_test.c")
emit(" *      gcc -std=c11 -Wall -Wextra -o /dev/null cgs_compile_test.c -lcgs")
emit(" */")
emit()
emit("#include <stdio.h>")
emit("#include <stdbool.h>")
emit("#include <string.h>")
emit('#define CGS_SHORT_NAMES')
emit('#include "../cgs.h"   /* adjust include path as needed */')
emit()

# ---------------------------------------------------------------------------
# strv(anystr, from?, to?)           — anystr
# ---------------------------------------------------------------------------

emit("/* ===== strv ===== */")
for _, aname, _ in ANYSTR_VARS:
    begin_fn()
    setup(aname)
    emit(f"    StrView r1 = strv({aname});")
    emit(f"    StrView r2 = strv({aname}, 1);")
    emit(f"    (void)r1; (void)r2;")
    end_fn()

# ---------------------------------------------------------------------------
# strbuf_init_from_cstr / strbuf_init_from_buf
# Only accept raw char/unsigned char pointers and arrays — NOT anystr
# ---------------------------------------------------------------------------

emit("/* ===== strbuf_init_from_cstr / strbuf_init_from_buf ===== */")
begin_fn()
emit("    char      rp[64] = \"hello\";  char      ra[] = \"hello\";")
emit("    unsigned char up[64] = {'h',0}; unsigned char ua[] = {'h',0};")
emit("    StrBuf s1  = strbuf_init_from_cstr(rp);")
emit("    StrBuf s2  = strbuf_init_from_cstr(rp, 64);")
emit("    StrBuf s3  = strbuf_init_from_cstr(ra);")
emit("    StrBuf s4  = strbuf_init_from_cstr(ra, sizeof(ra));")
emit("    StrBuf s5  = strbuf_init_from_cstr(up);")
emit("    StrBuf s6  = strbuf_init_from_cstr(up, 64);")
emit("    StrBuf s7  = strbuf_init_from_cstr(ua);")
emit("    StrBuf s8  = strbuf_init_from_cstr(ua, sizeof(ua));")
emit("    StrBuf s9  = strbuf_init_from_buf(rp, 64);")
emit("    StrBuf s10 = strbuf_init_from_buf(ra, sizeof(ra));")
emit("    StrBuf s11 = strbuf_init_from_buf(up, 64);")
emit("    StrBuf s12 = strbuf_init_from_buf(ua, sizeof(ua));")
emit("    (void)s1;(void)s2;(void)s3;(void)s4;(void)s5;(void)s6;")
emit("    (void)s7;(void)s8;(void)s9;(void)s10;(void)s11;(void)s12;")
end_fn()

# ---------------------------------------------------------------------------
# dstr_init / dstr_deinit / dstr_shrink_to_fit
# dstr_init_from(anystr)
# ---------------------------------------------------------------------------

emit("/* ===== dstr_init / dstr_deinit / dstr_shrink_to_fit ===== */")
begin_fn()
emit("    DStr d1 = dstr_init();")
emit("    DStr d2 = dstr_init(16, NULL);")
emit("    dstr_deinit(&d1);")
emit("    dstr_deinit(&d2);")
end_fn()

for _, aname, _ in ANYSTR_VARS:
    begin_fn()
    setup(aname)
    emit(f"    DStr d = dstr_init_from({aname}, NULL);")
    emit(f"    CGS_Error e = dstr_shrink_to_fit(&d);")
    emit(f"    (void)e; dstr_deinit(&d);")
    end_fn()

# ---------------------------------------------------------------------------
# mutstr_ref(mutstr)                 — mutstr only
# ---------------------------------------------------------------------------

emit("/* ===== mutstr_ref ===== */")
for _, mname, _ in MUTSTR_VARS:
    begin_fn()
    setup(mname)
    emit(f"    MutStrRef ref = mutstr_ref({mname});")
    emit(f"    (void)ref;")
    end_fn()

# ---------------------------------------------------------------------------
# strv_arr / strv_arr_from_carr
# ---------------------------------------------------------------------------

emit("/* ===== strv_arr / strv_arr_from_carr ===== */")
begin_fn()
emit('    StrViewArray va1 = strv_arr("a", "b", "c");')
emit('    StrView items[2] = { strv("x"), strv("y") };')
emit('    StrViewArray va2 = strv_arr_from_carr(items, 2);')
emit('    StrViewArray va3 = strv_arr_from_carr(items);')
emit('    (void)va1; (void)va2; (void)va3;')
end_fn()

# ---------------------------------------------------------------------------
# cgs_at / cgs_len / cgs_cap / cgs_chars / cgs_equal / cgs_find /
# cgs_count / cgs_starts_with / cgs_ends_with     — all anystr
# ---------------------------------------------------------------------------

emit("/* ===== single-arg read ops (anystr) ===== */")
for _, aname, _ in ANYSTR_VARS:
    begin_fn()
    setup(aname)
    emit(f"    char         c   = cgs_at({aname}, 0);")
    emit(f"    unsigned int len = cgs_len({aname});")
    emit(f"    unsigned int cap = cgs_cap({aname});")
    emit(f"    char        *ch  = cgs_chars({aname});")
    emit(f"    (void)c; (void)len; (void)cap; (void)ch;")
    end_fn()

emit("/* ===== two-arg read ops (anystr x anystr) ===== */")
for _, an1, _ in ANYSTR_VARS:
    for _, an2, _ in ANYSTR_VARS:
        begin_fn()
        setup(an1, an2)
        emit(f"    bool         eq    = cgs_equal({an1}, {an2});")
        emit(f"    StrView      found = cgs_find({an1}, {an2});")
        emit(f"    unsigned int cnt   = cgs_count({an1}, {an2});")
        emit(f"    bool         sw    = cgs_starts_with({an1}, {an2});")
        emit(f"    bool         ew    = cgs_ends_with({an1}, {an2});")
        emit(f"    (void)eq; (void)found; (void)cnt; (void)sw; (void)ew;")
        end_fn()

# ---------------------------------------------------------------------------
# cgs_clear / cgs_tolower / cgs_toupper / cgs_putc  — mutstr only
# ---------------------------------------------------------------------------

emit("/* ===== cgs_clear / cgs_tolower / cgs_toupper / cgs_putc (mutstr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    begin_fn()
    setup(mname)
    emit(f"    CGS_Error e1 = cgs_clear({mname});")
    emit(f"    cgs_tolower({mname});")
    emit(f"    cgs_toupper({mname});")
    emit(f"    CGS_Error e4 = cgs_putc({mname}, 'x');")
    emit(f"    (void)e1; (void)e4;")
    end_fn()

# ---------------------------------------------------------------------------
# cgs_copy / cgs_append / cgs_prepend  — mutstr dst, anystr src
# ---------------------------------------------------------------------------

emit("/* ===== cgs_copy / cgs_append / cgs_prepend (mutstr x anystr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    for _, aname, _ in ANYSTR_VARS:
        begin_fn()
        setup(mname, aname)
        emit(f"    CGS_Error e1 = cgs_copy({mname}, {aname});")
        emit(f"    CGS_Error e2 = cgs_append({mname}, {aname});")
        emit(f"    CGS_Error e3 = cgs_prepend({mname}, {aname});")
        emit(f"    (void)e1; (void)e2; (void)e3;")
        end_fn()

# ---------------------------------------------------------------------------
# cgs_insert — mutstr dst, anystr src, pos
# ---------------------------------------------------------------------------

emit("/* ===== cgs_insert (mutstr x anystr x pos) ===== */")
for _, mname, _ in MUTSTR_VARS:
    for _, aname, _ in ANYSTR_VARS:
        begin_fn()
        setup(mname, aname)
        emit(f"    CGS_Error e = cgs_insert({mname}, {aname}, 1);")
        emit(f"    (void)e;")
        end_fn()

# ---------------------------------------------------------------------------
# cgs_del — mutstr, from, to           — mutstr only
# ---------------------------------------------------------------------------

emit("/* ===== cgs_del (mutstr x from x to) ===== */")
for _, mname, _ in MUTSTR_VARS:
    begin_fn()
    setup(mname)
    emit(f"    CGS_Error e = cgs_del({mname}, 0, 1);")
    emit(f"    (void)e;")
    end_fn()

# ---------------------------------------------------------------------------
# cgs_dup(anystr)
# ---------------------------------------------------------------------------

emit("/* ===== cgs_dup (anystr) ===== */")
for _, aname, _ in ANYSTR_VARS:
    begin_fn()
    setup(aname)
    emit(f"    DStr d = cgs_dup({aname}, NULL);")
    emit(f"    dstr_deinit(&d);")
    end_fn()

# ---------------------------------------------------------------------------
# cgs_replace / cgs_replace_first  — mutstr dst, anystr target, anystr replacement
# ---------------------------------------------------------------------------

emit("/* ===== cgs_replace / cgs_replace_first (mutstr x anystr x anystr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    for _, an1, _ in ANYSTR_VARS:
        for _, an2, _ in ANYSTR_VARS:
            begin_fn()
            setup(mname, an1, an2)
            emit(f"    ReplaceResult rr = cgs_replace({mname}, {an1}, {an2});")
            emit(f"    CGS_Error     e  = cgs_replace_first({mname}, {an1}, {an2});")
            emit(f"    (void)rr; (void)e;")
            end_fn()

# ---------------------------------------------------------------------------
# cgs_replace_range  — mutstr dst, from, to, anystr replacement
# ---------------------------------------------------------------------------

emit("/* ===== cgs_replace_range (mutstr x from x to x anystr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    for _, aname, _ in ANYSTR_VARS:
        begin_fn()
        setup(mname, aname)
        emit(f"    CGS_Error e = cgs_replace_range({mname}, 0, 1, {aname});")
        emit(f"    (void)e;")
        end_fn()

# ---------------------------------------------------------------------------
# cgs_split(anystr, anystr)
# ---------------------------------------------------------------------------

emit("/* ===== cgs_split (anystr x anystr) ===== */")
for _, an1, _ in ANYSTR_VARS:
    for _, an2, _ in ANYSTR_VARS:
        begin_fn()
        setup(an1, an2)
        emit(f"    StrViewArray arr = cgs_split({an1}, {an2}, NULL);")
        emit(f"    (void)arr;")
        end_fn()

# ---------------------------------------------------------------------------
# cgs_split_iter(anystr, anystr, callback, arg)
# One callback covers all combinations; we vary the str/delim types.
# ---------------------------------------------------------------------------

emit("/* ===== cgs_split_iter (anystr x anystr x callback) ===== */")
emit("static bool split_iter_cb(StrView found, void *arg) { (void)found; (void)arg; return true; }")
for _, an1, _ in ANYSTR_VARS:
    for _, an2, _ in ANYSTR_VARS:
        begin_fn()
        setup(an1, an2)
        emit(f"    CGS_Error e = cgs_split_iter({an1}, {an2}, split_iter_cb, NULL);")
        emit(f"    (void)e;")
        end_fn()

# ---------------------------------------------------------------------------
# cgs_join — mutstr dst, StrViewArray, anystr delim
# ---------------------------------------------------------------------------

emit("/* ===== cgs_join (mutstr x StrViewArray x anystr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    for _, aname, _ in ANYSTR_VARS:
        begin_fn()
        setup(mname, aname)
        emit('    StrViewArray arr = strv_arr("a", "b");')
        emit(f"    CGS_Error e = cgs_join({mname}, arr, {aname});")
        emit(f"    (void)e;")
        end_fn()

# ---------------------------------------------------------------------------
# cgs_fread_line / cgs_append_fread_line / cgs_read_line / cgs_append_read_line
# — mutstr dst only
# ---------------------------------------------------------------------------

emit("/* ===== line reading (mutstr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    begin_fn()
    setup(mname)
    emit(f"    CGS_Error e1 = cgs_fread_line({mname}, stdin);")
    emit(f"    CGS_Error e2 = cgs_append_fread_line({mname}, stdin);")
    emit(f"    CGS_Error e3 = cgs_read_line({mname});")
    emit(f"    CGS_Error e4 = cgs_append_read_line({mname});")
    emit(f"    (void)e1; (void)e2; (void)e3; (void)e4;")
    end_fn()

# ---------------------------------------------------------------------------
# cgs_sprint / cgs_sprint_append   — mutstr dst only (no return value per API)
# ---------------------------------------------------------------------------

emit("/* ===== cgs_sprint / cgs_sprint_append (mutstr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    begin_fn()
    setup(mname)
    emit(f'    cgs_sprint({mname}, 42, 3.14f, "hi", (double)1.0);')
    emit(f'    cgs_sprint_append({mname}, 42, 3.14f, "hi");')
    end_fn()

# ---------------------------------------------------------------------------
# dstr_ensure_cap(DStr*, at_least)   — takes DStr* specifically, not generic mutstr
# ---------------------------------------------------------------------------

emit("/* ===== dstr_ensure_cap ===== */")
begin_fn()
emit("    DStr d = dstr_init();")
emit("    CGS_Error e = dstr_ensure_cap(&d, 128);")
emit("    (void)e; dstr_deinit(&d);")
end_fn()

# ---------------------------------------------------------------------------
# cgs_appender(mutstr, AppenderState*) / cgs_commit_appender(mutstr, MutStrRef)
# — mutstr only
# ---------------------------------------------------------------------------

emit("/* ===== cgs_appender / cgs_commit_appender (mutstr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    begin_fn()
    setup(mname)
    emit(f"    AppenderState state;")
    emit(f"    MutStrRef appender = cgs_appender({mname}, &state);")
    emit(f"    CGS_Error e = cgs_commit_appender({mname}, appender);")
    emit(f"    (void)e;")
    end_fn()

# ---------------------------------------------------------------------------
# tostr(mutstr, T) / tostr_p(mutstr, T*)   — mutstr dst only
#
# For scalar T: both tostr and tostr_p make sense.
# For anystr T: only tostr makes sense (tostr_p would be tostr_p(dst, &str_var)
#               which is valid for all types, but StrView/DStr/StrBuf are
#               passed by value so &var gives a pointer to the local — fine).
# ---------------------------------------------------------------------------

SCALAR_TYPES = [
    ("int",          "42"),
    ("unsigned int", "42u"),
    ("long",         "42L"),
    ("long long",    "42LL"),
    ("float",        "3.14f"),
    ("double",       "3.14"),
]

emit("/* ===== tostr / tostr_p (mutstr x scalar) ===== */")
for _, mname, _ in MUTSTR_VARS:
    begin_fn()
    setup(mname)
    for ctype, literal in SCALAR_TYPES:
        vname = ctype.replace(" ", "_") + "_v"
        emit(f"    {ctype} {vname} = {literal};")
        emit(f"    {{ CGS_Error e = tostr({mname}, {vname}); (void)e; }}")
        emit(f"    {{ CGS_Error e = tostr_p({mname}, &{vname}); (void)e; }}")
    end_fn()

emit("/* ===== tostr (mutstr x anystr) ===== */")
for _, mname, _ in MUTSTR_VARS:
    for _, aname, _ in ANYSTR_VARS:
        begin_fn()
        setup(mname, aname)
        emit(f"    CGS_Error e = tostr({mname}, {aname});")
        emit(f"    (void)e;")
        end_fn()

# ---------------------------------------------------------------------------
# print / println / fprint / fprintln  — variadic tostr args, no mutstr involved
# ---------------------------------------------------------------------------

emit("/* ===== print / println / fprint / fprintln ===== */")
begin_fn()
emit('    print(42, " ", 3.14, " ", "hello");')
emit('    println(42, " ", 3.14);')
emit('    fprint(stdout, 42, " ", "world");')
emit('    fprintln(stdout, 1, 2, 3);')
end_fn()

# ---------------------------------------------------------------------------
# tsfmt / arrfmt
# ---------------------------------------------------------------------------

emit("/* ===== tsfmt / arrfmt ===== */")
begin_fn()
emit("    tsfmt_t(int, 'x')   hex_val = tsfmt(255, 'x');")
emit("    tsfmt_t(float, 'e') sci_val = tsfmt(3.14f, 'e', 2);")
emit("    (void)hex_val; (void)sci_val;")
emit("    int arr_data[] = {1, 2, 3};")
emit('    ArrayFmt af1 = arrfmt(arr_data, 3);')
emit('    ArrayFmt af2 = arrfmt(arr_data, 3, "[", "]", ", ", ",");')
emit("    (void)af1; (void)af2;")
end_fn()

# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

emit(f"/* {fn_counter[0]} test functions generated */")
emit("int main(void) { return 0; }")