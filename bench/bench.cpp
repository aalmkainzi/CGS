#include <benchmark/benchmark.h>
#include <format>
#include <string>
#include <vector>
#include <random>
#include <cstdio>
#include <iterator>

#if 1 || __has_include(<print>)
#include <print>
#define HAS_CPP23_PRINT
#endif

#include "bridge.h"

// TODO change fprint to combine all into dynamic_fprint_buffer and fwrite at once

// --- Data Generation ---

struct TestParams {
    int i;
    double d;
    std::string s;
};

static std::vector<TestParams> G_DATA;
static std::vector<int> G_INT_POOL; // For the append loop
static const size_t POOL_SIZE = 1000;

void InitializeTestData() {
    if (!G_DATA.empty()) return;
    
    std::mt19937 rng(42); // Fixed seed for reproducibility
    std::uniform_int_distribution<int> dist_int(-1000000, 1000000);
    std::uniform_real_distribution<double> dist_dbl(-10000.0, 10000.0);
    const char* strings[] = {"short", "medium-length", "a-considerably-longer-string-to-test-copying"};

    for (size_t i = 0; i < POOL_SIZE; ++i) {
        G_DATA.push_back({
            dist_int(rng),
            dist_dbl(rng),
            strings[i % 3]
        });
        G_INT_POOL.push_back(dist_int(rng));
    }
}

// --- SCENARIO 1: Int to Buffer ---

static void BM_CGS_tostr_int(benchmark::State& state) {
    InitializeTestData();
    char buf[32];
    size_t idx = 0;
    for (auto _ : state) {
        bench_cgs_tostr_int(buf, G_DATA[idx++ % POOL_SIZE].i);
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_CGS_tostr_int);

static void BM_STD_format_int(benchmark::State& state) {
    InitializeTestData();
    char buf[32];
    size_t idx = 0;
    for (auto _ : state) {
        auto [ptr, ec] = std::format_to_n(buf, sizeof(buf), "{}", G_DATA[idx++ % POOL_SIZE].i);
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_STD_format_int);

// --- SCENARIO 2: Multi-arg Fixed Buffer ---

static void BM_CGS_sprint_fixed(benchmark::State& state) {
    InitializeTestData();
    char buf[256];
    size_t idx = 0;
    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
        bench_cgs_sprint_fixed(buf, sizeof(buf), p.i, p.d, p.s.c_str());
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_CGS_sprint_fixed);

static void BM_STD_format_fixed(benchmark::State& state) {
    InitializeTestData();
    char buf[256];
    size_t idx = 0;
    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
        auto it = std::format_to(buf, "i={} d={} s={}", p.i, p.d, p.s);
        *it = '\0'; 
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_STD_format_fixed);

// --- SCENARIO 3: Dynamic Append ---

static void BM_CGS_append_dynamic(benchmark::State& state) {
    InitializeTestData();
    for (auto _ : state) {
        // Appends 100 random ints to a DStr
        bench_cgs_append_dynamic(G_INT_POOL.data(), 100);
    }
}
//BENCHMARK(BM_CGS_append_dynamic);

static void BM_STD_append_dynamic(benchmark::State& state) {
    InitializeTestData();
    for (auto _ : state) {
        std::string s;
        s.reserve(1024); 
        for (int k = 0; k < 100; ++k) {
            std::format_to(std::back_inserter(s), "iteration: {} ", G_INT_POOL[k]);
        }
        benchmark::DoNotOptimize(s);
    }
}
//BENCHMARK(BM_STD_append_dynamic);

// --- SCENARIO 4: File Output ---

static void BM_CGS_fprint(benchmark::State& state) {
    InitializeTestData();
    FILE* tf = std::tmpfile();
    size_t idx = 0;
    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
        bench_cgs_fprint(tf, p.i, p.d, p.s.c_str());
        std::fflush(tf);
        std::fseek(tf, 0, SEEK_SET);
    }
    std::fclose(tf);
}
BENCHMARK(BM_CGS_fprint);

static void BM_CGS_fprint_old(benchmark::State& state) {
    InitializeTestData();
    FILE* tf = std::tmpfile();
    size_t idx = 0;
    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
        bench_cgs_fprint_old(tf, p.i, p.d, p.s.c_str());
        std::fflush(tf);
        std::fseek(tf, 0, SEEK_SET);
    }
    std::fclose(tf);
}
BENCHMARK(BM_CGS_fprint_old);

static void BM_STD_fprint(benchmark::State& state) {
    InitializeTestData();
    FILE* tf = std::tmpfile();
    std::string buf;
    buf.reserve(256);
    size_t idx = 0;

    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
#ifdef HAS_CPP23_PRINT
        std::print(tf, "i={} d={} s={}\n", p.i, p.d, p.s);
#else
        buf.clear();
        std::format_to(std::back_inserter(buf), "i={} d={} s={}\n", p.i, p.d, p.s);
        std::fwrite(buf.data(), 1, buf.size(), tf);
#endif
        std::fflush(tf);
        std::fseek(tf, 0, SEEK_SET);
    }
    std::fclose(tf);
}
BENCHMARK(BM_STD_fprint);

BENCHMARK_MAIN();