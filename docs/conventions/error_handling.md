# Error Handling Conventions

## Strategy

This project uses **return-code error handling** (no exceptions, no `setjmp/longjmp` outside the
VM layer). Every function that can fail returns an error indicator.

## Error Codes

Each library defines its own `<lib>_err_e` enum and maps to the global `ur_err_e`:

```c
/* global errors (ur_err.h) */
typedef enum {
    UR_OK           =  0,
    UR_ERR_NOMEM    = -1,
    UR_ERR_INVAL    = -2,
    UR_ERR_OVERFLOW = -3,
    UR_ERR_IO       = -4,
    UR_ERR_TIMEOUT  = -5,
    UR_ERR_UNKNOWN  = -99,
} ur_err_e;

const char *ur_strerror(ur_err_e err);
```

## Return Patterns

### Nullable pointer

```c
/* Returns NULL on failure; caller checks */
ft_list_t *ft_list_create(size_t capacity);
```

### Integer status

```c
/* Returns UR_OK (0) on success, negative ur_err_e on failure */
int ds_map_insert(ds_map_t *m, const char *key, void *value);
```

### Out-parameter

```c
/* Returns status; result written to *out (unchanged on error) */
int net_resolve(const char *host, net_addr_t *out);
```

## Rules

1. **Never ignore return values** — use `(void)` cast only for intentional discards.
2. **Propagate, don't swallow** — if a callee fails, return the error to the caller.
3. **Log at the boundary** — log errors at the public API boundary, not deep in helpers.
4. **Errno** — set `errno` only in POSIX-compatible wrappers; internal functions use `ur_err_e`.
5. **Assertions** — `assert()` for programmer errors (preconditions); error codes for runtime failures.
6. **No silent truncation** — if a buffer is too small, return `UR_ERR_OVERFLOW`, not a silent partial write.
