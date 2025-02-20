/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:22:14 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 21:59:01 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_image(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			pixel_in_image(x, y, &fractol->image, 0x00000000);
			y++;
		}
		x++;
	}
}
