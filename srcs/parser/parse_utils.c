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
