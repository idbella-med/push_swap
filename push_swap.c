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

void	do_three(t_list **a)
{
	t_list	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
	{
		rra(a);
	}
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if(is_sorted(*stack_a))
		return ;
	else if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) < 300)
		sort_low(stack_a, stack_b);
	else
		sort_high(stack_a, stack_b);
}

char **creat_stack(char **av)
{
	int i = 2;
	int j = 0;
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

    if(!check_args(ac, av) || ac == 1 || av[1][0] == '\0')
        force_exit();
	char **list = creat_stack(av);
    stack_a = list_stack(list);
    stack_b = NULL;
	size = ft_lstsize(stack_a);
	push_swap(&stack_a, &stack_b);
	ft_free(list);
	return 0;
}
