# warnings.cmake — Compiler warning configuration
# Usage: ur_enable_warnings(<target> [PRIVATE|PUBLIC|INTERFACE])

include_guard(GLOBAL)

function(ur_enable_warnings TARGET)
  set(options "")
  set(one_value_args VISIBILITY)
  cmake_parse_arguments(ARG "${options}" "${one_value_args}" "" ${ARGN})
  set(VIS ${ARG_VISIBILITY})
  if(NOT VIS)
    set(VIS PRIVATE)
  endif()

  target_compile_options(${TARGET} ${VIS}
    # ── GCC / Clang ────────────────────────────────────────────────────────
    $<$<C_COMPILER_ID:GNU,Clang,AppleClang>:
      -Wall
      -Wextra
      -Wpedantic
      -Wshadow
      -Wcast-align
      -Wformat=2
      -Wformat-truncation
      -Wnull-dereference
      -Wdouble-promotion
      -Wimplicit-fallthrough
      -Wmissing-prototypes
      -Wstrict-prototypes
      -Wold-style-definition
      -Wvla
      -Wno-unused-parameter
    >
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:
      -Wall
      -Wextra
      -Wpedantic
      -Wshadow
      -Wcast-align
      -Wformat=2
      -Wnull-dereference
      -Wdouble-promotion
      -Wimplicit-fallthrough
      -Woverloaded-virtual
      -Wnon-virtual-dtor
      -Wold-style-cast
      -Wno-unused-parameter
    >
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:
      -Wdeprecated
      -Wmove
      -Wno-c++98-compat
    >
    $<$<CXX_COMPILER_ID:GNU>:
      -Wduplicated-cond
      -Wduplicated-branches
      -Wlogical-op
      -Wmisleading-indentation
    >
    # ── MSVC ───────────────────────────────────────────────────────────────
    $<$<CXX_COMPILER_ID:MSVC>:
      /W4
      /WX
      /permissive-
      /w14242
      /w14254
      /w14263
      /w14265
      /w14287
      /we4289
      /w14296
      /w14311
      /w14545
      /w14546
      /w14547
      /w14549
      /w14555
      /w14619
      /w14640
      /w14826
      /w14905
      /w14906
      /w14928
    >
  )
endfunction()
