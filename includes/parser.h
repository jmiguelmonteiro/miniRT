#ifndef PARSER_H
# define PARSER_H

#include "miniRT.h"

t_scene	*parse_scene(char *filename);
t_scene	*init_scene(void);
bool	*validate_scene(t_scene *scene);

#endif
