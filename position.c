#include "push_swap.h"

t_list	*get_cheap(t_list *stack)
{
	t_list		*cheap;
	long long	n;

	n = LLONG_MAX;
	while (stack)
	{
		if ((long long)stack->cost_stack < n)
		{
			cheap = stack;
			n = (long long)stack->cost_stack;
		}
		stack = stack->next;
	}
	return (cheap);
}

void	set_target_a(t_list *a, t_list *b)
{
	t_list		*target;
	t_list		*current_b;
	long long	match;

	while (a)
	{
		match = LLONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->content < a->content && current_b->content > match)
			{
				match = current_b->content;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LLONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list		*target;
	t_list		*current_a;
	long long	match;

	while (b)
	{
		match = LLONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content && current_a->content < match)
			{
				match = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LLONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}