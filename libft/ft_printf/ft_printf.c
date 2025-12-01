/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:36:08 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/25 13:48:34 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_conversion(const char conversion_type, va_list args)
{
	int	nbytes;

	nbytes = 0;
	if (conversion_type == 'c')
		nbytes += printf_putchr(va_arg(args, int));
	else if (conversion_type == 's')
		nbytes += printf_putstr(va_arg(args, const char *));
	else if (conversion_type == 'p')
		nbytes += printf_putptr((unsigned long int)va_arg(args, void *));
	else if ((conversion_type == 'd') || (conversion_type == 'i'))
		nbytes += printf_putint(va_arg(args, int));
	else if (conversion_type == 'u')
		nbytes += printf_putbase(va_arg(args, unsigned int),
				"0123456789");
	else if (conversion_type == 'x')
		nbytes += printf_putbase(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (conversion_type == 'X')
		nbytes += printf_putbase(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (conversion_type == '%')
		nbytes += printf_putchr('%');
	return (nbytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nbytes;

	nbytes = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) != '\0')
			{
				nbytes += process_conversion(*(format + 1), args);
				format++;
			}
		}
		else
			nbytes += printf_putchr(*format);
		format++;
	}
	va_end(args);
	return (nbytes);
}
