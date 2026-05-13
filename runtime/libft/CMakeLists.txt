cmake_minimum_required(VERSION 3.24)

project(libft
    VERSION 1.0.0
    DESCRIPTION "Educational C standard library implementation"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ============================================================================
# Library sources - auto-discover from src/
# ============================================================================
file(GLOB_RECURSE LIBFT_SOURCES "src/**/*.c")

if(NOT LIBFT_SOURCES)
    message(WARNING "No libft sources found in src/")
    set(LIBFT_SOURCES "src/_empty.c")
endif()

# ============================================================================
# Library target
# ============================================================================
add_library(libft STATIC ${LIBFT_SOURCES})

set_target_properties(libft PROPERTIES
    OUTPUT_NAME "ft"
    VERSION "${CMAKE_PROJECT_VERSION}"
    SOVERSION 1
)

# ============================================================================
# Include directories
# ============================================================================
target_include_directories(libft
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# ============================================================================
# Compiler flags
# ============================================================================
target_compile_options(libft PRIVATE
    -Wall
    -Wextra
    -Werror
    -Wpedantic
    -O2
    -fsanitize=address
)

target_link_options(libft PRIVATE
    -fsanitize=address
)

# ============================================================================
# Installation
# ============================================================================
include(GNUInstallDirs)

install(
    TARGETS libft
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ============================================================================
# Tests (if enabled and available)
# ============================================================================
if(ENABLE_TESTING AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
    add_subdirectory(tests)
endif()

# ============================================================================
# Benchmarks (if enabled and available)
# ============================================================================
if(ENABLE_BENCHMARKS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks/CMakeLists.txt")
    add_subdirectory(benchmarks)
endif()
