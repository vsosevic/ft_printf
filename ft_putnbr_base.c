/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:39:50 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:43:39 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	nb_len(uintmax_t nb, char *str_base)
{
	unsigned char i;
	unsigned char base;

	base = ft_strlen(str_base);
	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

void			ft_putnbr_base_unsigned(uintmax_t nb, char *str_base)
{
	short int	base;
	char		str[22];
	short int	i;

	i = 0;
	base = ft_strlen(str_base);
	while (nb / base > 0)
	{
		str[i++] = str_base[nb % base];
		nb = nb / base;
	}
	str[i++] = str_base[nb % base];
	while (--i >= 0)
		ft_putchar(str[i]);
}
