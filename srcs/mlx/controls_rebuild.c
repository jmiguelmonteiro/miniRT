#include "miniRT.h"
#include "mlx_inc.h"
#include "algebraOperations.h"

t_matrix	*build_plane_transform(t_plane *plane);
t_matrix	*build_cyl_transform(t_cylinder *cyl);

void	rebuild_sphere_transform(t_sphere *sphere)
{
	t_matrix	*scale;
	t_matrix	*trans;
	double		radius;

	if (sphere->transform)
		free(sphere->transform);
	radius = sphere->diameter / 2.0;
	scale = scaling(radius, radius, radius);
	trans = translation(sphere->center.x, sphere->center.y, sphere->center.z);
	sphere->transform = multiply_matrices(trans, scale);
	free(scale);
	free(trans);
}

void	rebuild_plane_transform(t_plane *plane)
{
	if (plane->transform)
		free(plane->transform);
	plane->transform = build_plane_transform(plane);
}

void	rebuild_cylinder_transform(t_cylinder *cyl)
{
	if (cyl->transform)
		free(cyl->transform);
	cyl->transform = build_cyl_transform(cyl);
}
