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

void special_sort(t_stack *stack)
{
	if (stack->stack_len == 2)
	{
		if (stack->a_stack[0] > stack->a_stack[1])
			ft_printf("sa\n");
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

void middle_sort(t_stack *stack)
{
	pb_small(stack, 1);
	pb_small(stack, 2);
	pb_small(stack, 3);
	if (stack->a_len == 1)
		;
	else if (stack->a_len == 2)
	{
		if (stack->a_stack[0] > stack->a_stack[1])
			ft_printf("sa\n");
	}
	else if (stack->a_len == 3)
		mini_sort(stack);
	ft_printf("pa\npa\npa\n");
	return ;
}

void pb_small(t_stack *stack, int k)
{
	int ra_far;
	int rra_far;
	int i;

	i = 0;
	ra_far = i;
	rra_far = stack->a_len - i;
	while (stack->a_stack[i] != k)
		i++;
	if (ra_far < rra_far)
	{
		while (ra_far-- > 0)
			ft_printf("ra\n");
	}
	else
	{
		while (rra_far-- > 0)
			ft_printf("rra\n");
	}
	ft_printf("pb\n");
	return ;
}


void mini_sort(t_stack *stack)
{
	int i;
	int biggest;

	biggest = 0;
	set_biggest(stack, &biggest);
	if (biggest == stack->a_stack[0])
	{
		ft_printf("ra\n");
		if (stack->a_stack[1] > stack->a_stack[2])
			ft_printf("sa\n");
	}
	else if (biggest == stack->a_stack[1])
	{
		if (stack->a_stack[0] > stack->a_stack[2])
			ft_printf("rra\n");
		else if (stack->a_stack[0] < stack->a_stack[2])
			ft_printf("sa\nra\n");
	}
	else if (biggest == stack->a_stack[2])
	{
		if (stack->a_stack[0] > stack->a_stack[1])
			ft_printf("sa\n");
	}
	return ;
}

void set_biggest(t_stack *stack, int *biggest)
{
	int i;

	i = 0;
	while (i < stack->a_len)
	{
		if (stack->a_stack[i] > *biggest)
			*biggest = stack->a_stack[i];
		i++;
	}
	return ;
}