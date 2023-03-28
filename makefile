CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC =   main.c \
        argv_parse.c \
        argv_check.c \
        cost.c \
        operation_ex.c \
        swap.c \
        operations.c \
        sort_2.c \
        sort.c \
        target.c \
        utils_2.c \
        utils.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make extra -C libft
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
