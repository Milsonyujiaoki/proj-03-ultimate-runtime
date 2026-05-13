NAME    = libds.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c17
AR      = ar rcs

INCLUDES = -I include/public -I ../libft/include/public

SRCS = $(shell find src -name "*.c" 2>/dev/null)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	find src -name "*.o" -delete 2>/dev/null; true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
