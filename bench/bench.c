/* ===========================================================================
 * bench_cgs_vs_snprintf.c
 *
 * Benchmarks cgs_sprintf against the C standard snprintf on three workloads:
 *
 *   1. views    - 8 string views, each with its own alignment and width
 *   2. ints     - 8 integers in decimal, hex, HEX, octal and binary
 *   3. events   - a custom struct, via ADD_TOSTR here vs. hand-expansion there
 *
 * Both sides write into the SAME byte buffer, are called through the same
 * function-pointer signature (so neither gets inlined while the other does
 * not), and are checked for byte-identical output before being timed.
 *
 * Fairness note: both cases are held to what printf does natively, so neither
 * side is timed against emulation code. Case 1 is space fill and LEFT/RIGHT
 * only, because printf offers neither a fill character nor centering for %s.
 * Case 2 uses the C23 %b conversion rather than a hand-rolled binary loop.
 *
 * Build (cgs.c is pulled in directly, nothing else to compile or link):
 *     cc -std=c23 -O2 bench_cgs_vs_snprintf.c -o bench
 * On gcc 13 / clang 17 and earlier the flag is spelled -std=c2x. %b also
 * needs a C23-era libc at runtime (glibc 2.35+); musl and MSVC do not have
 * it yet, in which case convert to binary by hand and format it with %s.
 *
 * Run:
 *     ./bench [iterations]      (default 200000)
 * ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#if defined(_WIN32)
#  include <windows.h>
#else
#  include <time.h>
#endif

#define CGS_NDEBUG
#define NDEBUG
#define CGS_API static inline
#include "../cgs.c"

/* --------------------------------------------------------------------------
 * Knobs
 * ----------------------------------------------------------------------- */

#define BUF_CAP 512
#define ROUNDS  7       /* timed rounds per case; the best one is reported   */
#define WARMUP  20000

#if defined(__GNUC__)
#  define NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
#  define NOINLINE __declspec(noinline)
#else
#  define NOINLINE
#endif

static unsigned long long g_sink;   /* keeps the optimiser honest */
static unsigned           g_iters = 200000;

/* --------------------------------------------------------------------------
 * Clock
 * ----------------------------------------------------------------------- */

static double now_sec(void)
{
    #if defined(_WIN32)
    LARGE_INTEGER f, c;
    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&c);
    return (double)c.QuadPart / (double)f.QuadPart;
    #elif defined(CLOCK_MONOTONIC)
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
    #else
    return (double)clock() / (double)CLOCKS_PER_SEC;
    #endif
}

/* snprintf returns "would have been" length; clamp it to what is in the buf */
static unsigned clamp_len(int n, unsigned cap)
{
    if (n < 0)            return 0;
    if ((unsigned)n < cap) return (unsigned)n;
    return cap ? cap - 1u : 0u;
}

/* ==========================================================================
 * Custom type + its tostr
 * ======================================================================= */

typedef struct Rect { int x, y, w, h; }                  Rect;
typedef struct Rgba { unsigned char r, g, b, a; }        Rgba;

typedef struct Event {
    unsigned int id;
    char        *label;     /* plain char*, NOT const char*: _Generic in the  */
    Rect         area;      /* anystr_t macros matches char*, not const char* */
    Rgba         color;
    double       weight;
} Event;

static CGS_Error event_to_str(CGS_Writer *dst, Event e, CGS_StrView fmt_arg)
{
    if (cgs_equal(fmt_arg, "short"))
        return cgs_appendf(dst, "#%? %?", e.id, e.label);
    
    return cgs_appendf(dst,
                       "Event#%? \"%?\" rect(%?,%? %?x%?) rgba(%?,%?,%?,%?) w=%?",
                       e.id, e.label,
                       e.area.x, e.area.y, e.area.w, e.area.h,
                       cgs_nfmt((unsigned)e.color.r, 'd'),
                       cgs_nfmt((unsigned)e.color.g, 'd'),
                       cgs_nfmt((unsigned)e.color.b, 'd'),
                       cgs_nfmt((unsigned)e.color.a, 'd'),
                       cgs_nfmt(e.weight, 'f', 2));
}

#define ADD_TOSTR \
(Event, event_to_str)

#include "../cgs.h"     /* re-include registers Event with the tostr dispatch */

/* ==========================================================================
 * Data
 * ======================================================================= */

/* One packed run of bytes with no interior NULs, so the views really are
 * views and the snprintf side really does need %.*s. */
static char  BLOB[256];

