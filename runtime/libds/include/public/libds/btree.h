#ifndef LIBDS_BTREE_H
#define LIBDS_BTREE_H

#include <stddef.h>
#include "libds/bst.h"

typedef struct ds_btree ds_btree_t;

/**
 * @brief B-Tree of order @p order (minimum degree).
 *        All keys in sorted order; O(log n) operations.
 */
ds_btree_t *ds_btree_create(int order, ds_cmp_fn cmp);
void        ds_btree_destroy(ds_btree_t **self);
size_t      ds_btree_size(const ds_btree_t *t);
int         ds_btree_insert(ds_btree_t *t, void *data);
void       *ds_btree_search(const ds_btree_t *t, const void *key);
int         ds_btree_delete(ds_btree_t *t, const void *key);
void        ds_btree_clear(ds_btree_t *t);

#endif /* LIBDS_BTREE_H */
