#include <miniRT.h>
#include <structs.h>
#include <algebraOperations.h>

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

t_tuple	*sphere_normal_at(t_sphere *sphere, t_tuple *world_point)
{
	t_matrix	*inverse;
	t_matrix	*inverse_transpose;
	t_tuple		*object_point;
	t_tuple		object_normal;
	t_tuple		*world_normal;

	inverse = inverse_matrix(sphere->transform);
	if (!inverse)
		return (NULL);
	object_point = matrix_multiply_tuple(inverse, world_point);
	if (!object_point)
	{
		free(inverse);
		return (NULL);
	}
	object_normal.x = object_point->x;
	object_normal.y = object_point->y;
	object_normal.z = object_point->z;
	object_normal.w = 0.0;
	free(object_point);
	inverse_transpose = transpose_matrix(inverse);
	free(inverse);
	if (!inverse_transpose)
		return (NULL);
	world_normal = matrix_multiply_tuple(inverse_transpose, &object_normal);
	free(inverse_transpose);
	if (!world_normal)
		return (NULL);
	world_normal->w = 0.0;
	tuple_normalize(world_normal);
	return (world_normal);
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
	hit->object_type = 1;
	free(point);
	free(normal);
	return (hit);
}

void	free_ray(t_ray *ray)
{
	if (ray)
	{
		if (ray->origin)
			free(ray->origin);
		if (ray->direction)
			free(ray->direction);
		free(ray);
	}
}

void	free_hit(t_hit *hit)
{
	if (hit)
		free(hit);
}
