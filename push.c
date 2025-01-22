#include "push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *top = *stack_b;
    (*stack_b) = (*stack_b)->next;
    top->next = *stack_a;
    *stack_a = top;
    write(1, "pa\n", 3);
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *top = *stack_a;
    (*stack_a) = (*stack_a)->next;
    top->next = *stack_b;
    *stack_b = top;
    write(1, "pb\n", 3);
}