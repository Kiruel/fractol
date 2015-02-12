/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 10:54:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/12 18:02:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     motion_hook(int x, int y, t_env *e)
{
	double tmpRe;
	double tmpIm;
	
	if (e->how_window == 2)
	{
		tmpRe = e->cRe;
		tmpIm = e->cIm;
		tmpRe = (((2 * (((double)x * C_ECH) / e->default_x )) / C_ECH) - 1) / e->zoom;
		tmpIm = (((2 * (((double)y * C_ECH) / e->default_y )) / C_ECH) - 1) / e->zoom;
		if (e->keycode != KEY_M)
		{
			if (tmpRe != e->cRe)
				e->cRe = tmpRe;
			if (tmpIm != e->cIm)
				e->cIm = tmpIm;
			expose_hook(e);
		}		
	}
	return (0);
}

void	ft_zoom_mouse(double zoom, int x, int y, t_env *e)
{
	long double	p_x;
	long double	p_y;

	(void)zoom;
	p_x = (double)x / (double)e->default_x;
	p_y = (double)y / (double)e->default_y;
	e->moveX -= p_x * (-3.75 / e->zoom) + (1.875 / e->zoom);
	e->moveY -= p_y * (-2.5 / e->zoom) + (1.25 / e->zoom);
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
