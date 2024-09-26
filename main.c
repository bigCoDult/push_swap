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
		// print_str_stack(stack->str_stack, stack->stack_len);
		// print_stack(stack->num_stack, stack->stack_len);
		binary_radix_sort(stack);
		// print_stack(stack->a_stack, stack->stack_len);
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
	free(stack->a_stack);
	free(stack->b_stack);
	free(stack);
}

void print_stack(int *target_stack, int stack_len)
{
	int i;
	
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

void print_str_stack(char **str_stack, int stack_len)
{
	int i;
	
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

void print_ab(t_stack *stack)
{
	int i;
	
	i = 0;
	ft_printf("[A		B]\n");
	while (i < stack->stack_len)
	{
		ft_printf(" %d		%d\n", stack->a_stack[i], stack->b_stack[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}