/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:24:38 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 21:40:01 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_ship(t_fractol *fractol)
{
	fractol->type = 2;
	open_window(fractol);
	pixel_render(fractol, ship_draw);
	mlx_hook(fractol->window.window_pt, 17, 0, x_close, fractol);
	mlx_mouse_hook(fractol->window.window_pt, fractol_zoom, fractol);
	mlx_key_hook(fractol->window.window_pt, key_press, fractol);
	mlx_loop(fractol->window.init_pt);
}
