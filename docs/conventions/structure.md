# Directory and File Structure Conventions

## Monorepo Layout

```
proj-03-ultimate-runtime/
├── runtime/          # C libraries (libft, libds, libmath, …)
├── vm/               # Virtual machine implementations
├── parsers/          # Language parsers (JSON, Mini-C, Lox, …)
├── ai/               # Neural nets, ML inference, graphics
├── networking/       # TCP, UDP, HTTP, WebSocket, TLS
├── school/42/        # 42 common-core projects (unmodified)
├── benchmarks/       # Cross-library benchmark harnesses
├── docs/             # Project-level documentation
├── build_system/     # CMake modules and toolchain files
├── scripts/          # Developer tooling scripts
├── tools/            # Standalone dev tools
├── third_party/      # Vendored or fetched dependencies
└── .github/          # CI/CD workflows and PR templates
```

## Per-Library Layout

Every library under `runtime/` (and analogously under `vm/`, `parsers/`, `networking/`) follows:

```
<lib>/
├── CMakeLists.txt        # CMake target definition
├── Makefile              # 42-style make (all/clean/fclean/re/bonus)
├── README.md
├── ARCHITECTURE.md
├── API.md
├── ROADMAP.md
├── TODO.md
├── CHANGELOG.md
├── include/
│   ├── public/<lib>/     # Installed headers — one subdir per namespace
│   └── private/          # Internal headers (never installed)
├── src/                  # Implementation files
├── tests/                # Unit and integration tests
├── benchmarks/           # Microbenchmarks
├── fuzz/                 # LibFuzzer entry points
└── docs/                 # Additional diagrams, notes
```

## Rules

1. **Public headers** live under `include/public/<lib>/` so consumers include `<lib>/foo.h`.
2. **Private headers** live under `include/private/` and are never installed.
3. **One translation unit per module** — `src/string.c` implements `string.h`, not multiple headers.
4. **No circular dependencies** — the layer order (Foundation → Coreutils → Platform → Core → VM → Services → Libraries) must be respected.
5. **CMakeLists.txt required** at every library root — no implicit globbing.
