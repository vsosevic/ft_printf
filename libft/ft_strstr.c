/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:40:15 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/01 13:07:05 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	first;

	i = 0;
	while (big[i] != '\0')
	{
		first = 0;
		while (little[first] == big[i + first] && little[first] != '\0')
			first++;
		if (little[first] == '\0')
			return ((char *)(big + i));
		i++;
	}
	if (big[0] == '\0' && little[0] == '\0')
		return ((char *)big);
	return (NULL);
}
