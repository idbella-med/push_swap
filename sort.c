#include "push_swap.h"

static void	sort_arr(int **arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if ((*arr)[i] < (*arr)[j])
			{
				temp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = temp;
			}
		}
	}
}

static int	get_med(t_list **a, t_list **b)
{
	t_list	*temp;
	int		*arr;
	int		med;
	int		i;

	temp = *a;
	i = 0;
	med = ft_lstsize(temp);
	arr = (int *)malloc(ft_lstsize(temp) * sizeof(int));
	if (!arr)
	{
		ft_lstclear(a);
		ft_lstclear(b);
		force_exit();
	}
	while (temp)
	{
		arr[i++] = temp->content;
		temp = temp->next;
	}
	sort_arr(&arr, med);
	med = arr[med / 2];
	free(arr);
	return (med);
}

void	sort_high(t_list **a, t_list **b)
{
	int	count;
	int	med;
	int	i;
	int	n;

	count = ft_lstsize(*a);
	while (count-- > 3)
	{
		i = 0;
		med = get_med(a, b);
		n = ft_lstsize(*a);
		while (n > 3 && i++ < n)
		{
			if ((*a)->content <= med)
				pb(a, b);
			else
				ra(a);
		}
	}
	do_three(a);
	from_b_to_a(a, b);
}

void	sort_low(t_list **a, t_list **b)
{
	int	count;

	count = ft_lstsize(*a);
	if (count-- > 3)
		pb(a, b);
	if (count-- > 3)
		pb(a, b);
	while (count-- > 3)
	{
		set_index(*b);
		set_index(*a);
		set_target_a(*a, *b);
		cost_calc(*a, *b);
		push_to_b(a, b);
	}
	do_three(a);
	from_b_to_a(a, b);
}