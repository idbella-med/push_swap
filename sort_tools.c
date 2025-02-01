#include "push_swap.h"


void	bring_to_top(t_list **stack, t_list *cheap, char c)
{
	while ((*stack)->content != cheap->content)
	{
		if (c == 'a')
		{
			if (cheap->above)
				ra(stack);
			else
			{
				rra(stack);
			}
		}
		else if (c == 'b')
		{
			if (cheap->above)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	bring_min_top(t_list **a)
{
	t_list	*min;

	min = find_min(*a);
	while (*a != min)
	{
		if (min->above)
			ra(a);
		else
			rra(a);
	}
}

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = get_cheap(*a);
	if (cheap->above && cheap->target->above)
		rotate(a, b, cheap);
	else if (!(cheap->above) && !(cheap->target->above))
		rev_rotate(a, b, cheap);
	set_index(*a);
	set_index(*b);
	bring_to_top(a, cheap, 'a');
	bring_to_top(b, cheap->target, 'b');
	pb(a, b);
	cost_calc(*a, *b);
	cheap = get_cheap(*a);
}

void	push_to_a(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = get_cheap(*b);
	if (cheap->above && cheap->target->above)
		rotate(b, a, cheap);
	else if (!(cheap->above) && !(cheap->target->above))
		rev_rotate(b, a, cheap);
	set_index(*a);
	set_index(*b);
	bring_to_top(b, cheap, 'b');
	bring_to_top(a, cheap->target, 'a');
	pa(a, b);
}
