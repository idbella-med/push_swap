#include "push_swap.h"

static void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	tail = ft_lstlast(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	ft_lstadd_back(stack, NULL);
}

void    rra(t_list **stack_a)
{
    rev_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_list **stack_b)
{
    rev_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
}