#include <miniRT.h>
#include <algebraOperations.h>
#include <structs.h>

t_material	default_material(void)
{
	t_material	mat;

	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200.0;
	return (mat);
}

t_sphere	*create_sphere(t_tuple center, double diameter, t_color color)
{
	t_sphere	*sphere;
	t_matrix	*translation_m;
	t_matrix	*scaling_m;
	double		radius;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->diameter = diameter;
	sphere->color = color;
	sphere->material = default_material();
	radius = diameter / 2.0;
	translation_m = translation(center.x, center.y, center.z);
	scaling_m = scaling(radius, radius, radius);
	sphere->transform = multiply_matrices(translation_m, scaling_m);
	free(translation_m);
	free(scaling_m);
	sphere->next = NULL;
	return (sphere);
}

void	set_sphere_transform(t_sphere *sphere, t_matrix *transform)
{
	if (!sphere || !transform)
		return ;
	if (sphere->transform)
		free(sphere->transform);
	sphere->transform = transform;
}
