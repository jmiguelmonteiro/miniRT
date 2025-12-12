#include <algebraOperations.h>

t_tuple	*tuple_add(t_tuple *a, t_tuple *b)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
	result->w = a->w + b->w;
	return (result);
}

t_tuple	*tuple_subtract(t_tuple *a, t_tuple *b)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
	result->w = a->w - b->w;
	return (result);
}

double	tuple_dot(t_tuple *a, t_tuple *b)
{
	double	result;

	result = a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
	return (result);
}

t_tuple	*tuple_cross(t_tuple *a, t_tuple *b)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = a->y * b->z - a->z * b->y;
	result->y = a->z * b->x - a->x * b->z;
	result->z = a->x * b->y - a->y * b->x;
	result->w = 0.0;
	return (result);
}
