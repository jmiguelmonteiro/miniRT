/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/11 11:44:50 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	cc;

	str = (char *) s;
	cc = (char) c;
	len = ft_strlen(str);
	if (cc == '\0')
		return (&str[len]);
	while (len > 0)
	{
		if (str[len - 1] == cc)
			return (&str[len - 1]);
		len--;
	}
	return (NULL);
}
