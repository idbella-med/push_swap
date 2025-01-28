#include "push_swap.h"

static void   ft_swap(t_list **stack)
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
    ft_putstr_fd("sa\n", 1);
}

void sb(t_list **stack)
{
    ft_swap(stack);
    ft_putstr_fd("sb\n", 1);
}

void ss(t_list **stack_a, t_list **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    ft_putstr_fd("ss\n", 1);
}