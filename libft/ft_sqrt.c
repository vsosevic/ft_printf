/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 17:34:09 by vsosevic          #+#    #+#             */
/*   Updated: 2016/10/29 18:23:56 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int b;

	i = 1;
	while (i * i <= nb)
	{
		b = i * i;
		i++;
	}
	if (b == nb)
		return (--i);
	else
		return (0);
}