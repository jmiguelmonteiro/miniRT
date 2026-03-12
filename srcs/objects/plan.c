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
