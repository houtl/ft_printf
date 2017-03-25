/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:48:41 by thou              #+#    #+#             */
/*   Updated: 2017/03/25 10:58:28 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>


int	ft_printf(const char *format, ...);
int	ft_vfprintf(const char *format, va_list arg);
int	ft_persent(int *len);
int	ft_string(int *len, va_list arg);
int	ft_wchar(int *len, va_list arg);
int	ft_adresse(int *len, va_list arg);

#endif
