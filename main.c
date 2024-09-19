#include "push_swap.h"


int main(int argc, char** argv)
{
	char **str_stack;
	int *stack_a;
	
	str_stack = **set_str_stack(argc, argv);
	validate_str_stack(str_stack);
	// int i = 0;
	// while (i < argc - 1)
	// {
	// 	ft_printf("stack_a[%d] : %d\n", i, stack_a[i]);
	// 	i++;
	// }
	// validate_stack(stack_a);
	// binary_radix_sort(argc - 1, stack_a);
	// free(stack_a);
	return (0);
}
