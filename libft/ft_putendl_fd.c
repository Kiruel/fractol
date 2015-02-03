/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:18:06 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 17:05:17 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putendl_fd(char const *str, int fd)
{
	if (str != 0)
		while (*str != '\0')
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	write(fd, "\n", 1);
}
