#ifndef LIBFT_TIME_H
#define LIBFT_TIME_H

#include <stdint.h>

/**
 * @brief Returns the current monotonic time in nanoseconds.
 *
 * Uses CLOCK_MONOTONIC on POSIX. Returns 0 on platforms where
 * the clock is unavailable.
 *
 * @note MT-SAFE
 */
uint64_t ft_time_ns(void);

/**
 * @brief Returns the current monotonic time in milliseconds.
 * @note MT-SAFE
 */
uint64_t ft_time_ms(void);

/**
 * @brief Returns elapsed nanoseconds between @p start and the current time.
 * @note  @p start should be obtained from ft_time_ns().
 */
uint64_t ft_elapsed_ns(uint64_t start);

#endif /* LIBFT_TIME_H */
