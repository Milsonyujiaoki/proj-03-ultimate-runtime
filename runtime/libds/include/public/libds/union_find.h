#ifndef LIBDS_UNION_FIND_H
#define LIBDS_UNION_FIND_H

#include <stddef.h>

typedef struct ds_uf ds_uf_t;

/**
 * @brief Union-Find (Disjoint Set Union) with path compression and union by rank.
 *        All operations are effectively O(α(n)) — amortised near O(1).
 *
 * @param n  Total number of elements (0 … n-1).
 */
ds_uf_t *ds_uf_create(size_t n);
void     ds_uf_destroy(ds_uf_t **self);

/** @brief Find the representative (root) of the set containing @p x. */
int      ds_uf_find(ds_uf_t *uf, int x);

/** @brief Merge the sets containing @p x and @p y. Returns 1 if merged, 0 if already same. */
int      ds_uf_union(ds_uf_t *uf, int x, int y);

/** @brief Returns 1 if @p x and @p y are in the same component. */
int      ds_uf_connected(ds_uf_t *uf, int x, int y);

/** @brief Number of distinct components. */
size_t   ds_uf_component_count(const ds_uf_t *uf);

void     ds_uf_reset(ds_uf_t *uf);

#endif /* LIBDS_UNION_FIND_H */
