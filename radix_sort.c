/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 09:29:53 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 10:47:47 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_radix_sort(t_stack *stack, int *mask, int *i)
{
	while ((*mask) <= stack->max_mask)
	{
		(*i) = 0;
		while ((*i) + (stack->b_l) < stack->stack_len)
		{
			if ((stack->a_st[0] >> (*mask) & 1) == 0)
			{
				ft_printf("pb\n");
				push(stack->b_st, stack->a_st, &(stack->b_l), &(stack->a_l));
			}
			else
			{
				ft_printf("ra\n");
				rotate(stack->a_st, stack->a_l);
				(*i)++;
			}
		}
		while (stack->b_l > 0)
		{
			ft_printf("pa\n");
			push(stack->a_st, stack->b_st, &(stack->a_l), &(stack->b_l));
		}
		(*mask)++;
	}
}

int	is_already_sorted(t_stack *stack, int *mask, int *i)
{
	int	*snap_a_1;
	int	*snap_a_2;

	snap_a_1 = (int *)ft_calloc(stack->stack_len, sizeof(int));
	snap_a_2 = (int *)ft_calloc(stack->stack_len, sizeof(int));
	ft_memmove(snap_a_1, stack->a_st, stack->stack_len * 4);
	ft_memmove(snap_a_2, stack->a_st, stack->stack_len * sizeof(int));
	(*mask) = 0;
	sort_sh(stack, snap_a_2, mask, i);
	if (ft_memcmp(snap_a_2, snap_a_1, stack->stack_len * sizeof(int)) == 0)
		return (1);
	return (0);
}

void	sort_sh(t_stack *stack, int *snap_a_2, int *mask, int *i)
{
	while ((*mask) <= stack->max_mask)
	{
		(*i) = 0;
		while ((*i) + stack->b_l < stack->stack_len)
		{
			if ((snap_a_2[0] >> (*mask) & 1) == 0)
				push(stack->b_st, snap_a_2, &(stack->b_l), &(stack->a_l));
			else
			{
				rotate(snap_a_2, stack->a_l);
				(*i)++;
			}
		}
		while (stack->b_l > 0)
			push(snap_a_2, stack->b_st, &(stack->a_l), &(stack->b_l));
		(*mask)++;
	}
}

void	ready_sort(t_stack *stack)
{
	stack->a_st = (int *)ft_calloc(stack->stack_len, sizeof(int));
	stack->b_st = (int *)ft_calloc(stack->stack_len, sizeof(int));
	if (stack->a_st == NULL || stack->b_st == NULL)
		return ;
	set_ranking_stack(stack->a_st, stack->num_stack, stack->stack_len);
	stack->tmp_max_mask = 1 << 30;
	while (!(stack->stack_len & stack->tmp_max_mask))
		stack->tmp_max_mask = stack->tmp_max_mask >> 1;
	while (stack->tmp_max_mask > 1)
	{
		stack->tmp_max_mask = stack->tmp_max_mask >> 1;
		stack->max_mask++;
	}
	stack->a_l = stack->stack_len;
	stack->b_l = stack->a_l - stack->stack_len;
	return ;
}

void	set_ranking_stack(int *target_stack, int *num_stack, int stack_len)
{
	int	i;
	int	k;

	i = 0;
	while (i < stack_len)
		target_stack[i++] = 1;
	i = 0;
	while (i < stack_len)
	{
		k = i + 1;
		while (k < stack_len)
		{
			if (num_stack[i] > num_stack[k])
				target_stack[i]++;
			else if (num_stack[i] < num_stack[k])
				target_stack[k]++;
			k++;
		}
		i++;
	}
	return ;
}
