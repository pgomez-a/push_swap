/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:06:55 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 09:08:08 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 ** Checks if there are repeated numbers in the stack
 **/

void	check_doubles(t_node **stk)
{
	t_node	*ct_y;
	t_node	*ct_x;

	ct_y = *stk;
	while (ct_y != NULL)
	{
		ct_x = ct_y->node;
		while (ct_x != NULL)
		{
			if (ct_y->value == ct_x->value)
				ft_error("Error");
			ct_x = ct_x->node;
		}
		ct_y = ct_y->node;
	}
}

/**
 ** Checks if the list is sorted for the checker program
 **/

void	check_sort_stack(t_node **stk_a, t_node **stk_b)
{
	t_node	*min;
	t_node	*max;

	if (*stk_b != NULL)
		ft_error("KO");
	else if (*stk_a)
	{
		min = *stk_a;
		max = (*stk_a)->node;
		if (max == NULL)
			ft_printf("\033[92mOK\033[39m\n");
		else
		{
			while (max)
			{
				if (min->value > max->value)
					ft_error("KO");
				min = min->node;
				max = max->node;
			}
			ft_printf("\033[92mOK\033[39m\n");
			exit(0);
		}
	}
	ft_error("KO");
}

/**
 ** Checks if the list is sorted for the push_swap program
 **/

int	stack_is_sorted(t_node **stk)
{
	t_node	*min;
	t_node	*max;

	if (*stk)
	{
		min = *stk;
		max = (*stk)->node;
		if (max != NULL)
		{
			while (max)
			{
				if (min->value > max->value)
					return (0);
				min = min->node;
				max = max->node;
			}
		}
	}
	return (1);
}
