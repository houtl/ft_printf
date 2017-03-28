/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnesp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:20:51 by thou              #+#    #+#             */
/*   Updated: 2017/03/28 18:11:52 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_changxo(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 'x')
		i++;
	if (str[i] == 0)
		return (str);
	else if (i > 1 && str[0] == '0')
	{
		str[1] = 'x';
		str[i] = '0';
	}
	return (str);
}

char	*ft_printnesp(t_h *h, char *str)
{
	int	i;

	i = ft_strlen(str);
	while (h->nb > i && h->moin != 1)
	{
		if (h->zero == 1 && h->isnb == 1)
			str = ft_strjoinfree2(ft_strdup("0"), str);
		else
			str = ft_strjoinfree2(ft_strdup(" "), str);
		h->nb--;
	}
	while (h->nb > i && h->moin == 1)
	{
		str = ft_strjoinfree2(str, ft_strdup(" "));
		h->nb--;
	}
	if (h->isnb == 1)
		str = ft_changxo(str);
	return (str);
}
