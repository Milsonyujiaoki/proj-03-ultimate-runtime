#ifndef LIBFT_DEFS_H
# define LIBFT_DEFS_H

# include "types.h"

/*
** =========================================================
** Common status / result codes
**
** Convention:
**   FT_OK   (0)  — success
**   FT_ERR  (-1) — generic failure (check errno for details)
**   FT_E*   (<0) — specific error
**
** A function returning t_ft_status MUST document which
** codes it can produce.
** =========================================================
*/
typedef enum e_ft_status
{
    FT_OK        =  0,   /* success                         */
    FT_ERR       = -1,   /* generic error                   */
    FT_ENOMEM    = -2,   /* allocation failure              */
    FT_EINVAL    = -3,   /* invalid argument                */
    FT_ERANGE    = -4,   /* value out of range              */
    FT_ENOTFOUND = -5,   /* element not found               */
    FT_EEXIST    = -6,   /* element already exists          */
    FT_EEMPTY    = -7,   /* container is empty              */
    FT_EFULL     = -8,   /* container is full               */
    FT_EOVERFLOW = -9,   /* arithmetic or buffer overflow   */
}   t_ft_status;

/*
** =========================================================
** Generic callback / function-pointer typedefs
** =========================================================
*/

/*
** Comparison function.
** Returns: < 0 if a < b, == 0 if a == b, > 0 if a > b.
** Used by: sort, search, hashmap, tree.
*/
typedef int     (*t_cmp_fn)(const void *a, const void *b);

/*
** Visitor / iterator callback.
** elem  — pointer to the current element
** ctx   — caller-supplied context (may be NULL)
*/
typedef void    (*t_visit_fn)(void *elem, void *ctx);

/*
** Predicate function.
** Returns true when elem satisfies the condition.
*/
typedef t_bool  (*t_pred_fn)(const void *elem, const void *ctx);

/*
** Destructor / element free callback.
** Called by *_destroy_deep() variants.
*/
typedef void    (*t_free_fn)(void *elem);

/*
** Hash function.
** Returns a 64-bit hash of key_size bytes starting at key.
*/
typedef t_u64   (*t_hash_fn)(const void *key, t_usize key_size);

/*
** Map / transform callback.
** Returns a newly created element derived from elem.
** Ownership of the returned pointer is transferred to the caller.
*/
typedef void   *(*t_map_fn)(const void *elem, void *ctx);

#endif /* LIBFT_DEFS_H */
