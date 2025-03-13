/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:22:03 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/02/20 20:22:04 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	ft_printf("\033[1;31m");
	ft_printf("###############################\n");
	ft_printf("##   ERROR: Invalid Argument ##\n");
	ft_printf("###############################\n");
	ft_printf("\033[0m\n");
	ft_printf("Oops! It looks like you've entered an invalid argument.\n");
	ft_printf("Please follow the correct usage instructions:\n\n");
	ft_printf("\033[1;34mTo open Mandelbrot, enter:\033[0m Mandelbrot\n");
	ft_printf("\033[1;34mTo open Julia, enter:\033[0m");
	ft_printf(" Julia <a number> <a number>\n");
	ft_printf("\033[1;34mTo open Burning-Ship, enter:\033[0m Burning-ship\n\n");
	ft_printf("Note: It's better to enter a number between \033[1;32m2\033[0m");
	ft_printf(" and \033[1;32m-2\033[0m for better results with Julia.\n");
	ft_printf("This ensures the fractals are well-defined and look nice!\n");
	ft_printf("\nPlease try again with the correct arguments.\n");
	ft_printf("\033[1;31m");
	ft_printf("###############################\n");
	ft_printf("###############################\n");
	ft_printf("\033[0m");
}

void	print_usage(void)
{
	ft_printf("\033[1;32m");
	ft_printf("###############################\n");
	ft_printf("##     Fract-O-L: Controls    ##\n");
	ft_printf("###############################\n");
	ft_printf("\033[0m\n");
	ft_printf("Use the following keys to navigate");
	ft_printf(" and adjust the fractal view:\n\n");
	ft_printf("\033[1;34m+ and -\033[0m : Change the iterations\n");
	ft_printf("\033[1;34mScroll down\033[0m : Zoom In\n");
	ft_printf("\033[1;34mScroll up\033[0m : Zoom Out\n");
	ft_printf("\033[1;34mLeft Arrow\033[0m : Move Left\n");
	ft_printf("\033[1;34mRight Arrow\033[0m : Move Right\n");
	ft_printf("\033[1;34mUp Arrow\033[0m : Move Up\n");
	ft_printf("\033[1;34mDown Arrow\033[0m : Move Down\n");
	ft_printf("\033[1;34mThe 'r' Key\033[0m : Reset\n");
	ft_printf("\033[1;34mThe 'c' Key\033[0m : Change Color\n");
	ft_printf("\033[1;31mEsc\033[0m : Close the program\n");
	ft_printf("\nEnjoy exploring fractals!\n");
	ft_printf("\033[1;32m");
	ft_printf("###############################\n");
	ft_printf("###############################\n");
	ft_printf("\033[0m");
}

void	print_goodbye(void)
{
	ft_printf("\033[1;33m");
	ft_printf("#########################################\n");
	ft_printf("##                                     ##\n");
	ft_printf("##           THANK YOU FOR USING       ##\n");
	ft_printf("##             FRACT-O-L!              ##\n");
	ft_printf("##                                     ##\n");
	ft_printf("#########################################\n");
	ft_printf("\033[0m\n");
	ft_printf("We hope you enjoyed exploring fractals!\n");
	ft_printf("Goodbye and take care!\n");
	ft_printf("\033[1;32m");
	ft_printf("#########################################\n");
	ft_printf("#########################################\n");
	ft_printf("\033[0m");
}

void	julia_init(t_fractol *fractol)
{
	fractol->julia.im = 0.156;
	fractol->julia.re = -0.8;
	fractol_julia(fractol);
}

void	fractol_init(t_fractol *fractol)
{
	
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.iter = 42;
	fractol.zoom_factor.x = 2;
	fractol.zoom_factor.y = -2;
	fractol.x_move = 0;
	fractol.y_move = 0;
	if (ac == 2 || ac == 4)
	{
		if (!ft_strncmp(av[1], "Julia", 6))
		{
			if (parsing_julia(av, ac, &fractol.julia))
				fractol_julia(&fractol);
			else
				julia_init(&fractol);
		}
		else if (!ft_strncmp(av[1], "Burning-ship", 13))
			fractol_ship(&fractol);
		else if (!ft_strncmp(av[1], "Mandelbrot", 11))
			fractol_mandelbrot(&fractol);
		else
			error_message();
	}
	else
		error_message();
}
