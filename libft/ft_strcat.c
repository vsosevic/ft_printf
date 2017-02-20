/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:26:05 by vsosevic          #+#    #+#             */
/*   Updated: 2016/11/29 19:18:03 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char		*dest;
	const char	*src;
	int			i;
	int			l;

	i = 0;
	l = 0;
	dest = s1;
	src = s2;
	while (dest[l] != '\0')
		l++;
	while (src[i] != '\0')
	{
		dest[l] = src[i];
		i++;
		l++;
	}
	dest[l] = '\0';
	return (s1);
}
