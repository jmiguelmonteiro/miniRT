/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:39:58 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/23 17:55:27 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putstr(const char *str)
{
	int	i;

	if (str == NULL)
		return (printf_putstr(STRNULL));
	i = 0;
	while (*str)
	{
		i += printf_putchr(*str);
		str++;
	}
	return (i);
}
