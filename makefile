CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =   main.c \
        argv_check.c \
        cost.c \
        operation_ex.c \
        operations_2.c \
        operations.c \
        sort_2.c \
        sort.c \
        target.c \
        utils_2.c \
        utils.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
