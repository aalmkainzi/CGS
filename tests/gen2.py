#!/usr/bin/env python3

def emit(s=""):
    print(s)

# ---------------------------------------------------------------------------
# METADATA DEFINITIONS
# ---------------------------------------------------------------------------

# (Label, Declaration/Init, Variable Name)
# We use buffers for pointers to ensure they are valid for mutable (mutstr_t) APIs
ANYSTR_META = [
    ("char*",           'char ptr_b[8] = "a"; char *ptr = ptr_b;', "ptr"),
    ("unsigned char*",  'unsigned char uptr_b[8] = "a"; unsigned char *uptr = uptr_b;', "uptr"),
    ("char[]",          'char arr[] = "a";', "arr"),
    ("unsigned char[]", 'unsigned char uarr[] = "a";', "uarr"),
    ("CGS_StrView",     'CGS_StrView sv = cgs_strv("a");', "sv"),
    ("CGS_DStr",        'CGS_DStr ds = cgs_dstr_init();', "ds"),
    ("CGS_DStr*",       'CGS_DStr ds_o = cgs_dstr_init(); CGS_DStr *pds = &ds_o;', "pds"),
    ("CGS_StrBuf",      'char sb_b[8] = "a"; CGS_StrBuf sb = cgs_strbuf_init_from_buf(sb_b, 8);', "sb"),
    ("CGS_StrBuf*",     'char psb_b[8] = "a"; CGS_StrBuf psb_o = cgs_strbuf_init_from_buf(psb_b, 8); CGS_StrBuf *psb = &psb_o;', "psb"),
    ("CGS_MutStrRef",   'char msr_b[8] = "a"; CGS_MutStrRef msr = cgs_mutstr_ref(msr_b, 8);', "msr"),
]

# Map for easy lookup by variable name
ANYSTR_MAP = { m[2]: m for m in ANYSTR_META }

MUTSTR_VNAMES = ["ptr", "uptr", "arr", "uarr", "pds", "psb", "msr"]
MUTSTR_META = [ANYSTR_MAP[name] for name in MUTSTR_VNAMES]

WRITER_META = MUTSTR_META + [
    ("FILE*", "FILE *fp = stdout;", "fp"),
    ("CGS_Writer", "CGS_Writer wr = cgs_writer(stdout);", "wr")
]

INT_TYPES = ["int", "long", "long long", "int32_t", "uint64_t", "size_t"]
INT_FMTS = ["'d'", "'x'", "'o'", "'b'", "'X'"]
FLOAT_FMTS = ["'f'", "'g'", "'e'", "'a'"]

# ---------------------------------------------------------------------------
# TEST GENERATOR
# ---------------------------------------------------------------------------

fn_idx = 0

def generate_test(name, var_names, code_lines):
    global fn_idx
    fn_idx += 1
    emit(f"void test_{fn_idx:05d}_{name}(void) {{")
    
    # 1. Setup declarations
    seen = set()
    for vname in var_names:
        if vname in ANYSTR_MAP and vname not in seen:
            emit(f"    {ANYSTR_MAP[vname][1]}")
            seen.add(vname)
        elif vname == "fp":
            emit("    FILE *fp = stdout;")
            seen.add(vname)
        elif vname == "wr":
            emit("    CGS_Writer wr = cgs_writer(stdout);")
            seen.add(vname)
            
    # 2. Logic
    for line in code_lines:
        emit(f"    {line}")
        
    # 3. Cleanup DStr (if local ds or ds_o was created)
    if "ds" in seen: emit("    cgs_dstr_deinit(&ds);")
    if "pds" in seen: emit("    cgs_dstr_deinit(&ds_o);")
    
    emit("}")
    emit()

# ---------------------------------------------------------------------------
# START OUTPUT
# ---------------------------------------------------------------------------

emit("#include <stdio.h>")
emit("#include <stdint.h>")
emit("#include <stdbool.h>")
emit("#define CGS_SHORT_NAMES")
emit('#include "cgs.c"')
emit()

