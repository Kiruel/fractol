/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:04:08 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 16:40:34 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int i;

	i = (int)ft_strlen((char*)s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	return (0);
}
