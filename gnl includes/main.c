/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:23:05 by iperez            #+#    #+#             */
/*   Updated: 2019/05/15 14:23:14 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line.h"
#include <fcntl.h>

static void		ft_putnbr(int n)
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
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void		ft_putstr(char *c)
{
	int i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
}

int				main(int ac, char **av)
{
	char	*line;
	int		i1;
	int		i2;
	int		i3;
	int		fd1;
	int		fd2;
	int		fd3;

	if (ac < 2 || ac > 4)
	{
		ft_putstr("usage:\n	Enter 1 - 3 paramaters for gnl to process.\n");
		ft_putstr("	Output will print file descriptor number,\n	followed by what gnl returned,\n	followed by the string 'line' that gnl wrote to.\n");
		return (0);
	}
	if (ac == 4)
	{
		i1 = 1;
		i2 = 1;
		i3 = 1;
		fd1 = open(av[1], O_RDONLY | O_EXCL);
		fd2 = open(av[2], O_RDONLY | O_EXCL);
		fd3 = open(av[3], O_RDONLY | O_EXCL);
		while (i1 == 1 || i2 == 1 || i3 == 1)
		{
			if (i1 == 1)
			{
				i1 = get_next_line(fd1, &line);
				ft_putstr("FD: ");
				ft_putnbr(fd1);
				ft_putstr(" Output: ");
				ft_putnbr(i1);
				if (i1 == 1)
				{
					ft_putstr(" line: ");
					ft_putstr(line);
					free(line);
				}
				ft_putstr("\n");
			}
			if (i2 == 1)
			{
				i2 = get_next_line(fd2, &line);
				ft_putstr("FD: ");
				ft_putnbr(fd2);
				ft_putstr(" Output: ");
				ft_putnbr(i2);
				if (i2 == 1)
				{
					ft_putstr(" line: ");
					ft_putstr(line);
					free(line);
				}
				ft_putstr("\n");
			}
			if (i3 == 1)
			{
				i3 = get_next_line(fd3, &line);
				ft_putstr("FD: ");
				ft_putnbr(fd3);
				ft_putstr(" Output: ");
				ft_putnbr(i3);
				if (i3 == 1)
				{
					ft_putstr(" line: ");
					ft_putstr(line);
					free(line);
				}
				ft_putstr("\n");
			}
		}
	}
	if (ac == 3)
	{
		i1 = 1;
		i2 = 1;
		fd1 = open(av[1], O_RDONLY | O_EXCL);
		fd2 = open(av[2], O_RDONLY | O_EXCL);
		while (i1 == 1 || i2 == 1)
		{
			if (i1 == 1)
			{
				i1 = get_next_line(fd1, &line);
				ft_putstr("FD: ");
				ft_putnbr(fd1);
				ft_putstr(" Output: ");
				ft_putnbr(i1);
				if (i1 == 1)
				{
					ft_putstr(" line: ");
					ft_putstr(line);
					free(line);
				}
				ft_putstr("\n");
			}
			if (i2 == 1)
			{
				i2 = get_next_line(fd2, &line);
				ft_putstr("FD: ");
				ft_putnbr(fd2);
				ft_putstr(" Output: ");
				ft_putnbr(i2);
				if (i2 == 1)
				{
					ft_putstr(" line: ");
					ft_putstr(line);
					free(line);
				}
				ft_putstr("\n");
			}
		}
	}
	if (ac == 2)
	{
		i1 = 1;
		fd1 = open(av[1], O_RDONLY | O_EXCL);
		while (i1 == 1)
		{
			i1 = get_next_line(fd1, &line);
			ft_putstr("FD: ");
			ft_putnbr(fd1);
			ft_putstr(" Output: ");
			ft_putnbr(i1);
			if (i1 == 1)
			{
				ft_putstr(" line: ");
				ft_putstr(line);
				free(line);
			}
			ft_putstr("\n");
		}
	}
	ft_putstr("\n\n~-~ EOF HAS BEEN REACHED ~-~\n");
	return (0);
}
