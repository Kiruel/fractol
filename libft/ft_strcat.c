/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:13:19 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 16:51:46 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	int		j;

	i = ft_strlen((char*)s1);
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen((char*)s2)))
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = 0;
	return ((char*)s1);
}
