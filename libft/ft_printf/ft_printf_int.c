/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:39:58 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/25 12:48:14 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putint(int d)
{
	int			i;
	long int	dd;

	i = 0;
	dd = d;
	if (dd < 0)
	{
		i += printf_putchr('-');
		dd *= -1;
	}
	i += printf_putbase((unsigned long int) dd, "0123456789");
	return (i);
}
