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
		if (ft_issign(str_stack[i][k]))
			k++;
		while (ft_isdigit(str_stack[i][k]))
			k++;
		if (str_stack[i][k] == '\0')
		{
			i++;
			k = 0;
		}
		else
		{
			ft_printf("\nwrong input\n\n");
			while (str_stack[str_i])
				free(str_stack[str_i++]);
			free(str_stack);
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

int validate_inteager(char *str)
{
	int i;
	i = 0;
	if (ft_issign(str[i]))
		i++;
	if (ft_strlen(str) > ft_strlen("2147483647"))
		retunn (0);
}