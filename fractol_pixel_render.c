/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_pixel_render.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:23:46 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 21:48:56 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_type(t_fractol *fractol)
{
	clear_image(fractol);
	if (fractol->type == 0)
		pixel_render(fractol, mandelbrot_draw);
	if (fractol->type == 1)
		pixel_render(fractol, julia_draw);
	if (fractol->type == 2)
		pixel_render(fractol, ship_draw);
}

int	pixel_render(t_fractol *fractol, void (*f) (int, int, t_fractol *))
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
	mlx_put_image_to_window(fractol->window.init_pt,
		fractol->window.window_pt,
		fractol->image.img, 0, 0);
	return (0);
}

int loop_render(t_fractol *fractol)
{
	clear_image(fractol);
	fractol_type(fractol);
    return (0);
}
