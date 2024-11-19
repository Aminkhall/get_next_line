/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:00:35 by mkhallou          #+#    #+#             */
/*   Updated: 2024/11/19 17:00:38 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	ft_strcopy(result, s1);
	ft_strcopy(&result[ft_strlen(s1)], s2);
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (result);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	int		i;

	if (!s) // Added NULL protection here
		return (NULL);
	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s) // Added NULL protection here
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*check_new_line(char *line)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!line || !*line) // Added NULL protection here
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (ft_strdup(line));
	i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = line[j];
		j++;
	}
	result[i - 1] = '\n';
	result[i] = '\0';
	return (result);
}

char	*skip_new_line(char *line)
{
	char	*result;
	int		i;

	i = 0;
	if (!line) // Added NULL protection here
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	i++;
	result = ft_strdup(&line[i]);
	free(line);
	return (result);
}
