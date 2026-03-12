#include <miniRT.h>
#include <structs.h>
#include <algebraOperations.h>
#include <ray.h>

t_ray	*create_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_tuple	*ray_position(t_ray *ray, double t)
{
	t_tuple	*scaled;
	t_tuple	*result;

	scaled = tuple_scalar_multiply(ray->direction, t);
	if (!scaled)
		return (NULL);
	result = tuple_add(ray->origin, scaled);
	free(scaled);
	return (result);
}

t_hit	*create_hit(double t, t_ray *ray, t_sphere *sphere)
{
	t_hit	*hit;
	t_tuple	*point;
	t_tuple	*normal;

	hit = malloc(sizeof(t_hit));
	if (!hit)
		return (NULL);
	point = ray_position(ray, t);
	if (!point)
		return (free(hit), NULL);
	normal = sphere_normal_at(sphere, point);
	if (!normal)
		return (free(point), free(hit), NULL);
	hit->t = t;
	hit->point = *point;
	hit->normal = *normal;
	hit->color = sphere->color;
	hit->object = sphere;
	hit->object_type = OBJ_SPHERE;
	free(point);
	free(normal);
	return (hit);
}

double	get_closest_intersection(double *t_values, int count)
{
	double	closest;
	int		i;

	closest = -1.0;
	i = 0;
	while (i < count)
	{
		if (t_values[i] > EPSILON)
		{
			if (closest < 0 || t_values[i] < closest)
				closest = t_values[i];
		}
		i++;
	}
	return (closest);
}

