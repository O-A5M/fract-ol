#include "fractol.h"

void	error_message(void)
{
    ft_printf("Please check your input again, make sure it matchs one of those options:\n\
		|-------->\"Mandelbrot\"<--------|\n\
		|-------->\"Julia\" \"number\" \"number\"<--------|\n\
		|-------->For better experience we recommend you to enter a number between -2 and 2 <--------|\n");
}

int main(int ac, char **av)
{
    t_fractol	fractol;

    fractol.iter = 100;
    fractol.zoom_factor.x = 2;
    fractol.zoom_factor.y = -2;
    fractol.x_move = 0;
    fractol.y_move = 0;
    if (ac == 2 || ac == 4)
    {
	if (!ft_strncmp(av[1], "Julia", 5))
	{
	    if (parsing_julia(av, ac, &fractol.julia))
	    	fractol_julia(&fractol);
	    else
		error_message();
	}
	else if (!ft_strncmp(av[1], "Burning-ship", 12))
	    fractol_ship(&fractol);
	else if (!ft_strncmp(av[1], "Mandelbrot", 10))
	    fractol_mandelbrot(&fractol);
	else
	    error_message();
    }
    else
	error_message();
}
