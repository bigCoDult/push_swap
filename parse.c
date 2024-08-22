#include "push_swap.h"

int *parse(int argc, char** argv)
{
	//argc가 1일때 에러메세지 출력 금지
	if (argc == 1)
		exit(0);
	if (argc == 2)
		return (parse_str_input(argv[1]));
	else
		return (parse_char_pointer_input(argv));
}

int *parse_str_input(char *str)
{
	int *stack_a;
	stack_a = ft_split(str, ' ');
}

int *parse_char_pointer_input(char str, ...)
{
	va_list	ap;
	va_start(ap, str);
	va_end(ap);
}