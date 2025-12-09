#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void)argc;

	if (argc != 2)
	{
		print_error("Usage: ./miniRT <scene_file>", NULL, NULL);
		return (EXIT_FAILURE);
	}
	scene = parse_scene(argv[1]);
	if (!scene)
		return (EXIT_FAILURE);
	free_scene(scene);
	return (EXIT_SUCCESS);
}
