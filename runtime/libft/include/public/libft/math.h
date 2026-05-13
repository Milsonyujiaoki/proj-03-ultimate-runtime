#ifndef LIBFT_MATH_H
#define LIBFT_MATH_H

#include <stdint.h>

/** @brief Returns the absolute value of @p n. Undefined for INT64_MIN. @note MT-SAFE/re */
int64_t ft_abs(int64_t n);

/** @brief Returns the minimum of @p a and @p b. @note MT-SAFE/re */
int64_t ft_min(int64_t a, int64_t b);

/** @brief Returns the maximum of @p a and @p b. @note MT-SAFE/re */
int64_t ft_max(int64_t a, int64_t b);

/**
 * @brief Computes @p base raised to the non-negative integer power @p exp.
 * @return Result; 1 if @p exp == 0. Overflow is undefined behaviour.
 * @note  MT-SAFE/re
 */
int64_t ft_pow(int64_t base, unsigned int exp);

/** @brief Clamps @p val to the inclusive range [@p lo, @p hi]. @note MT-SAFE/re */
int64_t ft_clamp(int64_t val, int64_t lo, int64_t hi);

#endif /* LIBFT_MATH_H */
