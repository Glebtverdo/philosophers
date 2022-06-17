/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:29 by vearleen          #+#    #+#             */
/*   Updated: 2022/05/03 22:46:17 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include"../structs.h"
#include"../time_funcs/time_funcs.h"
#include"../utils/utils.h"

void	ft_print(t_philo_list *philo, char *str)
{
	sem_wait(philo->data->is_writing);
	printf("%lld %d %s", get_time() - philo->data->start_time, \
		philo->id + 1, str);
	sem_post(philo->data->is_writing);
}

static void	first_action(t_philo_list *philo)
{
	sem_wait(philo->sem_when_ate);
	philo->when_ate = get_time() - philo->data->start_time;
	sem_post(philo->sem_when_ate);
	if (philo->id % 2)
	{
		ft_print(philo, "is sleeping\n");
		mili_sleep(philo->data->sleep_time);
	}
}

static void	philo_eat(t_philo_list	*philo)
{
	sem_post(philo->sem_number_of_meals);
	sem_wait(philo->data->forks);
	ft_print(philo, "has taken a fork\n");
	sem_wait(philo->data->forks);
	ft_print(philo, "has taken a fork\n");
	ft_print(philo, "is eating\n");
	mili_sleep(philo->data->eat_time);
	sem_wait(philo->sem_when_ate);
	philo->when_ate = get_time() - philo->data->start_time;
	sem_post(philo->sem_when_ate);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	sem_wait(philo->sem_number_of_meals);
	if (philo->number_of_meals > 0)
		philo->number_of_meals--;
	sem_post(philo->sem_number_of_meals);
}

static void	*philo_life(void *data)
{
	t_philo_list	*philo;

	philo = (t_philo_list *)data;
	first_action(philo);
	sem_wait(philo->sem_number_of_meals);
	while (1 && philo->number_of_meals != 0)
	{
		philo_eat(philo);
		ft_print(philo, "is sleeping\n");
		mili_sleep(philo->data->sleep_time);
		ft_print(philo, "is thinking\n");
		sem_wait(philo->sem_number_of_meals);
	}
	sem_post(philo->sem_number_of_meals);
	return (NULL);
}

void	philos_start(t_philo_list **philos_arr, t_vars *data)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < data->number_of_philo)
	{
		pid = fork();
		if (pid == 0)
		{
			pthread_create(&philos_arr[i]->philo_phread_id, \
				NULL, &philo_life, philos_arr[i]);
			dead_check(philos_arr[i]);
		}
		else
			philos_arr[i]->philo_process_id = pid;
	}
	waitpid(-1, 0, 0);
	i = -1;
	while (++i < data->number_of_philo)
	{
		kill(philos_arr[i]->philo_process_id, 9);
		pthread_detach(philos_arr[i]->philo_phread_id);
	}
}
