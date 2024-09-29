/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:18:19 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 11:16:45 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *dest_stack, int *src_stack, int *dest_len, int *src_len)
{
	if (*src_len == 0)
	{
		write(2, "Error\n: improper push\n", 23);
		return ;
	}
	ft_memmove(dest_stack + 1, dest_stack, (*dest_len) * sizeof(int));
	dest_stack[0] = src_stack[0];
	(*dest_len)++;
	ft_memmove(src_stack, src_stack + 1, (*src_len + *dest_len - 2) * 4);
	src_stack[*src_len - 1] = 0;
	(*src_len)--;
}

void	rotate(int *target_stack, int target_len)
{
	int	tmp;

	tmp = target_stack[0];
	ft_memmove(target_stack, target_stack + 1, (target_len - 1) * sizeof(int));
	target_stack[target_len - 1] = tmp;
}

void	reverse_rotate(int *target_stack, int target_len)
{
	int	tmp;

	tmp = target_stack[target_len - 1];
	ft_memmove(target_stack + 1, target_stack, (target_len - 1) * sizeof(int));
	target_stack[0] = tmp;
}

void	swap(int *target_stack)
{
	int	tmp;

	tmp = target_stack[0];
	target_stack[0] = target_stack[1];
	target_stack[1] = tmp;
}
