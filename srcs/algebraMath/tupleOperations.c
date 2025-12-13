#include <algebraOperations.h>

double	tuple_magnitude(t_tuple v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

void	tuple_normalize(t_tuple *v)
{
	double	mag;

	mag = tuple_magnitude(*v);
	if (mag == 0.0)
	{
		v->x = 0.0;
		v->y = 0.0;
		v->z = 0.0;
		v->w = 0.0;
		return ;
	}
	v->x = v->x / mag;
	v->y = v->y / mag;
	v->z = v->z / mag;
	v->w = v->w / mag;
	return ;
}
