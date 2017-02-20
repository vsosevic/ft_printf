/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:57:07 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:39:48 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_signed_length(t_params *params, va_list *ap)
{
	intmax_t nb;

	nb = va_arg(*ap, intmax_t);
	if (params->length == zero)
		nb = (int)nb;
	else if (params->length == hh)
		nb = (signed char)nb;
	else if (params->length == h)
		nb = (short int)nb;
	else if (params->length == ll)
		nb = (long long int)nb;
	else if (params->length == l)
		nb = (long int)nb;
	else if (params->length == j)
		nb = (intmax_t)nb;
	else if (params->length == z)
		nb = (size_t)nb;
	return (nb);
}

int				handle_int(t_params *params, va_list *ap, char conversion)
{
	intmax_t	nb;
	char		*prefix;

	if (params->got_precision == 1)
		params->left_align = 0;
	if (conversion == 'D')
		nb = va_arg(*ap, long int);
	else
		nb = get_signed_length(params, ap);
	prefix = "";
	if (nb < 0 || params->show_sign || params->one_space)
	{
		if (nb < 0)
		{
			nb *= -1;
			prefix = "-";
		}
		else if (params->show_sign)
			prefix = "+";
		else if (params->one_space)
			prefix = " ";
	}
	return (handle_unbr(nb, params, "0123456789", prefix));
}
