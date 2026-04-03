/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by miniRT            #+#    #+#             */
/*   Updated: 2026/04/03 13:13:52 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx_inc.h"
#include "algebraOperations.h"

static void	translate_object(t_scene *scene, double dx, double dy, double dz)
{
	if (scene->selected_type == OBJ_CAMERA)
	{
		scene->camera.position.x += dx;
		scene->camera.position.y += dy;
		scene->camera.position.z += dz;
	}
	else if (scene->selected_type == OBJ_LIGHT)
	{
		scene->light.position.x += dx;
		scene->light.position.y += dy;
		scene->light.position.z += dz;
	}
	else if (scene->selected_type == OBJ_SPHERE)
	{
		((t_sphere *)scene->selected)->center.x += dx;
		((t_sphere *)scene->selected)->center.y += dy;
		((t_sphere *)scene->selected)->center.z += dz;
		rebuild_sphere_transform((t_sphere *)scene->selected);
	}
}

static void	translate_plane_cyl(t_scene *scene, double dx, double dy, double dz)
{
	if (scene->selected_type == OBJ_PLANE)
	{
		((t_plane *)scene->selected)->point.x += dx;
		((t_plane *)scene->selected)->point.y += dy;
		((t_plane *)scene->selected)->point.z += dz;
		rebuild_plane_transform((t_plane *)scene->selected);
	}
	else if (scene->selected_type == OBJ_CYLINDER)
	{
		((t_cylinder *)scene->selected)->center.x += dx;
		((t_cylinder *)scene->selected)->center.y += dy;
		((t_cylinder *)scene->selected)->center.z += dz;
		rebuild_cylinder_transform((t_cylinder *)scene->selected);
	}
}

void	handle_translate(t_scene *scene, int keysym)
{
	double	step;

	step = 1.0;
	if (keysym == XK_w)
		translate_object(scene, 0, 0, -step);
	else if (keysym == XK_s)
		translate_object(scene, 0, 0, step);
	else if (keysym == XK_a)
		translate_object(scene, -step, 0, 0);
	else if (keysym == XK_d)
		translate_object(scene, step, 0, 0);
	else if (keysym == XK_r)
		translate_object(scene, 0, step, 0);
	else if (keysym == XK_f)
		translate_object(scene, 0, -step, 0);
	if (keysym == XK_w || keysym == XK_s)
		translate_plane_cyl(scene, 0, 0, (keysym == XK_w) * -step
			+ (keysym == XK_s) * step);
	else if (keysym == XK_a || keysym == XK_d)
		translate_plane_cyl(scene, (keysym == XK_a) * -step
			+ (keysym == XK_d) * step, 0, 0);
	else if (keysym == XK_r || keysym == XK_f)
		translate_plane_cyl(scene, 0, (keysym == XK_r) * step
			+ (keysym == XK_f) * -step, 0);
}
