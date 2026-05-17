
#include "algo/hash.h"

/*
** =========================================================
** Hash functions — implementation
** =========================================================
*/

/*
** FNV-1a 64-bit
**
** Fast, simple, good avalanche for short keys.
** Reference: http://www.isthe.com/chongo/tech/comp/fnv/
*/
t_u64   ft_hash_fnv1a(const void *data, t_usize size)
{
    const t_byte    *p;
    t_u64            hash;
    t_usize          i;

    hash = 14695981039346656037ULL;   /* FNV offset basis */
    p = (const t_byte *)data;
    i = 0;
    while (i < size)
    {
        hash ^= (t_u64)p[i];
        hash *= 1099511628211ULL;     /* FNV prime */
        i++;
    }
    return (hash);
}

/*
** DJB2
**
** Classic string hash attributed to Dan Bernstein.
*/
t_u64   ft_hash_djb2(const char *str)
{
    t_u64   hash;

    hash = 5381;
    while (*str)
    {
        hash = ((hash << 5) + hash) + (t_u8)*str;
        str++;
    }
    return (hash);
}

/*
** MurmurHash3 (32-bit, simplified)
**
** High-quality bulk hasher; excellent for long keys.
** Original by Austin Appleby; placed in public domain.
*/
t_u32   ft_hash_murmur3_32(const void *data, t_usize size, t_u32 seed)
{
    const t_u8  *key;
    t_u32        h;
    t_usize      nblocks;
    t_usize      i;
    t_u32        k;

    key = (const t_u8 *)data;
    h = seed;
    nblocks = size / 4;
    i = 0;
    while (i < nblocks)
    {
        k  = (t_u32)key[i * 4 + 0];
        k |= (t_u32)key[i * 4 + 1] << 8;
        k |= (t_u32)key[i * 4 + 2] << 16;
        k |= (t_u32)key[i * 4 + 3] << 24;
        k *= 0xcc9e2d51;
        k  = (k << 15) | (k >> 17);
        k *= 0x1b873593;
        h ^= k;
        h  = (h << 13) | (h >> 19);
        h  = h * 5 + 0xe6546b64;
        i++;
    }
    /* Tail */
    key += nblocks * 4;
    k = 0;
    switch (size & 3)
    {
        case 3: k ^= (t_u32)key[2] << 16; /* fall through */
        case 2: k ^= (t_u32)key[1] << 8;  /* fall through */
        case 1: k ^= (t_u32)key[0];
                k *= 0xcc9e2d51;
                k  = (k << 15) | (k >> 17);
                k *= 0x1b873593;
                h ^= k;
                break;
        default: break;
    }
    /* Finalisation mix — forces avalanche */
    h ^= (t_u32)size;
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return (h);
}

/* ── Convenience wrappers ────────────────────────────── */

t_u64   ft_hash_str(const char *str)
{
    t_usize len;

    len = 0;
    while (str[len])
        len++;
    return (ft_hash_fnv1a(str, len));
}

t_u64   ft_hash_bytes(const void *data, t_usize size)
{
    return (ft_hash_fnv1a(data, size));
}

/*
** splitmix64 — bijective 64-bit integer mixer.
** Suitable for integer keys in hash tables.
*/
t_u64   ft_hash_u64(t_u64 value)
{
    value += 0x9e3779b97f4a7c15ULL;
    value  = (value ^ (value >> 30)) * 0xbf58476d1ce4e5b9ULL;
    value  = (value ^ (value >> 27)) * 0x94d049bb133111ebULL;
    return (value ^ (value >> 31));
}
