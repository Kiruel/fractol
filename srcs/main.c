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

int		expose_hook(t_env *e)
{
	ft_update_img(e);
	return (0);
}

int     motion_hook(int x, int y, t_env *e)
{
	double tmpRe;
	double tmpIm;
	
	tmpRe = DEFAUT_CRE;
	tmpIm = DEFAUT_CIM;
	tmpRe = ((2 * (((double)x * C_ECH) / DEFAUT_X )) / C_ECH) - 1;
	tmpIm = ((2 * (((double)y * C_ECH) / DEFAUT_Y )) / C_ECH) - 1;
	if (e->keycode != KEY_M)
	{
		if (tmpRe != e->cRe)
			e->cRe = tmpRe;
		if (tmpIm != e->cIm)
			e->cIm = tmpIm;
		expose_hook(e);
	}
	return (0);
}

void	ft_init_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, DEFAUT_X, DEFAUT_Y, "fractol");
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
	else if (!ft_strcmp(str, "sierp"))
		e->how_window = 0;
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
	if (e->how_window == 1)
		draw_mandelbrot(e);
	if (e->how_window == 2)
		draw_julia(e);
	if (e->how_window == 3)
		draw_ship(e);
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
	while (e->x < DEFAUT_X)
	{
		e->y = 0;
		while (e->y < DEFAUT_Y)
		{
			ft_draw_frct(e);
			if (e->how_window == 0)
				ft_put_pixel_to_image(e, e->x, e->y, WHITE * e->i);
			else if (e->how_window == 3)
				ft_put_pixel_to_image(e, e->x, e->y, ft_rgbtoint(((255 * e->i) / e->iters), ((255 * e->i) / e->iters), ((255 * e->i) /e->iters)));
			else
				ft_put_pixel_to_image(e, e->x, e->y, 0x0F << e->i);
			e->y++;
		}
		e->x++;
	}
}

int		main(int ac, char **av)
{
	t_env	*e;
	int i;

	i = 0;
	if (ac == 2)
	{
		if ((e = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
			ft_mallerr();
		ft_init_value(e);
		if (ft_find_frct(e, av[1]) == -1)
			return (0);
		ft_init_win(e);
	}
	else
		ft_putendl_fd("Error : Usage: ./fracol [julia,mandel,sierp]", 2);
	return (0);
}
