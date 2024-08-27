#include "push_swap.h"

int main(int argc, char** argv)
{
	int *stack_a;
	stack_a = parse(argc, argv);
	// validate_stack(stack_a);
	binary_radix_sort(stack_a);
	return (0);
}
