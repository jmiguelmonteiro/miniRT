#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

typedef struct s_matrix
{
	t_tuple	row[4];
}	t_matrix;

typedef struct s_amb_light
{
	double	ratio;
	t_color	color;
	bool	defined;
}	t_amb_light;

typedef struct s_camera
{
	t_tuple	position;
	t_tuple	orientation;
	double	fov;
	bool	defined;
}	t_camera;

typedef struct s_light
{
	t_tuple	position;
	double	brightness;
	t_color	color;
	bool	defined;
}	t_light;

typedef struct s_sphere
{
	t_tuple			center;
	double			diameter;
	t_color			color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_tuple			point;
	t_tuple			normal;
	t_color			color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple				center;
	t_tuple				normal;
	double				diameter;
	double				height;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_scene
{
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
	void		*mlx;
	void		*mlx_win;
	t_image		mlx_img;
	int			width;
	int			height;
}	t_scene;

#endif
