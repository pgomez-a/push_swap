/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:57:19 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/07 10:10:33 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack(int elem, t_node **stk)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (head)
	{
		head->value = elem;
		head->node = *stk;
		(*stk) = head;
	}
}

int	unstack(t_node **stk)
{
	t_node	*node;
	int	value;

	value = (*stk)->value;
	node = *stk;
	(*stk) = (*stk)->node;
	free(node);
	node = NULL;
	return (value);
}

int	len_stack(t_node **stk)
{
	t_node	*len;
	int	result;

	if (*stk)
	{
		len = *stk;
		result = 0;
		while (len)
		{
			result++;
			len = len->node;
		}
		return (result);
	}
	return (-1);
}

int	get_value_stack(int pos, t_node **stk)
{
	t_node	*node;
	int	count;

	if (*stk)
	{
		node = *stk;
		count = 0;
		while (node->node && count < pos)
		{
			count++;
			node = node->node;
		}
		return (node->value);
	}
	return (-9999);
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
