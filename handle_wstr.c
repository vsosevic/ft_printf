/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:44:20 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:38:33 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	precision_for_wstr(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (precision_for_wstr(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (precision_for_wstr(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (precision_for_wstr(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (precision_for_wstr(str + 1, precision - 4, i + 4));
	else
		return (i);
}

static int		ft_wcharlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	else
		return (0);
}

static int		ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

static void		ft_putnwstr(wchar_t *str, int n)
{
	wchar_t	*tmp;
	int		i;

	tmp = (wchar_t*)str;
	i = ft_wcharlen(*tmp);
	while (n >= i)
	{
		i += ft_wcharlen(*tmp);
		ft_putwchar(*tmp);
		tmp++;
	}
}

int				handle_wstr(t_params *params, va_list *ap)
{
	wchar_t	*str;
	size_t	strlen;

	str = va_arg(*ap, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = params->got_precision ?
		precision_for_wstr(str, params->precision, 0) : ft_wstrlen(str);
	if (params->got_width && !params->right_align)
		fill_width_with(strlen, params->width, params->left_align ? '0' : ' ');
	ft_putnwstr(str, strlen);
	if (params->got_width && params->right_align)
		fill_width_with(strlen, params->width, ' ');
	return (ft_max(strlen, params->width));
}
