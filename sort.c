#include "push_swap.h"

void	binary_radix_sort(int stack_len, int *random_number)
{
	int a_len;
	int b_len;
	int mask;
	int max_mask;
	int biggest_num;
	int k;

	a_len = stack_len;
	b_len = 0;
	mask = 1;
	max_mask = 1 << 30;
	biggest_num = random_number[0];
	k = 1;
	
	while (k < stack_len)
	{
		if (biggest_num < random_number[k])
			biggest_num = random_number[k];
		k++;
	}
	while (!(biggest_num & max_mask))
		max_mask = max_mask >> 1;
	
	// ft_printf("max_mask : %d\n", max_mask);
	
	while (mask <= max_mask)
	{
		a_len = stack_len;
		while (a_len)
		{
			if (*random_number & (mask))
			{
				ft_printf("pb\n");
				b_len++;
			}
			else
				ft_printf("ra\n");
			a_len--;
		}
		while (b_len)
		{
			ft_printf("pa\n");
			b_len--;
		}
		mask = mask << 1;
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
