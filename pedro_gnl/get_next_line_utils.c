/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:15:31 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/12/10 16:53:39 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < len2)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			total;
	size_t			i;
	unsigned char	*byte_ptr;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (s_len - start < len)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
