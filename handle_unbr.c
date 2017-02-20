/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:57:07 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 17:50:46 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	inner_if_got_width(t_params *params, short int out_len, char **prefix)
{
	if (params->left_align)
	{
		ft_putstr(*prefix);
		fill_width_with(out_len, params->width, '0');
		*prefix = "";
	}
	else
		fill_width_with(out_len, params->width, ' ');
}

int		handle_unbr(uintmax_t nb, t_params *params, char *str_base,
						char *prefix)
{
	short int out_len;
	short int nbr_len;

	if (params->got_precision == 1)
		params->left_align = 0;
	nbr_len = nb_len(nb, str_base);
	out_len = ft_strlen(prefix) + ft_max(nbr_len, params->precision);
	if (nb == 0 && params->got_precision && params->precision == 0)
		out_len = 0;
	if (params->got_width && params->width > out_len && !params->right_align)
		inner_if_got_width(params, out_len, &prefix);
	if (nb == 0 && params->got_precision && params->precision == 0)
		return (params->width);
	ft_putstr(prefix);
	fill_width_with(nbr_len, params->precision, '0');
	ft_putnbr_base_unsigned(nb, str_base);
	if (params->right_align && params->width > out_len)
		fill_width_with(out_len, params->width, ' ');
	return (ft_max(params->width, out_len));
}
