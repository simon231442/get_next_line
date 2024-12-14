/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:14:49 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/12/10 14:26:28 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *remainder)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (NULL);
	}
	return (remainder);
}

char	*copy_line(char *remainder)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = ft_substr(remainder, 0, i);
	return (line);
}

char	*remove_copied(char *remainder)
{
	size_t	i;
	char	*new_remainder;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_substr(remainder, i + 1, \
	ft_strlen(remainder) - i - 1);
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	remainder = read_line(fd, buffer, remainder);
	free(buffer);
	if (!remainder)
		return (NULL);
	line = copy_line(remainder);
	remainder = remove_copied(remainder);
	return (line);
}
