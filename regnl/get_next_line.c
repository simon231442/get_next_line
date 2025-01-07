/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:39:52 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/07 15:51:55 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *stash,int fd);
char	*extract_line(char *stash);
char	*clean_stash(char *stash, int len_line);
char	*init_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int		len_line;

//	write(1,"a\n",2);
	stash = read_file(stash, fd);
//	write(1,"c\n",2);
	line = extract_line(stash);
	len_line = ft_strlen(line);
	stash = clean_stash(stash, len_line);
	return (line);
}

char	*read_file(char *stash, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp_stash;
	int	bytes_read;

	if (!stash)
		stash = init_stash(stash);
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
//	write(1,"b\n",2);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return(/*free(stash),free(tmp_stash),*/ NULL);
		buff[bytes_read] = '\0';
		tmp_stash = gnl_strjoin(stash, buff);
		free(stash);
		stash = tmp_stash;
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int	len_line;

	len_line = 0;
	while (stash[len_line] != '\n' && stash[len_line])
		len_line++;
	line = malloc(sizeof(char) * (len_line + 1));
	if (!line)
		return(NULL);
	len_line = 0;
	while (stash[len_line] != '\n' && stash[len_line])
	{
		line[len_line] = stash[len_line];
		len_line++;
	}
	line[len_line] = '\n';
	clean_stash(stash, len_line);
	return (line);
}

char	*clean_stash(char *stash, int len_line)
{
	char	*cleaned_stash;
	int	len_cleaned_stash;

	len_cleaned_stash = 0;
	while (stash[len_line + len_cleaned_stash])
		len_cleaned_stash++;
	cleaned_stash = malloc(sizeof(char) * (len_cleaned_stash + 1));
	if (!cleaned_stash)
		return (NULL);
	len_cleaned_stash = 0;
	while (stash[len_line + len_cleaned_stash])
	{
		cleaned_stash[len_cleaned_stash] = stash[len_line + len_cleaned_stash];
		len_cleaned_stash++;
	}
	cleaned_stash[len_cleaned_stash] = '\0';
	return (/*free(stash), */cleaned_stash);
}

char	*init_stash(char *stash)
{
	stash = malloc(sizeof(char)*1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	return (stash);
}


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
		printf("%d : %s\n", count, line);
		count++;
	}
	close(fd);
	return (0);
}
