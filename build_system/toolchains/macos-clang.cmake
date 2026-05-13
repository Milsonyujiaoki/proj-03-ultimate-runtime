# macos-clang.cmake — Apple Clang / LLVM Clang toolchain for macOS

set(CMAKE_SYSTEM_NAME Darwin)

# ── Prefer Homebrew LLVM over Apple Clang for sanitizer support ──────────────
find_program(BREW_CLANG   /opt/homebrew/opt/llvm/bin/clang   NO_DEFAULT_PATH)
find_program(BREW_CLANGXX /opt/homebrew/opt/llvm/bin/clang++ NO_DEFAULT_PATH)

if(BREW_CLANG AND BREW_CLANGXX)
  set(CMAKE_C_COMPILER   ${BREW_CLANG})
  set(CMAKE_CXX_COMPILER ${BREW_CLANGXX})
  message(STATUS "[Toolchain] Using Homebrew LLVM Clang")
else()
  # Fallback to Apple Clang
  set(CMAKE_C_COMPILER   clang)
  set(CMAKE_CXX_COMPILER clang++)
  message(STATUS "[Toolchain] Using Apple Clang")
endif()

# ── macOS SDK ─────────────────────────────────────────────────────────────────
execute_process(
  COMMAND xcrun --sdk macosx --show-sdk-path
  OUTPUT_VARIABLE MACOS_SDK_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)
if(MACOS_SDK_PATH)
  set(CMAKE_OSX_SYSROOT ${MACOS_SDK_PATH})
endif()

# ── Deployment target ─────────────────────────────────────────────────────────
set(CMAKE_OSX_DEPLOYMENT_TARGET "13.0" CACHE STRING "Minimum macOS version")

# ── Flags ─────────────────────────────────────────────────────────────────────
set(CMAKE_C_FLAGS_INIT   "-fcolor-diagnostics")
set(CMAKE_CXX_FLAGS_INIT "-fcolor-diagnostics")
