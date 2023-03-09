/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/09 12:25:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*initialize_stack_a(char **argv)
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

t_node	*initialize_stack_b(t_node *stack_a)
{
	t_node	*stack_b;

	stack_b = (t_node *) malloc(sizeof(t_node));
	if (stack_b == (void *) 0)
	{
		free_list(stack_a);
		exit(1);
	}
	return (stack_b);
}

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

t_node	*sort_stack(t_node *stack_a, t_node *stack_b)
{
	

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*copy_stack;
	t_deque	*first_last;
	t_node	*temp;
	int		i;

	check_exception(argc, argv);
	stack_a = initialize_stack_a(argv);
	stack_b = initialize_stack_b(stack_a);
	stack_a = sort_stack(stack_a, stack_b);
	first_last = get_deque(stack_a);
	temp = stack_a;
	stack_a = stack_a->next;
	free(temp);
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
