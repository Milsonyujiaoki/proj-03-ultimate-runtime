# compiler_flags.cmake — Compiler optimization flags and C/C++ standards
# Included by the root CMakeLists.txt
# Sets global defaults; individual targets can override with target_compile_options().

include_guard(GLOBAL)

# ── Standards ─────────────────────────────────────────────────────────────────
set(CMAKE_C_STANDARD          17  CACHE STRING "C standard")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD        20  CACHE STRING "C++ standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS      OFF)

# ── Default build type ────────────────────────────────────────────────────────
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    Debug Release RelWithDebInfo MinSizeRel)
endif()

# ── Per-configuration flags ───────────────────────────────────────────────────
# Applied globally via add_compile_options; targets inherit automatically.
add_compile_options(
  $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<CONFIG:Debug>>:
    -O0;-g3;-fno-omit-frame-pointer>
  $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<CONFIG:Release>>:
    -O3;-DNDEBUG;-march=native;-fno-plt>
  $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<CONFIG:RelWithDebInfo>>:
    -O2;-g;-DNDEBUG;-fno-omit-frame-pointer>
  $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<CONFIG:MinSizeRel>>:
    -Os;-DNDEBUG>
  $<$<CXX_COMPILER_ID:MSVC>:
    /O2;/Oi;/GL;/DNDEBUG>
)

# ── LTO (Release only) ────────────────────────────────────────────────────────
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  include(CheckIPOSupported)
  check_ipo_supported(RESULT _ipo_supported OUTPUT _ipo_error)
  if(_ipo_supported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
  endif()
endif()

# ── Position-independent code ─────────────────────────────────────────────────
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ── Compile commands ──────────────────────────────────────────────────────────
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ── Helper function ───────────────────────────────────────────────────────────
# Usage: ur_set_compile_flags(target [PRIVATE|PUBLIC|INTERFACE])
function(ur_set_compile_flags TARGET VISIBILITY)
  target_compile_options(${TARGET} ${VISIBILITY}
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:
      -fno-strict-aliasing>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:
      -fcolor-diagnostics>
    $<$<CXX_COMPILER_ID:GNU>:
      -fdiagnostics-color=always>
  )
endfunction()
