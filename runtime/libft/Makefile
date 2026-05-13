CC = gcc

# Ajustado: Removidos níveis de otimização duplicados. Mantive -O2.
# Importante: O nome da lib deve bater com o -l. Se a lib é libft.a, usamos -lft.
CFLAGS = -Wall -Wextra -Werror -Wpedantic -O2 -fsanitize=address -std=c11 -Iinclude
LDFLAGS = -L$(BUILD_DIR) -lft

AR = ar
ARFLAGS = rcs

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TEST_DIR = $(BUILD_DIR)/tests

# Nome da biblioteca consistente
LIB = $(BUILD_DIR)/libft.a

# =========================
# Source files
# =========================

# Usando um padrão mais limpo para encontrar os subdiretórios
SRC = $(wildcard src/**/*.c)
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

# =========================
# Test files
# =========================

TESTS = $(wildcard tests/**/*.c)
# Isso transforma tests/string/test_strlen.c em build/tests/string/test_strlen
TEST_BINS = $(patsubst tests/%.c,$(TEST_DIR)/%,$(TESTS))

# =========================
# Main targets
# =========================

# Adicionado $(TEST_BINS) ao 'all' conforme solicitado
all: $(LIB) $(TEST_BINS)

test: all
	@echo "Estrutura de testes encontrada: $(TEST_BINS)"
	@for test_bin in $(TEST_BINS); do \
		if [ -f $$test_bin ]; then \
			echo "Running $$test_bin"; \
			./$$test_bin; \
		fi \
	done

# =========================
# Library
# =========================

$(LIB): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(AR) $(ARFLAGS) $@ $^

# =========================
# Object compilation
# =========================

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Test compilation
# =========================

# Aqui está a correção do link: usamos $(LIB) como dependência 
# e garantimos que o binário saia na pasta correta.
$(TEST_DIR)/%: tests/%.c $(LIB)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

# =========================
# Cleanup
# =========================

clean:
	rm -rf $(BUILD_DIR)

re: clean all

.PHONY: all clean re test
