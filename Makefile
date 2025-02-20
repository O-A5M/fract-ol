# fractol's variables

Cflags = -g3 -ggdb -Wall -Wextra -Werror
CC = cc
SRC = fractol.c fractol_math.c fractol_window.c fract_pixel_in_image.c fractol_mandelbrot.c fractol_events.c fractol_julia.c ft_atof.c fractol_render_julia.c fractol_render_mandelbrot.c fractol_parsing.c fractol_clear.c fractol_pixel_render.c fractol_color_shift.c fractol_render_ship.c fractol_ship.c
NAME = fractol
XFLAGS = -lmlx -lX11 -lXext -lm
MLX_D = /home/oakhmouc/minilibx-linux

# libft's variables

LIBFT_N = ft
LIBFT_D = libft
LIBFT = $(LIBFT_D)/lib$(LIBFT_N).a
LIBFT_H = $(LIBFT_D)/libft.h
PRINTF_D = $(LIBFT_D)/ft_printf
PRINTF_N = ftprintf

# rules and targets

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_D) && $(MAKE) -C $(PRINTF_D)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_D) -l$(LIBFT_N) -L$(PRINTF_D) -lftprintf -L$(MLX_D) $(XFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_D) clean

fclean: clean
	$(MAKE) -C $(LIBFT_D) fclean
	rm -rf $(NAME)

re: fclean all clean

.PHONY: clean
