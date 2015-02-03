/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:15:17 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/11 16:50:22 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*new1;

	i = 0;
	new1 = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	if (!new1 || !s)
		return (0);
	while (s[i])
	{
		new1[i] = f(s[i]);
		i++;
	}
	new1[i] = '\0';
	return (new1);
}
