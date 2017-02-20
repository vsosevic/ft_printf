/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:51:35 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/01 12:07:06 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	ls1;
	size_t	i;

	ls1 = 0;
	i = 0;
	while (s1[ls1] != '\0')
		ls1++;
	while (s2[i] != '\0' && (ls1 + i + 1 < size))
	{
		s1[ls1 + i] = s2[i];
		i++;
	}
	s1[ls1 + i] = '\0';
	while (s2[i] != '\0')
		i++;
	if (ls1 > size)
		ls1 = size;
	return (ls1 + i);
}
