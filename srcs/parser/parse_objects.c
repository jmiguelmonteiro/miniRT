/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:09:59 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:10:01 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <parser.h>

void	parse_ambient_light(char *line, t_scene *scene)
{
	if (scene->amb_light.defined)
		print_error("Ambient light (A) already defined.", NULL, scene);
	skip_whitespaces(&line);
	scene->amb_light.ratio = parse_double(&line, scene);
	skip_whitespaces(&line);
	scene->amb_light.color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after ambient light definition: ",
			line, scene);
	scene->amb_light.defined = true;
}

void	parse_camera(char *line, t_scene *scene)
{
	if (scene->camera.defined)
		print_error("Camera (C) already defined.", NULL, scene);
	skip_whitespaces(&line);
	scene->camera.position = parse_tuple(&line, scene, true);
	skip_whitespaces(&line);
	scene->camera.orientation = parse_tuple(&line, scene, false);
	skip_whitespaces(&line);
	scene->camera.fov = parse_double(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after camera definition: ",
			line, scene);
	scene->camera.defined = true;
}

void	parse_light(char *line, t_scene *scene)
{
	if (scene->light.defined)
		print_error("Light (L) already defined.", NULL, scene);
	skip_whitespaces(&line);
	scene->light.position = parse_tuple(&line, scene, true);
	skip_whitespaces(&line);
	scene->light.brightness = parse_double(&line, scene);
	skip_whitespaces(&line);
	scene->light.color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after light definition: ",
			line, scene);
	scene->light.defined = true;
}
