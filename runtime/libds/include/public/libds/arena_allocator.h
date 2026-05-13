#ifndef LIBDS_ARENA_ALLOCATOR_H
#define LIBDS_ARENA_ALLOCATOR_H

#include <stddef.h>

typedef struct ds_arena ds_arena_t;

/**
 * @brief Region-based allocator — allocate fast, free all at once.
 * @param size  Initial slab size in bytes.
 */
ds_arena_t *ds_arena_create(size_t size);
void        ds_arena_destroy(ds_arena_t **self);

/**
 * @brief Allocate @p n bytes from the arena, aligned to @p align.
 * @return Pointer to memory, or NULL if @p n > remaining slab space.
 * @note  UNSAFE — not thread-safe without external lock.
 */
void       *ds_arena_alloc(ds_arena_t *a, size_t n, size_t align);

/** @brief Reset the arena (reclaim all memory without deallocation). */
void        ds_arena_reset(ds_arena_t *a);

size_t      ds_arena_used(const ds_arena_t *a);
size_t      ds_arena_capacity(const ds_arena_t *a);

#endif /* LIBDS_ARENA_ALLOCATOR_H */