static char *PIECES[8] = {
    "Ada Lovelace", "A-7719", "Architect", "Cairo",
    "SA-01",        "core",   "Platform",  "active"
};

typedef struct Slice { char *p; int n; } Slice;

static CGS_StrView V[8];    /* what cgs sees */
static Slice       S[8];    /* what snprintf needs: pointer + explicit length */

static void init_views(void)
{
    unsigned off = 0;
    for (int k = 0; k < 8; ++k) {
        unsigned n = (unsigned)strlen(PIECES[k]);
        memcpy(BLOB + off, PIECES[k], n);
        V[k]   = cgs_strv(BLOB, off, off + n);
        S[k].p = BLOB + off;
        S[k].n = (int)n;
        off   += n;
    }
}

static int I32[8] = {
    0, -1, 42, -2147483647 - 1, 1234567, -99, 2147483647, -100000
};
static unsigned U32[8] = {
    0u, 1u, 0xDEADBEEFu, 4294967295u, 255u, 65535u, 0x8000u, 1000000007u
};
static long long I64[8] = {
    0, -1, 9223372036854775807LL, -9223372036854775807LL - 1,
    1000000000000LL, -42LL, 987654321987654321LL, 7LL
};
static unsigned long long U64[8] = {
    0ull, 1ull, 0xFFFFFFFFFFFFFFFFull, 0x0123456789ABCDEFull,
    1024ull, 0xCAFEBABEull, 999999999999ull, 0x10ull
};
static size_t SZ[8] = { 0, 1, 4096, 65536, 1048576, 17, 123456789, 64 };

static Event EV[8] = {
    { 1001u, "toolbar",   {    0,   0, 1280,  48 }, {  32,  34,  38, 255 },  1.00 },
    { 1002u, "sidebar",   {    0,  48,  240, 720 }, {  24,  26,  30, 240 },  0.50 },
    { 1003u, "canvas",    {  240,  48, 1040, 720 }, { 250, 250, 250, 255 },  3.25 },
    { 1004u, "statusbar", {    0, 768, 1280,  24 }, {  18,  18,  20, 200 },  0.10 },
    { 1005u, "tooltip",   {  512, 300,  180,  64 }, { 255, 214,  10, 230 }, 12.75 },
    { 1006u, "modal",     {  320, 200,  640, 400 }, {  12,  12,  16, 128 },  8.00 },
    { 1007u, "gutter",    {  240,  48,   40, 720 }, {  40,  42,  48, 255 },  0.25 },
    { 1008u, "minimap",   { 1180,  48,  100, 720 }, {  60,  62,  70, 180 },  2.50 }
};

/* ==========================================================================
 * Case 1 - string views with alignments and widths
 *
 * Field plan (shared by both implementations):
 *   0: LEFT  14     2: LEFT  16     4: LEFT  15     6: LEFT  17
 *   1: RIGHT 13     3: RIGHT 12     5: RIGHT 18     7: RIGHT 12
 *
 * Space fill only, which is all printf gives you for %s. Every width is >=
 * the longest piece (12), so nothing ever truncates and the two sides cannot
 * disagree about overflow behaviour. The precision (.*) is not optional on
 * the snprintf side: the views point into BLOB and are not NUL-terminated.
 * ======================================================================= */

static int cgs_views(CGS_StrBuf *o, unsigned i)
{
    cgs_sprintf(o, "%?|%?|%?|%?|%?|%?|%?|%?",
                cgs_alignfmt(V[(i + 0u) & 7u], LEFT,  14),
                cgs_alignfmt(V[(i + 1u) & 7u], RIGHT, 13),
                cgs_alignfmt(V[(i + 2u) & 7u], LEFT,  16),
                cgs_alignfmt(V[(i + 3u) & 7u], RIGHT, 12),
                cgs_alignfmt(V[(i + 4u) & 7u], LEFT,  15),
                cgs_alignfmt(V[(i + 5u) & 7u], RIGHT, 18),
                cgs_alignfmt(V[(i + 6u) & 7u], LEFT,  17),
                cgs_alignfmt(V[(i + 7u) & 7u], RIGHT, 12));
    
    return (int)o->len;
}

