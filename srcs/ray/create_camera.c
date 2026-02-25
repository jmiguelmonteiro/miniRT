#include "miniRT.h"
#include "algebraOperations.h"
#include "ray.h"

static t_tuple	get_world_up(t_camera *cam)
{
	t_tuple	up;

	up.x = 0.0;
	up.y = 1.0;
	up.z = 0.0;
	up.w = 0.0;
	if (fabs(cam->orientation.x) < 1e-5 && fabs(cam->orientation.z) < 1e-5)
	{
		up.y = 0.0;
		up.z = 1.0;
	}
	return (up);
}

static t_matrix	*build_orient(t_camera *cam)
{
	t_tuple		world_up;
	t_tuple		*left;
	t_tuple		*true_up;
	t_matrix	*orient;

	world_up = get_world_up(cam);
	left = tuple_cross(&cam->orientation, &world_up);
	tuple_normalize(left);
	true_up = tuple_cross(left, &cam->orientation);
	orient = identity_matrix();
	set_matrix_cel(&orient->row[0], 0, left->x);
	set_matrix_cel(&orient->row[0], 1, left->y);
	set_matrix_cel(&orient->row[0], 2, left->z);
	set_matrix_cel(&orient->row[1], 0, true_up->x);
	set_matrix_cel(&orient->row[1], 1, true_up->y);
	set_matrix_cel(&orient->row[1], 2, true_up->z);
	set_matrix_cel(&orient->row[2], 0, -cam->orientation.x);
	set_matrix_cel(&orient->row[2], 1, -cam->orientation.y);
	set_matrix_cel(&orient->row[2], 2, -cam->orientation.z);
	free(left);
	free(true_up);
	return (orient);
}

static t_matrix	*build_view_inv(t_camera *cam)
{
	t_matrix	*orient;
	t_matrix	*trans;
	t_matrix	*view;
	t_matrix	*inv;

	orient = build_orient(cam);
	trans = translation(-cam->position.x, -cam->position.y, -cam->position.z);
	view = multiply_matrices(orient, trans);
	free(orient);
	free(trans);
	inv = inverse_matrix(view);
	free(view);
	return (inv);
}

static t_tuple	get_canvas_pt(t_scene *scene, int x, int y)
{
	t_tuple	pt;
	double	hw;
	double	hh;
	double	half_view;
	double	aspect;

	half_view = tan((scene->camera.fov * M_PI / 180.0) / 2.0);
	aspect = (double)scene->width / (double)scene->height;
	if (aspect >= 1.0)
	{
		hw = half_view;
		hh = half_view / aspect;
	}
	else
	{
		hw = half_view * aspect;
		hh = half_view;
	}
	pt.x = hw - (x + 0.5) * (hw * 2.0 / scene->width);
	pt.y = hh - (y + 0.5) * (hw * 2.0 / scene->width);
	pt.z = -1.0;
	pt.w = 1.0;
	return (pt);
}

t_ray	*create_camera_ray(t_scene *scene, int x, int y)
{
	t_matrix	*inv;
	t_tuple		canvas_pt;
	t_tuple		*pixel;
	t_tuple		*origin;
	t_tuple		*dir;

	inv = build_view_inv(&scene->camera);
	canvas_pt = get_canvas_pt(scene, x, y);
	pixel = matrix_multiply_tuple(inv, &canvas_pt);
	origin = matrix_multiply_tuple(inv, &scene->camera.position);
	free(inv);
	dir = tuple_subtract(pixel, origin);
	tuple_normalize(dir);
	free(pixel);
	return (create_ray(origin, dir));
}
