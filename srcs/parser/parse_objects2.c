#include "miniRT.h"
#include "parser.h"
#include "objects.h"

void	parse_sphere(char *line, t_scene *scene)
{
	t_tuple		center;
	double		diameter;
	t_color		color;
	t_sphere	*sphere;

	center = parse_tuple(&line, scene, true);
	diameter = parse_double(&line, scene);
	if (diameter < 0)
		print_error("Sphere diameter cannot be negative: ", line, scene);
	color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after sphere definition: ",
			line, scene);
	sphere = create_sphere(center, diameter, color);
	if (!sphere)
		print_error("Error allocating memory for sphere definition: ",
			line, scene);
	sphere->next = scene->spheres;
	scene->spheres = sphere;
}

void	parse_plane(char *line, t_scene *scene)
{
	t_tuple	point;
	t_tuple	normal;
	t_color	color;
	t_plane	*plane;

	point = parse_tuple(&line, scene, true);
	normal = parse_tuple(&line, scene, false);
	color = parse_color(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after plane definition: ",
			line, scene);
	plane = create_plane(point, normal, color);
	if (!plane)
		print_error("Error allocating memory for plane definition: ",
			line, scene);
	plane->next = scene->planes;
	scene->planes = plane;
}

void	parse_cylinder(char *line, t_scene *scene)
{
	t_tuple		center;
	t_tuple		normal;
	double		diameter;
	double		height;
	t_cylinder	*cylinder;

	center = parse_tuple(&line, scene, true);
	normal = parse_tuple(&line, scene, false);
	diameter = parse_double(&line, scene);
	height = parse_double(&line, scene);
	skip_whitespaces(&line);
	if (*line != '\0' && *line != '\n')
		print_error("Unexpected characters after cylinder definition: ",
			line, scene);
	cylinder = create_cylinder(center, normal, diameter, height,
			parse_color(&line, scene));
	cylinder = NULL;
	if (!cylinder)
		print_error("Error allocating memory for cylinder definition: ",
			line, scene);
	cylinder->next = scene->cylinders;
	scene->cylinders = cylinder;
}
