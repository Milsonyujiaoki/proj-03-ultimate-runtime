#ifndef LIBFT_INTERNAL_PLATFORM_H
# define LIBFT_INTERNAL_PLATFORM_H

/*
** =========================================================
** Platform detection
**
** Defines compile-time constants for OS, CPU arch, and
** pointer size.  Used internally by memory, allocators, and
** any code that needs architecture-specific behaviour.
** =========================================================
*/

/*
** ──── Operating system ─────────────────────────────────── */
# if defined(__linux__)
#  define LIBFT_PLATFORM_LINUX    1
# elif defined(__APPLE__) && defined(__MACH__)
#  define LIBFT_PLATFORM_MACOS    1
# elif defined(_WIN32) || defined(_WIN64)
#  define LIBFT_PLATFORM_WINDOWS  1
# else
#  define LIBFT_PLATFORM_UNKNOWN  1
# endif

/*
** ──── CPU architecture ─────────────────────────────────── */
# if defined(__x86_64__) || defined(_M_X64)
#  define LIBFT_ARCH_X86_64   1
# elif defined(__aarch64__) || defined(_M_ARM64)
#  define LIBFT_ARCH_ARM64    1
# elif defined(__i386__) || defined(_M_IX86)
#  define LIBFT_ARCH_X86_32   1
# elif defined(__riscv) && __riscv_xlen == 64
#  define LIBFT_ARCH_RISCV64  1
# else
#  define LIBFT_ARCH_UNKNOWN  1
# endif

/*
** ──── Pointer size ─────────────────────────────────────── */
# if defined(LIBFT_ARCH_X86_64) || defined(LIBFT_ARCH_ARM64) \
    || defined(LIBFT_ARCH_RISCV64)
#  define LIBFT_POINTER_SIZE  8
# else
#  define LIBFT_POINTER_SIZE  4
# endif

/*
** ──── Cache geometry ───────────────────────────────────── */

/* Typical L1 cache-line size in bytes (x86-64, ARM64). */
# define LIBFT_CACHE_LINE_SIZE   64

/* Page size in bytes (common default; use sysconf for runtime value). */
# define LIBFT_PAGE_SIZE         4096

/*
** ──── Byte order ───────────────────────────────────────── */
# if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__)
#  if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#   define LIBFT_LITTLE_ENDIAN 1
#  else
#   define LIBFT_BIG_ENDIAN    1
#  endif
# endif

#endif /* LIBFT_INTERNAL_PLATFORM_H */
