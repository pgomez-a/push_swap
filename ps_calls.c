/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:08:34 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 09:10:59 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 ** Executes and prints swap rule
 **/

void	call_swap(char *str, t_node **stk)
{
	swap(stk);
	ft_printf("%s\n", str);
}

/**
 ** Executes and prints push rule
 **/

void	call_push(char *str, t_node **stk_i, t_node **stk_d)
{
	push(stk_i, stk_d);
	ft_printf("%s\n", str);
}

/**
 ** Executes and prints up_rotate rule
 **/

void	call_up_rotate(char *str, t_node **stk)
{
	up_rotate(unstack(stk), stk);
	ft_printf("%s\n", str);
}

/**
 ** Executes and prints down_rotate rule
 **/

void	call_down_rotate(char *str, t_node **stk)
{
	down_rotate(stk);
	ft_printf("%s\n", str);
}

/**
 ** Rotates to the given num. If verif == 1, it rotates int stack_a, so
 ** the output is "xa"; otherwise it rotates stack_b, so the otput is "xb"
 **/

void	rotate_to_num(int verif, int num, t_node **stk)
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
			{
				if (verif == 1)
					call_down_rotate("rra", stk);
				else
					call_down_rotate("rrb", stk);
			}
			else
			{
				if (verif == 1)
					call_up_rotate("ra", stk);
				else
					call_up_rotate("rb", stk);
			}
		}
	}
}
