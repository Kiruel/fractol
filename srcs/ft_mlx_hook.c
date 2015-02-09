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

void	ft_init_value(t_env *e)
{
	e->keycode = 0;
	e->ctr.x = DEFAUT_X / 2;
	e->ctr.y = DEFAUT_Y / 2;
	e->cRe = DEFAUT_CRE;
	e->cIm = DEFAUT_CIM;
	if (e->how_window == 1)
	{
		e->moveX = -0.5;
		e->moveY = 0;				
	}
	else if (e->how_window == 3)
	{
		e->moveX = 0.5;
		e->moveY = -0.5;			
	}
	else
	{
		e->moveX = 0;
		e->moveY = 0;
	}
	e->zoom = 0.8;
	e->iters = DEFAUT_MAXITER;
}

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
	ft_putnbr(e->cRe);
	ft_putstr("\n");
	ft_putstr("| Im : ");
	ft_putnbr(e->cIm);
	ft_putstr("\n");
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
	if (keycode == KEY_3_NUM || keycode == KEY_0)
		e->iters += 10;
	if (keycode == KEY_2_NUM || keycode == KEY_9)
		e->iters -= 10;
	expose_hook(e);
	// ft_putnbr(keycode);
	// ft_putchar('\n');
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
	if (keycode == KEY_4)
		e->how_window = 3;
	if (keycode == KEY_RIGHT)
		e->moveX -= (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_LEFT)
		e->moveX += (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_DOWN)
		e->moveY -= (SPEED_TRANSLATE / e->zoom);
	if (keycode == KEY_UP)
		e->moveY += (SPEED_TRANSLATE / e->zoom);
	ft_key_hook2(keycode, e);
	return (0);
}
