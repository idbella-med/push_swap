/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:15:58 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/17 12:58:26 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	**creat_list(char **av)
{
	int		i;
	char	*all;
	char	*tmp;
	char	**list;

	if (!*av || !av)
		return (NULL);
	i = 2;
	all = ft_strdup(av[1]);
	if (!all)
		return (NULL);
	while (av[i] != NULL)
	{
		tmp = ft_strjoin(all, " ");
		if (!tmp)
			return (free(all), NULL);
		free(all);
		all = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!all)
			return (NULL);
		i++;
	}
	list = ft_split(all, ' ');
	return (free(all), list);
}

static t_list	*list_stack(char **list)
{
	t_list	*stack_a;
	t_list	*new;
	int		i;

	if (!list || !*list)
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**list;

	if (ac == 1)
		return (0);
	if (!check_args(ac, av))
		force_exit();
	list = creat_list(av);
	stack_a = list_stack(list);
	if (!stack_a)
		force_exit();
	stack_b = NULL;
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_free(list);
}
