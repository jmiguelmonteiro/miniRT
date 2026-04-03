/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:14:01 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:14:02 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "utils.h"

int	handle_close(t_scene *scene)
{
	exit_minirt(EXIT_SUCCESS, scene);
	return (EXIT_SUCCESS);
}
