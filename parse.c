#include "push_swap.h"

int *parse(int argc, char** argv)
{
	if (argc == 1)
		return (NULL);
	if (argc == 2)
		return (parse_str_input(argv[1]));
	else
		return (parse_variatic_input(argv));
}

int *parse_str_input(char *str)
{
	int *stack_a;
	stack_a = ft_split(str, ' ');
}

int *parse_variatic_input(char str, ...)
{
	va_list	ap;
	va_start(ap, str);
	va_end(ap);
}