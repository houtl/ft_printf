/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:25:54 by thou              #+#    #+#             */
/*   Updated: 2017/03/29 11:44:20 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(va_list arg, t_h *h)
{
	char			c;
	char			*str;

	if (!(c = (char)va_arg(arg, int)))
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
		str = ft_strsub(&c, 0, 1);
	return (ft_printnesp(h, str));
}

char	*ft_oct(va_list arg, t_h *h)
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(0);
	h->isnb = 1;
	if (h->ll == 1 || h->l == 1 || h->hh == 1 || h->h == 1 || h->j == 1)
		dst = ft_printh(arg, h, 'o');
	else
	{
		i = va_arg(arg, unsigned int);
		dst = ft_strjoinfree2(dst, ft_unsignedintoa_base(i, 8, 'x'));
	}
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
	if (h->ll == 1 || h->l == 1 || h->hh == 1 || h->h == 1 || h->j == 1)
		dst = ft_printh(arg, h, 'X');
	else
	{
		i = va_arg(arg, unsigned int);
		dst = ft_strjoinfree2(dst, ft_unsignedintoa_base(i, 16, 'X'));
	}
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1)
		dst[0] = 0;
	if (h->ns == 1 && dst[0] != '0' && dst[0] != 0)
		dst = ft_strjoinfree2(ft_strdup("0X"), dst);
	return (ft_printnesp(h, dst));
}

char	*ft_intdi(va_list arg, t_h *h)
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(0);
	h->isnb = 1;
	if (h->ll == 1 || h->l == 1 || h->hh == 1 || h->h == 1 || h->j == 1)
		dst = ft_printh(arg, h, 'd');
	else
	{
		i = va_arg(arg, unsigned int);
		dst = ft_strjoinfree2(dst, ft_itoa_base(i, 10, 'd'));
	}
	if (h->plus == 1 && dst[0] != '-')
		dst = ft_strjoinfree2(ft_strdup("+"), dst);
	if (h->esp == 1 && dst[0] != '+' && dst[0] != '-')
		dst = ft_strjoinfree2(ft_strdup(" "), dst);
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1)
		dst[0] = 0;
	return (ft_printnesp(h, dst));
}
