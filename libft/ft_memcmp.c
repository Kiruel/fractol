/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:29:17 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/07 16:06:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	size_t			a;

	a = 0;
	i = (unsigned char*)s1;
	j = (unsigned char*)s2;
	while (a < n)
	{
		if (i[a] != j[a])
			return (i[a] - j[a]);
		a++;
	}
	return (0);
}
