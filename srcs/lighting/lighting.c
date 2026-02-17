#include "miniRT.h"
#include "lighting.h"
#include "algebraOperations.h"
#include "render.h"

t_color	apply_ambient(t_color obj_color, t_scene *scene)
{
	t_color	ambient;

	ambient = color_multiply(obj_color, scene->amb_light.color);
	ambient = color_mult(ambient, scene->amb_light.ratio);
	return (ambient);
}

t_color	apply_diffuse(t_hit *hit, t_light light, t_color obj_color)
{
	t_color	diffuse;
	t_tuple	*light_dir;
	double	diffuse_intensity;

	light_dir = tuple_subtract(&light.position, &hit->point);
	tuple_normalize(light_dir);
	diffuse_intensity = fmax(0.0, tuple_dot(&hit->normal, light_dir));
	diffuse_intensity *= light.brightness;
	diffuse = color_multiply(obj_color, light.color);
	diffuse = color_mult(obj_color, diffuse_intensity);
	free(light_dir);
	return (diffuse);
}

bool	is_in_shadow(t_hit *hit, t_light light, t_scene *scene)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;
	double	light_distance;
	t_tuple	*offset;
	t_tuple	*to_light;

	offset = tuple_scalar_multiply(&hit->normal, 0.001);
	to_light = tuple_subtract(&light.position, &hit->point);
	light_distance = tuple_magnitude(*to_light);
	shadow_ray.origin = tuple_add(&hit->point, offset);
	tuple_normalize(to_light);
	shadow_ray.direction = to_light;
	shadow_hit = find_closest_hit(&shadow_ray, scene);
	free(offset);
	free(to_light);
	return (shadow_hit.object && shadow_hit.t < light_distance);
}

t_color	calculate_lighting(t_hit *hit, t_scene *scene)
{
	t_color	final_color;
	t_color	ambient;
	t_color	diffuse;

	ambient = apply_ambient(hit->color, scene);
	final_color = ambient;
	if (!is_in_shadow(hit, scene->light, scene))
	{
		diffuse = apply_diffuse(hit, scene->light, hit->color);
		final_color = color_add(final_color, diffuse);
	}
	final_color = color_clamp(final_color);
	return (final_color);
}
