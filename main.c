#include "push_swap.h"

int main(int argc, char** argv)
{
	int *stack_a;
	int *stack_b;
	char **command;
	validate_input(argc, argv);
	stack_a = parse(argc, argv);
	stack_a = convert_binary_radix(stack_a);
	command = radix_sort(stack_a, stack_b);
	print_command(command);
	return (0);
}
