#ifndef LIBDS_KD_TREE_H
#define LIBDS_KD_TREE_H

#include <stddef.h>

typedef struct ds_kdtree ds_kdtree_t;

/**
 * @brief k-d Tree for k-dimensional point queries.
 * @param k   Number of dimensions.
 */
ds_kdtree_t *ds_kdtree_create(int k);
void         ds_kdtree_destroy(ds_kdtree_t **self);

/** @brief Insert a point (array of @p k doubles) with associated @p data. */
int          ds_kdtree_insert(ds_kdtree_t *t, const double *point, void *data);

/** @brief Find the nearest neighbour to @p query. Returns its @p data. */
void        *ds_kdtree_nearest(const ds_kdtree_t *t, const double *query);

/**
 * @brief Range query: calls @p fn for every point within @p radius of @p center.
 */
void         ds_kdtree_range(const ds_kdtree_t *t,
                              const double *center, double radius,
                              void (*fn)(const double *pt, void *data, void *ctx),
                              void *ctx);
void         ds_kdtree_clear(ds_kdtree_t *t);

#endif /* LIBDS_KD_TREE_H */
