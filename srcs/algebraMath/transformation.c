#include <algebraOperations.h>
#include <libft.h>

t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*m;

	m = identity_matrix();
	set_matrix_cel(&m->row[0], 3, x);
	set_matrix_cel(&m->row[1], 3, y);
	set_matrix_cel(&m->row[2], 3, z);
	return (m);
}

t_matrix	*scaling(double sx, double sy, double sz)
{
	t_matrix	*m;

	m = identity_matrix();
	if (!m)
		return (NULL);
	set_matrix_cel(&m->row[0], 0, sx);
	set_matrix_cel(&m->row[1], 1, sy);
	set_matrix_cel(&m->row[2], 2, sz);
	return (m);
}

t_matrix	*rotation_x(double angle)
{
	t_matrix	*m;

	m = identity_matrix();
	if (!m)
		return (NULL);
	set_matrix_cel(&m->row[1], 1, cos(angle));
	set_matrix_cel(&m->row[1], 2, -sin(angle));
	set_matrix_cel(&m->row[2], 1, sin(angle));
	set_matrix_cel(&m->row[2], 2, cos(angle));
	return (m);
}

t_matrix	*rotation_y(double angle)
{
	t_matrix	*m;

	m = identity_matrix();
	if (!m)
		return (NULL);
	set_matrix_cel(&m->row[0], 0, cos(angle));
	set_matrix_cel(&m->row[0], 2, sin(angle));
	set_matrix_cel(&m->row[2], 0, -sin(angle));
	set_matrix_cel(&m->row[2], 2, cos(angle));
	return (m);
}

t_matrix	*rotation_z(double angle)
{
	t_matrix	*m;

	m = identity_matrix();
	if (!m)
		return (NULL);
	set_matrix_cel(&m->row[0], 0, cos(angle));
	set_matrix_cel(&m->row[0], 1, -sin(angle));
	set_matrix_cel(&m->row[1], 0, sin(angle));
	set_matrix_cel(&m->row[1], 1, cos(angle));
	return (m);
}
