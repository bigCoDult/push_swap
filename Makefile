NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
RM = rm -fr
LIBFT_DIR = ./libft
LDFLAGS = -L$(LIBFT_DIR) -lft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I$(LIBFT_DIR)

SRC = \
			argv_to_str.c \
			main.c \
			print.c \
			sort.c \
			validate_stack.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
