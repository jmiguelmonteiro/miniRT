#ifndef RENDER_H
# define RENDER_H

# include <structs.h>
# include <stdbool.h>

// intersection.c
t_hit	find_closest_hit(t_ray *ray, t_scene *scene);
void	find_closest_hit_sphere(t_ray *ray, t_scene *scene, t_hit *closest_hit);
// void	find_closest_hit_plane(t_ray ray, t_scene *scene, t_hit *closest_hit);
// void	find_closest_hit_cylinder(t_ray ray, t_scene *scene,
// 			t_hit *closest_hit);

// render.c
void	render_scene(t_scene *scene);
t_color	trace_ray(t_ray *ray, t_scene *scene);
void	put_pixel(t_scene *scene, int x, int y, t_color color);

#endif
