/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/02/08 15:45:42 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 0)
		return (0);
	printf("argc: %d\n", argc);
	printf("argv[0]: %s\n", argv[0]);
	i = 1;
	while (i < argc)
	{
		printf("argv[%d][1] = %d\n", i, argv[i][1] - '0');
		i++;
	}
	return (0);
}
	
