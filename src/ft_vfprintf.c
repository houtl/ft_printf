/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:02:10 by thou              #+#    #+#             */
/*   Updated: 2017/03/25 18:11:01 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		input_handle(char *fmt, t_h *h)
{
	if (*fmt == 'l')
		(h->l == 1) ? (h->ll = 1) : (h->l = 1);
	else if (*fmt == 'h')
		(h->h == 1) ? (h->hh = 1) : (h->h = 1);
	else if (*fmt == 'j')
		h->j = 1;
	else if (*fmt == 'z')
		h->z = 1;
	else if (*fmt == ' ')
		h->esp = 1;
	else if (*fmt == '0')
		h->zero = 1;
	else if (*fmt == '+')
		h->plus = 1;
	else if (*fmt == '-')
		h->moin = 1;
	else if (*fmt == '#')
		h->ns = 1;
	else if (ft_isdigit(*fmt))
	{
		h->nb = ft_atoi(fmt);
		while (ft_isdigit(*(fmt + 1)))
			fmt++;
	}
}

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

static int	ft_printp(char *fmt, va_list arg, t_h *h)
{
	if (*fmt == '%')
		return (ft_persent(h));
	if (*fmt == 's')
		return (ft_string(arg, h));
	if (*fmt == 'S')
		return (ft_wchar(arg, h));
	if (*fmt == 'p')
		return (ft_adresse(arg, h));
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
	handle = "lhjz# 0123456789+-";
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			write(1, fmt++, 1);
			len++;
		}
		if (*fmt)
		{
			fmt++;
			while (ft_strchr(handle, *fmt))
				input_handle(fmt++, &h);
			len += ft_printp(fmt++, arg, &h);
			reset_handle(&h);
		}
	}
	return (len);
}
