/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by miniRT            #+#    #+#             */
/*   Updated: 2026/04/03 13:13:41 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx_inc.h"
#include "algebraOperations.h"

static void	rotate_tuple_y(t_tuple *t, double angle)
{
	double	cos_a;
	double	sin_a;
	double	new_x;
	double	new_z;

	cos_a = cos(angle);
	sin_a = sin(angle);
	new_x = t->x * cos_a + t->z * sin_a;
	new_z = -t->x * sin_a + t->z * cos_a;
	t->x = new_x;
	t->z = new_z;
}

static void	rotate_tuple_x(t_tuple *t, double angle)
{
	double	cos_a;
	double	sin_a;
	double	new_y;
	double	new_z;

	cos_a = cos(angle);
	sin_a = sin(angle);
	new_y = t->y * cos_a - t->z * sin_a;
	new_z = t->y * sin_a + t->z * cos_a;
	t->y = new_y;
	t->z = new_z;
}

static void	rotate_camera(t_scene *scene, int keysym)
{
	double	angle;

	angle = M_PI / 18.0;
	if (keysym == XK_q)
		rotate_tuple_y(&scene->camera.orientation, -angle);
	else if (keysym == XK_e)
		rotate_tuple_y(&scene->camera.orientation, angle);
	else if (keysym == XK_t)
		rotate_tuple_x(&scene->camera.orientation, -angle);
	else if (keysym == XK_g)
		rotate_tuple_x(&scene->camera.orientation, angle);
	tuple_normalize(&scene->camera.orientation);
}

static void	rotate_plane_cyl(t_scene *scene, int keysym, double angle)
{
	if (scene->selected_type == OBJ_PLANE)
	{
		if (keysym == XK_q || keysym == XK_e)
			rotate_tuple_y(&((t_plane *)scene->selected)->normal,
				(keysym == XK_q) * -angle + (keysym == XK_e) * angle);
		else
			rotate_tuple_x(&((t_plane *)scene->selected)->normal,
				(keysym == XK_t) * -angle + (keysym == XK_g) * angle);
		tuple_normalize(&((t_plane *)scene->selected)->normal);
		rebuild_plane_transform((t_plane *)scene->selected);
	}
	else if (scene->selected_type == OBJ_CYLINDER)
	{
		if (keysym == XK_q || keysym == XK_e)
			rotate_tuple_y(&((t_cylinder *)scene->selected)->normal,
				(keysym == XK_q) * -angle + (keysym == XK_e) * angle);
		else
			rotate_tuple_x(&((t_cylinder *)scene->selected)->normal,
				(keysym == XK_t) * -angle + (keysym == XK_g) * angle);
		tuple_normalize(&((t_cylinder *)scene->selected)->normal);
		rebuild_cylinder_transform((t_cylinder *)scene->selected);
	}
}

void	handle_rotate(t_scene *scene, int keysym)
{
	double	angle;

	angle = M_PI / 18.0;
	if (scene->selected_type == OBJ_CAMERA)
		rotate_camera(scene, keysym);
	else if (scene->selected_type == OBJ_PLANE
		|| scene->selected_type == OBJ_CYLINDER)
		rotate_plane_cyl(scene, keysym, angle);
}
