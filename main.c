/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/02/26 17:26:16 by tayou            ###   ########.fr       */
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

void	pass_notspace(char *str, int *i)
{
	while (ft_isspace(str[*i]) == 0 && str[*i] != '\0')
		(*i)++;
}

int	get_array_count(char **argv)
{
	int	i;
	int	j;
	int	array_count;

	array_count = 0;
	i = 1;
	while (argv[i] != (void *) 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			pass_space(argv[i], &j);
			pass_notspace(argv[i], &j);
			array_count++;
		}
		i++;
	}
	return (array_count);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	get_array_size(char *str, int *i)
{
	int	size;
	int	start_point;
	int	end_point;

	start_point = *i;
	pass_space(str, i);
	pass_notspace(str, i);
	end_point = *i - 1;
	size = end_point - start_point + 1;
	return (size);
}

char	*fill_array(char *array, char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**malloc_array(char **array, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	size;

	k = 0;
	i = 1;
	while (argv[i] != (void *) 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			size = get_array_size(argv[i], &j);
			array[k] = (char *) malloc(sizeof(char) * size + 1);
			if (array[k] == 0)
			{
				free_array(array);
				return (0);
			}
			array[k] = fill_array(array[k], &argv[i][j-size], size);
			k++;
		}
		i++;
	}
	return (array);
}

char	**get_number_array(char **argv)
{
	char	**number_array;
	int		array_count;

	array_count = get_array_count(argv);
	if (array_count == 0)
		return (0);
	number_array = (char **) malloc((sizeof(char *) * array_count) + 1);
	if (number_array == 0)
		return (0);
	number_array = malloc_array(number_array, argv);
	number_array[array_count] = (void *) 0;
	return (number_array);
}

void	pass_sign(char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
}

int	check_if_number(char **str)
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
			if (ft_isdigit == 1)
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
	int_min = –2147483648;
	i = 0;
	while (str[i] != (void *) 0)
	{
		number = ft_atoi_longlong(str[i]);
		if (number < int_min || number > int_max)
			return (0);
		else
			i++;
	}
}

int	check_error(char **str)
{
	if (check_if_number(str) == 0)
		return (0);
	if (check_if_int(str) == 0)
		return (0);
}

int	main(int argc, char *argv[])
{
	char	**number_array;
	int		i;

	if (argc <= 1)
		return (0);
	number_array = get_number_array(argv);
	if (number_array == 0)
		return (0);
	if (check_error(number_array) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 0;
	while (number_array[i] != (void *) 0)
	{
		ft_printf("array[%d]: %s\n", i, number_array[i]);
		i++;
	}
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
