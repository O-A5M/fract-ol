/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:25:07 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 20:31:03 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *s)
{
	double	ret;
	char	**sn;

	if (!s)
		return (0);
	if (!ft_strchr(s, '.'))
		return (ft_atoi(s));
	sn = ft_split(s, '.');
	if (sn[0][0] != '-')
		ret = ft_atoi(sn[0]) + (ft_atoi(sn[1]) / pow(10, ft_strlen(sn[1])));
	else if (sn[0][0] == '-')
		ret = ft_atoi(sn[0]) - (ft_atoi(sn[1]) / pow(10, ft_strlen(sn[1])));
	free(sn[0]);
	free(sn[1]);
	free(sn);
	return (ret);
}
