#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON 0.00001

//# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "parser.h"
# include "utils.h"

// when w = 0 vector
//		w = 1 point
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct	s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

typedef struct s_amb_light
{
	double	ratio;
	t_color	color;
}	t_amb_light;

typedef struct s_camera
{
	t_tuple	position;
	t_tuple	orientation;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_tuple	position;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_sphere
{
	t_tuple		center;
	double		diameter;
	t_color		color;
	t_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_tuple	point;
	t_tuple	normal;
	t_color	color;
	t_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple		center;
	t_tuple		normal;
	double		diameter;
	double		height;
	t_color		color;
	t_cylinder	*next;
}	t_cylinder;

typedef struct s_scene
{
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;

}	t_scene;

#endif
