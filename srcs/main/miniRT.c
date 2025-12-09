/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:40:09 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/08 22:40:20 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void)argc;

	if (argc != 2)
	{
		print_error("Usage: ./miniRT <scene_file>", NULL, NULL);
		return (EXIT_FAILURE);
	}
	scene = parse_scene(argv[1]);
	if (!scene)
		return (EXIT_FAILURE);
	free_scene(scene);
	return (EXIT_SUCCESS);
}
