/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/09 18:40:20 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	cc;

	str = (char *) s;
	cc = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	if (cc == '\0')
		return (&str[i]);
	return (NULL);
}
