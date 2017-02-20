/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:17:42 by vsosevic          #+#    #+#             */
/*   Updated: 2017/02/20 16:34:44 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwchar(wchar_t c)
{
	char buff[5];

	(c < 0x80) ? write(1, &c, 1) : 0;
	if (c > 127 && c < 0x0800)
	{
		buff[0] = ((c >> 6) | 0xC0);
		buff[1] = ((c & 0x3F) | 0x80);
		write(1, buff, 2);
	}
	else if ((c > 0x07ff) && c < 0x10000)
	{
		buff[0] = ((c >> 12) | 0xE0);
		buff[1] = (((c >> 6) & 0x3F) | 0x80);
		buff[2] = ((c & 0x3F) | 0x80);
		write(1, buff, 3);
	}
	else if (c > 0xFFFF && c < 110000)
	{
		buff[0] = ((c >> 18)) | 0xF0;
		buff[1] = ((c >> 12) & 0x3F) | 0x80;
		buff[2] = ((c >> 6) & 0x3F) | 0x80;
		buff[3] = (c & 0x3F) | 0x80;
		write(1, buff, 4);
	}
}
