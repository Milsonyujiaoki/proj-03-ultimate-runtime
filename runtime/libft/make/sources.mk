# ======================================
# Source files
# ======================================

STRING_SRC = $(wildcard src/string/*.c)
MEMORY_SRC = $(wildcard src/memory/*.c)
IO_SRC = $(wildcard src/io/*.c)
CONV_SRC = $(wildcard src/conversion/*.c)

SRC = \
	$(STRING_SRC) \
	$(MEMORY_SRC) \
	$(IO_SRC) \
	$(CONV_SRC)

# ======================================
# Object files
# ======================================

OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))
