#include "push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *top = *stack_b;
    (*stack_b) = (*stack_b)->next;
    top->next = *stack_a;
    *stack_a = top;
    ft_putstr_fd("pa\n", 1);
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *top;

    if(!*stack_a)
        return ;
    top = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = top;
    ft_putstr_fd("pb\n", 1);
}