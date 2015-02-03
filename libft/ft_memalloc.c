/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:30:56 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 17:07:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s1;
	size_t	i;

	i = 0;
	s1 = malloc(size);
	if (!s1)
		return (0);
	while (i < size)
	{
		((char*)s1)[i] = 0;
		i++;
	}
	return (s1);
}
