/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:13:13 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:13:14 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <algebraOperations.h>
#include <structs.h>

t_material	default_material(void);

t_sphere	*create_sphere(t_tuple center, double diameter, t_color color)
{
	t_sphere	*sphere;
	t_matrix	*scale;
	t_matrix	*trans;
	t_matrix	*transform;
	double		radius;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->diameter = diameter;
	sphere->color = color;
	sphere->material = default_material();
	radius = diameter / 2.0;
	scale = scaling(radius, radius, radius);
	trans = translation(center.x, center.y, center.z);
	transform = multiply_matrices(trans, scale);
	free (scale);
	free (trans);
	sphere->transform = transform;
	sphere->next = NULL;
	return (sphere);
}

t_material	default_material(void)
{
	t_material	mat;

	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200.0;
	return (mat);
}

void	set_sphere_transform(t_sphere *sphere, t_matrix *transform)
{
	if (!sphere || !transform)
		return ;
	if (sphere->transform)
		free(sphere->transform);
	sphere->transform = transform;
}
