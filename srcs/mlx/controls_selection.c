/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniRT <miniRT@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by miniRT            #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by miniRT           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx_inc.h"

static int	count_objects(t_scene *scene)
{
	int			count;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	count = 2;
	sp = scene->spheres;
	while (sp)
	{
		count++;
		sp = sp->next;
	}
	pl = scene->planes;
	while (pl)
	{
		count++;
		pl = pl->next;
	}
	cy = scene->cylinders;
	while (cy)
	{
		count++;
		cy = cy->next;
	}
	return (count);
}

void	init_selection(t_scene *scene)
{
	scene->total_objects = count_objects(scene);
	scene->selected_idx = 0;
	scene->selected = &scene->camera;
	scene->selected_type = OBJ_CAMERA;
}

static void	print_selection(t_scene *scene)
{
	if (scene->selected_type == OBJ_CAMERA)
		printf("\r\033[K[%d/%d] Selected: Camera", scene->selected_idx + 1,
			scene->total_objects);
	else if (scene->selected_type == OBJ_LIGHT)
		printf("\r\033[K[%d/%d] Selected: Light", scene->selected_idx + 1,
			scene->total_objects);
	else if (scene->selected_type == OBJ_SPHERE)
		printf("\r\033[K[%d/%d] Selected: Sphere", scene->selected_idx + 1,
			scene->total_objects);
	else if (scene->selected_type == OBJ_PLANE)
		printf("\r\033[K[%d/%d] Selected: Plane", scene->selected_idx + 1,
			scene->total_objects);
	else if (scene->selected_type == OBJ_CYLINDER)
		printf("\r\033[K[%d/%d] Selected: Cylinder", scene->selected_idx + 1,
			scene->total_objects);
	fflush(stdout);
}

void	cycle_selection(t_scene *scene, int direction)
{
	scene->selected_idx += direction;
	if (scene->selected_idx < 0)
		scene->selected_idx = scene->total_objects - 1;
	else if (scene->selected_idx >= scene->total_objects)
		scene->selected_idx = 0;
	select_by_index(scene, scene->selected_idx);
	print_selection(scene);
}
