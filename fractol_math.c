#include "fractol.h"

double	pixel_to_cord(double pixel, t_zoom_factor *zoom_factor)
{
	double	ret;

	ret = (zoom_factor->x - zoom_factor->y) * (pixel - 0) / (WIDTH - 0) + zoom_factor->y;
	return (ret);
}

t_complex	sum_c(t_complex z, t_complex c)
{
	t_complex	ret;

	ret.re = z.re + c.re;
	ret.im = z.im + c.im;
	return (ret);
}

t_complex	pow_c(t_complex z)
{
	t_complex	ret;

	ret.re = (z.re * z.re) - (z.im * z.im);
	ret.im = 2 * z.re * z.im;
	return (ret);
}

int	color_change(int i, int iter)
{
    int	ret;
//	int r, g, b;
//
//	r = (int)(sin(0.16 * i + 0) * 127 + 128);
//	g = (int)(sin(0.16 * i + 2) * 127 + 128);
//	b = (int)(sin(0.16 * i + 4) * 127 + 128);
//	
//	return (r << 16 | g << 8 | b);
	ret = (0x00FFFFFF - 0x00000000) * (i - 0) / (iter - 0) + 0x00000000;
	return (ret);
}
