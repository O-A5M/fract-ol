/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:22:57 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 21:53:55 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_julia(t_fractol *fractol)
{
	fractol->type = 1;
	open_window(fractol);
	loop_render(fractol);
	print_usage();
	mlx_hook(fractol->window.window_pt, 17, 0, x_close, fractol);
	mlx_mouse_hook(fractol->window.window_pt, fractol_zoom, fractol);
	mlx_key_hook(fractol->window.window_pt, key_press, fractol);
	mlx_loop_hook(fractol->window.init_pt, loop_render, fractol);
	mlx_loop(fractol->window.init_pt);
}
