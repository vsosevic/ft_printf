/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:37:26 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:39:32 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(t_params *params, va_list *ap, char conversion)
{
	short int	char_len;
	char		c;

	if (conversion == 'c' && params->length == l)
		return (handle_wchar(params, ap));
	else if (conversion == 'c')
		c = va_arg(*ap, int);
	else
		c = conversion;
	if (params->got_width && params->width > 1 && !params->right_align)
	{
		if (params->left_align)
			fill_width_with(1, params->width, '0');
		else
			fill_width_with(1, params->width, ' ');
	}
	ft_putchar(c);
	if (params->right_align && params->width > 1)
		fill_width_with(1, params->width, ' ');
	return (ft_max(params->width, 1));
}
