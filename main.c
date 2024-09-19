#include "push_swap.h"

int main(int argc, char** argv)
{
	int i = 0;
	char **str_stack;
	int *num_stack;
	
	str_stack = set_str_stack(argc, argv);
	// validate_str_stack(str_stack);
	num_stack = atoi_stack(str_stack);
	
	while (str_stack[i])
		free(str_stack[i++]);
	free(str_stack);
	free(num_stack);
	return (0);
}
