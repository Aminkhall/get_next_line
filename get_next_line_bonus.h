
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <libc.h>
# include <stdlib.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1110
#endif

char	*get_next_line_bonus(int fd);
char	*check_new_line(char *line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*skip_new_line(char *line);
char	*ft_strdup(char *s);
void	ft_strcopy(char *dst, char *src);

#endif