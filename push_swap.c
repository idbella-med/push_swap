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


int	ft_contains(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_it_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if ((!ft_is_it_num(args[i])) || (ft_contains(tmp, args, i)))
			return 0;
		i++;
	}
	if (ac == 2)
		ft_free(args);
    return 1;
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
	t_list *stack_a = NULL;
	t_list *new;
	int i = 0;
	while(list[i])
	{
		new = ft_lstnew(atoi(list[i]));
		if(!new)
			return(ft_lstclear(&stack_a), NULL);
		ft_lstadd_back(&stack_a, new);
        i++;
	}
	return (stack_a);
}

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    if(!check_args(ac, av) || ac == 1)
        return(write(2, "Error\n", 6), 1);
	char **list = creat_stack(av);
    stack_a = list_stack(list);
    stack_b = NULL;
	pb(&stack_a, &stack_b);
	while(stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("b : %d\n", stack_b->content);
	ft_free(list);
}
