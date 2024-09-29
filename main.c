/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:20:51 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 12:40:18 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (!is_proper_argv(argc, argv))
		return (1);
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (1);
	set_str_stack(argc, argv, stack);
	if (validate_str_stack(stack))
		binary_radix_sort(stack);
	free_stack(stack);
	return (0);
}

void	free_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->num_stack != NULL)
		free(stack->num_stack);
	while (i < stack->stack_len)
		free(stack->str_stack[i++]);
	free(stack->str_stack);
	free(stack->a_st);
	free(stack->b_st);
	free(stack);
}

int	validate_str_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->str_stack[i])
	{
		if (is_restorable(stack->str_stack[i]))
			i++;
		else
		{
			write(2, "Error\n: improper input\n", 23);
			return (0);
		}
	}
	stack->num_stack = atoi_stack(stack->str_stack);
	if (is_duplicated(stack))
	{
		write(2, "Error\n: duplicated input\n", 25);
		return (0);
	}
	return (1);
}

void	binary_radix_sort(t_stack *stack)
{
	int	i;
	int	mask;

	ready_sort(stack);
	if (stack->a_l == 0 || stack->a_l == 1)
		return ;
	if (is_already_sorted(stack, &mask, &i))
		return ;
	if (stack->stack_len <= 6)
	{
		special_sort(stack);
		return ;
	}
	mask = 0;
	do_radix_sort(stack, &mask, &i);
	return ;
}
