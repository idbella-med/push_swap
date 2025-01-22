/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:03:42 by mohidbel          #+#    #+#             */
/*   Updated: 2025/01/21 18:56:05 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(lst);
	*lst = NULL;
}
