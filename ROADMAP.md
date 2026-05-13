# Roadmap

## v0.1 — Foundation Layer
- [ ] `runtime/libft` — complete C standard library reimplementation
- [ ] `runtime/foundation` — memory, atomics, threading primitives
- [ ] `runtime/coreutils` — logging, tracing, panic, assert
- [ ] Root CMakeLists with working presets (debug / release / asan)
- [ ] CI pipeline: build matrix (GCC 12, Clang 16, macOS)
- [ ] Makefile wrapper: `make build`, `make test`, `make fmt`

## v0.2 — Data Structures & Algorithms
- [ ] `runtime/libds` — all 31 containers implemented and tested
- [ ] `runtime/libalgo` — sorting, searching, graph, DP, pathfinding
- [ ] Unit test harness per library (custom framework or Criterion)
- [ ] Benchmark suite with `google/benchmark` integration
- [ ] Fuzz targets for all public APIs via LibFuzzer

## v0.3 — Parser Infrastructure
- [ ] `runtime/libparser/lexer` — generic lexer engine
- [ ] `runtime/libparser/tokenizer` — pluggable tokenizer
- [ ] `runtime/libparser/ast` — generic AST node types
- [ ] `runtime/libparser/json` — RFC 8259 compliant JSON parser
- [ ] `runtime/libparser/shell` — POSIX shell grammar parser

## v0.4 — Runtime Core
- [ ] `runtime/core/scheduler` — cooperative + preemptive scheduler
- [ ] `runtime/core/event_loop` — epoll/kqueue/IOCP abstraction
- [ ] `runtime/core/coroutine` — stackful coroutines (ucontext/fibers)
- [ ] `runtime/core/async` — async/await primitives
- [ ] `runtime/platform` — POSIX, Linux, macOS, Windows, WASM layers

## v0.5 — Virtual Machine
- [ ] `runtime/vm/bytecode` — instruction set design
- [ ] `runtime/vm/interpreter` — stack-based interpreter
- [ ] `runtime/vm/garbage_collector` — mark-and-sweep GC
- [ ] `runtime/vm/optimizer` — peephole + constant folding
- [ ] `runtime/vm/jit` — JIT compilation stub (LLVM backend)

## v0.6 — 42 Common Core
- [ ] Port all 42 mandatory projects under `42_common_core/`
- [ ] Integrate with `runtime/libft` and `runtime/libds`
- [ ] Add automated test runners for each project

## v0.7 — Networking & Services
- [ ] `runtime/libnet` — TCP/UDP/HTTP/WebSocket abstractions
- [ ] `runtime/services/networking` — async I/O layer
- [ ] `applications/backend/reverse_proxy` — HTTP/1.1 + HTTP/2

## v0.8 — AI & Graphics
- [ ] `runtime/libai` — matrix ops, inference primitives
- [ ] `runtime/libgraphics` — 2D/3D primitive rendering
- [ ] `42_specializations/ai/neural_network` — feedforward NN from scratch
- [ ] `42_specializations/graphics/vulkan_renderer` — Vulkan triangle

## v0.9 — Systems Specializations
- [ ] `42_specializations/systems/mini_kernel` — x86 bootloader + protected mode
- [ ] `42_specializations/systems/filesystem` — ext2-like filesystem
- [ ] `42_specializations/systems/compiler` — toy language → bytecode

## v1.0 — Production Hardening
- [ ] Security audit of all public APIs
- [ ] Fuzzing coverage ≥ 80% on all parsers
- [ ] Performance regression CI gate
- [ ] Complete SDK bindings (Python, Rust, Lua, WASM)
- [ ] Full documentation site (Doxygen + custom theme)
- [ ] Semantic release automation (changelog, tags, GitHub releases)
