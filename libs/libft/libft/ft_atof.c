/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:45:42 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/20 14:56:22 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_space_sign(const char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(const char *nptr)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(nptr, &is_neg);
	while (nptr[i] && ft_isdigit(nptr[i]) && nptr[i] != '.')
	{
		nb = (nb * 10.0) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		nb = nb + ((nptr[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (nb * is_neg);
}
