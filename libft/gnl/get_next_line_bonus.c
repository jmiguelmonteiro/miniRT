/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:00 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/21 16:02:24 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"

static char	*extract_line(char *raw_line)
{
	char	*next_line;
	int		pos;

	if (!*raw_line)
		return (NULL);
	pos = 0;
	while ((raw_line[pos] != '\n') && (raw_line[pos] != '\0'))
		pos++;
	if (raw_line[pos] == '\0')
		pos -= 1;
	next_line = malloc((pos + 2) * sizeof (char));
	if (!next_line)
		return (NULL);
	ft_memmove(next_line, raw_line, pos + 1);
	next_line[pos + 1] = '\0';
	return (next_line);
}

static char	*add_buffer_to_raw(char *raw_line, char *buffer)
{
	char	*new_raw_line;

	new_raw_line = ft_strjoin(raw_line, buffer);
	free(raw_line);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	if (!new_raw_line)
		return (NULL);
	return (new_raw_line);
}

static void	update_buffer(char *raw_line, char *buffer)
{
	char	*pos_nl;
	int		i;

	i = 0;
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	pos_nl = ft_strchr(raw_line, '\n');
	if (!pos_nl)
		return ;
	while (pos_nl[i + 1])
	{
		buffer[i] = pos_nl[i + 1];
		i++;
	}
}

static char	*read_fd(int fd, char *raw_line, char *buffer)
{
	int		bytes_read;

	bytes_read = 0;
	if (!raw_line)
		return (NULL);
	while (true)
	{
		if (ft_strchr(raw_line, '\n'))
			return (raw_line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(raw_line), NULL);
		buffer[bytes_read] = '\0';
		raw_line = add_buffer_to_raw(raw_line, buffer);
		if (!raw_line)
			return (NULL);
		if (bytes_read < BUFFER_SIZE)
			return (raw_line);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*raw_line;
	char		*next_line;

	raw_line = NULL;
	next_line = NULL;
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	raw_line = malloc(1 * sizeof(char));
	if (!raw_line)
		return (NULL);
	raw_line[0] = '\0';
	if (buffer[fd][0])
		raw_line = add_buffer_to_raw(raw_line, buffer[fd]);
	raw_line = read_fd(fd, raw_line, buffer[fd]);
	if (!raw_line)
		return (NULL);
	next_line = extract_line(raw_line);
	update_buffer(raw_line, buffer[fd]);
	free(raw_line);
	return (next_line);
}
