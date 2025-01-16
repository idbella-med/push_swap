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
		if ((!ft_is_it_num(args[i])) || (tmp < -2147483648 || tmp > 2147483647) || (ft_contains(tmp, args, i)))
			return 0;
		i++;
	}
	if (ac == 2)
		ft_free(args);
    return 1;
}

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    if(!check_args(ac, av))
        puts("thats error asadi9i");
    
    stack_b = NULL;
}