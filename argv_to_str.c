#include "push_swap.h"

char **set_str_stack(int argc, char** argv)
{
	char *line;
	int seperater_space;
	int line_len;
	int i;
	char **str_stack;

	line_len = 0;
	seperater_space = argc;
	i = 0;
	
	while (--seperater_space)
		line_len += ft_strlen(argv[seperater_space]);
	
	seperater_space = argc;
	line = ft_calloc(seperater_space + line_len + 1, sizeof(char));
	while (--seperater_space)
	{
		line = ft_strjoin(line, argv[++i]);
		line = ft_strjoin(line, " ");
	}
	// printf("line : %s\n", line);
	str_stack = ft_split(line, ' ');
	free(line);
	// i = 0;
	// while (str_stack[i])
	// {
	// 	printf("str_stack[%d] : %s\n", i, str_stack[i]);
	// 	i++;
	// }
	return (str_stack);
}

