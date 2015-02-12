/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:40:39 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/12 15:17:47 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	ft_update_img(e);
	return (0);
}

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

void	ft_init_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->default_x, e->default_y, "fractol");
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_hook(e->win, 6, 64, motion_hook, e);
	mlx_hook(e->win, 4, 5, button_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}

int		ft_find_frct(t_env *e, char *str)
{
	if (!ft_strcmp(str, "julia"))
		e->how_window = 2;
	else if (!ft_strcmp(str, "ship"))
		e->how_window = 3;
	else if (!ft_strcmp(str, "mandel"))
		e->how_window = 1;
	else if (!ft_strcmp(str, "multi"))
		e->how_window = 4;
	else
	{
		ft_error("fractal name");
		return (-1);
	}
	return (0);
}

void	ft_draw_frct(t_env *e)
{
	if (e->how_window == 0)
		draw_sierpinski(e);
	else if (e->how_window == 1)
		draw_mandelbrot(e);
	else if (e->how_window == 2)
		draw_julia(e);
	else if (e->how_window == 3)
		draw_ship(e);
	else if (e->how_window == 4)
		draw_multi(e);
}

int 	ft_rgbtoint(int r, int g, int b)
{
	return ((0xFF & r) << 16 | (0xFF & g) << 8 | (0xFF & b));
}

void	ft_frct(t_env *e)
{
	e->x = 0;
	e->y = 0;
	e->i = 0;
	while (e->x < e->default_x)
	{
		e->y = 0;
		while (e->y < e->default_y)
		{
			e->pr = 1.5 * (e->x - e->default_x / 2) / (0.5 * e->zoom * e->default_x) + e->moveX;
			e->pi = (e->y - e->default_y / 2) / (0.5 * e->zoom * e->default_y) + e->moveY;
			ft_draw_frct(e);
			ft_put_pixel_to_image(e, e->x, e->y, ft_color(e));
			e->y++;
		}
		e->x++;
	}
}

void	ft_fractol(int ac, char **av)
{
	t_env	*e;

	if ((e = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		ft_mallerr();
	e->default_x = 400;
	e->default_y = 300;
	if (ac == 4)
	{
		if (ft_error_win(e, av) == -1)
			exit(0);
	}
	else if (ac != 2)
	{
		ft_putendl_fd("Error : Usage: ./fracol [julia,mandel,multi]", 2);
		exit(0);
	}
	if (ft_find_frct(e, av[1]) == -1)
		exit(0);
	ft_init_value(e);
	ft_init_win(e);
}

int		main(int ac, char **av)
{
	ft_fractol(ac, av);
	return (0);
}
