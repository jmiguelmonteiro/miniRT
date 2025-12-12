#ifndef UTILS_H
# define UTILS_H

# include <structs.h>
# include <stdbool.h>

t_scene	*init_scene(void);
bool	validate_scene(t_scene *scene);
void	free_scene(t_scene *scene);
void	normalize_scene_tuples(t_scene *scene);

#endif
