/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:15:39 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/05/07 11:19:11 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_swap(char *str, t_node **stk)
{
	swap(stk);
	ft_printf("%s\n", str);
}

void	call_push(char *str, t_node **stk_i, t_node **stk_d)
{
	push(stk_i, stk_d);
	ft_printf("%s\n", str);
}

void	call_up_rotate(char *str, t_node **stk)
{
	up_rotate(unstack(stk), stk);
	ft_printf("%s\n", str);
}

void	call_down_rotate(char *str, t_node **stk)
{
	down_rotate(stk);
	ft_printf("%s\n", str);
}
