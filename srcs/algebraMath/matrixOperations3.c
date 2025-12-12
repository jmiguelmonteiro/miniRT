#include <algebra.h>

double	determinant_3x3(double m[3][3]);
double	minor(t_matrix *m, int row, int col);
double	cofactor(t_matrix *m, int row, int col);

void	fill_submatrix(t_matrix *m, double sub_matrix[3][3], int skip_r, int ship_c)
{
	int	row;
	int	col;
	int	sub_row;
	int sub_col;

	row = -1;
	sub_row = 0;
	while (++row < 4)
	{
		if (row != skip_r)
		{
			col = 0;
			sub_col = 0;
			while (col < 4)
			{
				if (col != ship_c)
				{
					sub_matrix[sub_row][sub_col] = get_matrix_cel(m, row, col);
					++sub_col;
				}
				++ col;
			}
			++sub_row;
		}
	}
}

double	determinant_3x3(double m[3][3])
{
	double	det;

	det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
	det -= m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]);
	det += m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	return (det);
}

double	minor(t_matrix *m, int row, int col)
{
	double	sub[3][3];

	fill_submatrix(m, sub, row, col);
	return (determinant_3x3(sub));
}

double	cofactor(t_matrix *m, int row, int col)
{
	double	min;

	min = minor(m, row, col);
	if ((row + col) % 2 == 1)
		return (-min);
	return (min);
}

double	determinant(t_matrix *m)
{
	double	det;
	int		col;

	if (!m)
		return (0.0);
	det = 0.0;
	col = 0;
	while (col < 4)
	{
		det += get_matrix_cel(m, 0, col) * cofactor(m, 0, col);
		col++;
	}
	return (det);
}
