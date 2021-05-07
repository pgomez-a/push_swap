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
		last = get_value_stack(2, stk_a);
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


static int	sort_five(int tot, int len, t_node **stk_a, t_node **stk_b)
{
	int	max;
	int	min;

	while (len > 3)
	{
		call_push("pb", stk_a, stk_b);
		tot++;
		len--;
	}
	tot = sort_three(tot, stk_a);
	while (*stk_b)
	{
		max = get_max_stack(stk_a);
		min = get_min_stack(stk_a);
		read_stack(stk_a, stk_b);
		if ((*stk_b)->value < min)
		{
			call_push("pa", stk_b, stk_a);
			tot++;
		}
		else if ((*stk_b)->value > max)
		{
			call_push("pa", stk_b, stk_a);
			call_up_rotate("ra", stk_a);
			tot += 2;
		}
		else if ((*stk_b)->value > min && (*stk_b)->value < max)
		{
			while ((*stk_a)->value != max)
			{
				call_up_rotate("ra", stk_a);
				tot++;
			}
			call_push("pa", stk_b, stk_a);
			tot++;
		}
	}
	read_stack(stk_a, stk_b);
	exit(0);
	while (!stack_is_sorted(stk_a))
	{
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
	ft_printf("val: %d\n", get_value_stack(4, stk_a));
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
