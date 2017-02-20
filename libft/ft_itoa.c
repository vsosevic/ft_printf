/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:22:00 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/06 18:16:51 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dig_discharge(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		i = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*tmp_itoa(char *str, int nb)
{
	int		d;
	long	nbr;

	nbr = nb;
	if (nb < 0)
		nbr *= -1;
	d = dig_discharge(nb);
	str[d] = '\0';
	d--;
	while (nbr > 0)
	{
		str[d] = nbr % 10 + '0';
		d--;
		nbr = nbr / 10;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (dig_discharge(n) + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	tmp_itoa(str, n);
	return (str);
}
