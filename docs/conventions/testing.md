# Testing Conventions

## Test Levels

| Level         | Location              | Framework       | Preset       |
|---------------|-----------------------|-----------------|--------------|
| Unit          | `<lib>/tests/`        | GoogleTest      | debug        |
| Integration   | `tests/integration/`  | GoogleTest      | debug        |
| Fuzz          | `<lib>/fuzz/`         | LibFuzzer       | fuzz         |
| Benchmark     | `<lib>/benchmarks/`   | google/benchmark| release      |
| Sanitizer     | same as unit/integ    | —               | asan / tsan  |

## Naming

- Test binary:   `test_<library>_<module>` — e.g. `test_libft_string`
- Test suite:    `ClassName` = `<Library><Module>Test` — e.g. `LibftStringTest`
- Test name:     `MethodName_StateUnderTest_ExpectedBehavior`

```cpp
TEST(LibftStringTest, FtStrlen_EmptyString_ReturnsZero) {
    EXPECT_EQ(ft_strlen(""), 0);
}
```

## Coverage Requirements

| Layer       | Minimum line coverage |
|-------------|-----------------------|
| Foundation  | 95 %                  |
| Coreutils   | 90 %                  |
| Libraries   | 80 %                  |
| VM / JIT    | 70 %                  |

## Running Tests

```sh
# All tests (debug)
make test

# With AddressSanitizer
make test-asan

# With ThreadSanitizer
make test-tsan

# Specific preset via CTest
cmake --preset asan && cmake --build build/asan
ctest --preset asan --output-on-failure -R "libft"
```

## Fuzz Targets

Every parser and protocol decoder must have at least one fuzz entry point:

```c
/* fuzz/fuzz_json.c */
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    json_parser_t p;
    json_parser_init(&p, (const char *)data, size);
    json_node_t *root = json_parse(&p);
    json_node_free(root);
    return 0;
}
```

Build with: `cmake --preset fuzz && cmake --build build/fuzz`
