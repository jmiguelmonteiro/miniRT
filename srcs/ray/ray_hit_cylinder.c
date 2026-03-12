#include <miniRT.h>
#include <algebraOperations.h>
#include <ray.h>

static t_tuple	cylinder_object_normal(t_tuple *obj_pt)
{
	t_tuple	n;
	double	dist;

	dist = obj_pt->x * obj_pt->x + obj_pt->z * obj_pt->z;
	n.w = 0.0;
	if (dist < 1.0 && obj_pt->y >= 0.5 - EPSILON)
	{
		n.x = 0.0;
		n.y = 1.0;
		n.z = 0.0;
	}
	else if (dist < 1.0 && obj_pt->y <= -0.5 + EPSILON)
	{
		n.x = 0.0;
		n.y = -1.0;
		n.z = 0.0;
	}
	else
	{
		n.x = obj_pt->x;
		n.y = 0.0;
		n.z = obj_pt->z;
	}
	return (n);
}

static t_tuple	*cylinder_normal_at(t_cylinder *cyl, t_tuple *wp)
{
	t_matrix	*inverse;
	t_matrix	*inv_t;
	t_tuple		*obj_pt;
	t_tuple		obj_n;
	t_tuple		*world_n;

	inverse = inverse_matrix(cyl->transform);
	if (!inverse)
		return (NULL);
	obj_pt = matrix_multiply_tuple(inverse, wp);
	if (!obj_pt)
		return (free(inverse), NULL);
	obj_n = cylinder_object_normal(obj_pt);
	free(obj_pt);
	inv_t = transpose_matrix(inverse);
	free(inverse);
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

static t_hit	*build_cyl_hit(t_ray *ray, t_cylinder *cyl, double t)
{
	t_hit	*hit;
	t_tuple	*point;
	t_tuple	*normal;

	hit = malloc(sizeof(t_hit));
	point = ray_position(ray, t);
	if (!hit || !point)
		return (free(hit), free(point), NULL);
	normal = cylinder_normal_at(cyl, point);
	if (!normal)
		return (free(hit), free(point), NULL);
	hit->t = t;
	hit->point = *point;
	hit->normal = *normal;
	hit->color = cyl->color;
	hit->object = cyl;
	hit->object_type = OBJ_CYLINDER;
	free(point);
	free(normal);
	return (hit);
}

t_hit	*ray_hit_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	double	t_values[4];
	int		hit_count;
	double	closest_t;

	if (!intersect_cylinder(ray, cylinder, t_values, &hit_count))
		return (NULL);
	closest_t = get_closest_intersection(t_values, hit_count);
	if (closest_t < 0)
		return (NULL);
	return (build_cyl_hit(ray, cylinder, closest_t));
}
