/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:23:58 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:00 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr(char **str)
{
	int i;

	if (!str)
		ft_putstr("array is empty\n");
	i = 0;
	while (str[i] != '\0')
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}
