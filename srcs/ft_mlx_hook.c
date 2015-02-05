/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:17:08 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/05 13:18:13 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		ft_show_variable(e);
	if (keycode == KEY_ECHAP)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	if (keycode == KEY_1)
		e->how_window = 0;
	if (keycode == KEY_2)
		e->how_window = 1;
	if (keycode == KEY_3)
		e->how_window = 2;
	if (keycode == KEY_RIGHT)
		e->moveX -= (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_LEFT)
		e->moveX += (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_DOWN)
		e->moveY -= (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_UP)
		e->moveY += (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_MORE_NUM || keycode == KEY_MORE)
		e->zoom *= 1.5;
	if (keycode == KEY_LESS_NUM || keycode == KEY_LESS)
		e->zoom /= 1.5;
	if (keycode == KEY_R)
		ft_init_value(e);
	if (keycode == KEY_3_NUM || keycode == KEY_0)
		e->maxIterations += 10;
	if (keycode == KEY_2_NUM || keycode == KEY_9)
		e->maxIterations -= 10;
	if (keycode == KEY_7)
		e->cRe += 0.02;
	if (keycode == KEY_8)
		e->cRe -= 0.02;
	if (keycode == KEY_5)
		e->cIm += 0.02;
	if (keycode == KEY_6)
		e->cIm -= 0.02;
	ft_update(e);
	// ft_putnbr(keycode);
	// ft_putchar('\n');
	return (0);
}
