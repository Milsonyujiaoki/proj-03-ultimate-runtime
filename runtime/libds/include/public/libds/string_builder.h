#ifndef LIBDS_STRING_BUILDER_H
#define LIBDS_STRING_BUILDER_H

#include <stddef.h>

typedef struct ds_sb ds_sb_t;

ds_sb_t *ds_sb_create(size_t initial_cap);
void     ds_sb_destroy(ds_sb_t **self);
int      ds_sb_append(ds_sb_t *sb, const char *s);
int      ds_sb_append_n(ds_sb_t *sb, const char *s, size_t n);
int      ds_sb_append_char(ds_sb_t *sb, char c);
int      ds_sb_prepend(ds_sb_t *sb, const char *s);
size_t   ds_sb_length(const ds_sb_t *sb);

/** @brief Returns heap-allocated NUL-terminated string. Caller must free(). */
char    *ds_sb_build(const ds_sb_t *sb);

/** @brief Resets the builder to empty (keeps allocation). */
void     ds_sb_clear(ds_sb_t *sb);

#endif /* LIBDS_STRING_BUILDER_H */
