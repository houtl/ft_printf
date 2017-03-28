/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:25:54 by thou              #+#    #+#             */
/*   Updated: 2017/03/28 11:42:05 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(va_list arg, t_h *h)
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(0);
	if (h->ns == 1)
		dst = ft_strjoinfree(dst, "0x");
	if (h->ll == 1 || h->l == 1 || h->hh == 1 || h->h == 1)
		return (ft_printnesp(h, ft_strjoinfree2(dst, ft_printhl(arg, h, 'x'))));
	i = va_arg(arg, unsigned int);
	dst = ft_strjoinfree2(dst, ft_unsignedintoa_base(i, 16, 'x'));
	return (ft_printnesp(h, dst));
}

char	*ft_hexup(va_list arg, t_h *h)
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(0);
	if (h->ns == 1)
		dst = ft_strjoinfree(dst, "0X");
	i = va_arg(arg, unsigned int);
	dst = ft_strjoinfree2(dst, ft_unsignedintoa_base(i, 16, 'X'));
	return (ft_printnesp(h, dst));
}
