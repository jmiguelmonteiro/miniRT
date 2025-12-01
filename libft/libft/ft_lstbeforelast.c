/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbeforelast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:09:40 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/06 17:10:15 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*before_last;

	before_last = NULL;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		before_last = lst;
		lst = lst->next;
	}
	return (before_last);
}
