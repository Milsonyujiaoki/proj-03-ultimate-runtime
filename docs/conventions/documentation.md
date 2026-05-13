# Documentation Conventions

## Required Documents per Library

| File             | Purpose                                          |
|------------------|--------------------------------------------------|
| `README.md`      | One-paragraph description + quickstart           |
| `ARCHITECTURE.md`| Layer diagram, design decisions, invariants      |
| `API.md`         | Function-by-function reference (auto-generated)  |
| `ROADMAP.md`     | Milestone list and feature backlog               |
| `TODO.md`        | Prioritized task list (🔴🟠🟡🟢)                 |
| `CHANGELOG.md`   | Keep-a-Changelog format                          |

## In-Code Documentation

Use **Doxygen** style for all public headers:

```c
/**
 * @brief Copy at most `n` bytes from `src` to `dst`.
 *
 * Behaviour is undefined if the regions overlap — use ft_memmove() instead.
 *
 * @param[out] dst  Destination buffer.
 * @param[in]  src  Source buffer.
 * @param[in]  n    Number of bytes to copy.
 * @return          Pointer to `dst`.
 *
 * @note MT-SAFE
 */
void *ft_memcpy(void *dst, const void *src, size_t n);
```

Required tags: `@brief`, `@param`, `@return`.  
Optional tags: `@note` (thread safety), `@warning` (UB conditions), `@see` (related functions).

## Generating Docs

```sh
make docs          # runs Doxygen + deploys to gh-pages (CI)
```

Local preview:

```sh
doxygen docs/Doxyfile
open build/docs/html/index.html
```

## Changelog Format

Follow [Keep a Changelog](https://keepachangelog.com):

```markdown
## [Unreleased]
### Added
- ft_strtrim: new function

### Fixed
- ft_itoa: off-by-one for INT_MIN
```

Categories: `Added`, `Changed`, `Deprecated`, `Removed`, `Fixed`, `Security`.
