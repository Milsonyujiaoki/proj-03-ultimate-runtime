# testing.cmake — CTest and GoogleTest boilerplate
# Called by root CMakeLists when UR_BUILD_TESTS=ON

include_guard(GLOBAL)

# ── CTest ─────────────────────────────────────────────────────────────────────
function(ur_setup_testing)
  include(CTest)
  message(STATUS "[Testing] CTest: ON")
endfunction()

# ── GoogleTest (via FetchContent) ─────────────────────────────────────────────
option(UR_USE_GTEST "Fetch and use GoogleTest" ON)

macro(ur_fetch_gtest)
  if(UR_USE_GTEST AND NOT TARGET GTest::gtest)
    include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        v1.14.0
      GIT_SHALLOW    TRUE
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    message(STATUS "[Testing] GoogleTest 1.14.0 fetched")
  endif()
endmacro()

# ── Convenience: add a test executable ────────────────────────────────────────
# Usage:
#   ur_add_test(
#     NAME    my_test
#     SOURCES tests/my_test.cpp
#     LIBS    mylib
#   )
function(ur_add_test)
  cmake_parse_arguments(ARG "" "NAME" "SOURCES;LIBS;COMPILE_OPTIONS" ${ARGN})

  if(NOT ARG_NAME OR NOT ARG_SOURCES)
    message(FATAL_ERROR "ur_add_test: NAME and SOURCES are required")
  endif()

  ur_fetch_gtest()

  add_executable(${ARG_NAME} ${ARG_SOURCES})

  target_link_libraries(${ARG_NAME}
    PRIVATE
      GTest::gtest_main
      GTest::gmock
      ${ARG_LIBS}
  )

  if(ARG_COMPILE_OPTIONS)
    target_compile_options(${ARG_NAME} PRIVATE ${ARG_COMPILE_OPTIONS})
  endif()

  include(GoogleTest)
  gtest_discover_tests(${ARG_NAME}
    DISCOVERY_TIMEOUT 30
    PROPERTIES LABELS "unit"
  )
endfunction()

# ── Convenience: add a fuzz target (LibFuzzer) ────────────────────────────────
# Usage:
#   ur_add_fuzz_target(
#     NAME    my_fuzz
#     SOURCES fuzz/my_fuzz.cpp
#     LIBS    mylib
#   )
function(ur_add_fuzz_target)
  cmake_parse_arguments(ARG "" "NAME" "SOURCES;LIBS" ${ARGN})

  if(NOT ARG_NAME OR NOT ARG_SOURCES)
    message(FATAL_ERROR "ur_add_fuzz_target: NAME and SOURCES are required")
  endif()

  if(NOT CMAKE_C_COMPILER_ID MATCHES "Clang")
    message(WARNING "ur_add_fuzz_target: LibFuzzer requires Clang. Skipping ${ARG_NAME}.")
    return()
  endif()

  add_executable(${ARG_NAME} ${ARG_SOURCES})

  target_compile_options(${ARG_NAME} PRIVATE
    -fsanitize=fuzzer,address
    -fno-omit-frame-pointer
  )
  target_link_options(${ARG_NAME} PRIVATE
    -fsanitize=fuzzer,address
  )
  target_link_libraries(${ARG_NAME} PRIVATE ${ARG_LIBS})
endfunction()
