#include "push_swap.h"

void	binary_radix_sort(int *random_number)
{
	int a_len;
	int b_len;
	int mask;
	int bit_range;
	a_len = 10;
	b_len = 0;
	mask = 1;
	bit_range = 0;
	
	while (bit_range < 32)
	{
		a_len = 10;
		while (a_len)
		{
			if (*random_number & (mask << bit_range))
			{
				// ft_printf("pb\n");
				printf("pb\n");
				b_len++;
			}
			else
				// ft_printf("ra\n");
				printf("ra\n");
			a_len--;
		}
		while (b_len)
		{
			// ft_printf("pa\n");
			printf("pa\n");
			b_len--;
		}
		bit_range++;
	}
	return ;
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
