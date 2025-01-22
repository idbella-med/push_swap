#include "push_swap.h"

void    ft_swap(t_list **stack)
{
    t_list *first = *stack;
    t_list *second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void sa(t_list **stack)
{
    ft_swap(stack);
    write (1, "sa\n", 3);
}

void sb(t_list **stack)
{
    ft_swap(stack);
    write (1, "sb\n", 3);
}

void ss(t_list **stack_a, t_list **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    write (1, "sb\n", 3);
}