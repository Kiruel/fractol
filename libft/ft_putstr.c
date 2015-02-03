/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 12:12:04 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 17:01:55 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putstr(char const *str)
{
	if (str != 0)
	{
		while (*str != '\0')
		{
			ft_putchar(*str);
			str++;
		}
	}
}
