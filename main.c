#include "push_swap.h"

int main(int argc, char** argv)
{
	t_stack *stack;
	
	if (!is_proper_argv(argc, argv))
		return (1);
	if (argc == 2)
		return (0);
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (1);
	set_str_stack(argc, argv, stack);
	if (validate_str_stack(stack))
		binary_radix_sort(stack);
	free_stack(stack);
	return (0);
}

void free_stack(t_stack *stack)
{
	int i;
	
	i = 0;
	if (stack->num_stack != NULL)
		free(stack->num_stack);
	while (i < stack->stack_len)
		free(stack->str_stack[i++]);
	free(stack->str_stack);
	free(stack->a_stack);
	free(stack->b_stack);
	free(stack);
}

