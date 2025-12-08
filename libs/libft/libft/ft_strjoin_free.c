/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:52:17 by josemigu          #+#    #+#             */
/*   Updated: 2025/07/09 12:52:54 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief Concatenates s1 and s2 and frees s1
 *  @param s1 - string
 *  @param s2 - string
*/
char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_result = len_s1 + len_s2;
	result = malloc((len_result + 1) * sizeof (*result));
	if (!result)
		return (NULL);
	ft_memmove(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2);
	result[len_result] = '\0';
	free(s1);
	return (result);
}
