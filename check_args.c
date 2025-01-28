#include "push_swap.h"

static int	ft_contains(int num, char **av, int i)
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

static int	ft_is_it_num(char *num)
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