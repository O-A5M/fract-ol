/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_mandelbrot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:24:14 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 21:47:06 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_draw(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.re = 0;
	z.im = 0;
	c.re = pixel_to_cord(x, &fractol->zoom_factor)
		+ fractol->x_move * (fractol->zoom_factor.x / 2);
	c.im = pixel_to_cord(y, &fractol->zoom_factor)
		+ fractol->y_move * (fractol->zoom_factor.x / 2);
	i = 0;
	while (i < fractol->iter)
	{
		z = sum_c(pow_c(z), c);
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			color = color_change(i, fractol);
			pixel_in_image(x, y, &fractol->image, color);
			return ;
		}
		i++;
	}
}
