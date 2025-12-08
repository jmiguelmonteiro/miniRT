/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/11 11:31:14 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	len_s;
	size_t	len_result;

	len_s = ft_strlen(s);
	len_result = len_s - start;
	if (start >= len_s)
		len = 0;
	if (len_result > len)
		len_result = len;
	result = malloc((len_result + 1) * sizeof (*result));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len_result);
	result[len_result] = '\0';
	return (result);
}
