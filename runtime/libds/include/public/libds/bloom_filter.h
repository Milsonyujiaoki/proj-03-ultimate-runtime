#ifndef LIBDS_BLOOM_FILTER_H
#define LIBDS_BLOOM_FILTER_H

#include <stddef.h>

typedef struct ds_bloom ds_bloom_t;

/**
 * @brief Probabilistic set membership test.
 *        False positives possible; false negatives are impossible.
 *
 * @param bit_count   Number of bits in the filter (larger = lower FPR).
 * @param hash_count  Number of independent hash functions.
 */
ds_bloom_t *ds_bloom_create(size_t bit_count, size_t hash_count);
void        ds_bloom_destroy(ds_bloom_t **self);
void        ds_bloom_add(ds_bloom_t *b, const void *data, size_t len);
int         ds_bloom_contains(const ds_bloom_t *b, const void *data, size_t len);
void        ds_bloom_clear(ds_bloom_t *b);

/** @brief Estimated false positive rate given @p n inserted elements. */
double      ds_bloom_fpr(const ds_bloom_t *b, size_t n);

#endif /* LIBDS_BLOOM_FILTER_H */
