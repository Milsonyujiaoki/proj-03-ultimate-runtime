# ultimate-runtime

> A professional-grade C/C++ monorepo for building runtimes, virtual machines, parsers,
> networking stacks, data structures, and systems infrastructure — from scratch.

---

## Overview

`ultimate-runtime` is a modular monorepo engineered for:

| Domain | Subprojects |
|---|---|
| **Runtimes & VMs** | `runtime/libruntime`, `runtime/vm/` |
| **Data Structures** | `runtime/libds` (31 containers) |
| **Algorithms** | `runtime/libalgo` (13 categories) |
| **Parsers & ASTs** | `runtime/libparser` (15 formats) |
| **Networking** | `runtime/libnet`, `applications/backend/` |
| **AI / Inference** | `runtime/libai`, `applications/ai/` |
| **Graphics** | `runtime/libgraphics`, `42_specializations/graphics/` |
| **Systems** | `42_specializations/systems/` |
| **42 School** | `42_common_core/`, `42_specializations/` |

---

## Quickstart

```bash
# Clone
git clone https://github.com/Milsonyujiaoki/proj-03-ultimate-runtime.git
cd proj-03-ultimate-runtime

# Bootstrap (installs dependencies, configures CMake)
bash scripts/bootstrap/bootstrap.sh

# Configure + build (Debug)
cmake --preset debug
cmake --build build/debug --parallel

# Run tests
cmake --build build/debug --target test
# or
make test
```

---

## Build Requirements

| Tool | Minimum Version |
|---|---|
| CMake | 3.24 |
| GCC | 12 or Clang 16 |
| Python | 3.9 (scripts only) |
| Make | 4.x (optional wrapper) |

---

## Project Structure

```
ultimate-runtime/
├── runtime/               # Core libraries (libft, libds, libalgo, libparser…)
├── 42_common_core/        # 42 School mandatory projects
├── 42_specializations/    # 42 advanced tracks (graphics, AI, devops…)
├── applications/          # Standalone applications
├── build_system/          # CMake modules, toolchains, presets
├── scripts/               # Automation: bootstrap, CI, generators, fuzzing
├── tools/                 # Static analysis, profiling, debugging configs
├── docs/                  # Architecture docs, conventions, API references
├── specs/                 # Formal specifications per domain
├── research/              # Papers, experiments, prototypes
├── sdk/                   # Language bindings (C, C++, Rust, Python, Lua, WASM)
├── third_party/           # Vendored dependencies
├── playground/            # Sandbox experiments
├── tests/                 # Cross-cutting integration/stress/security tests
└── assets/                # Textures, fonts, shaders, datasets
```

---

## Scaffolding

To regenerate the directory structure in a fresh clone:

```bash
# Linux / macOS
bash create_structure.sh

# Cross-platform (Python 3.9+)
python3 create_structure.py --verbose
python3 create_structure.py --dry-run   # preview without writing
```

---

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for branch naming, commit conventions, and PR guidelines.

---

## License

[MIT](LICENSE) — Milson Yuji Aoki, 2026
