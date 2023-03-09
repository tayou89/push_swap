/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/09 15:01:21 by tayou            ###   ########.fr       */
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

int	get_array_size(char **str)
{
	int	size;
	int	i;

	i = 0;
	while (str[i] != (void *) 0)
		i++;
	size = i;
	return (size);
}

int	*get_int_array(char **argv)
{
	char	*number_array;
	int		*int_array;
	int		array_size;
	int		i;

	number_array = get_number_array(argv);
	array_size = get_array_size(number_array);
	int_array = (int *) malloc(sizeof(int) * array_size);
	if (int_array == (void *) 0)
	{
		free_array(number_array);
		exit(1);
	}
	i = 0;
	while (number_array[i] != (void *) 0)
	{
		int_array[i] = ft_atoi(number_array[i]);
		i++;
	}
	return (int_array);
}

int	*sort_int_array(int *int_array)
{
	int	array_size;
	int	i;
	int	j;
	int	temp;
	
	array_size = (int) (sizeof(int_array) / 4);
	i = 0;
	while (i + 1 < array_size)
	{
		j = i + 1;
		while (j < array_size)
		{
			if (int_array[i] > int_array[j])
			{
				temp = int_array[i];
				int_array[i] = int_array[j];
				int_array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (int_array);
}

t_node	*get_stack_a(char **argv)
{
	int	*int_array;

	int_array = get_int_array(argv);
	int_array = sort_int_array(int_array);

	


int	main(int argc, char *argv[])
{
	t_node	*stack_a;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	
	system("leaks push_swap");
	return (0);
}
