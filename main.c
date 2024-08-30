#include "push_swap.h"
#include "./libft/libft.h"


int main(int argc, char** argv)
{
	int *stack_a;
	stack_a = parse(argc, argv);
	// validate_stack(stack_a);
	binary_radix_sort(stack_a);
	ft_printf("stack_a[0] = %d\n", stack_a[0]);
	ft_printf("stack_a[1] = %d\n", stack_a[1]);
	ft_printf("stack_a[2] = %d\n", stack_a[2]);
	// ft_printf("stack_a[3] = %d\n", stack_a[3]);
	free(stack_a);
	return (0);
}
