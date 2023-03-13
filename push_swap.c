/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/13 15:21:38 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_deque(t_node *stack)
{
	t_deque	*first_last;

	first_last = (t_deque *) malloc(sizeof(t_deque));
	first_last->first = stack;
	while (stack->next != (void *) 0)
		stack = stack->next;
	first_last->last = stack;
	return (first_last);
}

int	check_if_sorted(t_node *stack)
{
	int		min_number;
	int		max_number;
	t_node	*stack_head;

	stack_head = stack;
	min_number = get_min_number(stack);
	max_number = get_max_number(stack);
	while (stack->next != (void *) 0)
	{
		if (stack->number == max_number && stack->number->next != min_number)
			return (0);
		if (stack->number != max_number && 
			stack->number->next != stack->number + 1)
			return (0);
		}
		stack = stack->next;
	}
	if (stack->number == max_number && stack_head->number != min_number)
		return (0);
	if (stack->number != max_number && stack_head->number != stack->number + 1)
		return (0);
	return (1);
}

t_node	*sort_stack_a(t_node *stack_a)
{
	t_node	*stack_b;

	if (check_if_sorted(stack_a) == 1)
		return (stack_a);
	


int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*copy_stack;
	int		i;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	stack_a = sort_stack_a(stack_a);
	copy_stack = stack_a;
	i = 0;
	while (copy_stack != (void *) 0)
	{
		ft_printf("stack_a[%d]->number: %d\n", i, copy_stack->number);
		i++;
		copy_stack = copy_stack->next;
	}
	free_list(stack_a);
	system("leaks push_swap");
	return (0);
}
