#include <algebra.h>

t_tuple	*tuple_scalar_multiply(t_tuple *v, double scalar)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = v->x * scalar;
	result->y = v->y * scalar;
	result->z = v->z * scalar;
	result->w = v->w * scalar;
	return (result);
}

t_tuple	*tuple_scalar_divide(t_tuple *v, double scalar)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	if (scalar == 0.0)
	{
		free(result);
		return (NULL);
	}
	result->x = v->x / scalar;
	result->y = v->y / scalar;
	result->z = v->z / scalar;
	result->w = v->w / scalar;
	return (result);
}

t_tuple	*tuple_negate(t_tuple *v)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = -v->x;
	result->y = -v->y;
	result->z = -v->z;
	result->w = -v->w;
	return (result);
}

t_tuple	*tuple_hadamard(t_tuple *a, t_tuple *b)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = a->x * b->x;
	result->y = a->y * b->y;
	result->z = a->z * b->z;
	result->w = a->w * b->w;
	return (result);
}

t_tuple	*tuple_reflect(t_tuple *v, t_tuple *normal)
{
	t_tuple	*result;
	t_tuple	*scaled;
	double	dot;

	dot = tuple_dot(v, normal);
	scaled = tuple_scalar_multiply(normal, 2.0 * dot);
	if (!scaled)
		return (NULL);
	result = tuple_subtract(v, scaled);
	free(scaled);
	return (result);
}
