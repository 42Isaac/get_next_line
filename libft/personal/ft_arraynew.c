/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 06:46:28 by iperez            #+#    #+#             */
/*   Updated: 2019/02/21 06:48:15 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs a new array and sets all values to 0.
*/

char	**ft_arraynew(size_t size)
{
	char	**arr;

	if (!(arr = (char **)malloc(sizeof(char **) * size + 1)))
		return (NULL);
	while (size > 0)
		arr[size--] = 0;
	arr[size] = 0;
	return (arr);
}
