/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:13:56 by thou              #+#    #+#             */
/*   Updated: 2017/03/30 17:20:22 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb(int value)
{
	int		i;

	i = 1;
	if (value < 0)
		i++;
	while (value / 10 != 0)
	{
		i++;
		value = value / 10;
	}
	return (i);
}

char		*ft_sctoa(signed char value)
{
	int		i;
	int		n;
	char	*c;
	char	*b;

	b = "0123456789";
	c = (char*)malloc(sizeof(char) * (ft_nb(value) + 1));
	if (!c)
		return (NULL);
	i = ft_nb(value);
	c[i--] = 0;
	n = value;
	if (value < 0)
	{
		n = -n;
		c[0] = '-';
	}
	while (n / 10 != 0)
	{
		c[i--] = *(b + (n % 10));
		n = n / 10;
	}
	c[i] = *(b + (n % 10));
	return (c);
}
