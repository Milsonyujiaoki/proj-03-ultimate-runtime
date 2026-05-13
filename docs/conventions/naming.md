# Naming Conventions

## Files and Directories

| Artifact        | Convention          | Example                    |
|-----------------|---------------------|----------------------------|
| C source file   | `snake_case.c`      | `memory_pool.c`            |
| C header        | `snake_case.h`      | `memory_pool.h`            |
| C++ source      | `snake_case.cpp`    | `arena_allocator.cpp`      |
| CMakeLists      | `CMakeLists.txt`    | —                          |
| CMake module    | `snake_case.cmake`  | `compiler_flags.cmake`     |
| Shell script    | `snake_case.sh`     | `create_structure.sh`      |
| Python script   | `snake_case.py`     | `generate_library.py`      |

## C Identifiers

| Kind              | Pattern             | Example                       |
|-------------------|---------------------|-------------------------------|
| Variable          | `lower_snake_case`  | `buffer_size`                 |
| Function          | `lib_verb_noun()`   | `ft_strlen()`, `ds_list_push()` |
| Struct typedef    | `name_t`            | `arena_t`                     |
| Struct tag        | `name_s`            | `struct arena_s`              |
| Enum typedef      | `name_e`            | `token_type_e`                |
| Macro constant    | `UPPER_SNAKE_CASE`  | `LIBFT_VERSION`               |
| Macro function    | `UPPER_SNAKE_CASE`  | `ARRAY_LEN(arr)`              |
| Include guard     | `PATH_FILE_H`       | `LIBFT_STRING_H`              |

## Library Prefixes

Each library owns a 2–4 letter prefix to avoid collisions:

| Library    | Prefix  |
|------------|---------|
| libft      | `ft_`   |
| libds      | `ds_`   |
| libmath    | `lm_`   |
| libparse   | `lp_`   |
| networking | `net_`  |
| vm core    | `vm_`   |
| runtime    | `rt_`   |
| ai         | `ai_`   |

## CMake Targets

- Lowercase, hyphen-separated: `libft-core`, `runtime-gc`
- Test executables: `test_<module>` e.g. `test_ft_string`
- Fuzz targets: `fuzz_<module>` e.g. `fuzz_json_parser`
