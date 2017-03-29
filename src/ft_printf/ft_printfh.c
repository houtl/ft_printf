/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:33:31 by thou              #+#    #+#             */
/*   Updated: 2017/03/29 09:44:56 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printj(va_list arg, char c)
{
	if (c == 'x')
		return (ft_uimtoa_base((uintmax_t)va_arg(arg, unsigned int*), 16, 'x'));
	if (c == 'X')
		return (ft_uimtoa_base((uintmax_t)va_arg(arg, unsigned int*), 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_uimtoa_base((uintmax_t)va_arg(arg, unsigned int*), 8, 'x'));
	if (c == 'd' || c == 'D')
		return (ft_intmaxtoa_base((va_arg(arg, intmax_t)), 10, 'x'));
	return (NULL);
}

char		*ft_printh(va_list arg, t_h *h, char c)
{
	if (h->h == 1 || h->hh == 1 || h->l == 1 || h->ll == 1)
		return (ft_printhl(arg, h, c));
	if (h->j == 1)
		return (ft_printj(arg, c));
	return (NULL);
}
