/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/07 14:27:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->number = number;
	new_node->prev = (void *) 0;
	new_node->next = (void *) 0;
	return (new_node);
}

t_node	*add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*copy_head;

	if (stack == (void *) 0)
	{
		*stack = new_node;
		return (*stack);
	}
	copy_head = *stack;
	while (copy_head->next != (void *) 0)
		copy_head = copy_head->next;
	copy_head->next = new_node;
	new_node->prev = copy_head;
	return (*stack);
}

t_node	*get_stack_a(char **argv)
{
	t_node	*stack_a;
	t_node	*new_node;
	char	**number_array;
	int		i;

	number_array = get_number_array(argv);
	if (number_array == 0)
		exit(1);
	stack_a = get_new_node(ft_atoi(number_array[0]));
	i = 1;
	while (number_array[i] != (void *) 0)
	{
		new_node = get_new_node(ft_atoi(number_array[i]));
		if (new_node == 0)
		{
			free_array(number_array);
			exit(1);
		}
		stack_a = add_node_back(&stack_a, new_node);
		i++;
	}
	free_array(number_array);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*copy_stack;
	int		i;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	copy_stack = stack_a;
	i = 1;
	while (copy_stack != (void *) 0)
	{
		ft_printf("stack_a[%d]->number: %d\n", i, copy_stack->number);
		copy_stack = copy_stack->next;
		i++;
	}
	free_list(stack_a);
	system("leaks push_swap");
	return (0);
}
