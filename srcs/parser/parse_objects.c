#include "miniRT.h"

void	parse_ambient_light(char *line, t_scene *scene)
{
	if (scene->amb_light.defined)
		print_error("Ambient light (A) already defined.", NULL, scene);
	scene->amb_light.ratio = parse_double(&line, scene);
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
	scene->camera.position = parse_tuple(&line, scene, true);
	scene->camera.orientation = parse_tuple(&line, scene, false);
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
	scene->light.position = parse_tuple(&line, scene, true);
	scene->light.brightness = parse_double(&line, scene);
	scene->light.color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after light definition: ",
			line, scene);
	scene->light.defined = true;
}
