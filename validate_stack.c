/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:21:52 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 12:48:08 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_restorable(char *str)
{
	int	skip;
	int	sign;

	skip = 0;
	sign = 1;
	if (str[0] == '+')
		skip++;
	else if (str[0] == '-')
	{
		sign = -1;
		skip++;
	}
	while (str[skip] == '0' && str[skip + 1] != '\0')
		skip++;
	if (cmp_itoa_atoi(str + skip, sign) == 0)
		return (1);
	else
		return (0);
}

int	cmp_itoa_atoi(char *str, int sign)
{
	char	*tmp_str;
	int		num;

	num = ft_atoi(str);
	if (num < 0)
		return (-1);
	num *= sign;
	tmp_str = ft_itoa(num);
	if (ft_memcmp(tmp_str, str, ft_strlen(str)) != 0)
	{
		free(tmp_str);
		return (0);
	}
	else
	{
		free(tmp_str);
		return (-1);
	}
}

int	is_duplicated(t_stack *stack)
{
	int	i;
	int	k;

	i = 0;
	while (i < stack->stack_len - 1)
	{
		k = i + 1;
		while (k < stack->stack_len)
		{
			if (stack->num_stack[i] == stack->num_stack[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	is_proper_argv(int argc, char **argv)
{
	int	i;
	int	k;
	int	check_empty;

	i = 0;
	k = 0;
	if (argc == 1)
		return (0);
	while (++i < argc)
	{
		check_empty = 0;
		k = 0;
		set_check_empty(argv, &i, &k, &check_empty);
		if (check_empty == 0)
		{
			write(2, "Error\n: empty argv\n", 19);
			return (0);
		}
	}
	return (1);
}

void	set_check_empty(char **argv, int *i, int *k, int *check_empty)
{
	while (argv[(*i)][(*k)] != '\0')
	{
		if (argv[(*i)][(*k)] == ' ')
			(*k)++;
		else
		{
			(*check_empty) = 1;
			break ;
		}
	}
	return ;
}
