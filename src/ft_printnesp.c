/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnesp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:20:51 by thou              #+#    #+#             */
/*   Updated: 2017/03/25 18:25:43 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printnesp(t_h *h, char *str)
{
	int	i;
	int len;

	i = ft_strlen(str);
	len = i
	while (h->nb > i && h->moin != 1)
	{
		write(1, " ", 1);
		len++;
		h->nb--;
	}
	write(1, str, i);
	while (h->nb > i && h->moin == 1)
	{
		write(1, " ", 1);
		len++;
		h->nb--;
	}
	return (len);
}
