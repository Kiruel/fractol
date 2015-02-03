/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:28:15 by etheodor          #+#    #+#             */
/*   Updated: 2015/01/09 14:28:16 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_error_arg(int ac)
{
	if (ac > 1)
	{
		ft_putstr_fd("Error: Too many argument.\n", 2);
		return (-1);
	}
	if (ac < 1)
	{
		ft_putstr_fd("Missing args after binary.", 2);
		ft_putchar('\n');
		return (-1);
	}
	return (0);
}

void	ft_map_error2(char **value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (ft_isalpha((int)*value[i]))
			ft_map_error();
		i++;
	}
}

void	ft_map_error3(t_env *ret, int width)
{
	if (ret->size_line > 0)
		if (ret->size_line != width)
			ft_map_error();
	ret->size_line = width;
}
