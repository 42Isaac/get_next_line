/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:29:51 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:31:52 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strwhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	finish;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_strwhitespace(s[start]))
		start++;
	finish = ft_strlen(s);
	while (ft_strwhitespace(s[finish - 1]))
		finish--;
	if (finish < start)
		finish = start;
	return (ft_strsub(s, start, finish - start));
}
