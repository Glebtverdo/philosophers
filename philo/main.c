/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:14 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/28 00:35:46 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"main.h"

int	main(int argc, char **argv)
{
	t_vars			*data;
	t_philo_list	**philos_arr;
	int				i;

	data = parser(argc, argv);
	if (!data)
		return (1);
	philos_arr = philos_init(data);
	data->start_time = get_time();
	philos_start(philos_arr, data);
	if (!philos_arr)
		return (1);
	pthread_create(&data->check_dead_phread_id, NULL, &dead_check, philos_arr);
	pthread_mutex_lock(&data->not_dead);
	pthread_mutex_lock(&data->not_dead);
	pthread_mutex_unlock(&data->not_dead);
	mili_sleep(10);
	i = -1;
	while (++i < data->number_of_philo)
		pthread_detach(philos_arr[i]->philo_phread_id);
	pthread_detach(data->check_dead_phread_id);
	free_all(philos_arr, data->number_of_philo, data);
	return (0);
}
