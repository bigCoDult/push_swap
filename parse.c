#include "push_swap.h"

int *parse(int argc, char** argv)
{
	// argc가 1일때 에러메세지 출력 금지
	// 빈문자열은 에러처리
	// ft_atoi 사용할것
	int tmp_argc;
	tmp_argc = argc;
	if (tmp_argc == 1)
		exit(1);
	while (tmp_argc > 1)
	{
		if (ft_isspace(argv[tmp_argc--]))
		{
			ft_printf("Error\n");
			// printf("Error\n");
			exit(1);
		}
	}
	tmp_argc = argc;
	if (argc == 2)
		return (parse_single_input(argv[1]));
	else
		return (parse_several_input(argc, argv));
}

int *parse_single_input(char *str)
{
	// char **char_a = ft_split_word(str, ' ');
	char **char_a = ft_split(str, ' ');
	int *int_a;
	while (*char_a)
	{
		*int_a = ft_atoi(*char_a);
		free(*char_a);
		char_a++;
		int_a++;
	}
	free(char_a);
	return (int_a);
}

int *parse_several_input(int argc, char **str)
{
	int *int_a;
	*int_a = 1;
	return (int_a);


}