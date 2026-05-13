# Changelog

All notable changes to `ultimate-runtime` are documented here.

Format: [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)  
Versioning: [Semantic Versioning](https://semver.org/spec/v2.0.0.html)

---

## [Unreleased]

### Added
- Initial monorepo scaffold with full directory structure
- `create_structure.py` — cross-platform Python scaffolding script
- `create_structure.sh` — Bash scaffolding script (Linux/macOS)
- Root CMakeLists.txt with CMakePresets (debug/release/asan/tsan/fuzz)
- Build system modules: compiler_flags, warnings, sanitizers, profiling, testing, packaging, dependencies
- Toolchain files: linux-clang, linux-gcc, macos-clang, windows-msvc, wasm
- GitHub Actions workflows: build, tests, fuzz, benchmark, docs, release, security
- `runtime/libft` skeleton with 10 public headers
- `runtime/libds` skeleton with 31 public headers
- `docs/conventions/` — 10 coding convention documents

---

## [0.0.1] — 2026-05-13

### Added
- Repository initialized
- Monorepo structure defined
