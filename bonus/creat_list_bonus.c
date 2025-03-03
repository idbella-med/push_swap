/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:55:53 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/26 10:01:57 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**creat_list(char **av)
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
	while (av[i])
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

t_list	*list_stack(char **list)
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
