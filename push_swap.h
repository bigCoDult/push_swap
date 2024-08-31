/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:21:15 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/31 10:39:41 by sanbaek          ###   ########.fr       */
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

void	binary_radix_sort(int stack_size, int *random_number);
int *parse(int argc, char** argv);
int *parse_single_input(char *str);
int *parse_several_input(int argc, char **argv);



#endif /* PUSH_SWAP_H */