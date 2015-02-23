/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 10:46:02 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/14 10:48:38 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_value2(t_env *e)
{
	if (e->how_window == 1)
	{
		e->movex = -0.5;
		e->movey = 0;
		e->zoom = 0.8;
	}
	else if (e->how_window == 3)
	{
		e->movex = 0.5;
		e->movey = -0.5;
	}
	else if (e->how_window == 4)
	{
		e->zoom = 0.6;
		e->movex = 0;
		e->movey = 0;
		e->l = 10;
	}
	else
	{
		e->movex = 0;
		e->movey = 0;
		e->zoom = 0.8;
	}
	e->iters = DEFAUT_MAXITER;
}

void	ft_init_value(t_env *e)
{
	e->rgb.r = 0.2;
	e->rgb.g = 0.4;
	e->rgb.b = 0.8;
	e->l = 8;
	e->freq = 1;
	e->keycode = 0;
	e->ctr.x = e->default_x / 2;
	e->ctr.y = e->default_y / 2;
	e->cre = -0.70176;
	e->cim = -0.3842;
	ft_init_value2(e);
}
