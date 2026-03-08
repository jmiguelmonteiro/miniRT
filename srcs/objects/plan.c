#include <miniRT.h>
#include <algebraOperations.h>
#include <stdlib.h>
#include <structs.h>
#include <objects.h>

static t_matrix	*rotation_from_normal(t_tuple normal);

t_plane	*create_plane(t_tuple point, t_tuple normal, t_color color)
{
	t_plane		*plane;
	t_matrix	*trans;
	t_matrix	*rot;
	t_matrix	*transform;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->point = point;
	plane->normal = normal;
	tuple_normalize(&plane->normal);
	plane->color = color;
	plane->material = default_material();
	rot = rotation_from_normal(plane->normal);
	trans = translation(point.x, point.y, point.z);
	transform = multiply_matrices(trans, rot);
	free(rot);
	free(trans);
	plane->transform = transform;
	plane->next = NULL;
	return (plane);
}

static t_matrix	*rotation_from_normal(t_tuple normal)
{
	t_tuple		up;
	t_tuple		*axis;
	double		dot;
	double		angle;
	double		c;
	double		s;
	double		t;
	t_matrix	*rot;

	up.x = 0.0; up.y = 1.0; up.z = 0.0; up.w = 0.0;
	dot = tuple_dot(&up, &normal);
	if (dot > 1.0 - EPSILON)
		return (identity_matrix());
	if (dot < -1.0 + EPSILON)
		return (rotation_x(M_PI));
	axis = tuple_cross(&up, &normal);
	tuple_normalize(axis);
	angle = acos(dot);
	c = cos(angle);
	s = sin(angle);
	t = 1.0 - c;
	rot = identity_matrix();
	set_matrix_cel(&rot->row[0], 0, t * axis->x * axis->x + c);
	set_matrix_cel(&rot->row[0], 1, t * axis->x * axis->y - s * axis->z);
	set_matrix_cel(&rot->row[0], 2, t * axis->x * axis->z + s * axis->y);
	set_matrix_cel(&rot->row[1], 0, t * axis->x * axis->y + s * axis->z);
	set_matrix_cel(&rot->row[1], 1, t * axis->y * axis->y + c);
	set_matrix_cel(&rot->row[1], 2, t * axis->y * axis->z - s * axis->x);
	set_matrix_cel(&rot->row[2], 0, t * axis->x * axis->z - s * axis->y);
	set_matrix_cel(&rot->row[2], 1, t * axis->y * axis->z + s * axis->x);
	set_matrix_cel(&rot->row[2], 2, t * axis->z * axis->z + c);
	free(axis);
	return (rot);
}
