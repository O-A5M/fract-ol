/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_julia.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:23:56 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 22:00:47 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_draw(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.re = pixel_to_cord(x, &fractol->zoom_factor)
		+ fractol->x_move * (fractol->zoom_factor.x);
	z.im = pixel_to_cord(y, &fractol->zoom_factor)
		+ fractol->y_move * (fractol->zoom_factor.x);
	c.re = fractol->julia.re;
	c.im = fractol->julia.im;
	i = 0;
	while (i < fractol->iter)
	{
		z = sum_c(pow_c(z), c);
		if (z.im * z.im + z.re * z.re > 4)
		{
			color = color_change(i, fractol);
			pixel_in_image(x, y, &fractol->image, color);
			return ;
		}
		i++;
	}
}
