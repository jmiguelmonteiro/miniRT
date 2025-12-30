#include <miniRT.h>
#include <algebraOperations.h>
#include <structs.h>
#include <ray.h>

static double	calculate_discriminant(t_ray *ray, t_sphere *sphere)
{
	t_tuple		*sphere_to_ray;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	sphere_to_ray = tuple_subtract(ray->origin, &sphere->center);
	if (!sphere_to_ray)
		return (-1.0);
	a = tuple_dot(ray->direction, ray->direction);
	b = 2.0 * tuple_dot(ray->direction, sphere_to_ray);
	c = tuple_dot(sphere_to_ray, sphere_to_ray);
	c -= pow(sphere->diameter / 2.0, 2);
	discriminant = b * b - 4 * a * c;
	free(sphere_to_ray);
	return (discriminant);
}

static void	calculate_intersections(t_ray *ray, t_sphere *sphere,
				double discriminant, double *t)
{
	t_tuple		*sphere_to_ray;
	double		a;
	double		b;
	double		sqrt_disc;

	sphere_to_ray = tuple_subtract(ray->origin, &sphere->center);
	if (!sphere_to_ray)
		return ;
	a = tuple_dot(ray->direction, ray->direction);
	b = 2.0 * tuple_dot(ray->direction, sphere_to_ray);
	sqrt_disc = sqrt(discriminant);
	t[0] = (-b - sqrt_disc) / (2.0 * a);
	t[1] = (-b + sqrt_disc) / (2.0 * a);
	free(sphere_to_ray);
}

bool	intersect_sphere(t_ray *ray, t_sphere *sphere, double *t_values)
{
	double	discriminant;

	if (!ray || !sphere || !t_values)
		return (false);
	discriminant = calculate_discriminant(ray, sphere);
	if (discriminant < 0)
		return (false);
	calculate_intersections(ray, sphere, discriminant, t_values);
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
