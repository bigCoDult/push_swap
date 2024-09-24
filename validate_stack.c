#include "push_swap.h"

int validate_str_stack(t_stack *stack)
{
	int i;
	i = 0;
	
	while (stack->str_stack[i])
	{
		
		if (is_restorable(stack->str_stack[i]))
			i++;
		else
		{
			ft_printf("\ninproper input\n\n");
			return (0);
		}
	}
	if (is_duplicated(stack))
	{
		ft_printf("\nduplicated input\n\n");
		return (0);
	}
	return (1);
}
// int validate_str_stack(char **str_stack)
// {
// 	int i;
// 	int k;
// 	int str_i;
// 	i = 0;
// 	k = 0;
// 	str_i = 0;
//
// 	while (str_stack[i])
// 	{
// 		if (ft_issign(str_stack[i][k]))
// 			k++;
// 		while (ft_isdigit(str_stack[i][k]))
// 			k++;
// 		if (str_stack[i][k] == '\0')
// 		{
// 			i++;
// 			k = 0;
// 		}
// 		else
// 		{
// 			ft_printf("\nwrong input\n\n");
// 			while (str_stack[str_i])
// 				free(str_stack[str_i++]);
// 			free(str_stack);
// 			exit(0);
// 		}
// 	}
// 	return (1);
// }

// int ft_issign(char c)
// {
// 	if (c == '-' || c == '+')
// 		return (1);
// 	return (0);
// }

// int validate_inteager(char *str)
// {
// 	int i;
// 	i = 0;
// 	if (ft_issign(str[i]))
// 		i++;
// 	if (ft_strlen(str) > ft_strlen("2147483647"))
// 		retunn (0);
// }

int is_restorable(char *str)
{
	char *tmp_str;
	
	tmp_str = (char *)ft_calloc(ft_strlen(str), sizeof(char));
	tmp_str = ft_itoa(ft_atoi(str));
	if (ft_memcmp(tmp_str, str, ft_strlen(str)))
	{
		free(tmp_str);
		return (0);
	}
	else
	{
		free(tmp_str);
		return (1);
	}
}

int is_duplicated(t_stack *stack)
{
	int i;
	int k;
	int len;
	
	i = 0;
	while (stack->str_stack[i])
	{
		k = i + 1;
		while (k < stack->stack_len)
		{
			if (ft_strlen(stack->str_stack[i]) < ft_strlen(stack->str_stack[k]))
				len = ft_strlen(stack->str_stack[i]);
			else
				len = ft_strlen(stack->str_stack[k]);
			
			if (ft_memcmp(stack->str_stack[i], stack->str_stack[k], len) == 0)
				return (1);
			else
				k++;
		}
		i++;
	}
	return (0);
}
