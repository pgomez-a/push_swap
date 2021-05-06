/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:45:17 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/05 10:06:28 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./stack/stack.h"
#include <stdio.h>

/* check_input.c */
int	find_variable(char *str);
void	check_argument(char *str);
void	check_argv(char *str, t_node **stk);
void	check_variable(char *str, t_node **stk);

/* check_list.c */
void	check_doubles(t_node **stk);
void	check_sort_list(t_node **stk_a, t_node **stk_b);

/* utils.c */
void	ft_error(char *str);

/* ch_rules.c */
void	ch_read_rules(t_node **stk_a, t_node **stk_b);

#endif
