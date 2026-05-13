# libds API Reference

All containers share this lifecycle pattern:

```c
<T>_t *<T>_create(/* options */);
void    <T>_destroy(<T>_t **self);    /* NULLs *self */
size_t  <T>_size(const <T>_t *t);
void    <T>_clear(<T>_t *t);          /* removes elements, keeps allocation */
```

See individual header files for the complete per-structure API.

## Quick Index

| Structure         | Header                  | Key operations                            |
|-------------------|-------------------------|-------------------------------------------|
| Vector            | `libds/vector.h`        | push_back, pop_back, get, set, reserve    |
| Linked List       | `libds/linked_list.h`   | push_front, push_back, pop_front, remove  |
| Doubly LL         | `libds/doubly_linked_list.h` | insert_before, insert_after, remove   |
| Circular List     | `libds/circular_list.h` | rotate, peek                              |
| Stack             | `libds/stack.h`         | push, pop, peek                           |
| Queue             | `libds/queue.h`         | enqueue, dequeue, peek                    |
| Deque             | `libds/deque.h`         | push_front, push_back, pop_front, pop_back|
| Ring Buffer       | `libds/ring_buffer.h`   | write, read, is_full, is_empty            |
| HashMap           | `libds/hashmap.h`       | insert, get, remove, iter                 |
| HashSet           | `libds/hashset.h`       | add, contains, remove                     |
| BST               | `libds/bst.h`           | insert, search, delete, inorder           |
| AVL               | `libds/avl.h`           | insert (auto-balance), search, delete     |
| Red-Black Tree    | `libds/red_black_tree.h`| insert, search, delete (O(log n))         |
| B-Tree            | `libds/btree.h`         | insert, search, delete, split             |
| Trie              | `libds/trie.h`          | insert, search, delete, prefix_count      |
| Graph             | `libds/graph.h`         | add_vertex, add_edge, bfs, dfs            |
| Heap              | `libds/heap.h`          | push, pop, peek (min/max configurable)    |
| Priority Queue    | `libds/priority_queue.h`| enqueue, dequeue, peek                   |
| Bloom Filter      | `libds/bloom_filter.h`  | add, contains (probabilistic)             |
| Arena Allocator   | `libds/arena_allocator.h`| alloc, reset, destroy                    |
| Memory Pool       | `libds/memory_pool.h`   | acquire, release, destroy                 |
| Slab Allocator    | `libds/slab_allocator.h`| alloc, free, destroy                     |
| Rope              | `libds/rope.h`          | concat, split, index, to_str              |
| String Builder    | `libds/string_builder.h`| append, prepend, build                   |
| Bitset            | `libds/bitset.h`        | set, clear, test, count, and/or/xor       |
| Skiplist          | `libds/skiplist.h`      | insert, search, delete (O(log n) avg)     |
| LRU Cache         | `libds/lru_cache.h`     | put, get, evict                           |
| Radix Tree        | `libds/radix_tree.h`    | insert, search, delete, prefix_iter       |
| Interval Tree     | `libds/interval_tree.h` | insert, query (overlapping intervals)     |
| k-d Tree          | `libds/kd_tree.h`       | insert, nearest_neighbor, range_query     |
| Union-Find        | `libds/union_find.h`    | make_set, find, union (path compression)  |
