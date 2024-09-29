/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:21:52 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 16:57:24 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_restorable(char *str)
{
	int	skip;
	int	sign;
	char *copy_str;

	skip = 0;
	sign = 1;
	copy_str = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	ft_memcpy(copy_str, str, ft_strlen(str));
	if (str[0] == '+')
		skip++;
	else if (str[0] == '-')
	{
		sign = -1;
		skip++;
	}
	while (str[skip] == '0' && str[skip + 1] != '\0')
		skip++;
	if (cmp_itoa_atoi(copy_str, skip, sign) == 0)
	{
		free(copy_str);
		return (1);
	}
	else
	{
		free(copy_str);
		return (0);
	}
}

int	cmp_itoa_atoi(char *copy_str, int skip, int sign)
{
	char	*tmp;
	int		num;
	int		cmp_result;

	if (copy_str[skip] == '-' || copy_str[skip] == '+')
		return (-1);
	if (sign == -1)
	{
		copy_str[skip - 1] = '-';
		skip--;
	}
	num = ft_atoi(copy_str + skip);
	tmp = ft_itoa(num);
	cmp_result = ft_memcmp(tmp, copy_str + skip, ft_strlen(copy_str) - skip);
	free(tmp);
	return (cmp_result);
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
