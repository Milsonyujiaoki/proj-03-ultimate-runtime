# libft

A complete reimplementation of the C standard library — built from scratch in C17 as part of the
42 School curriculum and extended for production use in `ultimate-runtime`.

## Modules

| Header           | Functions                                               |
|------------------|---------------------------------------------------------|
| `string.h`       | `ft_strlen`, `ft_strcpy`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`, `ft_strncmp`, `ft_strnstr`, `ft_strchr`, `ft_strrchr`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split` |
| `memory.h`       | `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_bzero`, `ft_calloc` |
| `ctype.h`        | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| `stdio.h`        | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| `stdlib.h`       | `ft_atoi`, `ft_itoa` |
| `unistd.h`       | `ft_write`, `ft_read` |
| `math.h`         | Integer power, abs, min, max helpers |
| `time.h`         | Monotonic clock wrappers |
| `errno.h`        | Error string helpers |
| `libft.h`        | Umbrella include |

## Quickstart

```sh
cd runtime/libft
make
# produces: libft.a
```

## CMake

```cmake
add_subdirectory(runtime/libft)
target_link_libraries(my_target PRIVATE libft)
```
