#include "miniRT.h"
#include <parser.h>

void	parse_sphere(char *line, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		print_error("Error allocating memory for sphere definition: ",
			line, scene);
	sphere->center = parse_tuple(&line, scene, true);
	sphere->diameter = parse_double(&line, scene);
	if (sphere->diameter < 0)
		print_error("Sphere diameter cannot be negative: ",
			line, scene);
	sphere->color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after sphere definition: ",
			line, scene);
	sphere->next = scene->spheres;
	scene->spheres = sphere;
}

void	parse_plane(char *line, t_scene *scene)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		print_error("Error allocating memory for plane definition: ",
			line, scene);
	plane->point = parse_tuple(&line, scene, true);
	plane->normal = parse_tuple(&line, scene, false);
	plane->color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after plane definition: ",
			line, scene);
	plane->next = scene->planes;
	scene->planes = plane;
}

void	parse_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		print_error("Error allocating memory for cylinder definition: ",
			line, scene);
	cylinder->center = parse_tuple(&line, scene, true);
	cylinder->normal = parse_tuple(&line, scene, false);
	cylinder->diameter = parse_double(&line, scene);
	cylinder->height = parse_double(&line, scene);
	cylinder->color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after cylinder definition: ",
			line, scene);
	cylinder->next = scene->cylinders;
	scene->cylinders = cylinder;
}
