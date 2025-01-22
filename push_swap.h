#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

void sa(t_list **stack);
void sb(t_list **stack);
void ss(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);

#endif