/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:14:11 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 15:23:52 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"
#include "utils.h"
#include "parser.h"
#include "mlx_inc.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		print_error(BOLD "Usage: ./miniRT <scene_file>" DEFAULT, NULL, NULL);
	scene = parse_scene(argv[1]);
	if (!scene)
		return (EXIT_FAILURE);
	if (!init_mlx(scene))
		print_error("MLX initialization failed", NULL, scene);
	init_selection(scene);
	start_menu(scene);
	render_scene(scene);
	mlx_put_image_to_window(scene->mlx, scene->mlx_win,
		scene->mlx_img.img_ptr, 0, 0);
	render_menu(scene);
	init_mlx_handlers(scene);
	mlx_loop(scene->mlx);
	return (EXIT_SUCCESS);
}
