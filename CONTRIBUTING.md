# Contributing

Thank you for contributing to `ultimate-runtime`.

---

## Development Setup

```bash
# 1. Fork and clone
git clone https://github.com/<your-username>/proj-03-ultimate-runtime.git
cd proj-03-ultimate-runtime

# 2. Install dependencies
bash scripts/bootstrap/bootstrap.sh

# 3. Configure for development
cmake --preset debug

# 4. Build
cmake --build build/debug --parallel

# 5. Run tests
cmake --build build/debug --target test
```

---

## Branch Naming

| Prefix | Purpose |
|---|---|
| `feat/` | New feature |
| `fix/` | Bug fix |
| `refactor/` | Code refactor (no behavior change) |
| `perf/` | Performance improvement |
| `docs/` | Documentation only |
| `test/` | Tests only |
| `chore/` | Build, CI, tooling changes |
| `security/` | Security fix |

Examples: `feat/libds-avl-tree`, `fix/libft-strlcpy-boundary`, `docs/architecture-diagram`

---

## Commit Convention

Follows [Conventional Commits](https://www.conventionalcommits.org/):

```
<type>(<scope>): <description>

[optional body]

[optional footer]
```

Examples:
```
feat(libds): add AVL tree with left/right rotation
fix(libft): fix ft_strlcpy off-by-one on empty dst
perf(libalgo): optimize quicksort pivot selection
docs(architecture): add layer dependency diagram
test(libds): add fuzz target for hashmap insert
```

Types: `feat`, `fix`, `refactor`, `perf`, `docs`, `test`, `chore`, `security`, `build`, `ci`

---

## Code Style

- **Formatter**: `clang-format` (config in `.clang-format`)  
  Run: `make fmt` or `bash scripts/formatting/format.sh`
- **Linter**: `clang-tidy` (config in `.clang-tidy`)  
  Run: `make lint` or `bash scripts/formatting/lint.sh`
- **Style guide**: see [docs/conventions/style_guide.md](docs/conventions/style_guide.md)

---

## Pull Request Process

1. Create a branch from `main` with the naming convention above.
2. Keep PRs focused — one feature or fix per PR.
3. All CI checks must pass before merging.
4. Add or update tests for any behavior change.
5. Update docs if public APIs change.
6. Request a review from at least one maintainer.

---

## Testing

```bash
# Unit tests for a specific library
cmake --build build/debug --target libft_tests
ctest --test-dir build/debug --output-on-failure -R libft

# All tests with sanitizers
cmake --preset asan
cmake --build build/asan --parallel
ctest --test-dir build/asan --output-on-failure

# Fuzz a target (requires clang)
cmake --preset fuzz
cmake --build build/fuzz --target libds_fuzz_hashmap
./build/fuzz/runtime/libds/fuzz/libds_fuzz_hashmap -max_total_time=60
```

---

## Adding a New Library

Use the generator script:

```bash
python3 scripts/generators/generate_library.py --name mylibrary --type c
```

This creates the canonical directory structure under `runtime/mylibrary/`.

---

## Security

Report security vulnerabilities via email to the maintainer — do not open a public issue.
