//
// Created by Kenneth Balslev on 19/06/2020.
//


#include <benchmark/benchmark.h>

/**
 * @brief
 * @param state
 */
static void BM_Test(benchmark::State& state)
{

    for (auto _ : state)
        // Insert benchmark code here
}

BENCHMARK(BM_Test)->Unit(benchmark::kMillisecond);

