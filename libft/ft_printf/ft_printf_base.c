/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:39:58 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/25 12:46:53 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putbase(unsigned long int n, const char *base)
{
	int				i;
	unsigned int	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	i = 0;
	if (n >= len_base)
	{
		i += printf_putbase(n / len_base, base);
		i += printf_putbase(n % len_base, base);
	}
	else
		i += printf_putchr(base[n]);
	return (i);
}
