/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:24:58 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:31:07 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	startsub;

	if (!s)
		return (NULL);
	startsub = 0;
	if (!(substr = ft_strnew(len)))
		return (NULL);
	while (startsub < len)
		substr[startsub++] = s[start++];
	return (substr);
}
