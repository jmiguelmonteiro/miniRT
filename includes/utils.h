/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:16:05 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:16:06 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"
# include "structs.h"
# include "mlx_inc.h"

t_scene	*init_scene(void);
bool	validate_scene(t_scene *scene);
void	free_scene2(t_scene *scene);
void	free_scene(t_scene *scene);
void	normalize_scene_tuples(t_scene *scene);
void	exit_minirt(int exit_code, t_scene *scene);

// Menu
void	start_menu(t_scene *scene);
void	render_menu(t_scene *scene);

#endif
