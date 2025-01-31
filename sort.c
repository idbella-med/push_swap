#include "push_swap.h"

static void	push_all_save_three(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_lstsize(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void	shift_stack(t_list **stack_a)
{
	int	low_pos;
	int	size;

	size = ft_lstsize(*stack_a);
	low_pos = get_lowest_index_position(stack_a);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			rra(stack_a);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ra(stack_a);
			low_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
void	sort(t_list **stack_a, t_list **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	do_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (is_sorted(*stack_a))
		shift_stack(stack_a);
}