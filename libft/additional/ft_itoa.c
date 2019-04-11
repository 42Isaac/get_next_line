/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:14:38 by iperez            #+#    #+#             */
/*   Updated: 2019/02/27 12:14:43 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_nbrstrlen(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	unsigned int	n_cpy;
	size_t			n_len;
	char			*nbr;

	n_len = ft_nbrstrlen(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		n_len++;
	}
	if (!(nbr = ft_strnew(n_len)))
		return (NULL);
	nbr[--n_len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		nbr[--n_len] = n_cpy % 10 + '0';
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
