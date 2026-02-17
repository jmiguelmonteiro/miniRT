#include "miniRT.h"
#include "structs.h"

// Convert to int for MLX (0-255)
int	color_to_int(t_color c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(c.red * 255.0);
	g = (int)(c.green * 255.0);
	b = (int)(c.blue * 255.0);
	r = fmax(0, fmin(255, r));
	g = fmax(0, fmin(255, g));
	b = fmax(0, fmin(255, b));
	return ((r << 16) | (g << 8) | b);
}
