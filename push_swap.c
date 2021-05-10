/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:05:22 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/07 14:28:32 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****************
 * SORT HUNDRED *
 * *************/

static int	first_in_part(int num, int parts, t_node **stk)
{
	t_node	*node;
	int	count;

	count = 0;
	if (*stk)
	{
		node = *stk;
		while (node)
		{
			if (node->value < num)
				count++;
			node = node->node;
		}
	}
	if (count < parts)
		return (1);
	return (0);
}

static void	look_for_part(int parts, int len, t_node **stk_a, t_node **stk_b)
{
	t_node	*node;
	int	pos;
	int	min;
	int	max;
	int	next;

	if (*stk_a)
	{
		if (len < parts)
			parts = len;
		while (parts > 0)
		{
			node = *stk_a;
			min = node->value;
			while (node && !first_in_part(min, parts, stk_a))
			{
				node = node->node;
				min = node->value;
			}
			parts--;
			pos = pos_from_value_stack(min, stk_a);
			while ((*stk_a)->value != min)
			{
				if (pos > len / 2)
					call_down_rotate("rra", stk_a);
				else
					call_up_rotate("ra", stk_a);
			}
			max = get_max_stack(stk_b);
			min = get_min_stack(stk_b);
			if ((*stk_a)->value > max)
				rotate_to_num(0, min, stk_b);
			else if ((*stk_a)->value < min)
				rotate_to_num(0, min, stk_b);
			else
			{
				next = get_next_num((*stk_a)->value, stk_b);
				rotate_to_num(0, next, stk_b);
			}
			call_push("pb", stk_a, stk_b);
		}
		read_stack(stk_a, stk_b);
		exit(0);
	}
}

static void	sort_hundred(t_node **stk_a, t_node **stk_b)
{
	int	parts;
	int	count;
	int	len;
	int	max;

	len = len_stack(stk_a);
	parts = len / 5;
	count = 0;
	while (count < 5)
	{
		look_for_part(parts, len, stk_a, stk_b);
		len = len_stack(stk_a);
		count++;
	}
	max = get_max_stack(stk_b);
	rotate_to_num(0, max, stk_b);
	while (*stk_b)
	{
		call_push("pa", stk_b, stk_a);
		if (*stk_b)
			call_down_rotate("rrb", stk_b);
	}
}
/*****************/

static void	set_rules(t_node **stk_a, t_node **stk_b)
{
	int	len;

	len = len_stack(stk_a);
	if (len <= 3)
		sort_three(stk_a);
	else if (len <= 10)
		sort_five(len, stk_a, stk_b);
	else
		sort_hundred(stk_a, stk_b);
}

int	main(int argc, char *argv[])
{
	int		count;
	int		verif;
	t_node		*stk_a;
	t_node		*stk_b;

	if (argc > 1)
	{
		count = argc - 1;
		while (count >= 1)
		{
			verif = find_variable(argv[count]);
			if (verif == 0)
				check_argv(argv[count], &stk_a);
			else
				check_variable(argv[count], &stk_a);
			count--;
		}
		check_doubles(&stk_a);
		set_rules(&stk_a, &stk_b);
	}
}
