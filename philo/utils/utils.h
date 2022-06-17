/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:39:19 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/19 18:37:40 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include"./structs.h"

void	*free_all(t_philo_list **arr, int i, t_vars *data);
int		ft_isdigit(int n);
int		ft_atoi(const char *str);
void	*dead_check(void *data);

#endif