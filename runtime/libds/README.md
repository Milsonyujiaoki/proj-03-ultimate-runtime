# libds — Data Structures

A comprehensive, header-documented data-structure library in C17.

## Available Structures

| Category       | Headers                                                          |
|----------------|------------------------------------------------------------------|
| Linear         | `vector`, `linked_list`, `doubly_linked_list`, `circular_list`  |
| Stack / Queue  | `stack`, `queue`, `deque`, `ring_buffer`                        |
| Hash           | `hashmap`, `hashset`                                            |
| Trees          | `bst`, `avl`, `red_black_tree`, `btree`, `trie`, `radix_tree`, `interval_tree`, `kd_tree` |
| Heap           | `heap`, `priority_queue`                                        |
| Graph          | `graph`                                                         |
| Probabilistic  | `bloom_filter`, `skiplist`                                      |
| Allocators     | `arena_allocator`, `memory_pool`, `slab_allocator`              |
| Strings        | `rope`, `string_builder`                                        |
| Bits / Sets    | `bitset`, `union_find`                                          |
| Cache          | `lru_cache`                                                     |

## Quickstart

```sh
cd runtime/libds
make
# produces: libds.a
```

## CMake

```cmake
add_subdirectory(runtime/libds)
target_link_libraries(my_target PRIVATE libds)
```
