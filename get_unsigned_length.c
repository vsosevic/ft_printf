/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:57:07 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/16 14:48:33 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_unsigned_length(t_params *params, va_list *ap)
{
	uintmax_t nb;

	nb = va_arg(*ap, uintmax_t);
	if (params->length == zero)
		nb = (unsigned int)nb;
	else if (params->length == hh)
		nb = (unsigned char)nb;
	else if (params->length == h)
		nb = (unsigned short int)nb;
	else if (params->length == ll)
		nb = (unsigned long long int)nb;
	else if (params->length == l)
		nb = (unsigned long int)nb;
	else if (params->length == j)
		nb = (uintmax_t)nb;
	else if (params->length == z)
		nb = (size_t)nb;
	return (nb);
}
