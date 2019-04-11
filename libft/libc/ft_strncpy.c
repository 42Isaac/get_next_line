/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:09:30 by iperez            #+#    #+#             */
/*   Updated: 2019/02/04 12:31:39 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = -1;
	while (++i < len)
		if (src[i])
			dst[i] = src[i];
		else
			while (i < len)
				dst[i++] = '\0';
	return (dst);
}
