/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:24:53 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/23 15:22:22 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_call(void)
{
	perror("It seems like we have some technical errors, try again later");
	exit(1);
}

void	open_window(t_fractol *fractol)
{
	fractol->window.init_pt = mlx_init();
	if (fractol->window.init_pt == NULL)
		error_call();
	fractol->window.window_pt = mlx_new_window(fractol->window.init_pt,
			WIDTH, HEIGHT, "Fract-ol");
	if (fractol->window.window_pt == NULL)
	{
		mlx_destroy_window(fractol->window.init_pt, fractol->window.window_pt);
		free(fractol->window.init_pt);
		error_call();
	}
	fractol->image.img = mlx_new_image(fractol->window.init_pt, WIDTH, HEIGHT);
	if (fractol->image.img == NULL)
	{
		mlx_destroy_window(fractol->window.init_pt, fractol->window.window_pt);
		mlx_destroy_image(fractol->window.init_pt, fractol->image.img);
		free(fractol->window.init_pt);
		free(fractol->window.window_pt);
		error_call();
	}
	fractol->image.addr = mlx_get_data_addr(fractol->image.img,
			&fractol->image.bpp,
			&fractol->image.line_len,
			&fractol->image.endian);
}
