/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:10 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/26 10:03:22 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			its_ko(stack, NULL);
		temp = temp->next;
	}
	ft_lstclear(stack);
	ft_putstr_fd("OK\n", 1);
	exit(0);
}

char	*ft_join(char *str1, char *str2)
{
	size_t	i;
	size_t	len;
	char	*join;

	if (!str1)
		str1 = "\0";
	len = ft_strlen(str1) + ft_strlen(str2);
	join = malloc((len + 1) * sizeof(char));
	if (!join)
	{
		if (str1[0])
			free(str1);
		return (NULL);
	}
	i = 0;
	len = 0;
	while (str1[i])
		join[len++] = str1[i++];
	i = 0;
	while (str2[i])
		join[len++] = str2[i++];
	join[len] = '\0';
	if (str1[0])
		free(str1);
	return (join);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((*str1 || *str2) && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
