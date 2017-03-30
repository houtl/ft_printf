/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:25:54 by thou              #+#    #+#             */
/*   Updated: 2017/03/30 16:44:37 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(va_list arg, t_h *h, char c)
{
	char			c1;
	char			*str;

	if (h->l == 1 || c == 'C')
		return (ft_charlc(arg, h));
	else if (!(c1 = (char)va_arg(arg, int)))
	{
		h->len += 1;
		str = ft_strnew(0);
		if (h->nb > 0)
		{
			str = ft_printnesp(h, str);
			return (ft_strsub(str, 0, ft_strlen(str) - 1));
		}
	}
	else
		str = ft_strsub(&c1, 0, 1);
	return (ft_printnesp(h, str));
}

char	*ft_oct(va_list arg, t_h *h, char c)
{
	char			*dst;

	if (c == 'O')
		h->l = 1;
	dst = ft_strnew(0);
	h->isnb = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'o'));
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1)
		dst[0] = 0;
	if (h->ns == 1 && dst[0] != '0')
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	return (ft_printnesp(h, dst));
}

char	*ft_hex(va_list arg, t_h *h)
{
	char			*dst;

	dst = ft_strnew(0);
	h->isnb = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'x'));
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

	dst = ft_strnew(0);
	h->isnb = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'X'));
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1)
		dst[0] = 0;
	if (h->ns == 1 && dst[0] != '0' && dst[0] != 0)
		dst = ft_strjoinfree2(ft_strdup("0X"), dst);
	return (ft_printnesp(h, dst));
}

char	*ft_intdi(va_list arg, t_h *h, char c)
{
	char			*dst;

	dst = ft_strnew(0);
	h->isnb = 1;
	if (c == 'D')
		h->l = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'd'));
	while (dst[0] == '-' && (int)ft_strlen(dst) - 1 < h->ps)
	{
		dst[0] = '0';
		dst = ft_strjoinfree2(ft_strdup("-"), dst);
	}
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1 && dst[0] == '0')
		dst[0] = 0;
	if (h->plus == 1 && dst[0] != '-')
		dst = ft_strjoinfree2(ft_strdup("+"), dst);
	if (h->esp == 1 && dst[0] != '+' && dst[0] != '-')
		dst = ft_strjoinfree2(ft_strdup(" "), dst);
	return (ft_printnesp(h, dst));
}
