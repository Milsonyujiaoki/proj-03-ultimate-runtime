#ifndef LIBDS_HASHSET_H
#define LIBDS_HASHSET_H

#include <stddef.h>
#include "libds/hashmap.h"

typedef struct ds_set ds_set_t;

ds_set_t *ds_set_create(size_t initial_buckets,
                         ds_hash_fn hash, ds_eq_fn eq);
void      ds_set_destroy(ds_set_t **self);
size_t    ds_set_size(const ds_set_t *s);
int       ds_set_add(ds_set_t *s, const void *key, size_t klen);
int       ds_set_contains(const ds_set_t *s, const void *key, size_t klen);
int       ds_set_remove(ds_set_t *s, const void *key, size_t klen);
void      ds_set_clear(ds_set_t *s);

#endif /* LIBDS_HASHSET_H */
