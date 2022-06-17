/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:43:07 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/29 00:37:10 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include<pthread.h>
# include<sys/time.h>
# include<sys/types.h>
# include <semaphore.h>
# define SEM_START_NAME_WHEN_ATE "/when_ate_"
# define SEM_START_NAME_NUMBER_OF_MEALS "/number_of_meals_"
# define SEM_NAME_FORKS "/forks"
# define SEM_NAME_IS_WRITING "/is_writing"

typedef struct s_vars
{
	int					number_of_philo;
	int					eat_time;
	int					sleep_time;
	int					life_time;
	int					number_of_cicles;
	sem_t				*forks;
	sem_t				*is_writing;
	long long int		start_time;	
}	t_vars;

typedef struct s_philo_list
{
	int					id;
	int					number_of_meals;
	int					is_dead;
	char				*char_when_ate;
	char				*char_number_of_meals;
	sem_t				*sem_when_ate;
	sem_t				*sem_number_of_meals;
	pid_t				philo_process_id;
	t_vars				*data;
	pthread_t			philo_phread_id;
	pthread_t			philo_life_phread_id;
	long long int		when_ate;
}	t_philo_list;

#endif