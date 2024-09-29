/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:06:53 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 09:51:22 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_sort(t_stack *stack)
{
	if (stack->stack_len == 2)
	{
		if (stack->a_st[0] > stack->a_st[1])
		{
			ft_printf("sa\n");
			swap(stack->a_st);
		}
		return ;
	}
	else if (stack->stack_len == 3)
	{
		mini_sort(stack);
		return ;
	}
	else if (stack->stack_len <= 6)
	{
		middle_sort(stack);
		return ;
	}
	return ;
}

void	middle_sort(t_stack *stack)
{
	pb_small(stack, 1);
	ft_printf("pb\n");
	pb_small(stack, 2);
	ft_printf("pb\n");
	pb_small(stack, 3);
	ft_printf("pb\n");
	if (stack->a_l == 2)
	{
		if (stack->a_st[0] > stack->a_st[1])
		{
			ft_printf("sa\n");
			swap(stack->a_st);
		}
	}
	else if (stack->a_l == 3)
		mini_sort(stack);
	ft_printf("pa\npa\npa\n");
	push(stack->a_st, stack->b_st, &(stack->a_l), &(stack->b_l));
	push(stack->a_st, stack->b_st, &(stack->a_l), &(stack->b_l));
	push(stack->a_st, stack->b_st, &(stack->a_l), &(stack->b_l));
	return ;
}

void	mini_sort(t_stack *stack)
{
	int	biggest;

	set_biggest(stack, &biggest);
	if (biggest == stack->a_st[0])
	{
		ra(stack);
		if (stack->a_st[0] > stack->a_st[1])
			sa(stack);
	}
	else if (biggest == stack->a_st[1])
	{
		if (stack->a_st[0] > stack->a_st[2])
			rra(stack);
		else if (stack->a_st[0] < stack->a_st[1])
		{
			sa(stack);
			ra(stack);
		}
	}
	else if (biggest == stack->a_st[2])
	{
		if (stack->a_st[0] > stack->a_st[1])
			sa(stack);
	}
	return ;
}

void	pb_small(t_stack *stack, int k)
{
	int				i;
	t_rotate_far	rotate_far;

	i = 0;
	while (stack->a_st[i] != k)
		i++;
	rotate_far = (t_rotate_far){i, stack->a_l - i};
	if (rotate_far.ra_far < rotate_far.rra_far)
	{
		while (rotate_far.ra_far-- > 0)
		{
			ft_printf("ra\n");
			rotate(stack->a_st, stack->a_l);
		}
	}
	else
	{
		while (rotate_far.rra_far-- > 0)
		{
			ft_printf("rra\n");
			reverse_rotate(stack->a_st, stack->a_l);
		}
	}
	push(stack->b_st, stack->a_st, &(stack->b_l), &(stack->a_l));
	return ;
}

void	set_biggest(t_stack *stack, int *biggest)
{
	int	i;

	i = 0;
	*biggest = 0;
	while (i < stack->a_l)
	{
		if (stack->a_st[i] > *biggest)
			*biggest = stack->a_st[i];
		i++;
	}
	return ;
}
