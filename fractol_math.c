/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:23:23 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 21:53:01 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pixel_to_cord(double pixel, t_zoom_factor *zoom_factor)
{
	double	ret;

	ret = (zoom_factor->x - zoom_factor->y) * pixel / WIDTH + zoom_factor->y;
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

int	color_change(int iter, t_fractol *fractol)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (iter * 7 + fractol->color_change) / 255.0;
	r = (int)(127.5 * (1 + sin(6.28 * t)));
	g = (int)(127.5 * (1 + sin(6.28 * t + 2)));
	b = (int)(127.5 * (1 + sin(6.28 * t + 4)));
	return ((r << 16) | (g << 8) | b);
}
