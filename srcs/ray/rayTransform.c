#include <miniRT.h>
#include <structs.h>
#include <algebraOperations.h>
#include <ray.h>

t_ray	*transform_ray(t_ray *ray, t_matrix *matrix)
{
	t_ray	*transformed_ray;
	t_tuple	*new_origin;
	t_tuple	*new_direction;

	if (!ray || !matrix)
		return (NULL);
	new_origin = matrix_multiply_tuple(matrix, ray->origin);
	if (!new_origin)
		return (NULL);
	new_direction = matrix_multiply_tuple(matrix, ray->direction);
	if (!new_direction)
	{
		free(new_origin);
		return (NULL);
	}
	transformed_ray = create_ray(new_origin, new_direction);
	if (!transformed_ray)
	{
		free(new_origin);
		free(new_direction);
		return (NULL);
	}
	return (transformed_ray);
}
