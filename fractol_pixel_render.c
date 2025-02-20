#include "fractol.h"

void	pixel_render(t_fractol *fractol, void (*f) (int, int, t_fractol *))
{
	int	y;
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			f(x, y, fractol);
			y++;
		}
		x++;
	}
   	mlx_put_image_to_window(fractol->window.init_pt, fractol->window.window_pt, fractol->image.img, 0, 0);
}
