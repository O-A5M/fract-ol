# libft variables

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_memmove.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_itoa.c ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c
OBJS = $(SRCS:.c=.o)
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NAME = libft.a

# ft_printf variables

PRINTF_A = ftprintf
PRINTF_D = ft_printf
PRINTF = $(PRINTF_D)/lib$(PRINTF_N).a

all: $(PRINTF) $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_D)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	$(MAKE) -C $(PRINTF_D) clean
	rm -rf $(OBJS) $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C $(PRINTF_D) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
