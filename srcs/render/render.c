#include "miniRT.h"
#include "structs.h"
#include "render.h"
#include "lighting.h"
#include "ray.h"

void	render_scene(t_scene *scene)
{
	int		x;
	int		y;
	// t_ray	ray;
	// t_color	color;

	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			// ray = create_camera_ray(&scene->camera, x, y, 
			//                         scene->width, scene->height);
			// color = trace_ray(&ray, scene);
			// put_pixel(scene, x, y, color);
			// free_ray(&ray);
			x++;
		}
		y++;
	}
}

t_color	trace_ray(t_ray *ray, t_scene *scene)
{
	t_hit	hit;
	t_color	final_color;

	hit = find_closest_hit(ray, scene);
	if (!hit.object)
		return (color_new(0, 0, 0));
	final_color = calculate_lighting(&hit, scene);
	return (final_color);
}

void	put_pixel(t_scene *scene, int x, int y, t_color color)
{
	char	*dst;
	int		pixel_color;

	pixel_color = color_to_int(color);
	dst = scene->mlx_img.img_pixels_ptr + (y * scene->mlx_img.line_len
			+ x * (scene->mlx_img.bits_per_pixel / 8));
	*(unsigned int *)dst = pixel_color;
}
