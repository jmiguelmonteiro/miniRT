#ifndef PARSER_H
# define PARSER_H

# include <structs.h>
# include <stdbool.h>

// parser.c
t_scene	*parse_scene(char *filename);
void	parse_line(char *line, t_scene *scene);

// parse_objects.c
void	parse_ambient_light(char *line, t_scene *scene);
void	parse_camera(char *line, t_scene *scene);
void	parse_light(char *line, t_scene *scene);

// parse_objects2.c
void	parse_sphere(char *line, t_scene *scene);
void	parse_plane(char *line, t_scene *scene);
void	parse_cylinder(char *line, t_scene *scene);

// parse_elements.c
double	parse_double(char **str, t_scene *scene);
t_color	parse_color(char **str, t_scene *scene);
t_tuple	parse_tuple(char **str, t_scene *scene, bool is_point);

// parse_utils.c
void	skip_whitespaces(char **str);
double	ft_strtod(const char *nptr, char **endptr);
double	ft_strtoi(const char *nptr, char **endptr);
void	print_error(char *message, char *arg, t_scene *scene);

// parse_utils2.c
void	print_scene(t_scene *scene);
void	print_scene2(t_scene *scene);
void	print_scene3(t_scene *scene);

#endif
