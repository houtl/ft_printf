/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:02:10 by thou              #+#    #+#             */
/*   Updated: 2017/03/25 13:38:33 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_handle(t_h *h)
{
	h->l = 0;
	h->ll = 0;
	h->hh = 0;
	h->h = 0;
	h->j = 0;
	h->z = 0;
	h->esp = 0;
	h->zero =  0;
	h->plus = 0;
	h->moin = 0;
	h->ns = 0;
}

static int	ft_printp(int *len, char *fmt, va_list arg, t_h *h)
{
	if (*fmt == '%')
		return (ft_persent(len));
	if (*fmt == 's')
		return (ft_string(len, arg));
	if (*fmt == 'S')
		return (ft_wchar(len, arg));
	if (*fmt == 'p')
		return (ft_adresse(len, arg));
	return (0);
}

int	ft_vfprintf(const char *format, va_list arg)
{
	char	*fmt;
	int		len;
	char	*handle;
	t_h		h;

	fmt = (char*)format;
	len = 0;
	handle = "lhjz# 0123456789+-"
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			write(1, fmt++, 1);
			len++;
		}
		while (ft_strcat(handle, *fmt))
			input_handle(*(fmt++, &h));
		if (*fmt)
		{
			fmt++;
			while (ft_strcat(handle, *fmt))
				input_handle(*(fmt++, &h));
			fmt += ft_printp(&len, fmt, arg, &h);
			reset_handle(&h);
		}
	}
	return (len);
}
