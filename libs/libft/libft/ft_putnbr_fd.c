/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/15 22:55:19 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nn;

	if (fd == -1)
		return ;
	nn = n;
	if (nn < 0)
	{
		nn *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nn > 9)
	{
		ft_putnbr_fd(nn / 10, fd);
		ft_putnbr_fd(nn % 10, fd);
	}
	else
		ft_putchar_fd((char)(nn + 48), fd);
}
