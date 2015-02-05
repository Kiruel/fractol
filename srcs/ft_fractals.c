/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 12:29:59 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/04 12:30:41 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	draw_sierpinski(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x <= DEFAUT_X)
	{
		e->y = 0;
		while (e->y <= DEFAUT_Y)
		{
			if (!((e->x / 1) % 3 == 1 && (e->y / 1) % 3 == 1) && !((e->x / 3) % 3 == 1
				&& (e->y / 3) % 3 == 1) && !((e->x / 9) % 3 == 1 && (e->y / 9) % 3 == 1)
				&& !((e->x / 27) % 3 == 1 && (e->y / 27) % 3 == 1)
				&& !((e->x / 81) % 3 == 1 && (e->y / 81) % 3 == 1)
				&& !((e->x / 243) % 3 == 1 && (e->y / 243) % 3 == 1))
			ft_put_pixel_to_image(e, e->x, e->y, 0xFFFFFF);
			e->y++;
		}
		e->x++;
	}
}

void	draw_mandelbrot(t_env *e)
{
	e->x = 0;
	e->y = 0;
    e->i = 0;
	while (e->x <= DEFAUT_X)
	{
		e->y = 0;
		while (e->y <= DEFAUT_Y)
		{
			e->pr = 1.5 * (e->x - DEFAUT_X / 2) / (0.5 * e->zoom * DEFAUT_X) + e->moveX;
	        e->pi = (e->y - DEFAUT_Y / 2) / (0.5 * e->zoom * DEFAUT_Y) + e->moveY;
	        e->newRe = e->newIm = e->oldRe = e->oldIm = 0;
	        e->i = 0;
	        while (e->i < e->maxIterations)
	        {
	            e->oldRe = e->newRe;
	            e->oldIm = e->newIm;
	            e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->pr;
	            e->newIm = 2 * e->oldRe * e->oldIm + e->pi;
	            if((e->newRe * e->newRe + e->newIm * e->newIm) > 4) 
	            	break;
	        	e->i++;
	        }
			ft_put_pixel_to_image(e, e->x, e->y, 0x0F << e->i);
			e->y++;
		}
		e->x++;
	}
}

void	draw_julia(t_env *e)
{
	e->x = 0;
	e->y = 0;
    e->i = 0;
	while (e->x < DEFAUT_X)
	{
		e->y = 0;
		while (e->y < DEFAUT_Y)
		{
			e->newRe = 1.5 * (e->x - DEFAUT_X / 2) / (0.5 * e->zoom * DEFAUT_X) + e->moveX;
			e->newIm = (e->y - DEFAUT_Y / 2) / (0.5 * e->zoom * DEFAUT_Y) + e->moveY;
			e->i = 0;
			while (e->i < e->maxIterations)
			{
				e->oldRe = e->newRe;
				e->oldIm = e->newIm;
				e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->cRe;
				e->newIm = 2 * e->oldRe * e->oldIm + e->cIm;
				if((e->newRe * e->newRe + e->newIm * e->newIm) > 4) break;				
				e->i++;
			}
			ft_put_pixel_to_image(e, e->x, e->y, 0x0F << e->i);
			e->y++;
		}
		e->x++;
    }
}