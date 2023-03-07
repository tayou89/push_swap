/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:51:37 by tayou             #+#    #+#             */
/*   Updated: 2023/03/07 14:24:21 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pass_sign(char *str, int *i)
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

static int	check_if_int(char **str)
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

static int	get_number_count(char **str)
{
	int	number_count;
	int	i;

	i = 0;
	while (str[i] != (void *) 0)
		i++;
	number_count = i;
	return (number_count);
}

static int	*fill_number_array(int *number_array, char **str)
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

static int	check_if_duplicate(char **str)
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
		while (j < number_count)
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

static int	check_error(char **str)
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
