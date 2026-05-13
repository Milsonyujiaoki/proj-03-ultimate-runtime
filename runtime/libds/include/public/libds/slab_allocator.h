#ifndef LIBDS_SLAB_ALLOCATOR_H
#define LIBDS_SLAB_ALLOCATOR_H

#include <stddef.h>

typedef struct ds_slab ds_slab_t;

/**
 * @brief Slab allocator — caches freed objects for immediate re-use.
 *        Suitable for high-churn, same-size allocations.
 *
 * @param obj_size  Size of each slab object in bytes.
 * @param slab_cap  Number of objects per slab.
 */
ds_slab_t *ds_slab_create(size_t obj_size, size_t slab_cap);
void       ds_slab_destroy(ds_slab_t **self);
void      *ds_slab_alloc(ds_slab_t *s);
void       ds_slab_free(ds_slab_t *s, void *obj);
size_t     ds_slab_allocated(const ds_slab_t *s);

#endif /* LIBDS_SLAB_ALLOCATOR_H */
