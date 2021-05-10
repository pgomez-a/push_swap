/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:04:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/05 10:09:51 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_printf("\033[31m");
	ft_printf("%s\n", str);
	ft_printf("\033[39m");
	exit(0);
}

int	get_next_num(int elem, t_node **stk)
{
	t_node	*node;
	int	result;

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
