CFLAGS = -g3 -Wall -Werror -Wextra
CC = cc
SRC = ft_putnbr_base.c ft_putuns.c ft_putchar_ffd.c ft_putnbr_ffd.c ft_putstr_ffd.c ft_printf.c ft_putadr.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
