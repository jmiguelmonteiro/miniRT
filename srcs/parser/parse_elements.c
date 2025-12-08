#include "miniRT.h"

double	parse_double(char **str, t_scene *scene)
{
	double	result;
	char	*endptr;

	result = ft_strtod(*str, &endptr);
	if (endptr == *str)
	{
		print_error("Parsing double value: ", *str, scene);
		return (0.0);
	}
	*str = endptr;
	return (result);
}

double	parse_color_value(char **str, t_scene *scene)
{
	double	value;
	char	*endptr;

	value = ft_strtoi(*str, &endptr) / 255.0;
	if (endptr == *str)
		print_error("Parsing color value: ", *str, scene);
	if (value < 0.0 || value > 1.0)
		print_error("Color value out of range [0-255]: ", *str, scene);
	*str = endptr;
	return (value);
}

t_color	parse_color(char **str, t_scene *scene)
{
	t_color	color;

	color.red = parse_color_value(str, scene);
	if (**str != ',')
		print_error("Expected ',' in color value: ", *str, scene);
	(*str)++;
	color.green = parse_color_value(str, scene);
	if (**str != ',')
		print_error("Expected ',' in color value: ", *str, scene);
	(*str)++;
	color.blue = parse_color_value(str, scene);
	return (color);
}

t_tuple	parse_tuple(char **str, t_scene *scene, bool is_point)
{
	t_tuple	result;

	result.x = parse_double(str, scene);
	if (**str != ',')
		print_error("Expected ',' in point value: ", *str, scene);
	(*str)++;
	result.y = parse_double(str, scene);
	if (**str != ',')
		print_error("Expected ',' in point value: ", *str, scene);
	(*str)++;
	result.z = parse_double(str, scene);
	if (is_point)
		result.w = 1.0;
	else
		result.w = 0.0;
	return (result);
}
