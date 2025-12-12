#include <algebra.h>

void	set_matrix_cel(t_tuple *row, int col, double value)
{
	if (col == 0)
		row->x = value;
	else if (col == 1)
		row->y = value;
	else if (col == 2)
		row->z = value;
	else
		row->w = value;
}

double	get_matrix_cel(t_matrix *matrix, int row, int col)
{
	if (col == 0)
		return (matrix->row[row].x);
	else if (col == 1)
		return (matrix->row[row].y);
	else if(col == 2)
		return (matrix->row[row].z);
	else
		return (matrix->row[row].w);
}
