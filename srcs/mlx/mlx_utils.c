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
