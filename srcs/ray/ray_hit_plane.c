#include <miniRT.h>
#include <algebraOperations.h>
#include <ray.h>

static double	intersect_plane(t_ray *ray, t_plane *plane)
{
	t_matrix	*inverse;
	t_ray		*object_ray;
	double		t;

	inverse = inverse_matrix(plane->transform);
	if (!inverse)
		return (-1.0);
	object_ray = transform_ray(ray, inverse);
	free(inverse);
	if (!object_ray)
		return (-1.0);
	if (fabs(object_ray->direction->y) < EPSILON)
		return (free_ray(object_ray), -1.0);
	t = -object_ray->origin->y / object_ray->direction->y;
	free_ray(object_ray);
	if (t < EPSILON)
		return (-1.0);
	return (t);
}

static t_tuple	*plane_normal_at(t_plane *plane)
{
	t_matrix	*inv;
	t_matrix	*inv_t;
	t_tuple		obj_n;
	t_tuple		*world_n;

	inv = inverse_matrix(plane->transform);
	if (!inv)
		return (NULL);
	obj_n.x = 0.0;
	obj_n.y = 1.0;
	obj_n.z = 0.0;
	obj_n.w = 0.0;
	inv_t = transpose_matrix(inv);
	free(inv);
	if (!inv_t)
		return (NULL);
	world_n = matrix_multiply_tuple(inv_t, &obj_n);
	free(inv_t);
	if (!world_n)
		return (NULL);
	world_n->w = 0.0;
	tuple_normalize(world_n);
	return (world_n);
}

t_hit	*ray_hit_plane(t_ray *ray, t_plane *plane)
{
	double	t;
	t_hit	*hit;
	t_tuple	*point;
	t_tuple	*normal;

	t = intersect_plane(ray, plane);
	if (t < EPSILON)
		return (NULL);
	hit = malloc(sizeof(t_hit));
	point = ray_position(ray, t);
	normal = plane_normal_at(plane);
	if (!hit || !point || !normal)
		return (free(hit), free(point), free(normal), NULL);
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
