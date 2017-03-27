/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:48:41 by thou              #+#    #+#             */
/*   Updated: 2017/03/27 15:15:01 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_handle
{
	int		len;
	int		l;
	int		ll;
	int		hh;
	int		h;
	int		j;
	int		z;
	int		esp;
	int		zero;
	int		plus;
	int		moin;
	int		ns;
	int		nb;
}				t_h;

int				ft_printf(const char *format, ...);
int				ft_vfprintf(char *format, va_list arg);
char			*ft_persent(t_h *h);
char			*ft_string(va_list arg, t_h *h);
char			*ft_wchar(va_list arg, t_h *h);
char			*ft_adresse(va_list arg, t_h *h);
char			*ft_printnesp(t_h *h, char *str);
char			*ft_hex(va_list arg, t_h *h);
char			*ft_hexup(va_list arg, t_h *h);

#endif
