#include "fractol.h"

void	clear_image(t_fractol *fractol)
{
    int	x;
    int	y;

    x = 0;
    while(x <= WIDTH)
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
