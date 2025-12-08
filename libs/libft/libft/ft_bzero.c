/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:01:37 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/05 16:37:31 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Writes n bytes of null into a string
 *  @param s - string
 *  @param n - len of bytes
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
