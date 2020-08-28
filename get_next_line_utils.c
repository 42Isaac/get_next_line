/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 14:51:35 by iperez            #+#    #+#             */
/*   Updated: 2020/08/22 14:53:51 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
		str[--n] = 0;
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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
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
