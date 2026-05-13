cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

# =============================================================================
# Project
# =============================================================================
project(
  ultimate-runtime
  VERSION 0.1.0
  DESCRIPTION "Professional C/C++ monorepo: runtimes, VMs, parsers, data structures"
  LANGUAGES C CXX
)

# =============================================================================
# CMake settings
# =============================================================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD   17 CACHE STRING "C standard")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build_system/cmake")

# =============================================================================
# Build system modules
# =============================================================================
include(compiler_flags)
include(warnings)
include(sanitizers)
include(dependencies)
include(testing)

# =============================================================================
# Options
# =============================================================================
option(UR_BUILD_TESTS      "Build test targets"           ON)
option(UR_BUILD_BENCHMARKS "Build benchmark targets"      OFF)
option(UR_BUILD_FUZZ       "Build fuzzing targets"        OFF)
option(UR_ENABLE_ASAN      "Enable AddressSanitizer"      OFF)
option(UR_ENABLE_TSAN      "Enable ThreadSanitizer"       OFF)
option(UR_ENABLE_UBSAN     "Enable UBSanitizer"           OFF)
option(UR_ENABLE_MSAN      "Enable MemorySanitizer"       OFF)

# =============================================================================
# Sanitizers
# =============================================================================
if(UR_ENABLE_ASAN OR UR_ENABLE_TSAN OR UR_ENABLE_UBSAN OR UR_ENABLE_MSAN)
  ur_enable_sanitizers()
endif()

# =============================================================================
# Testing
# =============================================================================
if(UR_BUILD_TESTS)
  enable_testing()
  ur_setup_testing()
endif()

# =============================================================================
# Subdirectories — ordered by dependency
# =============================================================================

# Foundation (zero external dependencies)
add_subdirectory(runtime/foundation   EXCLUDE_FROM_ALL)
add_subdirectory(runtime/coreutils   EXCLUDE_FROM_ALL)
add_subdirectory(runtime/platform    EXCLUDE_FROM_ALL)

# Core runtime
add_subdirectory(runtime/core        EXCLUDE_FROM_ALL)
add_subdirectory(runtime/vm          EXCLUDE_FROM_ALL)
add_subdirectory(runtime/services    EXCLUDE_FROM_ALL)

# Libraries
add_subdirectory(runtime/libft)
add_subdirectory(runtime/libds)
add_subdirectory(runtime/libalgo     EXCLUDE_FROM_ALL)
add_subdirectory(runtime/libparser   EXCLUDE_FROM_ALL)
add_subdirectory(runtime/libnet      EXCLUDE_FROM_ALL)
add_subdirectory(runtime/libai       EXCLUDE_FROM_ALL)
add_subdirectory(runtime/libgraphics EXCLUDE_FROM_ALL)
add_subdirectory(runtime/libdatabase EXCLUDE_FROM_ALL)
add_subdirectory(runtime/libsecurity EXCLUDE_FROM_ALL)

# =============================================================================
# Install rules
# =============================================================================
include(GNUInstallDirs)
include(packaging)
