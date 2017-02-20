/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:21:12 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 15:24:01 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	handle_wchar(t_params *params, va_list *ap)
{
	wchar_t		c;
	int			c_len;

	c = va_arg(*ap, wchar_t);
	if (c <= 0x7F)
		c_len = 1;
	else if (c <= 0x7FF)
		c_len = 2;
	else if (c <= 0xFFFF)
		c_len = 3;
	else if (c <= 0x10FFFF)
		c_len = 4;
	else
		c_len = 0;
	if (params->got_width && !params->right_align)
		fill_width_with(c_len, params->width, params->left_align ? '0' : ' ');
	ft_putwchar(c);
	if (params->got_width && params->right_align)
		fill_width_with(c_len, params->width, params->left_align ? '0' : ' ');
	return (ft_max(params->width, c_len));
}