# 1. All anystr_t read functions
for m in ANYSTR_META:
    v = m[2]
    generate_test(f"anystr_read_{v}", [v], [
        f"cgs_len({v});", f"cgs_cap({v});", f"cgs_chars({v});",
        f"CGS_DStr dupped = cgs_dup({v}, NULL);", f"cgs_find({v}, \"a\");",
        f"cgs_starts_with({v}, \"a\");", f"cgs_ends_with({v}, \"a\");"
    ])

# 2. All mutstr_t mutation functions
for m in MUTSTR_META:
    v = m[2]
    generate_test(f"mutstr_write_{v}", [v], [
        f"cgs_clear({v});", f"cgs_tolower({v});", f"cgs_toupper({v});",
        f"cgs_del({v}, 0, 1);"
    ])

# 3. writer_t combinations (putc, append, append_tostr)
# Every writer x every anystr type
for wm in WRITER_META:
    for am in ANYSTR_META:
        wv = wm[2]
        av = am[2]
        generate_test(f"writer_cross_{wv}_{av}", [wv, av], [
            f"cgs_putc({wv}, '!');",
            f"cgs_append({wv}, {av});",
            f"cgs_append_tostr({wv}, 42);"
        ])

# 4. Replacement combinations (mutstr x anystr)
for mm in MUTSTR_META:
    for am in ANYSTR_META:
        mv = mm[2]
        av = am[2]
        generate_test(f"replace_cross_{mv}_{av}", [mv, av], [
            f"cgs_replace({mv}, {av}, \"x\");",
            f"cgs_replace_first({mv}, \"x\", {av});",
            f"cgs_replace_range({mv}, 0, 1, {av});"
        ])

# 5. IO Reading (Every mutstr x every variant)
for mm in MUTSTR_META:
    mv = mm[2]
    generate_test(f"io_reading_{mv}", [mv], [
        f"cgs_fread_line({mv}, stdin);",
        f"cgs_append_fread_line({mv}, stdin);",
        f"cgs_read_line({mv});",
        f"cgs_append_read_line({mv});",
        f"cgs_fread_until({mv}, stdin, ':');",
        f"cgs_fread_until({mv}, stdin, EOF);",
        f"cgs_read_until({mv}, ',');",
        f"cgs_read_until({mv}, EOF);"
    ])

# 6. nfmt (Exhaustive Integer Types x Every Format Char)
for itype in INT_TYPES:
    for fchar in INT_FMTS:
        t_safe = itype.replace(" ", "_")
        f_safe = fchar.strip("'")
        generate_test(f"nfmt_int_{t_safe}_{f_safe}", [], [
            f"{itype} val = 10;",
            f"cgs_nfmt(val, {fchar});"
        ])

# 7. cgs_appender (Every mutstr_t type)
for mm in MUTSTR_META:
    mv = mm[2]
    generate_test(f"appender_{mv}", [mv], [
        "CGS_AppenderState state;",
        f"CGS_MutStrRef ap = cgs_appender({mv}, &state);",
        f"cgs_commit_appender({mv}, ap);"
    ])

# 8. Variadic Printing (Kitchen Sink)
# Use ALL ANYSTR variables at once to test variadic macro limits
all_vnames = [m[2] for m in ANYSTR_META]
generate_test("variadic_kitchen_sink", all_vnames, [
    "cgs_printf(" + ", ".join(all_vnames) + ");",
    "cgs_printfln(" + ", ".join(all_vnames) + ");",
    "cgs_append_tostr_all(stdout, " + ", ".join(all_vnames) + ");",
    "cgs_fmt(pds, " + ", ".join(all_vnames) + ");"
])

# 9. Array formatters
generate_test("array_fmt", [], [
    "int a[3] = {1,2,3};",
    "cgs_arrfmt(a, 3);",
    "cgs_arrfmt(a, 3, \"[\", \"]\", \",\", \"\");"
])

emit("int main(void) { return 0; }")