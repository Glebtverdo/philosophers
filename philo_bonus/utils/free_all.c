/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:07 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/30 00:35:16 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../structs.h"
#include<stdlib.h>

void	*free_all(t_philo_list **arr, int i, t_vars *data)
{
	i -= 1;
	while (i != -1)
	{
		if (arr[i]->char_number_of_meals)
			free(arr[i]->char_number_of_meals);
		if (arr[i]->char_when_ate)
			free(arr[i]->char_when_ate);
		sem_close(arr[i]->sem_when_ate);
		sem_close(arr[i]->sem_number_of_meals);
		free(arr[i]);
		i--;
	}
	sem_close(data->is_writing);
	sem_close(data->forks);
	free(arr);
	free(data);
	return (NULL);
}
