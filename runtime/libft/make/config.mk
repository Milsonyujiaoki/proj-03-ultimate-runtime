CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c11 -Iinclude

AR = ar

ARFLAGS = rcs

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TEST_DIR = $(BUILD_DIR)/tests

LIB = $(BUILD_DIR)/libft.a
