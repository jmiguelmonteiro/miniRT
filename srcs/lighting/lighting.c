#include "miniRT.h"
#include "lighting.h"
#include "algebraOperations.h"

t_color	apply_ambient(t_color obj_color, t_scene *scene)
{
	t_color	result;

	result.red = (obj_color.red * scene->amb_light.color.red / 255) *
		scene->amb_light.ratio;
	result.green = (obj_color.green * scene->amb_light.color.green / 255) *
		scene->amb_light.ratio;
	result.blue = (obj_color.blue * scene->amb_light.color.blue / 255) *
		scene->amb_light.ratio;
	return (result);
}

t_color	apply_diffuse(t_hit *hit, t_light light, t_color obj_color)
{
	t_tuple	light_dir;
	double	diffuse_intensity;
	t_color	result;

	light_dir = tuple_normalize(tuple_subtract(light.position, hit->point));
	diffuse_intensity = fmax(0.0, tuple_dot(hit->normal, light_dir));
	diffuse_intensity *= light.brightness;
	result.red = obj_color.red * diffuse_intensity;
	result.green = obj_color.green * diffuse_intensity;
	result.blue = obj_color.blue * diffuse_intensity;
	return (result);
}

bool	is_in_shadow(t_tuple point, t_light light, t_scene *scene)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;
	double	light_distance;

	shadow_ray.origin = tuple_add(point, tuple_scalar_multiply(tuple_normalize(point)), 0.001);
	shadow_ray.direction = tuple_normalize(tuple_subtract(light.position, point));
	light_distance = tuple_magnitude(tuple_subtract(light.position, point));

    // Check if anything blocks the light
    // Use Person A's find_closest_hit but check if t < light_distance
    shadow_hit = find_closest_hit(shadow_ray, scene);

	return(shadow_hit.hit && shadow_hit.t < light_distance);
}

t_color	calculate_lighting(t_hit *hit, t_scene *scene, t_ray ray)
{
	t_color	final_color;
	t_color	ambient;
	t_color	diffuse;

	ambient = apply_ambient(hit->color, scene);
	final_color = ambient;
	if (is_in_shadow(hit->point, scene->light, scene))
		return (final_color);
	diffuse(apply_diffuse(hit, scene->light, hit->color));
	final_color.red = fmin(255, final_color.red + diffuse.red);
	final_color.green = fmin(255, final_color.green + diffuse.green);
	final_color.blue = fmin(255, final_color.blue + diffuse.blue);
	return (final_color);
}
