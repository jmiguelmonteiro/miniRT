#include "miniRT.h"
#include "structs.h"
#include "algebraOperations.h"
#include "ray.h"
#include "lighting.h"

bool	is_in_shadow(t_hit *hit, t_light *light, t_scene *scene)
{
	t_ray	*shadow_ray;
	t_tuple	*offset;
	t_tuple	*to_light;
	double	light_distance;
	bool	blocked;

	to_light = tuple_subtract(&light->position, &hit->point);
	light_distance = tuple_magnitude(*to_light);
	offset = tuple_scalar_multiply(&hit->normal, EPSILON);
	shadow_ray = create_shadow_ray(hit->point, *offset, *to_light);
	if (!shadow_ray)
		return (false);
	blocked = is_path_blocked(shadow_ray, scene, light_distance);
	free_ray(shadow_ray);
	free(offset);
	free(to_light);
	return (blocked);
}

t_ray	*create_shadow_ray(t_tuple point, t_tuple offset, t_tuple to_light)
{
	t_ray	*shadow_ray;
	t_tuple	*origin;
	t_tuple	direction;

	shadow_ray = malloc(sizeof(t_ray));
	if (!shadow_ray)
		return (NULL);
	shadow_ray->origin = malloc(sizeof(t_tuple));
	shadow_ray->direction = malloc(sizeof(t_tuple));
	if (!shadow_ray->origin || !shadow_ray->direction)
	{
		free_ray(shadow_ray);
		return (NULL);
	}
	origin = tuple_add(&point, &offset);
	*shadow_ray->origin = *origin;
	direction = to_light;
	tuple_normalize(&direction);
	*shadow_ray->direction = direction;
	free(origin);
	return (shadow_ray);
}

bool	is_path_blocked(t_ray *shadow_ray, t_scene *scene,
			double light_distance)
{
	t_hit		*hit;
	t_sphere	*sphere;
	// t_plane		*plane;
	// t_cylinder	*cylinder;

	sphere = scene->spheres;
	while (sphere)
	{
		hit = ray_hit_sphere(shadow_ray, sphere);
		if (hit && hit->t > EPSILON && hit->t < light_distance)
			return (free(hit), true);
		if (hit)
			free(hit);
		sphere = sphere->next;
	}
	// plane = scene->planes;
	// while (plane)
	// {
	// 	hit = ray_hit_plane(shadow_ray, plane);
	// 	if (hit && hit->t > EPSILON && hit->t < light_distance)
	// 		return (free(hit), true);
	// 	if (hit)
	// 		free(hit);
	// 	plane = plane->next;
	// }
	// cylinder = scene->cylinders;
	// while (cylinder)
	// {
	// 	hit = ray_hit_cylinder(shadow_ray, cylinder);
	// 	if (hit && hit->t > EPSILON && hit->t < light_distance)
	// 		return (free(hit), true);
	// 	if (hit)
	// 		free(hit);
	// 	cylinder = cylinder->next;
	// }
	return (false);
}
