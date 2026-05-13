# Memory Management Conventions

## Ownership Model

This project follows **explicit single ownership**: every heap allocation has exactly one owner
responsible for freeing it.

```c
/* Caller owns result — must call ft_strdup_free() */
char *ft_strdup(const char *s);
void  ft_strdup_free(char **p);   /* sets *p = NULL after free */
```

## Allocation Patterns

### Raw Allocation

- Use `malloc` / `calloc` / `realloc` / `free` directly in leaf modules.
- Always check the return value; never assume success.
- Set pointers to `NULL` after `free`.

### Arena Allocator (`libds/arena`)

Preferred for short-lived, many-small-allocation workloads (parsers, AST nodes).

```c
arena_t *a = arena_create(64 * 1024);   /* 64 KB slab */
void    *p = arena_alloc(a, sizeof(node_t));
arena_destroy(a);                        /* frees everything at once */
```

### Memory Pool (`libds/pool`)

Preferred for fixed-size objects with high churn (network packets, tokens).

```c
pool_t *pool = pool_create(sizeof(token_t), 256 /* capacity */);
token_t *tok = pool_acquire(pool);
pool_release(pool, tok);
pool_destroy(pool);
```

## Prohibited Patterns

| Pattern                          | Why forbidden                         |
|----------------------------------|---------------------------------------|
| `alloca` / VLAs in hot paths     | Stack overflow risk                   |
| Global mutable state             | Thread-unsafe, hard to test           |
| `realloc` without NULL check     | Leak on failure                       |
| Pointer arithmetic past `end`    | UB — use offset + size instead        |
| Casting `void *` in C            | Unnecessary; obscures type errors     |

## Address Sanitizer

Run all tests with the `asan` preset to catch memory errors automatically:

```sh
cmake --preset asan && cmake --build build/asan
ctest --preset asan --output-on-failure
```
