/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:39:52 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/05 23:39:52 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *stash, fd);

char	*get_next_line(int fd)
{
	static char	*stash;

	read_file(stash, fd);
}

char	*read_file(char *stash, fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp_stash;
	int	bytes_read;

	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		tmp_stash = gnl_strjoin(stash, buff);
		free(stash);
		stash = tmp_stash;
	}
	if (bytes_read < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

