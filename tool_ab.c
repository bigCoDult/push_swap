/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:48:13 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 10:48:14 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate(stack->a_st, stack->a_l);
	ft_printf("ra\n");
	return ;
}

void	sa(t_stack *stack)
{
	swap(stack->a_st);
	ft_printf("sa\n");
	return ;
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack->a_st, stack->a_l);
	ft_printf("rra\n");
	return ;
}
