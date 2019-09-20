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

#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int			main(int ac, char **av)
{
	char	*line;
	int		i1;
	int		i2;
	int		i3;
	int		fd1;
	int		fd2;
	int		fd3;

	if (ac < 2 && ac > 4)
	{
		ft_putstr("Enter 1 or 2 filenames as parameters.\n1 file prints using GNL.\n2 files prints lines back and forth between the 2 files, till both are finished.\n");
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
		while (i1 || i2 || i3)
		{
			if (i1)
			{
				i1 = get_next_line(fd1, &line);
				ft_putstr(line);
				ft_putstr("\n");
				free(line);
			}
			if (i2)
			{
				i2 = get_next_line(fd2, &line);
				ft_putstr(line);
				ft_putstr("\n");
				free(line);
			}
			if (i3)
			{
				i3 = get_next_line(fd3, &line);
				ft_putstr(line);
				ft_putstr("\n");
				free(line);
			}
		}
	}
	if (ac == 3)
	{
		i1 = 1;
		i2 = 1;
		fd1 = open(av[1], O_RDONLY | O_EXCL);
		fd2 = open(av[2], O_RDONLY | O_EXCL);
		while (i1 || i2)
		{
			if (i1)
			{
				i1 = get_next_line(fd1, &line);
				ft_putstr(line);
				ft_putstr("\n");
				free(line);
			}
			if (i2)
			{
				i2 = get_next_line(fd2, &line);
				ft_putstr(line);
				ft_putstr("\n");
				free(line);
			}
		}
	}
	if (ac == 2)
	{
		i1 = 1;
		fd1 = open(av[1], O_RDONLY | O_EXCL);
		while (i1)
		{
			i1 = get_next_line(fd1, &line);
			ft_putnbr(i1);
			ft_putstr(": ");
			if (i1 == 0)
				break;
			ft_putstr(line);
			ft_putstr("\n");
			free(line);
		}
	}
	ft_putstr("\n~-~ EOF HAS BEEN REACHED ~-~\n");
	return (0);
}
