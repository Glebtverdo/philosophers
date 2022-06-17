/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:31:37 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/28 00:36:09 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../structs.h"
#include"../utils/utils.h"
#include<stdlib.h>
#include<unistd.h>

static int	first_parser_step(int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Error invalid number of arguments\n", 35);
		return (0);
	}
	else
		return (1);
}

static int	chec_args(int argc, char **argv)
{
	int		i;
	int		iter;

	i = 1;
	while (i < argc)
	{
		iter = 0;
		while (argv[i][iter])
		{
			if (!ft_isdigit(argv[i][iter]) || ((i == 1 || i == 2 || i == 5) \
				&& argv[i][0] == '0'))
			{
				write(2, "Error invalid arguments\n", 24);
				return (1);
			}
			iter++;
		}
		i++;
	}
	return (0);
}

static void	fill_data(t_vars **result, int argc, char **argv)
{
	(*result)->number_of_philo = ft_atoi(argv[1]);
	(*result)->life_time = ft_atoi(argv[2]);
	(*result)->eat_time = ft_atoi(argv[3]);
	(*result)->sleep_time = ft_atoi(argv[4]);
	pthread_mutex_init(&(*result)->not_dead, NULL);
	pthread_mutex_init(&(*result)->is_writing, NULL);
	if (argc > 5)
		(*result)->number_of_cicles = ft_atoi(argv[5]);
	else
		(*result)->number_of_cicles = -1;
}

static t_vars	*second_parser_step(int argc, char**argv)
{
	t_vars	*result;

	if (chec_args(argc, argv))
		return (NULL);
	result = malloc(sizeof(t_vars));
	if (!result)
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	fill_data(&result, argc, argv);
	return (result);
}

t_vars	*parser(int argc, char **argv)
{
	t_vars	*result;

	if (first_parser_step(argc) == 0)
		return (NULL);
	result = second_parser_step(argc, argv);
	if (!result)
		return (NULL);
	return (result);
}
