#include "push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*max;
	int		n;

	n = stack->content;
	max = stack;
	while (stack)
	{
		if (stack->content > n)
		{
			n = stack->content;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_list	*find_min(t_list *stack)
{
	t_list	*min;
	int		n;

	n = stack->content;
	min = stack;
	while (stack)
	{
		if (stack->content < n)
		{
			n = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	cost_calc(t_list *a, t_list *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_lstsize(a);
	b_len = ft_lstsize(b);
	while (a)
	{
		a->cost_stack = a->index;
		if (!(a->above))
			a->cost_stack = a_len - (a->index);
		if (a->target->above)
			a->cost_stack += a->target->index;
		else
			a->cost_stack += b_len - (a->target->index);
		a = a->next;
	}
}

void	set_index(t_list *stack)
{
	int	i;
	int	mid;

	if (!stack)
		return ;
	i = 0;
	mid = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->above = 1;
		else
			stack->above = 0;
		stack = stack->next;
		i++;
	}
}