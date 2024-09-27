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