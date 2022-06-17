/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:28:59 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/19 22:33:40 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../structs.h"
#include<unistd.h>
#include<stdio.h>

long long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	mili_sleep(int time)
{
	long long int	start;

	start = get_time();
	usleep(time * 900);
	while (get_time() - start < time)
		usleep(50);
}
