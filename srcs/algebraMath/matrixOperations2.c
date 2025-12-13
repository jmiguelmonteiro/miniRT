#include <algebraOperations.h>
#include <libft.h>

t_matrix	*add_matrices(t_matrix *matrix_a, t_matrix *matrix_b)
{
	int			i;
	t_matrix	*result;

	i = 0;
	if (!matrix_a || !matrix_b)
		return (NULL);
	result = (t_matrix *)(malloc(sizeof(t_matrix)));
	if (!result)
		return (NULL);
	while (i < 4)
	{
		result->row[i].x = matrix_a->row[i].x + matrix_b->row[i].x;
		result->row[i].y = matrix_a->row[i].y + matrix_b->row[i].y;
		result->row[i].z = matrix_a->row[i].z + matrix_b->row[i].z;
		result->row[i].w = matrix_a->row[i].w + matrix_b->row[i].w;
		i ++;
	}
	return (result);
}

t_matrix	*subtract_matrices(t_matrix *matrix_a, t_matrix *matrix_b)
{
	int			i;
	t_matrix	*result;

	i = 0;
	if (!matrix_a || !matrix_b)
		return (NULL);
	result = (t_matrix *)(malloc(sizeof(t_matrix)));
	if (!result)
		return (NULL);
	while (i < 4)
	{
		result->row[i].x = matrix_a->row[i].x - matrix_b->row[i].x;
		result->row[i].y = matrix_a->row[i].y - matrix_b->row[i].y;
		result->row[i].z = matrix_a->row[i].z - matrix_b->row[i].z;
		result->row[i].w = matrix_a->row[i].w - matrix_b->row[i].w;
		i ++;
	}
	return (result);
}

t_matrix	*transpose_matrix(t_matrix *m)
{
	t_matrix	*result;
	int			i;
	int			j;

	if (!m)
		return (NULL);
	result = (t_matrix *)malloc(sizeof(t_matrix));
	if (!result)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			set_matrix_cel(result->row, j, get_matrix_cel(m, j, i));
			j++;
		}
		i++;
	}
	return (result);
}

t_matrix	*identity_matrix(void)
{
	t_matrix	*result;

	result = (t_matrix *)malloc(sizeof(t_matrix));
	if (!result)
		return (NULL);
	ft_memset(result, 0, sizeof(t_matrix));
	result->row[0].x = 1.0;
	result->row[1].y = 1.0;
	result->row[2].z = 1.0;
	result->row[3].w = 1.0;
	return (result);
}
