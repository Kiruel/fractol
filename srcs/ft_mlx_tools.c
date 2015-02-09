/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 09:44:33 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/04 12:40:09 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel_to_image(t_env *ret, int x, int y, int color)
{
	int i;

	i = x * 4 + y * ret->size_line;
	ret->pimg[i] = (color & 0xFF);
	ret->pimg[i + 1] = (color & 0xFF00) >> 8;
	ret->pimg[i + 2] = (color & 0xFF0000) >> 16;
}

int		ft_update_img(t_env *ret)
{
	ret->img = mlx_new_image(ret->mlx, DEFAUT_X, DEFAUT_Y);
	ret->pimg = mlx_get_data_addr(ret->img, &(ret->bpp),
			&(ret->size_line), &(ret->endian));
	ft_frct(ret);
	mlx_put_image_to_window(ret->mlx, ret->win, ret->img, 0, 0);
	mlx_destroy_image(ret->mlx, ret->img);
	return (0);
}
