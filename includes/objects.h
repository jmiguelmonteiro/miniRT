/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:15:42 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:15:43 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <structs.h>

//Plane
t_plane		*create_plane(t_tuple point, t_tuple normal, t_color color);

// Sphers
t_sphere	*create_sphere(t_tuple center, double diameter, t_color color);
void		set_sphere_transform(t_sphere *sphere, t_matrix *transform);

// Cylindre
t_cylinder	*create_cylinder(t_tuple center, t_tuple normal,
				double diameter, double height);

// General
t_material	default_material(void);

#endif
