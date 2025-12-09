/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:55:42 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/08 23:04:04 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <structs.h>

// Magnitude and normalization

t_tuple	*tuple_normalize(t_tuple *v);
double	tuple_magnitude(t_tuple v);


