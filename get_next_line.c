/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:24:43 by srenaud           #+#    #+#             */
/*   Updated: 2024/12/28 13:24:43 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	read_file(int fd, static char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
		if (!stash || )
		stash = read_file(fd, stash);
	return (line);
}

static char	read_file(int fd, static char *stash)
{
	char	*buffer;
	int	byte_read;
	char	*tmp_stash;

	buffer = malloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(buffer, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buffer);
		tmp_stash = ft_strjoin(stash, buffer);
		if (!tmp_stash)
			return (free(buffer), NULL);
		free(stash);
		stash = tmp_stash;
		free(tmp_stash);
	}
	return (free(buffer), stash);
}
