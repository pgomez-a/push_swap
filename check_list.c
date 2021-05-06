#include "push_swap.h"

void	check_doubles(t_node **stk)
{
	t_node	*ct_y;
	t_node	*ct_x;

	ct_y = *stk;
	while (ct_y != NULL)
	{
		ct_x = ct_y->node;
		while (ct_x != NULL)
		{
			if (ct_y->value == ct_x->value)
				ft_error("Error");
			ct_x = ct_x->node;
		}
		ct_y = ct_y->node;
	}
}

void	check_sort_list(t_node **stk_a, t_node **stk_b)
{
	t_node	*min;
	t_node	*max;

	if (*stk_b != NULL)
		ft_error("KO");
	else if (*stk_a)
	{
		min = *stk_a;
		max = (*stk_a)->node;
		if (max == NULL)
			ft_printf("\033[92mOK\033[39m\n");
		else
		{
			while (max)
			{
				if (min->value > max->value)
					ft_error("KO");
				min = min->node;
				max = max->node;
			}
			ft_printf("\033[92mOK\033[39m\n");
		}
	}
	ft_error("KO");
}
