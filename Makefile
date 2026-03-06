NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
stack/stack_init.c \
stack/stack_utils.c \
operations/push.c \
operations/swap.c \
operations/rotate.c \
operations/reverse_rotate.c \
parsing/parse.c \
parsing/check_errors.c \
parsing/index.c \
sorting/radix_sort.c \
sorting/small_sort.c \
utils/ft_atoi.c \
utils/ft_split.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all