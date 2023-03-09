/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:59:52 by tayou             #+#    #+#             */
/*   Updated: 2023/03/09 14:29:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

void	pass_space(char *str, int *i)
{
	while (ft_isspace(str[*i]) == 1)
		(*i)++;
}

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack != (void *) 0)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
