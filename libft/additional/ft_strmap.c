/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:03:27 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:19:07 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*push;
	int		i;

	if (!s)
		return (NULL);
	push = ft_strnew(ft_strlen(s));
	if (!push)
		return (NULL);
	i = -1;
	while (s[++i])
		push[i] = f(s[i]);
	return (push);
}
