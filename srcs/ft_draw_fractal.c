#include "fractol.h"

int		expose_hook(t_env *e)
{
	ft_update_img(e);
	return (0);
}

void	ft_draw_frct(t_env *e)
{
	if (e->how_window == 0)
		draw_sierpinski(e);
	else if (e->how_window == 1)
		draw_mandelbrot(e);
	else if (e->how_window == 2)
		draw_julia(e);
	else if (e->how_window == 3)
		draw_ship(e);
	else if (e->how_window == 4)
		draw_multi(e);
}

int 	ft_rgbtoint(int r, int g, int b)
{
	return ((0xFF & r) << 16 | (0xFF & g) << 8 | (0xFF & b));
}

void	ft_frct(t_env *e)
{
	e->x = 0;
	e->y = 0;
	e->i = 0;
	while (e->x < e->default_x)
	{
		e->y = 0;
		while (e->y < e->default_y)
		{
			e->pr = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x) + e->moveX;
			e->pi = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y) + e->moveY;
			ft_draw_frct(e);
			ft_put_pixel_to_image(e, e->x, e->y, ft_color(e));
			e->y++;
		}
		e->x++;
	}
}
