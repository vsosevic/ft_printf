/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:31:29 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:41:43 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_params
{
	int			one_space;
	int			left_align;
	int			right_align;
	int			show_sign;
	int			alt_input;
	int			width;
	int			precision;
	int			got_width;
	int			got_precision;
	enum
	{
		zero, hh, h, l, ll, z, j
	}			length;

}				t_params;

void			get_flags(t_params *params, const char *format, int *i);
void			params_bzero(t_params *params);
void			get_width(t_params *params, const char *format, int *i,
		va_list *ap);
void			get_precision(t_params *params, const char *format, int *i,
		va_list *ap);
void			get_length(t_params *params, const char *format, int *i);
int				ft_pf_putchar(char c);
int				ft_pf_putstr(char *s);
void			ft_putnstr(char *s, int n);
int				handle_int(t_params *params, va_list *ap, char conversion);
void			ft_putnbr_base_unsigned(uintmax_t nb, char *str_base);
unsigned int	nb_len(uintmax_t nb, char *str_base);
void			fill_width_with(int nblen, int width, char c);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				handle_unbr(uintmax_t nb, t_params *params, char *str_base,
								char *prefix);
int				handle_uint(t_params *params, va_list *ap, char conversion);
uintmax_t		get_unsigned_length(t_params *params, va_list *ap);
int				handle_octal(t_params *params, va_list *ap, char conversion);
int				handle_hex(t_params *params, va_list *ap, char conversion);
int				handle_string(t_params *params, va_list *ap, char conversion);
int				handle_char(t_params *params, va_list *ap, char conversion);
int				handle_binary(t_params *params, va_list *ap);
int				handle_pointer(t_params *params, va_list *ap);
void			ft_putwchar(wchar_t c);
int				handle_wchar(t_params *params, va_list *ap);
int				handle_wstr(t_params *params, va_list *ap);

#endif
