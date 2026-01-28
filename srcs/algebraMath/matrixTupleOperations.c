#include <algebraOperations.h>

t_tuple	*matrix_multiply_tuple(t_matrix *m, t_tuple *t)
{
	t_tuple	*result;

	if (!m || !t)
		return (NULL);
	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = get_matrix_cel(m, 0, 0) * t->x
		+ get_matrix_cel(m, 0, 1) * t->y
		+ get_matrix_cel(m, 0, 2) * t->z
		+ get_matrix_cel(m, 0, 3) * t->w;
	result->y = get_matrix_cel(m, 1, 0) * t->x
		+ get_matrix_cel(m, 1, 1) * t->y
		+ get_matrix_cel(m, 1, 2) * t->z
		+ get_matrix_cel(m, 1, 3) * t->w;
	result->z = get_matrix_cel(m, 2, 0) * t->x
		+ get_matrix_cel(m, 2, 1) * t->y
		+ get_matrix_cel(m, 2, 2) * t->z
		+ get_matrix_cel(m, 2, 3) * t->w;
	result->w = get_matrix_cel(m, 3, 0) * t->x
		+ get_matrix_cel(m, 3, 1) * t->y
		+ get_matrix_cel(m, 3, 2) * t->z
		+ get_matrix_cel(m, 3, 3) * t->w;
	return (result);
}
