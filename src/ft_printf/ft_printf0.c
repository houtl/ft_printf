/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:33:38 by thou              #+#    #+#             */
/*   Updated: 2017/03/27 13:55:22 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_persent(t_h *h)
{
	char			*dst;

	dst = ft_strdup("%");
	while (h->nb > 1 && h->moin != 1)
	{
		dst = ft_strjoinfree2(ft_strdup(" "), dst);
		h->nb--;
	}
	while (h->nb > 1 && h->moin == 1)
	{
		dst = ft_strjoinfree(dst, " ");
		h->nb--;
	}
	return (dst);
}

char		*ft_string(va_list arg, t_h *h)
{
	char			*str;

	str = ft_strdup(va_arg(arg, char*));
	return (ft_printnesp(h, str));
}

static int	wchar_to_char(unsigned char **s, wchar_t c)
{
	if (c < (1 << 7))
		*(*s)++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*(*s)++ = (unsigned char)((c >> 6) | 0xC0);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*(*s)++ = (unsigned char)(((c >> 12)) | 0xE0);
		*(*s)++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*(*s)++ = (unsigned char)(((c >> 18)) | 0xF0);
		*(*s)++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else
		return (-1);
	return (0);
}

char		*ft_wchar(va_list arg, t_h *h)
{
	wchar_t			*w;
	unsigned char	*str;
	unsigned char	dst[1024];
	int				i;

	w = va_arg(arg, wchar_t*);
	str = dst;
	i = -1;
	while (w[++i])
		if (wchar_to_char(&str, w[i]) == -1)
			return (ft_strnew(0));
	*str = 0;
	return (ft_printnesp(h, ft_strdup((char*)dst)));
}

char		*ft_adresse(va_list arg, t_h *h)
{
	uintmax_t		addr;
	char			*str;

	addr = (uintmax_t)va_arg(arg, unsigned int*);
	str = ft_strjoinfree(ft_strdup("0x"), ft_uintmaxtoa_base(addr, 16, 'x'));
	return (ft_printnesp(h, str));
}
