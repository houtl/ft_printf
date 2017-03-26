/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:33:38 by thou              #+#    #+#             */
/*   Updated: 2017/03/25 18:26:54 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_persent(t_h *h)
{
	int				len;
	len = 1;
	while (h->nb > 1 && h->moin != 1)
	{
		write(1, " ", 1);
		len++;
		h->nb--;
	}
	write(1, "%", 1);
	while (h->nb > 1 && h->moin == 1)
	{
		write(1, " ", 1);
		len++;
		h->nb--;
	}
	return (len);
}

int ft_string(va_list arg, t_h *h)
{
	char			*str;
	int				len;

	str = va_arg(arg, char*);
	len = ft_printnesp(h, str);
	return (len);
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

int			ft_wchar(va_list arg, t_h *h)
{
	wchar_t			*w;
	unsigned char	*str;
	unsigned char	dst[1024];
	int				i;

	w = va_arg(arg, wchar_t*);
	str = dst;
	i = -1;
	while (w[++i])
	{
		*len += 1;
		if (wchar_to_char(&str, w[i]) == -1)
			return (1);
	}
	*str = 0;
	write(1, dst, ft_strlen((char*)dst));
	return (1);
}

int		ft_adresse(va_list arg, t_h *h)
{
	uintmax_t		addr;
	char			*str;

	addr = (uintmax_t)va_arg(arg, unsigned int*);
	write(1, "0x", 2);
	str = ft_uintmaxtoa_base(addr, 16, 'x');
	write(1, str, ft_strlen(str));
	*len += (ft_strlen(str) + 2);
	return (1);
}
