/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 12:06:41 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 17:04:03 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nb, int fd)
{
	int unite;
	int dizaine;

	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		unite = nb % 10;
		dizaine = (nb - unite) / 10;
		ft_putnbr_fd(dizaine, fd);
		ft_putnbr_fd(unite, fd);
	}
	else
	{
		ft_putchar_fd(nb + 48, fd);
	}
}
