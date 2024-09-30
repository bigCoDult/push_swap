/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:20:38 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/30 12:25:29 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_cmp_result(char *copy_str, int *num, int *skip)
{
	int		cmp_result;
	char	*tmp;
	int		len;

	len = ft_strlen(copy_str) - (*skip);
	tmp = ft_itoa((*num));
	cmp_result = ft_memcmp(tmp, copy_str + (*skip), len);
	free(tmp);
	return (cmp_result);
}

void	write_minus(char *copy_str, int *skip, int *num)
{
	copy_str[(*skip)-- - 1] = '-';
	(*num) = ft_atoi(copy_str + (*skip));
}
