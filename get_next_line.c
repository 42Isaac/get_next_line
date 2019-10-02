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

/*
** Creates a new structer and initializes everything as needed.
*/

static t_list		*ft_lstnew(int fd)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	list->fd = fd;
	list->eof = 1;
	if (!(list->buffer = ft_strnew(0)))
		list->buffer = NULL;
	list->next = NULL;
	return (list);
}

/*
** Returns the list for the current fd.
** If none exists, make a new list and add to the linked list.
*/

static t_list	*c_fd(t_list **fdl, int fd)
{
	t_list			*curfd;

	curfd = *fdl;
	while (curfd)
	{
		if (curfd->fd == fd)
			return (curfd->buffer == NULL ? NULL : curfd);
		curfd = curfd->next;
	}
	if (!(curfd = ft_lstnew(fd)) || curfd->buffer == NULL)
		return (NULL);
	if (curfd != *fdl)
	{
		curfd->next = *fdl;
		*fdl = curfd;
	}
	return (*fdl);
}

/*
** Removes line from sbuf.
** Returns 1 on success, -1 on failure.
*/

static int		clean_sbuf(char **sbuf, int linelen)
{
	int		sbuflen;
	int		newbuflen;
	int		nblcopy;
	char	*buf;

	sbuflen = ft_strlen(*sbuf);
	newbuflen = sbuflen - linelen - 1;
	if (newbuflen < 0)
		newbuflen = 0;
	nblcopy = newbuflen;
	MC(!(buf = ft_strnew(newbuflen)));
	while (newbuflen >= 0)
		buf[newbuflen--] = (*sbuf)[sbuflen--];
	free(*sbuf);
	MC(!(*sbuf = ft_strnew(nblcopy)));
	while (nblcopy >= 0)
	{
		(*sbuf)[nblcopy] = buf[nblcopy];
		nblcopy--;
	}
	free(buf);
	return (1);
}

/*
** Copy sbuf to line up to newline or EOF.
** Returns 1 on success, 0 on EOF, and -1 on error.
*/

static int		copy_till_eol(char **sbuf, char **line, int *eof)
{
	int		i;
	int		icpy;

	i =	0;
	while ((*sbuf)[i] && (*sbuf)[i] != '\n')
		i++;
	icpy = i;
	if (!(*sbuf)[0] || ((*sbuf)[icpy] == '\n' && !(*sbuf)[icpy + 1]))
		(*eof) = ((*eof) > 0) ? (*eof) : ((*eof) -= 1);
	MC(!(*line = ft_strnew(i)))
	while (icpy-- > 0)
		(*line)[icpy] = (*sbuf)[icpy];
	icpy = clean_sbuf(sbuf, i);
	return (icpy == 1 && (*eof) < -1 ? 0 : icpy);
}

/*
**	It's gnl. Does everything it needs to, returns -1 on error,
**	0 on success and EOF has been reached, and 1 on success
**	and EOF has not been reached.
*/

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	static t_list	*fdl;
	int				b_read;
	t_list			*curfd;

	MC(fd < 0 || !line || read(fd, buf, 0) < 0 || !(curfd = c_fd(&fdl, fd)))
	if (curfd->eof < -1)
		return (0);
	if (ft_strchr(curfd->buffer, '\n'))
		return (copy_till_eol(&curfd->buffer, line, &curfd->eof));
	ft_bzero(buf, BUFF_SIZE);
	while (!(ft_strchr(buf, '\n')) && (b_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[b_read] = '\0';
		MC(!(temp = ft_strjoin(curfd->buffer, buf)));
		free(curfd->buffer);
		curfd->buffer = temp;
	}
	curfd->eof = b_read == 0 && curfd->eof == 1 ? -1 : curfd->eof;
	return (copy_till_eol(&curfd->buffer, line, &curfd->eof));
}
