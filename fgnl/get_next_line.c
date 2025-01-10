/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:01:36 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/10 17:02:44 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Gets the next line from a file descriptor
 * @param fd The file descriptor to read from
 * @return The next line from the file, or NULL if there's an error or EOF
 * @details Reads from fd until a newline is found or EOF is reached.
 *          Manages a static buffer between calls.
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free_and_null(&stash), NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_file(stash, fd);
	if (!stash)
		return (NULL);
	if (!*stash)
		return (free_and_null(&stash), NULL);
	line = extract_line(stash);
	if (!line)
		return (free_and_null(&stash), NULL);
	stash = clean_stash(stash);
	return (line);
}

/**
 * @brief Reads from file descriptor and adds to existing stash
 * @param stash Current content buffer
 * @param fd File descriptor to read from
 * @return Updated stash with new content, or NULL on error
 * @details Reads BUFFER_SIZE bytes at a time until newline is found or EOF
 */
char	*read_file(char *stash, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp_stash;
	int		bytes_read;

	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_and_null(&stash), NULL);
		buff[bytes_read] = '\0';
		tmp_stash = gnl_strjoin(stash, buff);
		if (!tmp_stash)
			return (free_and_null(&stash), NULL);
		free_and_null(&stash);
		stash = tmp_stash;
		if (bytes_read == 0)
			break ;
	}
	return (stash);
}

/**
 * @brief Extracts the next line from the stash
 * @param stash Buffer containing file content
 * @return Extracted line including newline if present, or NULL on error
 * @details Allocates new memory for the line up to newline or end of stash
 */
char	*extract_line(char *stash)
{
	char	*line;
	int		len;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
	{
		line[len] = stash[len];
		len++;
	}
	if (stash[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

/**
 * @brief Cleans the stash by removing the extracted line
 * @param stash Current content buffer
 * @return New stash with remaining content, or NULL if empty/error
 * @details Frees original stash and returns new buffer with remaining content
 */
char	*clean_stash(char *stash)
{
	char	*cleaned;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
		return (free_and_null(&stash), NULL);
	cleaned = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!cleaned)
		return (free_and_null(&stash), NULL);
	j = 0;
	while (stash[i])
		cleaned[j++] = stash[i++];
	cleaned[j] = '\0';
	free_and_null(&stash);
	return (cleaned);
}

void	free_and_null(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	fd = open("test", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%d : %s", count, line);
		free(line);
		count++;
	}
	close(fd);	
	return (0);
}*/