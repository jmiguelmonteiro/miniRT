/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_cylinder2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:11:33 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:11:34 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <algebraOperations.h>
#include <structs.h>
#include <ray.h>

static void	intersect_cyl_tube(t_ray *oray, double *t_vals, int *cnt)
{
	double	a;
	double	b;
	double	c;
	double	disc;

	a = oray->direction->x * oray->direction->x
		+ oray->direction->z * oray->direction->z;
	if (a < EPSILON)
		return ;
	b = 2.0 * (oray->origin->x * oray->direction->x
			+ oray->origin->z * oray->direction->z);
	c = oray->origin->x * oray->origin->x
		+ oray->origin->z * oray->origin->z - 1.0;
	disc = b * b - 4.0 * a * c;
	if (disc < 0)
		return ;
	t_vals[*cnt] = (-b - sqrt(disc)) / (2.0 * a);
	if (fabs(oray->origin->y + t_vals[*cnt] * oray->direction->y) < 0.5)
		(*cnt)++;
	t_vals[*cnt] = (-b + sqrt(disc)) / (2.0 * a);
	if (fabs(oray->origin->y + t_vals[*cnt] * oray->direction->y) < 0.5)
		(*cnt)++;
}

static void	intersect_cyl_cap(t_ray *oray, double off,
				double *t_vals, int *cnt)
{
	double	t;
	double	x;
	double	z;

	if (fabs(oray->direction->y) < EPSILON)
		return ;
	t = (off - oray->origin->y) / oray->direction->y;
	x = oray->origin->x + t * oray->direction->x;
	z = oray->origin->z + t * oray->direction->z;
	if (x * x + z * z <= 1.0)
	{
		t_vals[*cnt] = t;
		(*cnt)++;
	}
}

bool	intersect_cylinder(t_ray *ray, t_cylinder *cylinder,
			double *t_values, int *hit_count)
{
	t_matrix	*inverse;
	t_ray		*object_ray;

	if (!ray || !cylinder || !t_values || !hit_count)
		return (false);
	inverse = inverse_matrix(cylinder->transform);
	if (!inverse)
		return (false);
	object_ray = transform_ray(ray, inverse);
	free(inverse);
	if (!object_ray)
		return (false);
	*hit_count = 0;
	intersect_cyl_tube(object_ray, t_values, hit_count);
	intersect_cyl_cap(object_ray, -0.5, t_values, hit_count);
	intersect_cyl_cap(object_ray, 0.5, t_values, hit_count);
	free_ray(object_ray);
	return (*hit_count > 0);
}
