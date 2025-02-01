#include "push_swap.h"

void ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

    if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void    ra(t_list **stack_a)
{
    ft_rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_list **stack_b)
{
    ft_rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
}

void	rotate(t_list **a, t_list **b, t_list *cheap)
{
	while ((*a)->content != cheap->content && (*b)->content != cheap->target->content)
		rr(a, b);
}