#include "fractol.h"

int	fractol_mandelbrot(t_fractol *fractol)
{
    fractol->type = 0;
    open_window(fractol);
    pixel_render(fractol, mandelbrot_draw);
    mlx_hook(fractol->window.window_pt, 17, 0, x_close, fractol);
    mlx_mouse_hook(fractol->window.window_pt, fractol_zoom, fractol);
    mlx_key_hook(fractol->window.window_pt, key_press, fractol);
    mlx_loop(fractol->window.init_pt);
}
