#include <algebra.h>
#include <miniRT.h>

int	is_invertible(t_matrix *m);

double	calc_matrix_cell(t_matrix *a, t_matrix *b, int row, int col)
{
	double	sum;
	int		k;

	sum = 0.0;
	k = 0;
	while (k < 4)
	{
		sum += get_matrix_cel(a, row, k) * get_matrix_cel(b, k, col);
		k++;
	}
	return (sum);
}

t_matrix	*multiply_matrices(t_matrix *matrix_a, t_matrix *matrix_b)
{
	int			i;
	int			j;
	t_matrix	*result;

	i = 0;
	if (!matrix_a || !matrix_b)
		return (NULL);
	result = (t_matrix *)(malloc(sizeof(t_matrix)));
	if (!result)
		return (NULL); // warning to handle errors in the caller function
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			set_matrix_cel(&result->row[i], j,
				calc_matrix_cell(matrix_a, matrix_b, i, j));
			j ++;
		}
		i ++;
	}
	return (result);
}

int	is_invertible(t_matrix *m)
{
	double	det;

	det = determinant(m);
	if (fabs(det) < EPSILON)
		return (0);
	return (1);
}

void	fill_cofactor_matrix(t_matrix *m, t_matrix *cof)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			set_matrix_cel(&cof->row[col], row, cofactor(m, row, col));
			col++;
		}
		row++;
	}
}

t_matrix	*inverse_matrix(t_matrix *m)
{
	t_matrix	*result;
	double		det;
	int			row;
	int			col;

	if (!m || !is_invertible(m))
		return (NULL);
	result = (t_matrix *)malloc(sizeof(t_matrix));
	if (!result)
		return (NULL);
	det = determinant(m);
	fill_cofactor_matrix(m, result);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			set_matrix_cel(&result->row[row], col,
				get_matrix_cel(result, row, col) / det);
			col++;
		}
		row++;
	}
	return (result);
}
