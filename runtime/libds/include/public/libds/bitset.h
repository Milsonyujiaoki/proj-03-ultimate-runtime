#ifndef LIBDS_BITSET_H
#define LIBDS_BITSET_H

#include <stddef.h>

typedef struct ds_bitset ds_bitset_t;

ds_bitset_t *ds_bitset_create(size_t num_bits);
void         ds_bitset_destroy(ds_bitset_t **self);
void         ds_bitset_set(ds_bitset_t *b, size_t pos);
void         ds_bitset_clear(ds_bitset_t *b, size_t pos);
void         ds_bitset_flip(ds_bitset_t *b, size_t pos);
int          ds_bitset_test(const ds_bitset_t *b, size_t pos);
size_t       ds_bitset_count(const ds_bitset_t *b);   /* popcount */
void         ds_bitset_and(ds_bitset_t *dst, const ds_bitset_t *src);
void         ds_bitset_or(ds_bitset_t *dst, const ds_bitset_t *src);
void         ds_bitset_xor(ds_bitset_t *dst, const ds_bitset_t *src);
void         ds_bitset_reset_all(ds_bitset_t *b);

#endif /* LIBDS_BITSET_H */
