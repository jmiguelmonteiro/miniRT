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
	if (!scene)
	{
		print_error("There was a problem initializing the scene.");
		return (NULL);
	}
	// TODO: parsing
	if (!validate_scene(scene))
	{
		free_scene(scene);
		return (NULL);
	}
	close(fd);
	return (scene);
}
