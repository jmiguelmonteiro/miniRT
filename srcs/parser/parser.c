#include "miniRT.h"

void	parse_line(char *line, t_scene *scene)
{
	if (!line || !*line || *line == '\n')
		return ;
	(void)scene;
	skip_whitespaces(&line);
	if (*line == '#')
		return ;
	else if (*line == 'A')
		parse_ambient_light(line + 1, scene);
	else if (*line == 'C')
		parse_camera(line + 1, scene);
	else if (*line == 'L')
		parse_light(line + 1, scene);
	else if (*line == 's' && *(line + 1) == 'p')
		parse_sphere(line + 2, scene);
	else if (*line == 'p' && *(line + 1) == 'l')
		parse_plane(line + 2, scene);
	else if (*line == 'c' && *(line + 1) == 'y')
		parse_cylinder(line + 2, scene);
	else
		print_error("Unknown identifier in scene file: ", line, scene);
}

t_scene	*parse_scene(char *filename)
{
	int		fd;
	char	*line;
	t_scene	*scene;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Cannot open scene file.", NULL, NULL);
	scene = init_scene();
	if (!scene)
		print_error("There was a problem initializing the scene.", NULL, NULL);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, scene);
		free(line);
	}
	if (!validate_scene(scene))
		return (free_scene(scene), NULL);
	close(fd);
	print_scene(scene); // TODO: remove line
	return (scene);
}
