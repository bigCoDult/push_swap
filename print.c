/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:20:38 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 09:51:22 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_to_find_error(t_stack *stack)
{
	ft_printf("\n");
	ft_printf("original\n\n");
	ft_printf("a_l : %d\nb_l : %d\n", stack->a_l, stack->b_l);
	print_ab(stack);
	ft_printf("\n");
	ft_printf("\n\npush pb\n\n\n");
	push(stack->b_st, stack->a_st, &(stack->b_l), &(stack->a_l));
	ft_printf("a_l : %d\nb_l : %d\n", stack->a_l, stack->b_l);
	print_ab(stack);
	ft_printf("\n\npush pa\n\n\n");
	push(stack->a_st, stack->b_st, &(stack->a_l), &(stack->b_l));
	ft_printf("a_l : %d\nb_l : %d\n", stack->a_l, stack->b_l);
	print_ab(stack);
	ft_printf("\n\nrotate ra\n\n\n");
	rotate(stack->a_st, stack->stack_len);
	ft_printf("a_l : %d\nb_l : %d\n", stack->a_l, stack->b_l);
	print_ab(stack);
	ft_printf("\n\npush pb\n\n\n");
	push(stack->b_st, stack->a_st, &(stack->b_l), &(stack->a_l));
	ft_printf("a_l : %d\nb_l : %d\n", stack->a_l, stack->b_l);
	print_ab(stack);
	push(stack->b_st, stack->a_st, &(stack->b_l), &(stack->a_l));
	ft_printf("a_l : %d\nb_l : %d\n", stack->a_l, stack->b_l);
	print_ab(stack);
	return ;
}

void	print_stack(int *target_stack, int stack_len)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (i < stack_len)
	{
		ft_printf("targer_stack[%d] : %d\n", i, target_stack[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}

void	print_str_stack(char **str_stack, int stack_len)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (i < stack_len)
	{
		ft_printf("str_stack[%d] : %s\n", i, str_stack[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}

void	print_ab(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("[A		B]\n");
	while (i < stack->stack_len)
	{
		ft_printf(" %d		%d\n", stack->a_st[i], stack->b_st[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}
