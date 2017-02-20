/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width_with.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:13:06 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/15 17:27:34 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_width_with(int nblen, int width, char c)
{
	while (nblen < width)
	{
		ft_putchar(c);
		nblen++;
	}
}
