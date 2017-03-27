/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:46:20 by thou              #+#    #+#             */
/*   Updated: 2017/03/27 18:17:31 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printll(va_list arg, t_h *h, char c)
{
	if (c == 'x')
		return (ft_longlongtoa_base((va_arg(arg, long long)), 16, 'x'));
	if (c == 'X')
		return (ft_longlongtoa_base((va_arg(arg, long long)), 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_longlongtoa_base((va_arg(arg, long long)), 8, 'o'));
	if (c == 'd' || c == 'D')
		return (ft_longlongtoa_base((va_arg(arg, long long)), 10, 'x'));
	return (NULL);
}

static char *ft_printl(va_list arg, t_h *h, char c)
{
	if (c == 'x')
		return (ft_longtoa_base((va_arg(arg, long)), 16, 'x'));
	if (c == 'X')
		return (ft_longtoa_base((va_arg(arg, long)), 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_longtoa_base((va_arg(arg, long)), 8, 'o'));
	if (c == 'd' || c == 'D')
		return (ft_longtoa_base((va_arg(arg, long)), 10, 'x'));
	return (NULL);
}

char		*ft_printhl(va_list arg, t_h *h, char c)
{
	if (h->ll == 1)
		return (ft_printll(arg, h, c));
	else if (h->l == 1)
		return (ft_printl(arg, h, c));
	else if (h->h == 1)
		return (ft_printh(arg, h, c));
	else
		return (ft_printhh(arg, h, c));
}
