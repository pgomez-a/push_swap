/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:14:31 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 09:14:58 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 ** Sorts a stack of three numbers or less
 **/

void	sort_three(t_node **stk)
{
	int	last;
	int	sec;

	while (!stack_is_sorted(stk))
	{
		sec = (*stk)->node->value;
		last = value_from_pos_stack(3, stk);
		if ((*stk)->value < sec && (*stk)->value < last)
			call_swap("sa", stk);
		else if ((*stk)->value > sec && (*stk)->value < last)
			call_swap("sa", stk);
		else if ((*stk)->value < sec && (*stk)->value > last)
			call_down_rotate("rra", stk);
		else if ((*stk)->value > sec && (*stk)->value > last)
			call_up_rotate("ra", stk);
	}
}
