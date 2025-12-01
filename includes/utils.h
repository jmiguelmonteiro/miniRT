#ifndef UTILS_H
# define UTILS_H

#include "miniRT.h"

t_scene	*init_scene(void);
bool	validate_scene(t_scene *scene);
void	free_scene(t_scene *scene);

#endif
