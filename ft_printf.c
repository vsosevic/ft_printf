/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:47:58 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 17:50:41 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#define IS_DIGIT ft_isdigit(format[i])

static int	conversion_handler(t_params *params, const char *format, int *i,
		va_list *ap)
{
	int ret;

	if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'D')
		ret = handle_int(params, ap, format[*i]);
	else if (format[*i] == 'u' || format[*i] == 'U')
		ret = handle_uint(params, ap, format[*i]);
	else if (format[*i] == 'o' || format[*i] == 'O')
		ret = handle_octal(params, ap, format[*i]);
	else if (format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'p')
		ret = handle_hex(params, ap, format[*i]);
	else if (format[*i] == 's' || format[*i] == 'S')
		ret = handle_string(params, ap, format[*i]);
	else if (format[*i] == 'c' || format[*i] == '%')
		ret = handle_char(params, ap, format[*i]);
	else if (format[*i] == 'b')
		ret = handle_binary(params, ap);
	else if (format[*i] == 'C')
		ret = handle_wchar(params, ap);
	else
		ret = handle_char(params, ap, format[*i]);
	return (ret);
}

int			internal_printf(const char *format, va_list *ap, t_params *params,
								int chrs_prntd)
{
	int			i;

	i = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			chrs_prntd += ft_pf_putchar(format[i++]);
		if (format[i++] == '\0')
			break ;
		params_bzero(params);
		while (ft_strrchr("sSpdDioOuUxXcC\0", format[i]) == NULL)
		{
			get_flags(params, format, &i);
			get_width(params, format, &i, ap);
			get_precision(params, format, &i, ap);
			get_length(params, format, &i);
			if (ft_strrchr("#-+ .*hljz", format[i]) == NULL && !IS_DIGIT)
				break ;
		}
		if (format[i] == '\0')
			break ;
		chrs_prntd += conversion_handler(params, format, &i, ap);
		i++;
	}
	return (chrs_prntd);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	va_start(ap, format);
	ret = internal_printf(format, &ap, params, 0);
	va_end(ap);
	free(params);
	return (ret);
}
