#include "miniRT.h"
#include "structs.h"

// Create color
t_color	color_new(double r, double g, double b)
{
	t_color	c;

	c.red = r;
	c.green = g;
	c.blue = b;
	return (c);
}

// Add colors
t_color	color_add(t_color a, t_color b)
{
	t_color	result;

	result.red = a.red + b.red;
	result.green = a.green + b.green;
	result.blue = a.blue + b.blue;
	return (result);
}

// Multiply color by scalar
t_color	color_mult(t_color c, double scalar)
{
	t_color	result;

	result.red = c.red * scalar;
	result.green = c.green * scalar;
	result.blue = c.blue * scalar;
	return (result);
}

// Multiply two colors (Hadamard product)
t_color	color_multiply(t_color a, t_color b)
{
	t_color	result;

	result.red = a.red * b.red;
	result.green = a.green * b.green;
	result.blue = a.blue * b.blue;
	return (result);
}

// Clamp color to [0, 1]
t_color	color_clamp(t_color c)
{
	t_color	result;

	result.red = fmax(0.0, fmin(1.0, c.red));
	result.green = fmax(0.0, fmin(1.0, c.green));
	result.blue = fmax(0.0, fmin(1.0, c.blue));
	return (result);
}
