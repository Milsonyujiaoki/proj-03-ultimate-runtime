# TODO

Priority: 🔴 Critical · 🟠 High · 🟡 Medium · 🟢 Low

---

## 🔴 Critical

- [ ] Implement `runtime/foundation/memory` — allocator interface
- [ ] Implement `runtime/foundation/atomics` — platform atomic ops
- [ ] Implement `runtime/coreutils/logging` — structured log system
- [ ] Implement `runtime/libft/src/string` — ft_strlen, ft_strcpy, ft_strdup family
- [ ] Implement `runtime/libft/src/memory` — ft_memset, ft_memcpy, ft_memmove
- [ ] Set up root CMakeLists.txt with working CMakePresets
- [ ] Write `scripts/bootstrap/bootstrap.sh`

## 🟠 High

- [ ] Implement `runtime/libds/src/vector` — dynamic array
- [ ] Implement `runtime/libds/src/hashmap` — open-addressing hash table
- [ ] Implement `runtime/libds/src/linked_list` — singly linked list
- [ ] Write unit tests for libft (string + memory modules)
- [ ] Configure clang-format CI check in `build.yml`
- [ ] Write `docs/conventions/naming.md` content

## 🟡 Medium

- [ ] Implement `runtime/libparser/lexer` — generic lexer
- [ ] Implement `runtime/libparser/json` — JSON parser
- [ ] Implement `runtime/core/event_loop` — epoll abstraction
- [ ] Port `42_common_core/libft` with grade-ready Makefile
- [ ] Port `42_common_core/ft_printf` — variadic formatted output
- [ ] Add Valgrind CI step to `tests.yml`
- [ ] Set up `tools/profiling/flamegraph` workflow

## 🟢 Low

- [ ] Implement `runtime/libai` — matrix multiply primitive
- [ ] Set up `sdk/python` — Python cffi bindings for libft
- [ ] Add Doxygen config and `docs.yml` deployment
- [ ] Configure Dependabot for `third_party/` submodules
- [ ] Write `research/notes/allocator_survey.md`
- [ ] Benchmark libds vs std::unordered_map
