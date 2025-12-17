#include "utils.h"

void	exit_minirt(int exit_code, t_scene *scene)
{
	if (!scene)
		exit(exit_code);
	free_mlx(scene);
	free_scene(scene);
	exit(exit_code);
}
