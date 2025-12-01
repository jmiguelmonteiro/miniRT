/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:20 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/17 12:43:48 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);

#endif
