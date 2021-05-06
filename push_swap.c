/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:43:25 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/05 10:09:21 by pgomez-a         ###   ########.fr       */
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

static void	set_rules(t_node **stk_a, t_node **stk_b)
{
	int	len;
	int	val;
	int	sec;
	int	last;

	while (!stack_is_sorted(stk_a))
	{
		len = len_stack(stk_a);
		last = get_value_stack(len, stk_a);
		val = (*stk_a)->value;
		sec = (*stk_a)->node->value;
		if (val < sec && val < last)
		{
			ft_printf("sa\n");
			swap(stk_a);
		}
		else if (val > sec && val < last)
		{
			ft_printf("ra\n");
			up_rotate(unstack(stk_a), stk_a);
		}
		else if (val < last && val > sec)
		{
			ft_printf("sa\n");
			swap(stk_a);
		}
		else if (val > last && val < sec)
		{
			ft_printf("rra\n");
			down_rotate(stk_a);
		}
		else if (val > sec && val > last)
		{
			ft_printf("ra\n");
			up_rotate(unstack(stk_a), stk_a);
		}
		ft_printf("\n\n");
		read_stack(stk_a, stk_b);
	}
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
	system("leaks push_swap");
}
