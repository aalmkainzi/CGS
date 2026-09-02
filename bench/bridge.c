// bridge.c
#include "bridge.h"
#define CGS_SHORT_NAMES
#include "cgs.c"

#ifndef nfmt
    #define nfmt tsfmt
#endif

// Assuming nfmt is declared and available, perhaps in bridge.h or cgs.c itself
// Example: SomeTsfmtReturnType nfmt(long long val, char format_char);
// Example: SomeTsfmtReturnType nfmt(double val, char format_char, int precision);

void cgs_init_once(void) {
    // Library initialization if required
}

void bench_cgs_tostr_llong(char* buf, long long val) {
    tostr(buf, val); 
}

void bench_cgs_sprint_fixed(char* buf, unsigned cap, long long i, double d, const char* s, const char* s2) {
    CGS_StrBuf sb = strbuf_init_from_buf(buf, cap);
    sprint(&sb, 
        "Data { id: ", i, 
        ", value: ", nfmt(d, 'f', 4), 
        ", primary_tag: \"", s, "\", secondary_tag: \"", s2, 
        "\", timestamp: ", i * 123456789LL, " ns, version: 1.0.0, status: OK }" 
    );
}

void bench_cgs_append_dynamic(long long* llong_pool, unsigned count) {
    DStr ds = dstr_init(4096); 
    for (unsigned k = 0; k < count; ++k) {
        // Assuming nfmt(value, 'd') for decimal. If padding is a separate argument, adapt here.
        sprint_append(&ds, "Entry ", k, ": value = ", nfmt(llong_pool[k], 'd'), " | "); 
    }
    dstr_deinit(&ds);
}

void bench_cgs_fprint(FILE* f, long long i, double d, const char* s, const char* s2, long long computed_val) {
    fprint(f, 
        "FileRecord: { ID: ", i, 
        ", Amount: ", nfmt(d, 'f', 6), 
        ", Desc1: \"", s, "\", Desc2: \"", s2, 
        "\", Hash: ", nfmt(((unsigned long long)i) ^ 0xDEADBEEF, 'x'), 
        ", Severity: ", 3, // Hardcoded integer 3
        ", Timestamp2: ", computed_val, // Now using computed_val
        " }\n"
    );
}