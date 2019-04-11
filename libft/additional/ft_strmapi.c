/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:10:14 by iperez            #+#    #+#             */
/*   Updated: 2019/02/11 13:10:16 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		push[i] = f(i, s[i]);
	return (push);
}
