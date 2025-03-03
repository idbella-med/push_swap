/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:18:05 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/26 10:02:12 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (!num || !num[0])
		return (0);
	while (num[i] == ' ')
		i++;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!ft_isdigit(num[i]))
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_valid_args(char **args)
{
	long	tmp;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!ft_is_it_num(args[i]) || !args[i][0])
			return (0);
		tmp = ft_atoi(args[i]);
		if (tmp < -2147483648 || tmp > 2147483647 || ft_contains(tmp, args, i))
			return (0);
		i++;
	}
	return (1);
}

static char	*fill_args(int ac, char **av)
{
	char	*result;
	char	*temp;
	int		i;

	i = 1;
	result = ft_strdup("");
	while (i < ac)
	{
		if (!av[i][0])
			return (free(result), NULL);
		temp = ft_strjoin(result, " ");
		free(result);
		result = ft_strjoin(temp, av[i]);
		free(temp);
		i++;
	}
	return (result);
}

int	check_args(int ac, char **av)
{
	char	**args;
	char	*str;

	str = fill_args(ac, av);
	if (ac < 2)
		return (0);
	args = ft_split(str, ' ');
	free(str);
	if (!args || !args[0] || !check_valid_args(args))
	{
		ft_free(args);
		return (0);
	}
	ft_free(args);
	return (1);
}
