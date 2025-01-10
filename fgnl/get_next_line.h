/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:02:13 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/10 15:02:13 by srenaud          ###   ########.ch       */
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
char	*clean_stash(char *stash);
char	*init_stash(char *stash);

/**
 * @brief Calculates string length
 * @param str String to measure
 * @return Length of string
 */
int		ft_strlen(char *str);

/**
 * @brief Locates first occurrence of character in string
 * @param s String to search
 * @param c Character to find
 * @return Pointer to character if found, NULL otherwise
 */
char	*gnl_strchr(char *s, char c);

/**
 * @brief Copies source string to destination
 * @param dest Destination buffer
 * @param src Source string
 */
void	ft_strcpy(char *dest, const char *src);

/**
 * @brief Concatenates source string to destination
 * @param dest Destination buffer
 * @param src Source string to append
 */
void	ft_strcat(char *dest, const char *src);

/**
 * @brief Joins stash and buffer into new string
 * @param stash Current content buffer
 * @param buff New content to append
 * @return New joined string, or NULL on error
 */
char	*gnl_strjoin(char *stash, char *buff);

void	free_and_null(char **ptr);

#endif