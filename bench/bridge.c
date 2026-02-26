#include "bridge.h"
#define CGS_SHORT_NAMES
#include "../cgs.c"

void cgs_init_once(void) {
    // Library initialization if required
}

void bench_cgs_tostr_int(char* buf, int val) {
    // Note: CGS handles 'mutstr' which can be a raw char*
    tostr(buf, val);
}

void bench_cgs_sprint_fixed(char* buf, unsigned cap, int i, double d, const char* s) {
    CGS_StrBuf sb = strbuf_init_from_buf(buf, cap);
    // Passing values directly to the variadic sprint
    sprint(&sb, "i=", i, " d=", d, " s=", s);
}

void bench_cgs_append_dynamic(int* int_pool, unsigned count) {
    // Pre-reserve 1KB to ensure we benchmark formatting, not realloc
    DStr ds = dstr_init(1024); 
    for (unsigned k = 0; k < count; ++k) {
        sprint_append(&ds, "iteration: ", int_pool[k], " ");
    }
    dstr_deinit(&ds);
}

void bench_cgs_fprint(FILE* f, int i, double d, const char* s) {
    fprint(f, "i=", i, " d=", d, " s=", s, "\n");
}

#undef cgs_fprint
#define cgs_fprint(f, ...)                       \
do                                               \
{                                                \
    FILE *cgs__file_stream = f;                  \
    (void) cgs__file_stream;                     \
    extern _Thread_local CGS_DStr cgs__fprint_dynamic_buffer; \
    CGS__FOREACH(cgs__fprint_each, __VA_ARGS__); \
} while(0)

void bench_cgs_fprint_old(FILE* f, int i, double d, const char* s)
{
    fprint(f, "i=", i, " d=", d, " s=", s, "\n");
}