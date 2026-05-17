#ifndef STRING_H
# define STRING_H

# include <stddef.h>

/* String examination functions */

size_t ft_strlen(const char *str);

int  ft_strcmp(const char *lhs, const char *rhs);

int  ft_strncmp(const char *lhs, const char *rhs, size_t count);

char *ft_strchr(const char *str, int ch);

char *ft_strrchr(const char *str, int ch);

char *ft_strstr(const char *str, const char *substr);

char *ft_strtok(char *restrict str, const char *restrict delim);

/* String manipulation functions */

char *ft_strcpy(char *dest, const char *src);

char *ft_strcpy_fast(char *dest, const char *src);

/* Compatibility alias for the previous experimental name. */
char *ft_strcpy_v2(char *dest, const char *src);

char *ft_strncpy(char *dest, const char *src, size_t count);

size_t ft_strlcpy(char *dst, const char *src, size_t size);

char *ft_strdup(const char *src);

char *ft_strndup(const char *src, size_t count);

char *ft_strcat(char *dest, const char *src);

size_t ft_strlcat(char *dst, const char *src, size_t size);

char *ft_strncat(char *dest, const char *src, size_t count);

/* Additional functions */

char *ft_substr(const char *str, unsigned int start, size_t len);

char *ft_strjoin(const char *s1, const char *s2);

char *ft_strtrim(const char *str, const char *set);

char **ft_strsplit(const char *str, char delimiter);

char *ft_strmapi(const char *str, char (*f)(unsigned int, char));

void ft_striteri(char *str, void (*f)(unsigned int, char *));

#endif
