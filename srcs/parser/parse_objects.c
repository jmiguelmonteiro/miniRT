#include "miniRT.h"

void	parse_ambient_light(char *line, t_scene *scene)
{
	scene->amb_light.ratio = parse_double(&line, scene);
	scene->amb_light.color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after ambient light definition: ",
			line, scene);
}

void	parse_camera(char *line, t_scene *scene)
{
	scene->camera.position = parse_tuple(&line, scene, true);
	// skip_whitespaces(&line);
	// if (*line != '\0' && *line != '\n')
	// 	print_error("Unexpected characters after camera definition: ",
	// 		line, scene);
}

void	parse_light(char *line, t_scene *scene)
{
	skip_whitespaces(&line);
	(void)scene;
}

void	parse_sphere(char *line, t_scene *scene)
{
	skip_whitespaces(&line);
	(void)scene;
}

void	parse_plane(char *line, t_scene *scene)
{
	skip_whitespaces(&line);
	(void)scene;
}
