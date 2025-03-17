/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:21:12 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 20:48:29 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define MIN_SCALE -2
# define MAX_SCALE 2
# define ARROW_LEFT 65361
# define ARROW_UP   65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ESC_KEY 65307
# define KEY_PLUS 61
# define KEY_MINUS 45
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_LOWER_C 99
# define KEY_LOWER_R 114
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <mlx.h>
# include <X11/X.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <math.h>

typedef struct s_window
{
	void	*init_pt;
	void	*window_pt;
}		t_window;

typedef struct s_zoom_factor
{
	double	x;
	double	y;
}		t_zoom_factor;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}		t_complex;

typedef struct s_julia
{
	double	re;
	double	im;
}		t_julia;

typedef struct s_fractol
{
	t_image				image;
	t_window			window;
	t_julia				julia;
	t_zoom_factor		zoom_factor;
	int					iter;
	double				x_move;
	double				y_move;
	int					type;
	int					color_change;
}				t_fractol;

int					pixel_render(t_fractol *fractol,
						void (*f) (int, int, t_fractol *));
int					loop_render(t_fractol *fractol);
void				open_window(t_fractol *fractol);
t_complex			sum_c(t_complex z, t_complex c);
t_complex			pow_c(t_complex z);
double				pixel_to_cord(double pixel, t_zoom_factor *zoom_factor);
int					x_close(t_fractol *fractol);
void				pixel_in_image(int x, int y, t_image *image, int color);
int					key_press(int the_code, t_fractol *fractol);
int					color_change(int i, t_fractol *fractol);
void				fractol_mandelbrot(t_fractol *fractol);
void				fractol_julia(t_fractol *fractol);
void				fractol_ship(t_fractol *fractol);
double				ft_atof(char *s);
int					parsing_julia(char **s, int ac, t_julia *julia);
int					fractol_zoom(int the_code, int x, int y,
						t_fractol *fractol);
void				clear_image(t_fractol *fractol);
void				julia_draw(int x, int y, t_fractol *fractol);
void				mandelbrot_draw(int x, int y, t_fractol *fractol);
void				ship_draw(int x, int y, t_fractol *fractol);
int					arrow_move(int the_code, t_fractol *fractol);
int					color_shift(int the_code, t_fractol *fractol);
void				print_goodbye(void);
void				print_usage(void);
void				fractol_init(t_fractol *fractol);
void				close_window(t_fractol *fractol);
int					isnum(char *s1, char *s2);

#endif
