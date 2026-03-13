#include <miniRT.h>
#include <algebraOperations.h>
#include <structs.h>
#include <objects.h>

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

static t_matrix	*rotation_from_axis(t_tuple axis)
{
	t_tuple		up;
	t_tuple		*cross;
	double		dot;
	double		angle;
	t_matrix	*rot;

	up.x = 0.0;
	up.y = 1.0;
	up.z = 0.0;
	up.w = 0.0;
	dot = tuple_dot(&up, &axis);
	if (dot > 1.0 - EPSILON)
		return (identity_matrix());
	if (dot < -1.0 + EPSILON)
		return (rotation_x(M_PI));
	cross = tuple_cross(&up, &axis);
	tuple_normalize(cross);
	angle = acos(dot);
	rot = identity_matrix();
	fill_rot_cells(rot, cross, cos(angle), sin(angle));
	free(cross);
	return (rot);
}

static t_matrix	*build_cylinder_transform(t_cylinder *cyl)
{
	t_matrix	*scale;
	t_matrix	*rot;
	t_matrix	*trans;
	t_matrix	*tmp;

	scale = scaling(cyl->diameter / 2.0, cyl->height,
			cyl->diameter / 2.0);
	rot = rotation_from_axis(cyl->normal);
	trans = translation(cyl->center.x, cyl->center.y,
			cyl->center.z);
	tmp = multiply_matrices(rot, scale);
	free(scale);
	free(rot);
	scale = multiply_matrices(trans, tmp);
	free(trans);
	free(tmp);
	return (scale);
}

t_cylinder	*create_cylinder(t_tuple center, t_tuple normal,
				double diameter, double height)
{
	t_cylinder	*cyl;

	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		return (NULL);
	cyl->center = center;
	cyl->normal = normal;
	tuple_normalize(&cyl->normal);
	cyl->diameter = diameter;
	cyl->height = height;
	cyl->material = default_material();
	cyl->transform = build_cylinder_transform(cyl);
	cyl->next = NULL;
	return (cyl);
}
