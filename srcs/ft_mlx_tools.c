/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 09:44:33 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/11 17:29:13 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int		color_scale_c(double d, double freq, double phase)
{
	return ((int)(127.5 * (1 - cos(freq * 2 * M_PI* (d + phase)))));
}

static int		color_scale(double d, t_env *e)
{
	int res;

	if (d < 0 || d > 1)
		return (0);
	res = 0;
	res += color_scale_c(d, e->freq, e->rgb.r);
	res = res << 8;
	res += color_scale_c(d, e->freq, e->rgb.g);
	res = res << 8;
	res += color_scale_c(d, e->freq, e->rgb.b);
	return (res);
}

int		ft_color(t_env *e)
{
	double d;

	d = ((double)e->i + 1.0 - log(log(sqrt(e->newRe * e->newRe + e->newIm * e->newIm))) / log(2));
	if (d <= 0)
		d = 0.1;
	if (d >= e->iters)
		return (0);
	d = ((int)d % 20) + (d - (int)d);
	d /= 20;
	return (color_scale(d, e));
}

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
	ret->img = mlx_new_image(ret->mlx, ret->default_x, ret->default_y);
	ret->pimg = mlx_get_data_addr(ret->img, &(ret->bpp),
			&(ret->size_line), &(ret->endian));
	ft_frct(ret);
	mlx_put_image_to_window(ret->mlx, ret->win, ret->img, 0, 0);
	mlx_destroy_image(ret->mlx, ret->img);
	return (0);
}
