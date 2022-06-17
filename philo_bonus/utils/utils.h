/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:39:19 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/29 00:24:53 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include"./structs.h"

int		ft_isdigit(int n);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
char	*make_sem_name(char *sem_start_name, int id);
void	dead_check(void *data);
void	*free_all(t_philo_list **arr, int i, t_vars *data);

#endif