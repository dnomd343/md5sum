#include <benchmark/benchmark.h>

#include "md5.h"

std::string test_data() {
    char data[64];
    for (char i = 0; i < 64; ++i) {
        data[i] = i;
    }
    return {data, data + 64};
}

static void BM_MD5_NEXT(benchmark::State &state) {
    const auto data = test_data();

    md5::MD5::md5_ctx c;
    md5::MD5::md5_reset(&c);

    for (auto _ : state) {
        md5::MD5::md5_update(&c, data.c_str(), 64);
    }
}

BENCHMARK(BM_MD5_NEXT);

BENCHMARK_MAIN();
