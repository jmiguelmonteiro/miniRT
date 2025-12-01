/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/12 11:05:29 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	str = (char *) s1;
	if (!*str || !*set)
		return (ft_strdup(str));
	end = ft_strlen(str);
	while (str[end - 1] && ft_strrchr(set, str[end - 1]))
		end--;
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	return (ft_substr(str, start, end - start));
}
