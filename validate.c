#include "push_swap.h"

int validate_stack(int *a_stack)
{
	is_duplicate(a_stack);

}

int is_duplicate(int *a_stack)
{
	
	int n;
	int *tmp_a_stack;
	tmp_a_stack = a_stack;
	n = *tmp_a_stack;
	while (tmp_a_stack++)
	{
		if (n == *tmp_a_stack++)
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}