/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:31:56 by vsosevic          #+#    #+#             */
/*   Updated: 2016/11/29 15:38:20 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*str;

	l = 0;
	while (s1[l] != '\0')
		l++;
	str = (char *)malloc(sizeof(*str) * (l + 1));
	if (str == NULL)
		return (NULL);
	l = 0;
	while (s1[l] != '\0')
	{
		str[l] = s1[l];
		l++;
	}
	str[l] = '\0';
	return (str);
}
