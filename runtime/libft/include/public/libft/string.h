#ifndef LIBFT_STRING_H
#define LIBFT_STRING_H

#include <stddef.h>

/**
 * @brief Returns the length of the null-terminated string @p s.
 * @note  MT-SAFE
 */
size_t  ft_strlen(const char *s);

/**
 * @brief Copies string @p src into @p dst (unsafe — no bounds check).
 * @return dst
 * @warning Prefer ft_strlcpy() to avoid buffer overflow.
 */
char   *ft_strcpy(char *dst, const char *src);

/**
 * @brief Copies up to @p size - 1 characters from @p src to @p dst.
 *        Always NUL-terminates if @p size > 0.
 * @return Total length of @p src (enables truncation detection).
 * @note  MT-SAFE
 */
size_t  ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends @p src to @p dst up to @p size - 1 total bytes.
 * @return Total desired length (strlen(dst) + strlen(src)).
 * @note  MT-SAFE
 */
size_t  ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Allocates a heap copy of @p s.
 * @return New string — caller must free() it. NULL on allocation failure.
 * @note  MT-SAFE
 */
char   *ft_strdup(const char *s);

/**
 * @brief Lexicographically compares up to @p n bytes of @p s1 and @p s2.
 * @note  MT-SAFE
 */
int     ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of @p needle in the first @p len bytes of @p haystack.
 * @return Pointer inside @p haystack, or NULL.
 * @note  MT-SAFE
 */
char   *ft_strnstr(const char *haystack, const char *needle, size_t len);

/** @brief First occurrence of character @p c in @p s. NULL if not found. */
char   *ft_strchr(const char *s, int c);

/** @brief Last occurrence of character @p c in @p s. NULL if not found. */
char   *ft_strrchr(const char *s, int c);

/**
 * @brief Allocates a substring of @p s starting at @p start with at most @p len characters.
 * @return New string — caller must free(). NULL on allocation failure.
 */
char   *ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Allocates a new string that is the concatenation of @p s1 and @p s2.
 * @return New string — caller must free(). NULL on allocation failure.
 */
char   *ft_strjoin(const char *s1, const char *s2);

/**
 * @brief Allocates a copy of @p s with leading/trailing characters in @p set removed.
 * @return New string — caller must free(). NULL on allocation failure.
 */
char   *ft_strtrim(const char *s, const char *set);

/**
 * @brief Splits @p s by delimiter @p c into a NULL-terminated array of strings.
 * @return Heap-allocated array — caller must free each element and the array.
 *         NULL on allocation failure.
 */
char  **ft_split(const char *s, char c);

#endif /* LIBFT_STRING_H */
