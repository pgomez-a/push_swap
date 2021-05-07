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

static int	stack_is_sorted(t_node **stk)
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

/**************
 * SORT THREE *
 * ***********/

static int	sort_three(int tot, t_node **stk_a)
{
	int	last;
	int	sec;

	while (!stack_is_sorted(stk_a))
	{
		sec = (*stk_a)->node->value;
		last = value_from_pos_stack(3, stk_a);
		if ((*stk_a)->value < sec && (*stk_a)->value < last)
			call_swap("sa", stk_a);
		else if ((*stk_a)->value > sec && (*stk_a)->value < last)
			call_swap("sa", stk_a);
		else if ((*stk_a)->value < sec && (*stk_a)->value > last)
			call_down_rotate("rra", stk_a);
		else if ((*stk_a)->value > sec && (*stk_a)->value > last)
			call_up_rotate("ra", stk_a);
		tot++;
	}
	return (tot);
}
/******************/


/*************
 * SORT FIVE *
 * **********/

static int	rotate_to_num(int tot, int num, t_node **stk)
{
	int	len;
	int	pos;

	if (*stk)
	{
		len = len_stack(stk);
		pos = pos_from_value_stack(num, stk);
		while ((*stk)->value != num)
		{
			if (pos > len / 2)
				call_down_rotate("rra", stk);
			else
				call_up_rotate("ra", stk);
			tot++;
		}
	}
	return (tot);
}

static int	get_next_num(int elem, t_node **stk)
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

static int	sort_five(int tot, int len, t_node **stk_a, t_node **stk_b)
{
	int	max;
	int	min;
	int	next;
	int	pos;

	while (len > 3 && !stack_is_sorted(stk_a))
	{
		call_push("pb", stk_a, stk_b);
		tot++;
		len--;
	}
	tot = sort_three(tot, stk_a);
	read_stack(stk_a, stk_b);
	ft_printf("\n");
	while (*stk_b)
	{
		max = get_max_stack(stk_a);
		min = get_min_stack(stk_a);
		if ((*stk_b)->value > max)
			tot = rotate_to_num(tot, min, stk_a);
		else if ((*stk_b)->value < min)
			tot = rotate_to_num(tot, min, stk_a);
		else
		{
			next = get_next_num((*stk_b)->value, stk_a);
			tot = rotate_to_num(tot, next, stk_a);
		}
		read_stack(stk_a, stk_b);
		call_push("pb", stk_b, stk_a);
		read_stack(stk_a, stk_b);
		tot++;
	}
	len = len_stack(stk_a);
	pos = pos_from_value_stack(min, stk_a);
	while (!stack_is_sorted(stk_a))
	{
		if (pos > len / 2)
			call_down_rotate("rra", stk_a);
		else
			call_up_rotate("ra", stk_a);
		tot++;
	}
	return (tot);
}
/*****************/

static void	set_rules(t_node **stk_a, t_node **stk_b)
{
	int	len;
	int	tot;

	len = len_stack(stk_a);
	tot = 0;
	if (len <= 3)
		tot = sort_three(tot, stk_a);
	else if (len <= 5)
		tot = sort_five(tot, len, stk_a, stk_b);
	read_stack(stk_a, stk_b);
	ft_printf("tot: %d\n", tot);
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
	//system("leaks push_swap");
}
