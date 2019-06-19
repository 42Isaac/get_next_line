/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:26:06 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:34:40 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**  Returns the length of a word in str s, that starts at index start,
**  and ends at char end.
*/

size_t	ft_wordlen(char *str, int start, char end)
{
	size_t	len;

	len = 0;
	while (str[start] && str[start] != end)
	{
		len++;
		start++;
	}
	return (len);
}
