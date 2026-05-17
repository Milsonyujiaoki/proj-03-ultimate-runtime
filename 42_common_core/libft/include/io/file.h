#ifndef LIBFT_IO_FILE_H
# define LIBFT_IO_FILE_H

# include "../core/types.h"
# include "../core/defs.h"

/*
** =========================================================
** File / path utilities
**
** These functions use POSIX syscalls (open/read/write/close)
** through the sys/unistd wrappers.
** =========================================================
*/

/* Read entire file into a heap-allocated NUL-terminated buffer.
** *out_size (if non-NULL) is set to the file size in bytes.
** Returns NULL on error.  Caller must ft_free() the result. */
char        *ft_file_read_all(const char *path, t_usize *out_size);

/* Write data to path, creating or truncating the file.
** Returns bytes written, or FT_ERR on error. */
t_isize      ft_file_write_all(const char *path, const void *data,
                t_usize size);

/* Return the file size in bytes, or FT_ERR on error. */
t_isize      ft_file_size(const char *path);

/* Return true if path exists and is accessible. */
t_bool       ft_file_exists(const char *path);

#endif /* LIBFT_IO_FILE_H */
