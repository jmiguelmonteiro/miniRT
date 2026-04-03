/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:13:55 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 15:24:26 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx_inc.h"
#include "render.h"
#include "utils.h"

static void	re_render(t_scene *scene)
{
	render_scene(scene);
	mlx_put_image_to_window(scene->mlx, scene->mlx_win,
		scene->mlx_img.img_ptr, 0, 0);
	render_menu(scene);
}

static int	is_transform_key(int keysym)
{
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
		return (1);
	if (keysym == XK_r || keysym == XK_f)
		return (1);
	if (keysym == XK_q || keysym == XK_e || keysym == XK_t || keysym == XK_g)
		return (1);
	if (keysym == XK_z || keysym == XK_h)
		return (1);
	if (keysym == XK_plus || keysym == XK_minus || keysym == XK_equal)
		return (1);
	if (keysym == XK_Up || keysym == XK_Down)
		return (1);
	return (0);
}

int	handle_key_input(int keysym, t_scene *s)
{
	if (keysym == XK_Escape)
		handle_close(s);
	else if (keysym == XK_Left)
		cycle_selection(s, -1);
	else if (keysym == XK_Right)
		cycle_selection(s, 1);
	else if (keysym == XK_Up || keysym == XK_Down)
		handle_light_brightness(s, keysym);
	else if (keysym == XK_w || keysym == XK_s || keysym == XK_a
		|| keysym == XK_d || keysym == XK_r || keysym == XK_f)
		handle_translate(s, keysym);
	else if (keysym == XK_q || keysym == XK_e
		|| keysym == XK_t || keysym == XK_g
		|| keysym == XK_z || keysym == XK_h)
		handle_rotate(s, keysym);
	else if (keysym == XK_plus || keysym == XK_minus || keysym == XK_equal)
		handle_resize(s, keysym);
	if (is_transform_key(keysym))
		re_render(s);
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
