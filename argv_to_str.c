#include "push_swap.h"

void set_str_stack(int argc, char** argv, t_stack *stack)
{
	char *line;
	int seperater_space;
	int line_len;
	int i;
	char **str_stack;
	char *tmp_line;

	line_len = 0;
	seperater_space = argc;
	i = 0;
	
	while (--seperater_space)
		line_len += ft_strlen(argv[seperater_space]);
	
	seperater_space = argc;
	line = ft_calloc(seperater_space + line_len + 1, sizeof(char));
	while (--seperater_space)
	{
		tmp_line = line;
		line = ft_strjoin(line, argv[++i]);
		free(tmp_line);
		tmp_line = line;
		line = ft_strjoin(line, " ");
		free(tmp_line);
	}
	str_stack = ft_split(line, ' ');
	free(line);
	stack->str_stack = str_stack;
	stack->stack_len = i;
	return ;
}


int *atoi_stack(char **str_stack)
{
	int i;
	int	stack_len;
	int *num_stack;
	
	i = 0;
	stack_len = 0;
	while (str_stack[stack_len])
		stack_len++;
	num_stack = (int *)ft_calloc(stack_len, sizeof(int));
	while (str_stack[i])
	{
		num_stack[i] = ft_atoi(str_stack[i]);
		i++;
	}
	return (num_stack);
}