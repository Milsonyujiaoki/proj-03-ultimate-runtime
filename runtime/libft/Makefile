NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c17
AR      = ar rcs

# Sources
SRCS_MANDATORY = \
	src/string/ft_strlen.c \
	src/string/ft_strcpy.c \
	src/string/ft_strlcpy.c \
	src/string/ft_strlcat.c \
	src/string/ft_strdup.c \
	src/string/ft_strncmp.c \
	src/string/ft_strnstr.c \
	src/string/ft_strchr.c \
	src/string/ft_strrchr.c \
	src/string/ft_substr.c \
	src/string/ft_strjoin.c \
	src/string/ft_strtrim.c \
	src/string/ft_split.c \
	src/memory/ft_memset.c \
	src/memory/ft_memcpy.c \
	src/memory/ft_memmove.c \
	src/memory/ft_memchr.c \
	src/memory/ft_memcmp.c \
	src/memory/ft_bzero.c \
	src/memory/ft_calloc.c \
	src/ctype/ft_isalpha.c \
	src/ctype/ft_isdigit.c \
	src/ctype/ft_isalnum.c \
	src/ctype/ft_isascii.c \
	src/ctype/ft_isprint.c \
	src/ctype/ft_toupper.c \
	src/ctype/ft_tolower.c \
	src/stdio/ft_putchar_fd.c \
	src/stdio/ft_putstr_fd.c \
	src/stdio/ft_putendl_fd.c \
	src/stdio/ft_putnbr_fd.c \
	src/stdlib/ft_atoi.c \
	src/stdlib/ft_itoa.c

SRCS_BONUS = \
	src/list/ft_lstnew.c \
	src/list/ft_lstadd_front.c \
	src/list/ft_lstadd_back.c \
	src/list/ft_lstsize.c \
	src/list/ft_lstlast.c \
	src/list/ft_lstdelone.c \
	src/list/ft_lstclear.c \
	src/list/ft_lstiter.c \
	src/list/ft_lstmap.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS     = $(SRCS_BONUS:.c=.o)

INCLUDES = -I include/public

all: $(NAME)

$(NAME): $(OBJS_MANDATORY)
	$(AR) $(NAME) $(OBJS_MANDATORY)

bonus: $(OBJS_MANDATORY) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_MANDATORY) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	find src -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
