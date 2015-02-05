/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:40:39 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/05 13:18:28 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_value(t_env *e)
{
	e->ctr.x = DEFAUT_X / 2;
	e->ctr.y = DEFAUT_Y / 2;
	e->cRe = DEFAUT_CRE;
	e->cIm = DEFAUT_CIM;
	if (e->how_window == 1)
		e->moveX = -0.5;
	else
		e->moveX = 0;
    e->moveY = 0;
	e->zoom = 0.8;
	e->maxIterations = 200;
}

int		expose_hook(t_env *e)
{
	ft_update_img(e, draw_julia);
	return (0);
}

void	ft_update(t_env *e)
{
	if (e->how_window == 0)
		ft_update_img(e, draw_sierpinski);
	if (e->how_window == 1)
		ft_update_img(e, draw_mandelbrot);
	if (e->how_window == 2)
		ft_update_img(e, draw_julia);
}

int     motion_hook(int x, int y, t_env *e)
{
	if ((x > 0 && x < DEFAUT_X / 2) && (y > 0 && y < DEFAUT_Y / 2))
	{
		e->cRe = 0.285;
		e->cIm = 0.01;
		ft_update(e);
	}
	else
	{
		e->cRe = DEFAUT_CRE;
		e->cIm = DEFAUT_CIM;
		ft_update(e);
	}
	return (0);
}

int		button_hook(int button, int x, int y, t_env *e)
{
	ft_putnbr(x);
	ft_putchar(':');
	ft_putnbr(y);
	ft_putchar('\n');
	if (button == 5)
	{
		e->zoom *= 1.5;
		ft_update(e);
	}
	if (button == 4)
	{
		e->zoom /= 1.5;
		ft_update(e);
	}
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
	ft_init_value(e);
	e->how_window = 2;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, DEFAUT_X, DEFAUT_Y, "fractol");
	mlx_hook(e->win, 2, 3, key_hook, e);
	// mlx_hook(e->win, 6, 64, motion_hook, e);
	mlx_hook(e->win, 4, 5, button_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
