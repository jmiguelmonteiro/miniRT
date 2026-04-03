/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:11:45 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:11:46 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_tuple	*sphere_normal_at(t_sphere *sphere, t_tuple *wp)
{
	t_matrix	*inv;
	t_matrix	*inv_t;
	t_tuple		*point;
	t_tuple		normal;

	inv = inverse_matrix(sphere->transform);
	if (!inv)
		return (NULL);
	point = matrix_multiply_tuple(inv, wp);
	if (!point)
		return (free(inv), NULL);
	normal = *point;
	normal.w = 0.0;
	free(point);
	inv_t = transpose_matrix(inv);
	free(inv);
	if (!inv_t)
		return (NULL);
	point = matrix_multiply_tuple(inv_t, &normal);
	free(inv_t);
	if (!point)
		return (NULL);
	point->w = 0.0;
	tuple_normalize(point);
	return (point);
}
