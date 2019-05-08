/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:41:12 by iperez            #+#    #+#             */
/*   Updated: 2019/04/11 03:41:14 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checknewline(const char *buf, int br)
{
	int			i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] != '\n')
		return (-1);
	i = br - i;
	return (i);
}

static t_list	*correct_fd(t_list **fdlist, int fd)
{
	t_list			*currfd;

	currfd = *fdlist;
	while (currfd)
	{
		if (currfd->fd = fd)
			return (currfd);
		currfd = currfd->next;
	}
	if (!(currfd = ft_lstnew(fd)))
	{
		fd_lstdel(&fdlist);
		return (NULL);
	}
	ft_lstadd(fdlist, currfd);
	return (fdlist);
}

void		copytillnewline(char **hold, char **line, int linelen)
{
	int i;
	char *temp;

	i = -1;
	*line = ft_strnew(linelen);
	while (++i <= linelen)
		*line[i] = *hold[i];
	while (hold[i])
		i++;
	i -= linelen;
	temp = ft_strnew(i);
	i = linelen - 1;
	while (hold[++i])
		temp[i] = *hold[i];
	free(*hold);
	hold = &temp;
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fdlist;
	char			*buf[BUFF_SIZE + 1];
	t_list			*currfd;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 ||
		!(currfd = correct_fd(&fdlist, fd)))
		return (-1);
	
}
