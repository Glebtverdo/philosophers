/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:57 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/30 00:13:08 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_isdigit(int n)
{
	return (n >= 48 && n <= 57);
}

static size_t	ft_skip_spaces(const char *str, size_t i)
{
	while ((str[i] == 32) | ((str[i] >= 9) & (str[i] <= 13)))
	{
		i++;
	}
	return (i);
}

static int	ft_check_long(size_t counter, int minus, size_t result)
{
	if (counter > 19)
	{
		if (minus == -1)
			return (0);
		else
			return (-1);
	}
	return (result * minus);
}

int	ft_atoi(const char *str)
{
	size_t					counter;
	size_t					i;
	unsigned long long int	result;
	int						minus;

	result = 0;
	i = 0;
	minus = 1;
	counter = 0;
	i = ft_skip_spaces(str, i);
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		counter++;
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_check_long(counter, minus, result));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
