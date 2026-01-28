#include <miniRT.h>
#include <lighting.h>

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
