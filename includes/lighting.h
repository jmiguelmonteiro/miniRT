#ifndef LIGHTING_H
# define LIGHTING_H

# include <structs.h>

// color.c
t_color	color_new(double r, double g, double b);
t_color	color_add(t_color a, t_color b);
t_color	color_mult(t_color c, double scalar);
t_color	color_multiply(t_color a, t_color b);
t_color	color_clamp(t_color c);

// color2.c
int		color_to_int(t_color c);

// lighting.c
t_color	apply_ambient(t_color obj_color, t_scene *scene);
t_color	apply_diffuse(t_hit *hit, t_light light, t_color obj_color);
t_color	calculate_lighting(t_hit *hit, t_scene *scene);

// shadows.c
bool	is_in_shadow(t_hit *hit, t_light *light, t_scene *scene);
t_ray	*create_shadow_ray(t_tuple point, t_tuple offset, t_tuple to_light);
bool	is_path_blocked(t_ray *shadow_ray, t_scene *scene,
			double light_distance);

#endif
