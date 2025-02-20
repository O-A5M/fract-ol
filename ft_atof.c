#include "fractol.h"

double	ft_atof(char *s)
{
	double	ret;
	char	**splited_number;

	if (!s)
	    return (0);
	if (!ft_strchr(s, '.'))
	    return (ft_atoi(s));
	splited_number = ft_split(s, '.');
	if (splited_number[0][0] != '-')
		ret = ft_atoi(splited_number[0]) + (ft_atoi(splited_number[1]) / pow(10, ft_strlen(splited_number[1])));
	else if (splited_number[0][0] == '-')
		ret = ft_atoi(splited_number[0]) - (ft_atoi(splited_number[1]) / pow(10, ft_strlen(splited_number[1])));
	free(splited_number[0]);
	free(splited_number[1]);
	free(splited_number);
	return (ret);
}
