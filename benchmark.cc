#include <benchmark/benchmark.h>

#include "md5.h"

std::string test_data() {
    char data[64];
    for (char i = 0; i < 64; ++i) {
        data[i] = i;
    }
    return {data, data + 64};
}

static void MD5_Update(benchmark::State &state) {
    const auto data = test_data();

    md5::MD5 kk;

    for (auto _ : state) {
        kk.Update(data.c_str(), 64);
    }
}

BENCHMARK(MD5_Update);

BENCHMARK_MAIN();
