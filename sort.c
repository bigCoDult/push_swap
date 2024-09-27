#include "push_swap.h"

// 	push 함수 swap 함수 만들고
// 	memset memmove로 배열 세그먼트 순서 바꾸기
//
// 	숫자를 미는거지 마스킹을 미는게 아님
// 		마스킹을 늘릴게 아니고 숫자를 작아지게 >>로 밀기
//
// 	pb 판단조건에 0, 1이 반대임
//
// 	구조체 무조건 쓸것
// 		넘길 변수가 너무 많다
// 		함수 나누면 어차피 필요하다









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
	
	if (stack->stack_len <= 5)
	{
		greedy_sort(stack);
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

void push(int *dest_stack, int *src_stack, int *dest_len, int *src_len)
{
	if (*src_len == 0)
	{
		ft_printf("inproper push\n");
		return ;
	}
	ft_memmove(dest_stack + 1, dest_stack, (*dest_len) * sizeof(int));
	dest_stack[0] = src_stack[0];
	(*dest_len)++;
	ft_memmove(src_stack, src_stack + 1, (*src_len + *dest_len - 2) * sizeof(int));
	src_stack[*src_len - 1] = 0;
	(*src_len)--;
}

void rotate(int *target_stack, int stack_len)
{
	int tmp;
	
	tmp = target_stack[0];
	ft_memmove(target_stack, target_stack + 1, (stack_len - 1) * sizeof(int));
	target_stack[stack_len - 1] = tmp;
}

void reverse_rotate(int *target_stack, int stack_len)
{
	int tmp;
	
	tmp = target_stack[stack_len - 1];
	ft_memmove(target_stack + 1, target_stack, stack_len - 1);
	target_stack[0] = tmp;
}

void swap(int *target_stack)
{
	int tmp;
	
	tmp = target_stack[0];
	target_stack[0] = target_stack[1];
	target_stack[1] = tmp;
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

void mini_sort(t_stack *stack)
{
	return ;
}




/*
	sa (swap a)
		스택 a의 맨 위에 있는 첫 번째 두 개의 요소를 스왑합니다.
	sb (swap b)
		스택 b의 맨 위에 있는 첫 번째 두 개의 요소를 스왑합니다.
	ss
		sa와 sb를 동시에.
	
	pa (push a)
		b의 맨 위에 있는 첫 번째 원소를 취하여 a의 맨 위에 놓는다.
	pb(push b)
		a의 맨 위에 있는 첫 번째 요소를 취하여 b의 맨 위에 놓습니다.
	
	ra(rotate a)
		스택 a의 모든 원소를 1씩 이동시킨다.
		첫 번째 요소가 마지막 요소가 됩니다.
	rb(rotate b)
		스택 b의 모든 요소를 1씩 위로 이동시킨다.
		첫 번째 요소가 마지막 요소가 됩니다.
	rr
		ra와 rb를 동시에.
	
	rra(reverse rotate a)
		스택 a의 모든 요소를 1씩 아래로 이동합니다.
		마지막 요소가 첫 번째 요소가 됩니다.
	rrb(reverse rotate b)
		스택 b의 모든 요소를 1만큼 아래로 이동합니다.
		마지막 요소가 첫 번째 요소가 됩니다.
	rrr
		rra와 rrb가 동시에 발생합니다.
*/
