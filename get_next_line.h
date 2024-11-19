/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:20:44 by mkhallou          #+#    #+#             */
/*   Updated: 2024/11/19 15:06:39 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <libc.h>
# include <stdlib.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
char	*check_new_line(char *line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*skip_new_line(char *line);
char	*ft_strdup(char *s);
void	ft_strcopy(char *dst, char *src);

#endif