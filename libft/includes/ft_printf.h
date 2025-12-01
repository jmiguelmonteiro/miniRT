/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:35:50 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/25 13:41:29 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define PTRNULL "(nil)"
# define STRNULL "(null)"

int	ft_printf(const char *format, ...);
int	printf_putchr(const unsigned char c);
int	printf_putstr(const char *str);
int	printf_putbase(unsigned long int n, const char *base);
int	printf_putptr(unsigned long int ptr);
int	printf_putint(int d);

#endif
