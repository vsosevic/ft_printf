/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:26:16 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/01 10:37:29 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	i = 0;
	while (n)
	{
		if (s[i] == (unsigned char)c)
		{
			d[i] = s[i];
			return (&dst[i + 1]);
			break ;
		}
		d[i] = s[i];
		n--;
		i++;
	}
	return (NULL);
}
