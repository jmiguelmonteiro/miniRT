#include "miniRT.h"

t_scene	*init_scene(void)
{
	t_scene		*scene;
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	amb_light.defined = false;
	camera.defined = false;
	light.defined = false;
	return (scene);
}

bool	validate_scene(t_scene *scene)
{
	if (!scene->amb_light.defined)
		print_error("No ambient light defined.", NULL, scene);
	if (!scene->camera.defined)
		print_error("No camera defined.", NULL, scene);
	if (!scene->light.defined)
		print_error("No light defined.", NULL, scene);
	if (!scene->spheres && !scene->planes && !scene->cylinders)
		print_error("No objects defined.", NULL, scene);
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
