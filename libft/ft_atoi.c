/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohidbel <mohidbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:09:23 by mohidbel          #+#    #+#             */
/*   Updated: 2025/02/23 10:25:49 by mohidbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	chek_sign(char const *s, long *i)
{
	long	sign;

	sign = 1;
	if (s[*i] == '-')
	{
		sign *= -1;
		(*i)++;
	}
	else if (s[*i] == '+')
		(*i)++;
	return (sign);
}

long	ft_atoi(const char	*str)
{
	long	i;
	long	sign;
	long	result;
	long	temp;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = chek_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = result;
		result = result * 10 + (str[i++] - '0');
		if (result > 2147483648)
			return (2147483648);
		if ((result / 10) != temp && sign == 1)
			return (-1);
		else if ((result / 10) != temp && sign == -1)
			return (0);
	}
	return (result * sign);
}
