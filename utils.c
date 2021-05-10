/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:04:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 09:16:57 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 ** Exits when an error occurs
 **/

void	ft_error(char *str)
{
	ft_printf("\033[31m");
	ft_printf("%s\n", str);
	ft_printf("\033[39m");
	exit(0);
}

/**
 ** Get the next number of the given number in stack. For example, if we
 ** have 4 from 3 2 4 1 7 5 8, it will return 5
 **/

int	get_next_num(int elem, t_node **stk)
{
	t_node	*node;
	int		result;

	result = -9999;
	if (*stk)
	{
		node = *stk;
		while (node)
		{
			if (result < elem && node->value > elem)
				result = node->value;
			else if (node->value > elem && node->value < result)
				result = node->value;
			node = node->node;
		}
	}
	return (result);
}
