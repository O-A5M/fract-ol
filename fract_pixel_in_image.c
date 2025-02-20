/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_pixel_in_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:21:46 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 20:21:53 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_in_image(int x, int y, t_image *image, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->line_len) + (x * (image->bpp / 8));
	*(unsigned int *)pixel = color;
}
