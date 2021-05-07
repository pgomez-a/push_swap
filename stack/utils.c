#include "stack.h"

int	get_min_stack(t_node **stk)
{
	t_node	*node;
	int	min;

	if (*stk)
	{
		node = *stk;
		min = node->value;
		while (node)
		{
			if (min > node->value)
				min = node->value;
			node = node->node;
		}
		return (min);
	}
	return (-9999);
}

int	get_max_stack(t_node **stk)
{
	t_node	*node;
	int	max;

	if (*stk)
	{
		node = *stk;
		max = node->value;
		while (node)
		{
			if (max < node->value)
				max = node->value;
			node = node->node;
		}
		return (max);
	}
	return (-9999);
}

/* Return the value of the given position */
int	value_from_pos_stack(int pos, t_node **stk)
{
	t_node	*node;
	int	count;

	if (*stk)
	{
		node = *stk;
		count = 1;
		while (node->node && count < pos)
		{
			count++;
			node = node->node;
		}
		return (node->value);
	}
	return (-9999);
}

/* Return the position of the given value */
int	pos_from_value_stack(int elem, t_node **stk)
{
	t_node	*node;
	int	count;

	if (*stk)
	{
		node = *stk;
		count = 0;
		while (node)
		{
			if (node->value == elem)
				return (count);
			count++;
			node = node->node;
		}
	}
	return (-9999);
}
