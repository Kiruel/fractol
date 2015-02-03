/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:58:39 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/10 17:58:48 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c > 64 && c < 91)
		return (c);
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}
