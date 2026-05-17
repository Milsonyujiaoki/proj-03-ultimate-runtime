#ifndef LIBFT_CONFIG_H
# define LIBFT_CONFIG_H

/*
** =========================================================
** Library version
** =========================================================
*/
# define LIBFT_VERSION_MAJOR  0
# define LIBFT_VERSION_MINOR  3
# define LIBFT_VERSION_PATCH  0
# define LIBFT_VERSION_STR    "0.3.0"

/*
** =========================================================
** Feature flags
**
** Disable a module at compile time by defining LIBFT_NO_<MODULE>
** before including libft.h, or via -DLIBFT_NO_DS in CFLAGS.
** =========================================================
*/
# ifndef LIBFT_NO_DS
#  define LIBFT_FEATURE_DS      1
# endif

# ifndef LIBFT_NO_ALGO
#  define LIBFT_FEATURE_ALGO    1
# endif

# ifndef LIBFT_NO_ARENA
#  define LIBFT_FEATURE_ARENA   1
# endif

# ifndef LIBFT_NO_POOL
#  define LIBFT_FEATURE_POOL    1
# endif

/*
** =========================================================
** Allocator configuration
** =========================================================
*/

/* Default arena capacity: 4 MiB */
# ifndef LIBFT_ARENA_DEFAULT_CAPACITY
#  define LIBFT_ARENA_DEFAULT_CAPACITY  (4 * 1024 * 1024)
# endif

/* Arena alignment: must be a power of two */
# ifndef LIBFT_ARENA_DEFAULT_ALIGN
#  define LIBFT_ARENA_DEFAULT_ALIGN     16
# endif

/*
** =========================================================
** Vector / dynamic array configuration
** =========================================================
*/

/* Initial capacity when none is specified */
# ifndef LIBFT_VECTOR_INIT_CAPACITY
#  define LIBFT_VECTOR_INIT_CAPACITY    8
# endif

/* Growth factor applied on resize (integer multiplier) */
# ifndef LIBFT_VECTOR_GROW_FACTOR
#  define LIBFT_VECTOR_GROW_FACTOR      2
# endif

/*
** =========================================================
** String builder configuration
** =========================================================
*/
# ifndef LIBFT_SB_INIT_CAPACITY
#  define LIBFT_SB_INIT_CAPACITY        64
# endif

/*
** =========================================================
** Hashmap configuration (Phase 2)
** =========================================================
*/

/* Rehash threshold expressed as percentage of capacity */
# ifndef LIBFT_HASHMAP_LOAD_FACTOR
#  define LIBFT_HASHMAP_LOAD_FACTOR     75
# endif

# ifndef LIBFT_HASHMAP_INIT_BUCKETS
#  define LIBFT_HASHMAP_INIT_BUCKETS    16
# endif

#endif /* LIBFT_CONFIG_H */
