#include "push_swap.h"

void print_to_find_error(t_stack *stack)
{
	ft_printf("\n");
	ft_printf("original\n\n");
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);

	ft_printf("\n");
	ft_printf("\n\npush pb\n\n\n");
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->b_stack, stack->a_stack, &(stack->b_len), &(stack->a_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	
	
	ft_printf("\n\npush pa\n\n\n");
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	push(stack->a_stack, stack->b_stack, &(stack->a_len), &(stack->b_len));
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);

	ft_printf("\n\nra\n\n\n");
	rotate(stack->a_stack, stack->a_len);
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	rotate(stack->a_stack, stack->a_len);
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	rotate(stack->a_stack, stack->a_len);
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	rotate(stack->a_stack, stack->a_len);
	ft_printf("a_len : %d\nb_len : %d\n", stack->a_len, stack->b_len);
	print_ab(stack);
	
	return ;
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