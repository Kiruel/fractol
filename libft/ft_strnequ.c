/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:23:40 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 16:44:19 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!(s1 && s2))
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		if (!s1[i] && !s2[i])
			return (1);
		i++;
	}
	return (1);
}
