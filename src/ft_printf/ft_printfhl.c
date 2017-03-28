/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:46:20 by thou              #+#    #+#             */
/*   Updated: 2017/03/28 13:18:43 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print_ll(va_list arg, char c)
{
	if (c == 'u' || c == 'U')
		return (ft_
	if (c == 'x')
		return (ft_lltoa_base((va_arg(arg, unsigned long long)), 16, 'x'));
	if (c == 'X')
		return (ft_lltoa_base((va_arg(arg, unsigned long long)), 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_lltoa_base((va_arg(arg, unsigned long long)), 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_lltoa_base((va_arg(arg, long long)), 10, 'x'));
	return (NULL);
}

static char *ft_print_l(va_list arg, char c)
{
	if (c == 'x')
		return (ft_ltoa_base((va_arg(arg, long)), 16, 'x'));
	if (c == 'X')
		return (ft_ltoa_base((va_arg(arg, long)), 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_ltoa_base((va_arg(arg, long)), 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_ltoa_base((va_arg(arg, long)), 10, 'x'));
	return (NULL);
}

static char *ft_print_h(va_list arg, char c)
{
	if (c == 'x')
		return (ft_itoa_base(((short)va_arg(arg, int)), 16, 'x'));
	if (c == 'X')
		return (ft_itoa_base(((short)va_arg(arg, int)), 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_itoa_base(((short)va_arg(arg, int)), 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_itoa_base(((short)va_arg(arg, int)), 10, 'x'));
	return (NULL);
}

static char *ft_print_hh(va_list arg, char c)
{
	if (c == 'x')
		return (ft_itoa_base(((char)va_arg(arg, int)), 16, 'x'));
	if (c == 'X')
		return (ft_itoa_base(((char)va_arg(arg, int)), 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_itoa_base(((char)va_arg(arg, int)), 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_itoa_base(((char)va_arg(arg, int)), 10, 'x'));
	return (NULL);
}

char		*ft_printhl(va_list arg, t_h *h, char c)
{
	if (h->ll == 1)
		return (ft_print_ll(arg, c));
	else if (h->l == 1)
		return (ft_print_l(arg, c));
	else if (h->h == 1)
		return (ft_print_h(arg, c));
	else
		return (ft_print_hh(arg, c));
}
