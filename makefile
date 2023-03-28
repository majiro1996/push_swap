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

BONSRC =	checker.c \
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

OBONUS = $(BONSRC:.c=.o)

BONUS = checker

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS): $(LIBFT) $(OBONUS)
	$(CC) $(CFLAGS) $(OBONUS) $(LIBFT) -o $(BONUS)

$(LIBFT):
	@make extra -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
	rm -f $(OBJ)
	rm -f $(OBONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
