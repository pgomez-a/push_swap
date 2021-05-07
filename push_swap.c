/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:05:22 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/07 11:28:56 by pgomez-a         ###   ########.fr       */
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

static void	sort_three(t_node **stk_a)
{
	int	last;
	int	sec;
	int	tot;

	tot = 0;
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
	ft_printf("tot: %d\n", tot);
}

static void	set_rules(t_node **stk_a, t_node **stk_b)
{
	int	len;

	len = len_stack(stk_a);
	if (len <= 3)
		sort_three(stk_a);
	read_stack(stk_a, stk_b);
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
