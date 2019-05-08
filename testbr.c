/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:13:13 by iperez            #+#    #+#             */
/*   Updated: 2019/04/15 00:13:15 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#define BUFF_SIZE 1

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

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int			main()
{
	char	*test;
	int		i;
	char	alpha;

	test = ft_strnew(10);
	i = 0;
	alpha = 'a';
	while (i < 11)
	{
		test[i] = alpha;
		alpha += 1;
		i++;
	}
	ft_putstr(test);
	ft_putstr("\n");
	test += 3;
	ft_putstr(test);
	ft_putstr("\n");
	return (0);
}
