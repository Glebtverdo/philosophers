/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:32 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/28 00:18:43 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include"../structs.h"
#include"../utils/utils.h"

static t_philo_list	*new_philo(t_vars *data, int id)
{
	t_philo_list	*new_philo;

	new_philo = malloc(sizeof(t_philo_list));
	if (!new_philo)
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	pthread_mutex_init(&new_philo->rigth_fork, NULL);
	pthread_mutex_init(&new_philo->when_ate_mutex, NULL);
	pthread_mutex_init(&new_philo->number_of_meals_mutex, NULL);
	new_philo->id = id;
	new_philo->number_of_meals = data->number_of_cicles;
	new_philo->data = data;
	return (new_philo);
}

t_philo_list	**philos_init(t_vars *data)
{
	t_philo_list	**philos_arr;
	int				i;
	t_philo_list	*buffer;

	philos_arr = (t_philo_list **)malloc(sizeof(t_philo_list *) \
		* data->number_of_philo);
	if (!philos_arr)
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		buffer = new_philo(data, i);
		if (!buffer)
			return (free_all(philos_arr, i, data));
		philos_arr[i] = buffer;
		i++;
	}
	return (philos_arr);
}
