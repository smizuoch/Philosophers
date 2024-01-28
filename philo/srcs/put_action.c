/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:18:18 by smizuoch          #+#    #+#             */
/*   Updated: 2024/01/17 12:01:49 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void put_action(t_philo *philo, char *action)
{
	(void)philo;
	(void)action;
	return ;
	// int	time;

	// time = get_time();
	// pthread_mutex_lock(&philo->config->write);
	// if (philo->config->number_of_philosophers > 0)
	// 	printf("%d %d %s\n", time, philo->id, action);
	// pthread_mutex_unlock(&philo->config->write);
}
