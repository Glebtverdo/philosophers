/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:32 by vearleen          #+#    #+#             */
/*   Updated: 2022/05/03 22:37:04 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include"../structs.h"
#include"../utils/utils.h"

static int	make_sems(t_philo_list	*new_philo, int id)
{
	new_philo->char_number_of_meals = \
		make_sem_name(SEM_START_NAME_NUMBER_OF_MEALS, id);
	new_philo->char_when_ate = make_sem_name(SEM_START_NAME_WHEN_ATE, id);
	if (!new_philo->char_number_of_meals || !new_philo->char_when_ate)
	{
		write(2, "malloc error\n", 13);
		return (1);
	}
	sem_unlink(new_philo->char_number_of_meals);
	sem_unlink(new_philo->char_when_ate);
	new_philo->sem_number_of_meals = sem_open(\
		new_philo->char_number_of_meals, O_CREAT | O_EXCL, 0777, 1);
	new_philo->sem_when_ate = sem_open(\
	new_philo->char_when_ate, O_CREAT | O_EXCL, 0777, 1);
	if (new_philo->sem_number_of_meals == SEM_FAILED \
	|| new_philo->sem_when_ate == SEM_FAILED)
	{
		write(1, "semaphore error\n", 16);
		return (1);
	}
	return (0);
}

static t_philo_list	*new_philo(t_vars *data, int id)
{
	t_philo_list	*new_philo;

	new_philo = malloc(sizeof(t_philo_list));
	if (!new_philo)
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	if (make_sems(new_philo, id))
		return (NULL);
	new_philo->id = id;
	new_philo->is_dead = 0;
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
