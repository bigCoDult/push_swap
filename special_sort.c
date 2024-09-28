#include "push_swap.h"

void special_sort(t_stack *stack)
{
	if (stack->stack_len == 2)
	{
		if (stack->a_stack[0] > stack->a_stack[1])
		{
			ft_printf("sa\n");
			swap(stack->a_stack);
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

void middle_sort(t_stack *stack)
{
	pb_small(stack, 1);
	pb_small(stack, 2);
	pb_small(stack, 3);
	if (stack->a_len == 2)
	{
		if (stack->a_stack[0] > stack->a_stack[1])
		{
			ft_printf("sa\n");
			swap(stack->a_stack);
		}
	}
	else if (stack->a_len == 3)
		mini_sort(stack);
	ft_printf("pa\npa\npa\n");
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	return ;
}

void mini_sort(t_stack *stack)
{
	int biggest;

	set_biggest(stack, &biggest);
	if (biggest == stack->a_stack[0])
	{
		ft_printf("ra\n");
		rotate(stack->a_stack, stack->a_len);
		if (stack->a_stack[1] > stack->a_stack[2])
		{
			ft_printf("sa\n");
			swap(stack->a_stack);
		}
	}
	else if (biggest == stack->a_stack[1])
	{
		if (stack->a_stack[0] > stack->a_stack[2])
		{
			ft_printf("rra\n");
			reverse_rotate(stack->a_stack, stack->a_len);
		}
		else if (stack->a_stack[0] < stack->a_stack[2])
		{
			ft_printf("sa\nra\n");
			swap(stack->a_stack);
			rotate(stack->a_stack, stack->a_len);
		}
	}
	else if (biggest == stack->a_stack[2])
	{
		if (stack->a_stack[0] > stack->a_stack[1])
		{
			ft_printf("sa\n");
			swap(stack->a_stack);
		}
	}
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
		{
			ft_printf("ra\n");
			rotate(stack->a_stack, stack->a_len);
		}
	}
	else
	{
		while (rra_far-- > 0)
		{
			ft_printf("rra\n");
			reverse_rotate(stack->a_stack, stack->a_len);
		}
	}
	ft_printf("pb\n");
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	return ;
}

void set_biggest(t_stack *stack, int *biggest)
{
	int i;

	i = 0;
	*biggest = 0;
	while (i < stack->a_len)
	{
		if (stack->a_stack[i] > *biggest)
			*biggest = stack->a_stack[i];
		i++;
	}
	return ;
}
