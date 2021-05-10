/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:47:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/10 08:52:38 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libft/libft.h"

typedef struct s_node {
	int				value;
	struct s_node	*node;
}	t_node;

/* stack.c */
void	stack(int elem, t_node **stk);
int		unstack(t_node **stk);
int		len_stack(t_node **stk);
void	read_stack(t_node **a, t_node **b);

/* rules.c */
void	swap(t_node **stk);
void	push(t_node **stk_i, t_node **stk_d);
void	up_rotate(int rot, t_node **stk);
void	down_rotate(t_node **stk);

/* utils.c */
int		get_min_stack(t_node **stk);
int		get_max_stack(t_node **stk);
int		value_from_pos_stack(int pos, t_node **stk);
int		pos_from_value_stack(int elem, t_node **stk);

#endif
