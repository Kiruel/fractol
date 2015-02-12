/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 10:54:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/12 10:54:05 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_mouse(double zoom, int x, int y, t_env *e)
{
	// ft_putnbr(x);
	// ft_putchar(':');
	// ft_putnbr(y);
	// ft_putchar('\n');
	// ft_putnbr(e->default_x);
	// ft_putchar('\n');
	long double	p_x;
	long double	p_y;

	p_x = (double)x / (double)e->default_x;
	p_y = (double)y / (double)e->default_y;
	e->moveX = (p_x * 3 - 2) / e->zoom;
	e->moveY = (p_y * 2 - 1) / e->zoom;
	e->zoom *= zoom;
	expose_hook(e);
}

int		button_hook(int button, int x, int y, t_env *e)
{
	if (button == 3)
		ft_zoom_mouse(0.5, x, y, e);
	if (button == 1)
		ft_zoom_mouse(2, x, y, e);
	return (0);
}


/*void		ft_center_mouse(int *x, int *y, t_env *e)
{
	if (*x > e->default_x / 2 && *y < e->default_y / 2)
	{
			*x = *x - e->default_x / 2;
			*y = -(*y - e->default_y / 2);
	}
 	else if (*x < e->default_x / 2 && *y < e->default_y / 2)
	{
		*x = *x - e->default_x / 2;
		*y = -(*y - e->default_y / 2);
	}
	else if (*x > e->default_x / 2 && *y > e->default_y / 2)
	{
		*x = *x - e->default_x / 2;
		*y = -(*y - e->default_y / 2);
	}
	else
	{
		*x = *x - e->default_x / 2;
		*y = -(*y - e->default_y / 2);
	}
}

void	ft_zoom_mouse(double zoom, int x, int y, t_env *e)
{
	long double	percent_x;
	long double	percent_y;

	ft_center_mouse(&x, &y, e);
	percent_x = ((double)x * 100) / (e->default_x / 2);
	percent_y = ((double)y * 100) / (e->default_y / 2);
	percent_x = (percent_x / 100) * 2.14;
	percent_y = (percent_y / 100) * 1.43;
	e->moveX += percent_x * (1 / (long double)e->zoom);
	e->moveY += percent_y * (1 / (long double)e->zoom);
	if (e->zoom * zoom >= 1)
		e->zoom *= zoom;
	expose_hook(e);
}*/