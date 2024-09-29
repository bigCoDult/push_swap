#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate(stack->a_st, stack->a_l);
	ft_printf("ra\n");
	return ;
}

void	sa(t_stack *stack)
{
	swap(stack->a_st);
	ft_printf("sa\n");
	return ;
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack->a_st, stack->a_l);
	ft_printf("rra\n");
	return ;
}
