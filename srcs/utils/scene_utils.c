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
}

bool	validate_scene(t_scene *scene)
{
	return (true);
}

void	free_scene(t_scene *scene)
{
	t_sphere	*next_sphere;
	t_plane		*next_plane;
	t_cylinder	*next_cylinder;

	while (scene->spheres)
	{
		next_sphere = scene->spheres->next;
		free(scene->spheres);
		scene->spheres = next_sphere;
	}
	while (scene->planes)
	{
		next_plane = scene->planes->next;
		free(scene->planes);
		scene->planes = next_plane;
	}
	while (scene->cylinders)
	{
		next_cylinder = scene->cylinders->next;
		free(scene->cylinders);
		scene->cylinders = next_cylinder;
	}
	free(scene);
}
