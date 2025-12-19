#include "mlx_inc.h"

void	free_mlx(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->mlx_img.img_ptr)
		mlx_destroy_image(scene->mlx, scene->mlx_img.img_ptr);
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

void	init_mlx(t_scene *scene)
{
	scene->width = WINDOW_WIDTH;
	scene->height = WINDOW_HEIGHT;
	scene->mlx = mlx_init();
	if (!scene->mlx)
		exit_minirt(EXIT_FAILURE, scene);
	scene->mlx_win = mlx_new_window(
			scene->mlx,
			scene->width,
			scene->height,
			"miniRT by josemigu and mreinald");
	if (!scene->mlx_win)
		exit_minirt(EXIT_FAILURE, scene);
	scene->mlx_img.img_ptr = mlx_new_image(
			scene->mlx,
			scene->width,
			scene->height);
	if (!scene->mlx_img.img_ptr)
		exit_minirt(EXIT_FAILURE, scene);
	scene->mlx_img.img_pixels_ptr = mlx_get_data_addr(
			scene->mlx_img.img_ptr,
			&scene->mlx_img.bits_per_pixel,
			&scene->mlx_img.line_len,
			&scene->mlx_img.endian);
}
