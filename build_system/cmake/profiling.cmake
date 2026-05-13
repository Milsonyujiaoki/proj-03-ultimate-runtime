# profiling.cmake — Profiling instrumentation helpers

include_guard(GLOBAL)

option(UR_ENABLE_GPROF   "Enable gprof profiling (-pg)"         OFF)
option(UR_ENABLE_PERF    "Enable perf-compatible frame pointers" OFF)
option(UR_ENABLE_TRACY   "Enable Tracy profiler integration"     OFF)

# ── gprof ─────────────────────────────────────────────────────────────────────
if(UR_ENABLE_GPROF)
  message(STATUS "[Profiling] gprof: ON")
  add_compile_options(-pg)
  add_link_options(-pg)
endif()

# ── perf / flamegraph ─────────────────────────────────────────────────────────
if(UR_ENABLE_PERF)
  message(STATUS "[Profiling] perf frame-pointers: ON")
  add_compile_options(-fno-omit-frame-pointer -fno-inline-functions)
endif()

# ── Tracy ─────────────────────────────────────────────────────────────────────
if(UR_ENABLE_TRACY)
  message(STATUS "[Profiling] Tracy: ON")
  find_path(TRACY_INCLUDE_DIR Tracy.hpp
    PATHS "${CMAKE_SOURCE_DIR}/third_party/tracy/public"
    NO_DEFAULT_PATH)
  if(TRACY_INCLUDE_DIR)
    add_compile_definitions(TRACY_ENABLE)
    include_directories(${TRACY_INCLUDE_DIR})
  else()
    message(WARNING "Tracy header not found. Add it to third_party/tracy/.")
  endif()
endif()

# ── Per-target helper ─────────────────────────────────────────────────────────
# Usage: ur_enable_profiling(<target> [GPROF] [PERF] [TRACY])
function(ur_enable_profiling TARGET)
  cmake_parse_arguments(ARG "GPROF;PERF;TRACY" "VISIBILITY" "" ${ARGN})
  set(VIS ${ARG_VISIBILITY})
  if(NOT VIS)
    set(VIS PRIVATE)
  endif()

  if(ARG_GPROF)
    target_compile_options(${TARGET} ${VIS} -pg)
    target_link_options(${TARGET}    ${VIS} -pg)
  endif()

  if(ARG_PERF)
    target_compile_options(${TARGET} ${VIS} -fno-omit-frame-pointer)
  endif()

  if(ARG_TRACY AND TRACY_INCLUDE_DIR)
    target_compile_definitions(${TARGET} ${VIS} TRACY_ENABLE)
    target_include_directories(${TARGET} ${VIS} ${TRACY_INCLUDE_DIR})
  endif()
endfunction()
