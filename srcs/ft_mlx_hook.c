/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:17:08 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/23 11:18:00 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_show_variable(t_env *e)
{
	ft_putstr("#------- VARIABLES ------#\n");
	ft_putstr("| iters : ");
	ft_putnbr(e->iters);
	ft_putstr("\n");
	ft_putstr("| zoom : ");
	ft_putnbr(e->zoom);
	ft_putstr("\n");
	ft_putstr("| Re : ");
	ft_putnbr(e->cre);
	ft_putstr("\n");
	ft_putstr("| Im : ");
	ft_putnbr(e->cim);
	ft_putstr("\n");
}

void	ft_key_hook4(int keycode, t_env *e)
{
	if (keycode == KEY_6_NUM)
	{
		if (e->rgb.b <= 0)
			e->rgb.b = 0;
		else
			e->rgb.b -= 0.1;
	}
	if (keycode == KEY_1_NUM)
		e->l -= 1;
	if (keycode == KEY_2_NUM)
		e->l += 1;
	if (keycode == KEY_STAR_NUM)
		e->freq += 1;
	if (keycode == KEY_SLACH_NUM)
		e->freq -= 1;
	if (keycode == KEY_4)
		e->how_window = 3;
	if (keycode == KEY_5)
		e->how_window = 4;
	e->event = 1;
}

void	ft_key_hook3(int keycode, t_env *e)
{
	if (keycode == KEY_9_NUM)
	{
		if (e->rgb.b > 1)
			e->rgb.b = 1;
		e->rgb.b += 0.1;
	}
	if (keycode == KEY_4_NUM)
	{
		if (e->rgb.r <= 0)
			e->rgb.r = 0;
		else
			e->rgb.r -= 0.1;
	}
	if (keycode == KEY_5_NUM)
	{
		if (e->rgb.g <= 0)
			e->rgb.g = 0;
		else
			e->rgb.g -= 0.1;
	}
	if (keycode == KEY_9)
		e->iters -= 10;
	ft_key_hook4(keycode, e);
}

void	ft_key_hook2(int keycode, t_env *e)
{
	if (keycode == KEY_MORE_NUM || keycode == KEY_MORE)
		e->zoom *= 1.5;
	if (keycode == KEY_M)
		e->keycode = keycode;
	else if (keycode == KEY_N)
		e->keycode = keycode;
	if (keycode == KEY_LESS_NUM || keycode == KEY_LESS)
		e->zoom /= 1.5;
	if (keycode == KEY_R)
		ft_init_value(e);
	if (keycode == KEY_0)
		e->iters += 10;
	if (keycode == KEY_7_NUM)
	{
		if (e->rgb.r > 1)
			e->rgb.r = 1;
		e->rgb.r += 0.1;
	}
	if (keycode == KEY_8_NUM)
	{
		if (e->rgb.g > 1)
			e->rgb.g = 1;
		e->rgb.g += 0.1;
	}
	ft_key_hook3(keycode, e);
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
		e->movex -= (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_LEFT)
		e->movex += (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_DOWN)
		e->movey -= (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_UP)
		e->movey += (SPEED_TRANSLATE / e->zoom);
	ft_key_hook2(keycode, e);
	return (0);
}
