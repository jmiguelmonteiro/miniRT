#ifndef RAY_H
# define RAY_H

# include <structs.h>
# include <stdbool.h>

t_ray	*create_ray(t_tuple *origin, t_tuple *direction);
t_tuple	*ray_position(t_ray *ray, double t);
void	free_ray(t_ray *ray);
t_tuple	*sphere_normal_at(t_sphere *sphere, t_tuple *point);
bool	intersect_sphere(t_ray *ray, t_sphere *sphere, double *t_values);
double	get_closest_intersection(double *t_values, int count);
t_hit	*ray_hit_sphere(t_ray *ray, t_sphere *sphere);
t_hit	*create_hit(double t, t_ray *ray, t_sphere *sphere);
void	free_hit(t_hit *hit);
t_ray	*transform_ray(t_ray *ray, t_matrix *matrix);
t_ray	*create_camera_ray(t_scene *scene, int x, int y);

#endif
