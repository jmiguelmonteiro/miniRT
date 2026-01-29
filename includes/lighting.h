#ifndef LIGHTING_H
# define LIGHTING_H

# include <structs.h>

t_color	apply_ambient(t_color obj_color, t_scene *scene);
t_color	apply_diffuse(t_hit *hit, t_light light, t_color obj_color);
bool	is_in_shadow(t_tuple point, t_light light, t_scene *scene);
t_color	calculate_lighting(t_hit *hit, t_scene *scene, t_ray ray);

#endif
