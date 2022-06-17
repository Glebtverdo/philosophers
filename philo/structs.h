/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:43:07 by vearleen          #+#    #+#             */
/*   Updated: 2022/05/03 22:36:58 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include<pthread.h>
# include<sys/time.h>

typedef struct s_vars
{
	int					number_of_philo;
	int					eat_time;
	int					sleep_time;
	int					life_time;
	int					number_of_cicles;
	long long int		start_time;
	pthread_mutex_t		not_dead;
	pthread_mutex_t		is_writing;
	pthread_t			check_dead_phread_id;
}	t_vars;

typedef struct s_philo_list
{
	int					id;
	int					number_of_meals;
	t_vars				*data;
	pthread_t			philo_phread_id;
	long long int		when_ate;
	pthread_mutex_t		number_of_meals_mutex;
	pthread_mutex_t		when_ate_mutex;
	pthread_mutex_t		rigth_fork;
	pthread_mutex_t		*left_fork;
}	t_philo_list;

#endif