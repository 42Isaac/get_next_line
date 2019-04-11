/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 05:39:42 by iperez            #+#    #+#             */
/*   Updated: 2019/01/07 11:50:35 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	void *push;

	push = (void *)malloc(sizeof(void) * size);
	if (!push)
		return (NULL);
	ft_bzero(push, size);
	return (push);
}
