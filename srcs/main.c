/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:40:39 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/04 13:40:40 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	ft_update_img(e, draw_sierpinski);
	return (0);
}

void	ft_show_variable(t_env *e)
{
	ft_putstr("####### VARIABLES #######\n");
	ft_putstr("## maxIterations : ");
	ft_putnbr(e->maxIterations);
	ft_putstr("\n");
	ft_putstr("##          zoom : ");
	ft_putnbr(e->zoom);
	ft_putstr("\n");
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_V)
	{
		ft_show_variable(e);		
	}
	if (keycode == KEY_ECHAP)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	if (keycode == KEY_1)
	{
		e->how_window = 0;
		ft_update_img(e, draw_sierpinski);
	}
	if (keycode == KEY_2)
	{
		e->how_window = 1;
		ft_update_img(e, draw_mandelbrot);
	}
	if (keycode == KEY_3)
	{
		e->how_window = 2;
		ft_update_img(e, draw_julia);
	}
	if (keycode == KEY_RIGHT)
	{
		e->moveX -= (SPEED_TRANSLATE / e->zoom);
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);
	}
	if (keycode == KEY_LEFT)
	{
		e->moveX += (SPEED_TRANSLATE / e->zoom);
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);
	}
	if (keycode == KEY_DOWN)
	{
		e->moveY -= (SPEED_TRANSLATE / e->zoom);
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);
	}
	if (keycode == KEY_UP)
	{
		e->moveY += (SPEED_TRANSLATE / e->zoom);
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);
	}
	if (keycode == KEY_MORE_NUM || keycode == KEY_MORE)
	{
		e->zoom *= 1.5;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	if (keycode == KEY_LESS_NUM || keycode == KEY_LESS)
	{
		e->zoom /= 1.5;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);
	}
	if (keycode == KEY_R)
	{
		e->zoom = 0.8;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);
	}
	if (keycode == KEY_3_NUM)
	{
		e->maxIterations += 10;
		if (e->how_window == 0)
			ft_update_img(e, draw_sierpinski);
		if (e->how_window == 1)
			ft_update_img(e, draw_mandelbrot);
		if (e->how_window == 2)
			ft_update_img(e, draw_julia);		
	}
	if (keycode == KEY_2_NUM)
	{
		e->maxIterations -= 10;
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
    e->moveX = 0.1;
    e->moveY = 0.1;
	e->zoom = 0.8;
    e->how_window = 0;
	e->maxIterations = 200;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, DEFAUT_X, DEFAUT_Y, "fractol");
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
