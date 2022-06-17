/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:29 by vearleen          #+#    #+#             */
/*   Updated: 2022/05/03 22:46:26 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include"../structs.h"
#include"../time_funcs/time_funcs.h"

void	ft_print(t_philo_list *philo, char *str)
{
	pthread_mutex_lock(&philo->data->is_writing);
	printf("%lld %d %s", get_time() - philo->data->start_time, \
		philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->is_writing);
}

static void	first_sleep(t_philo_list	*philo)
{
	if (philo->id % 2)
	{
		ft_print(philo, "is sleeping\n");
		mili_sleep(philo->data->sleep_time);
	}
}

static int	philo_eat(t_philo_list *philo)
{
	ft_print(philo, "is eating\n");
	mili_sleep(philo->data->eat_time);
	pthread_mutex_lock(&philo->when_ate_mutex);
	philo->when_ate = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->when_ate_mutex);
	pthread_mutex_lock(&philo->number_of_meals_mutex);
	if (philo->number_of_meals > 0)
		philo->number_of_meals--;
	pthread_mutex_unlock(&philo->rigth_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->number_of_meals == 0)
	{
		pthread_mutex_unlock(&philo->number_of_meals_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->number_of_meals_mutex);
	return (0);
}

static void	*philo_life(void *data)
{
	t_philo_list	*philo;

	philo = (t_philo_list *)data;
	pthread_mutex_lock(&philo->when_ate_mutex);
	philo->when_ate = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->when_ate_mutex);
	first_sleep(philo);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->rigth_fork);
		ft_print(philo, "has taken a fork\n");
		if (philo_eat(philo))
			return (NULL);
		ft_print(philo, "is sleeping\n");
		mili_sleep(philo->data->sleep_time);
		ft_print(philo, "is thinking\n");
	}
	pthread_mutex_unlock(&philo->number_of_meals_mutex);
	return (NULL);
}

void	philos_start(t_philo_list **philos_arr, t_vars *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (i == 0)
			philos_arr[i]->left_fork = \
				&philos_arr[data->number_of_philo - 1]->rigth_fork;
		else
			philos_arr[i]->left_fork = &philos_arr[i - 1]->rigth_fork;
		i++;
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&philos_arr[i]->philo_phread_id, \
			NULL, &philo_life, philos_arr[i]);
		i++;
	}
}
