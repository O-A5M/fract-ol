#include "fractol.h"

void	pixel_in_image(int x, int y, t_image *image, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->line_len) + (x * (image->bpp / 8));
	*(unsigned int *)pixel = color;
}
