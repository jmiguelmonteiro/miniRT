#include <algebraOperations.h>

t_matrix	*shearing(double xy, double xz, double yx, double yz, double zx, double zy)
{
	t_matrix	*m;

	m = identity_matrix();
	if (!m)
		return (NULL);
	set_matrix_cel(&m->row[0], 1, xy);
	set_matrix_cel(&m->row[0], 2, xz);
	set_matrix_cel(&m->row[1], 0, yx);
	set_matrix_cel(&m->row[1], 2, yz);
	set_matrix_cel(&m->row[2], 0, zx);
	set_matrix_cel(&m->row[2], 1, zy);
	return (m);
}
