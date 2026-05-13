# libft API Reference

## string.h

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Length of string (not counting NUL) |
| `ft_strcpy` | `char *ft_strcpy(char *dst, const char *src)` | Copy string (unsafe, prefer strlcpy) |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Safe copy; NUL-terminates |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Safe concat |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Heap-allocate a copy |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compare up to n bytes |
| `ft_strnstr` | `char *ft_strnstr(const char *h, const char *n, size_t len)` | Find needle in haystack |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | First occurrence of c |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Last occurrence of c |
| `ft_substr` | `char *ft_substr(const char *s, unsigned int start, size_t len)` | Allocate substring |
| `ft_strjoin` | `char *ft_strjoin(const char *s1, const char *s2)` | Allocate concatenation |
| `ft_strtrim` | `char *ft_strtrim(const char *s, const char *set)` | Trim chars in set |
| `ft_split` | `char **ft_split(const char *s, char c)` | Split by delimiter |

## memory.h

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_memset` | `void *ft_memset(void *b, int c, size_t n)` | Fill memory |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copy non-overlapping |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t n)` | Copy overlapping |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Find byte in memory |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compare memory |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Zero-fill |
| `ft_calloc` | `void *ft_calloc(size_t count, size_t size)` | Allocate zeroed memory |

## ctype.h

`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
— all match their POSIX equivalents.

## stdio.h

`ft_putchar_fd(char c, int fd)`, `ft_putstr_fd(char *s, int fd)`,
`ft_putendl_fd(char *s, int fd)`, `ft_putnbr_fd(int n, int fd)`

## stdlib.h

`ft_atoi(const char *nptr) → int`, `ft_itoa(int n) → char *` (heap-allocated)
