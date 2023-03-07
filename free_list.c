/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:08:46 by tayou             #+#    #+#             */
/*   Updated: 2023/03/07 14:21:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *list)
{
	t_node	*list_head;

	if (list == (void *) 0)
		return ;
	while (list != (void *) 0)
	{
		list_head = list;
		list = list->next;
		free(list_head);
	}
	list = (void *) 0;
}

