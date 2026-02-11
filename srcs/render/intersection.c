#include "miniRT.h"
#include "render.h"
#include "ray.h"

t_hit	find_closest_hit(t_ray *ray, t_scene *scene)
{
	t_hit	closest_hit;

	closest_hit.object = NULL;
	closest_hit.t = INFINITY;
	find_closest_hit_sphere(ray, scene, &closest_hit);
	// find_closest_hit_plane(ray, scene, &closest_hit);
	// find_closest_hit_cylinder(ray, scene, &closest_hit);
	return (closest_hit);
}

void	find_closest_hit_sphere(t_ray *ray, t_scene *scene, t_hit *closest_hit)
{
	t_sphere	*sphere;
	t_hit		*temp_hit;

	sphere = scene->spheres;
	while (sphere)
	{
		temp_hit = ray_hit_sphere(ray, sphere);
		if (temp_hit && temp_hit->t < closest_hit->t) 
		{
			*closest_hit = *temp_hit;
			free(temp_hit);
		}
		else if (temp_hit)
			free(temp_hit);
		sphere = sphere->next;
	}
}
