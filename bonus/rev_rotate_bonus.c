/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:52 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/26 10:02:45 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tail = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != tail && tmp->next)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_list **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_rev_rotate(stack_a);
}

void	rrb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rev_rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}
