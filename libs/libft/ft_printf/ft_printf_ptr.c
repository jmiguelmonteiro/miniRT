/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:39:58 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/25 12:47:28 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putptr(unsigned long int ptr)
{
	int	i;

	if (ptr == 0)
		return (printf_putstr(PTRNULL));
	i = 0;
	i += printf_putstr("0x");
	i += printf_putbase((unsigned long int) ptr, "0123456789abcdef");
	return (i);
}
