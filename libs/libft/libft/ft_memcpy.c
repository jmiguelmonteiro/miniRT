/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:01:37 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/05 16:21:50 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (const unsigned char *) src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}
