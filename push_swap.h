/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:21:15 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/27 15:53:59 by sanbaek          ###   ########.fr       */
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
	int tmp_max_mask;
	int max_mask;
	int a_len;
	int b_len;
}	t_stack;

void	binary_radix_sort(t_stack *stack);
void	mini_sort(t_stack *stack);
void	middle_sort(t_stack *stack);
void	special_sort(t_stack *stack);
void	ready_sort(t_stack *stack);
void	set_ranking_stack(int *target_stack, int *num_stack, int stack_len);

void push(int *dest_stack, int *src_stack, int *dest_len, int *src_len);
void swap(int *target_stack);
void rotate(int *target_stack, int stack_len);
void reverse_rotate(int *target_stack, int stack_len);




void print_stack(int *target_stack, int stack_len);
void print_str_stack(char **str_stack, int stack_len);
void print_ab(t_stack *stack);
void print_to_find_error(t_stack *stack);



void	set_str_stack(int argc, char** argv, t_stack *stack);
int		validate_str_stack(t_stack *stack);
int		*atoi_stack(char **str_stack);
void	free_stack(t_stack *stack);
int		is_restorable(char *str);
int		is_duplicated(t_stack *stack);
int		get_stack_len(char *line);
int		is_proper_argv(int argc, char **agrv);
int		cmp_itoa_atoi(char *str);



#endif /* PUSH_SWAP_H */