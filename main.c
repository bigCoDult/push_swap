#include "push_swap.h"

int main(int argc, char** argv)
{
	char **str_stack;
	int *num_stack;
	
	str_stack = set_str_stack(argc, argv);
	validate_str_stack(str_stack);
	num_stack = atoi_stack(str_stack);
	
	
	
	
	
	
	
	ft_printf("%d", num_stack[0]);
	free_stack(str_stack, num_stack);
	return (0);
}

void free_stack(char **str_stack, int *num_stack)
{
	int i;
	
	i = 0;
	while (str_stack[i])
		free(str_stack[i++]);
	free(str_stack);
	free(num_stack);
}