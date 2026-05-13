# Architecture

## Monorepo Layer Model

```
┌─────────────────────────────────────────────────────────────────┐
│                        APPLICATIONS                             │
│  cli/  distributed/  ai/  systems/  graphics/  backend/        │
├─────────────────────────────────────────────────────────────────┤
│                     42 SPECIALIZATIONS                          │
│  graphics  cybersecurity  devops  ai  systems  networking       │
├─────────────────────────────────────────────────────────────────┤
│                      42 COMMON CORE                             │
│  libft  ft_printf  minishell  philosophers  webserv  …          │
├─────────────────────────────────────────────────────────────────┤
│                    RUNTIME LIBRARIES                            │
│  libft  libds  libalgo  libparser  libnet  libai  libgraphics   │
├──────────────┬──────────────┬───────────────┬───────────────────┤
│ runtime/core │  runtime/vm  │runtime/services│  runtime/platform │
├──────────────┴──────────────┴───────────────┴───────────────────┤
│               runtime/foundation  +  runtime/coreutils          │
│  memory  atomics  threading  unicode  logging  arena  error     │
└─────────────────────────────────────────────────────────────────┘
                           BUILD SYSTEM
               cmake/  toolchains/  presets/  scripts/
```

---

## Layer Descriptions

### Foundation (`runtime/foundation/`)
Zero-dependency primitives. No standard library usage permitted.
Provides: memory layout helpers, atomic operations, mutex/condvar wrappers, UTF-8
codec, arena allocator, intrusive containers, error types.

### Coreutils (`runtime/coreutils/`)
Thin wrappers over Foundation exposing ergonomic logging, tracing, panic/assert
macros, and platform detection. Every other module depends on this.

### Platform (`runtime/platform/`)
OS-specific code isolated behind a uniform interface. Each target (linux, macos,
windows, posix, wasm) implements the same set of platform abstractions (file I/O,
threads, clocks, signals).

### Core (`runtime/core/`)
Scheduler, event loop, coroutines, fibers, async primitives. All higher-level
concurrency primitives are built on this layer.

### VM (`runtime/vm/`)
Self-contained bytecode virtual machine with interpreter, optional JIT, and
garbage collector. No dependency on application code.

### Services (`runtime/services/`)
Networking I/O, database drivers, serialization codecs, caching primitives.
Depend only on Foundation + Platform.

### Runtime Libraries (`runtime/lib*/`)
Purpose-built libraries:
- `libft` — C standard library reimplementation
- `libds` — 31 generic data structures
- `libalgo` — algorithms by category
- `libparser` — lexer/tokenizer/AST/format parsers
- `libnet` — TCP/UDP/HTTP/WebSocket
- `libai` — matrix ops, inference primitives
- `libgraphics` — 2D/3D rendering
- `libdatabase` — storage engine primitives
- `libsecurity` — crypto, hashing, TLS abstractions

---

## Dependency Rules

1. **No upward dependencies** — lower layers must never import upper layers.
2. **No circular dependencies** — enforced by CMake target dependency graph.
3. **Foundation is dependency-free** — stdlib usage banned in `runtime/foundation/`.
4. **Platform isolation** — all OS calls go through `runtime/platform/`.
5. **Third-party at the boundary** — `third_party/` is only linked by the topmost
   layer that requires it.

---

## Build System Design

```
CMakeLists.txt (root)
├── include(build_system/cmake/compiler_flags.cmake)
├── include(build_system/cmake/warnings.cmake)
├── include(build_system/cmake/sanitizers.cmake)
├── include(build_system/cmake/dependencies.cmake)
├── add_subdirectory(runtime/foundation)
├── add_subdirectory(runtime/coreutils)
├── add_subdirectory(runtime/platform)
├── add_subdirectory(runtime/core)
├── add_subdirectory(runtime/vm)
├── add_subdirectory(runtime/services)
├── add_subdirectory(runtime/libft)
├── add_subdirectory(runtime/libds)
└── …
```

CMakePresets:
- `debug`   — `-O0 -g3`, ASAN+UBSAN enabled
- `release` — `-O3 -DNDEBUG -march=native`
- `asan`    — AddressSanitizer
- `tsan`    — ThreadSanitizer
- `fuzz`    — LibFuzzer + coverage instrumentation

---

## Key Decisions

| Decision | Rationale |
|---|---|
| C17 + C++20 | Best balance of portability and modern features |
| CMake ≥ 3.24 | Native preset support (CMakePresets.json v3) |
| Monorepo | Single source of truth, unified CI, shared tooling |
| Zero-dependency Foundation | Portable to bare-metal and WASM targets |
| `.gitkeep` in empty dirs | Git doesn't track empty directories |
| clang-format (Google base) | Consistent style across C and C++ code |
