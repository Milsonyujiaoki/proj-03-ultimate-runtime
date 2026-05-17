#ifndef LIBFT_ALGO_HASH_H
# define LIBFT_ALGO_HASH_H

# include "../core/types.h"

/*
** =========================================================
** Hash functions
**
** Algorithms provided:
**
**   FNV-1a 64-bit  — simple, fast, good avalanche; suitable for
**                    hashmaps.  Non-cryptographic.
**
**   DJB2           — classic, widely known string hash.
**                    Slightly worse distribution than FNV-1a.
**
**   MurmurHash3-32 — excellent distribution, bulk-hashing; best
**                    for large keys or when quality matters most.
**
** All are NON-CRYPTOGRAPHIC.  Do NOT use for security purposes.
** =========================================================
*/

/* FNV-1a 64-bit: hash data bytes of length size. */
t_u64   ft_hash_fnv1a(const void *data, t_usize size);

/* DJB2: hash a NUL-terminated string. */
t_u64   ft_hash_djb2(const char *str);

/* MurmurHash3 32-bit: hash data with an explicit seed. */
t_u32   ft_hash_murmur3_32(const void *data, t_usize size, t_u32 seed);

/*
** ──── Convenience wrappers ─────────────────────────────── */

/* Hash a NUL-terminated string (uses FNV-1a). */
t_u64   ft_hash_str(const char *str);

/* Hash arbitrary bytes (uses FNV-1a). */
t_u64   ft_hash_bytes(const void *data, t_usize size);

/* Bijective mix of a single 64-bit integer (splitmix64). */
t_u64   ft_hash_u64(t_u64 value);

#endif /* LIBFT_ALGO_HASH_H */
