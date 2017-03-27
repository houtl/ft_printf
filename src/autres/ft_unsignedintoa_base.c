/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedintoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:55:49 by thou              #+#    #+#             */
/*   Updated: 2017/03/27 15:22:56 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_base(unsigned int  value, int base)
{
	int			i;

	i = 1;
	while (value / base != 0)
	{
		i++;
		value = value / base;
	}
	return (i);
}

char		*ft_unsignedintoa_base(unsigned int value, int base, char x)
{
	int				i;
	unsigned int	n;
	char			*c;
	char			*b;

	b = ((x == 'x') ? "0123456789abcdef" : "0123456789ABCDEF");
	c = (char*)malloc(sizeof(char) * (ft_nb_base(value, base) + 1));
	if (!c)
		return (NULL);
	i = ft_nb_base(value, base);
	c[i--] = 0;
	n = value;
	while (n / base != 0)
	{
		c[i--] = *(b + (n % base));
		n = n / base;
	}
	c[i] = *(b + (n % base));
	return (c);
}
