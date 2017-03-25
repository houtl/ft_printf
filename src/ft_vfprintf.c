/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:02:10 by thou              #+#    #+#             */
/*   Updated: 2017/03/25 10:50:57 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printp(int *len, char *fmt, va_list arg)
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

	fmt = (char*)format;
	len = 0;
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
			fmt += ft_printp(&len, fmt, arg);
		}
	}
	return (len);
}
