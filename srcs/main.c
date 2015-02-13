/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:40:39 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/12 17:40:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int		main(int ac, char **av)
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
	return (0);
}
