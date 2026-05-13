#ifndef LIBFT_ERRNO_H
#define LIBFT_ERRNO_H

/**
 * @brief Returns a human-readable description for the current @c errno value.
 *
 * This is a thin, re-entrant wrapper around strerror_r on POSIX and
 * strerror_s on Windows. Falls back to a generic message if the
 * platform provides neither.
 *
 * @return A pointer to a static or thread-local string — do NOT free it.
 * @note   MT-SAFE/re (uses thread-local storage on supported platforms)
 */
const char *ft_strerror(void);

/**
 * @brief Returns a human-readable description for error code @p errnum.
 * @note  MT-SAFE/re
 */
const char *ft_strerror_r(int errnum);

#endif /* LIBFT_ERRNO_H */
