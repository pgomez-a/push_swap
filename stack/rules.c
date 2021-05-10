/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:17:35 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 09:18:13 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 ** Swap rule
 **/

void	swap(t_node **stk)
{
	int	elemOne;
	int	elemTwo;

	if ((*stk) && (*stk)->node)
	{
		elemOne = unstack(stk);
		elemTwo = unstack(stk);
		stack(elemOne, stk);
		stack(elemTwo, stk);
	}
}

/**
 ** Push rule
 **/

void	push(t_node **stk_i, t_node **stk_d)
{
	int	elem;

	if ((*stk_i))
	{
		elem = unstack(stk_i);
		stack(elem, stk_d);
	}
}

/**
 ** Up Rotate rule
 **/

void	up_rotate(int rot, t_node **stk)
{
	int	elem;

	if ((*stk) != NULL)
	{
		elem = unstack(stk);
		up_rotate(rot, stk);
		stack(elem, stk);
	}
	else
		stack(rot, stk);
}

/**
 ** Down Rotate rule
 **/

void	down_rotate(t_node **stk)
{
	t_node	*node;
	int		elem;

	if ((*stk)->node)
	{
		node = *stk;
		while (node->node->node != NULL)
			node = node->node;
		elem = node->node->value;
		free(node->node);
		node->node = NULL;
		stack(elem, stk);
	}
}
