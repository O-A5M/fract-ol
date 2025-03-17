/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:02:34 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/03/14 23:02:38 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->image.addr = NULL;
	fractol->image.img = NULL;
	fractol->image.bpp = 0;
	fractol->image.endian = 0;
	fractol->image.line_len = 0;
	fractol->window.init_pt = NULL;
	fractol->window.window_pt = NULL;
	fractol->zoom_factor.x = 2;
	fractol->zoom_factor.y = -2;
	fractol->iter = 42;
	fractol->x_move = 0.0;
	fractol->y_move = 0.0;
	fractol->type = 0;
	fractol->color_change = fractol->type;
}
