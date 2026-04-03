/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:14:58 by josemigu          #+#    #+#             */
/*   Updated: 2026/04/03 13:14:59 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebraOperations.h>

t_matrix	*shearing(double x, double y, double z)
{
	t_matrix	*m;

	m = identity_matrix();
	if (!m)
		return (NULL);
	set_matrix_cel(&m->row[0], 1, x * y);
	set_matrix_cel(&m->row[0], 2, x * z);
	set_matrix_cel(&m->row[1], 0, y * x);
	set_matrix_cel(&m->row[1], 2, y * z);
	set_matrix_cel(&m->row[2], 0, z * x);
	set_matrix_cel(&m->row[2], 1, z * y);
	return (m);
}
