# dependencies.cmake — External dependency management
# Supports: FetchContent (default), Conan 2, vcpkg

include_guard(GLOBAL)

include(FetchContent)

# ── Strategy selection ────────────────────────────────────────────────────────
set(UR_DEP_STRATEGY "fetchcontent" CACHE STRING
  "Dependency strategy: fetchcontent | conan | vcpkg")
set_property(CACHE UR_DEP_STRATEGY PROPERTY STRINGS fetchcontent conan vcpkg)

message(STATUS "[Deps] Strategy: ${UR_DEP_STRATEGY}")

# ── FetchContent helpers ──────────────────────────────────────────────────────

macro(ur_fetch NAME GIT_REPO GIT_TAG)
  if(NOT TARGET ${NAME})
    FetchContent_Declare(${NAME}
      GIT_REPOSITORY ${GIT_REPO}
      GIT_TAG        ${GIT_TAG}
      GIT_SHALLOW    TRUE
    )
    FetchContent_MakeAvailable(${NAME})
    message(STATUS "[Deps] Fetched: ${NAME} @ ${GIT_TAG}")
  endif()
endmacro()

# ── Optional dependencies (fetch on demand) ───────────────────────────────────

# GoogleTest (fetched by testing.cmake, not here)

# google/benchmark
macro(ur_require_benchmark)
  if(UR_BUILD_BENCHMARKS AND NOT TARGET benchmark::benchmark)
    set(BENCHMARK_ENABLE_TESTING  OFF CACHE BOOL "" FORCE)
    set(BENCHMARK_ENABLE_INSTALL  OFF CACHE BOOL "" FORCE)
    ur_fetch(benchmark
      "https://github.com/google/benchmark.git"
      "v1.8.4"
    )
  endif()
endmacro()

# fmtlib
macro(ur_require_fmt)
  if(NOT TARGET fmt::fmt)
    ur_fetch(fmt
      "https://github.com/fmtlib/fmt.git"
      "10.2.1"
    )
  endif()
endmacro()

# spdlog
macro(ur_require_spdlog)
  if(NOT TARGET spdlog::spdlog)
    ur_fetch(spdlog
      "https://github.com/gabime/spdlog.git"
      "v1.13.0"
    )
  endif()
endmacro()

# ── Conan 2 hook ──────────────────────────────────────────────────────────────
if(UR_DEP_STRATEGY STREQUAL "conan")
  if(EXISTS "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
    include("${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
    message(STATUS "[Deps] Conan toolchain loaded")
  else()
    message(WARNING "[Deps] Conan strategy selected but conan_toolchain.cmake not found.\n"
                    "Run: conan install . --build=missing -s build_type=${CMAKE_BUILD_TYPE}")
  endif()
endif()

# ── vcpkg hook ────────────────────────────────────────────────────────────────
if(UR_DEP_STRATEGY STREQUAL "vcpkg")
  if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE
      "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "vcpkg toolchain")
    message(STATUS "[Deps] vcpkg toolchain: ${CMAKE_TOOLCHAIN_FILE}")
  else()
    message(WARNING "[Deps] vcpkg strategy selected but VCPKG_ROOT is not set.")
  endif()
endif()
