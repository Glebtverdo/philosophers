/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:57:07 by vearleen          #+#    #+#             */
/*   Updated: 2022/04/19 00:57:07 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H
# include"../structs.h"

t_philo_list	**philos_init(t_vars *data);
void			philos_start(t_philo_list **philos_arr, t_vars *data);
void			ft_print(t_philo_list *philo, char *str);

#endif