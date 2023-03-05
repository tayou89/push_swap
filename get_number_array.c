/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:59:23 by tayou             #+#    #+#             */
/*   Updated: 2023/03/05 08:11:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pass_notspace(char *str, int *i)
{
	while (ft_isspace(str[*i]) == 0 && str[*i] != '\0')
		(*i)++;
}

static int	get_array_count(char **argv)
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

static int	get_array_size(char *str, int *i)
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

static char	*fill_array(char *array, char *str, int size)
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

static char	**malloc_array(char **array, char **argv)
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
				exit(1);
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
		exit(1);
	number_array = (char **) malloc((sizeof(char *) * array_count) + 1);
	if (number_array == 0)
		exit(1);
	number_array = malloc_array(number_array, argv);
	number_array[array_count] = 0;
	return (number_array);
}
