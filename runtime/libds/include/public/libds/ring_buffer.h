#ifndef LIBDS_RING_BUFFER_H
#define LIBDS_RING_BUFFER_H

#include <stddef.h>

typedef struct ds_ring ds_ring_t;

/** @brief Fixed-capacity lock-free ring buffer for single-producer/single-consumer use. */
ds_ring_t *ds_ring_create(size_t capacity);
void       ds_ring_destroy(ds_ring_t **self);
size_t     ds_ring_capacity(const ds_ring_t *r);
size_t     ds_ring_size(const ds_ring_t *r);
int        ds_ring_write(ds_ring_t *r, void *item);   /* returns 0 on success, -1 if full */
void      *ds_ring_read(ds_ring_t *r);                /* returns NULL if empty */
int        ds_ring_is_full(const ds_ring_t *r);
int        ds_ring_is_empty(const ds_ring_t *r);
void       ds_ring_clear(ds_ring_t *r);

#endif /* LIBDS_RING_BUFFER_H */
