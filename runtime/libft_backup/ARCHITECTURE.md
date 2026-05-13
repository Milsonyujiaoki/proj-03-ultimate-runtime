# libft Architecture

## Layer

`libft` is in the **Foundation** layer — it has zero project dependencies and may only use the
C17 standard library.

## Design Decisions

| Decision | Rationale |
|----------|-----------|
| No external includes inside headers | Headers must be self-contained |
| `size_t` return for lengths | Matches POSIX; avoids signed/unsigned mismatch |
| `ft_` prefix for all symbols | Avoids collision with libc on linkers that include both |
| `_fd` suffix variants for I/O | Allows writing to arbitrary file descriptors |
| `strlcpy`/`strlcat` semantics | Safer than `strcpy`/`strcat`; returns total desired length |

## Module Dependency Graph

```
libft.h (umbrella)
├── string.h      → memory.h, ctype.h
├── memory.h      (standalone)
├── ctype.h       (standalone)
├── stdio.h       → unistd.h
├── stdlib.h      → string.h, math.h
├── unistd.h      (standalone)
├── math.h        (standalone)
├── time.h        (standalone)
└── errno.h       (standalone)
```

## Invariants

- Functions never call `abort()` or `exit()` — errors are returned to the caller.
- All pointer parameters are validated (NULL-safe where the C standard mandates it).
- No use of VLAs.
- No global mutable state.
