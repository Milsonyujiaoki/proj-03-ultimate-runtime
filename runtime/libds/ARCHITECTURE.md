# libds Architecture

## Layer

`libds` is in the **Coreutils** layer. It may depend on `libft` (Foundation) but on no other
project library.

## Design Principles

1. **Type-safe via void pointer + size** — all containers store `void *` for generic use.
2. **Allocator-aware** — every container accepts an optional `ds_alloc_t` allocator; defaults to `malloc/free`.
3. **Opaque types** — internal struct definitions live in `include/private/`; public headers expose only typedef pointers.
4. **Consistent API shape** — all containers follow the same lifecycle: `_create`, `_destroy`, `_size`, `_clear`.

## Dependency Graph

```
libds → libft (Foundation)
     → <nothing else>
```

## Module Groups

```
libds/
├── linear/       vector, linked_list, doubly_linked_list, circular_list, ring_buffer
├── stack_queue/  stack, queue, deque
├── hash/         hashmap, hashset
├── tree/         bst, avl, red_black_tree, btree, trie, radix_tree, interval_tree, kd_tree
├── heap/         heap, priority_queue
├── graph/        graph
├── string/       rope, string_builder
├── bits/         bitset, union_find
├── cache/        lru_cache
├── probabilistic/bloom_filter, skiplist
└── allocator/    arena_allocator, memory_pool, slab_allocator
```

## Allocator Protocol

```c
typedef struct {
    void *(*alloc)(size_t size, void *ctx);
    void  (*free)(void *ptr,  void *ctx);
    void  *ctx;
} ds_alloc_t;

extern const ds_alloc_t DS_ALLOC_DEFAULT;  /* malloc/free */
```
