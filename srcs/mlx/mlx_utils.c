/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:14:05 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/04 12:53:33 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_inc.h"
#include <miniRT.h>
#include <utils.h>
#include <algebraOperations.h>

void	free_mlx(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->mlx_img.img_ptr)
		mlx_destroy_image(scene->mlx, scene->mlx_img.img_ptr);
	if (scene->menu.img_ptr)
		mlx_destroy_image(scene->mlx, scene->menu.img_ptr);
	if (scene->mlx_win && scene->mlx)
		mlx_destroy_window(scene->mlx, scene->mlx_win);
	if (scene->mlx)
	{
		mlx_loop_end(scene->mlx);
		mlx_destroy_display(scene->mlx);
		free(scene->mlx);
	}
	return ;
}

static bool	init_mlx_image(t_scene *scene)
{
	scene->mlx_img.img_ptr = mlx_new_image(scene->mlx, scene->width,
			scene->height);
	if (!scene->mlx_img.img_ptr)
		return (mlx_destroy_window(scene->mlx, scene->mlx_win), false);
	scene->mlx_img.img_pixels_ptr = mlx_get_data_addr(
			scene->mlx_img.img_ptr,
			&scene->mlx_img.bits_per_pixel,
			&scene->mlx_img.line_len,
			&scene->mlx_img.endian);
	if (!scene->mlx_img.img_pixels_ptr)
		return (mlx_destroy_image(scene->mlx, scene->mlx_img.img_ptr),
			mlx_destroy_window(scene->mlx, scene->mlx_win), false);
	return (true);
}

bool	init_mlx(t_scene *scene)
{
	scene->width = WINDOW_WIDTH;
	scene->height = WINDOW_HEIGHT;
	printf("Window (WIDTH x HEIGHT): %d x %d\n", scene->width, scene->height);
	scene->mlx = mlx_init();
	if (!scene->mlx)
		return (false);
	scene->mlx_win = mlx_new_window(
			scene->mlx,
			scene->width,
			scene->height,
			"miniRT by josemigu and tmatheusdiniz");
	if (!scene->mlx_win)
		return (false);
	return (init_mlx_image(scene));
}

void	rotate_camera(t_scene *scene, int keysym)
{
	double	angle;

	angle = M_PI / 18.0;
	if (keysym == XK_q)
		rotate_tuple_x(&scene->camera.orientation, -angle);
	else if (keysym == XK_e)
		rotate_tuple_x(&scene->camera.orientation, angle);
	else if (keysym == XK_t)
		rotate_tuple_y(&scene->camera.orientation, -angle);
	else if (keysym == XK_g)
		rotate_tuple_y(&scene->camera.orientation, angle);
	else if (keysym == XK_z)
		rotate_tuple_z(&scene->camera.orientation, -angle);
	else if (keysym == XK_h)
		rotate_tuple_z(&scene->camera.orientation, angle);
	tuple_normalize(&scene->camera.orientation);
}
