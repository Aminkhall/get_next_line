
#include "get_next_line_bonus.h"

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

char	*get_next_line_bonus(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		*buf;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(buf), NULL);
		if (n == 0 && tmp[fd] == NULL)
			return (free(buf),NULL);
		buf[n] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		if (there_is_new_line(tmp[fd]))
			break ;
		if (n == 0)
			break ;
	}
	line = check_new_line(tmp[fd]);
	tmp[fd] = skip_new_line(tmp[fd]);
	return (free(buf), line);
}

// void ff()
// {
//     system("leaks a.out");
// }

// int main()
// {
//     // atexit(ff);
//     int fd = open("h.txt", O_RDONLY);
// 	if (fd < 0)
// 		return 0;
//     int fd2 = open("hh.txt", O_RDONLY);
// 	if (fd2 < 0)
// 		return 0;
// 	printf("===> %d\n", fd);
//     char *line = get_next_line(fd);
// 	// int i = 0;
//     // while (line)
//     // {
//         printf("from h.txt :%s\n" ,line);
//         printf("from hh.txt :%s" ,get_next_line(fd2));
//         printf("second time from h.txt :%s\n" ,get_next_line(fd));
//         free(line);
//         // line = get_next_line(fd);
// 		// i++;
//     // }
// 	// printf("\nLines Count = %d\n", i);
//     close(fd);
//     return 0;
// }
