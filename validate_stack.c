#include "push_swap.h"

int validate_str_stack(char **str_stack)
{
	int i;
	int k;
	i = 0;
	k = 0;
	
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
			ft_printf("\nwrong input\n");
			return (0);
		}
	}
	// int check = 5;
	// ft_printf("str_stack[0][%d] : %s\n", check, str_stack[0][check]);
	return (1);
}

int ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}