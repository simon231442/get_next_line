/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:24:49 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/10 13:22:47 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*read_file(char *stash, int fd);
char	*extract_line(char *stash);
char	*clean_stash(char *stash, int len_line);
char	*init_stash(char *stash);

int		ft_strlen(char *str);
char	*gnl_strchr(char *s, char c);
void	ft_strcpy(char *dest, const char *src);
void	ft_strcat(char *dest, const char *src);
char	*gnl_strjoin(char *stash, char *buff);

#endif