#ifndef LIBDS_GRAPH_H
#define LIBDS_GRAPH_H

#include <stddef.h>

typedef struct ds_graph ds_graph_t;

typedef enum {
    DS_GRAPH_DIRECTED   = 0,
    DS_GRAPH_UNDIRECTED = 1,
} ds_graph_type_e;

ds_graph_t *ds_graph_create(ds_graph_type_e type);
void        ds_graph_destroy(ds_graph_t **self);
int         ds_graph_add_vertex(ds_graph_t *g, int id, void *data);
int         ds_graph_add_edge(ds_graph_t *g, int from, int to, double weight);
int         ds_graph_remove_edge(ds_graph_t *g, int from, int to);
size_t      ds_graph_vertex_count(const ds_graph_t *g);
size_t      ds_graph_edge_count(const ds_graph_t *g);

/** @brief Breadth-first search from @p start. Calls @p fn for each visited vertex. */
void        ds_graph_bfs(ds_graph_t *g, int start,
                          void (*fn)(int id, void *data, void *ctx), void *ctx);

/** @brief Depth-first search from @p start. */
void        ds_graph_dfs(ds_graph_t *g, int start,
                          void (*fn)(int id, void *data, void *ctx), void *ctx);
void        ds_graph_clear(ds_graph_t *g);

#endif /* LIBDS_GRAPH_H */
