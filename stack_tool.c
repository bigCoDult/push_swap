#include "push_swap.h"

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
