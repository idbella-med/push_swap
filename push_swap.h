#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include <limits.h>
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
void	assign_index(t_list *stack_a, int stack_size);
void	do_three(t_list **stack);
void	sort(t_list **stack_a, t_list **stack_b);
void	get_cost(t_list **stack_a, t_list **stack_b);
void	do_cheapest_move(t_list **stack_a, t_list **stack_b);
void	do_move(t_list **a, t_list **b, int cost_a, int cost_b);
int	get_lowest_index_position(t_list **stack);
void	get_target_position(t_list **a, t_list **b);

#endif