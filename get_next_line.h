/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:41:25 by iperez            #+#    #+#             */
/*   Updated: 2019/04/11 03:41:27 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);

char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);

int					get_next_line(const int fd, char **line);

typedef struct		s_list
{
	int				fd;
	int				eof;
	char			*buffer;
	struct s_list	*next;
}					t_list;

#endif
