/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_selection2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniRT <miniRT@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by miniRT            #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by miniRT           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx_inc.h"

static void	select_camera_or_light(t_scene *scene, int idx, int *i)
{
	if (idx == (*i)++)
	{
		scene->selected = &scene->camera;
		scene->selected_type = OBJ_CAMERA;
	}
	else if (idx == (*i)++)
	{
		scene->selected = &scene->light;
		scene->selected_type = OBJ_LIGHT;
	}
}

static void	select_sphere(t_scene *scene, int idx, int *i)
{
	t_sphere	*sp;

	sp = scene->spheres;
	while (sp)
	{
		if (idx == (*i)++)
		{
			scene->selected = sp;
			scene->selected_type = OBJ_SPHERE;
			return ;
		}
		sp = sp->next;
	}
}

static void	select_plane(t_scene *scene, int idx, int *i)
{
	t_plane	*pl;

	pl = scene->planes;
	while (pl)
	{
		if (idx == (*i)++)
		{
			scene->selected = pl;
			scene->selected_type = OBJ_PLANE;
			return ;
		}
		pl = pl->next;
	}
}

static void	select_cylinder(t_scene *scene, int idx, int *i)
{
	t_cylinder	*cy;

	cy = scene->cylinders;
	while (cy)
	{
		if (idx == (*i)++)
		{
			scene->selected = cy;
			scene->selected_type = OBJ_CYLINDER;
			return ;
		}
		cy = cy->next;
	}
}

void	select_by_index(t_scene *scene, int idx)
{
	int	i;

	i = 0;
	scene->selected_type = -1;
	select_camera_or_light(scene, idx, &i);
	if (scene->selected_type == -1)
		select_sphere(scene, idx, &i);
	if (scene->selected_type == -1)
		select_plane(scene, idx, &i);
	if (scene->selected_type == -1)
		select_cylinder(scene, idx, &i);
}
