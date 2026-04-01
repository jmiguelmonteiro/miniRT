#ifndef MLX_INC_H
# define MLX_INC_H

# include "structs.h"

// mlx_utils.c
bool	init_mlx(t_scene *scene);
void	free_mlx(t_scene *scene);

// mlx_handlers.c
int		handle_close(t_scene *scene);
int		handle_key_input(int keysym, t_scene *s);
int		handle_mouse_input(int mouse_code, int x, int y, t_scene *s);
void	init_mlx_handlers(t_scene *scene);

// controls_selection.c
void	init_selection(t_scene *scene);
void	cycle_selection(t_scene *scene, int direction);

// controls_selection2.c
void	select_by_index(t_scene *scene, int idx);

// controls_transform.c
void	handle_translate(t_scene *scene, int keysym);

// controls_resize.c
void	handle_resize(t_scene *scene, int keysym);
void	handle_light_brightness(t_scene *scene, int keysym);

// controls_rotate.c
void	handle_rotate(t_scene *scene, int keysym);

// controls_rebuild.c
void	rebuild_sphere_transform(t_sphere *sphere);
void	rebuild_plane_transform(t_plane *plane);
void	rebuild_cylinder_transform(t_cylinder *cyl);

// transform_build.c
t_matrix	*build_plane_transform(t_plane *plane);
t_matrix	*build_cyl_transform(t_cylinder *cyl);

#endif
