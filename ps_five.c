/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:11:08 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 09:14:25 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 ** Sort stack_a the best way to introduce a number from top of stack_b
 **/

static void	rotate_five_stack(int min, int max, t_node **stk_a, t_node **stk_b)
{
	int	next;

	if ((*stk_b)->value > max)
		rotate_to_num(1, min, stk_a);
	else if ((*stk_b)->value < min)
		rotate_to_num(1, min, stk_a);
	else
	{
		next = get_next_num((*stk_b)->value, stk_a);
		rotate_to_num(1, next, stk_a);
	}
}

/**
 ** Once the stack is sorted, it rotates until the min is at the top
 **/

static void	sort_five_stack(int min, t_node **stk_a)
{
	int	len;
	int	pos;

	len = len_stack(stk_a);
	pos = pos_from_value_stack(min, stk_a);
	while (!stack_is_sorted(stk_a))
	{
		if (pos > len / 2)
			call_down_rotate("rra", stk_a);
		else
			call_up_rotate("ra", stk_a);
	}
}

/**
 ** Sorts the stack if it has ten or less numbers, but optimized for five
 **/

void	sort_five(int len, t_node **stk_a, t_node **stk_b)
{
	int	min;
	int	max;

	while (len > 3 && !stack_is_sorted(stk_a))
	{
		call_push("pb", stk_a, stk_b);
		len--;
	}
	sort_three(stk_a);
	while (*stk_b)
	{
		min = get_min_stack(stk_a);
		max = get_max_stack(stk_a);
		rotate_five_stack(min, max, stk_a, stk_b);
		call_push("pa", stk_b, stk_a);
	}
	sort_five_stack(min, stk_a);
}
