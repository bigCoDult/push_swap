#include "push_swap.h"

int *binary_radix_sort(int *random_number)
{
	int a_stack[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int b_stack[10];
	int a_len;
	int b_len;
	int mask;
	int bit_range;
	a_len = 10;
	b_len = 0;
	mask = 1;
	bit_range = 0;
	
	while (a_len--)
	{
		if (*a_stack & (mask << bit_range++))
			ft_printf("pb\n");
		else
			ft_printf("ra\n");
	}
	
	
	return (a_stack);
}

int *bubble_sort(void)
{
	int a_stack[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int b_stack[10];
	
	
	
	
	
	
	
	
	
	
	return (a_stack);
}

/*
	sa (swap a)
		스택 a의 맨 위에 있는 첫 번째 두 개의 요소를 스왑합니다.
	sb (swap b)
		스택 b의 맨 위에 있는 첫 번째 두 개의 요소를 스왑합니다.
	ss
		sa와 sb를 동시에.
	
	pa (push a)
		b의 맨 위에 있는 첫 번째 원소를 취하여 a의 맨 위에 놓는다.
	pb(push b)
		a의 맨 위에 있는 첫 번째 요소를 취하여 b의 맨 위에 놓습니다.
	
	ra(rotate a)
		스택 a의 모든 원소를 1씩 이동시킨다.
	첫 번째 요소가 마지막 요소가 됩니다.
	rb(rotate b)
		스택 b의 모든 요소를 1씩 위로 이동시킨다.
		첫 번째 요소가 마지막 요소가 됩니다.
	rr
		ra와 rb를 동시에.
	
	rra(reverse rotate a)
		스택 a의 모든 요소를 1씩 아래로 이동합니다.
		마지막 요소가 첫 번째 요소가 됩니다.
	rrb(reverse rotate b)
		스택 b의 모든 요소를 1만큼 아래로 이동합니다.
		마지막 요소가 첫 번째 요소가 됩니다.
	rrr
		rra와 rrb가 동시에 발생합니다.
*/

void	bubble_sort(int *tab, int size)
{
	int	tmp;
	int	i;
	int	k;

	i = 0;
	while (i < size - 1)
	{
		k = i + 1;
		while (k < size)
		{
			if (tab[i] > tab[k])
			{
				tmp = tab[i];
				tab[i] = tab[k];
				tab[k] = tmp;
			}
			k++;
		}
		i++;
	}
}

