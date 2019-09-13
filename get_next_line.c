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

void	printstructs(t_list *alst)
{
	ft_putstr("int	fd: ");
	ft_putnbr(alst->fd);
	ft_putchar('\n');
	ft_putstr("char	*buffer");
	ft_putstr(alst->buffer);
	ft_putchar('\n');
	ft_putstr("struct s_list	*next: ");
	if (alst->next)
		ft_putstr("next\n\n");
	else
		ft_putstr("NULL\n\n");
}

/*
**	Safely removes the list containing fd from the linked list.
*/

void	ft_lstdelone(t_list *alst, const int fd)
{
	t_list	*temp;
	t_list	*curlst;

	curlst = alst;
	temp = (alst->fd == fd ? alst : NULL);
	while (!temp)
	{
		if (curlst->next->fd == fd)
			temp = curlst->next;
		else
			curlst = curlst->next;
	}
	if (alst->fd == fd)
		alst = alst->next;
	else
		curlst->next = curlst->next->next;
	free(temp->buffer);
	free(temp);
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
	{
		ft_lstdelone(curfd, fd);
		return (NULL);
	}
	ft_lstadd(fdl, curfd);
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
	nblcopy = newbuflen;
	MALLCHECK(buf = ft_strnew(newbuflen));
	while (newbuflen >= 0)
		buf[newbuflen--] = (*sbuf)[sbuflen--];
	free(*sbuf);
	MALLCHECK(*sbuf = ft_strnew(nblcopy));
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

static int		copy_till_eol(char **sbuf, char **line)
{
	int		i;
	int		icpy;
	int		returnvalue;

	i =	0;
	returnvalue = 1;
	while ((*sbuf)[i] && (*sbuf)[i] != '\n')
		i++;
	icpy = i;
	if (!(*sbuf)[icpy])
		returnvalue = 0;
	MALLCHECK(*line = ft_strnew(i))
	while (icpy-- > 0)
	{
		(*line)[icpy] = (*sbuf)[icpy];
	}
	return (clean_sbuf(sbuf, i) == 1 ? returnvalue : -1);
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

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || !(curfd = c_fd(&fdl, fd)))
		return (-1);
	printstructs(curfd);
	if (ft_strchr(curfd->buffer, '\n'))
	{
		b_read = copy_till_eol(&curfd->buffer, line);
		return (b_read == -1 ? -1 : 1);
	}
	while ((b_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[b_read] = '\0';
		MALLCHECK(temp = ft_strjoin(curfd->buffer, buf));
		free(curfd->buffer);
		curfd->buffer = temp;
		if (ft_strchr(buf, '\n')) break;
	}
	b_read = copy_till_eol(&curfd->buffer, line);
	if (b_read == 0 || b_read == -1)
		ft_lstdelone(fdl, fd);
	return (b_read == 0 || b_read == -1 ? b_read : 1);
}
