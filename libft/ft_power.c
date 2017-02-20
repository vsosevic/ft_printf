/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:01:00 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/07 18:01:18 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	int answer;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	answer = nb * ft_power(nb, power - 1);
	return (answer);
}
