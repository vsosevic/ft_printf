/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:25:41 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/01 10:34:45 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;
	int			l;

	i = 0;
	l = 0;
	dest = s1;
	src = s2;
	while (dest[l] != '\0')
		l++;
	while (src[i] != '\0' && i < n)
	{
		dest[l] = src[i];
		i++;
		l++;
	}
	dest[l] = '\0';
	return (s1);
}
