/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:17:54 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/14 11:15:16 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putendl(char const *str)
{
	if (str != 0)
		while (*str != '\0')
		{
			ft_putchar(*str);
			str++;
		}
	write(1, "\n", 1);
}
