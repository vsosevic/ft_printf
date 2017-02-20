/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:11:39 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:45:37 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_octal(t_params *params, va_list *ap, char conversion)
{
	uintmax_t	nb;

	if (conversion == 'O')
		nb = va_arg(*ap, unsigned long);
	else
		nb = get_unsigned_length(params, ap);
	if (nb == 0 && params->alt_input)
		return (ft_pf_putchar('0'));
	if (params->alt_input && params->precision == 0)
		return (handle_unbr(nb, params, "01234567", "0"));
	return (handle_unbr(nb, params, "01234567", ""));
}

int	handle_binary(t_params *params, va_list *ap)
{
	uintmax_t	nb;

	nb = get_unsigned_length(params, ap);
	return (handle_unbr(nb, params, "01", ""));
}
