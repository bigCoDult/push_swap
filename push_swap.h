/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:21:15 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/27 15:46:50 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


//가변인자
# include <stdarg.h>
//NULL
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_etc
{
	int						n;
	unsigned int			u;
	char					*string;
	long long unsigned int	*ads;
}	t_etc;

void	binary_radix_sort(int *random_number);
int *parse(int argc, char** argv);
int *parse_single_input(char *str);
int *parse_several_input(int argc, char **str);



#endif /* PUSH_SWAP_H */