static int std_views(CGS_StrBuf *o, unsigned i)
{
    const Slice *a = &S[(i + 0u) & 7u], *b = &S[(i + 1u) & 7u];
    const Slice *c = &S[(i + 2u) & 7u], *d = &S[(i + 3u) & 7u];
    const Slice *e = &S[(i + 4u) & 7u], *f = &S[(i + 5u) & 7u];
    const Slice *g = &S[(i + 6u) & 7u], *h = &S[(i + 7u) & 7u];
    
    int n = snprintf(o->chars, o->cap,
                     "%-*.*s|%*.*s|%-*.*s|%*.*s|%-*.*s|%*.*s|%-*.*s|%*.*s",
                     14, a->n, a->p,
                     13, b->n, b->p,
                     16, c->n, c->p,
                     12, d->n, d->p,
                     15, e->n, e->p,
                     18, f->n, f->p,
                     17, g->n, g->p,
                     12, h->n, h->p);        /* 24 variadic arguments, none type-checked */
    
    o->len = clamp_len(n, o->cap);
    return n;
}

/* ==========================================================================
 * Case 2 - integers in five bases and four widths
 * ======================================================================= */

static int cgs_ints(CGS_StrBuf *o, unsigned i)
{
    unsigned k = i & 7u;
    
    cgs_sprintf(o, "d=%? x=%? X=%? o=%? b=%? ll=%? llx=%? z=%?",
                cgs_nfmt(I32[k],              'd'),
                cgs_nfmt(U32[k],              'x'),
                cgs_nfmt(U32[(k + 3u) & 7u],  'X'),
                cgs_nfmt(U32[(k + 5u) & 7u],  'o'),
                cgs_nfmt(U32[(k + 1u) & 7u],  'b'),
                cgs_nfmt(I64[k],              'd'),
                cgs_nfmt(U64[k],              'x'),
                cgs_nfmt(SZ[k],               'd'));
    
    return (int)o->len;
}

static int std_ints(CGS_StrBuf *o, unsigned i)
{
    unsigned k = i & 7u;
    
    /* Every length modifier here (ll, ll, z) is a silent-UB landmine that the
     * cgs version cannot have: cgs_nfmt takes the value, not a promise. */
    int n = snprintf(o->chars, o->cap,
                     "d=%d x=%x X=%X o=%o b=%b ll=%lld llx=%llx z=%zu",
                     I32[k],
                     U32[k],
                     U32[(k + 3u) & 7u],
                     U32[(k + 5u) & 7u],
                     U32[(k + 1u) & 7u],
                     I64[k],
                     U64[k],
                     SZ[k]);
    
    o->len = clamp_len(n, o->cap);
    return n;
}

/* ==========================================================================
 * Case 3 - custom type: one ADD_TOSTR vs. 33 hand-written specifiers
 * ======================================================================= */

#define EVT_FMT \
"Event#%u \"%s\" rect(%d,%d %dx%d) rgba(%u,%u,%u,%u) w=%.2f"

#define EVT_ARGS(e)                                                     \
(e)->id, (e)->label,                                                \
(e)->area.x, (e)->area.y, (e)->area.w, (e)->area.h,                 \
(unsigned)(e)->color.r, (unsigned)(e)->color.g,                     \
(unsigned)(e)->color.b, (unsigned)(e)->color.a,                     \
(e)->weight

static int cgs_events(CGS_StrBuf *o, unsigned i)
{
    unsigned k = i & 7u;
    
    cgs_sprintf(o, "%? | %? | %? | %(short)",
                EV[k],
                EV[(k + 3u) & 7u],
                EV[(k + 5u) & 7u],
                EV[(k + 7u) & 7u]);     /* %(short) picks the compact tostr branch */
    
    return (int)o->len;
}

static int std_events(CGS_StrBuf *o, unsigned i)
{
    unsigned k = i & 7u;
    const Event *e0 = &EV[k];
    const Event *e1 = &EV[(k + 3u) & 7u];
    const Event *e2 = &EV[(k + 5u) & 7u];
    const Event *e3 = &EV[(k + 7u) & 7u];
    
    /* The macro is the charitable version -- without it this is 33 arguments
     * written out three times. Note it still cannot compose with positional
     * specifiers, cannot be nested inside another field, and cannot switch
     * representation the way the fmt_arg branch above does. */
    int n = snprintf(o->chars, o->cap,
                     EVT_FMT " | " EVT_FMT " | " EVT_FMT " | #%u %s",
                     EVT_ARGS(e0), EVT_ARGS(e1), EVT_ARGS(e2),
                     e3->id, e3->label);
    
    o->len = clamp_len(n, o->cap);
    return n;
}

/* ==========================================================================
 * Harness
 * ======================================================================= */

static int std_none(CGS_StrBuf *o, unsigned i)
{
    return 0;
}

typedef int (*bench_fn)(CGS_StrBuf *out, unsigned i);

