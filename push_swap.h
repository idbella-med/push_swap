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
void	set_index(t_list *stack);
void	do_three(t_list **stack);
void	sort_high(t_list **a, t_list **b);
void	sort_low(t_list **a, t_list **b);
void	set_target_b(t_list *a, t_list *b);
void	set_target_a(t_list *a, t_list *b);
void	force_exit(void);
void	from_b_to_a(t_list **a, t_list **b);
void	bring_to_top(t_list **stack, t_list *cheap, char c);
void	bring_min_top(t_list **a);
void	push_to_b(t_list **a, t_list **b);
void	push_to_a(t_list **a, t_list **b);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);
void	cost_calc(t_list *a, t_list *b);
t_list	*get_cheap(t_list *stack);
void	rotate(t_list **a, t_list **b, t_list *cheap);
void	rev_rotate(t_list **a, t_list **b, t_list *cheap);
#endif