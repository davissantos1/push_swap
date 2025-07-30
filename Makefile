# Variables

CC= cc
CFLAGS= -Wall -Wextra -Werror -I.
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
NAME= push_swap

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
