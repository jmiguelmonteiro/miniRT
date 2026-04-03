/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:04:03 by mreinald          #+#    #+#             */
/*   Updated: 2026/04/03 14:19:43 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <structs.h>
#include <mlx_inc.h>

static void	print_string(t_scene *scene, int x, int y, char *str)
{
	mlx_string_put(scene->mlx, scene->mlx_win, x, y, M_STR_COLOR, str);
}

void	start_menu(t_scene *scene)
{
	scene->menu.img_ptr = mlx_new_image(scene->mlx, MENU_WIDTH, MENU_HEIGHT);
	if (!scene->menu.img_ptr)
		free_mlx(scene);
	scene->menu.addr = mlx_get_data_addr(scene->menu.img_ptr,
			&scene->menu.bits_p_pixel, &scene->menu.l_length, &scene->menu.endian);
}

void	render_menu(t_scene *scene)
{
	int	y;

	y = 20;
	print_string(scene, MENU_X - 20, y, "-- miniRT menu --");
	y = CONTROL_BOX;
	print_string(scene, MENU_X, y, "INSTRUCTIONS:");
	y += SPACE_B_LINES;
	print_string(scene, MENU_X + 10, y, "Rotation:");
	y += SPACE_B_LINES - 10;
	print_string(scene, MENU_X + 20, y, ROTATION_MSG);
	y += SPACE_B_LINES;
	print_string(scene, MENU_X + 10, y, "Translation:");
	y += SPACE_B_LINES - 10;
	print_string(scene, MENU_X + 20, y, TRANSLATION_MSG);
	y += SPACE_B_LINES - 10;
	print_string(scene, MENU_X + 10, y, "Animation:");
	y += SPACE_B_LINES - 10;
	print_string(scene, MENU_X + 20, y, ANIMATION_MSG);
	y+= SPACE_B_LINES;
	print_string(scene, MENU_X + 20, y, ANIMATION_MSG_LEFT);
	y+= SPACE_B_LINES;
	print_string(scene, MENU_X + 10, y, "Press ESC for exit!!!");
}
