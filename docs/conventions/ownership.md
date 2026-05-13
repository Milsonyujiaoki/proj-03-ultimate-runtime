# Ownership and Lifetime Conventions

## Principles

1. **Single owner** — every resource (heap memory, file descriptor, socket, mutex) has exactly one owner at any point in time.
2. **Transfer on call** — if a function transfers ownership it must be documented with `[transfer]` in the API.md comment.
3. **Borrow for read** — const pointers indicate borrowing; the callee must not free or mutate.
4. **Lifetime ≤ owner** — a borrowed reference must not outlive the owning object.

## Notation in Headers

```c
/* [own] Caller receives ownership — must call free() or the matching _destroy */
char *ft_strdup(const char *s);

/* [borrow] Caller borrows — do NOT free the result */
const char *ds_map_get(const ds_map_t *m, const char *key);

/* [transfer-in] Function takes ownership of `data` */
void ds_list_push(ds_list_t *list, void *data /* [transfer] */);
```

## Destructors

Every opaque struct that allocates resources must provide a matching destructor:

```c
thing_t *thing_create(/* … */);
void     thing_destroy(thing_t **self);   /* sets *self = NULL */
```

Using double-pointer destructors makes use-after-free bugs visible in static analysis.

## Resource Types and Their Owners

| Resource           | Owner type        | Destructor             |
|--------------------|-------------------|------------------------|
| Heap memory        | Calling function  | `free()`               |
| Arena              | `arena_t *`       | `arena_destroy()`      |
| File descriptor    | `io_ctx_t *`      | `io_ctx_close()`       |
| Socket             | `net_conn_t *`    | `net_conn_close()`     |
| Mutex              | Module singleton  | `pthread_mutex_destroy` |
| Thread             | Parent module     | `pthread_join`         |
