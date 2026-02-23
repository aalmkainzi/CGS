#include <benchmark/benchmark.h>
#include <iostream>

extern "C"
{
    size_t nsbm(size_t);
    size_t stdbm(size_t);
    size_t std_it2str(size_t i);
    size_t cgs_it2str(size_t i);
}

static void BM_neat(benchmark::State& state) {
    size_t v = state.range(0);
    
    std::cerr << nsbm(v) << std::endl;
    for (auto _ : state) {
        size_t s = nsbm(v);
        benchmark::DoNotOptimize(s);
    }
}

static void BM_std(benchmark::State& state) {
    size_t v = state.range(0);
    std::cerr << stdbm(v) << std::endl;
    for (auto _ : state) {
        size_t s = stdbm(v);
        benchmark::DoNotOptimize(s);
    }
}

static void BM_neat2(benchmark::State& state) {
    size_t v = state.range(0);
    
    std::cerr << nsbm(v) << std::endl;
    for (auto _ : state) {
        size_t s = cgs_it2str(v);
        benchmark::DoNotOptimize(s);
    }
}

static void BM_std2(benchmark::State& state) {
    size_t v = state.range(0);
    std::cerr << stdbm(v) << std::endl;
    for (auto _ : state) {
        size_t s = std_it2str(v);
        benchmark::DoNotOptimize(s);
    }
}

BENCHMARK(BM_neat2)->Range(10000, 100000);
BENCHMARK(BM_std2) ->Range(10000, 100000);
BENCHMARK_MAIN();