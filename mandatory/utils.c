/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:16:48 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/23 20:01:13 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	force_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_free(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_index(t_list *head, int size)
{
	t_list	*biggest;
	t_list	*tmp;

	if (!head)
		return ;
	while (size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL
					|| tmp->data > biggest->data))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = size;
	}
}

int	is_descending(t_list *a, int half)
{
	int	count;

	count = 0;
	while (a && a->next)
	{
		if (a->data >= a->next->data)
			count++;
		else
			count = 0;
		if (count >= half)
			return (1);
		a = a->next;
	}
	return (0);
}
