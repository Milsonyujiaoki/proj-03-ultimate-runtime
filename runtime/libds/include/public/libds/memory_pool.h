#ifndef LIBDS_MEMORY_POOL_H
#define LIBDS_MEMORY_POOL_H

#include <stddef.h>

typedef struct ds_pool ds_pool_t;

/**
 * @brief Fixed-size object pool.
 *        O(1) acquire and release with no fragmentation.
 *
 * @param obj_size   Size of each object in bytes.
 * @param capacity   Maximum number of objects.
 */
ds_pool_t *ds_pool_create(size_t obj_size, size_t capacity);
void       ds_pool_destroy(ds_pool_t **self);
void      *ds_pool_acquire(ds_pool_t *p);         /* NULL if pool is exhausted */
void       ds_pool_release(ds_pool_t *p, void *obj);
size_t     ds_pool_available(const ds_pool_t *p);
size_t     ds_pool_capacity(const ds_pool_t *p);

#endif /* LIBDS_MEMORY_POOL_H */
