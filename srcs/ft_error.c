/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 10:47:20 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/14 10:06:07 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mallerr(void)
{
	ft_putendl_fd("malloc error", 2);
	exit(2);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Somethings went wrong with:", 2);
	ft_putendl_fd(str, 2);
	exit(2);
}

void	ft_map_error(void)
{
	ft_putendl_fd("map error", 2);
	exit (2);
}

int		ft_error_win(t_env *e, char **av)
{
	if (ft_atoi(av[2]) == 0 || ft_atoi(av[3]) == 0)
	{
		ft_putendl_fd("Error win : 0 x ; 0 y.", 2);
		return (-1);
	}
	if (ft_atoi(av[2]) > 2560 || ft_atoi(av[3]) > 1350)
	{
		ft_putendl_fd("Error win : x > 2560 or y > 1350.", 2);
		return (-1);
	}
	e->default_x = ft_atoi(av[2]);
	e->default_y = ft_atoi(av[3]);
	return (0);
}
