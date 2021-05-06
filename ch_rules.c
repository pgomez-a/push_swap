/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:04:19 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/05 10:09:11 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_swap(char *line, t_node **stk_a, t_node **stk_b)
{
	if (!ft_strncmp(line, "sa", 3))
		swap(stk_a);
	else if (!ft_strncmp(line, "sb", 3))
		swap(stk_b);
	else if (!ft_strncmp(line, "ss", 3))
	{
		swap(stk_a);
		swap(stk_b);
	}
	else
		ft_error("Error");
}

static void	check_rotate(char *line, t_node **stk_a, t_node **stk_b)
{
	if (!ft_strncmp(line, "ra", 3))
	{
		if (*stk_a)
			up_rotate(unstack(stk_a), stk_a);
	}
	else if (!ft_strncmp(line, "rb", 3))
	{
		if (*stk_b)
			up_rotate(unstack(stk_b), stk_b);
	}
	else if (!ft_strncmp(line, "rr", 3))
	{
		if (*stk_a)
			up_rotate(unstack(stk_a), stk_a);
		if (*stk_b)
			up_rotate(unstack(stk_b), stk_b);
	}	
	else if (!ft_strncmp(line, "rra", 4))
	{
		if (*stk_a)
			down_rotate(stk_a);
	}
	else if (!ft_strncmp(line, "rrb", 4))
	{
		if (*stk_b)
			down_rotate(stk_b);
	}
	else if (!ft_strncmp(line, "rrr", 4))
	{
		if (*stk_a)
			down_rotate(stk_a);
		if (*stk_b)
			down_rotate(stk_b);
	}
	else
		ft_error("Error");
}

static void	check_rule(char *line, t_node **stk_a, t_node **stk_b)
{
	if (!ft_strncmp(line, "s", 1))
		check_swap(line, stk_a, stk_b);
	else if (!ft_strncmp(line, "r", 1))
		check_rotate(line, stk_a, stk_b);
	else if (!ft_strncmp(line, "pa", 3))
		push(stk_b, stk_a);
	else if (!ft_strncmp(line, "pb", 3))
		push(stk_a, stk_b);
	else
		ft_error("Error");
}

void	ch_read_rules(t_node **stk_a, t_node **stk_b)
{
	char	*line;
	int		verif;

	read_stack(stk_a, stk_b);
	verif = get_next_line(0, &line);
	while (verif > 0)
	{
		check_rule(line, stk_a, stk_b);
		read_stack(stk_a, stk_b);
		free(line);
		verif = get_next_line(0, &line);
	}
	free(line);
	check_sort_list(stk_a, stk_b);
}
