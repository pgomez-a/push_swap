/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:43:25 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/07 10:14:37 by pgomez-a         ###   ########.fr       */
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

static void	recursive_sort(int *tot, t_node **stk_a, t_node **stk_b)
{
	int	len;

	len = len_stack(stk_a);
	if (len > 1)
	{
		push(stk_a, stk_b);
		ft_printf("pb\n");
		(*tot) += 1;
		recursive_sort(tot, stk_a, stk_b);
		push(stk_b, stk_a);
		ft_printf("pa\n");
		(*tot) += 1;
		if ((*stk_a)->value > (*stk_a)->node->value)
		{
			swap(stk_a);
			ft_printf("sa\n");
			(*tot) += 1;
		}
	}
}

static void	set_rules(t_node **stk_a, t_node **stk_b)
{
	//int	len;
	//int	val;
	//int	sec;
	//int	last;
	int		*tot;

	tot = (int *)malloc(sizeof(int) * 1);
	(*tot) = 0;
	while (!stack_is_sorted(stk_a))
	{
		recursive_sort(tot, stk_a, stk_b);
	}
	ft_printf("\n\n");
	read_stack(stk_a, stk_b);
	ft_printf("tot: %d\n\n\n", *tot);
	free(tot);
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
