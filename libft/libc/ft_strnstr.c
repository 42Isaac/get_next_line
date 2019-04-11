/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 07:03:15 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:16:52 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[++i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			k = i;
			found = 1;
			while (haystack[k] && needle[j] && j < len && k < len)
				if (haystack[k++] != needle[j++])
					found = 0;
			if (found && !needle[j])
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
