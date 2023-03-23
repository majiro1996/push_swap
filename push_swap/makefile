CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

NAME=push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: clean all
