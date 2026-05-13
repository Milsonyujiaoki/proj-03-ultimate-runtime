#ifndef LIBDS_HASHMAP_H
#define LIBDS_HASHMAP_H

#include <stddef.h>

typedef struct ds_map ds_map_t;

/** @brief Hash function type: maps key to bucket index. */
typedef size_t (*ds_hash_fn)(const void *key, size_t key_len);

/** @brief Key equality function. */
typedef int    (*ds_eq_fn)(const void *a, const void *b, size_t len);

ds_map_t  *ds_map_create(size_t initial_buckets,
                          ds_hash_fn hash, ds_eq_fn eq);
void       ds_map_destroy(ds_map_t **self);
size_t     ds_map_size(const ds_map_t *m);
int        ds_map_insert(ds_map_t *m, const void *key, size_t klen, void *value);
void      *ds_map_get(const ds_map_t *m, const void *key, size_t klen);
int        ds_map_remove(ds_map_t *m, const void *key, size_t klen);
int        ds_map_contains(const ds_map_t *m, const void *key, size_t klen);

/** @brief Iterate: calls @p fn(key, klen, value, ctx) for every entry. */
void       ds_map_foreach(const ds_map_t *m,
                           void (*fn)(const void *k, size_t klen,
                                      void *v, void *ctx),
                           void *ctx);
void       ds_map_clear(ds_map_t *m);

/* Convenience helpers for C-string keys */
int        ds_map_set_str(ds_map_t *m, const char *key, void *value);
void      *ds_map_get_str(const ds_map_t *m, const char *key);

#endif /* LIBDS_HASHMAP_H */
