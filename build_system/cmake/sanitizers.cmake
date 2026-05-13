# sanitizers.cmake — Sanitizer configuration
# Controlled by UR_ENABLE_ASAN, UR_ENABLE_TSAN, UR_ENABLE_UBSAN, UR_ENABLE_MSAN

include_guard(GLOBAL)

function(ur_enable_sanitizers)
  if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(WARNING "sanitizers.cmake: Sanitizers not supported on MSVC. Skipping.")
    return()
  endif()

  set(_san_flags "")
  set(_san_link  "")

  if(UR_ENABLE_ASAN)
    list(APPEND _san_flags -fsanitize=address -fno-omit-frame-pointer)
    list(APPEND _san_link  -fsanitize=address)
    message(STATUS "[Sanitizers] AddressSanitizer: ON")
  endif()

  if(UR_ENABLE_TSAN)
    if(UR_ENABLE_ASAN)
      message(FATAL_ERROR "ASAN and TSAN cannot be enabled simultaneously.")
    endif()
    list(APPEND _san_flags -fsanitize=thread)
    list(APPEND _san_link  -fsanitize=thread)
    message(STATUS "[Sanitizers] ThreadSanitizer: ON")
  endif()

  if(UR_ENABLE_UBSAN)
    list(APPEND _san_flags
      -fsanitize=undefined
      -fsanitize=float-divide-by-zero
      -fsanitize=integer-divide-by-zero
      -fno-sanitize-recover=all)
    list(APPEND _san_link -fsanitize=undefined)
    message(STATUS "[Sanitizers] UBSanitizer: ON")
  endif()

  if(UR_ENABLE_MSAN)
    if(UR_ENABLE_ASAN OR UR_ENABLE_TSAN)
      message(FATAL_ERROR "MSAN cannot be combined with ASAN or TSAN.")
    endif()
    list(APPEND _san_flags -fsanitize=memory -fno-omit-frame-pointer)
    list(APPEND _san_link  -fsanitize=memory)
    message(STATUS "[Sanitizers] MemorySanitizer: ON")
  endif()

  if(_san_flags)
    add_compile_options(${_san_flags})
    add_link_options(${_san_link})
  endif()
endfunction()

# ── Per-target sanitizer helper ───────────────────────────────────────────────
# Usage: ur_target_sanitize(<target> ASAN|TSAN|UBSAN|MSAN [PRIVATE|PUBLIC])
function(ur_target_sanitize TARGET)
  cmake_parse_arguments(ARG "ASAN;TSAN;UBSAN;MSAN" "VISIBILITY" "" ${ARGN})
  set(VIS ${ARG_VISIBILITY})
  if(NOT VIS)
    set(VIS PRIVATE)
  endif()

  set(_flags "")
  if(ARG_ASAN)
    list(APPEND _flags -fsanitize=address -fno-omit-frame-pointer)
  endif()
  if(ARG_TSAN)
    list(APPEND _flags -fsanitize=thread)
  endif()
  if(ARG_UBSAN)
    list(APPEND _flags -fsanitize=undefined -fno-sanitize-recover=all)
  endif()
  if(ARG_MSAN)
    list(APPEND _flags -fsanitize=memory -fno-omit-frame-pointer)
  endif()

  if(_flags)
    target_compile_options(${TARGET} ${VIS} ${_flags})
    target_link_options(${TARGET}    ${VIS} ${_flags})
  endif()
endfunction()
