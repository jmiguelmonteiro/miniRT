#include "miniRT.h"

void	skip_whitespaces(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

int	ft_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	return (sign);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	double	result;
	double	fraction;
	int		sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = ft_sign(&nptr);
	result = 0.0;
	while (ft_isdigit(*nptr))
		result = result * 10.0 + (*nptr++ - '0');
	if (*nptr == '.')
	{
		nptr++;
		fraction = 0.1;
		while (ft_isdigit(*nptr))
		{
			result += (*nptr++ - '0') * fraction;
			fraction *= 0.1;
		}
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}

double	ft_strtoi(const char *nptr, char **endptr)
{
	int		result;
	int		sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = ft_sign(&nptr);
	result = 0;
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - '0');
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}

void	print_error(char *message, char *arg, t_scene *scene)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (scene)
		free_scene(scene);
	exit(EXIT_FAILURE);
}

void	print_scene(t_scene *scene)
{
	printf("Scene Details:\n\n");
	printf("Ambient Light Ratio: %lf\n", scene->amb_light.ratio);
	printf("Ambient Light Color: (%lf, %lf, %lf)\n", scene->amb_light.color.red,
		scene->amb_light.color.green, scene->amb_light.color.blue);
	printf("Camera Position: (%lf, %lf, %lf)\n", scene->camera.position.x,
		scene->camera.position.y, scene->camera.position.z);
	printf("Camera Orientation: (%lf, %lf, %lf)\n", scene->camera.orientation.x,
		scene->camera.orientation.y, scene->camera.orientation.z);
	printf("Camera FOV: %lf\n", scene->camera.fov);
	printf("Light Position: (%lf, %lf, %lf)\n", scene->light.position.x,
		scene->light.position.y, scene->light.position.z);
	printf("Light Brightness: %lf\n", scene->light.brightness);
	printf("Light Color: (%lf, %lf, %lf)\n", scene->light.color.red,
		scene->light.color.green, scene->light.color.blue);
}
