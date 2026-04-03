/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:15:34 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 14:43:32 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON		0.00001
# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# include <X11/X.h>
# include <X11/keysym.h>

// Menu
# define MENU_WIDTH			350
# define MENU_HEIGHT		540
# define M_STR_COLOR		0x2ECC71
# define CONTROL_BOX		180
# define MENU_X				30
# define SPACE_B_LINES		30
# define TRANSLATION_MSG	"W/S (Z-Axis) | A/D (X-Axis) | R/F (Y-Axis)"
# define ROTATION_MSG		"Q/E (X-Axis) | T/G (Y-Axis) | Z/H (Z-Axis)"
# define ANIMATION_MSG		"Select the objects by using left/right arrows and the light by using up/down arrows"

// Background
# define M_BG_C		0x0D1D3B // Menu Background color
# define M_B_COLOR	0x2C7DB3
# define B_W		4 // Border width

// Basic colors
# define DEFAULT "\033[0;39m"
# define GRAY "\033[0;90m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"
# define RED "\033[0;91m"

// Bold colors
# define BOLD "\033[1m"
# define B_GRAY "\033[1;90m"
# define B_GREEN "\033[1;92m"
# define B_YELLOW "\033[1;93m"
# define B_BLUE "\033[1;94m"
# define B_MAGENTA "\033[1;95m"
# define B_CYAN "\033[1;96m"
# define B_WHITE "\033[1;97m"
# define B_BROWN "\033[1;33m"
# define B_RED "\033[1;91m"

// Light colors (bright colors)
# define L_GRAY "\033[0;37m"
# define L_RED "\033[1;31m"
# define L_GREEN "\033[1;32m"
# define L_YELLOW "\033[1;33m"
# define L_BLUE "\033[1;34m"
# define L_MAGENTA "\033[1;35m"
# define L_CYAN "\033[1;36m"
# define L_WHITE "\033[1;37m"

// Light versions of colors
# define LIGHT_GRAY "\033[0;37m"
# define DARK_GRAY "\033[1;30m"

// Light brown/orange
# define LIGHT_BROWN "\033[1;33m"
# define ORANGE "\033[0;38;5;208m"

#endif
