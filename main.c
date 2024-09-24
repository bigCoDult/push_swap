#include "push_swap.h"

int main(int argc, char** argv)
{
	t_stack *stack;
	
	if (!is_proper_argv(argc, argv))
		return (1);
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	
	if (stack == NULL)
		return (1);
	
	set_str_stack(argc, argv, stack);
	if (validate_str_stack(stack))
	{
		stack->num_stack = atoi_stack(stack->str_stack);
		print_stack(stack);
	}
	
	free_stack(stack);
	// write(2, "Error\n", 6);
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
	free(stack);
}

void print_stack(t_stack *stack)
{
	int i;
	int k;
	
	i = 0;
	k = 0;
	
	ft_printf("stack_len : %d\n", stack->stack_len);
	ft_printf("\n");
	while (stack->str_stack[i])
	{
		ft_printf("str[%d] : %s\n", i, stack->str_stack[i]);
		i++;
	}
	
	while (k < stack->stack_len)
	{
		ft_printf("num[%d] : %d\n", k, stack->num_stack[k]);
		k++;
	}
	ft_printf("\n");
}