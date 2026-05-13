cmake_minimum_required(VERSION 3.24)
project(libft VERSION 0.1.0 LANGUAGES C)

include(../../build_system/cmake/compiler_flags.cmake)
include(../../build_system/cmake/warnings.cmake)

# ── Source discovery ──────────────────────────────────────────────────────────
# Explicitly listed to avoid accidental inclusion of bonus/private files.
set(LIBFT_SOURCES
    src/string/ft_strlen.c
    src/string/ft_strcpy.c
    src/string/ft_strlcpy.c
    src/string/ft_strlcat.c
    src/string/ft_strdup.c
    src/string/ft_strncmp.c
    src/string/ft_strnstr.c
    src/string/ft_strchr.c
    src/string/ft_strrchr.c
    src/string/ft_substr.c
    src/string/ft_strjoin.c
    src/string/ft_strtrim.c
    src/string/ft_split.c
    src/memory/ft_memset.c
    src/memory/ft_memcpy.c
    src/memory/ft_memmove.c
    src/memory/ft_memchr.c
    src/memory/ft_memcmp.c
    src/memory/ft_bzero.c
    src/memory/ft_calloc.c
    src/ctype/ft_isalpha.c
    src/ctype/ft_isdigit.c
    src/ctype/ft_isalnum.c
    src/ctype/ft_isascii.c
    src/ctype/ft_isprint.c
    src/ctype/ft_toupper.c
    src/ctype/ft_tolower.c
    src/stdio/ft_putchar_fd.c
    src/stdio/ft_putstr_fd.c
    src/stdio/ft_putendl_fd.c
    src/stdio/ft_putnbr_fd.c
    src/stdlib/ft_atoi.c
    src/stdlib/ft_itoa.c
)

add_library(libft STATIC ${LIBFT_SOURCES})

set_target_properties(libft PROPERTIES
    OUTPUT_NAME ft
    C_STANDARD  17
    C_EXTENSIONS OFF
)

target_include_directories(libft
    PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public>
            $<INSTALL_INTERFACE:include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private
)

ur_set_compile_flags(libft)
ur_enable_warnings(libft PRIVATE)

# ── Install ───────────────────────────────────────────────────────────────────
include(GNUInstallDirs)
install(TARGETS libft
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY include/public/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ── Tests ─────────────────────────────────────────────────────────────────────
if(UR_BUILD_TESTS)
    include(../../build_system/cmake/testing.cmake)
    ur_setup_testing()
    add_subdirectory(tests)
endif()

# ── Benchmarks ────────────────────────────────────────────────────────────────
if(UR_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()
