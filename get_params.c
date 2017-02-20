/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:41:04 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:44:59 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	params_bzero(t_params *params)
{
	params->one_space = 0;
	params->left_align = 0;
	params->right_align = 0;
	params->show_sign = 0;
	params->alt_input = 0;
	params->width = 0;
	params->precision = 0;
	params->got_width = 0;
	params->got_precision = 0;
	params->length = zero;
}

void	get_flags(t_params *params, const char *format, int *i)
{
	while (format[*i] == '0' || format[*i] == '#' || format[*i] == '-'
			|| format[*i] == '+' || format[*i] == ' ')
	{
		if (format[*i] == '0')
			params->left_align = 1;
		else if (format[*i] == '#')
			params->alt_input = 1;
		else if (format[*i] == '-')
			params->right_align = 1;
		else if (format[*i] == '+')
			params->show_sign = 1;
		else if (format[*i] == ' ')
			params->one_space = 1;
		(*i)++;
		if (params->right_align == 1)
			params->left_align = 0;
	}
}

void	get_width(t_params *params, const char *format, int *i, va_list *ap)
{
	int width;

	while (format[*i] == '*' || ft_isdigit(format[*i]))
	{
		if (format[*i] == '*')
		{
			(*i)++;
			width = va_arg(*ap, int);
			if (width < 0)
			{
				params->right_align = 1;
				width *= -1;
			}
			params->width = width;
		}
		if (ft_isdigit(format[*i]))
		{
			params->width = 0;
			while (ft_isdigit(format[*i]))
				params->width = params->width * 10 + format[(*i)++] - '0';
		}
		params->got_width = 1;
	}
}

void	get_precision(t_params *params, const char *format, int *i, va_list *ap)
{
	int prec;

	if (format[*i] == '.')
	{
		params->precision = 0;
		(*i)++;
		if (format[*i] == '*')
		{
			(*i)++;
			if ((prec = va_arg(*ap, int)) < 0 && !params->left_align)
				params->right_align = 1;
			if (prec >= 0)
			{
				params->precision = prec;
				params->got_precision = 1;
			}
		}
		else
		{
			while (ft_isdigit(format[*i]))
				params->precision = params->precision * 10
					+ format[(*i)++] - '0';
			params->got_precision = 1;
		}
	}
}

void	get_length(t_params *params, const char *format, int *i)
{
	if (format[*i] == 'h' && format[(*i) + 1] == 'h')
	{
		params->length = params->length < hh ? hh : params->length;
		(*i) += 2;
	}
	else if (format[*i] == 'l' && format[(*i) + 1] == 'l')
	{
		params->length = params->length < ll ? ll : params->length;
		(*i) += 2;
	}
	else if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j'
			|| format[*i] == 'z')
	{
		if (format[*i] == 'h')
			params->length = params->length < h ? h : params->length;
		else if (format[*i] == 'l')
			params->length = params->length < l ? l : params->length;
		else if (format[*i] == 'j')
			params->length = params->length < j ? j : params->length;
		else if (format[*i] == 'z')
			params->length = params->length < z ? z : params->length;
		(*i)++;
	}
}
