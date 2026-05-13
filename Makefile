# =============================================================================
# Makefile — ultimate-runtime Monorepo Wrapper
# =============================================================================
# Thin wrapper around CMake presets for convenience.
# Usage: make <target> [PRESET=debug|release|asan|tsan|fuzz]
# =============================================================================

PRESET    ?= debug
BUILD_DIR  = build/$(PRESET)
JOBS      ?= $(shell nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

.PHONY: all build test fmt lint clean fuzz bench docs help

# ── Default ───────────────────────────────────────────────────────────────────
all: build

# ── Configure + Build ─────────────────────────────────────────────────────────
configure:
	cmake --preset $(PRESET)

build: configure
	cmake --build $(BUILD_DIR) --parallel $(JOBS)

# ── Testing ───────────────────────────────────────────────────────────────────
test: build
	ctest --test-dir $(BUILD_DIR) --output-on-failure --parallel $(JOBS)

test-asan:
	$(MAKE) build PRESET=asan
	ctest --test-dir build/asan --output-on-failure --parallel $(JOBS)

test-tsan:
	$(MAKE) build PRESET=tsan
	ctest --test-dir build/tsan --output-on-failure --parallel $(JOBS)

# ── Formatting & Linting ──────────────────────────────────────────────────────
fmt:
	bash scripts/formatting/format.sh

lint:
	bash scripts/formatting/lint.sh

# ── Fuzzing ───────────────────────────────────────────────────────────────────
fuzz:
	$(MAKE) build PRESET=fuzz
	bash scripts/fuzzing/run_fuzz.sh

# ── Benchmarks ────────────────────────────────────────────────────────────────
bench:
	$(MAKE) build PRESET=release
	bash scripts/benchmarking/run_bench.sh

# ── Documentation ─────────────────────────────────────────────────────────────
docs:
	bash scripts/ci/generate_docs.sh

# ── Profiling ─────────────────────────────────────────────────────────────────
profile:
	$(MAKE) build PRESET=release
	bash scripts/profiling/run_profile.sh

# ── Clean ─────────────────────────────────────────────────────────────────────
clean:
	rm -rf build/

clean-preset:
	rm -rf $(BUILD_DIR)

# ── Scaffolding ───────────────────────────────────────────────────────────────
scaffold:
	python3 create_structure.py --verbose

scaffold-dry:
	python3 create_structure.py --dry-run

# ── Help ──────────────────────────────────────────────────────────────────────
help:
	@echo ""
	@echo "  ultimate-runtime — Makefile targets"
	@echo ""
	@echo "  make build        Build with current PRESET (default: debug)"
	@echo "  make test         Run CTest suite"
	@echo "  make test-asan    Build + test with AddressSanitizer"
	@echo "  make test-tsan    Build + test with ThreadSanitizer"
	@echo "  make fmt          Format all C/C++ sources (clang-format)"
	@echo "  make lint         Run clang-tidy static analysis"
	@echo "  make fuzz         Build fuzz preset + run fuzz targets"
	@echo "  make bench        Build release + run benchmarks"
	@echo "  make docs         Generate Doxygen documentation"
	@echo "  make profile      Build release + run profiling session"
	@echo "  make clean        Remove all build directories"
	@echo "  make scaffold     Regenerate directory structure"
	@echo ""
	@echo "  PRESET=debug|release|asan|tsan|fuzz  (default: debug)"
	@echo "  JOBS=N  Parallel build jobs           (default: nproc)"
	@echo ""
