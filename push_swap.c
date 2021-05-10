/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:05:22 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 13:34:21 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****************
 * SORT HUNDRED *
 * *************/

/*****************/

static void	set_rules(t_node **stk_a, t_node **stk_b)
{
	int	len;

	len = len_stack(stk_a);
	if (len <= 3)
		sort_three(stk_a);
	else if (len <= 10)
		sort_five(len, stk_a, stk_b);
	else if (len <= 100)
		sort_hundred(len, stk_a, stk_b);
	else
		sort_five_hundred(len, stk_a, stk_b);
}

int	main(int argc, char *argv[])
{
	t_node		*stk_a;
	t_node		*stk_b;
	int			count;
	int			verif;

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
