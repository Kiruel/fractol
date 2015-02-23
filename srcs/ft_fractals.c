/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 12:29:59 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/14 10:56:32 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_sierpinski(t_env *e)
{
	if (!((e->x / 1) % 3 == 1 && (e->y / 1) % 3 == 1)
		&& !((e->x / 3) % 3 == 1
		&& (e->y / 3) % 3 == 1) && !((e->x / 9) % 3 == 1
		&& (e->y / 9) % 3 == 1)
		&& !((e->x / 27) % 3 == 1 && (e->y / 27) % 3 == 1)
		&& !((e->x / 81) % 3 == 1 && (e->y / 81) % 3 == 1)
		&& !((e->x / 243) % 3 == 1 && (e->y / 243) % 3 == 1))
		e->i = 1;
	else
		e->i = 0;
}

void	draw_mandelbrot(t_env *e)
{
	e->pr = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x)
	+ e->movex;
	e->pi = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y)
	+ e->movey;
	e->newre = 0;
	e->newim = 0;
	e->oldre = 0;
	e->oldim = 0;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldre = e->newre;
		e->oldim = e->newim;
		e->newre = e->oldre * e->oldre - e->oldim * e->oldim + e->pr;
		e->newim = 2 * e->oldre * e->oldim + e->pi;
		if ((e->newre * e->newre + e->newim * e->newim) > e->l)
			break ;
		e->i++;
	}
}

void	draw_ship(t_env *e)
{
	e->pr = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x)
	+ e->movex;
	e->pi = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y)
	+ e->movey;
	e->newre = 0;
	e->newim = 0;
	e->oldre = 0;
	e->oldim = 0;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldre = e->newre;
		e->oldim = e->newim;
		e->newre = e->oldre * e->oldre - e->oldim * e->oldim - e->pr;
		e->newim = 2 * fabs(e->oldre) * fabs(e->oldim) + e->pi;
		if ((e->newre * e->newre + e->newim * e->newim) > e->l)
			break ;
		e->i++;
	}
}

void	draw_julia(t_env *e)
{
	e->newre = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x)
	+ e->movex;
	e->newim = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y)
	+ e->movey;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldre = e->newre;
		e->oldim = e->newim;
		e->newre = e->oldre * e->oldre - e->oldim * e->oldim + e->cre;
		e->newim = 2 * e->oldre * e->oldim + e->cim;
		if ((e->newre * e->newre + e->newim * e->newim) > e->l)
			break ;
		e->i++;
	}
}

void	draw_multi(t_env *e)
{
	e->newre = 0 + e->pr;
	e->newim = 0 + e->pi;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldre = e->newre;
		e->oldim = e->newim;
		e->tmpre = pow((e->oldre * e->oldre) - (e->oldim * e->oldim), 2.0) + 4.0
		* e->oldre * e->oldre * e->oldim * e->oldim;
		e->newre = (((e->oldre * e->oldre) - (e->oldim * e->oldim)) / e->tmpre)
		+ e->pr;
		e->newim = ((-2.0 * e->oldre * e->oldim) / e->tmpre) + e->pi;
		if ((e->newre * e->newre + e->newim * e->newim) > e->l)
			break ;
		e->i++;
	}
}
