#ifndef BRIDGE_H
#define BRIDGE_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void cgs_init_once(void);

// Scenario 1: Raw Integer to Buffer
void bench_cgs_tostr_int(char* buf, int val);

// Scenario 2: Fixed Buffer Multi-argument
void bench_cgs_sprint_fixed(char* buf, unsigned cap, int i, double d, const char* s);

// Scenario 3: Dynamic Appending (now takes the data as input to be fair)
void bench_cgs_append_dynamic(int* int_pool, unsigned count);

// Scenario 4: File Output
void bench_cgs_fprint(FILE* f, int i, double d, const char* s);

#ifdef __cplusplus
}
#endif

#endif