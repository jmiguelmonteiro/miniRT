/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:12:33 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:12:34 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_minirt(int exit_code, t_scene *scene)
{
	if (!scene)
		exit(exit_code);
	free_mlx(scene);
	free_scene(scene);
	exit(exit_code);
}
