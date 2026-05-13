#ifndef LIBDS_SKIPLIST_H
#define LIBDS_SKIPLIST_H

#include <stddef.h>
#include "libds/bst.h"

typedef struct ds_skiplist ds_skiplist_t;

/**
 * @brief Skip list — O(log n) average insert/search/delete.
 * @param max_level  Maximum number of levels (16 is a good default).
 */
ds_skiplist_t *ds_skiplist_create(int max_level, ds_cmp_fn cmp);
void           ds_skiplist_destroy(ds_skiplist_t **self);
size_t         ds_skiplist_size(const ds_skiplist_t *s);
int            ds_skiplist_insert(ds_skiplist_t *s, void *data);
void          *ds_skiplist_search(const ds_skiplist_t *s, const void *key);
int            ds_skiplist_delete(ds_skiplist_t *s, const void *key);
void           ds_skiplist_clear(ds_skiplist_t *s);

#endif /* LIBDS_SKIPLIST_H */
