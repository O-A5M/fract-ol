/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:22:45 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 22:02:50 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->window.init_pt, fractol->image.img);
	mlx_destroy_window(fractol->window.init_pt, fractol->window.window_pt);
	mlx_destroy_display(fractol->window.init_pt);
	free(fractol->window.init_pt);
	print_goodbye();
	exit(0);
}

// static void	fractol_type(t_fractol *fractol)
// {
// 	clear_image(fractol);
// 	if (fractol->type == 0)
// 		pixel_render(fractol, mandelbrot_draw);
// 	if (fractol->type == 1)
// 		pixel_render(fractol, julia_draw);
// 	if (fractol->type == 2)
// 		pixel_render(fractol, ship_draw);
// }

int	x_close(t_fractol *fractol)
{
	close_window(fractol);
	return (0);
}

int	key_press(int the_code, t_fractol *fractol)
{
	if (the_code == ESC_KEY)
		close_window(fractol);
	else if (the_code == ARROW_LEFT)
		fractol->x_move -= 0.1;
	else if (the_code == ARROW_RIGHT)
		fractol->x_move += 0.1;
	else if (the_code == ARROW_DOWN)
		fractol->y_move += 0.1;
	else if (the_code == ARROW_UP)
		fractol->y_move -= 0.1;
	else if (the_code == KEY_PLUS)
		fractol->iter += 5;
	else if (the_code == KEY_MINUS)
		fractol->iter -= 5;
	else if (the_code == 99)
		fractol->color_change += 50;
	else if (the_code == 114)
	{
		fractol->zoom_factor.x = 2;
		fractol->zoom_factor.y = -2;
		fractol->y_move = 0;
		fractol->x_move = 0;
	}
	return (0);
}

int	fractol_zoom(int the_code, int x, int y, t_fractol *fractol)
{
	x = x + 1;
	x = y - 1 + x - y;
	if (the_code == SCROLL_UP)
	{
		fractol->zoom_factor.x *= 0.9;
		fractol->zoom_factor.y *= 0.9;
	}
	else if (the_code == SCROLL_DOWN)
	{
		fractol->zoom_factor.y *= 1.1;
		fractol->zoom_factor.x *= 1.1;
	}
	return (0);
}
