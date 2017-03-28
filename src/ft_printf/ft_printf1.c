/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:25:54 by thou              #+#    #+#             */
/*   Updated: 2017/03/28 18:06:40 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(va_list arg, t_h *h)
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(0);
	h->isnb = 1;
	if (h->ll == 1 || h->l == 1 || h->hh == 1 || h->h == 1 || h->j == 1)
		dst = ft_printh(arg, h, 'x');
	else
	{
		i = va_arg(arg, unsigned int);
		dst = ft_strjoinfree2(dst, ft_unsignedintoa_base(i, 16, 'x'));
	}
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1)
		dst[0] = 0;
	if (h->ns == 1 && dst[0] != '0' && dst[0] != 0)
		dst = ft_strjoinfree2(ft_strdup("0x"), dst);
	return (ft_printnesp(h, dst));
}

char	*ft_hexup(va_list arg, t_h *h)
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(0);
	h->isnb = 1;
	if (h->ns == 1)
		dst = ft_strjoinfree(dst, "0X");
	if (h->ll == 1 || h->l == 1 || h->hh == 1 || h->h == 1 || h->j == 1)
		return (ft_printnesp(h, ft_strjoinfree2(dst, ft_printh(arg, h, 'X'))));
	i = va_arg(arg, unsigned int);
	dst = ft_strjoinfree2(dst, ft_unsignedintoa_base(i, 16, 'X'));
	return (ft_printnesp(h, dst));
}