typedef struct Case {
    char    *name;
    bench_fn std_fn;
    bench_fn cgs_fn;
} Case;

static Case CASES[] = {
    { "1. views  (8 aligned fields)", std_views,  cgs_views  },
    { "2. ints   (d/x/X/o/b/ll/z)",   std_ints,   cgs_ints   },
    { "3. events (custom tostr)",     std_events, cgs_events }
};

NOINLINE static double run(bench_fn f, CGS_StrBuf *out,
                           unsigned iters, unsigned rounds)
{
    double best = 1e300;
    
    for (unsigned r = 0; r < rounds; ++r) {
        unsigned long long acc = 0;
        double t0 = now_sec();
        
        for (unsigned i = 0; i < iters; ++i) {
            f(out, i);
            acc += out->len;
            acc += (unsigned char)out->chars[out->len ? out->len - 1u : 0u];
        }
        
        double dt = now_sec() - t0;
        g_sink += acc;
        if (dt < best) best = dt;
    }
    return best;
}

static int verify(const Case *c)
{
    char sa[BUF_CAP], sb[BUF_CAP];
    CGS_StrBuf a = cgs_strbuf_init_from_buf(sa, sizeof sa);
    CGS_StrBuf b = cgs_strbuf_init_from_buf(sb, sizeof sb);
    int ok = 1;
    
    sa[0] = sb[0] = '\0';
    
    for (unsigned i = 0; i < 8u; ++i) {
        c->std_fn(&a, i);
        c->cgs_fn(&b, i);
        
        if (strcmp(sa, sb) != 0) {
            if (ok) {
                printf("  MISMATCH in %s at i=%u\n", c->name, i);
                printf("    snprintf : [%s]\n", sa);
                printf("    cgs      : [%s]\n", sb);
            }
            ok = 0;
        }
        if (b.len != (unsigned)strlen(sb)) {
            printf("  NOTE: CGS_StrBuf.len (%u) != strlen (%u) at i=%u\n",
                   b.len, (unsigned)strlen(sb), i);
            ok = 0;
        }
    }
    return ok;
}

static void sample(const Case *c)
{
    char s[BUF_CAP];
    CGS_StrBuf o = cgs_strbuf_init_from_buf(s, sizeof s);
    s[0] = '\0';
    c->cgs_fn(&o, 0u);
    printf("  sample: %s\n", s);
}

int main(int argc, char **argv)
{
    char       buf[BUF_CAP];
    CGS_StrBuf out;
    size_t     ncases = sizeof CASES / sizeof CASES[0];
    
    if (argc > 1) {
        unsigned long v = strtoul(argv[1], NULL, 10);
        if (v) g_iters = (unsigned)v;
    }
    
    init_views();
    buf[0] = '\0';
    out = cgs_strbuf_init_from_buf(buf, sizeof buf);
    
    printf("cgs_sprintf vs snprintf -- %u iters x %d rounds, best round kept\n\n",
           g_iters, ROUNDS);
    
    /* Correctness gate first: a benchmark of two different outputs is noise. */
    for (size_t k = 0; k < ncases; ++k) {
        printf("%s\n", CASES[k].name);
        sample(&CASES[k]);
        printf("  verify: %s\n\n", verify(&CASES[k]) ? "identical output" :
        "DIFFERS (see above)");
    }
    
    printf("%-30s %13s %13s %9s %7s\n",
           "case", "snprintf", "cgs_sprintf", "speedup", "bytes");
    printf("%-30s %13s %13s %9s %7s\n",
           "------------------------------", "-------------", "-------------",
           "---------", "-------");
    
    for (size_t k = 0; k < ncases; ++k) {
        double tstd, tcgs;
        unsigned bytes;
        
        /* Warm up both sides: caches, branch predictors, any lazy locale init
         * inside the C library's printf machinery. */
        run(CASES[k].std_fn, &out, WARMUP, 1);
        run(CASES[k].cgs_fn, &out, WARMUP, 1);
        
        tstd = run(CASES[k].std_fn, &out, g_iters, ROUNDS);
        tcgs = run(CASES[k].cgs_fn, &out, g_iters, ROUNDS);
        
        CASES[k].cgs_fn(&out, 0u);
        bytes = out.len;
        
        printf("%-30s %10.1f ns %10.1f ns %8.2fx %7u\n",
               CASES[k].name,
               tstd * 1e9 / (double)g_iters,
               tcgs * 1e9 / (double)g_iters,
               tstd / tcgs,
               bytes);
    }
    
    printf("\nchecksum %llu\n", g_sink);
    return 0;
}