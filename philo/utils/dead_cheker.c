/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:03:26 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/28 00:41:52 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../structs.h"
#include<stdio.h>
#include"../time_funcs/time_funcs.h"

static void	*check_is_dead(t_philo_list *philo, long long int time)
{
	pthread_mutex_lock(&philo->data->is_writing);
	printf("%lld %d %s", time, philo->id + 1, "died\n");
	pthread_mutex_unlock(&philo->data->not_dead);
	return (NULL);
}

static void	change_iters(int *i, int *sum, int number_of_philo)
{
	*i += 1;
	if (*i == number_of_philo)
	{
		*i = 0;
		*sum = 0;
	}
}

static int	check_sum(t_philo_list **philo, int i, int *sum)
{
	pthread_mutex_lock(&philo[i]->number_of_meals_mutex);
	if (philo[i]->number_of_meals == 0)
		*sum += 1;
	pthread_mutex_unlock(&philo[i]->number_of_meals_mutex);
	if (*sum == philo[i]->data->number_of_philo)
	{
		pthread_mutex_unlock(&philo[i]->data->not_dead);
		return (1);
	}
	return (0);
}

void	*dead_check(void *data)
{
	t_philo_list	**philo;
	long long int	time;
	int				i;
	int				sum;

	i = 0;
	sum = 0;
	philo = (t_philo_list **)data;
	while (i < philo[0]->data->number_of_philo)
	{
		time = get_time() - philo[i]->data->start_time;
		pthread_mutex_lock(&philo[i]->when_ate_mutex);
		if (time - philo[i]->when_ate >= philo[i]->data->life_time)
			return (check_is_dead(philo[i], time));
		pthread_mutex_unlock(&philo[i]->when_ate_mutex);
		if (check_sum(philo, i, &sum))
			return (NULL);
		change_iters(&i, &sum, philo[i]->data->number_of_philo);
	}
	return (NULL);
}
