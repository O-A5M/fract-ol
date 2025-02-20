#include "fractol.h"

void	mandelbrot_draw(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;

	z.re = 0;
	z.im = 0;
	c.re = pixel_to_cord(x, &fractol->zoom_factor) + fractol->x_move;
	c.im = pixel_to_cord(y, &fractol->zoom_factor) + fractol->y_move;
	i = 0;
	while (i < fractol->iter)
	{
		z = sum_c(pow_c(z), c);
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			color = color_change(i, fractol->iter);
			pixel_in_image(x, y, &fractol->image, color);
			return ;
		}
		i++;
	}
}
/*
void	pixel_render(t_fractol *fractol)
{
	int	y;
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mandelbrot_draw(x, y, fractol);
			y++;
		}
		x++;
	}
   	mlx_put_image_to_window(fractol->window.init_pt, fractol->window.window_pt, fractol->image.img, 0, 0);
}*/
