/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sem_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:11:50 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/30 00:12:50 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include"utils.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		s2_len;
	int		s1_len;
	int		i;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = malloc(sizeof(char) * (s2_len + s1_len + 1));
	i = 0;
	if (new == NULL)
		return (NULL);
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < s2_len + s1_len)
	{
		new[i] = s2[i - s1_len];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_main_func(long int dev, long int new_n, int size, char *new)
{
	while (dev > 0)
	{
		new[size] = new_n / dev + 48;
		new_n = new_n % dev;
		dev /= 10;
		size++;
	}
	new[size] = '\0';
	return (new);
}

static int	minus_new(char *new, int new_n)
{
	if (new_n >= 0)
		return (0);
	else
	{
		*new = '-';
		return (1);
	}
}

char	*ft_itoa(int n)
{
	long int		dev;
	long int		new_n;
	int				size;
	char			*new;

	dev = 1;
	size = 1;
	new_n = n;
	if (new_n < 0)
	{
		size++;
		new_n *= -1;
	}
	while (new_n >= dev * 10)
	{
		dev *= 10;
		size++;
	}
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	size = minus_new(&new[0], n);
	new = ft_main_func(dev, new_n, size, new);
	return (new);
}

char	*make_sem_name(char *start_name, int id)
{
	char	*result;

	result = ft_strjoin(start_name, ft_itoa(id));
	if (!result)
		return (NULL);
	return (result);
}
