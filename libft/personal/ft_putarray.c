/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:01:54 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 08:32:47 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**  Like putchar or putstr but like it's for arrays instead.
*/

void	ft_putarray(char **a)
{
	int i;

	i = 0;
	while (a[i])
		ft_putendl(a[i++]);
}
