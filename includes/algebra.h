#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <stdlib.h>
# include <math.h>
# include <structs.h>

// Magnitude and normalization

t_tuple	*tuple_normalize(t_tuple *v);
double	tuple_magnitude(t_tuple v);

#endif
