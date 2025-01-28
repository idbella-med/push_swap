#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int	check_args(int ac, char **av);
void ft_free(char **args);
void sa(t_list **stack);
void sb(t_list **stack);
void ss(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
int	is_sorted(t_list *stack);

#endif