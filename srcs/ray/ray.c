#include <miniRT.h>
#include <algebraOperations.h>
#include <structs.h>
#include <ray.h>

static double	calculate_discriminant_unit_sphere(t_ray *object_ray)
{
	double		a;
	double		b;
	double		c;

	a = tuple_dot(object_ray->direction, object_ray->direction);
	b = 2.0 * tuple_dot(object_ray->direction, object_ray->origin);
	c = tuple_dot(object_ray->origin, object_ray->origin) - 1.0;
	return (b * b - 4.0 * a * c);
}

static void	calculate_intersections_unit_sphere(t_ray *object_ray,
				double discriminant, double *t)
{
	double		a;
	double		b;
	double		sqrt_disc;

	a = tuple_dot(object_ray->direction, object_ray->direction);
	b = 2.0 * tuple_dot(object_ray->direction, object_ray->origin);
	sqrt_disc = sqrt(discriminant);
	t[0] = (-b - sqrt_disc) / (2.0 * a);
	t[1] = (-b + sqrt_disc) / (2.0 * a);
}

bool	intersect_sphere(t_ray *ray, t_sphere *sphere, double *t_values)
{
	t_matrix	*inverse;
	t_ray		*object_ray;
	double		discriminant;

	if (!ray || !sphere || !t_values)
		return (false);
	inverse = inverse_matrix(sphere->transform);
	if (!inverse)
		return (false);
	object_ray = transform_ray(ray, inverse);
	free(inverse);
	if (!object_ray)
		return (false);
	discriminant = calculate_discriminant_unit_sphere(object_ray);
	if (discriminant < 0)
	{
		free_ray(object_ray);
		return (false);
	}
	calculate_intersections_unit_sphere(object_ray, discriminant, t_values);
	free_ray(object_ray);
	return (true);
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
