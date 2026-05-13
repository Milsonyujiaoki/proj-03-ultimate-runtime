#ifndef MINI_MEMORY_H
#define MINI_MEMORY_H

#include <stddef.h>

void *ft_memset( void *dest, int ch, size_t count );

void *ft_memcpy(void *dest, const void *src, size_t n);

void *ft_memccpy(void *dest, const void *src, int ch, size_t n);

void *ft_memmove(void *dest, const void *src, size_t n);

int ft_memcmp(const void *lhs, const void *rhs, size_t count);

void *ft_memchr(const void *ptr, int value, size_t num);

void *ft_bzero(void *ptr, size_t num);

#endif