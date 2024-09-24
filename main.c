#include "push_swap.h"

int main(int argc, char** argv)
{
	t_stack *stack;
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (1);
	set_str_stack(argc, argv, stack);
	if (validate_str_stack(stack))
		stack->num_stack = atoi_stack(stack->str_stack);

	// ft_printf("just for not unused : %d\n", stack->num_stack[0]);
	// ft_printf("\n	 atoi : %d\n", atoi(" 001"));
	// ft_printf("ft_atoi : %d\n", atoi(" 001"));

	// int a = -+-1;
	// int b = +-+3;
	// int c = a + b;
	// ft_printf("\nc = a + b : %d\n", c);
	free_stack(stack);
	return (0);
}

void free_stack(t_stack *stack)
{
	int i;
	
	i = 0;
	if (validate_str_stack(stack))
		free(stack->num_stack);
	while (stack->str_stack[i])
		free(stack->str_stack[i++]);
	free(stack->str_stack);
	free(stack);
}
