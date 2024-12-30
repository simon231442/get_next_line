/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:24:43 by srenaud           #+#    #+#             */
/*   Updated: 2024/12/30 23:39:59 by srenaud          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *stash);
char	*extract_line(char *stash);

static char	*get_next_line(int fd)
{
	char	*stash;
	char	*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stash)
		stash = read_file(fd, stash);
	line = extract_line(stash);
	return (line);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	char	*tmp_stash;

	buffer = malloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && read(fd, buffer) > 0)
	{
		tmp_stash = ft_strjoin(stash, buffer);
		if (!tmp_stash)
			return (free(buffer), NULL);
		free(stash);
		stash = tmp_stash;
	}
	return (free(buffer), stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	char	*ptr_line;
	char	*clean_stash;

	clean_stash = stash;
	line = ptr_line;
	while (*stash != '\n' && *stash)
	{
		*ptr_line = *stash;
		ptr_line++;
		stash++;
	}
	*stash = '\0';
	stash++;
	return (free(clean_stash), line);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	fd = open("test", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%d : %s\n"i, count++, line);
	close(fd);
	return (0);
}
