/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:13:58 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/01 13:25:15 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	first;

	i = 0;
	while (big[i] != '\0')
	{
		first = 0;
		while (little[first] == big[i + first] && little[first] != '\0'
				&& first + i < len)
			first++;
		if (little[first] == '\0')
			return ((char *)(big + i));
		i++;
	}
	if (big[0] == '\0' && little[0] == '\0')
		return ((char *)big);
	return (NULL);
}
