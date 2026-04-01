/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniRT <miniRT@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by miniRT            #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by miniRT           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"
#include "algebraOperations.h"

static void	fill_rot_cells(t_matrix *rot, t_tuple *a, double c, double s)
{
	double	t;

	t = 1.0 - c;
	set_matrix_cel(&rot->row[0], 0, t * a->x * a->x + c);
	set_matrix_cel(&rot->row[0], 1, t * a->x * a->y - s * a->z);
	set_matrix_cel(&rot->row[0], 2, t * a->x * a->z + s * a->y);
	set_matrix_cel(&rot->row[1], 0, t * a->x * a->y + s * a->z);
	set_matrix_cel(&rot->row[1], 1, t * a->y * a->y + c);
	set_matrix_cel(&rot->row[1], 2, t * a->y * a->z - s * a->x);
	set_matrix_cel(&rot->row[2], 0, t * a->x * a->z - s * a->y);
	set_matrix_cel(&rot->row[2], 1, t * a->y * a->z + s * a->x);
	set_matrix_cel(&rot->row[2], 2, t * a->z * a->z + c);
}

static t_matrix	*rotation_from_normal(t_tuple normal)
{
	t_tuple		up;
	t_tuple		*axis;
	double		dot;
	double		angle;
	t_matrix	*rot;

	up.x = 0.0;
	up.y = 1.0;
	up.z = 0.0;
	up.w = 0.0;
	dot = tuple_dot(&up, &normal);
	if (dot > 1.0 - EPSILON)
		return (identity_matrix());
	if (dot < -1.0 + EPSILON)
		return (rotation_x(M_PI));
	axis = tuple_cross(&up, &normal);
	tuple_normalize(axis);
	angle = acos(dot);
	rot = identity_matrix();
	fill_rot_cells(rot, axis, cos(angle), sin(angle));
	free(axis);
	return (rot);
}

t_matrix	*build_plane_transform(t_plane *plane)
{
	t_matrix	*trans;
	t_matrix	*rot;
	t_matrix	*transform;

	rot = rotation_from_normal(plane->normal);
	trans = translation(plane->point.x, plane->point.y, plane->point.z);
	transform = multiply_matrices(trans, rot);
	free(rot);
	free(trans);
	return (transform);
}

t_matrix	*build_cyl_transform(t_cylinder *cyl)
{
	t_matrix	*scale;
	t_matrix	*rot;
	t_matrix	*trans;
	t_matrix	*tmp;

	scale = scaling(cyl->diameter / 2.0, cyl->height, cyl->diameter / 2.0);
	rot = rotation_from_normal(cyl->normal);
	trans = translation(cyl->center.x, cyl->center.y, cyl->center.z);
	tmp = multiply_matrices(rot, scale);
	free(scale);
	free(rot);
	scale = multiply_matrices(trans, tmp);
	free(trans);
	free(tmp);
	return (scale);
}
