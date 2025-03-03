/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:59 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/26 10:02:36 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push(t_list **stack1, t_list **stack2)
{
	t_list	*top;

	top = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = top;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b || !stack_b)
		return ;
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !stack_a)
		return ;
	push(stack_a, stack_b);
}
