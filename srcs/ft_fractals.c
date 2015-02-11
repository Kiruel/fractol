/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 12:29:59 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/11 13:16:51 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_sierpinski(t_env *e)
{
	if (!((e->x / 1) % 3 == 1 && (e->y / 1) % 3 == 1) && !((e->x / 3) % 3 == 1
		&& (e->y / 3) % 3 == 1) && !((e->x / 9) % 3 == 1 && (e->y / 9) % 3 == 1)
		&& !((e->x / 27) % 3 == 1 && (e->y / 27) % 3 == 1)
		&& !((e->x / 81) % 3 == 1 && (e->y / 81) % 3 == 1)
		&& !((e->x / 243) % 3 == 1 && (e->y / 243) % 3 == 1))
		e->i = 1;
	else
		e->i = 0;
}

void	draw_mandelbrot(t_env *e)
{
	e->pr = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x) + e->moveX;
	e->pi = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y) + e->moveY;
	e->newRe = 0;
	e->newIm = 0;
	e->oldRe = 0;
	e->oldIm = 0;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldRe = e->newRe;
		e->oldIm = e->newIm;
		e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->pr;
		e->newIm = 2 * e->oldRe * e->oldIm + e->pi;
		if((e->newRe * e->newRe + e->newIm * e->newIm) > e->l) break;
		e->i++;
	}
}

void	draw_ship(t_env *e)
{
	e->pr = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x) + e->moveX;
	e->pi = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y) + e->moveY;
	e->newRe = 0;
	e->newIm = 0;
	e->oldRe = 0;
	e->oldIm = 0;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldRe = e->newRe;
		e->oldIm = e->newIm;
		e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm - e->pr;
		e->newIm = 2 * fabs(e->oldRe) * fabs(e->oldIm) + e->pi;
		if((e->newRe * e->newRe + e->newIm * e->newIm) > e->l) break;
		e->i++;
	}
}

void	draw_julia(t_env *e)
{
	e->newRe = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x) + e->moveX;
	e->newIm = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y) + e->moveY;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldRe = e->newRe;
		e->oldIm = e->newIm;
		e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->cRe;
		e->newIm = 2 * e->oldRe * e->oldIm + e->cIm;
		if((e->newRe * e->newRe + e->newIm * e->newIm) > e->l) break;
		e->i++;
	}
}

void	draw_multi(t_env *e)
{	
	e->newRe = 0 + e->pr;
	e->newIm = 0 + e->pi;
	e->i = 0;
	while (e->i < e->iters)
	{
		e->oldRe = e->newRe;
		e->oldIm = e->newIm;
		e->tmpre = pow((e->oldRe * e->oldRe) - (e->oldIm * e->oldIm), 2.0) + 4.0 * e->oldRe * e->oldRe * e->oldIm * e->oldIm;
		e->newRe = (((e->oldRe * e->oldRe) - (e->oldIm * e->oldIm)) / e->tmpre) + e->pr;
		e->newIm = ((-2.0 * e->oldRe * e->oldIm) / e->tmpre) + e->pi;
		if((e->newRe * e->newRe + e->newIm * e->newIm) > e->l)
			break;
		e->i++;
	}
}
