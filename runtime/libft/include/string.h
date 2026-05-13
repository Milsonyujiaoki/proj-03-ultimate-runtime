#ifndef MINI_STRING_H
#define MINI_STRING_H

#include <stddef.h>

size_t ft_strlen(const char *str);

char *ft_strcpy(char *dest, const char *src);

char *ft_strcpy_v2(char *dest, const char *src);

char *ft_strncpy(char *dest, const char *src, size_t count);

char *ft_strdup(const char *src);

char *ft_strndup(const char *src, size_t count);

char *ft_strcat(char *dest, const char *src);

char *ft_strncat(char *dest, const char *src, size_t count);

int  ft_strcmp(const char *lhs, const char *rhs);

int  ft_strncmp(const char *lhs, const char *rhs, size_t count);

char *ft_strchr(const char* str, int ch);

char *ft_strrchr(const char* str, int ch);

char *ft_strstr(const char *str, const char* substr);

char *ft_strtok( char* restrict str, const char* restrict delim );


#endif
