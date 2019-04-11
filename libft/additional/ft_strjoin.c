/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:46:17 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:32:22 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
