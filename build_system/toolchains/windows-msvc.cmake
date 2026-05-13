# windows-msvc.cmake — MSVC toolchain for Windows

set(CMAKE_SYSTEM_NAME Windows)

# ── Compiler selection ────────────────────────────────────────────────────────
# CMake auto-detects MSVC; this file sets MSVC-specific options.
set(CMAKE_C_COMPILER   cl)
set(CMAKE_CXX_COMPILER cl)

# ── Unicode ───────────────────────────────────────────────────────────────────
add_compile_definitions(
  UNICODE
  _UNICODE
  WIN32_LEAN_AND_MEAN
  NOMINMAX
  _CRT_SECURE_NO_WARNINGS
)

# ── MSVC flags ────────────────────────────────────────────────────────────────
set(CMAKE_C_FLAGS_INIT   "/utf-8 /EHsc")
set(CMAKE_CXX_FLAGS_INIT "/utf-8 /EHsc")

# ── Static runtime linkage ────────────────────────────────────────────────────
foreach(flag_var
    CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
    CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
  string(REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
endforeach()

# ── Parallel compilation ──────────────────────────────────────────────────────
add_compile_options(/MP)

# ── Linker ────────────────────────────────────────────────────────────────────
set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>")
set(CMAKE_EXE_LINKER_FLAGS_INIT         "/INCREMENTAL:NO")
set(CMAKE_SHARED_LINKER_FLAGS_INIT      "/INCREMENTAL:NO")
