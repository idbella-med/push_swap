#include "push_swap.h"

static void	ft_rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != tail)
		tmp = tmp->next;
	
	tmp->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void    rra(t_list **stack_a)
{
    ft_rev_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_list **stack_b)
{
    ft_rev_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    ft_rev_rotate(stack_a);
    ft_rev_rotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
}

void	rev_rotate(t_list **a, t_list **b, t_list *cheap)
{
	while ((*a)->content != cheap->content && (*b)->content != cheap->target->content)
		rrr(a, b);
}