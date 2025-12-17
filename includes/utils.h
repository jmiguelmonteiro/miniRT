#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"
# include "structs.h"
# include "mlx_inc.h"

t_scene	*init_scene(void);
bool	validate_scene(t_scene *scene);
void	free_scene(t_scene *scene);
void	normalize_scene_tuples(t_scene *scene);
void	exit_minirt(int exit_code, t_scene *scene);

#endif
