/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:03:26 by vearleen          #+#    #+#             */
/*   Updated: 2022/05/03 22:46:55 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../structs.h"
#include<stdio.h>
#include<stdlib.h>
#include"../time_funcs/time_funcs.h"

void	dead_check(void *data)
{
	t_philo_list	*philo;
	long long int	time;

	philo = (t_philo_list *)data;
	while (1)
	{
		time = get_time() - philo->data->start_time;
		sem_wait(philo->sem_when_ate);
		if (time - philo->when_ate > philo->data->life_time)
		{
			sem_wait(philo->data->is_writing);
			printf("%lld %d %s", get_time() - philo->data->start_time, \
				philo->id + 1, "died\n");
			exit(0);
		}
		sem_post(philo->sem_when_ate);
		sem_wait(philo->sem_number_of_meals);
		if (philo->number_of_meals != -1 && philo->number_of_meals == 0)
		{
			mili_sleep(philo->data->life_time);
			exit(0);
		}
		sem_post(philo->sem_number_of_meals);
		mili_sleep(5);
	}
}
