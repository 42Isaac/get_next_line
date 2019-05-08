/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:34:32 by iperez            #+#    #+#             */
/*   Updated: 2019/04/14 21:34:34 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#define BUFF_SIZE 100
#define MALLCHECK(x) if (!(x)) return (-1);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnb_read(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
	{
		write(1, "2", 1);
		n %= 1000000000;
		n = -n;
	}
	if (n > 9)
		ft_putnb_read(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
		str[--n] = 0;
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*push;
	int		s;
	int		p;

	if (!s1 || !s2)
		return (NULL);
	if (!(push = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	s = 0;
	p = 0;
	while (s1[s])
		push[p++] = s1[s++];
	s = 0;
	while (s2[s])
		push[p++] = s2[s++];
	return (push);
}

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*push;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (NULL);
	push = &s[i];
	return ((char *)push);
}

/*
** Copy sbuf to line to newline or EOF.
** Returns the index after newline in sbuf,
** 0 if EOF is reached, -1 if error has occured.
*/

int				copy_till_nl(char *sbuf, char **line)
{
	int		i;
	int		icopy;

	i =	0;
	while (sbuf[i] && sbuf[i] != '\n')
		i++;
	icopy = (sbuf[i] ? i + 1 : 0);
	MALLCHECK(*line = ft_strnew(i))
	while (i-- > 0)
		(*line)[i] = sbuf[i];
	return (icopy);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*sbuf;
	int				b_read;
	int				iofnl;

	if (!sbuf)							// Create the static string
		MALLCHECK(sbuf = ft_strnew(0))	// if it doesn't exist
	
	if (ft_strchr(sbuf, '\n'))
	{
		iofnl = copy_till_nl(sbuf, line);	// If /n already exists in sbuf,
		sbuf += iofnl;						// copy to that point, increment
		return (iofnl == -1 ? -1 : 1);		// sbuf, and return proper value
	}

	while ((b_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[b_read] = '\0';						// Write buf to sbuf
		MALLCHECK(sbuf = ft_strjoin(sbuf, buf))	// untill EOF or '\n' is
		if (ft_strchr(buf, '\n')) break;		// encountered in buf
	}

	iofnl = copy_till_nl(sbuf, line);

	if (iofnl == 0 || iofnl == -1)
	{
		free(sbuf);					// If EOF is reached or an error has occured,
		return (iofnl);				// free sbuf and return proper value
	}

	sbuf += iofnl;	// Increment sbuf to index after newline.

	return (1);
}

int			main()
{
	char	*line;
	int 	i;
	int		fd;

	fd = open("txt.txt", O_RDONLY | O_EXCL);
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	ft_putstr("\n~-~ EOF HAS BEEN REACHED ~-~\n");
	return (0);
}