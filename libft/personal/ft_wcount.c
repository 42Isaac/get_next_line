/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 07:10:27 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:25:23 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**  Returns the amount of words in str s, deliminated by char d.
*/

size_t	ft_wcount(char const *s, char d)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == d)
			i++;
		if (s[i] && s[i] != d)
		{
			count++;
			while (s[i] && s[i] != d)
				i++;
		}
	}
	return (count);
}
