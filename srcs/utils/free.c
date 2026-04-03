/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:12:19 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:12:20 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <structs.h>

void	free_ray(t_ray *ray)
{
	if (ray)
	{
		if (ray->origin)
			free(ray->origin);
		if (ray->direction)
			free(ray->direction);
		free(ray);
	}
}

void	free_hit(t_hit *hit)
{
	if (hit)
		free(hit);
}
