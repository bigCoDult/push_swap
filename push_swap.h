/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:21:15 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/24 20:41:14 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//가변인자
# include <stdarg.h>
//NULL
# include <stddef.h>
// 멍청함
# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	stack_len;
	char **str_stack;
	int	*num_stack;
	int *a_stack;
	int *b_stack;
	int max_mask;
}	t_stack;

void	old_binary_radix_sort(int stack_len, int *random_number);
void	binary_radix_sort(t_stack *stack);
void	set_a_stack(int *a_stack, int *num_stack, int stack_len);
void	ready_sort(t_stack *stack);




void	set_str_stack(int argc, char** argv, t_stack *stack);
int		validate_str_stack(t_stack *stack);
int		*atoi_stack(char **str_stack);
void	free_stack(t_stack *stack);
int		is_restorable(char *str);
int		is_duplicated(t_stack *stack);
void	print_stack(t_stack *stack);
int		get_stack_len(char *line);
int		is_proper_argv(int argc, char **agrv);
int		cmp_itoa_atoi(char *str);



#endif /* PUSH_SWAP_H */