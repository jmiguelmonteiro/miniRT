#include <algebra.h>

double	tuple_magnitude(t_tuple v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

t_tuple	*tuple_normalize(t_tuple *v)
{
	double	mag;
	t_tuple	*result;

	result = NULL;
	mag = tuple_magnitude(*v);
	if (mag == 0.0)
	{
		result->x = 0.0;
		result->y = 0.0;
		result->z = 0.0;
		result->w = 0.0;
		return (result);
	}
	result->x = v->x / mag;
	result->y = v->y / mag;
	result->z = v->z / mag;
	result->w = v->w / mag;
	return (result);
}
