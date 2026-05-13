# Performance Conventions

## Guiding Principles

1. **Measure before optimising** — profile first, never guess.
2. **Algorithmic complexity first** — prefer O(n log n) over O(n²) before micro-optimising.
3. **Cache friendliness** — prefer struct-of-arrays over array-of-structs for hot data.
4. **Avoid dynamic allocation in hot paths** — use arenas, pools, or stack allocation.

## Benchmark Harness

Use `google/benchmark` via `ur_add_benchmark()`:

```cmake
ur_add_benchmark(
    NAME  bench_ft_memcpy
    SOURCES benchmarks/bench_memcpy.cpp
    LIBS libft
)
```

```cpp
#include <benchmark/benchmark.h>
extern "C" { #include "libft/memory.h" }

static void BM_FtMemcpy(benchmark::State &state)
{
    std::vector<char> src(state.range(0), 'x');
    std::vector<char> dst(state.range(0));
    for (auto _ : state)
        ft_memcpy(dst.data(), src.data(), state.range(0));
    state.SetBytesProcessed(state.iterations() * state.range(0));
}
BENCHMARK(BM_FtMemcpy)->Range(64, 64 << 20);
BENCHMARK_MAIN();
```

Run with: `make bench`

## Profiling

| Tool     | Preset / flag              | Use case                         |
|----------|----------------------------|----------------------------------|
| gprof    | `UR_ENABLE_GPROF=ON`       | Function-level call graph (Linux)|
| perf     | `UR_ENABLE_PERF=ON`        | Hardware counters (Linux)        |
| Tracy    | `UR_ENABLE_TRACY=ON`       | Frame-level real-time profiling  |
| Valgrind | none — run externally      | Cache miss analysis (`cachegrind`)|

Run profiling build: `make profile`

## Hot-Path Rules

- No `printf` / `malloc` in tight loops.
- Avoid `strlen` on constant strings — use string literals with known lengths.
- Prefer `__builtin_expect(cond, 0)` for error branches in critical code.
- Use `restrict` on non-aliasing pointer parameters where proven safe.
- Align performance-critical structs to cache lines with `_Alignas(64)`.
