#include "miniRT.h"

t_scene	*init_scene(void)
{
	t_scene		*scene;
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	amb_light.ratio = 0;
	amb_light.color = color(0, 0, 0);
	camera.position = point(0, 0, 0);
	camera.orientation = vector(0, 0, 0);
	camera.fov = 0;
	light.position = point(0, 0, 0);
	light.brightness = 0;
	light.color = color(0, 0, 0);
	scene->amb_light = amb_light;
	scene->camera = camera;
	scene->light = light;
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->cylinders = NULL;
	return (scene);
	//
}
