/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:12:29 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:12:30 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parser.h"
#include "algebraOperations.h"

t_scene	*init_scene(void)
{
	t_scene		*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	return (scene);
}

void	validate_scene(t_scene *scene)
{
	if (!scene->amb_light.defined)
		print_error("No ambient light defined.", NULL, scene);
	if (!scene->camera.defined)
		print_error("No camera defined.", NULL, scene);
	if (!scene->lights)
		print_error("No light defined.", NULL, scene);
	if (!scene->spheres && !scene->planes && !scene->cylinders)
		print_error("No objects defined.", NULL, scene);
}

void	normalize_scene_tuples(t_scene *scene)
{
	t_plane		*next_plane;
	t_cylinder	*next_cylinder;

	tuple_normalize(&scene->camera.orientation);
	next_plane = scene->planes;
	while (next_plane)
	{
		tuple_normalize(&next_plane->normal);
		next_plane = next_plane->next;
	}
	next_cylinder = scene->cylinders;
	while (next_cylinder)
	{
		tuple_normalize(&next_cylinder->normal);
		next_cylinder = next_cylinder->next;
	}
}

void	free_scene2(t_scene *scene)
{
	t_cylinder	*next_cylinder;

	while (scene->cylinders)
	{
		next_cylinder = scene->cylinders->next;
		free(scene->cylinders->transform);
		free(scene->cylinders);
		scene->cylinders = next_cylinder;
	}
	free(scene);
}

void	free_scene(t_scene *scene)
{
	t_sphere	*next_sphere;
	t_plane		*next_plane;
	t_light		*next_light;

	while (scene->spheres)
	{
		next_sphere = scene->spheres->next;
		free(scene->spheres->transform);
		free(scene->spheres);
		scene->spheres = next_sphere;
	}
	while (scene->planes)
	{
		next_plane = scene->planes->next;
		free(scene->planes->transform);
		free(scene->planes);
		scene->planes = next_plane;
	}
	while (scene->lights)
	{
		next_light = scene->lights->next;
		free(scene->lights);
		scene->lights = next_light;
	}
	free_scene2(scene);
}
