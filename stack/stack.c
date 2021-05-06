/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:57:19 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/04 14:02:17 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack(int elem, t_node **stk)
{
	t_node	*pos;

	pos = (t_node *)malloc(sizeof(t_node));
	if (pos)
	{
		pos->value = elem;
		pos->node = *stk;
		(*stk) = pos;
	}
}

int	unstack(t_node **stk)
{
	t_node	*tmp;
	int	value;

	value = (*stk)->value;
	tmp = *stk;
	(*stk) = (*stk)->node;
	free(tmp);
	tmp = NULL;
	return (value);
}

void	read_stack(t_node **stk_a, t_node **stk_b)
{
	t_node	*a;
	t_node	*b;

	a = *stk_a;
	b = *stk_b;
	while (a && b)
	{
		ft_printf("|%5d    |     |%5d    |\n", a->value, b->value);
		a = a->node;
		b = b->node;
	}
	if (a)
	{
		ft_printf("|%5d    |     |_________|\n", a->value);
		a = a->node;
		while (a)
		{
			ft_printf("|%5d    |\n", a->value);
			a = a->node;
		}
		ft_printf("|_________|\n");
	}
	else if (b)
	{
		ft_printf("|_________|     |%5d    |\n", b->value);
		b = b->node;
		while (b)
		{
			ft_printf("                |%5d    |\n", b->value);
			b = b->node;
		}
		ft_printf("                |_________|\n");
	}
}
