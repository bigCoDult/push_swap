#include "push_swap.h"

void binary_radix_sort(t_stack *stack)
{
	int i;
	int mask;
	int *snapshot_a_stack;
	int *check_a_stack;
	
	snapshot_a_stack = (int *)ft_calloc(stack->stack_len, sizeof(int));
	check_a_stack = (int *)ft_calloc(stack->stack_len, sizeof(int));
	ready_sort(stack);
	ft_memmove(snapshot_a_stack, stack->a_stack, stack->stack_len * sizeof(int));
	ft_memmove(check_a_stack, stack->a_stack, stack->stack_len * sizeof(int));
	mask = 0;
	while (mask <= stack->max_mask)
	{
		i = 0;
		while (i + (stack->b_len)  < stack->stack_len)
		{
			if ((check_a_stack[0] >> mask & 1) == 0)
			{
				push(stack->b_stack, check_a_stack, &(stack->b_len), &(stack->a_len));
			}
			else
			{
				rotate(check_a_stack, stack->a_len);
				i++;
			}
		}
		while (stack->b_len > 0)
		{
			push(check_a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
		}
		mask++;
	}
	
	if (stack->stack_len <= 6)
	{
		special_sort(stack);
		return ;
	}
	
	if (ft_memcmp(check_a_stack, snapshot_a_stack, stack->stack_len * sizeof(int)) == 0)
		return ;
	
	mask = 0;
	while (mask <= stack->max_mask)
	{
		i = 0;
		while (i + (stack->b_len)  < stack->stack_len)
		{
			if ((stack->a_stack[0] >> mask & 1) == 0)
			{
				ft_printf("pb\n");
				push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
			}
			else
			{
				ft_printf("ra\n");
				rotate(stack->a_stack, stack->a_len);
				i++;
			}
		}
		while (stack->b_len > 0)
		{
			ft_printf("pa\n");
			push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
		}
		mask++;
	}
	return ;
}

void ready_sort(t_stack *stack)
{
	stack->a_stack = (int *)ft_calloc(stack->stack_len, sizeof(int));
	stack->b_stack = (int *)ft_calloc(stack->stack_len, sizeof(int));
	if (stack->a_stack == NULL || stack->b_stack == NULL)
		return ;
	set_ranking_stack(stack->a_stack, stack->num_stack, stack->stack_len);
	stack->tmp_max_mask = 1 << 30;
	while (!(stack->stack_len & stack->tmp_max_mask))
		stack->tmp_max_mask = stack->tmp_max_mask >> 1;
	while (stack->tmp_max_mask > 1)
	{
		stack->tmp_max_mask = stack->tmp_max_mask >> 1;
		stack->max_mask++;
	}
	stack->a_len = stack->stack_len;
	stack->b_len = stack->a_len - stack->stack_len;
	return ;
}

void set_ranking_stack(int *target_stack, int *num_stack, int stack_len)
{
	int i;
	int k;
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

