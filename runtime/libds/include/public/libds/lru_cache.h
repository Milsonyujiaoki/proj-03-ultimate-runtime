#ifndef LIBDS_LRU_CACHE_H
#define LIBDS_LRU_CACHE_H

#include <stddef.h>

typedef struct ds_lru ds_lru_t;

/** @brief LRU cache backed by a doubly-linked list + hash map. O(1) put/get. */
ds_lru_t *ds_lru_create(size_t capacity);
void      ds_lru_destroy(ds_lru_t **self);
int       ds_lru_put(ds_lru_t *c, const char *key, void *value);
void     *ds_lru_get(ds_lru_t *c, const char *key);  /* promotes to MRU */
int       ds_lru_contains(const ds_lru_t *c, const char *key);
int       ds_lru_remove(ds_lru_t *c, const char *key);
size_t    ds_lru_size(const ds_lru_t *c);
size_t    ds_lru_capacity(const ds_lru_t *c);
void      ds_lru_clear(ds_lru_t *c);

#endif /* LIBDS_LRU_CACHE_H */
