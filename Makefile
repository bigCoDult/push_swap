NAME = push_swap
CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -O0
CFLAGS = -g -O0
LDFLAGS = -L$(LIBFT_DIR) -lLIBFT
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -fr
INC = -I. -I$(LIBFT_DIR)
SRC = \
			main.c \
			sort.c \
			parse.c \

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
