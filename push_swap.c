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
		read_stack(&stk_a, &stk_b);
	}
	system("leaks checker");
}
