/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:58:08 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 13:24:36 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 ** Checks the numbers that should be in each part
 **/

static int	first_in_part(int num, int parts, t_node **stk)
{
	t_node	*node;
	int		count;

	count = 0;
	if (*stk)
	{
		node = *stk;
		while (node)
		{
			if (node->value > num)
				count++;
			node = node->node;
		}
	}
	if (count < parts)
		return (1);
	return (0);
}

/**
 ** Moves the max value of stack_a to top though the shortest path
 **/

static void	move_to_pos(int len, int max, t_node **stk_a)
{
	int	pos;

	pos = pos_from_value_stack(max, stk_a);
	while ((*stk_a)->value != max)
	{
		if (pos > len / 2)
			call_down_rotate("rra", stk_a);
		else
			call_up_rotate("ra", stk_a);
	}
}

/**
 ** Rotates the max value of stack_b to top in order to put the next
 ** max number from top of stack_a
 **/

static void	rotate_to_top(t_node **stk_a, t_node **stk_b)
{
	int	min;
	int	max;
	int	next;

	min = get_min_stack(stk_b);
	max = get_max_stack(stk_b);
	if ((*stk_a)->value > max)
		rotate_to_num(0, max, stk_b);
	else if ((*stk_a)->value < min)
		rotate_to_num(0, max, stk_b);
	else
	{
		next = get_prev_num((*stk_a)->value, stk_b);
		rotate_to_num(0, next, stk_b);
	}
}

/**
 ** Puts the first numbers of a part in stack_b
 **/

static void	look_for_part(int parts, int len, t_node **stk_a, t_node **stk_b)
{
	t_node	*node;
	int		max;

	if (*stk_a)
	{
		if (len < parts)
			parts = len;
		while (parts > 0)
		{
			node = *stk_a;
			max = node->value;
			while (node && !first_in_part(max, parts, stk_a))
			{
				node = node->node;
				max = node->value;
			}
			parts--;
			move_to_pos(len, max, stk_a);
			rotate_to_top(stk_a, stk_b);
			call_push("pb", stk_a, stk_b);
		}
	}
}

/**
 ** Sorts a stack of 100 or less numberss
 **/

void	sort_hundred(int len, t_node **stk_a, t_node **stk_b)
{
	int	parts;
	int	count;
	int	max;

	parts = len / 8;
	count = 0;
	while (count < 9)
	{
		look_for_part(parts, len, stk_a, stk_b);
		len = len_stack(stk_a);
		count++;
	}
	max = get_max_stack(stk_b);
	rotate_to_num(0, max, stk_b);
	while (*stk_b)
		call_push("pa", stk_b, stk_a);
}
