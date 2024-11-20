/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:42 by mkhallou          #+#    #+#             */
/*   Updated: 2024/11/20 18:09:31 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strcopy(char *dst, char *src)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	has_newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*buf_alloc(size_t size)
{
	char	*buf;

	buf = malloc(size + 1);
	if (!buf)
		return (NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		*buf;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	buf = buf_alloc(BUFFER_SIZE);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(buf), NULL);
		buf[n] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		if (has_newline(tmp[fd]) || n == 0)
			break ;
	}
	free(buf);
	if (!tmp[fd])
		return (NULL);
	line = extract_line(tmp[fd]);
	tmp[fd] = trim_to_next_line(tmp[fd]);
	return (line);
}
