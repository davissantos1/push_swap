# Variables

CC= cc
CFLAGS= -Wall -Wextra -Werror -Wpedantic -Iincludes
SRC= src/main.c src/push_swap.c 
OBJ= $(SRC:.c=.o)
NAME= push_swap
LIBFT_DIR= libft
LIBFT= $(LIBFT_DIR)/libft.a

# Rules

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
