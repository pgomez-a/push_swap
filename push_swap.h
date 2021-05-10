/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:45:17 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/07 11:12:43 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./stack/stack.h"
#include <stdio.h>

/* check_input.c */
int		find_variable(char *str);
void	check_argument(char *str);
void	check_argv(char *str, t_node **stk);
void	check_variable(char *str, t_node **stk);

/* check_list.c */
void	check_doubles(t_node **stk);
void	check_sort_stack(t_node **stk_a, t_node **stk_b);
int	stack_is_sorted(t_node **stk);

/* utils.c */
void	ft_error(char *str);
int	get_next_num(int elem, t_node **stk);

/* ch_rules.c */
void	ch_read_rules(t_node **stk_a, t_node **stk_b);

/* ps_calls.c */
void	call_swap(char *str, t_node **stk);
void	call_push(char *str, t_node **stk_i, t_node **stk_d);
void	call_up_rotate(char *str, t_node **stk);
void	call_down_rotate(char *str, t_node **stk);
void	rotate_to_num(int verif, int num, t_node **stk);

/* ps_three.c */
void	sort_three(t_node **stk);

/* ps_five.c */
void	sort_five(int len, t_node **stk_a, t_node **stk_b);

#endif
