#include <miniRT.h>
#include <algebraOperations.h>
#include <ray.h>

static t_tuple	*plane_normal_at(t_plane *plane);

t_hit	*ray_hit_sphere(t_ray *ray, t_sphere *sphere)
{
	double	t_values[2];
	double	closest_t;
	t_hit	*hit;

	if (!intersect_sphere(ray, sphere, t_values))
		return (NULL);
	closest_t = get_closest_intersection(t_values, 2);
	if (closest_t < 0)
		return (NULL);
	hit = create_hit(closest_t, ray, sphere);
	return (hit);
}

t_hit	*ray_hit_plane(t_ray *ray, t_plane *plane)
{
	t_matrix	*inverse;
	t_ray		*object_ray;
	double		t;
	t_hit		*hit;
	t_tuple		*point;
	t_tuple		*normal;

	inverse = inverse_matrix(plane->transform);
	if (!inverse)
		return (NULL);
	object_ray = transform_ray(ray, inverse);
	free(inverse);
	if (!object_ray)
		return (NULL);
	if (fabs(object_ray->direction->y) < EPSILON)
		return (free_ray(object_ray), NULL);
	t = -object_ray->origin->y / object_ray->direction->y;
	free_ray(object_ray);
	if (t < EPSILON)
		return (NULL);
	hit = malloc(sizeof(t_hit));
	if (!hit)
		return (NULL);
	point = ray_position(ray, t);
	if (!point)
		return (free(hit), NULL);
	normal = plane_normal_at(plane);
	if (!normal)
		return (free(point), free(hit), NULL);
	hit->t = t;
	hit->point = *point;
	hit->normal = *normal;
	hit->color = plane->color;
	hit->object = plane;
	hit->object_type = OBJ_PLANE;
	free(point);
	free(normal);
	return (hit);
}

static t_tuple	*plane_normal_at(t_plane *plane)
{
	t_matrix	*inverse;
	t_matrix	*inverse_transpose;
	t_tuple		object_normal;
	t_tuple		*world_normal;

	inverse = inverse_matrix(plane->transform);
	if (!inverse)
		return (NULL);
	object_normal.x = 0.0;
	object_normal.y = 1.0;
	object_normal.z = 0.0;
	object_normal.w = 0.0;
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
		return (free(inverse), NULL);
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
