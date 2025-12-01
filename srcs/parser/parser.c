#include "miniRT.h"

t_scene	*parse_scene(char *filename)
{
	int		fd;
	char	*line;
	t_scene	*scene;

	fd = open(filename);
	if (fd < 0)
	{
		print_error("Cannot open scene file.");
		return (NULL);
	}
	scene = init_scene();

	close(fd);
	return (scene);
}
