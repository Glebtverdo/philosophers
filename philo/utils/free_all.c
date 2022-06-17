/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:07 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/28 00:18:01 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../structs.h"
#include<stdlib.h>

void	*free_all(t_philo_list **arr, int i, t_vars *data)
{
	i -= 1;
	while (i != -1)
	{
		pthread_mutex_destroy(&arr[i]->rigth_fork);
		pthread_mutex_destroy(&arr[i]->when_ate_mutex);
		pthread_mutex_destroy(&arr[i]->number_of_meals_mutex);
		free(arr[i]);
		i--;
	}
	free(arr);
	pthread_mutex_destroy(&data->not_dead);
	free(data);
	return (NULL);
}
