/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 07:53:54 by iperez            #+#    #+#             */
/*   Updated: 2019/01/30 14:20:05 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < (int)n - 1)
		i++;
	if (n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
