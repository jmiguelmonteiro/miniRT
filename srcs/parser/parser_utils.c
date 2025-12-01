#include "miniRT.h"

void	init_scene(t_scene *scene)
{
	// TODO: change this to correct data type
	scene->ambient_lighting = 0;
	scene->camera = 0;
	scene->light = 0;
	scene->sphere = NULL;
	scene->plane = NULL;
	scene->cylinder = NULL;
}
