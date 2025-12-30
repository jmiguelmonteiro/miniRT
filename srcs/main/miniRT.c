#include "miniRT.h"
#include "structs.h"
#include "utils.h"
#include "parser.h"
#include "mlx_inc.h"

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
	init_mlx(scene);
	init_mlx_handlers(scene);
	mlx_loop((*scene).mlx);
	exit_minirt(EXIT_SUCCESS, scene);
}
