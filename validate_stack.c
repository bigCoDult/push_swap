#include "push_swap.h"

int validate_str_stack(char **str_stack)
{
	int i;
	int k;
	int str_i;
	i = 0;
	k = 0;
	str_i = 0;
	
	while (str_stack[i])
	{
		if (ft_issign(str_stack[i][k]) || ft_isdigit(str_stack[i][k]))
			k++;
		else if (str_stack[i][k] == '\0')
		{
			i++;
			k = 0;
		}
		else
		{
			ft_printf("\n");
			ft_printf("wrong input\n");
			while (str_stack[str_i])
				free(str_stack[str_i++]);
			free(str_stack);
			ft_printf("\n");
			exit(0);
		}
	}
	return (1);
}

int ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}