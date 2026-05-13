#ifndef LIBFT_MEMORY_H
#define LIBFT_MEMORY_H

#include <stddef.h>

/** @brief Fills the first @p n bytes of @p b with byte @p c. Returns @p b. @note MT-SAFE */
void  *ft_memset(void *b, int c, size_t n);

/** @brief Copies @p n bytes from @p src to @p dst (non-overlapping). Returns @p dst. */
void  *ft_memcpy(void *dst, const void *src, size_t n);

/** @brief Copies @p n bytes allowing overlap. Returns @p dst. @note MT-SAFE */
void  *ft_memmove(void *dst, const void *src, size_t n);

/** @brief Finds first occurrence of byte @p c in the first @p n bytes of @p s. */
void  *ft_memchr(const void *s, int c, size_t n);

/** @brief Compares first @p n bytes of @p s1 and @p s2. */
int    ft_memcmp(const void *s1, const void *s2, size_t n);

/** @brief Zeroes @p n bytes starting at @p s. @note MT-SAFE */
void   ft_bzero(void *s, size_t n);

/**
 * @brief Allocates @p count × @p size zero-initialised bytes.
 * @return Pointer to allocation, NULL on failure or overflow.
 * @note  MT-SAFE
 */
void  *ft_calloc(size_t count, size_t size);

#endif /* LIBFT_MEMORY_H */
