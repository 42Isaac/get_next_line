/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:03:42 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:14:38 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_arrayclear(char ***array, int arraylen)
{
	while (arraylen >= 0)
		free(*(array[arraylen--]));
	free(*array);
}

char		**ft_strsplit(char const *s, char c)
{
	int		arr;
	int		str;
	int		arrstr;
	char	**push;

	if (!s || !(push = ft_arraynew(ft_wcount(s, c))))
		return (NULL);
	str = 0;
	arr = 0;
	while ((size_t)arr < ft_wcount(s, c))
	{
		while (s[str] && s[str] == c)
			str++;
		if (!(push[arr] = ft_strnew(ft_wordlen((char *)s, str, c))))
		{
			ft_arrayclear(&push, arr);
			return (NULL);
		}
		arrstr = 0;
		while (s[str] && s[str] != c)
			push[arr][arrstr++] = s[str++];
		arr++;
	}
	return (push);
}
