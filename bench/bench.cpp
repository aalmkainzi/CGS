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
    long long i; // Changed to long long
    double d;
    std::string s;
    std::string s2; // Added another string for more complexity
};

static std::vector<TestParams> G_DATA;
static std::vector<long long> G_LLONG_POOL; // For the append loop, changed to long long
static const size_t POOL_SIZE = 1000;

void InitializeTestData() {
    if (!G_DATA.empty()) return;
    
    std::mt19937 rng(42); // Fixed seed for reproducibility
    std::uniform_int_distribution<long long> dist_llong(-9223372036854775807LL, 9223372036854775807LL); // long long range
    std::uniform_real_distribution<double> dist_dbl(-10000.0, 10000.0);
    const char* strings[] = {
        "short_str", 
        "medium-length_string_example", 
        "a-considerably-longer-string-to-test-copying-and-buffer-handling-efficiency",
        "another_quite_long_string_with_some_special_characters_!@#$%",
        "yet_another_string_for_variety_and_more_data_movement_tests_1234567890"
    };

    for (size_t i = 0; i < POOL_SIZE; ++i) {
        G_DATA.push_back({
            dist_llong(rng),
            dist_dbl(rng),
            strings[i % 5], // Use more strings
            strings[(i + 1) % 5] // Another string
        });
        G_LLONG_POOL.push_back(dist_llong(rng));
    }
}

// --- SCENARIO 1: Int to Buffer ---

static void BM_CGS_tostr_llong(benchmark::State& state) {
    InitializeTestData();
    char buf[64]; // Increased buffer size for long long
    size_t idx = 0;
    for (auto _ : state) {
        bench_cgs_tostr_llong(buf, G_DATA[idx++ % POOL_SIZE].i);
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_CGS_tostr_llong);

static void BM_STD_format_llong(benchmark::State& state) {
    InitializeTestData();
    char buf[64]; // Increased buffer size for long long
    size_t idx = 0;
    for (auto _ : state) {
        auto [ptr, ec] = std::format_to_n(buf, sizeof(buf), "{}", G_DATA[idx++ % POOL_SIZE].i);
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_STD_format_llong);

// --- SCENARIO 2: Multi-arg Fixed Buffer ---

static void BM_CGS_sprint_fixed(benchmark::State& state) {
    InitializeTestData();
    char buf[1024]; // Increased buffer size significantly
    size_t idx = 0;
    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
        bench_cgs_sprint_fixed(buf, sizeof(buf), p.i, p.d, p.s.c_str(), p.s2.c_str());
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_CGS_sprint_fixed);

static void BM_STD_format_fixed(benchmark::State& state) {
    InitializeTestData();
    char buf[1024]; // Increased buffer size significantly
    size_t idx = 0;
    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
        // Much more complex format string
        auto it = std::format_to(buf, 
            "Data {{ id: {}, value: {:+.4f}, primary_tag: \"{}\", secondary_tag: \"{}\", timestamp: {} ns, version: 1.0.0, status: OK }}", 
            p.i, p.d, p.s, p.s2, p.i * 123456789LL); // Added another long long calculated value
        *it = '\0'; 
        benchmark::DoNotOptimize(buf);
    }
}
BENCHMARK(BM_STD_format_fixed);

// --- SCENARIO 3: Dynamic Append ---

static void BM_CGS_append_dynamic(benchmark::State& state) {
    InitializeTestData();
    for (auto _ : state) {
        // Appends 100 random long longs to a DStr
        bench_cgs_append_dynamic(G_LLONG_POOL.data(), 100); // Changed to G_LLONG_POOL
    }
}
BENCHMARK(BM_CGS_append_dynamic);

static void BM_STD_append_dynamic(benchmark::State& state) {
    InitializeTestData();
    for (auto _ : state) { // Moved state loop outside the inner k loop
        std::string s;
        s.reserve(4096); // Increased initial reserve for more appends
        for (int k = 0; k < 100; ++k) {
            // More complex append format
            std::format_to(std::back_inserter(s), "Entry {}: value = {:020d} | ", k, G_LLONG_POOL[k]);
        }
        benchmark::DoNotOptimize(s);
    }
}
// BENCHMARK(BM_STD_append_dynamic);

// --- SCENARIO 4: File Output ---

static void BM_CGS_fprint(benchmark::State& state) {
    InitializeTestData();
    FILE* tf = std::tmpfile();
    size_t idx = 0;
    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
        bench_cgs_fprint(tf, p.i, p.d, p.s.c_str(), p.s2.c_str(), p.i * 123456789LL); // Passing computed_val
        std::fflush(tf);
        std::fseek(tf, 0, SEEK_SET);
    }
    std::fclose(tf);
}
BENCHMARK(BM_CGS_fprint);

static void BM_STD_fprint(benchmark::State& state) {
    InitializeTestData();
    FILE* tf = std::tmpfile();
    std::string buf;
    buf.reserve(1024); // Increased reserve for file output
    size_t idx = 0;

    for (auto _ : state) {
        const auto& p = G_DATA[idx++ % POOL_SIZE];
#ifdef HAS_CPP23_PRINT
        std::print(tf, 
            "FileRecord: {{ ID: {}, Amount: {:+.6f}, Desc1: \"{}\", Desc2: \"{}\", Hash: {:x}, Severity: {}, Timestamp2: {} }}\n", 
            p.i, p.d, p.s, p.s2, static_cast<unsigned long long>(p.i) ^ 0xDEADBEEF, 3, p.i * 123456789LL); // Re-added computed_val
#else
        buf.clear();
        std::format_to(std::back_inserter(buf), 
            "FileRecord: {{ ID: {}, Amount: {:+.6f}, Desc1: \"{}\", Desc2: \"{}\", Hash: {:x}, Severity: {}, Timestamp2: {} }}\n", 
            p.i, p.d, p.s, p.s2, static_cast<unsigned long long>(p.i) ^ 0xDEADBEEF, 3, p.i * 123456789LL); // Re-added computed_val
        std::fwrite(buf.data(), 1, 1, buf.size(), tf);
#endif
        std::fflush(tf);
        std::fseek(tf, 0, SEEK_SET);
    }
    std::fclose(tf);
}
BENCHMARK(BM_STD_fprint);

BENCHMARK_MAIN();