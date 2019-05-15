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

#include <fcntl.h>

int			main(void)
{
	char	*line;
	int		i;
	int		fd;

	i = 1;
	fd = open("txt.txt", O_RDONLY | O_EXCL);
	while (i)
	{
		i = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	ft_putstr("\n~-~ EOF HAS BEEN REACHED ~-~\n");
	return (0);
}
