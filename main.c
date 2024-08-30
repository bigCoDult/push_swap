#include "push_swap.h"


int main(int argc, char** argv)
{
	int *stack_a;
	stack_a = parse(argc, argv);
	// validate_stack(stack_a);
	binary_radix_sort(stack_a);
	int i = 0;
	while (i < argc - 1)
	{
		ft_printf("stack_a[%d] : %d\n", i, stack_a[i]);
		i++;
	}
	free(stack_a);
	return (0);
}
