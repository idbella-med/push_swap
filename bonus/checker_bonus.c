/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:30:42 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/26 10:01:46 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	clear_stacks_exit(t_list **a, t_list **b, char *input)
{
	free(input);
	ft_lstclear(a);
	ft_lstclear(b);
	force_exit();
}

static void	check_move(t_list **stack_a, t_list **stack_b, char *input)
{
	if (!ft_strcmp(input, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(input, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(input, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(input, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(input, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(input, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(input, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(input, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(input, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(input, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(input, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		clear_stacks_exit(stack_a, stack_b, input);
}

void	its_ko(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_putstr_fd("KO\n", 1);
	exit(0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**list;
	char	*str;

	if (ac == 1)
		return (0);
	if (!check_args(ac, av) || !*av || !av)
		force_exit();
	list = creat_list(av);
	stack_a = list_stack(list);
	stack_b = NULL;
	str = get_next_line(0);
	while (str)
	{
		if (str)
			check_move(&stack_a, &stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (stack_b)
		its_ko(&stack_a, &stack_b);
	is_sorted(&stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
