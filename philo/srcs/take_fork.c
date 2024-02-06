/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:26:08 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/06 14:59:25 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *philo)
{
	int	time;
	
	time = get_time();
	pthread_mutex_lock(&philo->config->forks[philo->id - 1]);
	printf("%d %d has taken a fork\n", time, philo->id);
	pthread_mutex_lock(&philo->config->forks[(philo->id) % philo->config->number_of_philosophers]);
	printf("%d %d has taken a fork\n", time, philo->id);
	return (0);
}
