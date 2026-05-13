#ifndef LIBDS_INTERVAL_TREE_H
#define LIBDS_INTERVAL_TREE_H

#include <stddef.h>

typedef struct {
    double low;
    double high;
} ds_interval_t;

typedef struct ds_itree ds_itree_t;

ds_itree_t *ds_itree_create(void);
void        ds_itree_destroy(ds_itree_t **self);
int         ds_itree_insert(ds_itree_t *t, ds_interval_t interval, void *data);
int         ds_itree_delete(ds_itree_t *t, ds_interval_t interval);

/**
 * @brief Query all intervals that overlap with @p query.
 *        Calls @p fn for each match.
 */
void        ds_itree_query(const ds_itree_t *t, ds_interval_t query,
                            void (*fn)(ds_interval_t iv, void *data, void *ctx),
                            void *ctx);
void        ds_itree_clear(ds_itree_t *t);

#endif /* LIBDS_INTERVAL_TREE_H */
