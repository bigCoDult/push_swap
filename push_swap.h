/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:21:15 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/29 10:58:53 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int		stack_len;
	char	**str_stack;
	int		*num_stack;
	int		*a_st;
	int		*b_st;
	int		tmp_max_mask;
	int		max_mask;
	int		a_l;
	int		b_l;
}	t_stack;

typedef struct s_rotate_far
{
	int	ra_far;
	int	rra_far;
}	t_rotate_far;

void	binary_radix_sort(t_stack *stack);
void	do_radix_sort(t_stack *stack, int *mask, int *i);
int		is_already_sorted(t_stack *stack, int *mask, int *i);
void	sort_sh(t_stack *stack, int *snap_a_2, int *mask, int *i);
void	ready_sort(t_stack *stack);
void	set_ranking_stack(int *target_stack, int *num_stack, int stack_len);
void	special_sort(t_stack *stack);
void	middle_sort(t_stack *stack);
void	pb_small(t_stack *stack, int k);
void	mini_sort(t_stack *stack);
void	set_biggest(t_stack *stack, int *biggest);
void	push(int *dest_stack, int *src_stack, int *dest_len, int *src_len);
void	swap(int *target_stack);
void	rotate(int *target_stack, int target_len);
void	reverse_rotate(int *target_stack, int target_len);
void	ra(t_stack *stack);
void	sa(t_stack *stack);
void	rra(t_stack *stack);
void	print_stack(int *target_stack, int stack_len);
void	print_str_stack(char **str_stack, int stack_len);
void	print_ab(t_stack *stack);
void	print_to_find_error(t_stack *stack);
void	set_str_stack(int argc, char **argv, t_stack *stack);
void	split_str_stack(t_stack *stack, char *line);
int		validate_str_stack(t_stack *stack);
int		*atoi_stack(char **str_stack);
void	free_stack(t_stack *stack);
int		is_restorable(char *str);
int		is_duplicated(t_stack *stack);
int		get_stack_len(char *line);
int		is_proper_argv(int argc, char **argv);
void	set_check_empty(char **argv, int *i, int *k, int *check_empty);
int		cmp_itoa_atoi(char *str);

#endif /* PUSH_SWAP_H */