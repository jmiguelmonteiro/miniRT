#include "miniRT.h"
#include "utils.h"

int	handle_close(t_scene *scene)
{
	exit_minirt(EXIT_SUCCESS, scene);
	return (EXIT_SUCCESS);
}
