#include <structs.h>
#include <miniRT.h>
#include <utils.h>
#include <parser.h>

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
	{
		print_error(BOLD "Usage: ./miniRT <scene_file>" DEFAULT, NULL, NULL);
		return (EXIT_FAILURE);
	}
	scene = parse_scene(argv[1]);
	if (!scene)
		return (EXIT_FAILURE);
	free_scene(scene);
	return (EXIT_SUCCESS);
}
