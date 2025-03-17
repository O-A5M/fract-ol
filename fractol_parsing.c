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

int	additional_check(char **s)
{
	if (s[3] && (s[3][0] < '0' || s[3][0] > '9')
		&& s[3][0] != '-' && s[3][0] != '+')
		return (0);
	if (s[2] && (s[2][0] < '0' || s[2][0] > '9')
		&& s[2][0] != '-' && s[2][0] != '+')
		return (0);
	return (1);
}

int	isnum(char *s1, char *s2)
{
	int	i;

	i = 1;
	if (!((s1[0] <= '9' && s1[0] >= '0') || s1[0] == '-' || s1[0] == '+'))
		return (0);
	if (!((s2[0] <= '9' && s2[0] >= '0') || s2[0] == '-' || s2[0] == '+'))
		return (0);
	while (s1[i])
	{
		if ((s1[i] <= '9' && s1[i] >= '0') || s1[i] == '.')
			i++;
		else
			return (0);
	}
	i = 1;
	while (s2[i])
	{
		if ((s2[i] <= '9' && s2[i] >= '0') || s2[i] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

int	parsing_julia(char **s, int ac, t_julia *julia)
{
	int	i;

	i = 0;
	if (ac != 4)
		return (0);
	if (!additional_check(s))
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
