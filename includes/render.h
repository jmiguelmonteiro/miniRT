#ifndef RENDER_H
# define RENDER_H

# include <structs.h>
# include <stdbool.h>

// closest_hit.c
t_hit	find_closest_hit(t_ray *ray, t_scene *scene);
void	find_closest_hit_sphere(t_ray *ray, t_scene *scene, t_hit *closest_hit);
// void	find_closest_hit_plane(t_ray ray, t_scene *scene, t_hit *closest_hit);
// void	find_closest_hit_cylinder(t_ray ray, t_scene *scene,
// 			t_hit *closest_hit);

#endif
