/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:23:36 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 21:51:38 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parsing_julia(char **s, int ac, t_julia *julia)
{
	int	i;

	i = 0;
	if (ac != 4)
		return (0);
	while (s[2][i])
	{
		if ((s[2][i] > '9' || s[2][i] < '0')
			&& s[2][i] != '.' && s[2][i] != '-')
			return (0);
		i++;
	}
	i = 0;
	while (s[3][i])
	{
		if ((s[3][i] > '9' || s[3][i] < '0')
			&& s[3][i] != '.' && s[3][i] != '-')
			return (0);
		i++;
	}
	julia->re = ft_atof(s[2]);
	julia->im = ft_atof(s[3]);
	return (1);
}
