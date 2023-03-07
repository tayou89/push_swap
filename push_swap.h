/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:39:01 by tayou             #+#    #+#             */
/*   Updated: 2023/03/07 14:14:19 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	t_node	*front;
	t_node	*back;
}	t_deque;


char		**get_number_array(char **argv);
void		check_exception(int argc, char **argv);

long long	ft_atoi_longlong(const char *str);
int			ft_isspace(int c);
void		free_array(char **array);
void		free_list(t_node *list);
void		pass_space(char *str, int *i);

#endif
