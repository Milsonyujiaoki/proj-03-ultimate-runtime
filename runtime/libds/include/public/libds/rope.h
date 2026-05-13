#ifndef LIBDS_ROPE_H
#define LIBDS_ROPE_H

#include <stddef.h>

typedef struct ds_rope ds_rope_t;

/** @brief Rope — O(log n) concat, split, and index on large strings. */
ds_rope_t  *ds_rope_create(const char *s);
void        ds_rope_destroy(ds_rope_t **self);
size_t      ds_rope_length(const ds_rope_t *r);
char        ds_rope_at(const ds_rope_t *r, size_t index);
ds_rope_t  *ds_rope_concat(ds_rope_t *a, ds_rope_t *b);        /* consumes a and b */
ds_rope_t **ds_rope_split(ds_rope_t *r, size_t index);          /* returns [left, right] */
char       *ds_rope_to_str(const ds_rope_t *r);                 /* heap-allocated; caller frees */

#endif /* LIBDS_ROPE_H */
