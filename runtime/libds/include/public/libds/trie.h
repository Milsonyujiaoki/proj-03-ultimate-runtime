#ifndef LIBDS_TRIE_H
#define LIBDS_TRIE_H

#include <stddef.h>

typedef struct ds_trie ds_trie_t;

ds_trie_t *ds_trie_create(void);
void       ds_trie_destroy(ds_trie_t **self);
int        ds_trie_insert(ds_trie_t *t, const char *key, void *value);
void      *ds_trie_search(const ds_trie_t *t, const char *key);
int        ds_trie_delete(ds_trie_t *t, const char *key);
int        ds_trie_starts_with(const ds_trie_t *t, const char *prefix);
size_t     ds_trie_prefix_count(const ds_trie_t *t, const char *prefix);
void       ds_trie_clear(ds_trie_t *t);

#endif /* LIBDS_TRIE_H */
