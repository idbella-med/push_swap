#include "push_swap.h"

void ft_free(char **args)
{
    int i = 0;
    while(args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	do_three(t_list **stack)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->content > (*stack)->next->content && (*stack)->next->content <
		(*stack)->next->next->content &&
		(*stack)->content < (*stack)->next->next->content)
		sa(stack);
	else if ((*stack)->content < (*stack)->next->content && (*stack)->next->content >
		(*stack)->next->next->content &&
		(*stack)->content < (*stack)->next->next->content)
	{
			rra(stack);
			sa(stack);
	}
	else if ((*stack)->content > (*stack)->next->content && (*stack)->content >
		(*stack)->next->next->content &&
		(*stack)->next->content < (*stack)->next->next->content)
		ra(stack);
	else if ((*stack)->content < (*stack)->next->content && (*stack)->content >
		(*stack)->next->next->content &&
		(*stack)->next->content > (*stack)->next->next->content)
		rra(stack);
	else if ((*stack)->content > (*stack)->next->content && (*stack)->next->content >
		(*stack)->next->next->content)
	{
			ra(stack);
			sa(stack);
	}
}

static void	push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	if(size == 2)
		sa(stack_a);
	else if (size == 3)
		do_three(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

char **creat_stack(char **av)
{
	int i = 2;
	char *all;
	char *tmp;
	char **list;
	all = ft_strdup(av[1]);
	while(av[i])
	{
		tmp = ft_strjoin(all, " ");
		free(all);
		all = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	list = ft_split(all, ' ');
	free(all);
	return (list);
}

t_list *list_stack(char **list)
{
    t_list *stack_a;
    t_list *new;
    int i = 0;

    stack_a = malloc(sizeof(t_list *));
    if (!stack_a)
        return (NULL);
    stack_a = NULL;
	i = 0;
    while (list[i])
    {
        new = ft_lstnew(ft_atoi(list[i]));
        if (!new)
        {
            ft_lstclear(&stack_a);
            return (NULL);
        }
        ft_lstadd_back(&stack_a, new);
        i++;
    }
    return (stack_a);
}

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
	int size;

    if(!check_args(ac, av) || ac == 1)
        return(write(2, "Error\n", 6), 1);
	char **list = creat_stack(av);
    stack_a = list_stack(list);
    stack_b = NULL;
	size = ft_lstsize(stack_a);
	assign_index(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	ft_free(list);
}
