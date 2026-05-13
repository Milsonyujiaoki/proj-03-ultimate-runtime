# ======================================
# Test files
# ======================================

STRING_TESTS = $(wildcard tests/string/*.c)
MEMORY_TESTS = $(wildcard tests/memory/*.c)
IO_TESTS = $(wildcard tests/io/*.c)
CONV_TESTS = $(wildcard tests/conversion/*.c)

TESTS = \
	$(STRING_TESTS) \
	$(MEMORY_TESTS) \
	$(IO_TESTS) \
	$(CONV_TESTS)

TEST_BINS = $(patsubst tests/%.c,$(TEST_DIR)/%,$(TESTS))

# ======================================
# Test target
# ======================================

test: $(LIB) $(TEST_BINS)
	@for test_bin in $(TEST_BINS); do \
		echo "Running $$test_bin"; \
		./$$test_bin; \
	done

# ======================================
# Test compilation
# ======================================

$(TEST_DIR)/%: tests/%.c $(LIB)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -lmini -o $@

.PHONY: test
