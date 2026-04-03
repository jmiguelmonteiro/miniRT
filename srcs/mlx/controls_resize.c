/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by miniRT            #+#    #+#             */
/*   Updated: 2026/04/03 13:13:32 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx_inc.h"

static void	resize_sphere(t_sphere *sphere, double delta)
{
	sphere->diameter += delta;
	if (sphere->diameter < 0.1)
		sphere->diameter = 0.1;
	rebuild_sphere_transform(sphere);
}

static void	resize_cylinder(t_cylinder *cyl, int keysym)
{
	double	step;

	step = 0.5;
	if (keysym == XK_plus || keysym == XK_equal)
	{
		cyl->diameter += step;
		cyl->height += step;
	}
	else if (keysym == XK_minus)
	{
		cyl->diameter -= step;
		cyl->height -= step;
		if (cyl->diameter < 0.1)
			cyl->diameter = 0.1;
		if (cyl->height < 0.1)
			cyl->height = 0.1;
	}
	rebuild_cylinder_transform(cyl);
}

void	handle_resize(t_scene *scene, int keysym)
{
	double	step;

	step = 0.5;
	if (keysym == XK_minus)
		step = -0.5;
	if (scene->selected_type == OBJ_SPHERE)
		resize_sphere((t_sphere *)scene->selected, step);
	else if (scene->selected_type == OBJ_CYLINDER)
		resize_cylinder((t_cylinder *)scene->selected, keysym);
}

void	handle_light_brightness(t_scene *scene, int keysym)
{
	double	step;
	t_light	*light;

	if (scene->selected_type != OBJ_LIGHT)
		return ;
	light = (t_light *)scene->selected;
	step = 0.1;
	if (keysym == XK_Down)
		step = -0.1;
	light->brightness += step;
	if (light->brightness < 0.0)
		light->brightness = 0.0;
	if (light->brightness > 1.0)
		light->brightness = 1.0;
	printf("\r\033[KLight brightness: %.1f; ", light->brightness);
	fflush(stdout);
}
