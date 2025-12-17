#ifndef MLX_INC_H
# define MLX_INC_H

# include "miniRT.h"
# include "structs.h"
# include "utils.h"

// window dimensions
# define WIDTH 800
# define HEIGHT 800

// mlx_utils.c
void	init_mlx(t_scene *scene);
void	free_mlx(t_scene *scene);

// mlx_handlers.c
int		handle_close(t_scene *scene);
int		handle_key_input(int keysym, t_scene *s);
int		handle_mouse_input(int mouse_code, int x, int y, t_scene *s);
void	init_mlx_handlers(t_scene *scene);

#endif
