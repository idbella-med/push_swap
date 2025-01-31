/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:09:18 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/30 17:48:37 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/* get_cost:
*	Calculates the cost of moving each element of stack B into the correct
*	position in stack A.
*	Two costs are calculated:
*		cost_b represents the cost of getting the element to the top of the B stack
*		cost_a represents the cost of getting to the right position in stack A.
*	If the element is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive. 
*/
void	get_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_lstsize(tmp_a);
	size_b = ft_lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_stack_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_stack_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_stack_a = tmp_b->target_position;
		if (tmp_b->target_position > size_a / 2)
			tmp_b->cost_stack_a= (size_a - tmp_b->target_position) * -1;
		tmp_b = tmp_b->next;
	}
}

/* do_cheapest_move:
*	Finds the element in stack B with the cheapest cost to move to stack A
*	and moves it to the correct position in stack A.
*/
void	do_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_stack_a) + nb_abs(tmp->cost_stack_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_stack_b) + nb_abs(tmp->cost_stack_a);
			cost_a = tmp->cost_stack_a;
			cost_b = tmp->cost_stack_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}