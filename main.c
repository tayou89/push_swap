/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/02/23 23:37:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	check_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	get_array_count(char **argv)
{
	int	array_count;
	int	i;
	int	j;

	array_count = 0;
	i = 1;
	while (argv[i] != (void *) 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (check_whitespace(argv[i][j]) == 1)
				j++;
			else
			{
				while (check_whitespace(argv[i][j]) == 0)
					j++;
				array_count++;
			}
		}
		i++;
	}
	return (array_count);
}

int	main(int argc, char *argv[])
{
	int	array_count;

	if (argc <= 1)
		return (0);
	array_count = get_array_count(argv);
	ft_printf("array_count: %d\n", array_count);
	
	return (0);	
}
