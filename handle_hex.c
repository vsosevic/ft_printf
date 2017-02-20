/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:50:15 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:39:19 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex(t_params *params, va_list *ap, char conversion)
{
	uintmax_t	nb;

	if (conversion == 'p')
		return (handle_pointer(params, ap));
	nb = get_unsigned_length(params, ap);
	if (params->alt_input)
	{
		if (nb == 0 && !params->got_precision)
			return (ft_pf_putchar('0'));
		if (conversion == 'X')
			return (handle_unbr(nb, params, "0123456789ABCDEF", "0X"));
		else if (conversion == 'x')
			return (handle_unbr(nb, params, "0123456789abcdef", "0x"));
	}
	if (conversion == 'X')
		return (handle_unbr(nb, params, "0123456789ABCDEF", ""));
	else
		return (handle_unbr(nb, params, "0123456789abcdef", ""));
}

int	handle_pointer(t_params *params, va_list *ap)
{
	uintmax_t	nb;

	nb = va_arg(*ap, uintmax_t);
	nb = (unsigned long int)nb;
	if (nb == 0 && params->got_precision && params->precision == 0)
		return (ft_pf_putstr("0x"));
	if (params->got_precision)
		params->left_align = 0;
	return (handle_unbr(nb, params, "0123456789abcdef", "0x"));
}
