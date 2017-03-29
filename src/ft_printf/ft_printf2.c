/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:04:51 by thou              #+#    #+#             */
/*   Updated: 2017/03/29 13:12:27 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsignedint(va_list arg, t_h *h)
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(0);
	h->isnb = 1;
	if (h->ll == 1 || h->l == 1 || h->hh == 1 || h->h == 1 || h->j == 1)
		dst = ft_printh(arg, h, 'u');
	else
	{
		i = va_arg(arg, unsigned int);
		dst = ft_strjoinfree2(dst, ft_unsignedintoa_base(i, 10, 'x'));
	}
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1)
		dst[0] = 0;
	return (ft_printnesp(h, dst));
}
