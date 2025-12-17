#include "mlx_inc.h"

int	handle_close(t_scene *scene)
{
	exit_minirt(EXIT_SUCCESS, scene);
	return (EXIT_SUCCESS);
}

int	handle_key_input(int keysym, t_scene *s)
{
	if (keysym == XK_Escape)
		handle_close(s);
	return (EXIT_SUCCESS);
}

int	handle_mouse_input(int mouse_code, int x, int y, t_scene *s)
{
	(void)mouse_code;
	(void)x;
	(void)y;
	(void)s;
	return (EXIT_SUCCESS);
}

void	init_mlx_handlers(t_scene *scene)
{
	mlx_key_hook((*scene).mlx_win, handle_key_input, scene);
	mlx_mouse_hook((*scene).mlx_win, handle_mouse_input, scene);
	mlx_hook((*scene).mlx_win, DestroyNotify, StructureNotifyMask,
		handle_close, scene);
}
