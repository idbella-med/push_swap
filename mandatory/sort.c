/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:16:33 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/23 20:01:02 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_three(t_list **a)
{
	t_list	*max;

	if (!*a || !a)
		return ;
	max = find_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

static void	do_five(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	do_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static void	do_move(t_list **stack_a, int half)
{
	if (is_descending(*stack_a, half))
		rra(stack_a);
	else
		ra(stack_a);
}

static void	move_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	range;
	int	i;

	i = 0;
	if (ft_lstsize(*stack_a) > 100)
		range = 30;
	else
		range = 15;
	while (ft_lstsize(*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			do_move(stack_a, ft_lstsize(*stack_a) / 2);
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	set_index(*a, size);
	if (size <= 3)
		do_three(a);
	else if (size <= 5)
		do_five(a, b);
	else
	{
		move_to_stack_b(a, b);
		move_largest_to_a(a, b);
	}
}
