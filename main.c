/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/05 08:55:39 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
1. argc값과 argv값을 입력받다.
2. 몇개의 배열이 필요한지 확인하다.
3. 배열의 개수만큼 배열을 할당하다.
4. 각 배열의 크기를 구하고, 크기만큼 메모리를 할당하다.
5. 할당한 배열에 값을 대입하다.
6. 각 배열에 숫자가 아닌것이 있는지를 확인하다.
	6.1. 숫자가 아닌것이 있으면 "Error"를 출력하고 함수를 종료하다.
7. 배열의 개수만큼 숫자 배열을 할당하다.
8. 각 숫자배열에 atoi함수를 통해 값을 구하고, 대입하다.
9. 숫자 배열중 중복된 값이 있는지를 확인하다.
	9.1. 중복된 값이 있으면 함수를 "Error"를 표시하고, 함수를 종료한다.
10. 숫자들중 int범위를 초과하는 것이 있는지를 확인하다.
	10.1 있으면 "Error"를 출력하고, 함수를 종료하다.
11. 정렬을 시작하다.
*/

#include "push_swap.h"

void	pass_sign(char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
}

static int	check_if_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != (void *) 0)
	{
		j = 0;
		pass_space(str[i], &j);
		pass_sign(str[i], &j);
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) == 1)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_if_int(char **str)
{
	long long	number;
	long long	int_max;
	long long	int_min;
	int			i;

	int_max = 2147483647;
	int_min = -2147483648;
	i = 0;
	while (str[i] != (void *) 0)
	{
		number = ft_atoi_longlong(str[i]);
		if (number < int_min || number > int_max)
			return (0);
		else
			i++;
	}
	return (1);
}

int	get_number_count(char **str)
{
	int	number_count;
	int	i;

	i = 0;
	while (str[i] != (void *) 0)
		i++;
	number_count = i;
	return (number_count);
}

int	*fill_number_array(int *number_array, char **str)
{
	int	i;

	i = 0;
	while (str[i] != (void *) 0)
	{
		number_array[i] = ft_atoi(str[i]);
		i++;
	}
	return (number_array);
}

int	check_if_duplicate(char **str)
{
	int	number_count;
	int	*number_array;
	int	i;
	int	j;

	number_count = get_number_count(str);
	number_array = (int *) malloc(sizeof(int) * number_count);
	if (number_array == 0)
		return (0);
	number_array = fill_number_array(number_array, str);
	i = 0;
	while (i + 1 < number_count)
	{
		j = i + 1;
		while (j <= number_count)
		{
			if (number_array[i] == number_array[j])
			{
				free(number_array);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(number_array);
	return (1);
}

int	check_error(char **str)
{
	if (check_if_number(str) == 0 || check_if_int(str) == 0 || 
		check_if_duplicate(str) == 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
		return (0);
}

void	check_exception(int argc, char **argv)
{
	char	**number_array;

	if (argc <= 1)
		exit(1);
	number_array = get_number_array(argv);
	if (check_error(number_array) == 1)
	{
		free_array(number_array);
		exit(2);
	}
	else
		free_array(number_array);
}

int	main(int argc, char *argv[])
{
	char	**number_array;
	int		i;

	check_exception(argc, argv);
	number_array = get_number_array(argv);
	i = 0;
	while (number_array[i] != (void *) 0)
	{
		ft_printf("number_array[%d]: %s\n", i, number_array[i]);
		i++;
	}
	free_array(number_array);
	system("leaks push_swap");
	return (0);
}
	
/*
t_list	*get_list(int argc, char **argv)
{
	t_list	*stack_a;
	char	**array;
	int		array_count;

	array_count = get_array_count(argc, argv);
	if (array_count == 0)
		return ((void *) 0);
	array = (char **) malloc((sizeof(char *) * array_count) + 1);
	if (array == 0)
		return (0);
	array = fill_array(array, argv);

	
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	if (argc <= 1)
		return (0);
	stack_a = get_list(argc, argv);
	if (stack_a == (void *) 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (0);	
}
*/
