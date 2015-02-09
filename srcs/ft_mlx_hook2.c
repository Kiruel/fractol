#include "fractol.h"

int		button_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		e->zoom *= 1.5;
		expose_hook(e);
	}
	if (button == 4)
	{
		e->zoom /= 1.5;
		expose_hook(e);
	}
	return (0);
}
