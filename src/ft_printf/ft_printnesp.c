/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnesp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:20:51 by thou              #+#    #+#             */
/*   Updated: 2017/03/26 18:38:33 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printnesp(t_h *h, char *str)
{
	int	i;

	i = ft_strlen(str);
	while (h->nb > i && h->moin != 1)
	{
		str = ft_strjoinfree2(ft_strdup(" "), str);
		h->nb--;
	}
	while (h->nb > i && h->moin == 1)
	{
		str = ft_strjoinfree2(str, ft_strdup(" "));
		h->nb--;
	}
	return (str);
}
