/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:09:18 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:46:05 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_uint(t_params *params, va_list *ap, char conversion)
{
	uintmax_t	nb;

	if (conversion == 'U')
		nb = va_arg(*ap, unsigned long);
	else
		nb = get_unsigned_length(params, ap);
	return (handle_unbr(nb, params, "0123456789", ""));
}
