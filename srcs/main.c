/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:40:39 by etheodor          #+#    #+#             */
/*   Updated: 2015/01/09 15:00:21 by etheodor         ###   ########.fr       */
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
    e->maxIterations = 300;
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
	e->cRe = -0.70176;
	e->cIm = -0.3842;
	e->x = 0;
	e->y = 0;
    e->maxIterations = 300;
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

int		expose_hook(t_env *e)
{
	ft_update_img(e, draw_sierpinski);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	if (keycode == 49)
	{
		e->how_window = 0;
		ft_update_img(e, draw_sierpinski);
	}
	if (keycode == 50)
	{
		e->how_window = 1;
		ft_update_img(e, draw_mandelbrot);
	}
	if (keycode == 51)
	{
		e->how_window = 2;
		ft_update_img(e, draw_julia);
	}
	if (keycode == 65363)
	{
		e->moveX -= SPEED_TRANSLATE;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	if (keycode == 65361)
	{
		e->moveX += SPEED_TRANSLATE;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	if (keycode == 65364)
	{
		e->moveY -= SPEED_TRANSLATE;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	if (keycode == 65362)
	{
		e->moveY += SPEED_TRANSLATE;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	if (keycode == 65451)
	{
		e->zoom *= 1.5;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	if (keycode == 65453)
	{
		e->zoom /= 1.5;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	// ft_putnbr(keycode);
	// ft_putchar('\n');
	return (0);
}

int		main(int ac, char **av, char **ev)
{
	t_env	*e;
	int		i;

	(void)av;
	i = 0;
	if (!ev[0])
		return (0);
	if ((i = ft_error_arg(ac)) == -1)
		return (0);
	if ((e = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		ft_mallerr();
    e->moveX = 0;
    e->moveY = 0;
	e->zoom = 0.8;
    e->how_window = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, DEFAUT_X, DEFAUT_Y, "fractol");
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
