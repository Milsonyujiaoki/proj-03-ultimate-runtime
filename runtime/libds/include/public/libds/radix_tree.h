#ifndef LIBDS_RADIX_TREE_H
#define LIBDS_RADIX_TREE_H

#include <stddef.h>

typedef struct ds_radix ds_radix_t;

/** @brief Compressed trie (PATRICIA tree) for string keys. */
ds_radix_t *ds_radix_create(void);
void        ds_radix_destroy(ds_radix_t **self);
int         ds_radix_insert(ds_radix_t *t, const char *key, void *value);
void       *ds_radix_search(const ds_radix_t *t, const char *key);
int         ds_radix_delete(ds_radix_t *t, const char *key);

/** @brief Iterate all entries whose key starts with @p prefix. */
void        ds_radix_prefix_iter(const ds_radix_t *t, const char *prefix,
                                  void (*fn)(const char *k, void *v, void *ctx),
                                  void *ctx);
void        ds_radix_clear(ds_radix_t *t);

#endif /* LIBDS_RADIX_TREE_H */
