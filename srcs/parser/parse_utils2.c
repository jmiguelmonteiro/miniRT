#include "miniRT.h"

void	print_scene(t_scene *scene)
{
	printf("Scene Details:\n\n");
	printf("Ambient Light Ratio: %lf\n", scene->amb_light.ratio);
	printf("Ambient Light Color: (%lf, %lf, %lf)\n", scene->amb_light.color.red,
		scene->amb_light.color.green, scene->amb_light.color.blue);
	printf("Camera Position: (%lf, %lf, %lf)\n", scene->camera.position.x,
		scene->camera.position.y, scene->camera.position.z);
	printf("Camera Orientation: (%lf, %lf, %lf)\n", scene->camera.orientation.x,
		scene->camera.orientation.y, scene->camera.orientation.z);
	printf("Camera FOV: %lf\n", scene->camera.fov);
	printf("Light Position: (%lf, %lf, %lf)\n", scene->light.position.x,
		scene->light.position.y, scene->light.position.z);
	printf("Light Brightness: %lf\n", scene->light.brightness);
	printf("Light Color: (%lf, %lf, %lf)\n", scene->light.color.red,
		scene->light.color.green, scene->light.color.blue);
	print_scene2(scene);
}

void	print_scene2(t_scene *scene)
{
	t_sphere	*sphere;
	t_plane		*plane;

	sphere = scene->spheres;
	while (sphere)
	{
		printf("Sphere Center: (%lf, %lf, %lf)\n", sphere->center.x,
			sphere->center.y, sphere->center.z);
		printf("Sphere Diameter: %lf\n", sphere->diameter);
		printf("Sphere Color: (%lf, %lf, %lf)\n", sphere->color.red,
			sphere->color.green, sphere->color.blue);
		sphere = sphere->next;
	}
	plane = scene->planes;
	while (plane)
	{
		printf("Plane Point: (%lf, %lf, %lf)\n", plane->point.x,
			plane->point.y, plane->point.z);
		printf("Plane Normal: (%lf, %lf, %lf)\n", plane->normal.x,
			plane->normal.y, plane->normal.z);
		printf("Plane Color: (%lf, %lf, %lf)\n", plane->color.red,
			plane->color.green, plane->color.blue);
		plane = plane->next;
	}
	print_scene3(scene);
}

void	print_scene3(t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = scene->cylinders;
	while (cylinder)
	{
		printf("Cylinder Center: (%lf, %lf, %lf)\n", cylinder->center.x,
			cylinder->center.y, cylinder->center.z);
		printf("Cylinder Normal: (%lf, %lf, %lf)\n", cylinder->normal.x,
			cylinder->normal.y, cylinder->normal.z);
		printf("Cylinder Diameter: %lf\n", cylinder->diameter);
		printf("Cylinder Height: %lf\n", cylinder->height);
		printf("Cylinder Color: (%lf, %lf, %lf)\n", cylinder->color.red,
			cylinder->color.green, cylinder->color.blue);
		cylinder = cylinder->next;
	}
}
