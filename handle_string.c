/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:14:29 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:46:43 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(t_params *params, va_list *ap, char conversion)
{
	int		str_len;
	char	*str;

	if (conversion == 'S' || (conversion == 's' && params->length == l))
		return (handle_wstr(params, ap));
	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	str_len = params->got_precision ?
		ft_min(params->precision, ft_strlen(str)) : ft_strlen(str);
	if (params->got_width && params->width > str_len && !params->right_align)
	{
		if (params->left_align)
			fill_width_with(str_len, params->width, '0');
		else
			fill_width_with(str_len, params->width, ' ');
	}
	ft_putnstr(str, str_len);
	if (params->right_align && params->width > str_len)
		fill_width_with(str_len, params->width, ' ');
	return (ft_max(params->width, str_len));
}
