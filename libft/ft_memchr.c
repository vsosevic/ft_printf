/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:05:14 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/01 10:36:47 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = s;
	i = 0;
	while (n)
	{
		if (str[i] == (unsigned char)c)
		{
			return ((void *)(s + i));
			break ;
		}
		n--;
		i++;
	}
	return (NULL);
}
