/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 17:51:48 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/22 11:19:24 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;

	if (!s2 || !*s2 || !s1)
		return (0);
	while (*s1)
	{
		if (s2[i] == 0)
			return ((char*)s1);
		if (*s1 == *s2)
		{
			i = 0;
			while (s1[i] == s2[i])
			{
				i++;
				if (s2[i] == 0)
					return ((char*)s1);
			}
		}
		s1++;
	}
	return (0);
}
