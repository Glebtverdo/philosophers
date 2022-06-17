/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:14 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/30 00:33:21 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"main.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

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
	i = 0;
	philos_start(philos_arr, data);
	free_all(philos_arr, data->number_of_philo, data);
	return (0);
}
