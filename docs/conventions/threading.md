# Threading Conventions

## Thread Safety Levels

Every public API function must be documented with one of these levels:

| Level       | Meaning                                              |
|-------------|------------------------------------------------------|
| `UNSAFE`    | Must be called from a single thread only             |
| `MT-SAFE`   | Safe to call concurrently from multiple threads      |
| `MT-SAFE/re` | MT-Safe and re-entrant                              |
| `ONCE`      | Safe to call once; use `pthread_once` wrapper        |

Example annotation in header comment:

```c
/* MT-SAFE — protected by internal spinlock */
void ds_queue_push(ds_queue_t *q, void *item);

/* UNSAFE — single-threaded arena, no locking */
void *arena_alloc(arena_t *a, size_t n);
```

## Synchronisation Primitives

| Use case                | Preferred primitive          |
|-------------------------|------------------------------|
| Short critical section  | Spinlock (`atomic_flag`)     |
| Long critical section   | `pthread_mutex_t`            |
| Reader/writer           | `pthread_rwlock_t`           |
| One-time init           | `pthread_once_t`             |
| Producer/consumer       | `pthread_cond_t` + mutex     |
| Lock-free counters      | `_Atomic int` / `stdatomic.h` |

## Rules

1. **No global mutable state** without explicit MT-SAFE annotation.
2. **Lock ordering** — always acquire locks in the same global order to prevent deadlocks.  
   Document the order in the module's `ARCHITECTURE.md`.
3. **No recursive locks** — use `PTHREAD_MUTEX_ERRORCHECK` in debug builds.
4. **TSAN preset** — run `cmake --preset tsan` to detect data races.
5. **Avoid blocking** inside a spinlock; use a mutex instead.

## Thread Sanitizer

```sh
cmake --preset tsan && cmake --build build/tsan
ctest --preset tsan --output-on-failure
```
