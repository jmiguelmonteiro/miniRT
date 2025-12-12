#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <stdlib.h>
# include <math.h>
#include <structs.h>

// Magnitude and normalization
void	tuple_normalize(t_tuple *v);
double	tuple_magnitude(t_tuple *v);

// operations
t_tuple	*tuple_add(t_tuple *a, t_tuple *b);
t_tuple	*tuple_subtract(t_tuple *a, t_tuple *b);
double	tuple_dot(t_tuple *a, t_tuple *b);
t_tuple	*tuple_cross(t_tuple *a, t_tuple *b);

// Aux. functions
void	set_matrix_cel(t_tuple *row, int col, double value);
double	get_matrix_cel(t_matrix *matrix, int row, int col);

// matrices
t_matrix	*add_matrices(t_matrix *matrix_a, t_matrix *matrix_b);
t_matrix	*subtract_matrices(t_matrix *matrix_a, t_matrix *matrix_b);
t_matrix	*multiply_matrices(t_matrix *matrix_a, t_matrix *matrix_b);
t_matrix	*transpose_matrix(t_matrix *m);
t_matrix	*identity_matrix(void);
double		determinant(t_matrix *m);
double		cofactor(t_matrix *m, int row, int col);

#endif
