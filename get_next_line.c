/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:20:13 by mkhallou          #+#    #+#             */
/*   Updated: 2024/11/19 15:27:27 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcopy(char *dst, char *src)
{
	int	i;

	i = 0;
	if (!dst || !src) // Added NULL protection here
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
}

int	there_is_new_line(char *line)
{
	int	i;

	i = 0;
	if (!line) // Added NULL protection here
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buf;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(buf), NULL);
		if (n == 0 && tmp == NULL)
			return (free(buf),NULL);
		buf[n] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (there_is_new_line(tmp))
			break ;
		if (n == 0)
			break ;
	}
	line = check_new_line(tmp);
	tmp = skip_new_line(tmp);
	return (free(buf), line);
}

// void ff()
// {
//     system("leaks a.out");
// }

// int main()
// {
//     // atexit(ff);
//     int fd = open("ttt", O_RDONLY);
// 	if (fd < 0)
// 		return 0;
// 	// printf("===> %d\n", fd);
//     char *line = get_next_line(fd);

// 	// int i = 0;
//     while (line)
//     {
// 		// printf("-----------------------\n");
//         printf("|%s|" ,line);
//         free(line);
//         line = get_next_line(fd);
// 	// 	// i++;
//     }
//         printf("|%s|" ,line);
// 	// printf("\nLines Count = %d\n", i);
//     close(fd);
//     return 0;
// }
