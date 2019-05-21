/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:35:00 by iperez            #+#    #+#             */
/*   Updated: 2019/03/06 15:35:02 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Safely removes the list containing fd from the linked list.
*/

void	ft_lstdelone(t_list **alst, const int fd)
{
	t_list	*temp;
	t_list	*curlst;

	curlst = *alst;
	temp = ((*alst)->fd == fd ? *alst : NULL);
	while (!temp)
	{
		if (curlst->next->fd == fd)
			temp = curlst->next;
		else
			curlst = curlst->next;
	}
	if ((*alst)->fd == fd)
		*alst = (*alst)->next;
	else
		curlst->next = curlst->next->next;
	free(temp->buffer);
	free(temp);
}
